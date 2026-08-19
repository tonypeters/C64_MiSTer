// Drive-only trace-diff harness.
//
// Runs iec_drive + drive_sound + arbiter with a scripted stepper (see
// stub_c1541_logic.sv) against a cycle-deterministic DDR3 model, and
// records every drive-visible event:
//   TRK  - half-track register change        (cycle, drive, track)
//   DMA  - track-buffer write from DDR       (cycle, drive, addr, data)
//   GCR  - byte_n fall: byte seen by the CPU (cycle, drive, byte)
//   DRD  - drive DDR read accepted           (cycle, drive=addr>>18&1, addr)
// Trace goes to a binary file named by argv:
//   ./Vtracediff_top off  trace_off.bin      (no samples, volume 0)
//   ./Vtracediff_top on   trace_on.bin       (samples loaded, volume 3)
// Compare with analyze.py. Tier 1 = off vs on-without-file must be
// byte-identical; tier 2 = on-with-file, bounded skew only.

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "Vtracediff_top.h"
#include "Vtracediff_top_tracediff_top.h"
#include "Vtracediff_top_iec_drive.h"
#include "verilated.h"

static Vtracediff_top* dut;
static uint64_t cyc = 0;

static const uint32_t DRV0_BASE = 0x06000000; // 64-bit word addresses
static const uint32_t DRV1_BASE = 0x06040000;
static const uint32_t SND_BASE  = 0x06080000;
static const uint32_t MEM_BASE  = 0x06000000;
static const uint32_t MEM_WORDS = 1 << 20;    // 8MB region

static std::vector<uint64_t> mem(MEM_WORDS, 0);

struct Ev { uint32_t cycle; uint8_t kind, drive; uint16_t a; uint64_t d; };
static std::vector<Ev> trace;
enum { K_TRK = 1, K_DMA = 2, K_GCR = 3, K_DRD = 4 };

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    setvbuf(stdout, nullptr, _IONBF, 0);
    if (argc < 3) { fprintf(stderr, "usage: %s off|on <trace.bin>\n", argv[0]); return 1; }
    bool with_samples = !strcmp(argv[1], "on");

    dut = new Vtracediff_top;

    // ---- preload both disk images
    {
        FILE* f = fopen("disk.img", "rb");
        if (!f) { fprintf(stderr, "no disk.img\n"); return 1; }
        std::vector<uint8_t> img;
        for (int c; (c = fgetc(f)) != EOF;) img.push_back((uint8_t)c);
        fclose(f);
        for (size_t i = 0; i + 7 < img.size(); i += 8) {
            uint64_t w; memcpy(&w, &img[i], 8);
            mem[(DRV0_BASE - MEM_BASE) + i / 8] = w;
            mem[(DRV1_BASE - MEM_BASE) + i / 8] = w;
        }
        printf("disk.img: %zu bytes preloaded to both drives\n", img.size());
    }

    long run_cycles = 0;
    { FILE* f = fopen("run_cycles.txt", "r"); if (f) { fscanf(f, "%ld", &run_cycles); fclose(f); } }
    if (!run_cycles) run_cycles = (long)(2.5 * 31527954);

    // ---- DDR model: constant latency, burst-capable, one outstanding read
    int      rd_wait = 0;
    uint32_t rd_addr = 0;
    int      rd_beats = 0;
    const int LAT = 24;

    auto step_ddr = [&]() {
        bool busy = (rd_beats > 0 && rd_wait > 0);
        dut->DDRAM_BUSY = busy;
        dut->DDRAM_DOUT_READY = 0;
        if (rd_beats > 0) {
            if (rd_wait > 0) rd_wait--;
            if (rd_wait == 0) {
                dut->DDRAM_DOUT_READY = 1;
                dut->DDRAM_DOUT = mem[(rd_addr - MEM_BASE) & (MEM_WORDS - 1)];
                rd_addr++;
                rd_beats--;
            }
        }
        if (!busy && dut->DDRAM_WE) {
            mem[(dut->DDRAM_ADDR - MEM_BASE) & (MEM_WORDS - 1)] = dut->DDRAM_DIN;
        }
        if (!busy && dut->DDRAM_RD && rd_beats == 0) {
            rd_addr = dut->DDRAM_ADDR;
            rd_beats = dut->DDRAM_BURSTCNT ? dut->DDRAM_BURSTCNT : 1;
            rd_wait = LAT;
            if (rd_addr < SND_BASE)
                trace.push_back({(uint32_t)cyc, K_DRD, (uint8_t)((rd_addr >> 18) & 1), 0, rd_addr});
        }
    };

    // ---- per-cycle observation state
    uint8_t  prev_track[2] = {0xFF, 0xFF};
    uint8_t  prev_byte_n[2] = {1, 1};

    auto observe = [&]() {
        uint8_t tr[2] = {dut->out_track0, dut->out_track1};
        for (int d = 0; d < 2; d++) {
            if (tr[d] != prev_track[d]) {
                trace.push_back({(uint32_t)cyc, K_TRK, (uint8_t)d, 0, tr[d]});
                prev_track[d] = tr[d];
            }
        }
        // hierarchy probes (names fixed at verilate time, see Makefile grep)
        uint8_t bn[2] = { TD_BYTE_N_0, TD_BYTE_N_1 };
        uint8_t db[2] = { TD_DOUT_0,   TD_DOUT_1   };
        for (int d = 0; d < 2; d++) {
            if (prev_byte_n[d] && !bn[d])
                trace.push_back({(uint32_t)cyc, K_GCR, (uint8_t)d, tr[d], db[d]});
            prev_byte_n[d] = bn[d];
        }
        if (TD_DMAWR_0) trace.push_back({(uint32_t)cyc, K_DMA, 0, (uint16_t)TD_DMAADDR_0, TD_DMADATA_0});
        if (TD_DMAWR_1) trace.push_back({(uint32_t)cyc, K_DMA, 1, (uint16_t)TD_DMAADDR_1, TD_DMADATA_1});
    };

    auto cycle = [&]() {
        step_ddr();
        dut->clk = 0; dut->eval();
        dut->clk = 1; dut->eval();
        observe();
        cyc++;
        dut->ce = cyc & 1;
    };

    // ---- reset & mount
    dut->reset = 1; dut->ce = 0; dut->volume = 0;
    dut->img_mounted = 0; dut->img_size = 85 * 8192 + 8192;
    dut->load = 0; dut->load_wr = 0;
    for (int i = 0; i < 20; i++) cycle();
    dut->reset = 0;
    for (int i = 0; i < 20; i++) cycle();

    // fixed preamble: mount happens at the same absolute cycle in every
    // run, so the reset-anchored stimulus stays aligned with the trace
    const uint64_t PREAMBLE = 300000;
    uint64_t preamble_start = cyc;

    if (with_samples) {
        FILE* f = fopen("drive_sounds.bin", "rb");
        if (!f) { fprintf(stderr, "no drive_sounds.bin\n"); return 1; }
        std::vector<uint8_t> bin;
        for (int c; (c = fgetc(f)) != EOF;) bin.push_back((uint8_t)c);
        fclose(f);
        dut->load = 1;
        for (size_t a = 0; a < bin.size(); a++) {
            long guard = 100000;
            while (dut->load_wait && --guard) cycle();
            if (!guard) { fprintf(stderr, "load stuck\n"); return 1; }
            dut->load_addr = (uint32_t)a; dut->load_data = bin[a];
            dut->load_wr = 1; cycle();
            dut->load_wr = 0; cycle();
        }
        while (dut->load_wait) cycle();
        dut->load = 0;
        dut->volume = 3;
        printf("samples loaded (%zu bytes), volume 3\n", bin.size());
    }

    if (cyc - preamble_start > PREAMBLE) { fprintf(stderr, "preamble too small\n"); return 1; }
    while (cyc - preamble_start < PREAMBLE) cycle();

    dut->img_mounted = 3; cycle(); cycle();
    dut->img_mounted = 0;
    trace.clear();  // keep only post-mount events, aligned across runs

    // ---- run (trace cycle 0 = mount for run-to-run alignment)
    uint64_t t0 = cyc;
    long hb = 0;
    while ((long)(cyc - t0) < run_cycles) {
        cycle();
        if (++hb == 10 * 1000 * 1000) {
            hb = 0;
            fprintf(stderr, "[hb] %.2fs / %.2fs sim, %zu events\n",
                    (double)(cyc - t0) / 31527954.0, (double)run_cycles / 31527954.0, trace.size());
        }
    }

    // rebase cycles to mount time
    for (auto& e : trace) e.cycle -= (uint32_t)t0;

    FILE* out = fopen(argv[2], "wb");
    for (auto& e : trace) fwrite(&e, sizeof(Ev), 1, out);
    fclose(out);
    printf("wrote %s: %zu events\n", argv[2], trace.size());

    long n[5] = {0};
    for (auto& e : trace) n[e.kind]++;
    printf("TRK %ld  DMA %ld  GCR %ld  DRD %ld\n", n[K_TRK], n[K_DMA], n[K_GCR], n[K_DRD]);
    delete dut;
    return 0;
}
