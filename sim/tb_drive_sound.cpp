// Verilator testbench for drive_sound.sv
//
// - Loads drive_sounds.bin through the ioctl interface (exercises the
//   loader, header snoop and magic check).
// - Fake DDR3: random 10-200 cycle read latency, plus a ~30us "track load
//   lockout" (busy toward the engine) after every step pulse, emulating
//   the arbiter deferral at the worst possible moment.
// - Stimulus: motor on, steps at 5/20/100/300 Hz, bumps, motor off,
//   motor re-on during spindown.
// - Output: drive_sound_tb.wav (16 kHz mono), underrun/stat report.
//   Exit code 1 if the FIFO ever underruns or no audio is produced.

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
#include "Vdrive_sound.h"
#include "Vdrive_sound___024root.h"
#include "verilated.h"

static Vdrive_sound* dut;
static uint64_t cyc = 0;

static const uint32_t SND_BASE = 0x06080000; // 64-bit word address
static const int CLK_HZ = 31527954;          // PAL clk_sys
static const int TICK = 1430;          // cycles per 22050 Hz sample

static std::vector<uint64_t> ddr(1 << 20, 0); // sparse enough: 8MB region
static std::mt19937 rng(1541);

static void tick_clk(void (*side)(void) = nullptr) {
    dut->clk = 0; dut->eval();
    dut->clk = 1; dut->eval();
    cyc++;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    setvbuf(stdout, nullptr, _IONBF, 0);
    dut = new Vdrive_sound;

    const char* bin_path = (argc > 1) ? argv[1] : "drive_sounds.bin";
    FILE* f = fopen(bin_path, "rb");
    if (!f) { fprintf(stderr, "cannot open %s\n", bin_path); return 1; }
    std::vector<uint8_t> bin;
    for (int c; (c = fgetc(f)) != EOF;) bin.push_back((uint8_t)c);
    fclose(f);
    printf("loaded %s: %zu bytes\n", bin_path, bin.size());

    // ---- DDR model state
    int rd_lat = 0;             // countdown to ddr_ready
    uint32_t rd_addr = 0;
    bool rd_pending = false;
    int64_t lockout_until = -1; // busy window after each step
    std::uniform_int_distribution<int> lat(10, 200);

    // ---- stats
    long underrun0 = 0, underrun1 = 0, ticks = 0;
    long head_grace_until = 0, motor_grace_until = 0;
    std::vector<int16_t> wav;
    long long sumsq_seg = 0; long seg_n = 0;

    auto& r = *dut->rootp;

    auto step_ddr = [&]() {
        // engine-side busy: real busy is rare; lockout emulates track loads
        bool busy = ((int64_t)cyc < lockout_until) || ((rng() & 63) == 0);
        dut->ddr_busy = busy;
        dut->ddr_ready = 0;
        if (rd_pending && --rd_lat <= 0) {
            dut->ddr_ready = 1;
            dut->ddr_dout = ddr[rd_addr & (ddr.size() - 1)];
            rd_pending = false;
        }
        if (!busy && dut->ddr_we) {
            ddr[dut->ddr_addr & (ddr.size() - 1)] = dut->ddr_din;
        }
        if (!busy && dut->ddr_rd && !rd_pending) {
            rd_pending = true;
            rd_addr = dut->ddr_addr;
            rd_lat = lat(rng);
        }
    };

    auto cycle = [&]() {
        step_ddr();
        tick_clk();
        if (cyc % (CLK_HZ / 10) == 0) {
            static time_t t0 = time(nullptr);
            long el = (long)(time(nullptr) - t0);
            fprintf(stderr, "[hb] sim %.1fs wall %lds (%.1f Mcyc/s)\n",
                    (double)cyc / CLK_HZ, el, el ? cyc / 1e6 / el : 0.0);
        }
        // capture one audio sample per 16kHz tick, count underruns
        if (cyc % TICK == 0) {
            ticks++;
            int16_t s = (int16_t)dut->audio_out;
            wav.push_back(s);
            sumsq_seg += (long long)s * s; seg_n++;
            bool mot_act = r.drive_sound__DOT__mstate != 0;
            uint8_t fill0 = (uint8_t)(r.drive_sound__DOT__wr_ptr[0] - r.drive_sound__DOT__rd_ptr[0]);
            uint8_t fill1 = (uint8_t)(r.drive_sound__DOT__wr_ptr[1] - r.drive_sound__DOT__rd_ptr[1]);
            bool hd_act = r.drive_sound__DOT__rem_f[1] || fill1;
            if (mot_act && !fill0 && r.drive_sound__DOT__rem_f[0] && ticks >= motor_grace_until) underrun0++;
            // 2-tick grace after a (re)trigger: first-fill latency is not starvation
            if (hd_act && !fill1 && r.drive_sound__DOT__rem_f[1] && ticks >= head_grace_until) underrun1++;
        }
    };

    auto run_us = [&](double us) { for (long n = (long)(us * CLK_HZ / 1e6); n > 0; n--) cycle(); };
    auto run_ms = [&](double ms) { run_us(ms * 1000.0); };

    auto seg_report = [&](const char* name) {
        double rms = seg_n ? sqrt((double)sumsq_seg / seg_n) : 0;
        printf("%-28s rms %7.0f  (%.2fs)\n", name, rms, (double)seg_n / 22050.0);
        sumsq_seg = 0; seg_n = 0;
    };

    auto do_step = [&](bool is_bump = false) {
        // hardware taps pulse step and bump TOGETHER on a clamped step
        if (is_bump) { dut->bump = 1; dut->step = 1; } else dut->step = 1;
        cycle();
        dut->step = 0; dut->bump = 0;
        head_grace_until = ticks + 2;
        lockout_until = cyc + 945;  // ~30us track load right after the step
    };

    // ---- reset
    dut->reset = 1; dut->ntsc = 0; dut->volume = 3; dut->track0 = 20; dut->track1 = 20;
    dut->step = 0; dut->bump = 0; dut->motor = 0; motor_grace_until = ticks + 2;
    dut->load = 0; dut->load_wr = 0;
    for (int i = 0; i < 10; i++) cycle();
    dut->reset = 0;
    for (int i = 0; i < 10; i++) cycle();

    // ---- ioctl upload, deliberately DURING core reset: Main auto-loads the
    // remembered file at core start while the reset counter still runs
    dut->reset = 1;
    for (int i = 0; i < 10; i++) cycle();
    dut->load = 1;
    for (size_t a = 0; a < bin.size(); a++) {
        long guard = 100000;
        while (dut->load_wait && --guard) cycle();
        if (!guard) { fprintf(stderr, "FAIL: load_wait stuck at byte %zu\n", a); return 1; }
        dut->load_addr = (uint32_t)a;
        dut->load_data = bin[a];
        dut->load_wr = 1; cycle();
        dut->load_wr = 0; cycle();
    }
    while (dut->load_wait) cycle();
    dut->load = 0;
    for (int i = 0; i < 100; i++) cycle();
    dut->reset = 0;
    for (int i = 0; i < 100; i++) cycle();
    if (!r.drive_sound__DOT__table_valid) { fprintf(stderr, "FAIL: table_valid not set after load-during-reset\n"); return 1; }
    printf("table_valid ok\n");
    for (int i = 0; i < 5; i++)
        printf("  sample %d: word off %u, %u samples\n", i,
               (unsigned)r.drive_sound__DOT__tbl_off[i], (unsigned)r.drive_sound__DOT__tbl_len[i]);

    // ---- optional drive-music mode: Daisy Bell as a step-rate timeline
    // (a reconstruction of the melody, not the executed CSDb program;
    //  pitch = step retrigger rate, like the real 1541 drive music)
    if (argc > 2 && !strcmp(argv[2], "daisy")) {
        struct Note { double hz; double beats; };
        // Daisy Bell chorus, first two phrases (3/4, ~100 BPM)
        static const Note tune[] = {
            {587.3,3},{493.9,3},{392.0,3},{293.7,3},
            {329.6,1},{370.0,1},{392.0,1},{329.6,2},{392.0,1},{293.7,5},{0,1},
            {440.0,3},{587.3,3},{493.9,3},{392.0,3},
            {329.6,1},{370.0,1},{392.0,1},{440.0,2},{493.9,1},{440.0,5},{0,1},
        };
        const double beat_s = 60.0 / 100.0;
        dut->motor = 1; motor_grace_until = ticks + 2; run_ms(800);   // spin up first, like the real program
        for (auto& n : tune) {
            double dur = n.beats * beat_s;
            if (n.hz < 1) { run_ms(dur * 1000.0); continue; }
            long nsteps = (long)(dur * n.hz);
            for (long i = 0; i < nsteps; i++) { do_step(); run_us(1e6 / n.hz - 1); }
        }
        dut->motor = 0; motor_grace_until = ticks + 2; run_ms(1500);
        printf("ticks %ld, underruns motor=%ld head=%ld\n", ticks, underrun0, underrun1);
        goto wav_out;
    }

    // ---- scenario
    seg_report("silence (pre)");

    dut->motor = 1; motor_grace_until = ticks + 2; run_ms(1200);            seg_report("motor: spinup + loop");
    for (int i = 0; i < 5;   i++) { do_step(); run_ms(200); }  seg_report("steps @5Hz");
    for (int i = 0; i < 20;  i++) { do_step(); run_ms(50);  }  seg_report("steps @20Hz");
    for (int i = 0; i < 50;  i++) { do_step(); run_ms(10);  }  seg_report("steps @100Hz");
    for (int i = 0; i < 150; i++) { do_step(); run_us(3333); } seg_report("steps @300Hz (SingSong)");
    for (int i = 0; i < 5;   i++) { do_step(true); run_ms(100); } seg_report("bumps @10Hz");
    dut->motor = 0; motor_grace_until = ticks + 2; run_ms(400);             seg_report("spindown (partial)");
    dut->motor = 1; motor_grace_until = ticks + 2; run_ms(500);             seg_report("re-spin during spindown");
    dut->motor = 0; motor_grace_until = ticks + 2; run_ms(1200);            seg_report("spindown + silence");

    // core reset must not kill the feature (OSD Reset regression)
    dut->reset = 1; for (int i = 0; i < 100; i++) cycle();
    dut->reset = 0; for (int i = 0; i < 100; i++) cycle();
    if (!r.drive_sound__DOT__table_valid) { fprintf(stderr, "FAIL: table_valid lost on core reset\n"); return 1; }
    dut->motor = 1; motor_grace_until = ticks + 2; run_ms(400);
    { long nz2 = 0; for (size_t i = wav.size() - 6000; i < wav.size(); i++) if (wav[i]) nz2++;
      printf("post-reset motor: %ld nonzero of 6000\n", nz2);
      if (nz2 < 1000) { fprintf(stderr, "FAIL: no audio after core reset\n"); return 1; } }
    dut->motor = 0; motor_grace_until = ticks + 2; run_ms(600);             seg_report("post-reset respin");

    // ---- step volume vs track: outer clicks must be much louder than inner
    {
    auto burst_rms = [&](int trk) {
        dut->track0 = dut->track1 = trk;
        size_t from = wav.size();
        for (int i = 0; i < 10; i++) { do_step(); run_ms(25); }
        long long e = 0; long n = 0;
        for (size_t i = from; i < wav.size(); i++) { e += (long long)wav[i]*wav[i]; n++; }
        return n ? sqrt((double)e / n) : 0.0;
    };
    double rms_out = burst_rms(0), rms_in = burst_rms(84);
    printf("step volume: track0 rms %.0f, track84 rms %.0f, ratio %.2f\n",
           rms_out, rms_in, rms_in ? rms_out / rms_in : 0.0);
    // volume (98/14 = 7x) stacked with the quieter inner-zone sample
    // (stepping2 is ~half the amplitude of stepping) gives ~15x
    if (rms_in <= 0 || rms_out / rms_in < 6.0 || rms_out / rms_in > 25.0) {
        fprintf(stderr, "FAIL: step volume ratio out of range (expect ~15)\n");
        return 1;
    }
    }

    // ---- checks
    printf("ticks %ld, underruns motor=%ld head=%ld\n", ticks, underrun0, underrun1);
wav_out:;
    long nz = 0; for (int16_t s : wav) if (s) nz++;
    printf("nonzero samples: %ld / %zu\n", nz, wav.size());

    // ---- WAV out
    FILE* w = fopen("drive_sound_tb.wav", "wb");
    uint32_t dlen = (uint32_t)(wav.size() * 2), rate = 22050;
    uint32_t riff = 36 + dlen; uint16_t one = 1, ch = 1, bits = 16, ba = 2;
    uint32_t brate = rate * 2;
    fwrite("RIFF", 4, 1, w); fwrite(&riff, 4, 1, w); fwrite("WAVEfmt ", 8, 1, w);
    uint32_t fmtlen = 16; fwrite(&fmtlen, 4, 1, w);
    fwrite(&one, 2, 1, w); fwrite(&ch, 2, 1, w); fwrite(&rate, 4, 1, w);
    fwrite(&brate, 4, 1, w); fwrite(&ba, 2, 1, w); fwrite(&bits, 2, 1, w);
    fwrite("data", 4, 1, w); fwrite(&dlen, 4, 1, w);
    fwrite(wav.data(), 2, wav.size(), w);
    fclose(w);
    printf("wrote drive_sound_tb.wav\n");

    bool fail = underrun0 || underrun1 || nz < 1000;
    printf(fail ? "RESULT: FAIL\n" : "RESULT: PASS\n");
    delete dut;
    return fail ? 1 : 0;
}
