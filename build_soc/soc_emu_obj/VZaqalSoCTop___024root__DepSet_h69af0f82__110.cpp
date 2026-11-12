// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VZaqalSoCTop.h for the primary calling header

#include "VZaqalSoCTop__pch.h"
#include "VZaqalSoCTop___024root.h"

VL_INLINE_OPT void VZaqalSoCTop___024root___nba_sequent__TOP__187(VZaqalSoCTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VZaqalSoCTop___024root___nba_sequent__TOP__187\n"); );
    VZaqalSoCTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_915;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_915 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_918;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_918 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_921;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_921 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_924;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_924 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1689;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1689 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1690;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1690 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1691;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1691 = 0;
    CData/*0:0*/ ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1692;
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1692 = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<4>/*127:0*/ __Vtemp_6;
    // Body
    __Vtemp_1[0U] = (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_31_exception_type_13) 
                              << 0xeU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_31_exception_type_13) 
                                          << 0xcU)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_31_exception_type_13) 
                                << 0xaU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_exception_type_13) 
                                            << 8U))) 
                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_31_exception_type_13) 
                                << 6U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_31_exception_type_13) 
                                          << 4U)) | 
                              (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_31_exception_type_13) 
                                << 2U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_31_exception_type_13)))) 
                          >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                         << 0x1eU) | (0x30000000U & 
                                      (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_30_exception_type_13) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_30_exception_type_13) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_30_exception_type_13) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_exception_type_13) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_30_exception_type_13) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_exception_type_13) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_30_exception_type_13) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_30_exception_type_13)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0x1cU))) 
                       | ((0xc000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_29_exception_type_13) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_29_exception_type_13) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_29_exception_type_13) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_exception_type_13) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_29_exception_type_13) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_exception_type_13) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_29_exception_type_13) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_29_exception_type_13)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x1aU)) 
                          | (0x3000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_28_exception_type_13) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_28_exception_type_13) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_28_exception_type_13) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_exception_type_13) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_exception_type_13) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_exception_type_13) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_28_exception_type_13) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_28_exception_type_13)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x18U)))) 
                      | (((0xc00000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_27_exception_type_13) 
                                             << 0xeU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_27_exception_type_13) 
                                               << 0xcU)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_27_exception_type_13) 
                                               << 0xaU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_exception_type_13) 
                                                 << 8U))) 
                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_27_exception_type_13) 
                                               << 6U) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_27_exception_type_13) 
                                                 << 4U)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_27_exception_type_13) 
                                                 << 2U) 
                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_27_exception_type_13)))) 
                                         >> (0xfU & 
                                             VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                        << 0x16U)) 
                          | (0x300000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_26_exception_type_13) 
                                               << 0xeU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_26_exception_type_13) 
                                                 << 0xcU)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_26_exception_type_13) 
                                                 << 0xaU) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_exception_type_13) 
                                                   << 8U))) 
                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_exception_type_13) 
                                                 << 6U) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_exception_type_13) 
                                                   << 4U)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_26_exception_type_13) 
                                                   << 2U) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_26_exception_type_13)))) 
                                           >> (0xfU 
                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                          << 0x14U))) 
                         | ((0xc0000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_25_exception_type_13) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_25_exception_type_13) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_25_exception_type_13) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_exception_type_13) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_exception_type_13) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_25_exception_type_13) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_25_exception_type_13) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_25_exception_type_13)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x12U)) 
                            | (0x30000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_24_exception_type_13) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_24_exception_type_13) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_24_exception_type_13) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_exception_type_13) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_exception_type_13) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_exception_type_13) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_24_exception_type_13) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_exception_type_13)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x10U))))) 
                     | ((((0xc000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_23_exception_type_13) 
                                           << 0xeU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_23_exception_type_13) 
                                             << 0xcU)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_23_exception_type_13) 
                                             << 0xaU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_exception_type_13) 
                                               << 8U))) 
                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_23_exception_type_13) 
                                             << 6U) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_23_exception_type_13) 
                                               << 4U)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_23_exception_type_13) 
                                               << 2U) 
                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_exception_type_13)))) 
                                       >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                      << 0xeU)) | (0x3000U 
                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_22_exception_type_13) 
                                                           << 0xeU) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_22_exception_type_13) 
                                                             << 0xcU)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_22_exception_type_13) 
                                                             << 0xaU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_exception_type_13) 
                                                               << 8U))) 
                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_22_exception_type_13) 
                                                             << 6U) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_22_exception_type_13) 
                                                               << 4U)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_22_exception_type_13) 
                                                               << 2U) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_22_exception_type_13)))) 
                                                       >> 
                                                       (0xfU 
                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                      << 0xcU))) 
                         | ((0xc00U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_21_exception_type_13) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_21_exception_type_13) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_21_exception_type_13) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_exception_type_13) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_exception_type_13) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_exception_type_13) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_21_exception_type_13) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_exception_type_13)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0xaU)) | 
                            (0x300U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_20_exception_type_13) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_20_exception_type_13) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_20_exception_type_13) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_exception_type_13) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_20_exception_type_13) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_20_exception_type_13) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_20_exception_type_13) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_20_exception_type_13)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 8U)))) | 
                        (((0xc0U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_19_exception_type_13) 
                                         << 0xeU) | 
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_19_exception_type_13) 
                                         << 0xcU)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_19_exception_type_13) 
                                           << 0xaU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_exception_type_13) 
                                             << 8U))) 
                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_exception_type_13) 
                                           << 6U) | 
                                          ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_19_exception_type_13) 
                                           << 4U)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_19_exception_type_13) 
                                             << 2U) 
                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_19_exception_type_13)))) 
                                     >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                    << 6U)) | (0x30U 
                                               & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_18_exception_type_13) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_18_exception_type_13) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_18_exception_type_13) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_exception_type_13) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_exception_type_13) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_18_exception_type_13) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_18_exception_type_13) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_18_exception_type_13)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                  << 4U))) 
                         | ((0xcU & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_17_exception_type_13) 
                                          << 0xeU) 
                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_17_exception_type_13) 
                                            << 0xcU)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_17_exception_type_13) 
                                            << 0xaU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_exception_type_13) 
                                              << 8U))) 
                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_exception_type_13) 
                                            << 6U) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_17_exception_type_13) 
                                              << 4U)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_17_exception_type_13) 
                                              << 2U) 
                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_exception_type_13)))) 
                                      >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                     << 2U)) | (3U 
                                                & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_16_exception_type_13) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_16_exception_type_13) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_16_exception_type_13) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_exception_type_13) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_exception_type_13) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_16_exception_type_13) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_16_exception_type_13) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_16_exception_type_13)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))));
    __Vtemp_1[1U] = (IData)((((QData)((IData)((((((
                                                   ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_63_exception_type_13) 
                                                        << 0xeU) 
                                                       | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_63_exception_type_13) 
                                                          << 0xcU)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_63_exception_type_13) 
                                                          << 0xaU) 
                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_63_exception_type_13) 
                                                            << 8U))) 
                                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_exception_type_13) 
                                                          << 6U) 
                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_exception_type_13) 
                                                            << 4U)) 
                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_63_exception_type_13) 
                                                            << 2U) 
                                                           | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_exception_type_13)))) 
                                                    >> 
                                                    (0xfU 
                                                     & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                   << 0x1eU) 
                                                  | (0x30000000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_62_exception_type_13) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_62_exception_type_13) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_exception_type_13) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_62_exception_type_13) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_62_exception_type_13) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_62_exception_type_13) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_62_exception_type_13) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_exception_type_13)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0x1cU))) 
                                                 | ((0xc000000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_exception_type_13) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_exception_type_13) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_exception_type_13) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_61_exception_type_13) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_61_exception_type_13) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_exception_type_13) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_61_exception_type_13) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_exception_type_13)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0x1aU)) 
                                                    | (0x3000000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_60_exception_type_13) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_60_exception_type_13) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_60_exception_type_13) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_60_exception_type_13) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_exception_type_13) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_60_exception_type_13) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_60_exception_type_13) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_60_exception_type_13)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0x18U)))) 
                                                | (((0xc00000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_59_exception_type_13) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_59_exception_type_13) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_59_exception_type_13) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_59_exception_type_13) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_59_exception_type_13) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_59_exception_type_13) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_59_exception_type_13) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_59_exception_type_13)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0x16U)) 
                                                    | (0x300000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_58_exception_type_13) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_58_exception_type_13) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_58_exception_type_13) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_58_exception_type_13) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_exception_type_13) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_58_exception_type_13) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_58_exception_type_13) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_exception_type_13)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0x14U))) 
                                                   | ((0xc0000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_exception_type_13) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_57_exception_type_13) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_57_exception_type_13) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_exception_type_13) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_exception_type_13) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_57_exception_type_13) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_57_exception_type_13) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_exception_type_13)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0x12U)) 
                                                      | (0x30000U 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_56_exception_type_13) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_56_exception_type_13) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_56_exception_type_13) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_56_exception_type_13) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_56_exception_type_13) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_exception_type_13) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_56_exception_type_13) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_exception_type_13)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 0x10U))))) 
                                               | ((((0xc000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_55_exception_type_13) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_55_exception_type_13) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_55_exception_type_13) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_55_exception_type_13) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_55_exception_type_13) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_55_exception_type_13) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_55_exception_type_13) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_exception_type_13)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0xeU)) 
                                                    | (0x3000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_54_exception_type_13) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_54_exception_type_13) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_54_exception_type_13) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_exception_type_13) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_54_exception_type_13) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_54_exception_type_13) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_54_exception_type_13) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_exception_type_13)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0xcU))) 
                                                   | ((0xc00U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_53_exception_type_13) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_53_exception_type_13) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_53_exception_type_13) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_exception_type_13) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_53_exception_type_13) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_53_exception_type_13) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_exception_type_13) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_exception_type_13)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0xaU)) 
                                                      | (0x300U 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_52_exception_type_13) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_exception_type_13) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_exception_type_13) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_exception_type_13) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_52_exception_type_13) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_exception_type_13) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_52_exception_type_13) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_52_exception_type_13)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 8U)))) 
                                                  | (((0xc0U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_51_exception_type_13) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_51_exception_type_13) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_51_exception_type_13) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_exception_type_13) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_51_exception_type_13) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_51_exception_type_13) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_exception_type_13) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_exception_type_13)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 6U)) 
                                                      | (0x30U 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_50_exception_type_13) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_50_exception_type_13) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_50_exception_type_13) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_exception_type_13) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_50_exception_type_13) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_50_exception_type_13) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_50_exception_type_13) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_exception_type_13)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 4U))) 
                                                     | ((0xcU 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_49_exception_type_13) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_49_exception_type_13) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_49_exception_type_13) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_exception_type_13) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_49_exception_type_13) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_exception_type_13) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_49_exception_type_13) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_exception_type_13)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 2U)) 
                                                        | (3U 
                                                           & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_48_exception_type_13) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_48_exception_type_13) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_48_exception_type_13) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_exception_type_13) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_48_exception_type_13) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_exception_type_13) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_48_exception_type_13) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_exception_type_13)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U)))))))))) 
                              << 0x20U) | (QData)((IData)(
                                                          (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_47_exception_type_13) 
                                                                    << 0xeU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_exception_type_13) 
                                                                      << 0xcU)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_47_exception_type_13) 
                                                                      << 0xaU) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_exception_type_13) 
                                                                        << 8U))) 
                                                                 | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_47_exception_type_13) 
                                                                      << 6U) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_exception_type_13) 
                                                                        << 4U)) 
                                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_47_exception_type_13) 
                                                                        << 2U) 
                                                                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_exception_type_13)))) 
                                                                >> 
                                                                (0xfU 
                                                                 & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                               << 0x1eU) 
                                                              | (0x30000000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_46_exception_type_13) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_46_exception_type_13) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_46_exception_type_13) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_exception_type_13) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_46_exception_type_13) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_46_exception_type_13) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_exception_type_13) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_46_exception_type_13)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0x1cU))) 
                                                             | ((0xc000000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_45_exception_type_13) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_exception_type_13) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_45_exception_type_13) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_exception_type_13) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_exception_type_13) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_exception_type_13) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_45_exception_type_13) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_exception_type_13)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0x1aU)) 
                                                                | (0x3000000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_44_exception_type_13) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_44_exception_type_13) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_44_exception_type_13) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_44_exception_type_13) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_44_exception_type_13) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_exception_type_13) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_44_exception_type_13) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_44_exception_type_13)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0x18U)))) 
                                                            | (((0xc00000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_43_exception_type_13) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_exception_type_13) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_43_exception_type_13) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_exception_type_13) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_43_exception_type_13) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_exception_type_13) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_exception_type_13) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_exception_type_13)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0x16U)) 
                                                                | (0x300000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_42_exception_type_13) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_exception_type_13) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_42_exception_type_13) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_exception_type_13) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_42_exception_type_13) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_42_exception_type_13) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_42_exception_type_13) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_42_exception_type_13)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0x14U))) 
                                                               | ((0xc0000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_41_exception_type_13) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_41_exception_type_13) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_41_exception_type_13) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_exception_type_13) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_41_exception_type_13) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_exception_type_13) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_41_exception_type_13) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_41_exception_type_13)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0x12U)) 
                                                                  | (0x30000U 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_40_exception_type_13) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_40_exception_type_13) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_40_exception_type_13) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_exception_type_13) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_40_exception_type_13) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_40_exception_type_13) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_40_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_exception_type_13)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 0x10U))))) 
                                                           | ((((0xc000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_39_exception_type_13) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_39_exception_type_13) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_39_exception_type_13) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_exception_type_13) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_39_exception_type_13) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_exception_type_13) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_exception_type_13) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_exception_type_13)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0xeU)) 
                                                                | (0x3000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_38_exception_type_13) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_38_exception_type_13) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_38_exception_type_13) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_exception_type_13) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_38_exception_type_13) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_38_exception_type_13) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_38_exception_type_13) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_exception_type_13)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0xcU))) 
                                                               | ((0xc00U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_37_exception_type_13) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_37_exception_type_13) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_exception_type_13) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_37_exception_type_13) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_37_exception_type_13) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_exception_type_13) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_37_exception_type_13) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_exception_type_13)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0xaU)) 
                                                                  | (0x300U 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_exception_type_13) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_36_exception_type_13) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_exception_type_13) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_36_exception_type_13) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_36_exception_type_13) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_36_exception_type_13) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_36_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_exception_type_13)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 8U)))) 
                                                              | (((0xc0U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_35_exception_type_13) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_35_exception_type_13) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_35_exception_type_13) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_exception_type_13) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_exception_type_13) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_exception_type_13) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_35_exception_type_13) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_exception_type_13)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 6U)) 
                                                                  | (0x30U 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_34_exception_type_13) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_34_exception_type_13) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_34_exception_type_13) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_34_exception_type_13) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_34_exception_type_13) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_exception_type_13) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_34_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_exception_type_13)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 4U))) 
                                                                 | ((0xcU 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_33_exception_type_13) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_33_exception_type_13) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_33_exception_type_13) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_exception_type_13) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_exception_type_13) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_exception_type_13) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_33_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_exception_type_13)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 2U)) 
                                                                    | (3U 
                                                                       & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_32_exception_type_13) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_32_exception_type_13) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_exception_type_13) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_exception_type_13) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_exception_type_13) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_32_exception_type_13) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_32_exception_type_13)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))))))));
    __Vtemp_1[2U] = (IData)(((((QData)((IData)(((((
                                                   (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_63_exception_type_13) 
                                                         << 0xeU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_63_exception_type_13) 
                                                           << 0xcU)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_63_exception_type_13) 
                                                           << 0xaU) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_63_exception_type_13) 
                                                             << 8U))) 
                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_exception_type_13) 
                                                           << 6U) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_exception_type_13) 
                                                             << 4U)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_63_exception_type_13) 
                                                             << 2U) 
                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_exception_type_13)))) 
                                                     >> 
                                                     (0xfU 
                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                    << 0x1eU) 
                                                   | (0x30000000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_62_exception_type_13) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_62_exception_type_13) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_exception_type_13) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_62_exception_type_13) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_62_exception_type_13) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_62_exception_type_13) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_62_exception_type_13) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_exception_type_13)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0x1cU))) 
                                                  | ((0xc000000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_exception_type_13) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_exception_type_13) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_exception_type_13) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_61_exception_type_13) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_61_exception_type_13) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_exception_type_13) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_61_exception_type_13) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_exception_type_13)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0x1aU)) 
                                                     | (0x3000000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_60_exception_type_13) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_60_exception_type_13) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_60_exception_type_13) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_60_exception_type_13) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_exception_type_13) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_60_exception_type_13) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_60_exception_type_13) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_60_exception_type_13)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0x18U)))) 
                                                 | (((0xc00000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_59_exception_type_13) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_59_exception_type_13) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_59_exception_type_13) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_59_exception_type_13) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_59_exception_type_13) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_59_exception_type_13) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_59_exception_type_13) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_59_exception_type_13)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0x16U)) 
                                                     | (0x300000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_58_exception_type_13) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_58_exception_type_13) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_58_exception_type_13) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_58_exception_type_13) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_exception_type_13) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_58_exception_type_13) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_58_exception_type_13) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_exception_type_13)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0x14U))) 
                                                    | ((0xc0000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_exception_type_13) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_57_exception_type_13) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_57_exception_type_13) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_exception_type_13) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_exception_type_13) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_57_exception_type_13) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_57_exception_type_13) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_exception_type_13)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0x12U)) 
                                                       | (0x30000U 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_56_exception_type_13) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_56_exception_type_13) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_56_exception_type_13) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_56_exception_type_13) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_56_exception_type_13) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_exception_type_13) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_56_exception_type_13) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_exception_type_13)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 0x10U))))) 
                                                | ((((0xc000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_55_exception_type_13) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_55_exception_type_13) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_55_exception_type_13) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_55_exception_type_13) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_55_exception_type_13) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_55_exception_type_13) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_55_exception_type_13) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_exception_type_13)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0xeU)) 
                                                     | (0x3000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_54_exception_type_13) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_54_exception_type_13) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_54_exception_type_13) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_exception_type_13) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_54_exception_type_13) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_54_exception_type_13) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_54_exception_type_13) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_exception_type_13)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0xcU))) 
                                                    | ((0xc00U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_53_exception_type_13) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_53_exception_type_13) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_53_exception_type_13) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_exception_type_13) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_53_exception_type_13) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_53_exception_type_13) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_exception_type_13) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_exception_type_13)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0xaU)) 
                                                       | (0x300U 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_52_exception_type_13) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_exception_type_13) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_exception_type_13) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_exception_type_13) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_52_exception_type_13) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_exception_type_13) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_52_exception_type_13) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_52_exception_type_13)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 8U)))) 
                                                   | (((0xc0U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_51_exception_type_13) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_51_exception_type_13) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_51_exception_type_13) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_exception_type_13) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_51_exception_type_13) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_51_exception_type_13) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_exception_type_13) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_exception_type_13)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 6U)) 
                                                       | (0x30U 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_50_exception_type_13) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_50_exception_type_13) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_50_exception_type_13) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_exception_type_13) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_50_exception_type_13) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_50_exception_type_13) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_50_exception_type_13) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_exception_type_13)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 4U))) 
                                                      | ((0xcU 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_49_exception_type_13) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_49_exception_type_13) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_49_exception_type_13) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_exception_type_13) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_49_exception_type_13) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_exception_type_13) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_49_exception_type_13) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_exception_type_13)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 2U)) 
                                                         | (3U 
                                                            & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_48_exception_type_13) 
                                                                   << 0xeU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_48_exception_type_13) 
                                                                     << 0xcU)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_48_exception_type_13) 
                                                                     << 0xaU) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_exception_type_13) 
                                                                       << 8U))) 
                                                                | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_48_exception_type_13) 
                                                                     << 6U) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_exception_type_13) 
                                                                       << 4U)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_48_exception_type_13) 
                                                                       << 2U) 
                                                                      | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_exception_type_13)))) 
                                                               >> 
                                                               (0xfU 
                                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U)))))))))) 
                               << 0x20U) | (QData)((IData)(
                                                           (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_47_exception_type_13) 
                                                                     << 0xeU) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_exception_type_13) 
                                                                       << 0xcU)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_47_exception_type_13) 
                                                                       << 0xaU) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_exception_type_13) 
                                                                         << 8U))) 
                                                                  | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_47_exception_type_13) 
                                                                       << 6U) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_exception_type_13) 
                                                                         << 4U)) 
                                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_47_exception_type_13) 
                                                                         << 2U) 
                                                                        | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_exception_type_13)))) 
                                                                 >> 
                                                                 (0xfU 
                                                                  & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                << 0x1eU) 
                                                               | (0x30000000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_46_exception_type_13) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_46_exception_type_13) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_46_exception_type_13) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_exception_type_13) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_46_exception_type_13) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_46_exception_type_13) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_exception_type_13) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_46_exception_type_13)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0x1cU))) 
                                                              | ((0xc000000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_45_exception_type_13) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_exception_type_13) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_45_exception_type_13) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_exception_type_13) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_exception_type_13) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_exception_type_13) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_45_exception_type_13) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_exception_type_13)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0x1aU)) 
                                                                 | (0x3000000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_44_exception_type_13) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_44_exception_type_13) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_44_exception_type_13) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_44_exception_type_13) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_44_exception_type_13) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_exception_type_13) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_44_exception_type_13) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_44_exception_type_13)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0x18U)))) 
                                                             | (((0xc00000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_43_exception_type_13) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_exception_type_13) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_43_exception_type_13) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_exception_type_13) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_43_exception_type_13) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_exception_type_13) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_exception_type_13) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_exception_type_13)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0x16U)) 
                                                                 | (0x300000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_42_exception_type_13) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_exception_type_13) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_42_exception_type_13) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_exception_type_13) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_42_exception_type_13) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_42_exception_type_13) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_42_exception_type_13) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_42_exception_type_13)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0x14U))) 
                                                                | ((0xc0000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_41_exception_type_13) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_41_exception_type_13) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_41_exception_type_13) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_exception_type_13) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_41_exception_type_13) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_exception_type_13) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_41_exception_type_13) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_41_exception_type_13)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0x12U)) 
                                                                   | (0x30000U 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_40_exception_type_13) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_40_exception_type_13) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_40_exception_type_13) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_exception_type_13) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_40_exception_type_13) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_40_exception_type_13) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_40_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_exception_type_13)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 0x10U))))) 
                                                            | ((((0xc000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_39_exception_type_13) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_39_exception_type_13) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_39_exception_type_13) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_exception_type_13) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_39_exception_type_13) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_exception_type_13) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_exception_type_13) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_exception_type_13)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0xeU)) 
                                                                 | (0x3000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_38_exception_type_13) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_38_exception_type_13) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_38_exception_type_13) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_exception_type_13) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_38_exception_type_13) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_38_exception_type_13) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_38_exception_type_13) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_exception_type_13)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0xcU))) 
                                                                | ((0xc00U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_37_exception_type_13) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_37_exception_type_13) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_exception_type_13) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_37_exception_type_13) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_37_exception_type_13) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_exception_type_13) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_37_exception_type_13) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_exception_type_13)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0xaU)) 
                                                                   | (0x300U 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_exception_type_13) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_36_exception_type_13) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_exception_type_13) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_36_exception_type_13) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_36_exception_type_13) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_36_exception_type_13) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_36_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_exception_type_13)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 8U)))) 
                                                               | (((0xc0U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_35_exception_type_13) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_35_exception_type_13) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_35_exception_type_13) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_exception_type_13) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_exception_type_13) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_exception_type_13) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_35_exception_type_13) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_exception_type_13)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 6U)) 
                                                                   | (0x30U 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_34_exception_type_13) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_34_exception_type_13) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_34_exception_type_13) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_34_exception_type_13) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_34_exception_type_13) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_exception_type_13) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_34_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_exception_type_13)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 4U))) 
                                                                  | ((0xcU 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_33_exception_type_13) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_33_exception_type_13) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_33_exception_type_13) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_exception_type_13) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_exception_type_13) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_exception_type_13) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_33_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_exception_type_13)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 2U)) 
                                                                     | (3U 
                                                                        & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_32_exception_type_13) 
                                                                               << 0xeU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_32_exception_type_13) 
                                                                                << 0xcU)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_exception_type_13) 
                                                                                << 0xaU) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_exception_type_13) 
                                                                                << 8U))) 
                                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_exception_type_13) 
                                                                                << 6U) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_32_exception_type_13) 
                                                                                << 4U)) 
                                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_exception_type_13) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_32_exception_type_13)))) 
                                                                           >> 
                                                                           (0xfU 
                                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))))))) 
                             >> 0x20U));
    __Vtemp_2[0U] = (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_15_exception_type_13) 
                              << 0xeU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_15_exception_type_13) 
                                          << 0xcU)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_15_exception_type_13) 
                                << 0xaU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_exception_type_13) 
                                            << 8U))) 
                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_15_exception_type_13) 
                                << 6U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_15_exception_type_13) 
                                          << 4U)) | 
                              (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_15_exception_type_13) 
                                << 2U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_exception_type_13)))) 
                          >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                         << 0x1eU) | (0x30000000U & 
                                      (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_14_exception_type_13) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_14_exception_type_13) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_14_exception_type_13) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_exception_type_13) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_14_exception_type_13) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_14_exception_type_13) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_14_exception_type_13) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_exception_type_13)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0x1cU))) 
                       | ((0xc000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_13_exception_type_13) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_13_exception_type_13) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_13_exception_type_13) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_13_exception_type_13) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_exception_type_13) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_13_exception_type_13) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_13_exception_type_13) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_13_exception_type_13)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x1aU)) 
                          | (0x3000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_12_exception_type_13) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_12_exception_type_13) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_12_exception_type_13) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_12_exception_type_13) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_12_exception_type_13) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_12_exception_type_13) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_12_exception_type_13) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_12_exception_type_13)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x18U)))) 
                      | (((0xc00000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_11_exception_type_13) 
                                             << 0xeU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_11_exception_type_13) 
                                               << 0xcU)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_11_exception_type_13) 
                                               << 0xaU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_11_exception_type_13) 
                                                 << 8U))) 
                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_11_exception_type_13) 
                                               << 6U) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_11_exception_type_13) 
                                                 << 4U)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_11_exception_type_13) 
                                                 << 2U) 
                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_11_exception_type_13)))) 
                                         >> (0xfU & 
                                             VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                        << 0x16U)) 
                          | (0x300000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_10_exception_type_13) 
                                               << 0xeU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_10_exception_type_13) 
                                                 << 0xcU)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_10_exception_type_13) 
                                                 << 0xaU) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_10_exception_type_13) 
                                                   << 8U))) 
                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_10_exception_type_13) 
                                                 << 6U) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_10_exception_type_13) 
                                                   << 4U)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_10_exception_type_13) 
                                                   << 2U) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_exception_type_13)))) 
                                           >> (0xfU 
                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                          << 0x14U))) 
                         | ((0xc0000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_9_exception_type_13) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_9_exception_type_13) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_9_exception_type_13) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_9_exception_type_13) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_9_exception_type_13) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_9_exception_type_13) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_9_exception_type_13) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_exception_type_13)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x12U)) 
                            | (0x30000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_8_exception_type_13) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_8_exception_type_13) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_8_exception_type_13) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_8_exception_type_13) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_8_exception_type_13) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_8_exception_type_13) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_8_exception_type_13) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_8_exception_type_13)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x10U))))) 
                     | ((((0xc000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_7_exception_type_13) 
                                           << 0xeU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_7_exception_type_13) 
                                             << 0xcU)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_7_exception_type_13) 
                                             << 0xaU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_7_exception_type_13) 
                                               << 8U))) 
                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_exception_type_13) 
                                             << 6U) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_7_exception_type_13) 
                                               << 4U)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_7_exception_type_13) 
                                               << 2U) 
                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_7_exception_type_13)))) 
                                       >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                      << 0xeU)) | (0x3000U 
                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_6_exception_type_13) 
                                                           << 0xeU) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_6_exception_type_13) 
                                                             << 0xcU)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_6_exception_type_13) 
                                                             << 0xaU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_6_exception_type_13) 
                                                               << 8U))) 
                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_6_exception_type_13) 
                                                             << 6U) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_6_exception_type_13) 
                                                               << 4U)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_6_exception_type_13) 
                                                               << 2U) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_6_exception_type_13)))) 
                                                       >> 
                                                       (0xfU 
                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                      << 0xcU))) 
                         | ((0xc00U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_5_exception_type_13) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_5_exception_type_13) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_5_exception_type_13) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_5_exception_type_13) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_exception_type_13) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_5_exception_type_13) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_5_exception_type_13) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_5_exception_type_13)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0xaU)) | 
                            (0x300U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_4_exception_type_13) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_4_exception_type_13) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_4_exception_type_13) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_4_exception_type_13) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_exception_type_13) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_4_exception_type_13) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_4_exception_type_13) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_exception_type_13)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 8U)))) | 
                        (((0xc0U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_3_exception_type_13) 
                                         << 0xeU) | 
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_3_exception_type_13) 
                                         << 0xcU)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_3_exception_type_13) 
                                           << 0xaU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_3_exception_type_13) 
                                             << 8U))) 
                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_3_exception_type_13) 
                                           << 6U) | 
                                          ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_3_exception_type_13) 
                                           << 4U)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_3_exception_type_13) 
                                             << 2U) 
                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_exception_type_13)))) 
                                     >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                    << 6U)) | (0x30U 
                                               & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_2_exception_type_13) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_2_exception_type_13) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_2_exception_type_13) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_2_exception_type_13) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_2_exception_type_13) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_2_exception_type_13) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_2_exception_type_13) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_2_exception_type_13)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                  << 4U))) 
                         | ((0xcU & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_1_exception_type_13) 
                                          << 0xeU) 
                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_1_exception_type_13) 
                                            << 0xcU)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_1_exception_type_13) 
                                            << 0xaU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_1_exception_type_13) 
                                              << 8U))) 
                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_1_exception_type_13) 
                                            << 6U) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_1_exception_type_13) 
                                              << 4U)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_1_exception_type_13) 
                                              << 2U) 
                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_exception_type_13)))) 
                                      >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                     << 2U)) | (3U 
                                                & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_0_exception_type_13) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_0_exception_type_13) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_0_exception_type_13) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_0_exception_type_13) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_0_exception_type_13) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_0_exception_type_13) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_0_exception_type_13) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_0_exception_type_13)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))));
    __Vtemp_2[1U] = __Vtemp_1[0U];
    __Vtemp_2[2U] = __Vtemp_1[1U];
    __Vtemp_2[3U] = __Vtemp_1[2U];
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__io_read_resp_data_exception_type_13 
        = (3U & (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                (0x3fU 
                                                 & (IData)(
                                                           (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                            >> 2U))), 1U)))
                   ? 0U : (__Vtemp_2[(((IData)(1U) 
                                       + (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                                (0x3fU 
                                                                 & (IData)(
                                                                           (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                                            >> 2U))), 1U))) 
                                      >> 5U)] << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(7,7,32, 
                                                                   (0x3fU 
                                                                    & (IData)(
                                                                              (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                                               >> 2U))), 1U))))) 
                 | (__Vtemp_2[(3U & (VL_SHIFTL_III(7,7,32, 
                                                   (0x3fU 
                                                    & (IData)(
                                                              (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                               >> 2U))), 1U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (0x3fU 
                                                                   & (IData)(
                                                                             (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                                              >> 2U))), 1U)))));
    __Vtemp_3[0U] = (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_31_exception_type_14) 
                              << 0xeU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_31_exception_type_14) 
                                          << 0xcU)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_31_exception_type_14) 
                                << 0xaU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_exception_type_14) 
                                            << 8U))) 
                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_31_exception_type_14) 
                                << 6U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_31_exception_type_14) 
                                          << 4U)) | 
                              (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_31_exception_type_14) 
                                << 2U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_31_exception_type_14)))) 
                          >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                         << 0x1eU) | (0x30000000U & 
                                      (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_30_exception_type_14) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_30_exception_type_14) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_30_exception_type_14) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_exception_type_14) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_30_exception_type_14) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_exception_type_14) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_30_exception_type_14) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_30_exception_type_14)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0x1cU))) 
                       | ((0xc000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_29_exception_type_14) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_29_exception_type_14) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_29_exception_type_14) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_exception_type_14) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_29_exception_type_14) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_exception_type_14) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_29_exception_type_14) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_29_exception_type_14)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x1aU)) 
                          | (0x3000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_28_exception_type_14) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_28_exception_type_14) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_28_exception_type_14) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_exception_type_14) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_exception_type_14) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_exception_type_14) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_28_exception_type_14) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_28_exception_type_14)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x18U)))) 
                      | (((0xc00000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_27_exception_type_14) 
                                             << 0xeU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_27_exception_type_14) 
                                               << 0xcU)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_27_exception_type_14) 
                                               << 0xaU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_exception_type_14) 
                                                 << 8U))) 
                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_27_exception_type_14) 
                                               << 6U) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_27_exception_type_14) 
                                                 << 4U)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_27_exception_type_14) 
                                                 << 2U) 
                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_27_exception_type_14)))) 
                                         >> (0xfU & 
                                             VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                        << 0x16U)) 
                          | (0x300000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_26_exception_type_14) 
                                               << 0xeU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_26_exception_type_14) 
                                                 << 0xcU)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_26_exception_type_14) 
                                                 << 0xaU) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_exception_type_14) 
                                                   << 8U))) 
                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_exception_type_14) 
                                                 << 6U) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_exception_type_14) 
                                                   << 4U)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_26_exception_type_14) 
                                                   << 2U) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_26_exception_type_14)))) 
                                           >> (0xfU 
                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                          << 0x14U))) 
                         | ((0xc0000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_25_exception_type_14) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_25_exception_type_14) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_25_exception_type_14) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_exception_type_14) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_exception_type_14) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_25_exception_type_14) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_25_exception_type_14) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_25_exception_type_14)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x12U)) 
                            | (0x30000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_24_exception_type_14) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_24_exception_type_14) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_24_exception_type_14) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_exception_type_14) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_exception_type_14) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_exception_type_14) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_24_exception_type_14) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_exception_type_14)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x10U))))) 
                     | ((((0xc000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_23_exception_type_14) 
                                           << 0xeU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_23_exception_type_14) 
                                             << 0xcU)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_23_exception_type_14) 
                                             << 0xaU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_exception_type_14) 
                                               << 8U))) 
                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_23_exception_type_14) 
                                             << 6U) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_23_exception_type_14) 
                                               << 4U)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_23_exception_type_14) 
                                               << 2U) 
                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_exception_type_14)))) 
                                       >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                      << 0xeU)) | (0x3000U 
                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_22_exception_type_14) 
                                                           << 0xeU) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_22_exception_type_14) 
                                                             << 0xcU)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_22_exception_type_14) 
                                                             << 0xaU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_exception_type_14) 
                                                               << 8U))) 
                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_22_exception_type_14) 
                                                             << 6U) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_22_exception_type_14) 
                                                               << 4U)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_22_exception_type_14) 
                                                               << 2U) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_22_exception_type_14)))) 
                                                       >> 
                                                       (0xfU 
                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                      << 0xcU))) 
                         | ((0xc00U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_21_exception_type_14) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_21_exception_type_14) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_21_exception_type_14) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_exception_type_14) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_exception_type_14) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_exception_type_14) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_21_exception_type_14) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_exception_type_14)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0xaU)) | 
                            (0x300U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_20_exception_type_14) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_20_exception_type_14) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_20_exception_type_14) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_exception_type_14) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_20_exception_type_14) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_20_exception_type_14) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_20_exception_type_14) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_20_exception_type_14)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 8U)))) | 
                        (((0xc0U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_19_exception_type_14) 
                                         << 0xeU) | 
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_19_exception_type_14) 
                                         << 0xcU)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_19_exception_type_14) 
                                           << 0xaU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_exception_type_14) 
                                             << 8U))) 
                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_exception_type_14) 
                                           << 6U) | 
                                          ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_19_exception_type_14) 
                                           << 4U)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_19_exception_type_14) 
                                             << 2U) 
                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_19_exception_type_14)))) 
                                     >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                    << 6U)) | (0x30U 
                                               & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_18_exception_type_14) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_18_exception_type_14) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_18_exception_type_14) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_exception_type_14) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_exception_type_14) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_18_exception_type_14) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_18_exception_type_14) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_18_exception_type_14)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                  << 4U))) 
                         | ((0xcU & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_17_exception_type_14) 
                                          << 0xeU) 
                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_17_exception_type_14) 
                                            << 0xcU)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_17_exception_type_14) 
                                            << 0xaU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_exception_type_14) 
                                              << 8U))) 
                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_exception_type_14) 
                                            << 6U) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_17_exception_type_14) 
                                              << 4U)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_17_exception_type_14) 
                                              << 2U) 
                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_exception_type_14)))) 
                                      >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                     << 2U)) | (3U 
                                                & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_16_exception_type_14) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_16_exception_type_14) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_16_exception_type_14) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_exception_type_14) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_exception_type_14) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_16_exception_type_14) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_16_exception_type_14) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_16_exception_type_14)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))));
    __Vtemp_3[1U] = (IData)((((QData)((IData)((((((
                                                   ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_63_exception_type_14) 
                                                        << 0xeU) 
                                                       | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_63_exception_type_14) 
                                                          << 0xcU)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_63_exception_type_14) 
                                                          << 0xaU) 
                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_63_exception_type_14) 
                                                            << 8U))) 
                                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_exception_type_14) 
                                                          << 6U) 
                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_exception_type_14) 
                                                            << 4U)) 
                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_63_exception_type_14) 
                                                            << 2U) 
                                                           | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_exception_type_14)))) 
                                                    >> 
                                                    (0xfU 
                                                     & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                   << 0x1eU) 
                                                  | (0x30000000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_62_exception_type_14) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_62_exception_type_14) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_exception_type_14) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_62_exception_type_14) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_62_exception_type_14) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_62_exception_type_14) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_62_exception_type_14) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_exception_type_14)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0x1cU))) 
                                                 | ((0xc000000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_exception_type_14) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_exception_type_14) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_exception_type_14) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_61_exception_type_14) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_61_exception_type_14) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_exception_type_14) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_61_exception_type_14) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_exception_type_14)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0x1aU)) 
                                                    | (0x3000000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_60_exception_type_14) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_60_exception_type_14) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_60_exception_type_14) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_60_exception_type_14) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_exception_type_14) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_60_exception_type_14) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_60_exception_type_14) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_60_exception_type_14)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0x18U)))) 
                                                | (((0xc00000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_59_exception_type_14) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_59_exception_type_14) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_59_exception_type_14) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_59_exception_type_14) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_59_exception_type_14) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_59_exception_type_14) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_59_exception_type_14) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_59_exception_type_14)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0x16U)) 
                                                    | (0x300000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_58_exception_type_14) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_58_exception_type_14) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_58_exception_type_14) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_58_exception_type_14) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_exception_type_14) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_58_exception_type_14) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_58_exception_type_14) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_exception_type_14)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0x14U))) 
                                                   | ((0xc0000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_exception_type_14) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_57_exception_type_14) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_57_exception_type_14) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_exception_type_14) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_exception_type_14) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_57_exception_type_14) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_57_exception_type_14) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_exception_type_14)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0x12U)) 
                                                      | (0x30000U 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_56_exception_type_14) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_56_exception_type_14) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_56_exception_type_14) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_56_exception_type_14) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_56_exception_type_14) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_exception_type_14) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_56_exception_type_14) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_exception_type_14)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 0x10U))))) 
                                               | ((((0xc000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_55_exception_type_14) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_55_exception_type_14) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_55_exception_type_14) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_55_exception_type_14) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_55_exception_type_14) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_55_exception_type_14) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_55_exception_type_14) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_exception_type_14)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0xeU)) 
                                                    | (0x3000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_54_exception_type_14) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_54_exception_type_14) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_54_exception_type_14) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_exception_type_14) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_54_exception_type_14) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_54_exception_type_14) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_54_exception_type_14) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_exception_type_14)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0xcU))) 
                                                   | ((0xc00U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_53_exception_type_14) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_53_exception_type_14) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_53_exception_type_14) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_exception_type_14) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_53_exception_type_14) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_53_exception_type_14) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_exception_type_14) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_exception_type_14)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0xaU)) 
                                                      | (0x300U 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_52_exception_type_14) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_exception_type_14) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_exception_type_14) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_exception_type_14) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_52_exception_type_14) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_exception_type_14) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_52_exception_type_14) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_52_exception_type_14)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 8U)))) 
                                                  | (((0xc0U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_51_exception_type_14) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_51_exception_type_14) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_51_exception_type_14) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_exception_type_14) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_51_exception_type_14) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_51_exception_type_14) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_exception_type_14) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_exception_type_14)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 6U)) 
                                                      | (0x30U 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_50_exception_type_14) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_50_exception_type_14) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_50_exception_type_14) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_exception_type_14) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_50_exception_type_14) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_50_exception_type_14) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_50_exception_type_14) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_exception_type_14)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 4U))) 
                                                     | ((0xcU 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_49_exception_type_14) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_49_exception_type_14) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_49_exception_type_14) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_exception_type_14) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_49_exception_type_14) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_exception_type_14) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_49_exception_type_14) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_exception_type_14)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 2U)) 
                                                        | (3U 
                                                           & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_48_exception_type_14) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_48_exception_type_14) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_48_exception_type_14) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_exception_type_14) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_48_exception_type_14) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_exception_type_14) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_48_exception_type_14) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_exception_type_14)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U)))))))))) 
                              << 0x20U) | (QData)((IData)(
                                                          (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_47_exception_type_14) 
                                                                    << 0xeU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_exception_type_14) 
                                                                      << 0xcU)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_47_exception_type_14) 
                                                                      << 0xaU) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_exception_type_14) 
                                                                        << 8U))) 
                                                                 | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_47_exception_type_14) 
                                                                      << 6U) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_exception_type_14) 
                                                                        << 4U)) 
                                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_47_exception_type_14) 
                                                                        << 2U) 
                                                                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_exception_type_14)))) 
                                                                >> 
                                                                (0xfU 
                                                                 & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                               << 0x1eU) 
                                                              | (0x30000000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_46_exception_type_14) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_46_exception_type_14) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_46_exception_type_14) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_exception_type_14) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_46_exception_type_14) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_46_exception_type_14) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_exception_type_14) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_46_exception_type_14)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0x1cU))) 
                                                             | ((0xc000000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_45_exception_type_14) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_exception_type_14) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_45_exception_type_14) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_exception_type_14) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_exception_type_14) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_exception_type_14) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_45_exception_type_14) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_exception_type_14)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0x1aU)) 
                                                                | (0x3000000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_44_exception_type_14) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_44_exception_type_14) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_44_exception_type_14) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_44_exception_type_14) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_44_exception_type_14) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_exception_type_14) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_44_exception_type_14) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_44_exception_type_14)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0x18U)))) 
                                                            | (((0xc00000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_43_exception_type_14) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_exception_type_14) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_43_exception_type_14) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_exception_type_14) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_43_exception_type_14) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_exception_type_14) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_exception_type_14) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_exception_type_14)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0x16U)) 
                                                                | (0x300000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_42_exception_type_14) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_exception_type_14) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_42_exception_type_14) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_exception_type_14) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_42_exception_type_14) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_42_exception_type_14) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_42_exception_type_14) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_42_exception_type_14)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0x14U))) 
                                                               | ((0xc0000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_41_exception_type_14) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_41_exception_type_14) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_41_exception_type_14) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_exception_type_14) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_41_exception_type_14) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_exception_type_14) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_41_exception_type_14) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_41_exception_type_14)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0x12U)) 
                                                                  | (0x30000U 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_40_exception_type_14) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_40_exception_type_14) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_40_exception_type_14) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_exception_type_14) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_40_exception_type_14) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_40_exception_type_14) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_40_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_exception_type_14)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 0x10U))))) 
                                                           | ((((0xc000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_39_exception_type_14) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_39_exception_type_14) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_39_exception_type_14) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_exception_type_14) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_39_exception_type_14) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_exception_type_14) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_exception_type_14) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_exception_type_14)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0xeU)) 
                                                                | (0x3000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_38_exception_type_14) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_38_exception_type_14) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_38_exception_type_14) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_exception_type_14) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_38_exception_type_14) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_38_exception_type_14) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_38_exception_type_14) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_exception_type_14)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0xcU))) 
                                                               | ((0xc00U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_37_exception_type_14) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_37_exception_type_14) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_exception_type_14) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_37_exception_type_14) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_37_exception_type_14) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_exception_type_14) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_37_exception_type_14) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_exception_type_14)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0xaU)) 
                                                                  | (0x300U 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_exception_type_14) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_36_exception_type_14) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_exception_type_14) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_36_exception_type_14) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_36_exception_type_14) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_36_exception_type_14) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_36_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_exception_type_14)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 8U)))) 
                                                              | (((0xc0U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_35_exception_type_14) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_35_exception_type_14) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_35_exception_type_14) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_exception_type_14) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_exception_type_14) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_exception_type_14) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_35_exception_type_14) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_exception_type_14)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 6U)) 
                                                                  | (0x30U 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_34_exception_type_14) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_34_exception_type_14) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_34_exception_type_14) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_34_exception_type_14) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_34_exception_type_14) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_exception_type_14) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_34_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_exception_type_14)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 4U))) 
                                                                 | ((0xcU 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_33_exception_type_14) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_33_exception_type_14) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_33_exception_type_14) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_exception_type_14) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_exception_type_14) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_exception_type_14) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_33_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_exception_type_14)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 2U)) 
                                                                    | (3U 
                                                                       & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_32_exception_type_14) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_32_exception_type_14) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_exception_type_14) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_exception_type_14) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_exception_type_14) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_32_exception_type_14) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_32_exception_type_14)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))))))));
    __Vtemp_3[2U] = (IData)(((((QData)((IData)(((((
                                                   (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_63_exception_type_14) 
                                                         << 0xeU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_63_exception_type_14) 
                                                           << 0xcU)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_63_exception_type_14) 
                                                           << 0xaU) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_63_exception_type_14) 
                                                             << 8U))) 
                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_exception_type_14) 
                                                           << 6U) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_exception_type_14) 
                                                             << 4U)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_63_exception_type_14) 
                                                             << 2U) 
                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_exception_type_14)))) 
                                                     >> 
                                                     (0xfU 
                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                    << 0x1eU) 
                                                   | (0x30000000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_62_exception_type_14) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_62_exception_type_14) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_exception_type_14) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_62_exception_type_14) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_62_exception_type_14) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_62_exception_type_14) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_62_exception_type_14) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_exception_type_14)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0x1cU))) 
                                                  | ((0xc000000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_exception_type_14) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_exception_type_14) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_exception_type_14) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_61_exception_type_14) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_61_exception_type_14) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_exception_type_14) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_61_exception_type_14) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_exception_type_14)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0x1aU)) 
                                                     | (0x3000000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_60_exception_type_14) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_60_exception_type_14) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_60_exception_type_14) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_60_exception_type_14) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_exception_type_14) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_60_exception_type_14) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_60_exception_type_14) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_60_exception_type_14)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0x18U)))) 
                                                 | (((0xc00000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_59_exception_type_14) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_59_exception_type_14) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_59_exception_type_14) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_59_exception_type_14) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_59_exception_type_14) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_59_exception_type_14) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_59_exception_type_14) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_59_exception_type_14)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0x16U)) 
                                                     | (0x300000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_58_exception_type_14) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_58_exception_type_14) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_58_exception_type_14) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_58_exception_type_14) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_exception_type_14) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_58_exception_type_14) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_58_exception_type_14) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_exception_type_14)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0x14U))) 
                                                    | ((0xc0000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_exception_type_14) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_57_exception_type_14) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_57_exception_type_14) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_exception_type_14) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_exception_type_14) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_57_exception_type_14) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_57_exception_type_14) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_exception_type_14)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0x12U)) 
                                                       | (0x30000U 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_56_exception_type_14) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_56_exception_type_14) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_56_exception_type_14) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_56_exception_type_14) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_56_exception_type_14) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_exception_type_14) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_56_exception_type_14) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_exception_type_14)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 0x10U))))) 
                                                | ((((0xc000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_55_exception_type_14) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_55_exception_type_14) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_55_exception_type_14) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_55_exception_type_14) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_55_exception_type_14) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_55_exception_type_14) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_55_exception_type_14) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_exception_type_14)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0xeU)) 
                                                     | (0x3000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_54_exception_type_14) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_54_exception_type_14) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_54_exception_type_14) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_exception_type_14) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_54_exception_type_14) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_54_exception_type_14) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_54_exception_type_14) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_exception_type_14)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0xcU))) 
                                                    | ((0xc00U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_53_exception_type_14) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_53_exception_type_14) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_53_exception_type_14) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_exception_type_14) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_53_exception_type_14) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_53_exception_type_14) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_exception_type_14) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_exception_type_14)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0xaU)) 
                                                       | (0x300U 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_52_exception_type_14) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_exception_type_14) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_exception_type_14) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_exception_type_14) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_52_exception_type_14) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_exception_type_14) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_52_exception_type_14) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_52_exception_type_14)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 8U)))) 
                                                   | (((0xc0U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_51_exception_type_14) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_51_exception_type_14) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_51_exception_type_14) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_exception_type_14) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_51_exception_type_14) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_51_exception_type_14) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_exception_type_14) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_exception_type_14)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 6U)) 
                                                       | (0x30U 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_50_exception_type_14) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_50_exception_type_14) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_50_exception_type_14) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_exception_type_14) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_50_exception_type_14) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_50_exception_type_14) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_50_exception_type_14) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_exception_type_14)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 4U))) 
                                                      | ((0xcU 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_49_exception_type_14) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_49_exception_type_14) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_49_exception_type_14) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_exception_type_14) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_49_exception_type_14) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_exception_type_14) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_49_exception_type_14) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_exception_type_14)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 2U)) 
                                                         | (3U 
                                                            & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_48_exception_type_14) 
                                                                   << 0xeU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_48_exception_type_14) 
                                                                     << 0xcU)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_48_exception_type_14) 
                                                                     << 0xaU) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_exception_type_14) 
                                                                       << 8U))) 
                                                                | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_48_exception_type_14) 
                                                                     << 6U) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_exception_type_14) 
                                                                       << 4U)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_48_exception_type_14) 
                                                                       << 2U) 
                                                                      | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_exception_type_14)))) 
                                                               >> 
                                                               (0xfU 
                                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U)))))))))) 
                               << 0x20U) | (QData)((IData)(
                                                           (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_47_exception_type_14) 
                                                                     << 0xeU) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_exception_type_14) 
                                                                       << 0xcU)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_47_exception_type_14) 
                                                                       << 0xaU) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_exception_type_14) 
                                                                         << 8U))) 
                                                                  | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_47_exception_type_14) 
                                                                       << 6U) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_exception_type_14) 
                                                                         << 4U)) 
                                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_47_exception_type_14) 
                                                                         << 2U) 
                                                                        | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_exception_type_14)))) 
                                                                 >> 
                                                                 (0xfU 
                                                                  & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                << 0x1eU) 
                                                               | (0x30000000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_46_exception_type_14) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_46_exception_type_14) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_46_exception_type_14) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_exception_type_14) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_46_exception_type_14) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_46_exception_type_14) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_exception_type_14) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_46_exception_type_14)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0x1cU))) 
                                                              | ((0xc000000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_45_exception_type_14) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_exception_type_14) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_45_exception_type_14) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_exception_type_14) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_exception_type_14) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_exception_type_14) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_45_exception_type_14) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_exception_type_14)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0x1aU)) 
                                                                 | (0x3000000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_44_exception_type_14) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_44_exception_type_14) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_44_exception_type_14) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_44_exception_type_14) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_44_exception_type_14) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_exception_type_14) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_44_exception_type_14) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_44_exception_type_14)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0x18U)))) 
                                                             | (((0xc00000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_43_exception_type_14) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_exception_type_14) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_43_exception_type_14) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_exception_type_14) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_43_exception_type_14) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_exception_type_14) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_exception_type_14) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_exception_type_14)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0x16U)) 
                                                                 | (0x300000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_42_exception_type_14) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_exception_type_14) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_42_exception_type_14) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_exception_type_14) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_42_exception_type_14) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_42_exception_type_14) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_42_exception_type_14) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_42_exception_type_14)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0x14U))) 
                                                                | ((0xc0000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_41_exception_type_14) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_41_exception_type_14) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_41_exception_type_14) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_exception_type_14) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_41_exception_type_14) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_exception_type_14) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_41_exception_type_14) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_41_exception_type_14)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0x12U)) 
                                                                   | (0x30000U 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_40_exception_type_14) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_40_exception_type_14) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_40_exception_type_14) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_exception_type_14) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_40_exception_type_14) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_40_exception_type_14) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_40_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_exception_type_14)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 0x10U))))) 
                                                            | ((((0xc000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_39_exception_type_14) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_39_exception_type_14) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_39_exception_type_14) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_exception_type_14) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_39_exception_type_14) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_exception_type_14) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_exception_type_14) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_exception_type_14)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0xeU)) 
                                                                 | (0x3000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_38_exception_type_14) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_38_exception_type_14) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_38_exception_type_14) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_exception_type_14) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_38_exception_type_14) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_38_exception_type_14) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_38_exception_type_14) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_exception_type_14)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0xcU))) 
                                                                | ((0xc00U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_37_exception_type_14) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_37_exception_type_14) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_exception_type_14) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_37_exception_type_14) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_37_exception_type_14) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_exception_type_14) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_37_exception_type_14) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_exception_type_14)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0xaU)) 
                                                                   | (0x300U 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_exception_type_14) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_36_exception_type_14) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_exception_type_14) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_36_exception_type_14) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_36_exception_type_14) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_36_exception_type_14) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_36_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_exception_type_14)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 8U)))) 
                                                               | (((0xc0U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_35_exception_type_14) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_35_exception_type_14) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_35_exception_type_14) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_exception_type_14) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_exception_type_14) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_exception_type_14) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_35_exception_type_14) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_exception_type_14)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 6U)) 
                                                                   | (0x30U 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_34_exception_type_14) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_34_exception_type_14) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_34_exception_type_14) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_34_exception_type_14) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_34_exception_type_14) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_exception_type_14) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_34_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_exception_type_14)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 4U))) 
                                                                  | ((0xcU 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_33_exception_type_14) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_33_exception_type_14) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_33_exception_type_14) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_exception_type_14) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_exception_type_14) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_exception_type_14) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_33_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_exception_type_14)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 2U)) 
                                                                     | (3U 
                                                                        & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_32_exception_type_14) 
                                                                               << 0xeU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_32_exception_type_14) 
                                                                                << 0xcU)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_exception_type_14) 
                                                                                << 0xaU) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_exception_type_14) 
                                                                                << 8U))) 
                                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_exception_type_14) 
                                                                                << 6U) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_32_exception_type_14) 
                                                                                << 4U)) 
                                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_exception_type_14) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_32_exception_type_14)))) 
                                                                           >> 
                                                                           (0xfU 
                                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))))))) 
                             >> 0x20U));
    __Vtemp_4[0U] = (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_15_exception_type_14) 
                              << 0xeU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_15_exception_type_14) 
                                          << 0xcU)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_15_exception_type_14) 
                                << 0xaU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_exception_type_14) 
                                            << 8U))) 
                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_15_exception_type_14) 
                                << 6U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_15_exception_type_14) 
                                          << 4U)) | 
                              (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_15_exception_type_14) 
                                << 2U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_exception_type_14)))) 
                          >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                         << 0x1eU) | (0x30000000U & 
                                      (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_14_exception_type_14) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_14_exception_type_14) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_14_exception_type_14) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_exception_type_14) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_14_exception_type_14) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_14_exception_type_14) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_14_exception_type_14) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_exception_type_14)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0x1cU))) 
                       | ((0xc000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_13_exception_type_14) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_13_exception_type_14) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_13_exception_type_14) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_13_exception_type_14) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_exception_type_14) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_13_exception_type_14) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_13_exception_type_14) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_13_exception_type_14)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x1aU)) 
                          | (0x3000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_12_exception_type_14) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_12_exception_type_14) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_12_exception_type_14) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_12_exception_type_14) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_12_exception_type_14) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_12_exception_type_14) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_12_exception_type_14) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_12_exception_type_14)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x18U)))) 
                      | (((0xc00000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_11_exception_type_14) 
                                             << 0xeU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_11_exception_type_14) 
                                               << 0xcU)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_11_exception_type_14) 
                                               << 0xaU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_11_exception_type_14) 
                                                 << 8U))) 
                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_11_exception_type_14) 
                                               << 6U) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_11_exception_type_14) 
                                                 << 4U)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_11_exception_type_14) 
                                                 << 2U) 
                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_11_exception_type_14)))) 
                                         >> (0xfU & 
                                             VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                        << 0x16U)) 
                          | (0x300000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_10_exception_type_14) 
                                               << 0xeU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_10_exception_type_14) 
                                                 << 0xcU)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_10_exception_type_14) 
                                                 << 0xaU) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_10_exception_type_14) 
                                                   << 8U))) 
                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_10_exception_type_14) 
                                                 << 6U) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_10_exception_type_14) 
                                                   << 4U)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_10_exception_type_14) 
                                                   << 2U) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_exception_type_14)))) 
                                           >> (0xfU 
                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                          << 0x14U))) 
                         | ((0xc0000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_9_exception_type_14) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_9_exception_type_14) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_9_exception_type_14) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_9_exception_type_14) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_9_exception_type_14) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_9_exception_type_14) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_9_exception_type_14) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_exception_type_14)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x12U)) 
                            | (0x30000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_8_exception_type_14) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_8_exception_type_14) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_8_exception_type_14) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_8_exception_type_14) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_8_exception_type_14) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_8_exception_type_14) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_8_exception_type_14) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_8_exception_type_14)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x10U))))) 
                     | ((((0xc000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_7_exception_type_14) 
                                           << 0xeU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_7_exception_type_14) 
                                             << 0xcU)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_7_exception_type_14) 
                                             << 0xaU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_7_exception_type_14) 
                                               << 8U))) 
                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_exception_type_14) 
                                             << 6U) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_7_exception_type_14) 
                                               << 4U)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_7_exception_type_14) 
                                               << 2U) 
                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_7_exception_type_14)))) 
                                       >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                      << 0xeU)) | (0x3000U 
                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_6_exception_type_14) 
                                                           << 0xeU) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_6_exception_type_14) 
                                                             << 0xcU)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_6_exception_type_14) 
                                                             << 0xaU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_6_exception_type_14) 
                                                               << 8U))) 
                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_6_exception_type_14) 
                                                             << 6U) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_6_exception_type_14) 
                                                               << 4U)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_6_exception_type_14) 
                                                               << 2U) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_6_exception_type_14)))) 
                                                       >> 
                                                       (0xfU 
                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                      << 0xcU))) 
                         | ((0xc00U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_5_exception_type_14) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_5_exception_type_14) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_5_exception_type_14) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_5_exception_type_14) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_exception_type_14) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_5_exception_type_14) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_5_exception_type_14) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_5_exception_type_14)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0xaU)) | 
                            (0x300U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_4_exception_type_14) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_4_exception_type_14) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_4_exception_type_14) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_4_exception_type_14) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_exception_type_14) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_4_exception_type_14) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_4_exception_type_14) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_exception_type_14)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 8U)))) | 
                        (((0xc0U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_3_exception_type_14) 
                                         << 0xeU) | 
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_3_exception_type_14) 
                                         << 0xcU)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_3_exception_type_14) 
                                           << 0xaU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_3_exception_type_14) 
                                             << 8U))) 
                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_3_exception_type_14) 
                                           << 6U) | 
                                          ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_3_exception_type_14) 
                                           << 4U)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_3_exception_type_14) 
                                             << 2U) 
                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_exception_type_14)))) 
                                     >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                    << 6U)) | (0x30U 
                                               & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_2_exception_type_14) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_2_exception_type_14) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_2_exception_type_14) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_2_exception_type_14) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_2_exception_type_14) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_2_exception_type_14) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_2_exception_type_14) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_2_exception_type_14)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                  << 4U))) 
                         | ((0xcU & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_1_exception_type_14) 
                                          << 0xeU) 
                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_1_exception_type_14) 
                                            << 0xcU)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_1_exception_type_14) 
                                            << 0xaU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_1_exception_type_14) 
                                              << 8U))) 
                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_1_exception_type_14) 
                                            << 6U) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_1_exception_type_14) 
                                              << 4U)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_1_exception_type_14) 
                                              << 2U) 
                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_exception_type_14)))) 
                                      >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                     << 2U)) | (3U 
                                                & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_0_exception_type_14) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_0_exception_type_14) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_0_exception_type_14) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_0_exception_type_14) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_0_exception_type_14) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_0_exception_type_14) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_0_exception_type_14) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_0_exception_type_14)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))));
    __Vtemp_4[1U] = __Vtemp_3[0U];
    __Vtemp_4[2U] = __Vtemp_3[1U];
    __Vtemp_4[3U] = __Vtemp_3[2U];
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__io_read_resp_data_exception_type_14 
        = (3U & (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                (0x3fU 
                                                 & (IData)(
                                                           (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                            >> 2U))), 1U)))
                   ? 0U : (__Vtemp_4[(((IData)(1U) 
                                       + (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                                (0x3fU 
                                                                 & (IData)(
                                                                           (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                                            >> 2U))), 1U))) 
                                      >> 5U)] << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(7,7,32, 
                                                                   (0x3fU 
                                                                    & (IData)(
                                                                              (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                                               >> 2U))), 1U))))) 
                 | (__Vtemp_4[(3U & (VL_SHIFTL_III(7,7,32, 
                                                   (0x3fU 
                                                    & (IData)(
                                                              (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                               >> 2U))), 1U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (0x3fU 
                                                                   & (IData)(
                                                                             (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                                              >> 2U))), 1U)))));
    __Vtemp_5[0U] = (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_31_exception_type_15) 
                              << 0xeU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_31_exception_type_15) 
                                          << 0xcU)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_31_exception_type_15) 
                                << 0xaU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_exception_type_15) 
                                            << 8U))) 
                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_31_exception_type_15) 
                                << 6U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_31_exception_type_15) 
                                          << 4U)) | 
                              (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_31_exception_type_15) 
                                << 2U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_31_exception_type_15)))) 
                          >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                         << 0x1eU) | (0x30000000U & 
                                      (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_30_exception_type_15) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_30_exception_type_15) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_30_exception_type_15) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_exception_type_15) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_30_exception_type_15) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_exception_type_15) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_30_exception_type_15) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_30_exception_type_15)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0x1cU))) 
                       | ((0xc000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_29_exception_type_15) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_29_exception_type_15) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_29_exception_type_15) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_exception_type_15) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_29_exception_type_15) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_exception_type_15) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_29_exception_type_15) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_29_exception_type_15)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x1aU)) 
                          | (0x3000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_28_exception_type_15) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_28_exception_type_15) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_28_exception_type_15) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_exception_type_15) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_exception_type_15) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_exception_type_15) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_28_exception_type_15) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_28_exception_type_15)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x18U)))) 
                      | (((0xc00000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_27_exception_type_15) 
                                             << 0xeU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_27_exception_type_15) 
                                               << 0xcU)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_27_exception_type_15) 
                                               << 0xaU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_exception_type_15) 
                                                 << 8U))) 
                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_27_exception_type_15) 
                                               << 6U) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_27_exception_type_15) 
                                                 << 4U)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_27_exception_type_15) 
                                                 << 2U) 
                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_27_exception_type_15)))) 
                                         >> (0xfU & 
                                             VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                        << 0x16U)) 
                          | (0x300000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_26_exception_type_15) 
                                               << 0xeU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_26_exception_type_15) 
                                                 << 0xcU)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_26_exception_type_15) 
                                                 << 0xaU) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_exception_type_15) 
                                                   << 8U))) 
                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_exception_type_15) 
                                                 << 6U) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_exception_type_15) 
                                                   << 4U)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_26_exception_type_15) 
                                                   << 2U) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_26_exception_type_15)))) 
                                           >> (0xfU 
                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                          << 0x14U))) 
                         | ((0xc0000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_25_exception_type_15) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_25_exception_type_15) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_25_exception_type_15) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_exception_type_15) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_exception_type_15) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_25_exception_type_15) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_25_exception_type_15) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_25_exception_type_15)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x12U)) 
                            | (0x30000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_24_exception_type_15) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_24_exception_type_15) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_24_exception_type_15) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_exception_type_15) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_exception_type_15) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_exception_type_15) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_24_exception_type_15) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_exception_type_15)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x10U))))) 
                     | ((((0xc000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_23_exception_type_15) 
                                           << 0xeU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_23_exception_type_15) 
                                             << 0xcU)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_23_exception_type_15) 
                                             << 0xaU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_exception_type_15) 
                                               << 8U))) 
                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_23_exception_type_15) 
                                             << 6U) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_23_exception_type_15) 
                                               << 4U)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_23_exception_type_15) 
                                               << 2U) 
                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_exception_type_15)))) 
                                       >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                      << 0xeU)) | (0x3000U 
                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_22_exception_type_15) 
                                                           << 0xeU) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_22_exception_type_15) 
                                                             << 0xcU)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_22_exception_type_15) 
                                                             << 0xaU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_exception_type_15) 
                                                               << 8U))) 
                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_22_exception_type_15) 
                                                             << 6U) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_22_exception_type_15) 
                                                               << 4U)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_22_exception_type_15) 
                                                               << 2U) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_22_exception_type_15)))) 
                                                       >> 
                                                       (0xfU 
                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                      << 0xcU))) 
                         | ((0xc00U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_21_exception_type_15) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_21_exception_type_15) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_21_exception_type_15) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_exception_type_15) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_exception_type_15) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_exception_type_15) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_21_exception_type_15) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_exception_type_15)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0xaU)) | 
                            (0x300U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_20_exception_type_15) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_20_exception_type_15) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_20_exception_type_15) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_exception_type_15) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_20_exception_type_15) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_20_exception_type_15) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_20_exception_type_15) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_20_exception_type_15)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 8U)))) | 
                        (((0xc0U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_19_exception_type_15) 
                                         << 0xeU) | 
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_19_exception_type_15) 
                                         << 0xcU)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_19_exception_type_15) 
                                           << 0xaU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_exception_type_15) 
                                             << 8U))) 
                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_exception_type_15) 
                                           << 6U) | 
                                          ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_19_exception_type_15) 
                                           << 4U)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_19_exception_type_15) 
                                             << 2U) 
                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_19_exception_type_15)))) 
                                     >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                    << 6U)) | (0x30U 
                                               & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_18_exception_type_15) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_18_exception_type_15) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_18_exception_type_15) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_exception_type_15) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_exception_type_15) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_18_exception_type_15) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_18_exception_type_15) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_18_exception_type_15)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                  << 4U))) 
                         | ((0xcU & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_17_exception_type_15) 
                                          << 0xeU) 
                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_17_exception_type_15) 
                                            << 0xcU)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_17_exception_type_15) 
                                            << 0xaU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_exception_type_15) 
                                              << 8U))) 
                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_exception_type_15) 
                                            << 6U) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_17_exception_type_15) 
                                              << 4U)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_17_exception_type_15) 
                                              << 2U) 
                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_exception_type_15)))) 
                                      >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                     << 2U)) | (3U 
                                                & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_16_exception_type_15) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_16_exception_type_15) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_16_exception_type_15) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_exception_type_15) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_exception_type_15) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_16_exception_type_15) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_16_exception_type_15) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_16_exception_type_15)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))));
    __Vtemp_5[1U] = (IData)((((QData)((IData)((((((
                                                   ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_63_exception_type_15) 
                                                        << 0xeU) 
                                                       | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_63_exception_type_15) 
                                                          << 0xcU)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_63_exception_type_15) 
                                                          << 0xaU) 
                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_63_exception_type_15) 
                                                            << 8U))) 
                                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_exception_type_15) 
                                                          << 6U) 
                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_exception_type_15) 
                                                            << 4U)) 
                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_63_exception_type_15) 
                                                            << 2U) 
                                                           | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_exception_type_15)))) 
                                                    >> 
                                                    (0xfU 
                                                     & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                   << 0x1eU) 
                                                  | (0x30000000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_62_exception_type_15) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_62_exception_type_15) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_exception_type_15) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_62_exception_type_15) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_62_exception_type_15) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_62_exception_type_15) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_62_exception_type_15) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_exception_type_15)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0x1cU))) 
                                                 | ((0xc000000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_exception_type_15) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_exception_type_15) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_exception_type_15) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_61_exception_type_15) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_61_exception_type_15) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_exception_type_15) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_61_exception_type_15) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_exception_type_15)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0x1aU)) 
                                                    | (0x3000000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_60_exception_type_15) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_60_exception_type_15) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_60_exception_type_15) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_60_exception_type_15) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_exception_type_15) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_60_exception_type_15) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_60_exception_type_15) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_60_exception_type_15)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0x18U)))) 
                                                | (((0xc00000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_59_exception_type_15) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_59_exception_type_15) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_59_exception_type_15) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_59_exception_type_15) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_59_exception_type_15) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_59_exception_type_15) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_59_exception_type_15) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_59_exception_type_15)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0x16U)) 
                                                    | (0x300000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_58_exception_type_15) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_58_exception_type_15) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_58_exception_type_15) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_58_exception_type_15) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_exception_type_15) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_58_exception_type_15) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_58_exception_type_15) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_exception_type_15)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0x14U))) 
                                                   | ((0xc0000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_exception_type_15) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_57_exception_type_15) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_57_exception_type_15) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_exception_type_15) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_exception_type_15) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_57_exception_type_15) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_57_exception_type_15) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_exception_type_15)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0x12U)) 
                                                      | (0x30000U 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_56_exception_type_15) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_56_exception_type_15) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_56_exception_type_15) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_56_exception_type_15) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_56_exception_type_15) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_exception_type_15) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_56_exception_type_15) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_exception_type_15)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 0x10U))))) 
                                               | ((((0xc000U 
                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_55_exception_type_15) 
                                                             << 0xeU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_55_exception_type_15) 
                                                               << 0xcU)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_55_exception_type_15) 
                                                               << 0xaU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_55_exception_type_15) 
                                                                 << 8U))) 
                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_55_exception_type_15) 
                                                               << 6U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_55_exception_type_15) 
                                                                 << 4U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_55_exception_type_15) 
                                                                 << 2U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_exception_type_15)))) 
                                                         >> 
                                                         (0xfU 
                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                        << 0xeU)) 
                                                    | (0x3000U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_54_exception_type_15) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_54_exception_type_15) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_54_exception_type_15) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_exception_type_15) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_54_exception_type_15) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_54_exception_type_15) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_54_exception_type_15) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_exception_type_15)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0xcU))) 
                                                   | ((0xc00U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_53_exception_type_15) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_53_exception_type_15) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_53_exception_type_15) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_exception_type_15) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_53_exception_type_15) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_53_exception_type_15) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_exception_type_15) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_exception_type_15)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 0xaU)) 
                                                      | (0x300U 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_52_exception_type_15) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_exception_type_15) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_exception_type_15) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_exception_type_15) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_52_exception_type_15) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_exception_type_15) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_52_exception_type_15) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_52_exception_type_15)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 8U)))) 
                                                  | (((0xc0U 
                                                       & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_51_exception_type_15) 
                                                               << 0xeU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_51_exception_type_15) 
                                                                 << 0xcU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_51_exception_type_15) 
                                                                 << 0xaU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_exception_type_15) 
                                                                   << 8U))) 
                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_51_exception_type_15) 
                                                                 << 6U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_51_exception_type_15) 
                                                                   << 4U)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_exception_type_15) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_exception_type_15)))) 
                                                           >> 
                                                           (0xfU 
                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                          << 6U)) 
                                                      | (0x30U 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_50_exception_type_15) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_50_exception_type_15) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_50_exception_type_15) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_exception_type_15) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_50_exception_type_15) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_50_exception_type_15) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_50_exception_type_15) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_exception_type_15)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 4U))) 
                                                     | ((0xcU 
                                                         & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_49_exception_type_15) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_49_exception_type_15) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_49_exception_type_15) 
                                                                   << 0xaU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_exception_type_15) 
                                                                     << 8U))) 
                                                              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_49_exception_type_15) 
                                                                   << 6U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_exception_type_15) 
                                                                     << 4U)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_49_exception_type_15) 
                                                                     << 2U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_exception_type_15)))) 
                                                             >> 
                                                             (0xfU 
                                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                            << 2U)) 
                                                        | (3U 
                                                           & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_48_exception_type_15) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_48_exception_type_15) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_48_exception_type_15) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_exception_type_15) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_48_exception_type_15) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_exception_type_15) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_48_exception_type_15) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_exception_type_15)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U)))))))))) 
                              << 0x20U) | (QData)((IData)(
                                                          (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_47_exception_type_15) 
                                                                    << 0xeU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_exception_type_15) 
                                                                      << 0xcU)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_47_exception_type_15) 
                                                                      << 0xaU) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_exception_type_15) 
                                                                        << 8U))) 
                                                                 | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_47_exception_type_15) 
                                                                      << 6U) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_exception_type_15) 
                                                                        << 4U)) 
                                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_47_exception_type_15) 
                                                                        << 2U) 
                                                                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_exception_type_15)))) 
                                                                >> 
                                                                (0xfU 
                                                                 & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                               << 0x1eU) 
                                                              | (0x30000000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_46_exception_type_15) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_46_exception_type_15) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_46_exception_type_15) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_exception_type_15) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_46_exception_type_15) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_46_exception_type_15) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_exception_type_15) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_46_exception_type_15)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0x1cU))) 
                                                             | ((0xc000000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_45_exception_type_15) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_exception_type_15) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_45_exception_type_15) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_exception_type_15) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_exception_type_15) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_exception_type_15) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_45_exception_type_15) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_exception_type_15)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0x1aU)) 
                                                                | (0x3000000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_44_exception_type_15) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_44_exception_type_15) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_44_exception_type_15) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_44_exception_type_15) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_44_exception_type_15) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_exception_type_15) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_44_exception_type_15) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_44_exception_type_15)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0x18U)))) 
                                                            | (((0xc00000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_43_exception_type_15) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_exception_type_15) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_43_exception_type_15) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_exception_type_15) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_43_exception_type_15) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_exception_type_15) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_exception_type_15) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_exception_type_15)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0x16U)) 
                                                                | (0x300000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_42_exception_type_15) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_exception_type_15) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_42_exception_type_15) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_exception_type_15) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_42_exception_type_15) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_42_exception_type_15) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_42_exception_type_15) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_42_exception_type_15)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0x14U))) 
                                                               | ((0xc0000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_41_exception_type_15) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_41_exception_type_15) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_41_exception_type_15) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_exception_type_15) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_41_exception_type_15) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_exception_type_15) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_41_exception_type_15) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_41_exception_type_15)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0x12U)) 
                                                                  | (0x30000U 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_40_exception_type_15) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_40_exception_type_15) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_40_exception_type_15) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_exception_type_15) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_40_exception_type_15) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_40_exception_type_15) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_40_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_exception_type_15)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 0x10U))))) 
                                                           | ((((0xc000U 
                                                                 & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_39_exception_type_15) 
                                                                         << 0xeU) 
                                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_39_exception_type_15) 
                                                                           << 0xcU)) 
                                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_39_exception_type_15) 
                                                                           << 0xaU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_exception_type_15) 
                                                                             << 8U))) 
                                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_39_exception_type_15) 
                                                                           << 6U) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_exception_type_15) 
                                                                             << 4U)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_exception_type_15) 
                                                                             << 2U) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_exception_type_15)))) 
                                                                     >> 
                                                                     (0xfU 
                                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                    << 0xeU)) 
                                                                | (0x3000U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_38_exception_type_15) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_38_exception_type_15) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_38_exception_type_15) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_exception_type_15) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_38_exception_type_15) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_38_exception_type_15) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_38_exception_type_15) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_exception_type_15)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0xcU))) 
                                                               | ((0xc00U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_37_exception_type_15) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_37_exception_type_15) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_exception_type_15) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_37_exception_type_15) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_37_exception_type_15) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_exception_type_15) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_37_exception_type_15) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_exception_type_15)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 0xaU)) 
                                                                  | (0x300U 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_exception_type_15) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_36_exception_type_15) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_exception_type_15) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_36_exception_type_15) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_36_exception_type_15) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_36_exception_type_15) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_36_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_exception_type_15)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 8U)))) 
                                                              | (((0xc0U 
                                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_35_exception_type_15) 
                                                                           << 0xeU) 
                                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_35_exception_type_15) 
                                                                             << 0xcU)) 
                                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_35_exception_type_15) 
                                                                             << 0xaU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_exception_type_15) 
                                                                               << 8U))) 
                                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_exception_type_15) 
                                                                             << 6U) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_exception_type_15) 
                                                                               << 4U)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_35_exception_type_15) 
                                                                               << 2U) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_exception_type_15)))) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                      << 6U)) 
                                                                  | (0x30U 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_34_exception_type_15) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_34_exception_type_15) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_34_exception_type_15) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_34_exception_type_15) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_34_exception_type_15) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_exception_type_15) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_34_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_exception_type_15)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 4U))) 
                                                                 | ((0xcU 
                                                                     & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_33_exception_type_15) 
                                                                             << 0xeU) 
                                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_33_exception_type_15) 
                                                                               << 0xcU)) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_33_exception_type_15) 
                                                                               << 0xaU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_exception_type_15) 
                                                                                << 8U))) 
                                                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_exception_type_15) 
                                                                               << 6U) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_exception_type_15) 
                                                                                << 4U)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_33_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_exception_type_15)))) 
                                                                         >> 
                                                                         (0xfU 
                                                                          & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                        << 2U)) 
                                                                    | (3U 
                                                                       & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_32_exception_type_15) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_32_exception_type_15) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_exception_type_15) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_exception_type_15) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_exception_type_15) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_32_exception_type_15) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_32_exception_type_15)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))))))));
    __Vtemp_5[2U] = (IData)(((((QData)((IData)(((((
                                                   (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_63_exception_type_15) 
                                                         << 0xeU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_63_exception_type_15) 
                                                           << 0xcU)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_63_exception_type_15) 
                                                           << 0xaU) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_63_exception_type_15) 
                                                             << 8U))) 
                                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_exception_type_15) 
                                                           << 6U) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_exception_type_15) 
                                                             << 4U)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_63_exception_type_15) 
                                                             << 2U) 
                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_exception_type_15)))) 
                                                     >> 
                                                     (0xfU 
                                                      & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                    << 0x1eU) 
                                                   | (0x30000000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_62_exception_type_15) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_62_exception_type_15) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_exception_type_15) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_62_exception_type_15) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_62_exception_type_15) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_62_exception_type_15) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_62_exception_type_15) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_exception_type_15)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0x1cU))) 
                                                  | ((0xc000000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_exception_type_15) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_exception_type_15) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_exception_type_15) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_61_exception_type_15) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_61_exception_type_15) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_exception_type_15) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_61_exception_type_15) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_exception_type_15)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0x1aU)) 
                                                     | (0x3000000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_60_exception_type_15) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_60_exception_type_15) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_60_exception_type_15) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_60_exception_type_15) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_exception_type_15) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_60_exception_type_15) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_60_exception_type_15) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_60_exception_type_15)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0x18U)))) 
                                                 | (((0xc00000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_59_exception_type_15) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_59_exception_type_15) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_59_exception_type_15) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_59_exception_type_15) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_59_exception_type_15) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_59_exception_type_15) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_59_exception_type_15) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_59_exception_type_15)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0x16U)) 
                                                     | (0x300000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_58_exception_type_15) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_58_exception_type_15) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_58_exception_type_15) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_58_exception_type_15) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_exception_type_15) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_58_exception_type_15) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_58_exception_type_15) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_exception_type_15)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0x14U))) 
                                                    | ((0xc0000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_exception_type_15) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_57_exception_type_15) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_57_exception_type_15) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_exception_type_15) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_exception_type_15) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_57_exception_type_15) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_57_exception_type_15) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_exception_type_15)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0x12U)) 
                                                       | (0x30000U 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_56_exception_type_15) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_56_exception_type_15) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_56_exception_type_15) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_56_exception_type_15) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_56_exception_type_15) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_exception_type_15) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_56_exception_type_15) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_exception_type_15)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 0x10U))))) 
                                                | ((((0xc000U 
                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_55_exception_type_15) 
                                                              << 0xeU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_55_exception_type_15) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_55_exception_type_15) 
                                                                << 0xaU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_55_exception_type_15) 
                                                                  << 8U))) 
                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_55_exception_type_15) 
                                                                << 6U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_55_exception_type_15) 
                                                                  << 4U)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_55_exception_type_15) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_exception_type_15)))) 
                                                          >> 
                                                          (0xfU 
                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                         << 0xeU)) 
                                                     | (0x3000U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_54_exception_type_15) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_54_exception_type_15) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_54_exception_type_15) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_exception_type_15) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_54_exception_type_15) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_54_exception_type_15) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_54_exception_type_15) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_exception_type_15)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0xcU))) 
                                                    | ((0xc00U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_53_exception_type_15) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_53_exception_type_15) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_53_exception_type_15) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_exception_type_15) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_53_exception_type_15) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_53_exception_type_15) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_exception_type_15) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_exception_type_15)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 0xaU)) 
                                                       | (0x300U 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_52_exception_type_15) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_exception_type_15) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_exception_type_15) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_exception_type_15) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_52_exception_type_15) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_exception_type_15) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_52_exception_type_15) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_52_exception_type_15)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 8U)))) 
                                                   | (((0xc0U 
                                                        & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_51_exception_type_15) 
                                                                << 0xeU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_51_exception_type_15) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_51_exception_type_15) 
                                                                  << 0xaU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_exception_type_15) 
                                                                    << 8U))) 
                                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_51_exception_type_15) 
                                                                  << 6U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_51_exception_type_15) 
                                                                    << 4U)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_exception_type_15) 
                                                                    << 2U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_exception_type_15)))) 
                                                            >> 
                                                            (0xfU 
                                                             & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                           << 6U)) 
                                                       | (0x30U 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_50_exception_type_15) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_50_exception_type_15) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_50_exception_type_15) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_exception_type_15) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_50_exception_type_15) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_50_exception_type_15) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_50_exception_type_15) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_exception_type_15)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 4U))) 
                                                      | ((0xcU 
                                                          & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_49_exception_type_15) 
                                                                  << 0xeU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_49_exception_type_15) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_49_exception_type_15) 
                                                                    << 0xaU) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_exception_type_15) 
                                                                      << 8U))) 
                                                               | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_49_exception_type_15) 
                                                                    << 6U) 
                                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_exception_type_15) 
                                                                      << 4U)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_49_exception_type_15) 
                                                                      << 2U) 
                                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_exception_type_15)))) 
                                                              >> 
                                                              (0xfU 
                                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                             << 2U)) 
                                                         | (3U 
                                                            & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_48_exception_type_15) 
                                                                   << 0xeU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_48_exception_type_15) 
                                                                     << 0xcU)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_48_exception_type_15) 
                                                                     << 0xaU) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_exception_type_15) 
                                                                       << 8U))) 
                                                                | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_48_exception_type_15) 
                                                                     << 6U) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_exception_type_15) 
                                                                       << 4U)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_48_exception_type_15) 
                                                                       << 2U) 
                                                                      | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_exception_type_15)))) 
                                                               >> 
                                                               (0xfU 
                                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U)))))))))) 
                               << 0x20U) | (QData)((IData)(
                                                           (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_47_exception_type_15) 
                                                                     << 0xeU) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_exception_type_15) 
                                                                       << 0xcU)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_47_exception_type_15) 
                                                                       << 0xaU) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_exception_type_15) 
                                                                         << 8U))) 
                                                                  | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_47_exception_type_15) 
                                                                       << 6U) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_exception_type_15) 
                                                                         << 4U)) 
                                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_47_exception_type_15) 
                                                                         << 2U) 
                                                                        | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_exception_type_15)))) 
                                                                 >> 
                                                                 (0xfU 
                                                                  & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                << 0x1eU) 
                                                               | (0x30000000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_46_exception_type_15) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_46_exception_type_15) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_46_exception_type_15) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_exception_type_15) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_46_exception_type_15) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_46_exception_type_15) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_exception_type_15) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_46_exception_type_15)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0x1cU))) 
                                                              | ((0xc000000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_45_exception_type_15) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_exception_type_15) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_45_exception_type_15) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_exception_type_15) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_exception_type_15) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_exception_type_15) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_45_exception_type_15) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_exception_type_15)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0x1aU)) 
                                                                 | (0x3000000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_44_exception_type_15) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_44_exception_type_15) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_44_exception_type_15) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_44_exception_type_15) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_44_exception_type_15) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_exception_type_15) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_44_exception_type_15) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_44_exception_type_15)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0x18U)))) 
                                                             | (((0xc00000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_43_exception_type_15) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_exception_type_15) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_43_exception_type_15) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_exception_type_15) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_43_exception_type_15) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_exception_type_15) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_exception_type_15) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_exception_type_15)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0x16U)) 
                                                                 | (0x300000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_42_exception_type_15) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_exception_type_15) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_42_exception_type_15) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_exception_type_15) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_42_exception_type_15) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_42_exception_type_15) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_42_exception_type_15) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_42_exception_type_15)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0x14U))) 
                                                                | ((0xc0000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_41_exception_type_15) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_41_exception_type_15) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_41_exception_type_15) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_exception_type_15) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_41_exception_type_15) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_exception_type_15) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_41_exception_type_15) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_41_exception_type_15)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0x12U)) 
                                                                   | (0x30000U 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_40_exception_type_15) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_40_exception_type_15) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_40_exception_type_15) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_exception_type_15) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_40_exception_type_15) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_40_exception_type_15) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_40_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_exception_type_15)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 0x10U))))) 
                                                            | ((((0xc000U 
                                                                  & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_39_exception_type_15) 
                                                                          << 0xeU) 
                                                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_39_exception_type_15) 
                                                                            << 0xcU)) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_39_exception_type_15) 
                                                                            << 0xaU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_exception_type_15) 
                                                                              << 8U))) 
                                                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_39_exception_type_15) 
                                                                            << 6U) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_exception_type_15) 
                                                                              << 4U)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_exception_type_15) 
                                                                              << 2U) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_exception_type_15)))) 
                                                                      >> 
                                                                      (0xfU 
                                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                     << 0xeU)) 
                                                                 | (0x3000U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_38_exception_type_15) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_38_exception_type_15) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_38_exception_type_15) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_exception_type_15) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_38_exception_type_15) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_38_exception_type_15) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_38_exception_type_15) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_exception_type_15)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0xcU))) 
                                                                | ((0xc00U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_37_exception_type_15) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_37_exception_type_15) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_exception_type_15) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_37_exception_type_15) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_37_exception_type_15) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_exception_type_15) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_37_exception_type_15) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_exception_type_15)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 0xaU)) 
                                                                   | (0x300U 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_exception_type_15) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_36_exception_type_15) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_exception_type_15) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_36_exception_type_15) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_36_exception_type_15) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_36_exception_type_15) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_36_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_exception_type_15)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 8U)))) 
                                                               | (((0xc0U 
                                                                    & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_35_exception_type_15) 
                                                                            << 0xeU) 
                                                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_35_exception_type_15) 
                                                                              << 0xcU)) 
                                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_35_exception_type_15) 
                                                                              << 0xaU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_exception_type_15) 
                                                                                << 8U))) 
                                                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_exception_type_15) 
                                                                              << 6U) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_exception_type_15) 
                                                                                << 4U)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_35_exception_type_15) 
                                                                                << 2U) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_exception_type_15)))) 
                                                                        >> 
                                                                        (0xfU 
                                                                         & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                       << 6U)) 
                                                                   | (0x30U 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_34_exception_type_15) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_34_exception_type_15) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_34_exception_type_15) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_34_exception_type_15) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_34_exception_type_15) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_exception_type_15) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_34_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_exception_type_15)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 4U))) 
                                                                  | ((0xcU 
                                                                      & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_33_exception_type_15) 
                                                                              << 0xeU) 
                                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_33_exception_type_15) 
                                                                                << 0xcU)) 
                                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_33_exception_type_15) 
                                                                                << 0xaU) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_exception_type_15) 
                                                                                << 8U))) 
                                                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_exception_type_15) 
                                                                                << 6U) 
                                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_exception_type_15) 
                                                                                << 4U)) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_33_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_exception_type_15)))) 
                                                                          >> 
                                                                          (0xfU 
                                                                           & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                                         << 2U)) 
                                                                     | (3U 
                                                                        & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_32_exception_type_15) 
                                                                               << 0xeU) 
                                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_32_exception_type_15) 
                                                                                << 0xcU)) 
                                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_exception_type_15) 
                                                                                << 0xaU) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_exception_type_15) 
                                                                                << 8U))) 
                                                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_exception_type_15) 
                                                                                << 6U) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_32_exception_type_15) 
                                                                                << 4U)) 
                                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_exception_type_15) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_32_exception_type_15)))) 
                                                                           >> 
                                                                           (0xfU 
                                                                            & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))))))) 
                             >> 0x20U));
    __Vtemp_6[0U] = (((((((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_15_exception_type_15) 
                              << 0xeU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_15_exception_type_15) 
                                          << 0xcU)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_15_exception_type_15) 
                                << 0xaU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_exception_type_15) 
                                            << 8U))) 
                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_15_exception_type_15) 
                                << 6U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_15_exception_type_15) 
                                          << 4U)) | 
                              (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_15_exception_type_15) 
                                << 2U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_exception_type_15)))) 
                          >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                         << 0x1eU) | (0x30000000U & 
                                      (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_14_exception_type_15) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_14_exception_type_15) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_14_exception_type_15) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_exception_type_15) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_14_exception_type_15) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_14_exception_type_15) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_14_exception_type_15) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_exception_type_15)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0x1cU))) 
                       | ((0xc000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_13_exception_type_15) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_13_exception_type_15) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_13_exception_type_15) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_13_exception_type_15) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_exception_type_15) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_13_exception_type_15) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_13_exception_type_15) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_13_exception_type_15)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x1aU)) 
                          | (0x3000000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_12_exception_type_15) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_12_exception_type_15) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_12_exception_type_15) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_12_exception_type_15) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_12_exception_type_15) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_12_exception_type_15) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_12_exception_type_15) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_12_exception_type_15)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x18U)))) 
                      | (((0xc00000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_11_exception_type_15) 
                                             << 0xeU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_11_exception_type_15) 
                                               << 0xcU)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_11_exception_type_15) 
                                               << 0xaU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_11_exception_type_15) 
                                                 << 8U))) 
                                          | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_11_exception_type_15) 
                                               << 6U) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_11_exception_type_15) 
                                                 << 4U)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_11_exception_type_15) 
                                                 << 2U) 
                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_11_exception_type_15)))) 
                                         >> (0xfU & 
                                             VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                        << 0x16U)) 
                          | (0x300000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_10_exception_type_15) 
                                               << 0xeU) 
                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_10_exception_type_15) 
                                                 << 0xcU)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_10_exception_type_15) 
                                                 << 0xaU) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_10_exception_type_15) 
                                                   << 8U))) 
                                            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_10_exception_type_15) 
                                                 << 6U) 
                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_10_exception_type_15) 
                                                   << 4U)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_10_exception_type_15) 
                                                   << 2U) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_exception_type_15)))) 
                                           >> (0xfU 
                                               & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                          << 0x14U))) 
                         | ((0xc0000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_9_exception_type_15) 
                                              << 0xeU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_9_exception_type_15) 
                                                << 0xcU)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_9_exception_type_15) 
                                                << 0xaU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_9_exception_type_15) 
                                                  << 8U))) 
                                           | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_9_exception_type_15) 
                                                << 6U) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_9_exception_type_15) 
                                                  << 4U)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_9_exception_type_15) 
                                                  << 2U) 
                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_exception_type_15)))) 
                                          >> (0xfU 
                                              & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                         << 0x12U)) 
                            | (0x30000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_8_exception_type_15) 
                                                << 0xeU) 
                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_8_exception_type_15) 
                                                  << 0xcU)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_8_exception_type_15) 
                                                  << 0xaU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_8_exception_type_15) 
                                                    << 8U))) 
                                             | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_8_exception_type_15) 
                                                  << 6U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_8_exception_type_15) 
                                                    << 4U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_8_exception_type_15) 
                                                    << 2U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_8_exception_type_15)))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                           << 0x10U))))) 
                     | ((((0xc000U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_7_exception_type_15) 
                                           << 0xeU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_7_exception_type_15) 
                                             << 0xcU)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_7_exception_type_15) 
                                             << 0xaU) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_7_exception_type_15) 
                                               << 8U))) 
                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_exception_type_15) 
                                             << 6U) 
                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_7_exception_type_15) 
                                               << 4U)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_7_exception_type_15) 
                                               << 2U) 
                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_7_exception_type_15)))) 
                                       >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                      << 0xeU)) | (0x3000U 
                                                   & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_6_exception_type_15) 
                                                           << 0xeU) 
                                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_6_exception_type_15) 
                                                             << 0xcU)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_6_exception_type_15) 
                                                             << 0xaU) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_6_exception_type_15) 
                                                               << 8U))) 
                                                        | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_6_exception_type_15) 
                                                             << 6U) 
                                                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_6_exception_type_15) 
                                                               << 4U)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_6_exception_type_15) 
                                                               << 2U) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_6_exception_type_15)))) 
                                                       >> 
                                                       (0xfU 
                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                      << 0xcU))) 
                         | ((0xc00U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_5_exception_type_15) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_5_exception_type_15) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_5_exception_type_15) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_5_exception_type_15) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_exception_type_15) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_5_exception_type_15) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_5_exception_type_15) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_5_exception_type_15)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 0xaU)) | 
                            (0x300U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_4_exception_type_15) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_4_exception_type_15) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_4_exception_type_15) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_4_exception_type_15) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_exception_type_15) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_4_exception_type_15) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_4_exception_type_15) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_exception_type_15)))) 
                                        >> (0xfU & 
                                            VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                       << 8U)))) | 
                        (((0xc0U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_3_exception_type_15) 
                                         << 0xeU) | 
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_3_exception_type_15) 
                                         << 0xcU)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_3_exception_type_15) 
                                           << 0xaU) 
                                          | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_3_exception_type_15) 
                                             << 8U))) 
                                      | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_3_exception_type_15) 
                                           << 6U) | 
                                          ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_3_exception_type_15) 
                                           << 4U)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_3_exception_type_15) 
                                             << 2U) 
                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_exception_type_15)))) 
                                     >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                    << 6U)) | (0x30U 
                                               & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_2_exception_type_15) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_2_exception_type_15) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_2_exception_type_15) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_2_exception_type_15) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_2_exception_type_15) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_2_exception_type_15) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_2_exception_type_15) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_2_exception_type_15)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                                  << 4U))) 
                         | ((0xcU & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_1_exception_type_15) 
                                          << 0xeU) 
                                         | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_1_exception_type_15) 
                                            << 0xcU)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_1_exception_type_15) 
                                            << 0xaU) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_1_exception_type_15) 
                                              << 8U))) 
                                       | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_1_exception_type_15) 
                                            << 6U) 
                                           | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_1_exception_type_15) 
                                              << 4U)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_1_exception_type_15) 
                                              << 2U) 
                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_exception_type_15)))) 
                                      >> (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))) 
                                     << 2U)) | (3U 
                                                & ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_0_exception_type_15) 
                                                       << 0xeU) 
                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_0_exception_type_15) 
                                                         << 0xcU)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_0_exception_type_15) 
                                                         << 0xaU) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_0_exception_type_15) 
                                                           << 8U))) 
                                                    | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_0_exception_type_15) 
                                                         << 6U) 
                                                        | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_0_exception_type_15) 
                                                           << 4U)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_0_exception_type_15) 
                                                           << 2U) 
                                                          | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_0_exception_type_15)))) 
                                                   >> 
                                                   (0xfU 
                                                    & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__hitWay), 1U))))))));
    __Vtemp_6[1U] = __Vtemp_5[0U];
    __Vtemp_6[2U] = __Vtemp_5[1U];
    __Vtemp_6[3U] = __Vtemp_5[2U];
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__io_read_resp_data_exception_type_15 
        = (3U & (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                (0x3fU 
                                                 & (IData)(
                                                           (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                            >> 2U))), 1U)))
                   ? 0U : (__Vtemp_6[(((IData)(1U) 
                                       + (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                                (0x3fU 
                                                                 & (IData)(
                                                                           (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                                            >> 2U))), 1U))) 
                                      >> 5U)] << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(7,7,32, 
                                                                   (0x3fU 
                                                                    & (IData)(
                                                                              (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                                               >> 2U))), 1U))))) 
                 | (__Vtemp_6[(3U & (VL_SHIFTL_III(7,7,32, 
                                                   (0x3fU 
                                                    & (IData)(
                                                              (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                               >> 2U))), 1U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (0x3fU 
                                                                   & (IData)(
                                                                             (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc 
                                                                              >> 2U))), 1U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_is_ret 
        = ((0x67U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst)) 
           & (((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst 
                                >> 0xfU))) | (5U == 
                                              (0x1fU 
                                               & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst 
                                                  >> 0xfU)))) 
              & ((0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst 
                           >> 7U)) != (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst 
                                                >> 0xfU)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_1__DOT___io_out_is_call_T 
        = ((0x6fU == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst)) 
           | (0x67U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst)));
    if ((0x200U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu_skid__DOT__slot0_data_mask))) {
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_915 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_914) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_723));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_918 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_917) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_726));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_921 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_920) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_729));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_924 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_923) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_732));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1689 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_914) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1641));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1690 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_917) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1642));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1691 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_920) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1643));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1692 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_923) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1644));
    } else {
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_915 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_777) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_723));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_918 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_778) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_726));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_921 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_779) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_729));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_924 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_780) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_732));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1689 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_777) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1641));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1690 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_778) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1642));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1691 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_779) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1643));
        ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1692 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_780) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1644));
    }
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__allocWay 
        = (((IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_14 
                     >> (0x3fU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0 
                                          >> 2U))))) 
            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8406) 
               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8405) 
                  & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8404) 
                     & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8403) 
                        & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8402) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8401) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8400))))))))
            ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8408)
            : ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8400)
                ? ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8401)
                    ? ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8402)
                        ? ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8403)
                            ? ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8404)
                                ? ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8405)
                                    ? (6U | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8406))
                                    : 5U) : 4U) : 3U)
                        : 2U) : 1U) : 0U));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst 
        = ((3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0))
            ? vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_0__DOT___rvc_expander_io_out
            : vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0);
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_2 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 2U) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                       & (IData)((4U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_1) 
                          & (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                                          >> 0x10U)))) 
                         | ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                            & ((3U == (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0)) 
                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_0))))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_14_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_14__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_14_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_14_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_14__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_14_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_14_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_15_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_15__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_15_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_15_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_15__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_15_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_15_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_12_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_12__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_12_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_12_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_12__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_12_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_12_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_13_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_13__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_13_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_13_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_13__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_13_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_13_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_10_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_10__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_10_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_10_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_10__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_10_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_10_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_11_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_11__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_11_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_11_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_11__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_11_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_11_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_8_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_8__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_8_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_8_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_8__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_8_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_8_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_9_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_9__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_9_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_9_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_9__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_9_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_9_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_6_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_6__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_6_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_6_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_6__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_6_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_6_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_7_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_7__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_7_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_7_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_7__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_7_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_7_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_4_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_4__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_4_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_4_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_4__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_4_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_4_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_5_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_5__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_5_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_5_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_5__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_5_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_5_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_2_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_2__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_2_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_2_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_2__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_2_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_2_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_3_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_3__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_3_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_3_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_3__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_3_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_3_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_1__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_1__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_1_expanded_inst 
                                                     >> 7U)))));
    if ((0x800U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu_skid__DOT__slot0_data_mask))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1107 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1106) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_915));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1110 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1109) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_918));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1113 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1112) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_921));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1116 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1115) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_924));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1737 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1106) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1689));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1738 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1109) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1690));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1739 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1112) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1691));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1740 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1115) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1692));
    } else {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1107 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_969) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_915));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1110 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_970) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_918));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1113 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_971) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_921));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1116 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_972) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_924));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1737 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_969) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1689));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1738 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_970) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1690));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1739 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_971) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1691));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1740 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_972) 
               | (IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1692));
    }
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT____Vcellinp__uopCache__io_write_req_valid) 
           & (0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__allocWay)));
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT____Vcellinp__uopCache__io_write_req_valid) 
           & (1U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__allocWay)));
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT____Vcellinp__uopCache__io_write_req_valid) 
           & (2U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__allocWay)));
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT____Vcellinp__uopCache__io_write_req_valid) 
           & (3U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__allocWay)));
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT____Vcellinp__uopCache__io_write_req_valid) 
           & (4U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__allocWay)));
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT____Vcellinp__uopCache__io_write_req_valid) 
           & (5U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__allocWay)));
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT____Vcellinp__uopCache__io_write_req_valid) 
           & (6U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__allocWay)));
    ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT____Vcellinp__uopCache__io_write_req_valid) 
           & (7U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__allocWay)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_is_ret 
        = ((0x67U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst)) 
           & (((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst 
                                >> 0xfU))) | (5U == 
                                              (0x1fU 
                                               & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst 
                                                  >> 0xfU)))) 
              & ((0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst 
                           >> 7U)) != (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst 
                                                >> 0xfU)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_0__DOT___io_out_is_call_T 
        = ((0x6fU == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst)) 
           | (0x67U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_3 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 3U) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                       & (IData)((8U == (0xfU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_2) 
                          & (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1))) 
                         | (IData)(((0x30000U == (0x30000U 
                                                  & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0)) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_1))))));
    if ((0x2000U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu_skid__DOT__slot0_data_mask))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1299 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1298) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1107));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1302 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1301) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1110));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1305 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1304) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1113));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1308 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1307) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1116));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1785 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1298) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1737));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1786 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1301) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1738));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1787 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1304) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1739));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1788 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1307) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1740));
    } else {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1299 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1161) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1107));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1302 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1162) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1110));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1305 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1163) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1113));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1308 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1164) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1116));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1785 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1161) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1737));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1786 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1162) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1738));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1787 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1163) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1739));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1788 
            = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1164) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT___GEN_1740));
    }
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8411 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8413 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8415 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8417 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8419 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x10ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8421 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x14ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8423 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x18ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8425 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x1cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8427 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x20ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8429 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x24ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8431 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x28ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8433 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x2cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8435 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x30ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8437 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x34ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8439 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x38ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8441 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x3cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8443 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x40ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8445 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x44ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8447 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x48ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8449 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x4cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8451 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x50ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8453 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x54ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8455 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x58ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8457 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x5cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8459 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x60ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8461 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x64ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8463 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x68ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8465 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x6cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8467 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x70ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8469 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x74ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8471 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x78ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8473 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x7cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8475 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x80ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8477 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x84ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8479 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x88ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8481 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x8cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8483 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x90ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8485 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x94ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8487 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x98ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8489 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0x9cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8491 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xa0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8493 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xa4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8495 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xa8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8497 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xacULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8499 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xb0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8501 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xb4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8503 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xb8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8505 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xbcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8507 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xc0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8509 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xc4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8511 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xc8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8513 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xccULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8515 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xd0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8517 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xd4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8519 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xd8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8521 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xdcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8523 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xe0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8525 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xe4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8527 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xe8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8529 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xecULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8531 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xf0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8533 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xf4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8535 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xf8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8536 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_3) 
           & (0xfcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8538 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8539 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8540 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8541 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8542 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x10ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8543 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x14ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8544 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x18ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8545 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x1cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8546 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x20ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8547 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x24ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8548 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x28ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8549 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x2cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8550 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x30ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8551 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x34ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8552 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x38ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8553 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x3cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8554 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x40ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8555 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x44ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8556 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x48ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8557 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x4cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8558 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x50ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8559 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x54ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8560 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x58ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8561 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x5cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8562 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x60ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8563 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x64ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8564 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x68ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8565 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x6cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8566 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x70ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8567 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x74ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8568 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x78ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8569 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x7cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8570 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x80ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8571 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x84ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8572 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x88ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8573 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x8cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8574 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x90ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8575 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x94ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8576 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x98ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8577 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0x9cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8578 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xa0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8579 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xa4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8580 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xa8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8581 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xacULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8582 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xb0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8583 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xb4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8584 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xb8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8585 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xbcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8586 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xc0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8587 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xc4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8588 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xc8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8589 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xccULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8590 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xd0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8591 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xd4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8592 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xd8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8593 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xdcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8594 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xe0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8595 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xe4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8596 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xe8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8597 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xecULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8598 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xf0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8599 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xf4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8600 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xf8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8601 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_5) 
           & (0xfcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8603 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8604 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8605 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8606 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8607 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x10ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8608 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x14ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8609 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x18ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8610 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x1cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8611 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x20ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8612 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x24ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8613 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x28ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8614 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x2cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8615 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x30ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8616 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x34ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8617 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x38ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8618 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x3cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8619 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x40ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8620 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x44ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8621 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x48ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8622 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x4cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8623 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x50ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8624 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x54ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8625 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x58ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8626 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x5cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8627 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x60ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8628 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x64ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8629 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x68ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8630 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x6cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8631 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x70ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8632 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x74ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8633 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x78ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8634 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x7cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8635 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x80ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8636 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x84ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8637 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x88ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8638 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x8cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8639 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x90ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8640 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x94ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8641 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x98ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8642 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0x9cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8643 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xa0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8644 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xa4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8645 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xa8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8646 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xacULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8647 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xb0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8648 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xb4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8649 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xb8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8650 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xbcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8651 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xc0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8652 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xc4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8653 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xc8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8654 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xccULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8655 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xd0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8656 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xd4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8657 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xd8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8658 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xdcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8659 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xe0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8660 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xe4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8661 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xe8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8662 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xecULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8663 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xf0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8664 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xf4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8665 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xf8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8666 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_6) 
           & (0xfcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8668 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8669 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8670 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8671 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8672 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x10ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8673 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x14ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8674 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x18ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8675 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x1cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8676 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x20ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8677 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x24ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8678 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x28ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8679 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x2cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8680 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x30ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8681 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x34ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8682 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x38ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8683 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x3cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8684 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x40ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8685 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x44ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8686 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x48ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8687 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x4cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8688 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x50ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8689 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x54ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8690 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x58ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8691 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x5cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8692 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x60ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8693 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x64ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8694 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x68ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8695 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x6cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8696 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x70ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8697 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x74ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8698 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x78ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8699 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x7cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8700 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x80ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8701 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x84ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8702 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x88ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8703 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x8cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8704 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x90ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8705 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x94ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8706 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x98ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8707 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0x9cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8708 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xa0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8709 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xa4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8710 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xa8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8711 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xacULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8712 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xb0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8713 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xb4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8714 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xb8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8715 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xbcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8716 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xc0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8717 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xc4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8718 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xc8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8719 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xccULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8720 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xd0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8721 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xd4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8722 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xd8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8723 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xdcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8724 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xe0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8725 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xe4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8726 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xe8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8727 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xecULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8728 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xf0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8729 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xf4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8730 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xf8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8731 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_7) 
           & (0xfcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8733 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8734 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8735 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8736 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8737 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x10ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8738 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x14ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8739 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x18ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8740 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x1cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8741 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x20ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8742 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x24ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8743 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x28ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8744 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x2cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8745 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x30ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8746 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x34ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8747 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x38ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8748 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x3cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8749 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x40ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8750 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x44ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8751 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x48ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8752 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x4cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8753 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x50ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8754 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x54ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8755 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x58ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8756 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x5cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8757 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x60ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8758 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x64ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8759 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x68ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8760 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x6cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8761 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x70ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8762 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x74ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8763 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x78ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8764 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x7cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8765 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x80ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8766 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x84ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8767 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x88ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8768 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x8cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8769 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x90ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8770 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x94ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8771 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x98ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8772 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0x9cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8773 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xa0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8774 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xa4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8775 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xa8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8776 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xacULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8777 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xb0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8778 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xb4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8779 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xb8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8780 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xbcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8781 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xc0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8782 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xc4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8783 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xc8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8784 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xccULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8785 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xd0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8786 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xd4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8787 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xd8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8788 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xdcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8789 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xe0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8790 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xe4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8791 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xe8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8792 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xecULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8793 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xf0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8794 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xf4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8795 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xf8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8796 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_8) 
           & (0xfcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8798 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8799 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8800 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8801 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8802 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x10ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8803 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x14ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8804 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x18ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8805 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x1cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8806 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x20ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8807 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x24ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8808 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x28ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8809 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x2cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8810 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x30ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8811 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x34ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8812 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x38ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8813 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x3cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8814 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x40ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8815 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x44ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8816 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x48ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8817 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x4cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8818 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x50ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8819 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x54ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8820 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x58ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8821 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x5cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8822 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x60ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8823 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x64ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8824 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x68ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8825 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x6cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8826 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x70ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8827 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x74ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8828 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x78ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8829 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x7cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8830 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x80ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8831 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x84ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8832 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x88ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8833 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x8cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8834 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x90ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8835 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x94ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8836 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x98ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8837 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0x9cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8838 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xa0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8839 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xa4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8840 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xa8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8841 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xacULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8842 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xb0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8843 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xb4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8844 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xb8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8845 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xbcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8846 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xc0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8847 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xc4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8848 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xc8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8849 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xccULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8850 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xd0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8851 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xd4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8852 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xd8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8853 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xdcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8854 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xe0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8855 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xe4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8856 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xe8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8857 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xecULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8858 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xf0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8859 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xf4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8860 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xf8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8861 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_9) 
           & (0xfcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8863 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8864 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8865 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8866 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8867 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x10ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8868 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x14ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8869 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x18ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8870 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x1cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8871 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x20ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8872 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x24ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8873 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x28ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8874 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x2cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8875 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x30ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8876 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x34ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8877 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x38ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8878 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x3cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8879 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x40ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8880 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x44ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8881 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x48ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8882 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x4cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8883 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x50ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8884 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x54ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8885 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x58ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8886 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x5cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8887 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x60ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8888 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x64ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8889 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x68ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8890 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x6cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8891 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x70ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8892 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x74ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8893 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x78ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8894 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x7cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8895 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x80ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8896 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x84ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8897 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x88ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8898 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x8cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8899 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x90ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8900 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x94ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8901 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x98ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8902 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0x9cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8903 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xa0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8904 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xa4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8905 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xa8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8906 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xacULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8907 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xb0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8908 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xb4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8909 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xb8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8910 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xbcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8911 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xc0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8912 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xc4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8913 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xc8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8914 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xccULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8915 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xd0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8916 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xd4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8917 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xd8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8918 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xdcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8919 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xe0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8920 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xe4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8921 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xe8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8922 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xecULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8923 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xf0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8924 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xf4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8925 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xf8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8926 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_10) 
           & (0xfcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8927 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8928 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8929 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8930 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8931 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x10ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8932 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x14ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8933 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x18ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8934 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x1cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8935 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x20ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8936 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x24ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8937 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x28ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8938 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x2cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8939 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x30ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8940 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x34ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8941 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x38ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8942 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x3cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8943 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x40ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8944 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x44ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8945 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x48ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8946 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x4cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8947 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x50ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8948 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x54ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8949 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x58ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8950 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x5cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8951 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x60ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8952 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x64ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8953 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x68ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8954 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x6cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8955 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x70ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8956 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x74ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8957 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x78ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8958 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x7cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8959 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x80ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8960 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x84ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8961 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x88ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8962 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x8cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8963 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x90ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8964 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x94ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8965 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x98ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8966 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0x9cULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8967 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xa0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8968 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xa4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8969 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xa8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8970 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xacULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8971 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xb0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8972 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xb4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8973 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xb8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8974 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xbcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8975 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xc0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8976 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xc4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8977 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xc8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8978 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xccULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8979 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xd0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8980 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xd4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8981 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xd8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8982 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xdcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8983 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xe0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8984 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xe4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8985 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xe8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8986 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xecULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8987 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xf0ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8988 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xf4ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8989 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xf8ULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8990 
        = ((IData)(ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT____VdfgRegularize_hc9788227_0_11) 
           & (0xfcULL == (0xfcULL & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pc_0)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_is_cfi 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_0__DOT___io_out_is_call_T) 
           | (0x63U == (0x7fU & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_is_call 
        = ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__predecoders_0__DOT___io_out_is_call_T) 
           & ((1U == (0x1fU & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst 
                               >> 7U))) | (5U == (0x1fU 
                                                  & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_pre_decoded_0_expanded_inst 
                                                     >> 7U)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_4 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 4U) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                       & (IData)((0x10U == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_3) 
                          & (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                                          >> 0x10U)))) 
                         | ((3U == (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1)) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_2)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_5 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 5U) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                       & (IData)((0x20U == (0x3fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_4) 
                          & (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_2))) 
                         | (IData)(((0x30000U == (0x30000U 
                                                  & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1)) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_3))))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_6 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 6U) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                       & (IData)((0x40U == (0x7fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_5) 
                          & (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_2 
                                          >> 0x10U)))) 
                         | ((3U == (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_2)) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_4)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_7 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 7U) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                       & (IData)((0x80U == (0xffU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_6) 
                          & (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_3))) 
                         | (IData)(((0x30000U == (0x30000U 
                                                  & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_2)) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_5))))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_8 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 8U) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                       & (IData)((0x100U == (0x1ffU 
                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_7) 
                          & (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_3 
                                          >> 0x10U)))) 
                         | ((3U == (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_3)) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_6)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_9 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 9U) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                       & (IData)((0x200U == (0x3ffU 
                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_8) 
                          & (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_4))) 
                         | (IData)(((0x30000U == (0x30000U 
                                                  & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_3)) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_7))))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_10 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 0xaU) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                         & (IData)((0x400U == (0x7ffU 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_9) 
                            & (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_4 
                                            >> 0x10U)))) 
                           | ((3U == (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_4)) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_8)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_11 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 0xbU) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                         & (IData)((0x800U == (0xfffU 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_10) 
                            & (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_5))) 
                           | (IData)(((0x30000U == 
                                       (0x30000U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_4)) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_9))))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_12 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 0xcU) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                         & (IData)((0x1000U == (0x1fffU 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_11) 
                            & (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_5 
                                            >> 0x10U)))) 
                           | ((3U == (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_5)) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_10)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_13 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 0xdU) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                         & (IData)((0x2000U == (0x3fffU 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_12) 
                            & (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_6))) 
                           | (IData)(((0x30000U == 
                                       (0x30000U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_5)) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_11))))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_14 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 0xeU) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                         & (IData)((0x4000U == (0x7fffU 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask))))) 
                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_13) 
                            & (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_6 
                                            >> 0x10U)))) 
                           | ((3U == (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_6)) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_12)))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_15 
        = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask) 
            >> 0xfU) & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__is_cross_match)) 
                         & (IData)((0x8000U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_mask)))) 
                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_14) 
                            & (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_7))) 
                           | (IData)(((0x30000U == 
                                       (0x30000U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_6)) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_13))))));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__slot15_crosses 
        = (IData)(((0x30000U == (0x30000U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_7)) 
                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_15)));
    vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_mask 
        = (((((((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__slot15_crosses)) 
                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_15)) 
               << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_14) 
                           << 0xeU)) | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_13) 
                                         << 0xdU) | 
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_12) 
                                         << 0xcU))) 
            | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_11) 
                 << 0xbU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_10) 
                             << 0xaU)) | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_9) 
                                           << 9U) | 
                                          ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_8) 
                                           << 8U)))) 
           | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_7) 
                 << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_6) 
                           << 6U)) | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_5) 
                                       << 5U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_4) 
                                                 << 4U))) 
              | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_3) 
                   << 3U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_2) 
                             << 2U)) | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_1) 
                                         << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu__DOT__raw_mask_0)))));
}
