// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdrive_sound.h for the primary calling header

#include "Vdrive_sound__pch.h"

void Vdrive_sound___024root___eval_triggers_vec__ico(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_triggers_vec__ico\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                    (((((((IData)(vlSelfRef.ddr_ready) 
                                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ddr_ready__0)) 
                                                         << 5U) 
                                                        | ((vlSelfRef.ddr_dout 
                                                            != vlSelfRef.__Vtrigprevexpr___TOP__ddr_dout__0) 
                                                           << 4U)) 
                                                       | (((((IData)(vlSelfRef.ddr_busy) 
                                                             != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ddr_busy__0)) 
                                                            << 3U) 
                                                           | (((IData)(vlSelfRef.load_data) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__load_data__0)) 
                                                              << 2U)) 
                                                          | (((vlSelfRef.load_addr 
                                                               != vlSelfRef.__Vtrigprevexpr___TOP__load_addr__0) 
                                                              << 1U) 
                                                             | ((IData)(vlSelfRef.load_wr) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__load_wr__0))))) 
                                                      << 8U) 
                                                     | (((((((IData)(vlSelfRef.load) 
                                                             != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__load__0)) 
                                                            << 3U) 
                                                           | (((IData)(vlSelfRef.volume) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__volume__0)) 
                                                              << 2U)) 
                                                          | ((((IData)(vlSelfRef.motor) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__motor__0)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelfRef.bump) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__bump__0)))) 
                                                         << 4U) 
                                                        | (((((IData)(vlSelfRef.step) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__step__0)) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.ntsc) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ntsc__0)) 
                                                               << 2U)) 
                                                           | ((((IData)(vlSelfRef.reset) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.clk) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
    vlSelfRef.__Vtrigprevexpr___TOP__ntsc__0 = vlSelfRef.ntsc;
    vlSelfRef.__Vtrigprevexpr___TOP__step__0 = vlSelfRef.step;
    vlSelfRef.__Vtrigprevexpr___TOP__bump__0 = vlSelfRef.bump;
    vlSelfRef.__Vtrigprevexpr___TOP__motor__0 = vlSelfRef.motor;
    vlSelfRef.__Vtrigprevexpr___TOP__volume__0 = vlSelfRef.volume;
    vlSelfRef.__Vtrigprevexpr___TOP__load__0 = vlSelfRef.load;
    vlSelfRef.__Vtrigprevexpr___TOP__load_wr__0 = vlSelfRef.load_wr;
    vlSelfRef.__Vtrigprevexpr___TOP__load_addr__0 = vlSelfRef.load_addr;
    vlSelfRef.__Vtrigprevexpr___TOP__load_data__0 = vlSelfRef.load_data;
    vlSelfRef.__Vtrigprevexpr___TOP__ddr_busy__0 = vlSelfRef.ddr_busy;
    vlSelfRef.__Vtrigprevexpr___TOP__ddr_dout__0 = vlSelfRef.ddr_dout;
    vlSelfRef.__Vtrigprevexpr___TOP__ddr_ready__0 = vlSelfRef.ddr_ready;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
        vlSelfRef.__VicoDidInit = 1U;
        vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (8ULL | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000010ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000020ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000040ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000080ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000100ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000200ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000400ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000800ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000001000ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000002000ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
    }
}

bool Vdrive_sound___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

void Vdrive_sound___024root___eval_ico(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_ico\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__0
            vlSelfRef.drive_sound__DOT__clk = vlSelfRef.clk;
        }
    }
    if ((2ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__1
            vlSelfRef.drive_sound__DOT__reset = vlSelfRef.reset;
        }
    }
    if ((8ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__2
            vlSelfRef.drive_sound__DOT__step = vlSelfRef.step;
        }
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__3
            vlSelfRef.drive_sound__DOT__bump = vlSelfRef.bump;
        }
    }
    if ((0x0000000000000100ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__4
            vlSelfRef.drive_sound__DOT__load_wr = vlSelfRef.load_wr;
        }
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__5
            vlSelfRef.drive_sound__DOT__load_addr = vlSelfRef.load_addr;
        }
    }
    if ((0x0000000000000400ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__6
            vlSelfRef.drive_sound__DOT__load_data = vlSelfRef.load_data;
        }
    }
    if ((0x0000000000000800ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__7
            vlSelfRef.drive_sound__DOT__ddr_busy = vlSelfRef.ddr_busy;
        }
    }
    if ((1ULL & vlSelfRef.__VicoTriggered[1U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__8
            vlSelfRef.ddr_we = vlSelfRef.drive_sound__DOT__ddr_we;
            vlSelfRef.ddr_rd = vlSelfRef.drive_sound__DOT__ddr_rd;
            vlSelfRef.audio_out = vlSelfRef.drive_sound__DOT__audio_out;
            vlSelfRef.drive_sound__DOT__mot_act = (0U 
                                                   != (IData)(vlSelfRef.drive_sound__DOT__mstate));
            vlSelfRef.drive_sound__DOT__fill0 = (0x000000ffU 
                                                 & ((IData)(vlSelfRef.drive_sound__DOT__wr_ptr[0U]) 
                                                    - (IData)(vlSelfRef.drive_sound__DOT__rd_ptr[0U])));
            vlSelfRef.drive_sound__DOT__load_wait = vlSelfRef.drive_sound__DOT__wr_pending;
            vlSelfRef.drive_sound__DOT__ddr_din = vlSelfRef.drive_sound__DOT__wbuf;
            vlSelfRef.drive_sound__DOT__ddr_addr = 
                ((IData)(vlSelfRef.drive_sound__DOT__ddr_we)
                  ? vlSelfRef.drive_sound__DOT__wr_addr
                  : vlSelfRef.drive_sound__DOT__f_addr);
            vlSelfRef.drive_sound__DOT__fill1 = (0x000000ffU 
                                                 & ((IData)(vlSelfRef.drive_sound__DOT__wr_ptr[1U]) 
                                                    - (IData)(vlSelfRef.drive_sound__DOT__rd_ptr[1U])));
            vlSelfRef.load_wait = vlSelfRef.drive_sound__DOT__load_wait;
            vlSelfRef.ddr_din = vlSelfRef.drive_sound__DOT__ddr_din;
            vlSelfRef.ddr_addr = vlSelfRef.drive_sound__DOT__ddr_addr;
            vlSelfRef.drive_sound__DOT__hd_act = ((0U 
                                                   != vlSelfRef.drive_sound__DOT__rem_f[1U]) 
                                                  | (0U 
                                                     != (IData)(vlSelfRef.drive_sound__DOT__fill1)));
        }
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__9
            vlSelfRef.drive_sound__DOT__ddr_dout = vlSelfRef.ddr_dout;
        }
    }
    if ((0x0000000000002000ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__10
            vlSelfRef.drive_sound__DOT__ddr_ready = vlSelfRef.ddr_ready;
        }
    }
    if ((4ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__11
            vlSelfRef.drive_sound__DOT__ntsc = vlSelfRef.ntsc;
        }
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__12
            vlSelfRef.drive_sound__DOT__motor = vlSelfRef.motor;
        }
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__13
            vlSelfRef.drive_sound__DOT__volume = vlSelfRef.volume;
        }
    }
    if ((0x0000000000000080ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__14
            vlSelfRef.drive_sound__DOT__load = vlSelfRef.load;
        }
    }
    if (((1ULL & vlSelfRef.__VicoTriggered[1U]) | (4ULL 
                                                   & vlSelfRef.__VicoTriggered[0U]))) {
        {
            // Inlined CFunc: _ico_comb__TOP__0
            vlSelfRef.drive_sound__DOT__divmax = ((IData)(vlSelfRef.drive_sound__DOT__ntsc)
                                                   ? 0x07fcU
                                                   : 0x07b1U);
        }
    }
    if (((1ULL & vlSelfRef.__VicoTriggered[1U]) | (0x0000000000000020ULL 
                                                   & vlSelfRef.__VicoTriggered[0U]))) {
        {
            // Inlined CFunc: _ico_comb__TOP__1
            vlSelfRef.drive_sound__DOT__mtr_on = (0U 
                                                  != (IData)(vlSelfRef.drive_sound__DOT__motor));
        }
    }
    if (((1ULL & vlSelfRef.__VicoTriggered[1U]) | (0x00000000000000c0ULL 
                                                   & vlSelfRef.__VicoTriggered[0U]))) {
        {
            // Inlined CFunc: _ico_comb__TOP__2
            vlSelfRef.drive_sound__DOT__snd_on = ((IData)(vlSelfRef.drive_sound__DOT__table_valid) 
                                                  & ((~ (IData)(vlSelfRef.drive_sound__DOT__load)) 
                                                     & (0U 
                                                        != (IData)(vlSelfRef.drive_sound__DOT__volume))));
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdrive_sound___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vdrive_sound___024root___eval_phase__ico(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_phase__ico\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdrive_sound___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdrive_sound___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vdrive_sound___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vdrive_sound___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

bool Vdrive_sound___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vdrive_sound___024root___nba_sequent__TOP__0(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___nba_sequent__TOP__0\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*63:0*/ __Vdly__drive_sound__DOT__wbuf;
    __Vdly__drive_sound__DOT__wbuf = 0;
    CData/*0:0*/ __Vdly__drive_sound__DOT__wr_pending;
    __Vdly__drive_sound__DOT__wr_pending = 0;
    SData/*11:0*/ __Vdly__drive_sound__DOT__div;
    __Vdly__drive_sound__DOT__div = 0;
    CData/*2:0*/ __Vdly__drive_sound__DOT__oseq;
    __Vdly__drive_sound__DOT__oseq = 0;
    SData/*8:0*/ __Vdly__drive_sound__DOT__fifo_raddr;
    __Vdly__drive_sound__DOT__fifo_raddr = 0;
    SData/*15:0*/ __Vdly__drive_sound__DOT__s0;
    __Vdly__drive_sound__DOT__s0 = 0;
    SData/*15:0*/ __Vdly__drive_sound__DOT__s1;
    __Vdly__drive_sound__DOT__s1 = 0;
    CData/*0:0*/ __Vdly__drive_sound__DOT__ddr_rd;
    __Vdly__drive_sound__DOT__ddr_rd = 0;
    CData/*0:0*/ __Vdly__drive_sound__DOT__ddr_we;
    __Vdly__drive_sound__DOT__ddr_we = 0;
    CData/*1:0*/ __Vdly__drive_sound__DOT__wcnt;
    __Vdly__drive_sound__DOT__wcnt = 0;
    CData/*1:0*/ __Vdly__drive_sound__DOT__fstate;
    __Vdly__drive_sound__DOT__fstate = 0;
    CData/*0:0*/ __Vdly__drive_sound__DOT__fv;
    __Vdly__drive_sound__DOT__fv = 0;
    CData/*1:0*/ __Vdly__drive_sound__DOT__mstate;
    __Vdly__drive_sound__DOT__mstate = 0;
    CData/*0:0*/ __Vdly__drive_sound__DOT__h_trig;
    __Vdly__drive_sound__DOT__h_trig = 0;
    CData/*2:0*/ __Vdly__drive_sound__DOT__h_sel;
    __Vdly__drive_sound__DOT__h_sel = 0;
    IData/*18:0*/ __VdlyVal__drive_sound__DOT__tbl_off__v0;
    __VdlyVal__drive_sound__DOT__tbl_off__v0 = 0;
    CData/*2:0*/ __VdlyDim0__drive_sound__DOT__tbl_off__v0;
    __VdlyDim0__drive_sound__DOT__tbl_off__v0 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__tbl_off__v0;
    __VdlySet__drive_sound__DOT__tbl_off__v0 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__tbl_len__v0;
    __VdlyVal__drive_sound__DOT__tbl_len__v0 = 0;
    CData/*2:0*/ __VdlyDim0__drive_sound__DOT__tbl_len__v0;
    __VdlyDim0__drive_sound__DOT__tbl_len__v0 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__tbl_len__v0;
    __VdlySet__drive_sound__DOT__tbl_len__v0 = 0;
    CData/*7:0*/ __VdlyVal__drive_sound__DOT__rd_ptr__v0;
    __VdlyVal__drive_sound__DOT__rd_ptr__v0 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__rd_ptr__v0;
    __VdlySet__drive_sound__DOT__rd_ptr__v0 = 0;
    CData/*7:0*/ __VdlyVal__drive_sound__DOT__rd_ptr__v1;
    __VdlyVal__drive_sound__DOT__rd_ptr__v1 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__rd_ptr__v1;
    __VdlySet__drive_sound__DOT__rd_ptr__v1 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__rem_f__v0;
    __VdlyVal__drive_sound__DOT__rem_f__v0 = 0;
    CData/*0:0*/ __VdlyDim0__drive_sound__DOT__rem_f__v0;
    __VdlyDim0__drive_sound__DOT__rem_f__v0 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__rem_f__v0;
    __VdlySet__drive_sound__DOT__rem_f__v0 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__fptr__v0;
    __VdlyVal__drive_sound__DOT__fptr__v0 = 0;
    CData/*0:0*/ __VdlyDim0__drive_sound__DOT__fptr__v0;
    __VdlyDim0__drive_sound__DOT__fptr__v0 = 0;
    SData/*15:0*/ __VdlyVal__drive_sound__DOT__fifo__v0;
    __VdlyVal__drive_sound__DOT__fifo__v0 = 0;
    SData/*8:0*/ __VdlyDim0__drive_sound__DOT__fifo__v0;
    __VdlyDim0__drive_sound__DOT__fifo__v0 = 0;
    CData/*7:0*/ __VdlyVal__drive_sound__DOT__wr_ptr__v0;
    __VdlyVal__drive_sound__DOT__wr_ptr__v0 = 0;
    CData/*0:0*/ __VdlyDim0__drive_sound__DOT__wr_ptr__v0;
    __VdlyDim0__drive_sound__DOT__wr_ptr__v0 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__wr_ptr__v0;
    __VdlySet__drive_sound__DOT__wr_ptr__v0 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__fptr__v1;
    __VdlySet__drive_sound__DOT__fptr__v1 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__rem_f__v1;
    __VdlyVal__drive_sound__DOT__rem_f__v1 = 0;
    CData/*7:0*/ __VdlyVal__drive_sound__DOT__rd_ptr__v2;
    __VdlyVal__drive_sound__DOT__rd_ptr__v2 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__sel__v0;
    __VdlySet__drive_sound__DOT__sel__v0 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__fptr__v2;
    __VdlySet__drive_sound__DOT__fptr__v2 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__rem_f__v2;
    __VdlyVal__drive_sound__DOT__rem_f__v2 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__fptr__v3;
    __VdlySet__drive_sound__DOT__fptr__v3 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__rem_f__v3;
    __VdlyVal__drive_sound__DOT__rem_f__v3 = 0;
    CData/*7:0*/ __VdlyVal__drive_sound__DOT__rd_ptr__v3;
    __VdlyVal__drive_sound__DOT__rd_ptr__v3 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__sel__v1;
    __VdlySet__drive_sound__DOT__sel__v1 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__fptr__v4;
    __VdlySet__drive_sound__DOT__fptr__v4 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__rem_f__v4;
    __VdlyVal__drive_sound__DOT__rem_f__v4 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__sel__v2;
    __VdlySet__drive_sound__DOT__sel__v2 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__fptr__v5;
    __VdlySet__drive_sound__DOT__fptr__v5 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__rem_f__v5;
    __VdlyVal__drive_sound__DOT__rem_f__v5 = 0;
    CData/*7:0*/ __VdlyVal__drive_sound__DOT__rd_ptr__v4;
    __VdlyVal__drive_sound__DOT__rd_ptr__v4 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__sel__v3;
    __VdlySet__drive_sound__DOT__sel__v3 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__fptr__v6;
    __VdlySet__drive_sound__DOT__fptr__v6 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__rem_f__v6;
    __VdlyVal__drive_sound__DOT__rem_f__v6 = 0;
    CData/*7:0*/ __VdlyVal__drive_sound__DOT__rd_ptr__v5;
    __VdlyVal__drive_sound__DOT__rd_ptr__v5 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__sel__v4;
    __VdlySet__drive_sound__DOT__sel__v4 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__fptr__v7;
    __VdlySet__drive_sound__DOT__fptr__v7 = 0;
    CData/*7:0*/ __VdlyVal__drive_sound__DOT__rd_ptr__v6;
    __VdlyVal__drive_sound__DOT__rd_ptr__v6 = 0;
    CData/*2:0*/ __VdlyVal__drive_sound__DOT__sel__v5;
    __VdlyVal__drive_sound__DOT__sel__v5 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__sel__v5;
    __VdlySet__drive_sound__DOT__sel__v5 = 0;
    IData/*20:0*/ __VdlyVal__drive_sound__DOT__rem_f__v7;
    __VdlyVal__drive_sound__DOT__rem_f__v7 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__rem_f__v8;
    __VdlySet__drive_sound__DOT__rem_f__v8 = 0;
    CData/*0:0*/ __VdlySet__drive_sound__DOT__rem_f__v9;
    __VdlySet__drive_sound__DOT__rem_f__v9 = 0;
    // Body
    __VdlySet__drive_sound__DOT__tbl_off__v0 = 0U;
    __VdlySet__drive_sound__DOT__tbl_len__v0 = 0U;
    __Vdly__drive_sound__DOT__wbuf = vlSelfRef.drive_sound__DOT__wbuf;
    __Vdly__drive_sound__DOT__wr_pending = vlSelfRef.drive_sound__DOT__wr_pending;
    __Vdly__drive_sound__DOT__div = vlSelfRef.drive_sound__DOT__div;
    __Vdly__drive_sound__DOT__oseq = vlSelfRef.drive_sound__DOT__oseq;
    __Vdly__drive_sound__DOT__fifo_raddr = vlSelfRef.drive_sound__DOT__fifo_raddr;
    __Vdly__drive_sound__DOT__s0 = vlSelfRef.drive_sound__DOT__s0;
    __Vdly__drive_sound__DOT__s1 = vlSelfRef.drive_sound__DOT__s1;
    __Vdly__drive_sound__DOT__wcnt = vlSelfRef.drive_sound__DOT__wcnt;
    __Vdly__drive_sound__DOT__fstate = vlSelfRef.drive_sound__DOT__fstate;
    __Vdly__drive_sound__DOT__fv = vlSelfRef.drive_sound__DOT__fv;
    __Vdly__drive_sound__DOT__h_trig = vlSelfRef.drive_sound__DOT__h_trig;
    __Vdly__drive_sound__DOT__h_sel = vlSelfRef.drive_sound__DOT__h_sel;
    __Vdly__drive_sound__DOT__ddr_rd = vlSelfRef.drive_sound__DOT__ddr_rd;
    __Vdly__drive_sound__DOT__mstate = vlSelfRef.drive_sound__DOT__mstate;
    __VdlySet__drive_sound__DOT__sel__v0 = 0U;
    __VdlySet__drive_sound__DOT__sel__v1 = 0U;
    __VdlySet__drive_sound__DOT__sel__v2 = 0U;
    __VdlySet__drive_sound__DOT__sel__v3 = 0U;
    __VdlySet__drive_sound__DOT__sel__v4 = 0U;
    __Vdly__drive_sound__DOT__ddr_we = vlSelfRef.drive_sound__DOT__ddr_we;
    __VdlySet__drive_sound__DOT__wr_ptr__v0 = 0U;
    __VdlySet__drive_sound__DOT__rem_f__v8 = 0U;
    __VdlySet__drive_sound__DOT__rem_f__v9 = 0U;
    __VdlySet__drive_sound__DOT__rd_ptr__v0 = 0U;
    __VdlySet__drive_sound__DOT__rd_ptr__v1 = 0U;
    __VdlySet__drive_sound__DOT__sel__v5 = 0U;
    __VdlySet__drive_sound__DOT__fptr__v2 = 0U;
    __VdlySet__drive_sound__DOT__fptr__v4 = 0U;
    __VdlySet__drive_sound__DOT__fptr__v7 = 0U;
    __VdlySet__drive_sound__DOT__rem_f__v0 = 0U;
    __VdlySet__drive_sound__DOT__fptr__v1 = 0U;
    __VdlySet__drive_sound__DOT__fptr__v3 = 0U;
    __VdlySet__drive_sound__DOT__fptr__v5 = 0U;
    __VdlySet__drive_sound__DOT__fptr__v6 = 0U;
    if (((IData)(vlSelfRef.drive_sound__DOT__load) 
         & (~ (IData)(vlSelfRef.drive_sound__DOT__unnamedblk1__DOT__load_d)))) {
        vlSelfRef.drive_sound__DOT__table_valid = 0U;
    }
    if (((~ (IData)(vlSelfRef.drive_sound__DOT__load)) 
         & (IData)(vlSelfRef.drive_sound__DOT__unnamedblk1__DOT__load_d))) {
        vlSelfRef.drive_sound__DOT__table_valid = vlSelfRef.drive_sound__DOT__magic_ok;
    }
    __Vdly__drive_sound__DOT__div = (0x00000fffU & 
                                     ((IData)(1U) + (IData)(vlSelfRef.drive_sound__DOT__div)));
    if (((IData)(vlSelfRef.drive_sound__DOT__div) >= (IData)(vlSelfRef.drive_sound__DOT__divmax))) {
        __Vdly__drive_sound__DOT__div = 0U;
        __Vdly__drive_sound__DOT__oseq = 1U;
    }
    if ((0U != (IData)(vlSelfRef.drive_sound__DOT__oseq))) {
        __Vdly__drive_sound__DOT__oseq = (7U & ((IData)(1U) 
                                                + (IData)(vlSelfRef.drive_sound__DOT__oseq)));
    }
    if ((1U == (IData)(vlSelfRef.drive_sound__DOT__oseq))) {
        __Vdly__drive_sound__DOT__fifo_raddr = vlSelfRef.drive_sound__DOT__rd_ptr[0U];
    } else if ((2U == (IData)(vlSelfRef.drive_sound__DOT__oseq))) {
        __Vdly__drive_sound__DOT__fifo_raddr = (0x00000100U 
                                                | vlSelfRef.drive_sound__DOT__rd_ptr[1U]);
    } else if ((3U == (IData)(vlSelfRef.drive_sound__DOT__oseq))) {
        if (((IData)(vlSelfRef.drive_sound__DOT__mot_act) 
             & (0U != (IData)(vlSelfRef.drive_sound__DOT__fill0)))) {
            __VdlyVal__drive_sound__DOT__rd_ptr__v0 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.drive_sound__DOT__rd_ptr[0U])));
            __VdlySet__drive_sound__DOT__rd_ptr__v0 = 1U;
            __Vdly__drive_sound__DOT__s0 = vlSelfRef.drive_sound__DOT__fifo_q;
        } else {
            __Vdly__drive_sound__DOT__s0 = 0U;
        }
    } else if ((4U == (IData)(vlSelfRef.drive_sound__DOT__oseq))) {
        if (((IData)(vlSelfRef.drive_sound__DOT__hd_act) 
             & (0U != (IData)(vlSelfRef.drive_sound__DOT__fill1)))) {
            __VdlyVal__drive_sound__DOT__rd_ptr__v1 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.drive_sound__DOT__rd_ptr[1U])));
            __VdlySet__drive_sound__DOT__rd_ptr__v1 = 1U;
            __Vdly__drive_sound__DOT__s1 = vlSelfRef.drive_sound__DOT__fifo_q;
        } else {
            __Vdly__drive_sound__DOT__s1 = 0U;
        }
    } else if ((5U == (IData)(vlSelfRef.drive_sound__DOT__oseq))) {
        vlSelfRef.drive_sound__DOT__sum = (0x0001ffffU 
                                           & (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.drive_sound__DOT__s0)) 
                                              + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.drive_sound__DOT__s1))));
        if (VL_LTS_III(17, 0x00007fffU, vlSelfRef.drive_sound__DOT__sum)) {
            vlSelfRef.drive_sound__DOT__sum = 0x00007fffU;
        }
        __Vdly__drive_sound__DOT__oseq = 0U;
        if (VL_GTS_III(17, 0x00018000U, vlSelfRef.drive_sound__DOT__sum)) {
            vlSelfRef.drive_sound__DOT__sum = 0x00018000U;
        }
        if ((0U == (IData)(vlSelfRef.drive_sound__DOT__volume))) {
            vlSelfRef.drive_sound__DOT__audio_out = 0U;
        } else if ((1U == (IData)(vlSelfRef.drive_sound__DOT__volume))) {
            vlSelfRef.drive_sound__DOT__audio_out = 
                ((0x0000c000U & ((- (IData)((1U & (vlSelfRef.drive_sound__DOT__sum 
                                                   >> 0x10U)))) 
                                 << 0x0000000eU)) | 
                 (0x00003fffU & (vlSelfRef.drive_sound__DOT__sum 
                                 >> 2U)));
        } else if ((2U == (IData)(vlSelfRef.drive_sound__DOT__volume))) {
            vlSelfRef.drive_sound__DOT__audio_out = 
                (0x0000ffffU & (vlSelfRef.drive_sound__DOT__sum 
                                >> 1U));
        } else if ((3U == (IData)(vlSelfRef.drive_sound__DOT__volume))) {
            vlSelfRef.drive_sound__DOT__audio_out = 
                (0x0000ffffU & vlSelfRef.drive_sound__DOT__sum);
        }
    }
    __Vdly__drive_sound__DOT__ddr_rd = 0U;
    __Vdly__drive_sound__DOT__ddr_we = 0U;
    if ((2U & (IData)(vlSelfRef.drive_sound__DOT__fstate))) {
        if ((1U & (IData)(vlSelfRef.drive_sound__DOT__fstate))) {
            __Vdly__drive_sound__DOT__wcnt = (3U & 
                                              ((IData)(1U) 
                                               + (IData)(vlSelfRef.drive_sound__DOT__wcnt)));
            if ((0U != vlSelfRef.drive_sound__DOT__rem_f
                 [vlSelfRef.drive_sound__DOT__fv])) {
                __VdlyVal__drive_sound__DOT__rem_f__v0 
                    = (0x001fffffU & (vlSelfRef.drive_sound__DOT__rem_f
                                      [vlSelfRef.drive_sound__DOT__fv] 
                                      - (IData)(1U)));
                __VdlyDim0__drive_sound__DOT__rem_f__v0 
                    = vlSelfRef.drive_sound__DOT__fv;
                __VdlySet__drive_sound__DOT__rem_f__v0 = 1U;
                __VdlyVal__drive_sound__DOT__fptr__v0 
                    = (0x001fffffU & ((IData)(1U) + vlSelfRef.drive_sound__DOT__fptr
                                      [vlSelfRef.drive_sound__DOT__fv]));
                __VdlyDim0__drive_sound__DOT__fptr__v0 
                    = vlSelfRef.drive_sound__DOT__fv;
                __VdlyVal__drive_sound__DOT__fifo__v0 
                    = (0x0000ffffU & (IData)(vlSelfRef.drive_sound__DOT__beat));
                __VdlyDim0__drive_sound__DOT__fifo__v0 
                    = (((IData)(vlSelfRef.drive_sound__DOT__fv) 
                        << 8U) | vlSelfRef.drive_sound__DOT__wr_ptr
                       [vlSelfRef.drive_sound__DOT__fv]);
                vlSelfRef.drive_sound__DOT__beat = 
                    (vlSelfRef.drive_sound__DOT__beat 
                     >> 0x10U);
                __VdlyVal__drive_sound__DOT__wr_ptr__v0 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.drive_sound__DOT__wr_ptr
                                                            [vlSelfRef.drive_sound__DOT__fv])));
                __VdlyDim0__drive_sound__DOT__wr_ptr__v0 
                    = vlSelfRef.drive_sound__DOT__fv;
                __VdlySet__drive_sound__DOT__wr_ptr__v0 = 1U;
            }
            if ((3U == (IData)(vlSelfRef.drive_sound__DOT__wcnt))) {
                __Vdly__drive_sound__DOT__fstate = 0U;
            }
        } else if (vlSelfRef.drive_sound__DOT__ddr_ready) {
            vlSelfRef.drive_sound__DOT__beat = vlSelfRef.drive_sound__DOT__ddr_dout;
            __Vdly__drive_sound__DOT__wcnt = 0U;
            __Vdly__drive_sound__DOT__fstate = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.drive_sound__DOT__fstate))) {
        __Vdly__drive_sound__DOT__ddr_rd = 1U;
        if (((IData)(vlSelfRef.drive_sound__DOT__ddr_rd) 
             & (~ (IData)(vlSelfRef.drive_sound__DOT__ddr_busy)))) {
            __Vdly__drive_sound__DOT__ddr_rd = 0U;
            __Vdly__drive_sound__DOT__fstate = 2U;
        }
    } else if (vlSelfRef.drive_sound__DOT__wr_pending) {
        __Vdly__drive_sound__DOT__ddr_we = 1U;
        if (((IData)(vlSelfRef.drive_sound__DOT__ddr_we) 
             & (~ (IData)(vlSelfRef.drive_sound__DOT__ddr_busy)))) {
            __Vdly__drive_sound__DOT__ddr_we = 0U;
        }
    } else if (vlSelfRef.drive_sound__DOT__snd_on) {
        if ((((IData)(vlSelfRef.drive_sound__DOT__mot_act) 
              & (0U != vlSelfRef.drive_sound__DOT__rem_f[0U])) 
             & (4U <= (0x000000ffU & ((IData)(0xffU) 
                                      - (IData)(vlSelfRef.drive_sound__DOT__fill0)))))) {
            __Vdly__drive_sound__DOT__fv = 0U;
            vlSelfRef.drive_sound__DOT__f_addr = (0x1fffffffU 
                                                  & ((IData)(0x06080000U) 
                                                     + 
                                                     (((4U 
                                                        >= vlSelfRef.drive_sound__DOT__sel[0U])
                                                        ? vlSelfRef.drive_sound__DOT__tbl_off
                                                       [vlSelfRef.drive_sound__DOT__sel[0U]]
                                                        : 0U) 
                                                      + 
                                                      (0x0007ffffU 
                                                       & (vlSelfRef.drive_sound__DOT__fptr[0U] 
                                                          >> 2U)))));
            __Vdly__drive_sound__DOT__fstate = 1U;
        } else if (((0U != vlSelfRef.drive_sound__DOT__rem_f[1U]) 
                    & (4U <= (0x000000ffU & ((IData)(0xffU) 
                                             - (IData)(vlSelfRef.drive_sound__DOT__fill1)))))) {
            __Vdly__drive_sound__DOT__fv = 1U;
            vlSelfRef.drive_sound__DOT__f_addr = (0x1fffffffU 
                                                  & ((IData)(0x06080000U) 
                                                     + 
                                                     (((4U 
                                                        >= vlSelfRef.drive_sound__DOT__sel[1U])
                                                        ? vlSelfRef.drive_sound__DOT__tbl_off
                                                       [vlSelfRef.drive_sound__DOT__sel[1U]]
                                                        : 0U) 
                                                      + 
                                                      (0x0007ffffU 
                                                       & (vlSelfRef.drive_sound__DOT__fptr[1U] 
                                                          >> 2U)))));
            __Vdly__drive_sound__DOT__fstate = 1U;
        }
    }
    if ((2U & (IData)(vlSelfRef.drive_sound__DOT__mstate))) {
        if ((1U & (IData)(vlSelfRef.drive_sound__DOT__mstate))) {
            if (vlSelfRef.drive_sound__DOT__mtr_on) {
                __VdlySet__drive_sound__DOT__fptr__v1 = 1U;
                __VdlyVal__drive_sound__DOT__rem_f__v1 
                    = vlSelfRef.drive_sound__DOT__tbl_len[1U];
                __VdlyVal__drive_sound__DOT__rd_ptr__v2 
                    = vlSelfRef.drive_sound__DOT__wr_ptr[0U];
                __Vdly__drive_sound__DOT__mstate = 2U;
                __VdlySet__drive_sound__DOT__sel__v0 = 1U;
            } else if ((1U & ((~ (0U != vlSelfRef.drive_sound__DOT__rem_f[0U])) 
                              & (~ (0U != (IData)(vlSelfRef.drive_sound__DOT__fill0)))))) {
                __Vdly__drive_sound__DOT__mstate = 0U;
            }
        } else {
            if (((~ (0U != vlSelfRef.drive_sound__DOT__rem_f[0U])) 
                 & (0U == (IData)(vlSelfRef.drive_sound__DOT__fstate)))) {
                __VdlySet__drive_sound__DOT__fptr__v2 = 1U;
                __VdlyVal__drive_sound__DOT__rem_f__v2 
                    = vlSelfRef.drive_sound__DOT__tbl_len[1U];
            }
            if ((1U & (~ (IData)(vlSelfRef.drive_sound__DOT__mtr_on)))) {
                __VdlySet__drive_sound__DOT__fptr__v3 = 1U;
                __VdlyVal__drive_sound__DOT__rem_f__v3 
                    = vlSelfRef.drive_sound__DOT__tbl_len[2U];
                __VdlyVal__drive_sound__DOT__rd_ptr__v3 
                    = vlSelfRef.drive_sound__DOT__wr_ptr[0U];
                __Vdly__drive_sound__DOT__mstate = 3U;
                __VdlySet__drive_sound__DOT__sel__v1 = 1U;
            }
        }
    } else if ((1U & (IData)(vlSelfRef.drive_sound__DOT__mstate))) {
        if (((~ (0U != vlSelfRef.drive_sound__DOT__rem_f[0U])) 
             & (0U == (IData)(vlSelfRef.drive_sound__DOT__fstate)))) {
            __VdlySet__drive_sound__DOT__fptr__v4 = 1U;
            __VdlyVal__drive_sound__DOT__rem_f__v4 
                = vlSelfRef.drive_sound__DOT__tbl_len[1U];
            __Vdly__drive_sound__DOT__mstate = 2U;
            __VdlySet__drive_sound__DOT__sel__v2 = 1U;
        }
        if ((1U & (~ (IData)(vlSelfRef.drive_sound__DOT__mtr_on)))) {
            __VdlySet__drive_sound__DOT__fptr__v5 = 1U;
            __VdlyVal__drive_sound__DOT__rem_f__v5 
                = vlSelfRef.drive_sound__DOT__tbl_len[2U];
            __VdlyVal__drive_sound__DOT__rd_ptr__v4 
                = vlSelfRef.drive_sound__DOT__wr_ptr[0U];
            __Vdly__drive_sound__DOT__mstate = 3U;
            __VdlySet__drive_sound__DOT__sel__v3 = 1U;
        }
    } else if (((IData)(vlSelfRef.drive_sound__DOT__snd_on) 
                & (IData)(vlSelfRef.drive_sound__DOT__mtr_on))) {
        __VdlySet__drive_sound__DOT__fptr__v6 = 1U;
        __VdlyVal__drive_sound__DOT__rem_f__v6 = vlSelfRef.drive_sound__DOT__tbl_len[0U];
        __VdlyVal__drive_sound__DOT__rd_ptr__v5 = vlSelfRef.drive_sound__DOT__wr_ptr[0U];
        __Vdly__drive_sound__DOT__mstate = 1U;
        __VdlySet__drive_sound__DOT__sel__v4 = 1U;
    }
    if (vlSelfRef.drive_sound__DOT__snd_on) {
        if ((0U != (IData)(vlSelfRef.drive_sound__DOT__bump))) {
            __Vdly__drive_sound__DOT__h_trig = 1U;
            __Vdly__drive_sound__DOT__h_sel = 4U;
        } else if (((0U != (IData)(vlSelfRef.drive_sound__DOT__step)) 
                    & (~ ((IData)(vlSelfRef.drive_sound__DOT__h_trig) 
                          & (4U == (IData)(vlSelfRef.drive_sound__DOT__h_sel)))))) {
            __Vdly__drive_sound__DOT__h_trig = 1U;
            __Vdly__drive_sound__DOT__h_sel = 3U;
        }
    }
    if (((IData)(vlSelfRef.drive_sound__DOT__h_trig) 
         & ((0U == (IData)(vlSelfRef.drive_sound__DOT__fstate)) 
            | (~ (IData)(vlSelfRef.drive_sound__DOT__fv))))) {
        __VdlySet__drive_sound__DOT__fptr__v7 = 1U;
        __VdlyVal__drive_sound__DOT__rd_ptr__v6 = vlSelfRef.drive_sound__DOT__wr_ptr[1U];
        __Vdly__drive_sound__DOT__h_trig = 0U;
        __VdlyVal__drive_sound__DOT__sel__v5 = vlSelfRef.drive_sound__DOT__h_sel;
        __VdlySet__drive_sound__DOT__sel__v5 = 1U;
        __VdlyVal__drive_sound__DOT__rem_f__v7 = ((4U 
                                                   >= (IData)(vlSelfRef.drive_sound__DOT__h_sel))
                                                   ? vlSelfRef.drive_sound__DOT__tbl_len
                                                  [vlSelfRef.drive_sound__DOT__h_sel]
                                                   : 0U);
    }
    if ((1U & (~ (IData)(vlSelfRef.drive_sound__DOT__snd_on)))) {
        vlSelfRef.drive_sound__DOT__audio_out = 0U;
        __VdlySet__drive_sound__DOT__rem_f__v8 = 1U;
        __Vdly__drive_sound__DOT__mstate = 0U;
        __VdlySet__drive_sound__DOT__rem_f__v9 = 1U;
        __Vdly__drive_sound__DOT__h_trig = 0U;
    }
    vlSelfRef.drive_sound__DOT__div = __Vdly__drive_sound__DOT__div;
    if (vlSelfRef.drive_sound__DOT__reset) {
        vlSelfRef.drive_sound__DOT__table_valid = 0U;
        __Vdly__drive_sound__DOT__ddr_rd = 0U;
        __Vdly__drive_sound__DOT__ddr_we = 0U;
        __Vdly__drive_sound__DOT__fstate = 0U;
        __Vdly__drive_sound__DOT__oseq = 0U;
    }
    vlSelfRef.drive_sound__DOT__oseq = __Vdly__drive_sound__DOT__oseq;
    vlSelfRef.drive_sound__DOT__s0 = __Vdly__drive_sound__DOT__s0;
    vlSelfRef.drive_sound__DOT__s1 = __Vdly__drive_sound__DOT__s1;
    vlSelfRef.drive_sound__DOT__wcnt = __Vdly__drive_sound__DOT__wcnt;
    vlSelfRef.drive_sound__DOT__fstate = __Vdly__drive_sound__DOT__fstate;
    vlSelfRef.drive_sound__DOT__fv = __Vdly__drive_sound__DOT__fv;
    vlSelfRef.drive_sound__DOT__h_trig = __Vdly__drive_sound__DOT__h_trig;
    vlSelfRef.drive_sound__DOT__h_sel = __Vdly__drive_sound__DOT__h_sel;
    vlSelfRef.drive_sound__DOT__ddr_rd = __Vdly__drive_sound__DOT__ddr_rd;
    vlSelfRef.drive_sound__DOT__mstate = __Vdly__drive_sound__DOT__mstate;
    if (__VdlySet__drive_sound__DOT__wr_ptr__v0) {
        vlSelfRef.drive_sound__DOT__wr_ptr[__VdlyDim0__drive_sound__DOT__wr_ptr__v0] 
            = __VdlyVal__drive_sound__DOT__wr_ptr__v0;
    }
    if (__VdlySet__drive_sound__DOT__sel__v0) {
        vlSelfRef.drive_sound__DOT__sel[0U] = 1U;
    }
    if (__VdlySet__drive_sound__DOT__sel__v1) {
        vlSelfRef.drive_sound__DOT__sel[0U] = 2U;
    }
    if (__VdlySet__drive_sound__DOT__sel__v2) {
        vlSelfRef.drive_sound__DOT__sel[0U] = 1U;
    }
    if (__VdlySet__drive_sound__DOT__sel__v3) {
        vlSelfRef.drive_sound__DOT__sel[0U] = 2U;
    }
    if (__VdlySet__drive_sound__DOT__sel__v4) {
        vlSelfRef.drive_sound__DOT__sel[0U] = 0U;
    }
    if (__VdlySet__drive_sound__DOT__rem_f__v0) {
        vlSelfRef.drive_sound__DOT__fptr[__VdlyDim0__drive_sound__DOT__fptr__v0] 
            = __VdlyVal__drive_sound__DOT__fptr__v0;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v1) {
        vlSelfRef.drive_sound__DOT__fptr[0U] = 0U;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v2) {
        vlSelfRef.drive_sound__DOT__fptr[0U] = 0U;
    }
    if (__VdlySet__drive_sound__DOT__rem_f__v0) {
        vlSelfRef.drive_sound__DOT__rem_f[__VdlyDim0__drive_sound__DOT__rem_f__v0] 
            = __VdlyVal__drive_sound__DOT__rem_f__v0;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v1) {
        vlSelfRef.drive_sound__DOT__rem_f[0U] = __VdlyVal__drive_sound__DOT__rem_f__v1;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v2) {
        vlSelfRef.drive_sound__DOT__rem_f[0U] = __VdlyVal__drive_sound__DOT__rem_f__v2;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v3) {
        vlSelfRef.drive_sound__DOT__fptr[0U] = 0U;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v4) {
        vlSelfRef.drive_sound__DOT__fptr[0U] = 0U;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v3) {
        vlSelfRef.drive_sound__DOT__rem_f[0U] = __VdlyVal__drive_sound__DOT__rem_f__v3;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v4) {
        vlSelfRef.drive_sound__DOT__rem_f[0U] = __VdlyVal__drive_sound__DOT__rem_f__v4;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v5) {
        vlSelfRef.drive_sound__DOT__fptr[0U] = 0U;
        vlSelfRef.drive_sound__DOT__rem_f[0U] = __VdlyVal__drive_sound__DOT__rem_f__v5;
    }
    if (__VdlySet__drive_sound__DOT__sel__v5) {
        vlSelfRef.drive_sound__DOT__sel[1U] = __VdlyVal__drive_sound__DOT__sel__v5;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v6) {
        vlSelfRef.drive_sound__DOT__fptr[0U] = 0U;
        vlSelfRef.drive_sound__DOT__rem_f[0U] = __VdlyVal__drive_sound__DOT__rem_f__v6;
    }
    if (__VdlySet__drive_sound__DOT__sel__v5) {
        vlSelfRef.drive_sound__DOT__rem_f[1U] = __VdlyVal__drive_sound__DOT__rem_f__v7;
    }
    if (__VdlySet__drive_sound__DOT__rem_f__v8) {
        vlSelfRef.drive_sound__DOT__rem_f[0U] = 0U;
    }
    if (__VdlySet__drive_sound__DOT__rem_f__v9) {
        vlSelfRef.drive_sound__DOT__rem_f[1U] = 0U;
    }
    if (__VdlySet__drive_sound__DOT__rd_ptr__v0) {
        vlSelfRef.drive_sound__DOT__rd_ptr[0U] = __VdlyVal__drive_sound__DOT__rd_ptr__v0;
    }
    if (__VdlySet__drive_sound__DOT__rd_ptr__v1) {
        vlSelfRef.drive_sound__DOT__rd_ptr[1U] = __VdlyVal__drive_sound__DOT__rd_ptr__v1;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v1) {
        vlSelfRef.drive_sound__DOT__rd_ptr[0U] = __VdlyVal__drive_sound__DOT__rd_ptr__v2;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v3) {
        vlSelfRef.drive_sound__DOT__rd_ptr[0U] = __VdlyVal__drive_sound__DOT__rd_ptr__v3;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v5) {
        vlSelfRef.drive_sound__DOT__rd_ptr[0U] = __VdlyVal__drive_sound__DOT__rd_ptr__v4;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v6) {
        vlSelfRef.drive_sound__DOT__rd_ptr[0U] = __VdlyVal__drive_sound__DOT__rd_ptr__v5;
    }
    if (__VdlySet__drive_sound__DOT__fptr__v7) {
        vlSelfRef.drive_sound__DOT__fptr[1U] = 0U;
        vlSelfRef.drive_sound__DOT__rd_ptr[1U] = __VdlyVal__drive_sound__DOT__rd_ptr__v6;
    }
    vlSelfRef.drive_sound__DOT__snd_on = ((IData)(vlSelfRef.drive_sound__DOT__table_valid) 
                                          & ((~ (IData)(vlSelfRef.drive_sound__DOT__load)) 
                                             & (0U 
                                                != (IData)(vlSelfRef.drive_sound__DOT__volume))));
    vlSelfRef.drive_sound__DOT__unnamedblk1__DOT__load_d 
        = vlSelfRef.drive_sound__DOT__load;
    if (((IData)(vlSelfRef.drive_sound__DOT__load) 
         & (IData)(vlSelfRef.drive_sound__DOT__load_wr))) {
        __Vdly__drive_sound__DOT__wbuf = (((QData)((IData)(vlSelfRef.drive_sound__DOT__load_data)) 
                                           << 0x00000038U) 
                                          | (vlSelfRef.drive_sound__DOT__wbuf 
                                             >> 8U));
        if ((7U == (7U & vlSelfRef.drive_sound__DOT__load_addr))) {
            __Vdly__drive_sound__DOT__wr_pending = 1U;
        }
    }
    if ((((IData)(vlSelfRef.drive_sound__DOT__wr_pending) 
          & (IData)(vlSelfRef.drive_sound__DOT__ddr_we)) 
         & (~ (IData)(vlSelfRef.drive_sound__DOT__ddr_busy)))) {
        __Vdly__drive_sound__DOT__wr_pending = 0U;
        if ((0U == (vlSelfRef.drive_sound__DOT__wr_addr 
                    - (IData)(0x06080000U)))) {
            vlSelfRef.drive_sound__DOT__magic_ok = 
                (0x444e5344U == (IData)(vlSelfRef.drive_sound__DOT__wbuf));
        } else if ((((((1U == (vlSelfRef.drive_sound__DOT__wr_addr 
                               - (IData)(0x06080000U))) 
                       || (2U == (vlSelfRef.drive_sound__DOT__wr_addr 
                                  - (IData)(0x06080000U)))) 
                      || (3U == (vlSelfRef.drive_sound__DOT__wr_addr 
                                 - (IData)(0x06080000U)))) 
                     || (4U == (vlSelfRef.drive_sound__DOT__wr_addr 
                                - (IData)(0x06080000U)))) 
                    || (5U == (vlSelfRef.drive_sound__DOT__wr_addr 
                               - (IData)(0x06080000U))))) {
            if ((4U >= (7U & (vlSelfRef.drive_sound__DOT__wr_addr 
                              - (IData)(1U))))) {
                __VdlyVal__drive_sound__DOT__tbl_off__v0 
                    = (0x0007ffffU & (IData)((vlSelfRef.drive_sound__DOT__wbuf 
                                              >> 3U)));
                __VdlyDim0__drive_sound__DOT__tbl_off__v0 
                    = (7U & (vlSelfRef.drive_sound__DOT__wr_addr 
                             - (IData)(1U)));
                __VdlySet__drive_sound__DOT__tbl_off__v0 = 1U;
                __VdlyVal__drive_sound__DOT__tbl_len__v0 
                    = (0x001fffffU & (IData)((vlSelfRef.drive_sound__DOT__wbuf 
                                              >> 0x20U)));
                __VdlyDim0__drive_sound__DOT__tbl_len__v0 
                    = (7U & (vlSelfRef.drive_sound__DOT__wr_addr 
                             - (IData)(1U)));
                __VdlySet__drive_sound__DOT__tbl_len__v0 = 1U;
            }
        }
    }
    if (((IData)(vlSelfRef.drive_sound__DOT__load) 
         & (IData)(vlSelfRef.drive_sound__DOT__load_wr))) {
        if ((7U == (7U & vlSelfRef.drive_sound__DOT__load_addr))) {
            vlSelfRef.drive_sound__DOT__wr_addr = (0x1fffffffU 
                                                   & ((IData)(0x06080000U) 
                                                      + 
                                                      (0x003fffffU 
                                                       & (vlSelfRef.drive_sound__DOT__load_addr 
                                                          >> 3U))));
        }
    }
    if (vlSelfRef.drive_sound__DOT__reset) {
        __Vdly__drive_sound__DOT__wr_pending = 0U;
    }
    vlSelfRef.audio_out = vlSelfRef.drive_sound__DOT__audio_out;
    vlSelfRef.ddr_rd = vlSelfRef.drive_sound__DOT__ddr_rd;
    vlSelfRef.drive_sound__DOT__mot_act = (0U != (IData)(vlSelfRef.drive_sound__DOT__mstate));
    vlSelfRef.drive_sound__DOT__fifo_q = vlSelfRef.drive_sound__DOT__fifo
        [vlSelfRef.drive_sound__DOT__fifo_raddr];
    if (__VdlySet__drive_sound__DOT__rem_f__v0) {
        vlSelfRef.drive_sound__DOT__fifo[__VdlyDim0__drive_sound__DOT__fifo__v0] 
            = __VdlyVal__drive_sound__DOT__fifo__v0;
    }
    vlSelfRef.drive_sound__DOT__fill0 = (0x000000ffU 
                                         & ((IData)(vlSelfRef.drive_sound__DOT__wr_ptr[0U]) 
                                            - (IData)(vlSelfRef.drive_sound__DOT__rd_ptr[0U])));
    vlSelfRef.drive_sound__DOT__fill1 = (0x000000ffU 
                                         & ((IData)(vlSelfRef.drive_sound__DOT__wr_ptr[1U]) 
                                            - (IData)(vlSelfRef.drive_sound__DOT__rd_ptr[1U])));
    if (__VdlySet__drive_sound__DOT__tbl_off__v0) {
        vlSelfRef.drive_sound__DOT__tbl_off[__VdlyDim0__drive_sound__DOT__tbl_off__v0] 
            = __VdlyVal__drive_sound__DOT__tbl_off__v0;
    }
    if (__VdlySet__drive_sound__DOT__tbl_len__v0) {
        vlSelfRef.drive_sound__DOT__tbl_len[__VdlyDim0__drive_sound__DOT__tbl_len__v0] 
            = __VdlyVal__drive_sound__DOT__tbl_len__v0;
    }
    vlSelfRef.drive_sound__DOT__wbuf = __Vdly__drive_sound__DOT__wbuf;
    vlSelfRef.drive_sound__DOT__wr_pending = __Vdly__drive_sound__DOT__wr_pending;
    vlSelfRef.drive_sound__DOT__ddr_we = __Vdly__drive_sound__DOT__ddr_we;
    vlSelfRef.drive_sound__DOT__fifo_raddr = __Vdly__drive_sound__DOT__fifo_raddr;
    vlSelfRef.drive_sound__DOT__hd_act = ((0U != vlSelfRef.drive_sound__DOT__rem_f[1U]) 
                                          | (0U != (IData)(vlSelfRef.drive_sound__DOT__fill1)));
    vlSelfRef.drive_sound__DOT__ddr_din = vlSelfRef.drive_sound__DOT__wbuf;
    vlSelfRef.drive_sound__DOT__load_wait = vlSelfRef.drive_sound__DOT__wr_pending;
    if (vlSelfRef.drive_sound__DOT__ddr_we) {
        vlSelfRef.ddr_we = 1U;
        vlSelfRef.ddr_din = vlSelfRef.drive_sound__DOT__ddr_din;
        vlSelfRef.load_wait = vlSelfRef.drive_sound__DOT__load_wait;
        vlSelfRef.drive_sound__DOT__ddr_addr = vlSelfRef.drive_sound__DOT__wr_addr;
    } else {
        vlSelfRef.ddr_we = 0U;
        vlSelfRef.ddr_din = vlSelfRef.drive_sound__DOT__ddr_din;
        vlSelfRef.load_wait = vlSelfRef.drive_sound__DOT__load_wait;
        vlSelfRef.drive_sound__DOT__ddr_addr = vlSelfRef.drive_sound__DOT__f_addr;
    }
    vlSelfRef.ddr_addr = vlSelfRef.drive_sound__DOT__ddr_addr;
}

void Vdrive_sound___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdrive_sound___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vdrive_sound___024root___eval_phase__act(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_phase__act\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((IData)(vlSelfRef.drive_sound__DOT__clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__drive_sound__DOT__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__drive_sound__DOT__clk__0 
            = vlSelfRef.drive_sound__DOT__clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdrive_sound___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vdrive_sound___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vdrive_sound___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vdrive_sound___024root___eval_phase__nba(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_phase__nba\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vdrive_sound___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vdrive_sound___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vdrive_sound___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vdrive_sound___024root___eval(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vdrive_sound___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../rtl/drive_sound.sv", 30, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vdrive_sound___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vdrive_sound___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../rtl/drive_sound.sv", 30, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vdrive_sound___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../rtl/drive_sound.sv", 30, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vdrive_sound___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vdrive_sound___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vdrive_sound___024root___eval_debug_assertions(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_debug_assertions\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.ntsc & 0xfeU)))) {
        Verilated::overWidthError("ntsc");
    }
    if (VL_UNLIKELY(((vlSelfRef.step & 0xfcU)))) {
        Verilated::overWidthError("step");
    }
    if (VL_UNLIKELY(((vlSelfRef.bump & 0xfcU)))) {
        Verilated::overWidthError("bump");
    }
    if (VL_UNLIKELY(((vlSelfRef.motor & 0xfcU)))) {
        Verilated::overWidthError("motor");
    }
    if (VL_UNLIKELY(((vlSelfRef.volume & 0xfcU)))) {
        Verilated::overWidthError("volume");
    }
    if (VL_UNLIKELY(((vlSelfRef.load & 0xfeU)))) {
        Verilated::overWidthError("load");
    }
    if (VL_UNLIKELY(((vlSelfRef.load_wr & 0xfeU)))) {
        Verilated::overWidthError("load_wr");
    }
    if (VL_UNLIKELY(((vlSelfRef.load_addr & 0xfe000000U)))) {
        Verilated::overWidthError("load_addr");
    }
    if (VL_UNLIKELY(((vlSelfRef.ddr_busy & 0xfeU)))) {
        Verilated::overWidthError("ddr_busy");
    }
    if (VL_UNLIKELY(((vlSelfRef.ddr_ready & 0xfeU)))) {
        Verilated::overWidthError("ddr_ready");
    }
}
#endif  // VL_DEBUG
