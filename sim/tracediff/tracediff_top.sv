//-------------------------------------------------------------------------------
// Trace-diff harness top: iec_drive + drive_sound + drive_sound_arb wired
// exactly like c64.sv, with the drive CPU replaced by stub_c1541_logic.
// The C++ testbench provides the DDR3 model, mounts the images, uploads
// the sample file, and records the drive-side traces.
//-------------------------------------------------------------------------------

module tracediff_top
(
	input         clk,
	input         reset,
	input         ce,          // 16MHz-ish enable, every other clk

	input   [1:0] img_mounted,
	input  [31:0] img_size,

	input   [1:0] volume,

	// sample upload
	input         load,
	input         load_wr,
	input  [24:0] load_addr,
	input   [7:0] load_data,
	output        load_wait,

	// DDR3 model side
	input         DDRAM_BUSY,
	output  [7:0] DDRAM_BURSTCNT,
	output [28:0] DDRAM_ADDR,
	input  [63:0] DDRAM_DOUT,
	input         DDRAM_DOUT_READY,
	output        DDRAM_RD,
	output        DDRAM_WE,
	output [63:0] DDRAM_DIN,
	output  [7:0] DDRAM_BE,

	// observables
	output  [7:0] out_track0,
	output  [7:0] out_track1,
	output        disk_ready,
	output [15:0] audio_out
);

wire [31:0] sd_lba[2];
wire  [5:0] sd_blk_cnt[2];
wire  [1:0] sd_rd, sd_wr;
wire  [7:0] sd_buff_din[2];
wire  [7:0] out_track[2];

assign out_track0 = out_track[0];
assign out_track1 = out_track[1];

wire        drv_ddram_busy, drv_ddram_ready;
wire  [7:0] drv_ddram_burstcnt;
wire [28:0] drv_ddram_addr;
wire        drv_ddram_rd, drv_ddram_we;
wire [63:0] drv_ddram_din;
wire  [7:0] drv_ddram_be;

wire        snd_ddram_busy, snd_ddram_ready;
wire [28:0] snd_ddram_addr;
wire        snd_ddram_rd, snd_ddram_we;
wire [63:0] snd_ddram_din;

wire  [1:0] snd_step, snd_bump, snd_motor;

iec_drive iec_drive
(
	.clk(clk),
	.reset({reset, reset}),
	.ce(ce),
	.pause(1'b0),

	.iec_atn_i(1'b1),
	.iec_data_i(1'b1),
	.iec_clk_i(1'b1),

	.img_mounted(img_mounted),
	.img_size(img_size),
	.img_readonly(1'b1),
	.img_type(2'b01),
	.drive_rpm(3'd0),
	.drive_wobble(1'b0),

	.out_track(out_track),
	.disk_ready(disk_ready),

	.snd_step(snd_step),
	.snd_bump(snd_bump),
	.snd_motor(snd_motor),

	.par_data_i(8'hFF),
	.par_stb_i(1'b1),

	.clk_sys(clk),

	.sd_lba(sd_lba),
	.sd_blk_cnt(sd_blk_cnt),
	.sd_rd(sd_rd),
	.sd_wr(sd_wr),
	.sd_ack(2'b00),
	.sd_buff_addr(14'd0),
	.sd_buff_dout(8'd0),
	.sd_buff_din(sd_buff_din),
	.sd_buff_wr(1'b0),

	.rom_addr(16'd0),
	.rom_data(8'd0),
	.rom_wr(1'b0),
	.rom_std(1'b1),

	.DDRAM_BUSY(drv_ddram_busy),
	.DDRAM_BURSTCNT(drv_ddram_burstcnt),
	.DDRAM_ADDR(drv_ddram_addr),
	.DDRAM_DOUT(DDRAM_DOUT),
	.DDRAM_DOUT_READY(drv_ddram_ready),
	.DDRAM_RD(drv_ddram_rd),
	.DDRAM_WE(drv_ddram_we),
	.DDRAM_DIN(drv_ddram_din),
	.DDRAM_BE(drv_ddram_be)
);

`ifdef TD_NO_ENGINE
// upstream-equivalent wiring: no engine, no arbiter, straight through
assign DDRAM_BURSTCNT = drv_ddram_burstcnt;
assign DDRAM_ADDR     = drv_ddram_addr;
assign DDRAM_RD       = drv_ddram_rd;
assign DDRAM_WE       = drv_ddram_we;
assign DDRAM_DIN      = drv_ddram_din;
assign DDRAM_BE       = drv_ddram_be;
assign drv_ddram_busy  = DDRAM_BUSY;
assign drv_ddram_ready = DDRAM_DOUT_READY;
assign load_wait = 0;
assign audio_out = 0;
assign {snd_ddram_busy, snd_ddram_ready} = 0;
assign {snd_ddram_addr, snd_ddram_rd, snd_ddram_we, snd_ddram_din} = 0;
`else
drive_sound drive_sound
(
	.clk(clk),
	.reset(reset),
	.ntsc(1'b0),

	.step(snd_step),
	.bump(snd_bump),
	.motor(snd_motor),
	.volume(volume),

	.load(load),
	.load_wr(load_wr),
	.load_addr(load_addr),
	.load_data(load_data),
	.load_wait(load_wait),

	.ddr_busy(snd_ddram_busy),
	.ddr_addr(snd_ddram_addr),
	.ddr_burstcnt(),
	.ddr_rd(snd_ddram_rd),
	.ddr_we(snd_ddram_we),
	.ddr_din(snd_ddram_din),
	.ddr_dout(DDRAM_DOUT),
	.ddr_ready(snd_ddram_ready),

	.audio_out(audio_out)
);

drive_sound_arb drive_sound_arb
(
	.clk(clk),
	.reset(reset),

	.DDRAM_BUSY(DDRAM_BUSY),
	.DDRAM_BURSTCNT(DDRAM_BURSTCNT),
	.DDRAM_ADDR(DDRAM_ADDR),
	.DDRAM_DOUT_READY(DDRAM_DOUT_READY),
	.DDRAM_RD(DDRAM_RD),
	.DDRAM_WE(DDRAM_WE),
	.DDRAM_DIN(DDRAM_DIN),
	.DDRAM_BE(DDRAM_BE),

	.drv_busy(drv_ddram_busy),
	.drv_burstcnt(drv_ddram_burstcnt),
	.drv_addr(drv_ddram_addr),
	.drv_ready(drv_ddram_ready),
	.drv_rd(drv_ddram_rd),
	.drv_we(drv_ddram_we),
	.drv_din(drv_ddram_din),
	.drv_be(drv_ddram_be),

	.snd_busy(snd_ddram_busy),
	.snd_addr(snd_ddram_addr),
	.snd_ready(snd_ddram_ready),
	.snd_rd(snd_ddram_rd),
	.snd_we(snd_ddram_we),
	.snd_din(snd_ddram_din)
);
`endif

endmodule
