// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdrive_sound.h for the primary calling header

#ifndef VERILATED_VDRIVE_SOUND___024ROOT_H_
#define VERILATED_VDRIVE_SOUND___024ROOT_H_  // guard

#include "verilated.h"


class Vdrive_sound__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdrive_sound___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(ntsc,0,0);
        VL_IN8(step,1,0);
        VL_IN8(bump,1,0);
        VL_IN8(motor,1,0);
        VL_IN8(volume,1,0);
        VL_IN8(load,0,0);
        VL_IN8(load_wr,0,0);
        VL_IN8(load_data,7,0);
        VL_OUT8(load_wait,0,0);
        VL_IN8(ddr_busy,0,0);
        VL_OUT8(ddr_burstcnt,7,0);
        VL_OUT8(ddr_rd,0,0);
        VL_OUT8(ddr_we,0,0);
        VL_IN8(ddr_ready,0,0);
        CData/*0:0*/ drive_sound__DOT__clk;
        CData/*0:0*/ drive_sound__DOT__reset;
        CData/*0:0*/ drive_sound__DOT__ntsc;
        CData/*1:0*/ drive_sound__DOT__step;
        CData/*1:0*/ drive_sound__DOT__bump;
        CData/*1:0*/ drive_sound__DOT__motor;
        CData/*1:0*/ drive_sound__DOT__volume;
        CData/*0:0*/ drive_sound__DOT__load;
        CData/*0:0*/ drive_sound__DOT__load_wr;
        CData/*7:0*/ drive_sound__DOT__load_data;
        CData/*0:0*/ drive_sound__DOT__load_wait;
        CData/*0:0*/ drive_sound__DOT__ddr_busy;
        CData/*7:0*/ drive_sound__DOT__ddr_burstcnt;
        CData/*0:0*/ drive_sound__DOT__ddr_rd;
        CData/*0:0*/ drive_sound__DOT__ddr_we;
        CData/*0:0*/ drive_sound__DOT__ddr_ready;
        CData/*0:0*/ drive_sound__DOT__wr_pending;
        CData/*0:0*/ drive_sound__DOT__magic_ok;
        CData/*0:0*/ drive_sound__DOT__table_valid;
        CData/*1:0*/ drive_sound__DOT__mstate;
        CData/*7:0*/ drive_sound__DOT__fill0;
        CData/*7:0*/ drive_sound__DOT__fill1;
        CData/*0:0*/ drive_sound__DOT__snd_on;
        CData/*0:0*/ drive_sound__DOT__mtr_on;
        CData/*0:0*/ drive_sound__DOT__mot_act;
        CData/*0:0*/ drive_sound__DOT__hd_act;
        CData/*0:0*/ drive_sound__DOT__h_trig;
        CData/*2:0*/ drive_sound__DOT__h_sel;
        CData/*1:0*/ drive_sound__DOT__fstate;
        CData/*0:0*/ drive_sound__DOT__fv;
        CData/*1:0*/ drive_sound__DOT__wcnt;
        CData/*2:0*/ drive_sound__DOT__oseq;
        CData/*0:0*/ drive_sound__DOT__unnamedblk1__DOT__load_d;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ntsc__0;
        CData/*1:0*/ __Vtrigprevexpr___TOP__step__0;
        CData/*1:0*/ __Vtrigprevexpr___TOP__bump__0;
        CData/*1:0*/ __Vtrigprevexpr___TOP__motor__0;
        CData/*1:0*/ __Vtrigprevexpr___TOP__volume__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__load__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__load_wr__0;
        CData/*7:0*/ __Vtrigprevexpr___TOP__load_data__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ddr_busy__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ddr_ready__0;
        CData/*0:0*/ __VicoDidInit;
    };
    struct {
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__drive_sound__DOT__clk__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_OUT16(audio_out,15,0);
        SData/*15:0*/ drive_sound__DOT__audio_out;
        SData/*15:0*/ drive_sound__DOT__fifo_q;
        SData/*8:0*/ drive_sound__DOT__fifo_raddr;
        SData/*11:0*/ drive_sound__DOT__div;
        SData/*15:0*/ drive_sound__DOT__s0;
        SData/*15:0*/ drive_sound__DOT__s1;
        SData/*11:0*/ drive_sound__DOT__divmax;
        VL_IN(load_addr,24,0);
        VL_OUT(ddr_addr,28,0);
        IData/*24:0*/ drive_sound__DOT__load_addr;
        IData/*28:0*/ drive_sound__DOT__ddr_addr;
        IData/*28:0*/ drive_sound__DOT__wr_addr;
        IData/*28:0*/ drive_sound__DOT__f_addr;
        IData/*16:0*/ drive_sound__DOT__sum;
        IData/*24:0*/ __Vtrigprevexpr___TOP__load_addr__0;
        IData/*31:0*/ __VactIterCount;
        VL_OUT64(ddr_din,63,0);
        VL_IN64(ddr_dout,63,0);
        QData/*63:0*/ drive_sound__DOT__ddr_din;
        QData/*63:0*/ drive_sound__DOT__ddr_dout;
        QData/*63:0*/ drive_sound__DOT__wbuf;
        QData/*63:0*/ drive_sound__DOT__beat;
        QData/*63:0*/ __Vtrigprevexpr___TOP__ddr_dout__0;
        VlUnpacked<IData/*18:0*/, 5> drive_sound__DOT__tbl_off;
        VlUnpacked<IData/*20:0*/, 5> drive_sound__DOT__tbl_len;
        VlUnpacked<CData/*2:0*/, 2> drive_sound__DOT__sel;
        VlUnpacked<IData/*20:0*/, 2> drive_sound__DOT__rem_f;
        VlUnpacked<IData/*20:0*/, 2> drive_sound__DOT__fptr;
        VlUnpacked<CData/*7:0*/, 2> drive_sound__DOT__wr_ptr;
        VlUnpacked<CData/*7:0*/, 2> drive_sound__DOT__rd_ptr;
        VlUnpacked<SData/*15:0*/, 512> drive_sound__DOT__fifo;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vdrive_sound__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*1:0*/ drive_sound__DOT__M_OFF = 0U;
    static constexpr CData/*1:0*/ drive_sound__DOT__M_SPINUP = 1U;
    static constexpr CData/*1:0*/ drive_sound__DOT__M_LOOP = 2U;
    static constexpr CData/*1:0*/ drive_sound__DOT__M_SPINDOWN = 3U;
    static constexpr CData/*2:0*/ drive_sound__DOT__S_SPINUP = 0U;
    static constexpr CData/*2:0*/ drive_sound__DOT__S_LOOP = 1U;
    static constexpr CData/*2:0*/ drive_sound__DOT__S_SPINDOWN = 2U;
    static constexpr CData/*2:0*/ drive_sound__DOT__S_STEP = 3U;
    static constexpr CData/*2:0*/ drive_sound__DOT__S_BUMP = 4U;
    static constexpr CData/*1:0*/ drive_sound__DOT__F_IDLE = 0U;
    static constexpr CData/*1:0*/ drive_sound__DOT__F_REQ = 1U;
    static constexpr CData/*1:0*/ drive_sound__DOT__F_DATA = 2U;
    static constexpr CData/*1:0*/ drive_sound__DOT__F_WR = 3U;
    static constexpr IData/*28:0*/ drive_sound__DOT__SND_BASE = 0x06080000U;
    static constexpr IData/*31:0*/ drive_sound__DOT__MAGIC = 0x444e5344U;

    // CONSTRUCTORS
    Vdrive_sound___024root(Vdrive_sound__Syms* symsp, const char* namep);
    ~Vdrive_sound___024root();
    VL_UNCOPYABLE(Vdrive_sound___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
