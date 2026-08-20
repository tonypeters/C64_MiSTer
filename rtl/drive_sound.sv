//-------------------------------------------------------------------------------
//
// 1541 drive sound emulation
//
// Plays sampled drive mechanics (motor spin-up/loop/spin-down, head step,
// head bump) triggered by output-only taps from the 1541 model.
// Samples live in DDR3, loaded via ioctl from drive_sounds.bin.
//
// Two voices:
//   0: motor  - OFF -> SPINUP -> LOOP -> SPINDOWN -> OFF
//   1: head   - retriggerable one-shot, step or bump sample
//
// Single-beat DDR3 reads only (burstcnt=1), ~500 words/s per active voice.
// One 512x16 BRAM holds both voice FIFOs (255 samples each, ~11ms).
// No multipliers. Runs entirely on clk_sys.
//
// Known simplification: a voice flush (retrigger, motor state change) does
// not abort a DDR beat already in flight; up to 4 samples (0.25ms) of the
// previous sound can land at the start of the new one. Inaudible.
//
// File format (drive_sounds.bin), all little-endian, 8-byte aligned:
//   word 0 : bytes 0-3 magic "DSND", bytes 4-7 reserved
//   word 1-5: per sample {byte 0-3: byte offset from file start,
//                         byte 4-7: length in samples}
//             order: 0 spinup, 1 loop, 2 spindown, 3 step, 4 bump
//   data   : 16-bit signed mono, 22050 Hz, each sample 8-byte aligned
//
//-------------------------------------------------------------------------------

module drive_sound #(parameter SND_BASE = 29'h0608_0000)
(
	input             clk,
	input             reset,
	input             ntsc,

	input       [1:0] step,      // per-drive one-cycle pulses, already masked
	input       [1:0] bump,
	input       [1:0] motor,     // per-drive levels, already masked

	input       [1:0] volume,    // 0 off, 1 quiet(>>2), 2 normal(>>1), 3 loud

	// sample upload (ioctl)
	input             load,      // ioctl_download & this file index
	input             load_wr,
	input      [24:0] load_addr,
	input       [7:0] load_data,
	output            load_wait,

	// DDR3 through drive_sound_arb
	input             ddr_busy,
	output     [28:0] ddr_addr,
	output      [7:0] ddr_burstcnt,
	output reg        ddr_rd,
	output reg        ddr_we,
	output     [63:0] ddr_din,
	input      [63:0] ddr_dout,
	input             ddr_ready,

	output reg [15:0] audio_out  // signed
);

assign ddr_burstcnt = 8'd1;

// ------------------------------------------------------------------ loader

localparam [31:0] MAGIC = "DNSD"; // file bytes "DSND" read back little-endian

reg  [63:0] wbuf;
reg         wr_pending;
reg  [28:0] wr_addr;
reg         magic_ok;
reg         table_valid = 0;
reg  [18:0] tbl_off[5];  // 64-bit word offset from file start
reg  [20:0] tbl_len[5];  // length in samples

assign load_wait = wr_pending;
assign ddr_din   = wbuf;
assign ddr_addr  = ddr_we ? wr_addr : f_addr;

// The whole upload path ignores core reset: Main auto-loads the remembered
// file at core start while the core reset counter still runs, and the
// samples stay valid across every later reset (nothing re-uploads them).
always @(posedge clk) begin
	reg load_d;
	load_d <= load;

	if(load & load_wr) begin
		wbuf <= {load_data, wbuf[63:8]};
		if(&load_addr[2:0]) begin
			wr_pending <= 1;
			wr_addr    <= SND_BASE + load_addr[24:3];
		end
	end

	if(wr_pending) ddr_we <= 1;

	// write accepted: snoop the header while it streams by
	if(wr_pending & ddr_we & ~ddr_busy) begin
		wr_pending <= 0;
		ddr_we     <= 0;
		case(wr_addr - SND_BASE)
			0:         magic_ok <= (wbuf[31:0] == MAGIC);
			1,2,3,4,5: begin
				tbl_off[wr_addr - SND_BASE - 1] <= wbuf[21:3];
				tbl_len[wr_addr - SND_BASE - 1] <= wbuf[52:32];
			end
			default: ;
		endcase
	end

	if(load & ~load_d)  table_valid <= 0;
	if(~load & load_d)  table_valid <= magic_ok;
end

initial {wr_pending, ddr_we} = 0;

// ------------------------------------------------------------- voice state

localparam M_OFF = 2'd0, M_SPINUP = 2'd1, M_LOOP = 2'd2, M_SPINDOWN = 2'd3;
localparam [2:0] S_SPINUP = 0, S_LOOP = 1, S_SPINDOWN = 2, S_STEP = 3, S_BUMP = 4;

reg  [1:0] mstate = M_OFF;
reg  [2:0] sel[2];       // current sample per voice
reg [20:0] rem_f[2];     // samples left to fetch
reg [20:0] fptr[2];      // fetch position in samples (multiple of 4)
reg  [7:0] wr_ptr[2], rd_ptr[2];

// fill derived from pointers: no counter, no write/read update clash
wire [7:0] fill0 = wr_ptr[0] - rd_ptr[0];
wire [7:0] fill1 = wr_ptr[1] - rd_ptr[1];

wire snd_on  = table_valid & |volume & ~load;
wire mtr_on  = |motor;
wire mot_act = (mstate != M_OFF);
wire hd_act  = |rem_f[1] | |fill1;

// head trigger latch: bump wins over step
reg       h_trig;
reg [2:0] h_sel;

// -------------------------------------------------------------- fetch FSM

localparam F_IDLE = 2'd0, F_REQ = 2'd1, F_DATA = 2'd2, F_WR = 2'd3;

reg  [1:0] fstate = F_IDLE;
reg        fv;           // voice being fetched
reg  [1:0] wcnt;
reg [63:0] beat;
reg [28:0] f_addr;

// ------------------------------------------------------------ FIFO memory

reg [15:0] fifo[512];
reg [15:0] fifo_q;
reg  [8:0] fifo_raddr;
always @(posedge clk) fifo_q <= fifo[fifo_raddr];

// ---------------------------------------------------------------- output

reg  [11:0] div;
reg   [2:0] oseq = 0;
reg signed [15:0] s0, s1;
reg signed [16:0] sum;

// 22050 Hz: PAL 31527954/1430 = 22047, NTSC 32727264/1484 = 22053
wire [11:0] divmax = ntsc ? 12'd1483 : 12'd1429;

always @(posedge clk) begin

	// ---- sample tick and output sequencer
	div <= div + 1'd1;
	if(div >= divmax) begin
		div  <= 0;
		oseq <= 1;
	end
	if(oseq) oseq <= oseq + 1'd1;

	case(oseq)
		1: fifo_raddr <= {1'b0, rd_ptr[0]};
		2: fifo_raddr <= {1'b1, rd_ptr[1]};
		3: begin
			s0 <= (mot_act && fill0 != 0) ? fifo_q : 16'd0;
			if(mot_act && fill0 != 0) rd_ptr[0] <= rd_ptr[0] + 1'd1;
		end
		4: begin
			s1 <= (hd_act && fill1 != 0) ? fifo_q : 16'd0;
			if(hd_act && fill1 != 0) rd_ptr[1] <= rd_ptr[1] + 1'd1;
		end
		5: begin
			sum = s0 + s1;
			if(sum > 17'sd32767)  sum = 17'sd32767;
			if(sum < -17'sd32768) sum = -17'sd32768;
			case(volume)
				0: audio_out <= 0;
				1: audio_out <= {{2{sum[16]}}, sum[15:2]};
				2: audio_out <= {sum[16], sum[15:1]};
				3: audio_out <= sum[15:0];
			endcase
			oseq <= 0;
		end
		default: ;
	endcase
	if(~snd_on) audio_out <= 0;

	// ---- fetch FSM: voice refills, single beats (writes live in the loader)
	ddr_rd <= 0;

	case(fstate)
		F_IDLE: begin
			if(snd_on && !wr_pending) begin
				if(mot_act && |rem_f[0] && (8'd255 - fill0) >= 8'd4) begin
					fv <= 0;
					f_addr <= SND_BASE + tbl_off[sel[0]] + fptr[0][20:2];
					fstate <= F_REQ;
				end
				else if(|rem_f[1] && (8'd255 - fill1) >= 8'd4) begin
					fv <= 1;
					f_addr <= SND_BASE + tbl_off[sel[1]] + fptr[1][20:2];
					fstate <= F_REQ;
				end
			end
		end

		F_REQ: begin
			ddr_rd <= 1;
			if(ddr_rd & ~ddr_busy) begin
				ddr_rd <= 0;
				fstate <= F_DATA;
			end
		end

		F_DATA: if(ddr_ready) begin
			beat   <= ddr_dout;
			wcnt   <= 0;
			fstate <= F_WR;
		end

		F_WR: begin
			if(|rem_f[fv]) begin
				fifo[{fv, wr_ptr[fv]}] <= beat[15:0];
				beat       <= {16'd0, beat[63:16]};
				wr_ptr[fv] <= wr_ptr[fv] + 1'd1;
				rem_f[fv]  <= rem_f[fv] - 1'd1;
				fptr[fv]   <= fptr[fv] + 1'd1;
			end
			wcnt <= wcnt + 1'd1;
			if(&wcnt) fstate <= F_IDLE;
		end
	endcase

	// ---- motor voice FSM (last writer wins over fetch/read updates)
	case(mstate)
		M_OFF: if(snd_on & mtr_on) begin
			mstate    <= M_SPINUP;
			sel[0]    <= S_SPINUP;
			fptr[0]   <= 0;
			rem_f[0]  <= tbl_len[S_SPINUP];
			rd_ptr[0] <= wr_ptr[0];
		end
		M_SPINUP: begin
			if(!rem_f[0] && fstate == F_IDLE) begin
				// chain into the loop without a flush: seamless
				mstate   <= M_LOOP;
				sel[0]   <= S_LOOP;
				fptr[0]  <= 0;
				rem_f[0] <= tbl_len[S_LOOP];
			end
			if(~mtr_on) begin
				mstate    <= M_SPINDOWN;
				sel[0]    <= S_SPINDOWN;
				fptr[0]   <= 0;
				rem_f[0]  <= tbl_len[S_SPINDOWN];
				rd_ptr[0] <= wr_ptr[0];
			end
		end
		M_LOOP: begin
			if(!rem_f[0] && fstate == F_IDLE) begin
				fptr[0]  <= 0;                      // seamless loop restart
				rem_f[0] <= tbl_len[S_LOOP];
			end
			if(~mtr_on) begin
				mstate    <= M_SPINDOWN;
				sel[0]    <= S_SPINDOWN;
				fptr[0]   <= 0;
				rem_f[0]  <= tbl_len[S_SPINDOWN];
				rd_ptr[0] <= wr_ptr[0];
			end
		end
		M_SPINDOWN: begin
			if(mtr_on) begin
				mstate    <= M_LOOP;
				sel[0]    <= S_LOOP;
				fptr[0]   <= 0;
				rem_f[0]  <= tbl_len[S_LOOP];
				rd_ptr[0] <= wr_ptr[0];
			end
			else if(!rem_f[0] && !fill0) mstate <= M_OFF;
		end
	endcase

	// ---- head voice trigger (bump wins), applied only between fetches
	if(snd_on) begin
		if(|bump)      begin h_trig <= 1; h_sel <= S_BUMP; end
		else if(|step && !(h_trig && h_sel == S_BUMP)) begin h_trig <= 1; h_sel <= S_STEP; end
	end

	if(h_trig && (fstate == F_IDLE || !fv)) begin
		h_trig    <= 0;
		sel[1]    <= h_sel;
		fptr[1]   <= 0;
		rem_f[1]  <= tbl_len[h_sel];
		rd_ptr[1] <= wr_ptr[1];
	end

	// voices idle without valid samples/volume; the upload path stays alive
	if(~snd_on) begin
		mstate <= M_OFF;
		{rem_f[0], rem_f[1], h_trig} <= 0;
	end

	if(reset) begin
		fstate <= F_IDLE;
		oseq   <= 0;
		ddr_rd <= 0;
	end
end

endmodule

//-------------------------------------------------------------------------------
// DDR3 arbiter: iec_drive (priority, bursts) vs drive_sound (single beats).
// Zero added cycles on the drive path while the sound client is idle.
// Sound holds off for a cooldown after any drive request, so a stepping
// drive loads its track before the click sample is fetched.
//-------------------------------------------------------------------------------

module drive_sound_arb
(
	input             clk,
	input             reset,

	// framework side
	input             DDRAM_BUSY,
	output      [7:0] DDRAM_BURSTCNT,
	output     [28:0] DDRAM_ADDR,
	input             DDRAM_DOUT_READY,
	output            DDRAM_RD,
	output            DDRAM_WE,
	output     [63:0] DDRAM_DIN,
	output      [7:0] DDRAM_BE,

	// drive client (priority)
	output            drv_busy,
	input       [7:0] drv_burstcnt,
	input      [28:0] drv_addr,
	output            drv_ready,
	input             drv_rd,
	input             drv_we,
	input      [63:0] drv_din,
	input       [7:0] drv_be,

	// sound client (burstcnt fixed at 1)
	output            snd_busy,
	input      [28:0] snd_addr,
	output            snd_ready,
	input             snd_rd,
	input             snd_we,
	input      [63:0] snd_din
);

reg       drv_lock, snd_lock;
reg [7:0] beats;
reg [3:0] cool;

wire drv_req = drv_rd | drv_we;
wire snd_go  = ~drv_req & ~drv_lock & ~snd_lock & ~|cool;

assign DDRAM_ADDR     = snd_go ? snd_addr : drv_addr;
assign DDRAM_BURSTCNT = snd_go ? 8'd1     : drv_burstcnt;
assign DDRAM_DIN      = snd_go ? snd_din  : drv_din;
assign DDRAM_BE       = snd_go ? 8'hFF    : drv_be;
assign DDRAM_RD       = snd_go ? snd_rd   : (drv_rd & ~snd_lock);
assign DDRAM_WE       = snd_go ? snd_we   : (drv_we & ~snd_lock);

assign drv_busy  = DDRAM_BUSY | snd_lock;
assign snd_busy  = DDRAM_BUSY | ~snd_go;
assign drv_ready = DDRAM_DOUT_READY & drv_lock;
assign snd_ready = DDRAM_DOUT_READY & snd_lock;

always @(posedge clk) begin
	if(drv_rd & ~drv_busy) begin
		drv_lock <= 1;
		beats    <= drv_burstcnt;
	end
	if(drv_lock & DDRAM_DOUT_READY) begin
		if(beats <= 1) drv_lock <= 0;
		else           beats    <= beats - 1'd1;
	end

	if(snd_go & snd_rd & ~DDRAM_BUSY) snd_lock <= 1;
	if(snd_lock & DDRAM_DOUT_READY)   snd_lock <= 0;

	if(drv_req | drv_lock) cool <= '1;
	else if(|cool)         cool <= cool - 1'd1;

	if(reset) {drv_lock, snd_lock, cool} <= 0;
end

endmodule
