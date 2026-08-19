# Drive-only trace-diff (see NOTES.md section 10)
#
#   make        tier 1 + tier 2
#   make tier1  no-engine build vs engine-idle build: traces must be identical
#   make tier2  engine-idle vs samples-playing: bounded skew only

VERILATOR ?= verilator
VFLAGS = --cc --exe --build -DDRIVE_SOUNDS -Wno-WIDTH -Wno-UNUSEDSIGNAL -Wno-PROCASSWIRE -Wno-fatal \
         --public-flat-rw --top-module tracediff_top

RTL = ../../rtl/iec_drive/iec_drive.sv \
      ../../rtl/iec_drive/c1541_multi.sv \
      ../../rtl/iec_drive/c1541_drv.sv \
      ../../rtl/iec_drive/c1541_direct_gcr.sv \
      ../../rtl/iec_drive/c1541_track.sv \
      ../../rtl/iec_drive/c1541_gcr.sv \
      ../../rtl/iec_drive/c1581_multi.sv \
      ../../rtl/iec_drive/c1581_drv.sv \
      ../../rtl/iec_drive/fdc1772.v \
      ../../rtl/iec_drive/floppy.v \
      ../../rtl/iec_drive/lfsr.v \
      ../../rtl/iec_drive/iecdrv_mos8520.v \
      ../../rtl/iec_drive/iecdrv_misc.sv \
      ../../rtl/drive_sound.sv \
      stub_c1541_logic.sv \
      stub_vhdl_prims.sv \
      tracediff_top.sv

all: run

# headers first, so the probe macros can be extracted from the flattened names
obj_dir/Vtracediff_top_iec_drive.h: $(RTL)
	$(VERILATOR) --cc -DDRIVE_SOUNDS -Wno-WIDTH -Wno-UNUSEDSIGNAL -Wno-PROCASSWIRE -Wno-fatal \
		--public-flat-rw --top-module tracediff_top $(RTL)

probes.h: obj_dir/Vtracediff_top_iec_drive.h gen_probes.py
	python3 gen_probes.py $< > $@

obj_dir/Vtracediff_top: probes.h tb_tracediff.cpp $(RTL)
	$(VERILATOR) $(VFLAGS) -CFLAGS "-include $(CURDIR)/probes.h -O2" \
		$(RTL) tb_tracediff.cpp

obj_dir_noeng/Vtracediff_top: probes.h tb_tracediff.cpp $(RTL)
	$(VERILATOR) $(VFLAGS) -DTD_NO_ENGINE --Mdir obj_dir_noeng \
		-CFLAGS "-include $(CURDIR)/probes.h -O2" \
		$(RTL) tb_tracediff.cpp

stimulus.hex disk.img run_cycles.txt: gen_stimulus.py
	python3 gen_stimulus.py

drive_sounds.bin:
	python3 ../../tools/build_drive_sounds.py --synth -o $@

tier1: obj_dir/Vtracediff_top obj_dir_noeng/Vtracediff_top stimulus.hex
	./obj_dir_noeng/Vtracediff_top off trace_noeng.bin
	./obj_dir/Vtracediff_top       off trace_idle.bin
	cmp trace_noeng.bin trace_idle.bin && echo "TIER1: IDENTICAL (PASS)"

tier2: obj_dir/Vtracediff_top stimulus.hex drive_sounds.bin
	./obj_dir/Vtracediff_top off trace_off.bin
	./obj_dir/Vtracediff_top on  trace_on.bin
	python3 analyze.py trace_off.bin trace_on.bin

run: tier1 tier2

clean:
	rm -rf obj_dir obj_dir_noeng probes.h stimulus.hex run_cycles.txt disk.img \
	       drive_sounds.bin trace_*.bin

.PHONY: all run tier1 tier2 clean
