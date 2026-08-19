#!/usr/bin/env python3
"""Build drive_sounds.bin for the C64 MiSTer drive sound engine.

Layout (little-endian, 8-byte aligned):
  word 0 : bytes 0-3 magic "DSND", bytes 4-7 reserved (zero)
  word 1-5: per sample {u32 byte offset from file start, u32 length in samples}
            order: spinup, loop, spindown, step, bump
  data   : 16-bit signed mono 16 kHz, each sample zero-padded to 8 bytes

Usage:
  build_drive_sounds.py --synth -o drive_sounds.bin
  build_drive_sounds.py -o drive_sounds.bin spinup.wav loop.wav spindown.wav step.wav bump.wav
"""

import argparse
import math
import struct
import sys
import wave

RATE = 16000
MAGIC = b"DSND"
NAMES = ["spinup", "loop", "spindown", "step", "bump"]


def read_wav(path):
    """Read a WAV, mix to mono, resample to RATE with linear interpolation."""
    with wave.open(path, "rb") as w:
        nch, sw, rate, nfr = w.getnchannels(), w.getsampwidth(), w.getframerate(), w.getnframes()
        raw = w.readframes(nfr)
    if sw != 2:
        sys.exit(f"{path}: only 16-bit WAV supported (got {8*sw}-bit)")
    data = struct.unpack(f"<{nfr*nch}h", raw)
    mono = [sum(data[i*nch:(i+1)*nch]) // nch for i in range(nfr)]
    if rate == RATE:
        return mono
    out = []
    ratio = rate / RATE
    n = int(len(mono) / ratio)
    for i in range(n):
        pos = i * ratio
        j = int(pos)
        frac = pos - j
        a = mono[j]
        b = mono[j + 1] if j + 1 < len(mono) else a
        out.append(int(a + (b - a) * frac))
    return out


def synth():
    """Synthetic test tones, one recognizable pitch per event."""
    def tone(freq0, freq1, secs, amp, decay=0.0):
        n = int(secs * RATE)
        out = []
        phase = 0.0
        for i in range(n):
            f = freq0 + (freq1 - freq0) * i / n
            phase += 2 * math.pi * f / RATE
            a = amp * (math.exp(-decay * i / RATE) if decay else 1.0)
            out.append(int(a * math.sin(phase)))
        return out

    return [
        tone(200, 100, 0.50, 12000),          # spinup: falling chirp
        tone(100, 100, 1.00, 10000),          # loop:   steady hum
        tone(100, 40, 0.80, 12000, decay=3),  # spindown: dying chirp
        tone(1000, 1000, 0.004, 16000, decay=400),  # step: 4ms click
        tone(300, 300, 0.020, 20000, decay=100),    # bump: 20ms knock
    ]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--out", required=True)
    ap.add_argument("--synth", action="store_true", help="generate test tones instead of reading WAVs")
    ap.add_argument("wavs", nargs="*", help=f"5 WAV files: {' '.join(NAMES)}")
    args = ap.parse_args()

    if args.synth:
        samples = synth()
    else:
        if len(args.wavs) != 5:
            sys.exit(f"need 5 WAV files in order: {' '.join(NAMES)}")
        samples = [read_wav(p) for p in args.wavs]

    header_len = 8 + 5 * 8
    table = []
    blobs = []
    off = header_len
    for name, smp in zip(NAMES, samples):
        blob = struct.pack(f"<{len(smp)}h", *[max(-32768, min(32767, s)) for s in smp])
        pad = (-len(blob)) % 8
        table.append((off, len(smp)))
        blobs.append(blob + b"\0" * pad)
        off += len(blob) + pad

    with open(args.out, "wb") as f:
        f.write(MAGIC + b"\0\0\0\0")
        for o, n in table:
            f.write(struct.pack("<II", o, n))
        for b in blobs:
            f.write(b)

    total = off
    print(f"{args.out}: {total} bytes")
    for name, (o, n) in zip(NAMES, table):
        print(f"  {name:9s} offset {o:7d}  {n:7d} samples  {n/RATE:.3f}s")


if __name__ == "__main__":
    main()
