// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdrive_sound.h for the primary calling header

#include "Vdrive_sound__pch.h"

// Parameter definitions for Vdrive_sound___024root
constexpr CData/*1:0*/ Vdrive_sound___024root::drive_sound__DOT__M_OFF;
constexpr CData/*1:0*/ Vdrive_sound___024root::drive_sound__DOT__M_SPINUP;
constexpr CData/*1:0*/ Vdrive_sound___024root::drive_sound__DOT__M_LOOP;
constexpr CData/*1:0*/ Vdrive_sound___024root::drive_sound__DOT__M_SPINDOWN;
constexpr CData/*2:0*/ Vdrive_sound___024root::drive_sound__DOT__S_SPINUP;
constexpr CData/*2:0*/ Vdrive_sound___024root::drive_sound__DOT__S_LOOP;
constexpr CData/*2:0*/ Vdrive_sound___024root::drive_sound__DOT__S_SPINDOWN;
constexpr CData/*2:0*/ Vdrive_sound___024root::drive_sound__DOT__S_STEP;
constexpr CData/*2:0*/ Vdrive_sound___024root::drive_sound__DOT__S_BUMP;
constexpr CData/*1:0*/ Vdrive_sound___024root::drive_sound__DOT__F_IDLE;
constexpr CData/*1:0*/ Vdrive_sound___024root::drive_sound__DOT__F_REQ;
constexpr CData/*1:0*/ Vdrive_sound___024root::drive_sound__DOT__F_DATA;
constexpr CData/*1:0*/ Vdrive_sound___024root::drive_sound__DOT__F_WR;
constexpr IData/*28:0*/ Vdrive_sound___024root::drive_sound__DOT__SND_BASE;
constexpr IData/*31:0*/ Vdrive_sound___024root::drive_sound__DOT__MAGIC;


void Vdrive_sound___024root___ctor_var_reset(Vdrive_sound___024root* vlSelf);

Vdrive_sound___024root::Vdrive_sound___024root(Vdrive_sound__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vdrive_sound___024root___ctor_var_reset(this);
}

void Vdrive_sound___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vdrive_sound___024root::~Vdrive_sound___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
