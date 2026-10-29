// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VCORE__DPI_H_
#define VERILATED_VCORE__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/emerald/zaqal/build/DifftestInstrCommit.v:2:30
    extern void difftest_InstrCommit(char coreid, char index, svBit valid, long long pc, int instr, svBit skip, svBit isRVC, svBit rfwen, svBit fpwen, svBit vecwen, char wdest, long long data);
    // DPI import at /home/emerald/zaqal/build/DifftestTrapEvent.v:2:30
    extern void difftest_TrapEvent(char coreid, svBit valid, char code, long long pc, long long cycle);

#ifdef __cplusplus
}
#endif

#endif  // guard
