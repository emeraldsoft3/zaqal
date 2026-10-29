// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCore.h for the primary calling header

#include "VCore__pch.h"
#include "VCore__Syms.h"
#include "VCore___024unit.h"

extern "C" void difftest_InstrCommit(char coreid, char index, svBit valid, long long pc, int instr, svBit skip, svBit isRVC, svBit rfwen, svBit fpwen, svBit vecwen, char wdest, long long data);

VL_INLINE_OPT void VCore___024unit____Vdpiimwrap_difftest_InstrCommit_TOP____024unit(CData/*7:0*/ coreid, CData/*7:0*/ index, CData/*0:0*/ valid, QData/*63:0*/ pc, IData/*31:0*/ instr, CData/*0:0*/ skip, CData/*0:0*/ isRVC, CData/*0:0*/ rfwen, CData/*0:0*/ fpwen, CData/*0:0*/ vecwen, CData/*7:0*/ wdest, QData/*63:0*/ data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCore___024unit____Vdpiimwrap_difftest_InstrCommit_TOP____024unit\n"); );
    // Body
    char coreid__Vcvt;
    coreid__Vcvt = coreid;
    char index__Vcvt;
    index__Vcvt = index;
    svBit valid__Vcvt;
    valid__Vcvt = valid;
    long long pc__Vcvt;
    pc__Vcvt = pc;
    int instr__Vcvt;
    instr__Vcvt = instr;
    svBit skip__Vcvt;
    skip__Vcvt = skip;
    svBit isRVC__Vcvt;
    isRVC__Vcvt = isRVC;
    svBit rfwen__Vcvt;
    rfwen__Vcvt = rfwen;
    svBit fpwen__Vcvt;
    fpwen__Vcvt = fpwen;
    svBit vecwen__Vcvt;
    vecwen__Vcvt = vecwen;
    char wdest__Vcvt;
    wdest__Vcvt = wdest;
    long long data__Vcvt;
    data__Vcvt = data;
    difftest_InstrCommit(coreid__Vcvt, index__Vcvt, valid__Vcvt, pc__Vcvt, instr__Vcvt, skip__Vcvt, isRVC__Vcvt, rfwen__Vcvt, fpwen__Vcvt, vecwen__Vcvt, wdest__Vcvt, data__Vcvt);
}

extern "C" void difftest_TrapEvent(char coreid, svBit valid, char code, long long pc, long long cycle);

VL_INLINE_OPT void VCore___024unit____Vdpiimwrap_difftest_TrapEvent_TOP____024unit(CData/*7:0*/ coreid, CData/*0:0*/ valid, CData/*7:0*/ code, QData/*63:0*/ pc, QData/*63:0*/ cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCore___024unit____Vdpiimwrap_difftest_TrapEvent_TOP____024unit\n"); );
    // Body
    char coreid__Vcvt;
    coreid__Vcvt = coreid;
    svBit valid__Vcvt;
    valid__Vcvt = valid;
    char code__Vcvt;
    code__Vcvt = code;
    long long pc__Vcvt;
    pc__Vcvt = pc;
    long long cycle__Vcvt;
    cycle__Vcvt = cycle;
    difftest_TrapEvent(coreid__Vcvt, valid__Vcvt, code__Vcvt, pc__Vcvt, cycle__Vcvt);
}
