//-------------------------------------------------------------------------------
// Simulation-only stand-in for c1541_logic (drive CPU + VIAs).
//
// Replaces the 6502/VIA (VHDL, not Verilator-friendly) with a scripted
// stepper/motor sequence loaded from stimulus.hex, so the DDR3-facing
// drive logic (c1541_drv, c1541_track, c1541_direct_gcr, arbiters) runs
// unmodified and deterministically. Used only by the trace-diff harness;
// never part of the FPGA build.
//
// stimulus.hex: one 64-bit hex word per line:
//   [31:0] cycle (clk cycles after reset release), [33:32] stp, [34] mtr
// Events must be in ascending cycle order. Drive 1 (ds[0]=1) plays the
// same script delayed by DS1_DELAY cycles.
//-------------------------------------------------------------------------------

module c1541_logic
(
	input        clk,
	input        reset,

	input        ce,
	input        ph2_r,
	input        ph2_f,

	input        iec_clk_in,
	input        iec_data_in,
	input        iec_atn_in,
	output       iec_clk_out,
	output       iec_data_out,

	input        ext_en,
	output[14:0] rom_addr,
	input  [7:0] rom_data,

	input  [7:0] par_data_in,
	input        par_stb_in,
	output [7:0] par_data_out,
	output       par_stb_out,

	input  [1:0] ds,
	input  [7:0] din,
	output [7:0] dout,
	output       mode,
	output reg [1:0] stp,
	output reg   mtr,
	output [1:0] freq,
	input        sync_n,
	input        byte_n,
	input        wps_n,
	input        tr00_sense_n,
	output       act
);

localparam MAXEV     = 8192;
localparam DS1_DELAY = 7_000_000;

assign iec_clk_out  = 1;
assign iec_data_out = 1;
assign rom_addr     = 0;
assign par_data_out = 8'hFF;
assign par_stb_out  = 1;
assign dout         = 0;
assign mode         = 1;     // read
assign freq         = 0;
assign act          = mtr;

reg [63:0] ev[MAXEV];
initial $readmemh("stimulus.hex", ev);

reg [31:0] cyc = 0;
reg [15:0] idx = 0;

wire [31:0] ev_cyc = ev[idx][31:0] + (ds[0] ? DS1_DELAY : 0);

always @(posedge clk) begin
	if(reset) begin
		cyc <= 0;
		idx <= 0;
		stp <= 0;
		mtr <= 0;
	end
	else begin
		cyc <= cyc + 1'd1;
		if(idx < MAXEV && ev[idx] !== 64'hx && cyc == ev_cyc) begin
			stp <= ev[idx][33:32];
			mtr <= ev[idx][34];
			idx <= idx + 1'd1;
		end
	end
end

endmodule
