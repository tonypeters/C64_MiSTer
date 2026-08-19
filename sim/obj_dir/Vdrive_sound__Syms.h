// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDRIVE_SOUND__SYMS_H_
#define VERILATED_VDRIVE_SOUND__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdrive_sound.h"

// INCLUDE MODULE CLASSES
#include "Vdrive_sound___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vdrive_sound__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdrive_sound* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdrive_sound___024root         TOP;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_TOP;
    VerilatedScope* __Vscopep_drive_sound;
    VerilatedScope* __Vscopep_drive_sound__unnamedblk1;

    // CONSTRUCTORS
    Vdrive_sound__Syms(VerilatedContext* contextp, const char* namep, Vdrive_sound* modelp);
    ~Vdrive_sound__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
