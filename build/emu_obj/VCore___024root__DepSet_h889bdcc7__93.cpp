// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCore.h for the primary calling header

#include "VCore__pch.h"
#include "VCore___024root.h"

void VCore___024root___eval_triggers__act(VCore___024root* vlSelf);
void VCore___024root___eval_act(VCore___024root* vlSelf);

bool VCore___024root___eval_phase__act(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root___eval_phase__act\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VCore___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VCore___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void VCore___024root___eval_nba(VCore___024root* vlSelf);

bool VCore___024root___eval_phase__nba(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root___eval_phase__nba\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VCore___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCore___024root___dump_triggers__ico(VCore___024root* vlSelf);
#endif  // VL_DEBUG
bool VCore___024root___eval_phase__ico(VCore___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCore___024root___dump_triggers__nba(VCore___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCore___024root___dump_triggers__act(VCore___024root* vlSelf);
#endif  // VL_DEBUG

void VCore___024root___eval(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root___eval\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            VCore___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/emerald/zaqal/build/Core.sv", 69, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VCore___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VCore___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/emerald/zaqal/build/Core.sv", 69, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VCore___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/emerald/zaqal/build/Core.sv", 69, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VCore___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VCore___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VCore___024root___eval_debug_assertions(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root___eval_debug_assertions\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY(((vlSelfRef.io_mem_req_ready & 0xfeU)))) {
        Verilated::overWidthError("io_mem_req_ready");}
    if (VL_UNLIKELY(((vlSelfRef.io_mem_resp_valid & 0xfeU)))) {
        Verilated::overWidthError("io_mem_resp_valid");}
    if (VL_UNLIKELY(((vlSelfRef.io_mem_resp_bits_last 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_mem_resp_bits_last");}
    if (VL_UNLIKELY(((vlSelfRef.io_mem_d_req_ready 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_mem_d_req_ready");}
    if (VL_UNLIKELY(((vlSelfRef.io_mem_d_resp_valid 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_mem_d_resp_valid");}
    if (VL_UNLIKELY(((vlSelfRef.io_mem_d_resp_bits_last 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_mem_d_resp_bits_last");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_a_ready & 0xfeU)))) {
        Verilated::overWidthError("io_tl_d_a_ready");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_b_valid & 0xfeU)))) {
        Verilated::overWidthError("io_tl_d_b_valid");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_b_bits_opcode 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_tl_d_b_bits_opcode");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_b_bits_param 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_tl_d_b_bits_param");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_b_bits_size 
                      & 0xf0U)))) {
        Verilated::overWidthError("io_tl_d_b_bits_size");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_b_bits_source 
                      & 0xc0U)))) {
        Verilated::overWidthError("io_tl_d_b_bits_source");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_b_bits_corrupt 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_tl_d_b_bits_corrupt");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_c_ready & 0xfeU)))) {
        Verilated::overWidthError("io_tl_d_c_ready");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_d_valid & 0xfeU)))) {
        Verilated::overWidthError("io_tl_d_d_valid");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_d_bits_opcode 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_tl_d_d_bits_opcode");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_d_bits_param 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_tl_d_d_bits_param");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_d_bits_size 
                      & 0xf0U)))) {
        Verilated::overWidthError("io_tl_d_d_bits_size");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_d_bits_source 
                      & 0xc0U)))) {
        Verilated::overWidthError("io_tl_d_d_bits_source");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_d_bits_sink 
                      & 0xc0U)))) {
        Verilated::overWidthError("io_tl_d_d_bits_sink");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_d_bits_denied 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_tl_d_d_bits_denied");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_d_bits_corrupt 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_tl_d_d_bits_corrupt");}
    if (VL_UNLIKELY(((vlSelfRef.io_tl_d_e_ready & 0xfeU)))) {
        Verilated::overWidthError("io_tl_d_e_ready");}
}
#endif  // VL_DEBUG
