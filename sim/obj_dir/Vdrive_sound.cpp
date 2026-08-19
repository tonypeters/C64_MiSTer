// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdrive_sound__pch.h"

//============================================================
// Constructors

Vdrive_sound::Vdrive_sound(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdrive_sound__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , ntsc{vlSymsp->TOP.ntsc}
    , step{vlSymsp->TOP.step}
    , bump{vlSymsp->TOP.bump}
    , motor{vlSymsp->TOP.motor}
    , volume{vlSymsp->TOP.volume}
    , load{vlSymsp->TOP.load}
    , load_wr{vlSymsp->TOP.load_wr}
    , load_data{vlSymsp->TOP.load_data}
    , load_wait{vlSymsp->TOP.load_wait}
    , ddr_busy{vlSymsp->TOP.ddr_busy}
    , ddr_burstcnt{vlSymsp->TOP.ddr_burstcnt}
    , ddr_rd{vlSymsp->TOP.ddr_rd}
    , ddr_we{vlSymsp->TOP.ddr_we}
    , ddr_ready{vlSymsp->TOP.ddr_ready}
    , audio_out{vlSymsp->TOP.audio_out}
    , load_addr{vlSymsp->TOP.load_addr}
    , ddr_addr{vlSymsp->TOP.ddr_addr}
    , ddr_din{vlSymsp->TOP.ddr_din}
    , ddr_dout{vlSymsp->TOP.ddr_dout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdrive_sound::Vdrive_sound(const char* _vcname__)
    : Vdrive_sound(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdrive_sound::~Vdrive_sound() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdrive_sound___024root___eval_debug_assertions(Vdrive_sound___024root* vlSelf);
#endif  // VL_DEBUG
void Vdrive_sound___024root___eval_static(Vdrive_sound___024root* vlSelf);
void Vdrive_sound___024root___eval_initial(Vdrive_sound___024root* vlSelf);
void Vdrive_sound___024root___eval_settle(Vdrive_sound___024root* vlSelf);
void Vdrive_sound___024root___eval(Vdrive_sound___024root* vlSelf);

void Vdrive_sound::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdrive_sound::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdrive_sound___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdrive_sound___024root___eval_static(&(vlSymsp->TOP));
        Vdrive_sound___024root___eval_initial(&(vlSymsp->TOP));
        Vdrive_sound___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdrive_sound___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdrive_sound::eventsPending() { return false; }

uint64_t Vdrive_sound::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdrive_sound::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdrive_sound___024root___eval_final(Vdrive_sound___024root* vlSelf);

VL_ATTR_COLD void Vdrive_sound::final() {
    contextp()->executingFinal(true);
    Vdrive_sound___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdrive_sound::hierName() const { return vlSymsp->name(); }
const char* Vdrive_sound::modelName() const { return "Vdrive_sound"; }
unsigned Vdrive_sound::threads() const { return 1; }
void Vdrive_sound::prepareClone() const { contextp()->prepareClone(); }
void Vdrive_sound::atClone() const {
    contextp()->threadPoolpOnClone();
}
