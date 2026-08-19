# Unit test for rtl/drive_sound.sv (Verilator)
#
#   make        build and run
#   make wav    just run (rebuilds if needed), leaves drive_sound_tb.wav

VERILATOR ?= verilator

all: run

obj_dir/Vdrive_sound: ../rtl/drive_sound.sv tb_drive_sound.cpp
	$(VERILATOR) --cc --exe --build -O2 -DDRIVE_SOUNDS \
		-Wno-WIDTH -Wno-UNUSEDSIGNAL \
		--public-flat-rw --top-module drive_sound \
		../rtl/drive_sound.sv tb_drive_sound.cpp

drive_sounds.bin: ../tools/build_drive_sounds.py
	python3 ../tools/build_drive_sounds.py --synth -o $@

run: obj_dir/Vdrive_sound drive_sounds.bin
	./obj_dir/Vdrive_sound drive_sounds.bin

wav: run

clean:
	rm -rf obj_dir drive_sounds.bin drive_sound_tb.wav

.PHONY: all run wav clean
