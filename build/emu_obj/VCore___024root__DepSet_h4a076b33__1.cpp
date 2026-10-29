// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCore.h for the primary calling header

#include "VCore__pch.h"
#include "VCore__Syms.h"
#include "VCore___024root.h"

void VCore___024root___nba_sequent__TOP__0(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__1(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__2(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__3(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__4(VCore___024root* vlSelf);

void VCore___024root__nba_mtask0(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask0\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 0;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__0(vlSelf);
        VCore___024root___nba_sequent__TOP__1(vlSelf);
        VCore___024root___nba_sequent__TOP__2(vlSelf);
        VCore___024root___nba_sequent__TOP__3(vlSelf);
        VCore___024root___nba_sequent__TOP__4(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__7(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__8(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__9(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__10(VCore___024root* vlSelf);

void VCore___024root__nba_mtask1(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask1\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 1;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__7(vlSelf);
        VCore___024root___nba_sequent__TOP__8(vlSelf);
        VCore___024root___nba_sequent__TOP__9(vlSelf);
        VCore___024root___nba_sequent__TOP__10(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__13(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__14(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__15(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__16(VCore___024root* vlSelf);

void VCore___024root__nba_mtask2(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask2\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 2;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__13(vlSelf);
        VCore___024root___nba_sequent__TOP__14(vlSelf);
        VCore___024root___nba_sequent__TOP__15(vlSelf);
        VCore___024root___nba_sequent__TOP__16(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__18(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__20(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__21(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__22(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__23(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__24(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__25(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__26(VCore___024root* vlSelf);

void VCore___024root__nba_mtask3(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask3\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 3;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__18(vlSelf);
        VCore___024root___nba_sequent__TOP__20(vlSelf);
        VCore___024root___nba_sequent__TOP__21(vlSelf);
        VCore___024root___nba_sequent__TOP__22(vlSelf);
        VCore___024root___nba_sequent__TOP__23(vlSelf);
        VCore___024root___nba_sequent__TOP__24(vlSelf);
        VCore___024root___nba_sequent__TOP__25(vlSelf);
        VCore___024root___nba_sequent__TOP__26(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__28(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__29(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__30(VCore___024root* vlSelf);

void VCore___024root__nba_mtask4(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask4\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 4;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__28(vlSelf);
        VCore___024root___nba_sequent__TOP__29(vlSelf);
        VCore___024root___nba_sequent__TOP__30(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__31(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__32(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__33(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__34(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__35(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__36(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__37(VCore___024root* vlSelf);

void VCore___024root__nba_mtask5(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask5\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 5;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__31(vlSelf);
        VCore___024root___nba_sequent__TOP__32(vlSelf);
        VCore___024root___nba_sequent__TOP__33(vlSelf);
        VCore___024root___nba_sequent__TOP__34(vlSelf);
        VCore___024root___nba_sequent__TOP__35(vlSelf);
        VCore___024root___nba_sequent__TOP__36(vlSelf);
        VCore___024root___nba_sequent__TOP__37(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__40(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__41(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__42(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__43(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__44(VCore___024root* vlSelf);

void VCore___024root__nba_mtask6(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask6\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 6;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__40(vlSelf);
        VCore___024root___nba_sequent__TOP__41(vlSelf);
        VCore___024root___nba_sequent__TOP__42(vlSelf);
        VCore___024root___nba_sequent__TOP__43(vlSelf);
        VCore___024root___nba_sequent__TOP__44(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__45(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__46(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__47(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__48(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__49(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__50(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__51(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__52(VCore___024root* vlSelf);

void VCore___024root__nba_mtask7(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask7\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 7;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__45(vlSelf);
        VCore___024root___nba_sequent__TOP__46(vlSelf);
        VCore___024root___nba_sequent__TOP__47(vlSelf);
        VCore___024root___nba_sequent__TOP__48(vlSelf);
        VCore___024root___nba_sequent__TOP__49(vlSelf);
        VCore___024root___nba_sequent__TOP__50(vlSelf);
        VCore___024root___nba_sequent__TOP__51(vlSelf);
        VCore___024root___nba_sequent__TOP__52(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__53(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__54(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__55(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__56(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__57(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__58(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__59(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__60(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__61(VCore___024root* vlSelf);

void VCore___024root__nba_mtask8(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask8\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 8;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__53(vlSelf);
        VCore___024root___nba_sequent__TOP__54(vlSelf);
        VCore___024root___nba_sequent__TOP__55(vlSelf);
        VCore___024root___nba_sequent__TOP__56(vlSelf);
        VCore___024root___nba_sequent__TOP__57(vlSelf);
        VCore___024root___nba_sequent__TOP__58(vlSelf);
        VCore___024root___nba_sequent__TOP__59(vlSelf);
        VCore___024root___nba_sequent__TOP__60(vlSelf);
        VCore___024root___nba_sequent__TOP__61(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__63(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__64(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__65(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__66(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__67(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__68(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__69(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__70(VCore___024root* vlSelf);

void VCore___024root__nba_mtask9(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask9\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 9;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__63(vlSelf);
        VCore___024root___nba_sequent__TOP__64(vlSelf);
        VCore___024root___nba_sequent__TOP__65(vlSelf);
        VCore___024root___nba_sequent__TOP__66(vlSelf);
        VCore___024root___nba_sequent__TOP__67(vlSelf);
        VCore___024root___nba_sequent__TOP__68(vlSelf);
        VCore___024root___nba_sequent__TOP__69(vlSelf);
        VCore___024root___nba_sequent__TOP__70(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__71(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__72(VCore___024root* vlSelf);

void VCore___024root__nba_mtask10(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask10\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 10;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__71(vlSelf);
        VCore___024root___nba_sequent__TOP__72(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__73(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__74(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__75(VCore___024root* vlSelf);

void VCore___024root__nba_mtask11(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask11\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 11;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__73(vlSelf);
        VCore___024root___nba_sequent__TOP__74(vlSelf);
        VCore___024root___nba_sequent__TOP__75(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__76(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__77(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__78(VCore___024root* vlSelf);

void VCore___024root__nba_mtask12(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask12\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 12;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__76(vlSelf);
        VCore___024root___nba_sequent__TOP__77(vlSelf);
        VCore___024root___nba_sequent__TOP__78(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__79(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__80(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__81(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__82(VCore___024root* vlSelf);

void VCore___024root__nba_mtask13(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask13\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 13;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__79(vlSelf);
        VCore___024root___nba_sequent__TOP__80(vlSelf);
        VCore___024root___nba_sequent__TOP__81(vlSelf);
        VCore___024root___nba_sequent__TOP__82(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__85(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__86(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__87(VCore___024root* vlSelf);

void VCore___024root__nba_mtask14(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask14\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 14;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__85(vlSelf);
        VCore___024root___nba_sequent__TOP__86(vlSelf);
        VCore___024root___nba_sequent__TOP__87(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__88(VCore___024root* vlSelf);

void VCore___024root__nba_mtask15(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask15\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 15;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__88(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__89(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__90(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__91(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__92(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__93(VCore___024root* vlSelf);

void VCore___024root__nba_mtask16(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask16\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 16;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__89(vlSelf);
        VCore___024root___nba_sequent__TOP__90(vlSelf);
        VCore___024root___nba_sequent__TOP__91(vlSelf);
        VCore___024root___nba_sequent__TOP__92(vlSelf);
        VCore___024root___nba_sequent__TOP__93(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__94(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__95(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__96(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__97(VCore___024root* vlSelf);

void VCore___024root__nba_mtask17(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask17\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 17;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__94(vlSelf);
        VCore___024root___nba_sequent__TOP__95(vlSelf);
        VCore___024root___nba_sequent__TOP__96(vlSelf);
        VCore___024root___nba_sequent__TOP__97(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__98(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__99(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__100(VCore___024root* vlSelf);

void VCore___024root__nba_mtask18(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask18\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 18;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__98(vlSelf);
        VCore___024root___nba_sequent__TOP__99(vlSelf);
        VCore___024root___nba_sequent__TOP__100(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__101(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__102(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__103(VCore___024root* vlSelf);

void VCore___024root__nba_mtask19(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask19\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 19;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__101(vlSelf);
        VCore___024root___nba_sequent__TOP__102(vlSelf);
        VCore___024root___nba_sequent__TOP__103(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__104(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__105(VCore___024root* vlSelf);

void VCore___024root__nba_mtask20(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask20\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 20;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__104(vlSelf);
        VCore___024root___nba_sequent__TOP__105(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__106(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__107(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__108(VCore___024root* vlSelf);

void VCore___024root__nba_mtask21(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask21\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 21;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__106(vlSelf);
        VCore___024root___nba_sequent__TOP__107(vlSelf);
        VCore___024root___nba_sequent__TOP__108(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__109(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__110(VCore___024root* vlSelf);

void VCore___024root__nba_mtask22(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask22\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 22;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__109(vlSelf);
        VCore___024root___nba_sequent__TOP__110(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__111(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__112(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__113(VCore___024root* vlSelf);

void VCore___024root__nba_mtask23(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask23\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 23;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__111(vlSelf);
        VCore___024root___nba_sequent__TOP__112(vlSelf);
        VCore___024root___nba_sequent__TOP__113(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__114(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__115(VCore___024root* vlSelf);

void VCore___024root__nba_mtask24(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask24\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 24;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__114(vlSelf);
        VCore___024root___nba_sequent__TOP__115(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__116(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__117(VCore___024root* vlSelf);

void VCore___024root__nba_mtask25(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask25\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 25;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__116(vlSelf);
        VCore___024root___nba_sequent__TOP__117(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__118(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__119(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__120(VCore___024root* vlSelf);

void VCore___024root__nba_mtask26(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask26\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 26;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__118(vlSelf);
        VCore___024root___nba_sequent__TOP__119(vlSelf);
        VCore___024root___nba_sequent__TOP__120(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__121(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__122(VCore___024root* vlSelf);

void VCore___024root__nba_mtask27(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask27\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 27;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__121(vlSelf);
        VCore___024root___nba_sequent__TOP__122(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__123(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__127(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__128(VCore___024root* vlSelf);

void VCore___024root__nba_mtask28(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask28\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 28;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__123(vlSelf);
        VCore___024root___nba_sequent__TOP__127(vlSelf);
        VCore___024root___nba_sequent__TOP__128(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__129(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__130(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__131(VCore___024root* vlSelf);

void VCore___024root__nba_mtask29(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask29\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 29;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__129(vlSelf);
        VCore___024root___nba_sequent__TOP__130(vlSelf);
        VCore___024root___nba_sequent__TOP__131(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__132(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__133(VCore___024root* vlSelf);

void VCore___024root__nba_mtask30(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask30\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 30;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__132(vlSelf);
        VCore___024root___nba_sequent__TOP__133(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__134(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__135(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__136(VCore___024root* vlSelf);

void VCore___024root__nba_mtask31(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask31\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 31;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__134(vlSelf);
        VCore___024root___nba_sequent__TOP__135(vlSelf);
        VCore___024root___nba_sequent__TOP__136(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__137(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__138(VCore___024root* vlSelf);

void VCore___024root__nba_mtask32(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask32\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 32;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__137(vlSelf);
        VCore___024root___nba_sequent__TOP__138(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__139(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__140(VCore___024root* vlSelf);

void VCore___024root__nba_mtask33(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask33\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 33;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__139(vlSelf);
        VCore___024root___nba_sequent__TOP__140(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__141(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__142(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__143(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__144(VCore___024root* vlSelf);

void VCore___024root__nba_mtask34(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask34\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 34;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__141(vlSelf);
        VCore___024root___nba_sequent__TOP__142(vlSelf);
        VCore___024root___nba_sequent__TOP__143(vlSelf);
        VCore___024root___nba_sequent__TOP__144(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__145(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__146(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__147(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__148(VCore___024root* vlSelf);

void VCore___024root__nba_mtask35(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask35\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 35;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__145(vlSelf);
        VCore___024root___nba_sequent__TOP__146(vlSelf);
        VCore___024root___nba_sequent__TOP__147(vlSelf);
        VCore___024root___nba_sequent__TOP__148(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__149(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__150(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__151(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__152(VCore___024root* vlSelf);

void VCore___024root__nba_mtask36(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask36\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 36;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__149(vlSelf);
        VCore___024root___nba_sequent__TOP__150(vlSelf);
        VCore___024root___nba_sequent__TOP__151(vlSelf);
        VCore___024root___nba_sequent__TOP__152(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root___nba_sequent__TOP__153(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__154(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__155(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__156(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__157(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__158(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__159(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__160(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__161(VCore___024root* vlSelf);
void VCore___024root___nba_sequent__TOP__162(VCore___024root* vlSelf);

void VCore___024root__nba_mtask37(VCore___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root__nba_mtask37\n"); );
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 37;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCore___024root___nba_sequent__TOP__153(vlSelf);
        VCore___024root___nba_sequent__TOP__154(vlSelf);
        VCore___024root___nba_sequent__TOP__155(vlSelf);
        VCore___024root___nba_sequent__TOP__156(vlSelf);
        VCore___024root___nba_sequent__TOP__157(vlSelf);
        VCore___024root___nba_sequent__TOP__158(vlSelf);
        VCore___024root___nba_sequent__TOP__159(vlSelf);
        VCore___024root___nba_sequent__TOP__160(vlSelf);
        VCore___024root___nba_sequent__TOP__161(vlSelf);
        VCore___024root___nba_sequent__TOP__162(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VCore___024root____Vthread__nba__s0__t0(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root____Vthread__nba__s0__t0\n"); );
    // Body
    VCore___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCore___024root*>(voidSelf);
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VCore___024root__nba_mtask7(vlSelf);
    vlSelf->__Vm_mtaskstate_14.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_21.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_22.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask9(vlSelf);
    vlSelf->__Vm_mtaskstate_20.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_21.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_22.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask3(vlSelf);
    vlSelf->__Vm_mtaskstate_28.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_16.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask16(vlSelf);
    vlSelf->__Vm_mtaskstate_24.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_23.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask23(vlSelf);
    vlSelf->__Vm_mtaskstate_25.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_26.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask26(vlSelf);
    vlSelf->__Vm_mtaskstate_27.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_29.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_30.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask30(vlSelf);
    vlSelf->__Vm_mtaskstate_31.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_32.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask32(vlSelf);
    vlSelf->__Vm_mtaskstate_33.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_36.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_37.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask35(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VCore___024root____Vthread__nba__s0__t1(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root____Vthread__nba__s0__t1\n"); );
    // Body
    VCore___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCore___024root*>(voidSelf);
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VCore___024root__nba_mtask11(vlSelf);
    vlSelf->__Vm_mtaskstate_16.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_18.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_19.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask8(vlSelf);
    vlSelf->__Vm_mtaskstate_18.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_20.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_21.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_17.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask17(vlSelf);
    vlSelf->__Vm_mtaskstate_20.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_21.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask4(vlSelf);
    vlSelf->__Vm_mtaskstate_14.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_23.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_22.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask22(vlSelf);
    vlSelf->__Vm_mtaskstate_23.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_24.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask6(vlSelf);
    vlSelf->__Vm_mtaskstate_28.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask28(vlSelf);
    vlSelf->__Vm_mtaskstate_31.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask31(vlSelf);
    vlSelf->__Vm_mtaskstate_37.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask37(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VCore___024root____Vthread__nba__s0__t2(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root____Vthread__nba__s0__t2\n"); );
    // Body
    VCore___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCore___024root*>(voidSelf);
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VCore___024root__nba_mtask12(vlSelf);
    vlSelf->__Vm_mtaskstate_15.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_17.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask5(vlSelf);
    vlSelf->__Vm_mtaskstate_23.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask1(vlSelf);
    vlSelf->__Vm_mtaskstate_23.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_28.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_20.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask20(vlSelf);
    vlSelf->__Vm_mtaskstate_23.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_18.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask18(vlSelf);
    vlSelf->__Vm_mtaskstate_23.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_14.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask14(vlSelf);
    vlSelf->__Vm_mtaskstate_24.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask24(vlSelf);
    vlSelf->__Vm_mtaskstate_26.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_28.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_25.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask25(vlSelf);
    vlSelf->__Vm_mtaskstate_29.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_30.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_27.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask27(vlSelf);
    vlSelf->__Vm_mtaskstate_31.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_32.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask34(vlSelf);
    vlSelf->__Vm_mtaskstate_33.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask33(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VCore___024root____Vthread__nba__s0__t3(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore___024root____Vthread__nba__s0__t3\n"); );
    // Body
    VCore___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCore___024root*>(voidSelf);
    VCore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VCore___024root__nba_mtask13(vlSelf);
    VCore___024root__nba_mtask10(vlSelf);
    vlSelf->__Vm_mtaskstate_17.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask0(vlSelf);
    vlSelf->__Vm_mtaskstate_20.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_22.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_15.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask15(vlSelf);
    vlSelf->__Vm_mtaskstate_16.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_18.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_19.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask19(vlSelf);
    vlSelf->__Vm_mtaskstate_20.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_22.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_21.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask21(vlSelf);
    vlSelf->__Vm_mtaskstate_24.signalUpstreamDone(even_cycle);
    VCore___024root__nba_mtask2(vlSelf);
    vlSelf->__Vm_mtaskstate_28.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_29.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask29(vlSelf);
    vlSelf->__Vm_mtaskstate_37.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_36.waitUntilUpstreamDone(even_cycle);
    VCore___024root__nba_mtask36(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}
