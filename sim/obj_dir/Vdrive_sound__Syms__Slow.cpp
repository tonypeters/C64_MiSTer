// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vdrive_sound__pch.h"

Vdrive_sound__Syms::Vdrive_sound__Syms(VerilatedContext* contextp, const char* namep, Vdrive_sound* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(500);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_drive_sound = new VerilatedScope{this, "drive_sound", "drive_sound", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_drive_sound__unnamedblk1 = new VerilatedScope{this, "drive_sound.unnamedblk1", "unnamedblk1", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("audio_out", &(TOP.audio_out), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("bump", &(TOP.bump), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("ddr_addr", &(TOP.ddr_addr), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,28,0);
    __Vscopep_TOP->varInsert("ddr_burstcnt", &(TOP.ddr_burstcnt), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("ddr_busy", &(TOP.ddr_busy), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("ddr_din", &(TOP.ddr_din), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("ddr_dout", &(TOP.ddr_dout), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("ddr_rd", &(TOP.ddr_rd), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("ddr_ready", &(TOP.ddr_ready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("ddr_we", &(TOP.ddr_we), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("load", &(TOP.load), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("load_addr", &(TOP.load_addr), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,24,0);
    __Vscopep_TOP->varInsert("load_data", &(TOP.load_data), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("load_wait", &(TOP.load_wait), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("load_wr", &(TOP.load_wr), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("motor", &(TOP.motor), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("ntsc", &(TOP.ntsc), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("reset", &(TOP.reset), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("step", &(TOP.step), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("volume", &(TOP.volume), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("F_DATA", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__F_DATA))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("F_IDLE", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__F_IDLE))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("F_REQ", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__F_REQ))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("F_WR", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__F_WR))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("MAGIC", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__MAGIC))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_drive_sound->varInsert("M_LOOP", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__M_LOOP))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("M_OFF", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__M_OFF))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("M_SPINDOWN", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__M_SPINDOWN))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("M_SPINUP", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__M_SPINUP))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("SND_BASE", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__SND_BASE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,28,0);
    __Vscopep_drive_sound->varInsert("S_BUMP", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__S_BUMP))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_drive_sound->varInsert("S_LOOP", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__S_LOOP))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_drive_sound->varInsert("S_SPINDOWN", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__S_SPINDOWN))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_drive_sound->varInsert("S_SPINUP", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__S_SPINUP))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_drive_sound->varInsert("S_STEP", const_cast<void*>(static_cast<const void*>(&(TOP.drive_sound__DOT__S_STEP))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_drive_sound->varInsert("audio_out", &(TOP.drive_sound__DOT__audio_out), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_drive_sound->varInsert("beat", &(TOP.drive_sound__DOT__beat), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_drive_sound->varInsert("bump", &(TOP.drive_sound__DOT__bump), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("clk", &(TOP.drive_sound__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("ddr_addr", &(TOP.drive_sound__DOT__ddr_addr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,28,0);
    __Vscopep_drive_sound->varInsert("ddr_burstcnt", &(TOP.drive_sound__DOT__ddr_burstcnt), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_drive_sound->varInsert("ddr_busy", &(TOP.drive_sound__DOT__ddr_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("ddr_din", &(TOP.drive_sound__DOT__ddr_din), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_drive_sound->varInsert("ddr_dout", &(TOP.drive_sound__DOT__ddr_dout), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_drive_sound->varInsert("ddr_rd", &(TOP.drive_sound__DOT__ddr_rd), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("ddr_ready", &(TOP.drive_sound__DOT__ddr_ready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("ddr_we", &(TOP.drive_sound__DOT__ddr_we), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("div", &(TOP.drive_sound__DOT__div), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,11,0);
    __Vscopep_drive_sound->varInsert("divmax", &(TOP.drive_sound__DOT__divmax), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 1 ,11,0);
    __Vscopep_drive_sound->varInsert("f_addr", &(TOP.drive_sound__DOT__f_addr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,28,0);
    __Vscopep_drive_sound->varInsert("fifo", &(TOP.drive_sound__DOT__fifo), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,511 ,15,0);
    __Vscopep_drive_sound->varInsert("fifo_q", &(TOP.drive_sound__DOT__fifo_q), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_drive_sound->varInsert("fifo_raddr", &(TOP.drive_sound__DOT__fifo_raddr), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,8,0);
    __Vscopep_drive_sound->varInsert("fill0", &(TOP.drive_sound__DOT__fill0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 1 ,7,0);
    __Vscopep_drive_sound->varInsert("fill1", &(TOP.drive_sound__DOT__fill1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 1 ,7,0);
    __Vscopep_drive_sound->varInsert("fptr", &(TOP.drive_sound__DOT__fptr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,1 ,20,0);
    __Vscopep_drive_sound->varInsert("fstate", &(TOP.drive_sound__DOT__fstate), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("fv", &(TOP.drive_sound__DOT__fv), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("h_sel", &(TOP.drive_sound__DOT__h_sel), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_drive_sound->varInsert("h_trig", &(TOP.drive_sound__DOT__h_trig), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("hd_act", &(TOP.drive_sound__DOT__hd_act), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 0);
    __Vscopep_drive_sound->varInsert("load", &(TOP.drive_sound__DOT__load), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("load_addr", &(TOP.drive_sound__DOT__load_addr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,24,0);
    __Vscopep_drive_sound->varInsert("load_data", &(TOP.drive_sound__DOT__load_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_drive_sound->varInsert("load_wait", &(TOP.drive_sound__DOT__load_wait), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_drive_sound->varInsert("load_wr", &(TOP.drive_sound__DOT__load_wr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("magic_ok", &(TOP.drive_sound__DOT__magic_ok), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("mot_act", &(TOP.drive_sound__DOT__mot_act), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 0);
    __Vscopep_drive_sound->varInsert("motor", &(TOP.drive_sound__DOT__motor), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("mstate", &(TOP.drive_sound__DOT__mstate), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("mtr_on", &(TOP.drive_sound__DOT__mtr_on), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 0);
    __Vscopep_drive_sound->varInsert("ntsc", &(TOP.drive_sound__DOT__ntsc), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("oseq", &(TOP.drive_sound__DOT__oseq), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_drive_sound->varInsert("rd_ptr", &(TOP.drive_sound__DOT__rd_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,1 ,7,0);
    __Vscopep_drive_sound->varInsert("rem_f", &(TOP.drive_sound__DOT__rem_f), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,1 ,20,0);
    __Vscopep_drive_sound->varInsert("reset", &(TOP.drive_sound__DOT__reset), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("s0", &(TOP.drive_sound__DOT__s0), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,15,0);
    __Vscopep_drive_sound->varInsert("s1", &(TOP.drive_sound__DOT__s1), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,15,0);
    __Vscopep_drive_sound->varInsert("sel", &(TOP.drive_sound__DOT__sel), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,1 ,2,0);
    __Vscopep_drive_sound->varInsert("snd_on", &(TOP.drive_sound__DOT__snd_on), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 0);
    __Vscopep_drive_sound->varInsert("step", &(TOP.drive_sound__DOT__step), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("sum", &(TOP.drive_sound__DOT__sum), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,16,0);
    __Vscopep_drive_sound->varInsert("table_valid", &(TOP.drive_sound__DOT__table_valid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("tbl_len", &(TOP.drive_sound__DOT__tbl_len), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,4 ,20,0);
    __Vscopep_drive_sound->varInsert("tbl_off", &(TOP.drive_sound__DOT__tbl_off), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,4 ,18,0);
    __Vscopep_drive_sound->varInsert("volume", &(TOP.drive_sound__DOT__volume), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("wbuf", &(TOP.drive_sound__DOT__wbuf), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_drive_sound->varInsert("wcnt", &(TOP.drive_sound__DOT__wcnt), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_drive_sound->varInsert("wr_addr", &(TOP.drive_sound__DOT__wr_addr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,28,0);
    __Vscopep_drive_sound->varInsert("wr_pending", &(TOP.drive_sound__DOT__wr_pending), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_drive_sound->varInsert("wr_ptr", &(TOP.drive_sound__DOT__wr_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,1 ,7,0);
    __Vscopep_drive_sound__unnamedblk1->varInsert("load_d", &(TOP.drive_sound__DOT__unnamedblk1__DOT__load_d), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vdrive_sound__Syms::~Vdrive_sound__Syms() {
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_drive_sound, __Vscopep_drive_sound = nullptr);
    VL_DO_CLEAR(delete __Vscopep_drive_sound__unnamedblk1, __Vscopep_drive_sound__unnamedblk1 = nullptr);
    // Tear down sub module instances
}
