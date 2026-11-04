// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VZaqalSoCTop.h for the primary calling header

#include "VZaqalSoCTop__pch.h"
#include "VZaqalSoCTop__Syms.h"
#include "VZaqalSoCTop___024unit.h"

void VZaqalSoCTop___024unit___ctor_var_reset(VZaqalSoCTop___024unit* vlSelf);

VZaqalSoCTop___024unit::VZaqalSoCTop___024unit(VZaqalSoCTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VZaqalSoCTop___024unit___ctor_var_reset(this);
}

void VZaqalSoCTop___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VZaqalSoCTop___024unit::~VZaqalSoCTop___024unit() {
}
