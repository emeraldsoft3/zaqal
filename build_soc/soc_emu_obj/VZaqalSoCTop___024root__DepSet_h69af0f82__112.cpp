// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VZaqalSoCTop.h for the primary calling header

#include "VZaqalSoCTop__pch.h"
#include "VZaqalSoCTop___024root.h"

void VZaqalSoCTop___024root___eval_triggers__act(VZaqalSoCTop___024root* vlSelf);
void VZaqalSoCTop___024root___eval_act(VZaqalSoCTop___024root* vlSelf);

bool VZaqalSoCTop___024root___eval_phase__act(VZaqalSoCTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VZaqalSoCTop___024root___eval_phase__act\n"); );
    VZaqalSoCTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VZaqalSoCTop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VZaqalSoCTop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void VZaqalSoCTop___024root___eval_nba(VZaqalSoCTop___024root* vlSelf);

bool VZaqalSoCTop___024root___eval_phase__nba(VZaqalSoCTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VZaqalSoCTop___024root___eval_phase__nba\n"); );
    VZaqalSoCTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VZaqalSoCTop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VZaqalSoCTop___024root___dump_triggers__ico(VZaqalSoCTop___024root* vlSelf);
#endif  // VL_DEBUG
bool VZaqalSoCTop___024root___eval_phase__ico(VZaqalSoCTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VZaqalSoCTop___024root___dump_triggers__nba(VZaqalSoCTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VZaqalSoCTop___024root___dump_triggers__act(VZaqalSoCTop___024root* vlSelf);
#endif  // VL_DEBUG

void VZaqalSoCTop___024root___eval(VZaqalSoCTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VZaqalSoCTop___024root___eval\n"); );
    VZaqalSoCTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VZaqalSoCTop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/emerald/zaqal/build_soc/ZaqalSoCTop.sv", 69, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VZaqalSoCTop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VZaqalSoCTop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/emerald/zaqal/build_soc/ZaqalSoCTop.sv", 69, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VZaqalSoCTop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/emerald/zaqal/build_soc/ZaqalSoCTop.sv", 69, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VZaqalSoCTop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VZaqalSoCTop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VZaqalSoCTop___024root___eval_debug_assertions(VZaqalSoCTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VZaqalSoCTop___024root___eval_debug_assertions\n"); );
    VZaqalSoCTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY(((vlSelfRef.io_spi_miso & 0xfeU)))) {
        Verilated::overWidthError("io_spi_miso");}
}
#endif  // VL_DEBUG
