// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdrive_sound.h for the primary calling header

#include "Vdrive_sound__pch.h"

VL_ATTR_COLD void Vdrive_sound___024root___eval_static(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_static\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.drive_sound__DOT__table_valid = 0U;
        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
        vlSelfRef.drive_sound__DOT__unnamedblk1__DOT__load_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3731444768847836547ull);
        vlSelfRef.drive_sound__DOT__mstate = 0U;
        vlSelfRef.drive_sound__DOT__fstate = 0U;
        vlSelfRef.drive_sound__DOT__oseq = 0U;
    }
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
    vlSelfRef.__Vtrigprevexpr___TOP__drive_sound__DOT__clk__0 
        = vlSelfRef.drive_sound__DOT__clk;
}

VL_ATTR_COLD void Vdrive_sound___024root___eval_initial(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_initial\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.ddr_burstcnt = 1U;
        vlSelfRef.drive_sound__DOT__ddr_burstcnt = 1U;
    }
}

VL_ATTR_COLD void Vdrive_sound___024root___eval_final(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_final\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdrive_sound___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdrive_sound___024root___eval_phase__stl(Vdrive_sound___024root* vlSelf);

VL_ATTR_COLD void Vdrive_sound___024root___eval_settle(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_settle\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vdrive_sound___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../rtl/drive_sound.sv", 30, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vdrive_sound___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vdrive_sound___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdrive_sound___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vdrive_sound___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vdrive_sound___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD bool Vdrive_sound___024root___eval_phase__stl(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___eval_phase__stl\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdrive_sound___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vdrive_sound___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                {
                    // Inlined CFunc: _stl_sequent__TOP__0
                    vlSelfRef.drive_sound__DOT__clk 
                        = vlSelfRef.clk;
                    vlSelfRef.drive_sound__DOT__reset 
                        = vlSelfRef.reset;
                    vlSelfRef.drive_sound__DOT__step 
                        = vlSelfRef.step;
                    vlSelfRef.drive_sound__DOT__bump 
                        = vlSelfRef.bump;
                    vlSelfRef.drive_sound__DOT__load_wr 
                        = vlSelfRef.load_wr;
                    vlSelfRef.drive_sound__DOT__load_addr 
                        = vlSelfRef.load_addr;
                    vlSelfRef.drive_sound__DOT__load_data 
                        = vlSelfRef.load_data;
                    vlSelfRef.drive_sound__DOT__ddr_busy 
                        = vlSelfRef.ddr_busy;
                    vlSelfRef.ddr_we = vlSelfRef.drive_sound__DOT__ddr_we;
                    vlSelfRef.ddr_rd = vlSelfRef.drive_sound__DOT__ddr_rd;
                    vlSelfRef.drive_sound__DOT__ddr_dout 
                        = vlSelfRef.ddr_dout;
                    vlSelfRef.drive_sound__DOT__ddr_ready 
                        = vlSelfRef.ddr_ready;
                    vlSelfRef.audio_out = vlSelfRef.drive_sound__DOT__audio_out;
                    vlSelfRef.drive_sound__DOT__mot_act 
                        = (0U != (IData)(vlSelfRef.drive_sound__DOT__mstate));
                    vlSelfRef.drive_sound__DOT__fill0 
                        = (0x000000ffU & ((IData)(vlSelfRef.drive_sound__DOT__wr_ptr[0U]) 
                                          - (IData)(vlSelfRef.drive_sound__DOT__rd_ptr[0U])));
                    vlSelfRef.drive_sound__DOT__ntsc 
                        = vlSelfRef.ntsc;
                    vlSelfRef.drive_sound__DOT__motor 
                        = vlSelfRef.motor;
                    vlSelfRef.drive_sound__DOT__load_wait 
                        = vlSelfRef.drive_sound__DOT__wr_pending;
                    vlSelfRef.drive_sound__DOT__ddr_din 
                        = vlSelfRef.drive_sound__DOT__wbuf;
                    vlSelfRef.drive_sound__DOT__volume 
                        = vlSelfRef.volume;
                    vlSelfRef.drive_sound__DOT__load 
                        = vlSelfRef.load;
                    vlSelfRef.drive_sound__DOT__ddr_addr 
                        = ((IData)(vlSelfRef.drive_sound__DOT__ddr_we)
                            ? vlSelfRef.drive_sound__DOT__wr_addr
                            : vlSelfRef.drive_sound__DOT__f_addr);
                    vlSelfRef.drive_sound__DOT__fill1 
                        = (0x000000ffU & ((IData)(vlSelfRef.drive_sound__DOT__wr_ptr[1U]) 
                                          - (IData)(vlSelfRef.drive_sound__DOT__rd_ptr[1U])));
                    vlSelfRef.drive_sound__DOT__divmax 
                        = ((IData)(vlSelfRef.drive_sound__DOT__ntsc)
                            ? 0x07fcU : 0x07b1U);
                    vlSelfRef.drive_sound__DOT__mtr_on 
                        = (0U != (IData)(vlSelfRef.drive_sound__DOT__motor));
                    vlSelfRef.load_wait = vlSelfRef.drive_sound__DOT__load_wait;
                    vlSelfRef.ddr_din = vlSelfRef.drive_sound__DOT__ddr_din;
                    vlSelfRef.drive_sound__DOT__snd_on 
                        = ((IData)(vlSelfRef.drive_sound__DOT__table_valid) 
                           & ((~ (IData)(vlSelfRef.drive_sound__DOT__load)) 
                              & (0U != (IData)(vlSelfRef.drive_sound__DOT__volume))));
                    vlSelfRef.ddr_addr = vlSelfRef.drive_sound__DOT__ddr_addr;
                    vlSelfRef.drive_sound__DOT__hd_act 
                        = ((0U != vlSelfRef.drive_sound__DOT__rem_f[1U]) 
                           | (0U != (IData)(vlSelfRef.drive_sound__DOT__fill1)));
                }
            }
        }
    }
    return (__VstlExecute);
}

bool Vdrive_sound___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdrive_sound___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vdrive_sound___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( ntsc)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( step)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( bump)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @( motor)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @( volume)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @( load)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @( load_wr)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @( load_addr)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @( load_data)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @( ddr_busy)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 12 is active: @( ddr_dout)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 13 is active: @( ddr_ready)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vdrive_sound___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdrive_sound___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vdrive_sound___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge drive_sound.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdrive_sound___024root___ctor_var_reset(Vdrive_sound___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdrive_sound___024root___ctor_var_reset\n"); );
    Vdrive_sound__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->ntsc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2976193588104925908ull);
    vlSelf->step = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6399494957627430472ull);
    vlSelf->bump = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11199208576331586388ull);
    vlSelf->motor = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11167658272809320596ull);
    vlSelf->volume = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7699327401757349171ull);
    vlSelf->load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1148748992964133306ull);
    vlSelf->load_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1031951698852033173ull);
    vlSelf->load_addr = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 4617866286526414823ull);
    vlSelf->load_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9762156056485505432ull);
    vlSelf->load_wait = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4551674861174746552ull);
    vlSelf->ddr_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15409013951706940078ull);
    vlSelf->ddr_addr = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 16863598742676895022ull);
    vlSelf->ddr_burstcnt = 1U;
    ;
    vlSelf->ddr_rd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9234584257600189541ull);
    vlSelf->ddr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15423180479648388075ull);
    vlSelf->ddr_din = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14302332706012207439ull);
    vlSelf->ddr_dout = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13607875976680885400ull);
    vlSelf->ddr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 533639635671566117ull);
    vlSelf->audio_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16887251779955964156ull);
    vlSelf->drive_sound__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13499978294158578107ull);
    vlSelf->drive_sound__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5857574553182469483ull);
    vlSelf->drive_sound__DOT__ntsc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16307936659352054974ull);
    vlSelf->drive_sound__DOT__step = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6507747188476297575ull);
    vlSelf->drive_sound__DOT__bump = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7156572314865945012ull);
    vlSelf->drive_sound__DOT__motor = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17120222584965616501ull);
    vlSelf->drive_sound__DOT__volume = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15411631143548699821ull);
    vlSelf->drive_sound__DOT__load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14216968042126014778ull);
    vlSelf->drive_sound__DOT__load_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4221668467761332728ull);
    vlSelf->drive_sound__DOT__load_addr = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 2393295398365172907ull);
    vlSelf->drive_sound__DOT__load_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4092741321614366120ull);
    vlSelf->drive_sound__DOT__load_wait = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8152228440180200324ull);
    vlSelf->drive_sound__DOT__ddr_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2955287206386165132ull);
    vlSelf->drive_sound__DOT__ddr_addr = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 2578892806881834485ull);
    vlSelf->drive_sound__DOT__ddr_burstcnt = 1U;
    ;
    vlSelf->drive_sound__DOT__ddr_rd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9514102906205554485ull);
    vlSelf->drive_sound__DOT__ddr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 535479070734355143ull);
    vlSelf->drive_sound__DOT__ddr_din = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10221741769935468166ull);
    vlSelf->drive_sound__DOT__ddr_dout = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13492566787356584310ull);
    vlSelf->drive_sound__DOT__ddr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15337824954253754598ull);
    vlSelf->drive_sound__DOT__audio_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14150846368754543104ull);
    vlSelf->drive_sound__DOT__wbuf = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10582090752177065128ull);
    vlSelf->drive_sound__DOT__wr_pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14555438151010195633ull);
    vlSelf->drive_sound__DOT__wr_addr = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 15413725426102745505ull);
    vlSelf->drive_sound__DOT__magic_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8007147750747860113ull);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->drive_sound__DOT__tbl_off[__Vi0] = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 2997197973005450356ull);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->drive_sound__DOT__tbl_len[__Vi0] = VL_SCOPED_RAND_RESET_I(21, __VscopeHash, 17325997543372724179ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->drive_sound__DOT__sel[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1964512616492607856ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->drive_sound__DOT__rem_f[__Vi0] = VL_SCOPED_RAND_RESET_I(21, __VscopeHash, 9710967609387039919ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->drive_sound__DOT__fptr[__Vi0] = VL_SCOPED_RAND_RESET_I(21, __VscopeHash, 14021294366639431460ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->drive_sound__DOT__wr_ptr[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12702460640065043447ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->drive_sound__DOT__rd_ptr[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6985186432020623396ull);
    }
    vlSelf->drive_sound__DOT__fill0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18405984247965759969ull);
    vlSelf->drive_sound__DOT__fill1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4268399864247743248ull);
    vlSelf->drive_sound__DOT__snd_on = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12464484898343480115ull);
    vlSelf->drive_sound__DOT__mtr_on = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4849305524772170561ull);
    vlSelf->drive_sound__DOT__mot_act = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6750032441950558813ull);
    vlSelf->drive_sound__DOT__hd_act = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 545893023197338329ull);
    vlSelf->drive_sound__DOT__h_trig = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3930473537554384150ull);
    vlSelf->drive_sound__DOT__h_sel = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12157823485051373508ull);
    vlSelf->drive_sound__DOT__fv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11742714921299703143ull);
    vlSelf->drive_sound__DOT__wcnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14088322379625633727ull);
    vlSelf->drive_sound__DOT__beat = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2974201005316901708ull);
    vlSelf->drive_sound__DOT__f_addr = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 1622947229872201807ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->drive_sound__DOT__fifo[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6213033213258484283ull);
    }
    vlSelf->drive_sound__DOT__fifo_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10418876314859114571ull);
    vlSelf->drive_sound__DOT__fifo_raddr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 7316069776546955468ull);
    vlSelf->drive_sound__DOT__div = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 498385624637041486ull);
    vlSelf->drive_sound__DOT__s0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5480243540348288954ull);
    vlSelf->drive_sound__DOT__s1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13953340418550766328ull);
    vlSelf->drive_sound__DOT__sum = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 196724358563875871ull);
    vlSelf->drive_sound__DOT__divmax = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 12539169847679884049ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ntsc__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__step__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__bump__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__motor__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__volume__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__load__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__load_wr__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__load_addr__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__load_data__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ddr_busy__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ddr_dout__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ddr_ready__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__drive_sound__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
