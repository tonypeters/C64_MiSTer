// Dead stand-ins for the VHDL CPU/VIA used by the (held-in-reset) 1581
// side, so the whole iec_drive tree verilates. Simulation only.

module T65
(
	input  [1:0]  mode,
	input         res_n,
	input         enable,
	input         clk,
	input         rdy,
	input         abort_n,
	input         irq_n,
	input         nmi_n,
	input         so_n,
	output        r_w_n,
	output        sync,
	output [23:0] A,
	input  [7:0]  DI,
	output [7:0]  DO,
	output        NMI_ack
);
assign r_w_n = 1;
assign sync = 0;
assign A = 0;
assign DO = 0;
assign NMI_ack = 0;
endmodule

module iecdrv_via6522
(
	input        clock,
	input        rising,
	input        falling,
	input        reset,
	input  [3:0] addr,
	input        wen,
	input        ren,
	input  [7:0] data_in,
	output [7:0] data_out,
	output       phi2_ref,
	output [7:0] port_a_o,
	output [7:0] port_a_t,
	input  [7:0] port_a_i,
	output [7:0] port_b_o,
	output [7:0] port_b_t,
	input  [7:0] port_b_i,
	input        ca1_i,
	output       ca2_o,
	input        ca2_i,
	output       ca2_t,
	output       cb1_o,
	input        cb1_i,
	output       cb1_t,
	output       cb2_o,
	input        cb2_i,
	output       cb2_t,
	output       irq
);
assign data_out = 0;
assign phi2_ref = 0;
assign port_a_o = 0;
assign port_a_t = 0;
assign port_b_o = 0;
assign port_b_t = 0;
assign ca2_o = 0;
assign ca2_t = 0;
assign cb1_o = 0;
assign cb1_t = 0;
assign cb2_o = 0;
assign cb2_t = 0;
assign irq = 0;
endmodule
