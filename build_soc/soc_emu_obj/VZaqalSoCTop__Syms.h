// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VZAQALSOCTOP__SYMS_H_
#define VERILATED_VZAQALSOCTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VZaqalSoCTop.h"

// INCLUDE MODULE CLASSES
#include "VZaqalSoCTop___024root.h"
#include "VZaqalSoCTop___024unit.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VZaqalSoCTop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VZaqalSoCTop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MULTI-THREADING
    VlThreadPool* __Vm_threadPoolp;
    bool __Vm_even_cycle__ico = false;
    bool __Vm_even_cycle__act = false;
    bool __Vm_even_cycle__nba = false;

    // MODULE INSTANCE STATE
    VZaqalSoCTop___024root         TOP;
    VZaqalSoCTop___024unit         TOP____024unit;

    // CONSTRUCTORS
    VZaqalSoCTop__Syms(VerilatedContext* contextp, const char* namep, VZaqalSoCTop* modelp);
    ~VZaqalSoCTop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
