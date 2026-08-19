#!/usr/bin/env python3
"""Tier-2 trace comparison for the drive-only trace-diff.

Usage: analyze.py trace_off.bin trace_on.bin

Event record (16 bytes): u32 cycle, u8 kind, u8 drive, u16 a, u64 d.
Kinds: 1 TRK, 2 DMA, 3 GCR, 4 DRD.

Rules:
- TRK: sequences must be identical in content AND cycle (head movement
  never depends on DDR traffic).
- GCR: byte VALUES may differ only inside a settle window after a head
  step on the same drive (buffer refill in progress); cadence may skew
  by a bounded amount (track-length bookkeeping lands with the load;
  ~1us, orders of magnitude under real spindle wobble).
- DMA: content must be identical; completion may skew by a bounded
  number of cycles (the drive waited on one in-flight sound beat).
- DRD: addresses identical; accept times may skew by the same bound.
"""

import struct
import sys
from collections import defaultdict

REC = struct.Struct("<IBBHQ")
KIND = {1: "TRK", 2: "DMA", 3: "GCR", 4: "DRD"}
SETTLE_WINDOW = 63000   # ~2ms after a step
SKEW_BOUND = 100        # cycles: > one sound beat + arbiter margin
GCR_SKEW_BOUND = 500    # cadence phase: must stay under one GCR byte cell (~820)


def load(path):
    evs = defaultdict(list)
    with open(path, "rb") as f:
        while True:
            b = f.read(REC.size)
            if len(b) < REC.size:
                break
            cyc, kind, drive, a, d = REC.unpack(b)
            evs[(kind, drive)].append((cyc, a, d))
    return evs


off = load(sys.argv[1])
on = load(sys.argv[2])

fail = []
report = []

# settle windows per drive, from the off-trace TRK events
windows = defaultdict(list)
for (kind, drive), evs in off.items():
    if kind == 1:
        for cyc, _, _ in evs:
            windows[drive].append((cyc, cyc + SETTLE_WINDOW))


def in_window(drive, cyc):
    return any(lo <= cyc <= hi for lo, hi in windows[drive])


for key in sorted(set(off) | set(on)):
    kind, drive = key
    a, b = off.get(key, []), on.get(key, [])
    name = f"{KIND[kind]} drv{drive}"
    if len(a) != len(b):
        fail.append(f"{name}: event count {len(a)} vs {len(b)}")
        continue
    max_skew = 0
    val_diffs_in_window = 0
    for i, ((c1, a1, d1), (c2, a2, d2)) in enumerate(zip(a, b)):
        skew = abs(c2 - c1)
        max_skew = max(max_skew, skew)
        content_same = (a1, d1) == (a2, d2)
        if kind == 1:  # TRK: everything identical
            if not content_same or skew:
                fail.append(f"{name}[{i}]: TRK differs (cyc {c1}/{c2}, {d1}/{d2})")
                break
        elif kind == 3:  # GCR: bounded skew; value may differ only in window
            if skew > GCR_SKEW_BOUND:
                fail.append(f"{name}[{i}]: GCR cadence skew {skew} at cyc {c1}")
                break
            if not content_same:
                if in_window(drive, c1):
                    val_diffs_in_window += 1
                else:
                    fail.append(f"{name}[{i}]: GCR value differs OUTSIDE window at cyc {c1}: {d1:02x} vs {d2:02x}")
                    break
        else:  # DMA / DRD: content identical, bounded skew
            if not content_same:
                fail.append(f"{name}[{i}]: content differs at cyc {c1}: a {a1:04x}/{a2:04x} d {d1:016x}/{d2:016x}")
                break
            if skew > SKEW_BOUND:
                fail.append(f"{name}[{i}]: skew {skew} > {SKEW_BOUND} at cyc {c1}")
                break
    note = f", {val_diffs_in_window} value diffs inside settle windows" if val_diffs_in_window else ""
    report.append(f"{name}: {len(a)} events, max skew {max_skew}{note}")

print("\n".join(report))
if fail:
    print("TIER2: FAIL")
    print("\n".join(fail[:10]))
    sys.exit(1)
print("TIER2: PASS (content identical; skew bounded; value diffs only in settle windows)")
