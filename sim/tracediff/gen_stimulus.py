#!/usr/bin/env python3
"""Generate stimulus.hex (stepper/motor script) and disk.img (fake G64
region) for the drive-only trace-diff harness.

stimulus.hex: 64-bit words {[34] mtr, [33:32] stp, [31:0] cycle}.
disk.img: raw bytes for one drive's 2MB DDR region — an offset table at
byte 12 (one u32 per half-track 0..84) and 8KB track blobs whose bytes
encode (half-track, counter) so any cross-track mixup is visible in the
GCR trace.
"""

import struct

CLK = 31_527_954

ev = []          # (cycle, mtr, stp)
stp = 0          # current phase
track = 34       # mirror of c1541_drv track_num (init 34, clamps 0..84)
mtr = 0


def emit(cyc):
    ev.append((int(cyc), mtr, stp & 3))


def step(cyc, down):
    """One half-track step: advance phase; c1541_drv: move[1]=down."""
    global stp, track
    stp = (stp - 1) & 3 if down else (stp + 1) & 3
    if down and track > 0:
        track -= 1
    if not down and track < 84:
        track += 1
    emit(cyc)


t = int(0.60 * CLK)

# motor on
mtr = 1
emit(t)
t += int(0.10 * CLK)

# slow seek: 20 half-tracks down at 6ms, back up 10 at 6ms
for _ in range(20):
    step(t, down=True)
    t += int(0.006 * CLK)
for _ in range(10):
    step(t, down=False)
    t += int(0.006 * CLK)

# sing-song regime: alternate half-tracks at 300Hz for 0.3s
for i in range(90):
    step(t, down=(i & 1) == 0)
    t += CLK // 300

# seek to track 0 (currently at 24), then 20 bump attempts at 5ms
for _ in range(24):
    step(t, down=True)
    t += int(0.004 * CLK)
for _ in range(20):
    step(t, down=True)   # clamped at 0 -> bump pulses
    t += int(0.005 * CLK)

# recover: seek up 10, brief 100Hz burst
for _ in range(10):
    step(t, down=False)
    t += int(0.006 * CLK)
for i in range(30):
    step(t, down=(i & 1) == 0)
    t += CLK // 100

# motor off, then a late re-on/off to exercise spindown/respin
mtr = 0
emit(t)
t += int(0.15 * CLK)
mtr = 1
emit(t)
t += int(0.10 * CLK)
mtr = 0
emit(t)

END = t + int(0.20 * CLK)

with open("stimulus.hex", "w") as f:
    for cyc, m, s in ev:
        f.write(f"{(m << 34) | (s << 32) | cyc:016x}\n")
    # sentinel: far future but small enough that +DS1_DELAY cannot wrap 32 bits
    f.write(f"{0xF0000000:016x}\n")

print(f"stimulus.hex: {len(ev)} events, last at {ev[-1][0]/CLK:.3f}s, run to {END} cycles ({END/CLK:.3f}s)")
with open("run_cycles.txt", "w") as f:
    f.write(str(END))

# ---- fake G64 image: every half-track populated
TRACK_SLOT = 8192
TRACK_LEN = 6250
ntracks = 85
data_base = 4096  # first track blob offset (8KB-aligned enough: use 4096? keep 8-byte aligned)
data_base = 8192

img = bytearray(12)  # 12-byte header
offs = []
for tno in range(ntracks):
    offs.append(data_base + tno * TRACK_SLOT)
img += b"".join(struct.pack("<I", o) for o in offs)
img += bytes(data_base - len(img))
# GCR-encode the payload: real disks never have zero-runs long enough to
# trigger the weak-bit (random flux) injector in c1541_direct_gcr, and the
# trace-diff needs deterministic media. Standard Commodore 4-to-5 GCR.
GCR = [0b01010,0b01011,0b10010,0b10011,0b01110,0b01111,0b10110,0b10111,
       0b01001,0b11001,0b11010,0b11011,0b01101,0b11101,0b11110,0b10101]

def gcr_bytes(payload, out_len):
    bits = []
    for b in payload:
        bits += [(GCR[b >> 4] >> (4 - i)) & 1 for i in range(5)]
        bits += [(GCR[b & 15] >> (4 - i)) & 1 for i in range(5)]
    out = bytearray()
    acc = nb = 0
    for bit in bits:
        acc = (acc << 1) | bit
        nb += 1
        if nb == 8:
            out.append(acc)
            acc = nb = 0
        if len(out) == out_len:
            break
    while len(out) < out_len:
        out.append(0x55)
    return out

for tno in range(ntracks):
    blob = bytearray(struct.pack("<H", TRACK_LEN))
    blob += b"\xff" * 5                              # sync run
    payload = bytes((tno ^ (i & 0xFF)) & 0xFF for i in range(TRACK_LEN))
    blob += gcr_bytes(payload, TRACK_LEN - 5)
    blob += bytes(TRACK_SLOT - len(blob))
    img += blob

with open("disk.img", "wb") as f:
    f.write(img)
print(f"disk.img: {len(img)} bytes, {ntracks} half-tracks")
