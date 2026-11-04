// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VZaqalSoCTop.h for the primary calling header

#ifndef VERILATED_VZAQALSOCTOP___024UNIT_H_
#define VERILATED_VZAQALSOCTOP___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VZaqalSoCTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VZaqalSoCTop___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    VZaqalSoCTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VZaqalSoCTop___024unit(VZaqalSoCTop__Syms* symsp, const char* v__name);
    ~VZaqalSoCTop___024unit();
    VL_UNCOPYABLE(VZaqalSoCTop___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
