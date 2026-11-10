// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VZaqalSoCTop__Syms.h"


void VZaqalSoCTop___024root__trace_chg_3_sub_8(VZaqalSoCTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VZaqalSoCTop___024root__trace_chg_3_sub_8\n"); );
    VZaqalSoCTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 167075);
    VlWide<32>/*1023:0*/ __Vtemp_15;
    VlWide<16>/*511:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<6>/*191:0*/ __Vtemp_34;
    VlWide<4>/*127:0*/ __Vtemp_36;
    VlWide<4>/*127:0*/ __Vtemp_38;
    VlWide<4>/*127:0*/ __Vtemp_40;
    // Body
    bufp->chgBit(oldp+0,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_401) 
                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_0_uop_decode_is_slt)) 
                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_405) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_1_uop_decode_is_slt)) 
                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_409) 
                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_2_uop_decode_is_slt)) 
                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_413) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_3_uop_decode_is_slt)) 
                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_417) 
                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_4_uop_decode_is_slt)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_421) 
                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_5_uop_decode_is_slt)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_425) 
                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_6_uop_decode_is_slt)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_429) 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_7_uop_decode_is_slt)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_433) 
                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_8_uop_decode_is_slt)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_437) 
                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_9_uop_decode_is_slt)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_441) 
                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_10_uop_decode_is_slt)) 
                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_445) 
                                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_11_uop_decode_is_slt)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_449) 
                                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_12_uop_decode_is_slt)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_453) 
                                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_13_uop_decode_is_slt)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_457) 
                                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_14_uop_decode_is_slt)) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_461) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_15_uop_decode_is_slt)))))))))))))))))));
    bufp->chgBit(oldp+1,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_401) 
                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_0_uop_decode_is_bclri)) 
                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_405) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_1_uop_decode_is_bclri)) 
                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_409) 
                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_2_uop_decode_is_bclri)) 
                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_413) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_3_uop_decode_is_bclri)) 
                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_417) 
                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_4_uop_decode_is_bclri)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_421) 
                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_5_uop_decode_is_bclri)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_425) 
                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_6_uop_decode_is_bclri)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_429) 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_7_uop_decode_is_bclri)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_433) 
                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_8_uop_decode_is_bclri)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_437) 
                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_9_uop_decode_is_bclri)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_441) 
                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_10_uop_decode_is_bclri)) 
                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_445) 
                                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_11_uop_decode_is_bclri)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_449) 
                                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_12_uop_decode_is_bclri)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_453) 
                                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_13_uop_decode_is_bclri)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_457) 
                                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_14_uop_decode_is_bclri)) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_461) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_15_uop_decode_is_bclri)))))))))))))))))));
    bufp->chgBit(oldp+2,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_402) 
                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_0_uop_decode_is_slt)) 
                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_406) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_1_uop_decode_is_slt)) 
                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_410) 
                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_2_uop_decode_is_slt)) 
                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_414) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_3_uop_decode_is_slt)) 
                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_418) 
                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_4_uop_decode_is_slt)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_422) 
                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_5_uop_decode_is_slt)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_426) 
                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_6_uop_decode_is_slt)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_430) 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_7_uop_decode_is_slt)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_434) 
                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_8_uop_decode_is_slt)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_438) 
                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_9_uop_decode_is_slt)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_442) 
                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_10_uop_decode_is_slt)) 
                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_446) 
                                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_11_uop_decode_is_slt)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_450) 
                                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_12_uop_decode_is_slt)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_454) 
                                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_13_uop_decode_is_slt)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_458) 
                                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_14_uop_decode_is_slt)) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_462) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_15_uop_decode_is_slt)))))))))))))))))));
    bufp->chgBit(oldp+3,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_402) 
                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_0_uop_decode_is_bclri)) 
                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_406) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_1_uop_decode_is_bclri)) 
                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_410) 
                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_2_uop_decode_is_bclri)) 
                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_414) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_3_uop_decode_is_bclri)) 
                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_418) 
                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_4_uop_decode_is_bclri)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_422) 
                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_5_uop_decode_is_bclri)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_426) 
                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_6_uop_decode_is_bclri)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_430) 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_7_uop_decode_is_bclri)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_434) 
                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_8_uop_decode_is_bclri)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_438) 
                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_9_uop_decode_is_bclri)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_442) 
                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_10_uop_decode_is_bclri)) 
                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_446) 
                                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_11_uop_decode_is_bclri)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_450) 
                                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_12_uop_decode_is_bclri)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_454) 
                                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_13_uop_decode_is_bclri)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_458) 
                                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_14_uop_decode_is_bclri)) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_462) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_15_uop_decode_is_bclri)))))))))))))))))));
    bufp->chgBit(oldp+4,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_403) 
                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_0_uop_decode_is_slt)) 
                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_407) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_1_uop_decode_is_slt)) 
                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_411) 
                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_2_uop_decode_is_slt)) 
                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_415) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_3_uop_decode_is_slt)) 
                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_419) 
                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_4_uop_decode_is_slt)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_423) 
                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_5_uop_decode_is_slt)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_427) 
                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_6_uop_decode_is_slt)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_431) 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_7_uop_decode_is_slt)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_435) 
                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_8_uop_decode_is_slt)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_439) 
                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_9_uop_decode_is_slt)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_443) 
                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_10_uop_decode_is_slt)) 
                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_447) 
                                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_11_uop_decode_is_slt)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_451) 
                                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_12_uop_decode_is_slt)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_455) 
                                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_13_uop_decode_is_slt)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_459) 
                                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_14_uop_decode_is_slt)) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_463) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_15_uop_decode_is_slt)))))))))))))))))));
    bufp->chgBit(oldp+5,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_403) 
                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_0_uop_decode_is_bclri)) 
                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_407) 
                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_1_uop_decode_is_bclri)) 
                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_411) 
                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_2_uop_decode_is_bclri)) 
                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_415) 
                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_3_uop_decode_is_bclri)) 
                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_419) 
                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_4_uop_decode_is_bclri)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_423) 
                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_5_uop_decode_is_bclri)) 
                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_427) 
                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_6_uop_decode_is_bclri)) 
                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_431) 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_7_uop_decode_is_bclri)) 
                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_435) 
                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_8_uop_decode_is_bclri)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_439) 
                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_9_uop_decode_is_bclri)) 
                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_443) 
                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_10_uop_decode_is_bclri)) 
                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_447) 
                                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_11_uop_decode_is_bclri)) 
                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_451) 
                                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_12_uop_decode_is_bclri)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_455) 
                                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_13_uop_decode_is_bclri)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_459) 
                                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_14_uop_decode_is_bclri)) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT____VdfgRegularize_hb3f26619_0_463) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpIq__DOT__entries_15_uop_decode_is_bclri)))))))))))))))))));
    bufp->chgBit(oldp+6,((1U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_0_buf__DOT__slot0_data_decode_rs3_is_fp)
                                 ? ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_0_buf__DOT__slot0_data_psrs3)) 
                                    | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpBusyTable__DOT___GEN_28608[
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_0_buf__DOT__slot0_data_psrs3) 
                                        >> 5U)] >> 
                                       (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_0_buf__DOT__slot0_data_psrs3))))
                                 : ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_0_buf__DOT__slot0_data_psrs3)) 
                                    | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intBusyTable__DOT___GEN_28608[
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_0_buf__DOT__slot0_data_psrs3) 
                                        >> 5U)] >> 
                                       (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_0_buf__DOT__slot0_data_psrs3))))))));
    bufp->chgBit(oldp+7,((1U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_1_buf__DOT__slot0_data_decode_rs3_is_fp)
                                 ? ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_1_buf__DOT__slot0_data_psrs3)) 
                                    | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpBusyTable__DOT___GEN_28608[
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_1_buf__DOT__slot0_data_psrs3) 
                                        >> 5U)] >> 
                                       (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_1_buf__DOT__slot0_data_psrs3))))
                                 : ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_1_buf__DOT__slot0_data_psrs3)) 
                                    | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intBusyTable__DOT___GEN_28608[
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_1_buf__DOT__slot0_data_psrs3) 
                                        >> 5U)] >> 
                                       (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_1_buf__DOT__slot0_data_psrs3))))))));
    bufp->chgBit(oldp+8,((1U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_2_buf__DOT__slot0_data_decode_rs3_is_fp)
                                 ? ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_2_buf__DOT__slot0_data_psrs3)) 
                                    | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpBusyTable__DOT___GEN_28608[
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_2_buf__DOT__slot0_data_psrs3) 
                                        >> 5U)] >> 
                                       (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_2_buf__DOT__slot0_data_psrs3))))
                                 : ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_2_buf__DOT__slot0_data_psrs3)) 
                                    | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intBusyTable__DOT___GEN_28608[
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_2_buf__DOT__slot0_data_psrs3) 
                                        >> 5U)] >> 
                                       (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_2_buf__DOT__slot0_data_psrs3))))))));
    bufp->chgBit(oldp+9,((1U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_3_buf__DOT__slot0_data_decode_rs3_is_fp)
                                 ? ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_3_buf__DOT__slot0_data_psrs3)) 
                                    | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpBusyTable__DOT___GEN_28608[
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_3_buf__DOT__slot0_data_psrs3) 
                                        >> 5U)] >> 
                                       (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_3_buf__DOT__slot0_data_psrs3))))
                                 : ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_3_buf__DOT__slot0_data_psrs3)) 
                                    | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intBusyTable__DOT___GEN_28608[
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_3_buf__DOT__slot0_data_psrs3) 
                                        >> 5U)] >> 
                                       (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_3_buf__DOT__slot0_data_psrs3))))))));
    bufp->chgBit(oldp+10,((1U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_4_buf__DOT__slot0_data_decode_rs3_is_fp)
                                  ? ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_4_buf__DOT__slot0_data_psrs3)) 
                                     | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpBusyTable__DOT___GEN_28608[
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_4_buf__DOT__slot0_data_psrs3) 
                                         >> 5U)] >> 
                                        (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_4_buf__DOT__slot0_data_psrs3))))
                                  : ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_4_buf__DOT__slot0_data_psrs3)) 
                                     | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intBusyTable__DOT___GEN_28608[
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_4_buf__DOT__slot0_data_psrs3) 
                                         >> 5U)] >> 
                                        (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_4_buf__DOT__slot0_data_psrs3))))))));
    bufp->chgBit(oldp+11,((1U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_5_buf__DOT__slot0_data_decode_rs3_is_fp)
                                  ? ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_5_buf__DOT__slot0_data_psrs3)) 
                                     | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpBusyTable__DOT___GEN_28608[
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_5_buf__DOT__slot0_data_psrs3) 
                                         >> 5U)] >> 
                                        (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_5_buf__DOT__slot0_data_psrs3))))
                                  : ((0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_5_buf__DOT__slot0_data_psrs3)) 
                                     | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intBusyTable__DOT___GEN_28608[
                                        ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_5_buf__DOT__slot0_data_psrs3) 
                                         >> 5U)] >> 
                                        (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_5_buf__DOT__slot0_data_psrs3))))))));
    __Vtemp_15[0U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_uop_pc);
    __Vtemp_15[1U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_uop_pc 
                              >> 0x20U));
    __Vtemp_15[2U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_uop_pc);
    __Vtemp_15[3U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_uop_pc 
                              >> 0x20U));
    __Vtemp_15[4U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_uop_pc);
    __Vtemp_15[5U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_uop_pc 
                              >> 0x20U));
    __Vtemp_15[6U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_uop_pc);
    __Vtemp_15[7U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_uop_pc 
                              >> 0x20U));
    __Vtemp_15[8U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_uop_pc);
    __Vtemp_15[9U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_uop_pc 
                              >> 0x20U));
    __Vtemp_15[0xaU] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_uop_pc);
    __Vtemp_15[0xbU] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_uop_pc 
                                >> 0x20U));
    __Vtemp_15[0xcU] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_uop_pc);
    __Vtemp_15[0xdU] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_uop_pc 
                                >> 0x20U));
    __Vtemp_15[0xeU] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_uop_pc);
    __Vtemp_15[0xfU] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_uop_pc 
                                >> 0x20U));
    __Vtemp_15[0x10U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_uop_pc);
    __Vtemp_15[0x11U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_uop_pc 
                                 >> 0x20U));
    __Vtemp_15[0x12U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_uop_pc);
    __Vtemp_15[0x13U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_uop_pc 
                                 >> 0x20U));
    __Vtemp_15[0x14U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_uop_pc);
    __Vtemp_15[0x15U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_uop_pc 
                                 >> 0x20U));
    __Vtemp_15[0x16U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_uop_pc);
    __Vtemp_15[0x17U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_uop_pc 
                                 >> 0x20U));
    __Vtemp_15[0x18U] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_uop_pc);
    __Vtemp_15[0x19U] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_uop_pc 
                                 >> 0x20U));
    __Vtemp_15[0x1aU] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_uop_pc);
    __Vtemp_15[0x1bU] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_uop_pc 
                                 >> 0x20U));
    __Vtemp_15[0x1cU] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_uop_pc);
    __Vtemp_15[0x1dU] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_uop_pc 
                                 >> 0x20U));
    __Vtemp_15[0x1eU] = (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_uop_pc);
    __Vtemp_15[0x1fU] = (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_uop_pc 
                                 >> 0x20U));
    bufp->chgQData(oldp+12,((((QData)((IData)(__Vtemp_15[
                                              (((IData)(0x3fU) 
                                                + (0x3ffU 
                                                   & VL_SHIFTL_III(10,10,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 6U))) 
                                               >> 5U)])) 
                              << ((0U == (0x1fU & VL_SHIFTL_III(10,10,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 6U)))
                                   ? 0x20U : ((IData)(0x40U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(10,10,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 6U))))) 
                             | (((0U == (0x1fU & VL_SHIFTL_III(10,10,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 6U)))
                                  ? 0ULL : ((QData)((IData)(
                                                            __Vtemp_15[
                                                            (((IData)(0x1fU) 
                                                              + 
                                                              (0x3ffU 
                                                               & VL_SHIFTL_III(10,10,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 6U))) 
                                                             >> 5U)])) 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(10,10,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 6U))))) 
                                | ((QData)((IData)(
                                                   __Vtemp_15[
                                                   (0x1fU 
                                                    & (VL_SHIFTL_III(10,10,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 6U) 
                                                       >> 5U))])) 
                                   >> (0x1fU & VL_SHIFTL_III(10,10,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 6U)))))),64);
    __Vtemp_29[0U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_uop_inst_raw;
    __Vtemp_29[1U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_uop_inst_raw;
    __Vtemp_29[2U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_uop_inst_raw;
    __Vtemp_29[3U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_uop_inst_raw;
    __Vtemp_29[4U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_uop_inst_raw;
    __Vtemp_29[5U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_uop_inst_raw;
    __Vtemp_29[6U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_uop_inst_raw;
    __Vtemp_29[7U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_uop_inst_raw;
    __Vtemp_29[8U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_uop_inst_raw;
    __Vtemp_29[9U] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_uop_inst_raw;
    __Vtemp_29[0xaU] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_uop_inst_raw;
    __Vtemp_29[0xbU] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_uop_inst_raw;
    __Vtemp_29[0xcU] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_uop_inst_raw;
    __Vtemp_29[0xdU] = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_uop_inst_raw;
    __Vtemp_29[0xeU] = (IData)((((QData)((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_uop_inst_raw)) 
                                 << 0x20U) | (QData)((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_uop_inst_raw))));
    __Vtemp_29[0xfU] = (IData)(((((QData)((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_uop_inst_raw)) 
                                  << 0x20U) | (QData)((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_uop_inst_raw))) 
                                >> 0x20U));
    bufp->chgIData(oldp+14,((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 5U)))
                               ? 0U : (__Vtemp_29[(
                                                   ((IData)(0x1fU) 
                                                    + 
                                                    (0x1ffU 
                                                     & VL_SHIFTL_III(9,9,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 5U))) 
                                                   >> 5U)] 
                                       << ((IData)(0x20U) 
                                           - (0x1fU 
                                              & VL_SHIFTL_III(9,9,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 5U))))) 
                             | (__Vtemp_29[(0xfU & 
                                            (VL_SHIFTL_III(9,9,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 5U) 
                                             >> 5U))] 
                                >> (0x1fU & VL_SHIFTL_III(9,9,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 5U))))),32);
    bufp->chgBit(oldp+15,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_uop_pre_is_rvc) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_uop_pre_is_rvc) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_uop_pre_is_rvc) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_uop_pre_is_rvc) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_uop_pre_is_rvc) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_uop_pre_is_rvc) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_uop_pre_is_rvc) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_uop_pre_is_rvc) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_uop_pre_is_rvc) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_uop_pre_is_rvc) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_uop_pre_is_rvc) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_uop_pre_is_rvc) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_uop_pre_is_rvc) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_uop_pre_is_rvc) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_uop_pre_is_rvc) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_uop_pre_is_rvc))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    __Vtemp_30[0U] = (IData)((((QData)((IData)(((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_uop_ftqPtr) 
                                                  << 0x12U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_uop_ftqPtr) 
                                                    << 0xcU)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_uop_ftqPtr) 
                                                    << 6U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_uop_ftqPtr))))) 
                               << 0x18U) | (QData)((IData)(
                                                           ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_uop_ftqPtr) 
                                                              << 0x12U) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_uop_ftqPtr) 
                                                                << 0xcU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_uop_ftqPtr) 
                                                                << 6U) 
                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_uop_ftqPtr)))))));
    __Vtemp_30[1U] = (((IData)((((QData)((IData)(((
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_uop_ftqPtr) 
                                                    << 0x12U) 
                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_uop_ftqPtr) 
                                                      << 0xcU)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_uop_ftqPtr) 
                                                      << 6U) 
                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_uop_ftqPtr))))) 
                                 << 0x18U) | (QData)((IData)(
                                                             ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_uop_ftqPtr) 
                                                                << 0x12U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_uop_ftqPtr) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_uop_ftqPtr) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_uop_ftqPtr))))))) 
                       << 0x10U) | (IData)(((((QData)((IData)(
                                                              ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_uop_ftqPtr) 
                                                                 << 0x12U) 
                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_uop_ftqPtr) 
                                                                   << 0xcU)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_uop_ftqPtr) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_uop_ftqPtr))))) 
                                              << 0x18U) 
                                             | (QData)((IData)(
                                                               ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_uop_ftqPtr) 
                                                                  << 0x12U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_uop_ftqPtr) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_uop_ftqPtr) 
                                                                    << 6U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_uop_ftqPtr)))))) 
                                            >> 0x20U)));
    __Vtemp_30[2U] = (((IData)((((QData)((IData)(((
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_uop_ftqPtr) 
                                                    << 0x12U) 
                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_uop_ftqPtr) 
                                                      << 0xcU)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_uop_ftqPtr) 
                                                      << 6U) 
                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_uop_ftqPtr))))) 
                                 << 0x18U) | (QData)((IData)(
                                                             ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_uop_ftqPtr) 
                                                                << 0x12U) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_uop_ftqPtr) 
                                                                  << 0xcU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_uop_ftqPtr) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_uop_ftqPtr))))))) 
                       >> 0x10U) | ((IData)(((((QData)((IData)(
                                                               ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_uop_ftqPtr) 
                                                                  << 0x12U) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_uop_ftqPtr) 
                                                                    << 0xcU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_uop_ftqPtr) 
                                                                    << 6U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_uop_ftqPtr))))) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_uop_ftqPtr) 
                                                                   << 0x12U) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_uop_ftqPtr) 
                                                                     << 0xcU)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_uop_ftqPtr) 
                                                                     << 6U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_uop_ftqPtr)))))) 
                                             >> 0x20U)) 
                                    << 0x10U));
    bufp->chgCData(oldp+16,(((0x5fU >= (0x7fU & ((IData)(6U) 
                                                 * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))
                              ? (0x3fU & (((0U == (0x1fU 
                                                   & ((IData)(6U) 
                                                      * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))
                                            ? 0U : 
                                           (__Vtemp_30[
                                            (((IData)(5U) 
                                              + (0x7fU 
                                                 & ((IData)(6U) 
                                                    * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(6U) 
                                                      * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))))) 
                                          | (__Vtemp_30[
                                             (3U & 
                                              (((IData)(6U) 
                                                * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)) 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & ((IData)(6U) 
                                                    * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))))
                              : 0U)),6);
    bufp->chgBit(oldp+17,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_uop_is_predicted_taken) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_uop_is_predicted_taken) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_uop_is_predicted_taken) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_uop_is_predicted_taken) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_uop_is_predicted_taken) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_uop_is_predicted_taken) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_uop_is_predicted_taken) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_uop_is_predicted_taken) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_uop_is_predicted_taken) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_uop_is_predicted_taken) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_uop_is_predicted_taken) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_uop_is_predicted_taken) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_uop_is_predicted_taken) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_uop_is_predicted_taken) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_uop_is_predicted_taken) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_uop_is_predicted_taken))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+18,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_addi) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_addi) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_addi) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_addi) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_addi) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_addi) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_addi) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_addi) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_addi) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_addi) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_addi) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_addi) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_addi) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_addi) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_addi) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_addi))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+19,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_mul) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_mul) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_mul) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_mul) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_mul) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_mul) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_mul) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_mul) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_mul) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_mul) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_mul) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_mul) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_mul) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_mul) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_mul) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_mul))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+20,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_mulhsu) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_mulhsu) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_mulhsu) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_mulhsu) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_mulhsu) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_mulhsu) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_mulhsu) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_mulhsu) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_mulhsu) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_mulhsu) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_mulhsu) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_mulhsu) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_mulhsu) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_mulhsu) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_mulhsu) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_mulhsu))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+21,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_mulhu) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_mulhu) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_mulhu) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_mulhu) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_mulhu) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_mulhu) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_mulhu) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_mulhu) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_mulhu) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_mulhu) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_mulhu) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_mulhu) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_mulhu) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_mulhu) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_mulhu) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_mulhu))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+22,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_mulw) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_mulw) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_mulw) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_mulw) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_mulw) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_mulw) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_mulw) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_mulw) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_mulw) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_mulw) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_mulw) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_mulw) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_mulw) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_mulw) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_mulw) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_mulw))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+23,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_divuw) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_divuw) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_divuw) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_divuw) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_divuw) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_divuw) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_divuw) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_divuw) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_divuw) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_divuw) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_divuw) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_divuw) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_divuw) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_divuw) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_divuw) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_divuw))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+24,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_bge) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_bge) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_bge) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_bge) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_bge) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_bge) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_bge) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_bge) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_bge) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_bge) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_bge) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_bge) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_bge) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_bge) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_bge) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_bge))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+25,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_ori) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_ori) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_ori) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_ori) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_ori) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_ori) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_ori) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_ori) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_ori) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_ori) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_ori) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_ori) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_ori) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_ori) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_ori) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_ori))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+26,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_xori) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_xori) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_xori) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_xori) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_xori) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_xori) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_xori) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_xori) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_xori) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_xori) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_xori) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_xori) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_xori) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_xori) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_xori) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_xori))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+27,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_sh1add_uw) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_sh1add_uw) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_sh1add_uw) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_sh1add_uw) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_sh1add_uw) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_sh1add_uw) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_sh1add_uw) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_sh1add_uw) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_sh1add_uw) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_sh1add_uw) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_sh1add_uw) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_sh1add_uw) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_sh1add_uw) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_sh1add_uw) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_sh1add_uw) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_sh1add_uw))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+28,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_bseti) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_bseti) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_bseti) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_bseti) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_bseti) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_bseti) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_bseti) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_bseti) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_bseti) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_bseti) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_bseti) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_bseti) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_bseti) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_bseti) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_bseti) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_bseti))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+29,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_csr) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_csr) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_csr) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_csr) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_csr) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_csr) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_csr) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_csr) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_csr) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_csr) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_csr) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_csr) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_csr) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_csr) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_csr) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_csr))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgCData(oldp+30,(((0x2fU >= (0x3fU & ((IData)(3U) 
                                                 * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))
                              ? (7U & (IData)(((((QData)((IData)(
                                                                 (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_csr_cmd) 
                                                                     << 0x15U) 
                                                                    | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_csr_cmd) 
                                                                       << 0x12U)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_csr_cmd) 
                                                                       << 0xfU) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_csr_cmd) 
                                                                         << 0xcU))) 
                                                                  | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_csr_cmd) 
                                                                       << 9U) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_csr_cmd) 
                                                                         << 6U)) 
                                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_csr_cmd) 
                                                                         << 3U) 
                                                                        | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_csr_cmd)))))) 
                                                 << 0x18U) 
                                                | (QData)((IData)(
                                                                  (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_csr_cmd) 
                                                                      << 0x15U) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_csr_cmd) 
                                                                        << 0x12U)) 
                                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_csr_cmd) 
                                                                        << 0xfU) 
                                                                       | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_csr_cmd) 
                                                                          << 0xcU))) 
                                                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_csr_cmd) 
                                                                        << 9U) 
                                                                       | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_csr_cmd) 
                                                                          << 6U)) 
                                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_csr_cmd) 
                                                                          << 3U) 
                                                                         | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_csr_cmd))))))) 
                                               >> (0x3fU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))))
                              : 0U)),3);
    bufp->chgBit(oldp+31,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_ecall) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_ecall) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_ecall) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_ecall) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_ecall) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_ecall) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_ecall) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_ecall) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_ecall) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_ecall) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_ecall) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_ecall) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_ecall) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_ecall) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_ecall) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_ecall))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+32,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_ebreak) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_ebreak) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_ebreak) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_ebreak) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_ebreak) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_ebreak) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_ebreak) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_ebreak) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_ebreak) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_ebreak) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_ebreak) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_ebreak) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_ebreak) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_ebreak) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_ebreak) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_ebreak))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+33,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_mret) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_mret) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_mret) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_mret) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_mret) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_mret) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_mret) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_mret) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_mret) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_mret) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_mret) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_mret) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_mret) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_mret) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_mret) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_mret))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+34,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_sret) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_sret) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_sret) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_sret) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_sret) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_sret) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_sret) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_sret) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_sret) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_sret) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_sret) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_sret) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_sret) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_sret) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_sret) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_sret))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+35,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_sfence_vma) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_sfence_vma) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_sfence_vma) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_sfence_vma) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_sfence_vma) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_sfence_vma) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_sfence_vma) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_sfence_vma) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_sfence_vma) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_sfence_vma) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_sfence_vma) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_sfence_vma) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_sfence_vma) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_sfence_vma) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_sfence_vma) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_sfence_vma))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+36,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_rs2_is_vec) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_rs2_is_vec) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_rs2_is_vec) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_rs2_is_vec) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_rs2_is_vec) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_rs2_is_vec) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_rs2_is_vec) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_rs2_is_vec) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_rs2_is_vec) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_rs2_is_vec) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_rs2_is_vec) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_rs2_is_vec) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_rs2_is_vec) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_rs2_is_vec) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_rs2_is_vec) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_rs2_is_vec))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+37,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_rs3_is_vec) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_rs3_is_vec) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_rs3_is_vec) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_rs3_is_vec) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_rs3_is_vec) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_rs3_is_vec) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_rs3_is_vec) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_rs3_is_vec) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_rs3_is_vec) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_rs3_is_vec) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_rs3_is_vec) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_rs3_is_vec) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_rs3_is_vec) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_rs3_is_vec) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_rs3_is_vec) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_rs3_is_vec))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+38,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_amx) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_amx) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_amx) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_amx) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_amx) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_amx) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_amx) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_amx) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_amx) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_amx) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_amx) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_amx) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_amx) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_amx) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_amx) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_amx))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    bufp->chgBit(oldp+39,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_vset) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_vset) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_vset) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_vset) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_vset) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_vset) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_vset) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_vset) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_vset) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_vset) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_vset) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_vset) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_vset) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_vset) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_vset) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_vset))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    __Vtemp_31[0U] = (IData)((((QData)((IData)(((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_vec_vs2) 
                                                  << 0xfU) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_vec_vs2) 
                                                    << 0xaU)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_vec_vs2) 
                                                    << 5U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_vec_vs2))))) 
                               << 0x14U) | (QData)((IData)(
                                                           ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_vec_vs2) 
                                                              << 0xfU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_vec_vs2) 
                                                                << 0xaU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_vec_vs2) 
                                                                << 5U) 
                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_vec_vs2)))))));
    __Vtemp_31[1U] = (((IData)((((QData)((IData)(((
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_vec_vs2) 
                                                    << 0xfU) 
                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_vec_vs2) 
                                                      << 0xaU)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_vec_vs2) 
                                                      << 5U) 
                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_vec_vs2))))) 
                                 << 0x14U) | (QData)((IData)(
                                                             ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_vec_vs2) 
                                                                << 0xfU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_vec_vs2) 
                                                                  << 0xaU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_vec_vs2) 
                                                                  << 5U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_vec_vs2))))))) 
                       << 8U) | (IData)(((((QData)((IData)(
                                                           ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_vec_vs2) 
                                                              << 0xfU) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_vec_vs2) 
                                                                << 0xaU)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_vec_vs2) 
                                                                << 5U) 
                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_vec_vs2))))) 
                                           << 0x14U) 
                                          | (QData)((IData)(
                                                            ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_vec_vs2) 
                                                               << 0xfU) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_vec_vs2) 
                                                                 << 0xaU)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_vec_vs2) 
                                                                 << 5U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_vec_vs2)))))) 
                                         >> 0x20U)));
    __Vtemp_31[2U] = (((IData)((((QData)((IData)(((
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_vec_vs2) 
                                                    << 0xfU) 
                                                   | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_vec_vs2) 
                                                      << 0xaU)) 
                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_vec_vs2) 
                                                      << 5U) 
                                                     | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_vec_vs2))))) 
                                 << 0x14U) | (QData)((IData)(
                                                             ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_vec_vs2) 
                                                                << 0xfU) 
                                                               | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_vec_vs2) 
                                                                  << 0xaU)) 
                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_vec_vs2) 
                                                                  << 5U) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_vec_vs2))))))) 
                       >> 0x18U) | ((IData)(((((QData)((IData)(
                                                               ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_vec_vs2) 
                                                                  << 0xfU) 
                                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_vec_vs2) 
                                                                    << 0xaU)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_vec_vs2) 
                                                                    << 5U) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_vec_vs2))))) 
                                               << 0x14U) 
                                              | (QData)((IData)(
                                                                ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_vec_vs2) 
                                                                   << 0xfU) 
                                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_vec_vs2) 
                                                                     << 0xaU)) 
                                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_vec_vs2) 
                                                                     << 5U) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_vec_vs2)))))) 
                                             >> 0x20U)) 
                                    << 8U));
    bufp->chgCData(oldp+40,(((0x4fU >= (0x7fU & ((IData)(5U) 
                                                 * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))
                              ? (0x1fU & (((0U == (0x1fU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))
                                            ? 0U : 
                                           (__Vtemp_31[
                                            (((IData)(4U) 
                                              + (0x7fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))))) 
                                          | (__Vtemp_31[
                                             (3U & 
                                              (((IData)(5U) 
                                                * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)) 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))))
                              : 0U)),5);
    bufp->chgBit(oldp+41,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_vec_vm) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_vec_vm) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_vec_vm) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_vec_vm) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_vec_vm) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_vec_vm) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_vec_vm) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_vec_vm) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_vec_vm) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_vec_vm) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_vec_vm) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_vec_vm) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_vec_vm) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_vec_vm) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_vec_vm) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_vec_vm))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    __Vtemp_34[0U] = (IData)((((QData)((IData)((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_vec_zimm) 
                                                 << 0xbU) 
                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_vec_zimm)))) 
                               << 0x16U) | (QData)((IData)(
                                                           (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_vec_zimm) 
                                                             << 0xbU) 
                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_vec_zimm))))));
    __Vtemp_34[1U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_vec_zimm) 
                                                   << 0xbU) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_vec_zimm)))) 
                                 << 0x16U) | (QData)((IData)(
                                                             (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_vec_zimm) 
                                                               << 0xbU) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_vec_zimm)))))) 
                       << 0xcU) | (IData)(((((QData)((IData)(
                                                             (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_vec_zimm) 
                                                               << 0xbU) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_vec_zimm)))) 
                                             << 0x16U) 
                                            | (QData)((IData)(
                                                              (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_vec_zimm) 
                                                                << 0xbU) 
                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_vec_zimm))))) 
                                           >> 0x20U)));
    __Vtemp_34[2U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_vec_zimm) 
                                                   << 0xbU) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_vec_zimm)))) 
                                 << 0x16U) | (QData)((IData)(
                                                             (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_vec_zimm) 
                                                               << 0xbU) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_vec_zimm)))))) 
                       << 0x18U) | (((IData)((((QData)((IData)(
                                                               (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_vec_zimm) 
                                                                 << 0xbU) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_vec_zimm)))) 
                                               << 0x16U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_vec_zimm) 
                                                                  << 0xbU) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_vec_zimm)))))) 
                                     >> 0x14U) | ((IData)(
                                                          ((((QData)((IData)(
                                                                             (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_vec_zimm) 
                                                                               << 0xbU) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_vec_zimm)))) 
                                                             << 0x16U) 
                                                            | (QData)((IData)(
                                                                              (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_vec_zimm) 
                                                                                << 0xbU) 
                                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_vec_zimm))))) 
                                                           >> 0x20U)) 
                                                  << 0xcU)));
    __Vtemp_34[3U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_vec_zimm) 
                                                   << 0xbU) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_vec_zimm)))) 
                                 << 0x16U) | (QData)((IData)(
                                                             (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_vec_zimm) 
                                                               << 0xbU) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_vec_zimm)))))) 
                       >> 8U) | ((IData)(((((QData)((IData)(
                                                            (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_vec_zimm) 
                                                              << 0xbU) 
                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_vec_zimm)))) 
                                            << 0x16U) 
                                           | (QData)((IData)(
                                                             (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_vec_zimm) 
                                                               << 0xbU) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_vec_zimm))))) 
                                          >> 0x20U)) 
                                 << 0x18U));
    __Vtemp_34[4U] = (((0xfffff0U & ((IData)((((QData)((IData)(
                                                               (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_vec_zimm) 
                                                                 << 0xbU) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_vec_zimm)))) 
                                               << 0x16U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_vec_zimm) 
                                                                  << 0xbU) 
                                                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_vec_zimm)))))) 
                                     << 4U)) | ((IData)(
                                                        ((((QData)((IData)(
                                                                           (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_vec_zimm) 
                                                                             << 0xbU) 
                                                                            | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_vec_zimm)))) 
                                                           << 0x16U) 
                                                          | (QData)((IData)(
                                                                            (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_vec_zimm) 
                                                                              << 0xbU) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_vec_zimm))))) 
                                                         >> 0x20U)) 
                                                >> 8U)) 
                      | (0xff000000U & ((IData)((((QData)((IData)(
                                                                  (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_vec_zimm) 
                                                                    << 0xbU) 
                                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_vec_zimm)))) 
                                                  << 0x16U) 
                                                 | (QData)((IData)(
                                                                   (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_vec_zimm) 
                                                                     << 0xbU) 
                                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_vec_zimm)))))) 
                                        << 4U)));
    __Vtemp_34[5U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_vec_zimm) 
                                                   << 0xbU) 
                                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_vec_zimm)))) 
                                 << 0x16U) | (QData)((IData)(
                                                             (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_vec_zimm) 
                                                               << 0xbU) 
                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_vec_zimm)))))) 
                       >> 0x1cU) | (0xfffff0U & ((IData)(
                                                         ((((QData)((IData)(
                                                                            (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_vec_zimm) 
                                                                              << 0xbU) 
                                                                             | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_vec_zimm)))) 
                                                            << 0x16U) 
                                                           | (QData)((IData)(
                                                                             (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_vec_zimm) 
                                                                               << 0xbU) 
                                                                              | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_vec_zimm))))) 
                                                          >> 0x20U)) 
                                                 << 4U)));
    bufp->chgSData(oldp+42,(((0xafU >= (0xffU & ((IData)(0xbU) 
                                                 * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))
                              ? (0x7ffU & (((0U == 
                                             (0x1fU 
                                              & ((IData)(0xbU) 
                                                 * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))
                                             ? 0U : 
                                            (__Vtemp_34[
                                             (((IData)(0xaU) 
                                               + (0xffU 
                                                  & ((IData)(0xbU) 
                                                     * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(0xbU) 
                                                     * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))))) 
                                           | (__Vtemp_34[
                                              (7U & 
                                               (((IData)(0xbU) 
                                                 * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)) 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & ((IData)(0xbU) 
                                                     * (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr))))))
                              : 0U)),11);
    bufp->chgBit(oldp+43,((1U & (((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_decode_is_vec_mem) 
                                      << 0xfU) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_decode_is_vec_mem) 
                                                  << 0xeU)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_decode_is_vec_mem) 
                                        << 0xdU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_decode_is_vec_mem) 
                                        << 0xcU))) 
                                   | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_decode_is_vec_mem) 
                                        << 0xbU) | 
                                       ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_decode_is_vec_mem) 
                                        << 0xaU)) | 
                                      (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_decode_is_vec_mem) 
                                        << 9U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_decode_is_vec_mem) 
                                                  << 8U)))) 
                                  | (((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_decode_is_vec_mem) 
                                        << 7U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_decode_is_vec_mem) 
                                                  << 6U)) 
                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_decode_is_vec_mem) 
                                          << 5U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_decode_is_vec_mem) 
                                          << 4U))) 
                                     | ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_decode_is_vec_mem) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_decode_is_vec_mem) 
                                          << 2U)) | 
                                        (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_decode_is_vec_mem) 
                                          << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_decode_is_vec_mem))))) 
                                 >> (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr)))));
    __Vtemp_36[0U] = ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_psrs3) 
                        << 0x18U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_psrs3) 
                                     << 0x10U)) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_psrs3) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_psrs3)));
    __Vtemp_36[1U] = ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_psrs3) 
                        << 0x18U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_psrs3) 
                                     << 0x10U)) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_psrs3) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_psrs3)));
    __Vtemp_36[2U] = (IData)((((QData)((IData)(((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_psrs3) 
                                                  << 0x18U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_psrs3) 
                                                    << 0x10U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_psrs3) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_psrs3))))) 
                               << 0x20U) | (QData)((IData)(
                                                           ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_psrs3) 
                                                              << 0x18U) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_psrs3) 
                                                                << 0x10U)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_psrs3) 
                                                                << 8U) 
                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_psrs3)))))));
    __Vtemp_36[3U] = (IData)(((((QData)((IData)(((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_psrs3) 
                                                   << 0x18U) 
                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_psrs3) 
                                                     << 0x10U)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_psrs3) 
                                                     << 8U) 
                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_psrs3))))) 
                                << 0x20U) | (QData)((IData)(
                                                            ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_psrs3) 
                                                               << 0x18U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_psrs3) 
                                                                 << 0x10U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_psrs3) 
                                                                 << 8U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_psrs3)))))) 
                              >> 0x20U));
    bufp->chgCData(oldp+44,((0xffU & (((0U == (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U)))
                                        ? 0U : (__Vtemp_36[
                                                (((IData)(7U) 
                                                  + 
                                                  (0x7fU 
                                                   & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U))) 
                                                 >> 5U)] 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U))))) 
                                      | (__Vtemp_36[
                                         (3U & (VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U) 
                                                >> 5U))] 
                                         >> (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U)))))),8);
    __Vtemp_38[0U] = ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_pdest) 
                        << 0x18U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_pdest) 
                                     << 0x10U)) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_pdest) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_pdest)));
    __Vtemp_38[1U] = ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_pdest) 
                        << 0x18U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_pdest) 
                                     << 0x10U)) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_pdest) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_pdest)));
    __Vtemp_38[2U] = (IData)((((QData)((IData)(((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_pdest) 
                                                  << 0x18U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_pdest) 
                                                    << 0x10U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_pdest) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_pdest))))) 
                               << 0x20U) | (QData)((IData)(
                                                           ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_pdest) 
                                                              << 0x18U) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_pdest) 
                                                                << 0x10U)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_pdest) 
                                                                << 8U) 
                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_pdest)))))));
    __Vtemp_38[3U] = (IData)(((((QData)((IData)(((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_pdest) 
                                                   << 0x18U) 
                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_pdest) 
                                                     << 0x10U)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_pdest) 
                                                     << 8U) 
                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_pdest))))) 
                                << 0x20U) | (QData)((IData)(
                                                            ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_pdest) 
                                                               << 0x18U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_pdest) 
                                                                 << 0x10U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_pdest) 
                                                                 << 8U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_pdest)))))) 
                              >> 0x20U));
    bufp->chgCData(oldp+45,((0xffU & (((0U == (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U)))
                                        ? 0U : (__Vtemp_38[
                                                (((IData)(7U) 
                                                  + 
                                                  (0x7fU 
                                                   & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U))) 
                                                 >> 5U)] 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U))))) 
                                      | (__Vtemp_38[
                                         (3U & (VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U) 
                                                >> 5U))] 
                                         >> (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U)))))),8);
    __Vtemp_40[0U] = ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_3_uop_snapshotIdx) 
                        << 0x18U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_2_uop_snapshotIdx) 
                                     << 0x10U)) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_1_uop_snapshotIdx) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_0_uop_snapshotIdx)));
    __Vtemp_40[1U] = ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_7_uop_snapshotIdx) 
                        << 0x18U) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_6_uop_snapshotIdx) 
                                     << 0x10U)) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_5_uop_snapshotIdx) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_4_uop_snapshotIdx)));
    __Vtemp_40[2U] = (IData)((((QData)((IData)(((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_snapshotIdx) 
                                                  << 0x18U) 
                                                 | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_snapshotIdx) 
                                                    << 0x10U)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_snapshotIdx) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_snapshotIdx))))) 
                               << 0x20U) | (QData)((IData)(
                                                           ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_snapshotIdx) 
                                                              << 0x18U) 
                                                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_snapshotIdx) 
                                                                << 0x10U)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_snapshotIdx) 
                                                                << 8U) 
                                                               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_snapshotIdx)))))));
    __Vtemp_40[3U] = (IData)(((((QData)((IData)(((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_15_uop_snapshotIdx) 
                                                   << 0x18U) 
                                                  | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_14_uop_snapshotIdx) 
                                                     << 0x10U)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_13_uop_snapshotIdx) 
                                                     << 8U) 
                                                    | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_12_uop_snapshotIdx))))) 
                                << 0x20U) | (QData)((IData)(
                                                            ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_11_uop_snapshotIdx) 
                                                               << 0x18U) 
                                                              | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_10_uop_snapshotIdx) 
                                                                 << 0x10U)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_9_uop_snapshotIdx) 
                                                                 << 8U) 
                                                                | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__entries_8_uop_snapshotIdx)))))) 
                              >> 0x20U));
    bufp->chgCData(oldp+46,((0xffU & (((0U == (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U)))
                                        ? 0U : (__Vtemp_40[
                                                (((IData)(7U) 
                                                  + 
                                                  (0x7fU 
                                                   & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U))) 
                                                 >> 5U)] 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U))))) 
                                      | (__Vtemp_40[
                                         (3U & (VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U) 
                                                >> 5U))] 
                                         >> (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecDispatchQueue__DOT__headPtr), 3U)))))),8);
    bufp->chgBit(oldp+47,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_uop_pre_is_rvc)) 
                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404) 
                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_uop_pre_is_rvc)) 
                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408) 
                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_uop_pre_is_rvc)) 
                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412) 
                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_uop_pre_is_rvc)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416) 
                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_uop_pre_is_rvc)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420) 
                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_uop_pre_is_rvc)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424) 
                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_uop_pre_is_rvc)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428) 
                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_uop_pre_is_rvc)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432) 
                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_uop_pre_is_rvc)) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436) 
                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_uop_pre_is_rvc)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440) 
                                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_uop_pre_is_rvc)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444) 
                                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_uop_pre_is_rvc)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448) 
                                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_uop_pre_is_rvc)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452) 
                                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_uop_pre_is_rvc)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456) 
                                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_uop_pre_is_rvc)) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460) 
                                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_uop_pre_is_rvc)))))))))))))))))));
    bufp->chgBit(oldp+48,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_mulhsu)) 
                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404) 
                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_mulhsu)) 
                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408) 
                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_mulhsu)) 
                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412) 
                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_mulhsu)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416) 
                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_mulhsu)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420) 
                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_mulhsu)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424) 
                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_mulhsu)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428) 
                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_mulhsu)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432) 
                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_mulhsu)) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436) 
                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_mulhsu)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440) 
                                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_mulhsu)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444) 
                                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_mulhsu)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448) 
                                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_mulhsu)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452) 
                                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_mulhsu)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456) 
                                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_mulhsu)) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460) 
                                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_mulhsu)))))))))))))))))));
    bufp->chgBit(oldp+49,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_mulhu)) 
                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404) 
                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_mulhu)) 
                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408) 
                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_mulhu)) 
                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412) 
                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_mulhu)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416) 
                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_mulhu)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420) 
                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_mulhu)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424) 
                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_mulhu)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428) 
                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_mulhu)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432) 
                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_mulhu)) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436) 
                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_mulhu)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440) 
                                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_mulhu)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444) 
                                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_mulhu)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448) 
                                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_mulhu)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452) 
                                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_mulhu)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456) 
                                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_mulhu)) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460) 
                                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_mulhu)))))))))))))))))));
    bufp->chgBit(oldp+50,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_mulw)) 
                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404) 
                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_mulw)) 
                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408) 
                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_mulw)) 
                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412) 
                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_mulw)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416) 
                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_mulw)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420) 
                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_mulw)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424) 
                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_mulw)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428) 
                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_mulw)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432) 
                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_mulw)) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436) 
                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_mulw)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440) 
                                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_mulw)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444) 
                                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_mulw)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448) 
                                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_mulw)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452) 
                                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_mulw)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456) 
                                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_mulw)) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460) 
                                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_mulw)))))))))))))))))));
    bufp->chgBit(oldp+51,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_div)) 
                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404) 
                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_div)) 
                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408) 
                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_div)) 
                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412) 
                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_div)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416) 
                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_div)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420) 
                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_div)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424) 
                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_div)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428) 
                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_div)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432) 
                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_div)) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436) 
                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_div)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440) 
                                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_div)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444) 
                                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_div)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448) 
                                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_div)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452) 
                                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_div)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456) 
                                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_div)) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460) 
                                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_div)))))))))))))))))));
    bufp->chgBit(oldp+52,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_maxu)) 
                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404) 
                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_maxu)) 
                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408) 
                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_maxu)) 
                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412) 
                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_maxu)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416) 
                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_maxu)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420) 
                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_maxu)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424) 
                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_maxu)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428) 
                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_maxu)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432) 
                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_maxu)) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436) 
                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_maxu)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440) 
                                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_maxu)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444) 
                                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_maxu)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448) 
                                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_maxu)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452) 
                                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_maxu)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456) 
                                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_maxu)) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460) 
                                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_maxu)))))))))))))))))));
    bufp->chgCData(oldp+53,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_fused_type)
                               : 0U) | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404)
                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_fused_type)
                                          : 0U) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408)
                                                     ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_fused_type)
                                                     : 0U) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412)
                                                        ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_fused_type)
                                                        : 0U) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416)
                                                           ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_fused_type)
                                                           : 0U) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420)
                                                              ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_fused_type)
                                                              : 0U) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424)
                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_fused_type)
                                                                 : 0U) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428)
                                                                    ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_fused_type)
                                                                    : 0U) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432)
                                                                       ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_fused_type)
                                                                       : 0U) 
                                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436)
                                                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_fused_type)
                                                                          : 0U) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440)
                                                                             ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_fused_type)
                                                                             : 0U) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444)
                                                                                ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_fused_type)
                                                                                : 0U) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_fused_type)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_fused_type)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_fused_type)
                                                                                 : 0U) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_fused_type)
                                                                                 : 0U))))))))))))))))),5);
    bufp->chgBit(oldp+54,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_rs2_is_vec)) 
                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404) 
                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_rs2_is_vec)) 
                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408) 
                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_rs2_is_vec)) 
                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412) 
                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_rs2_is_vec)) 
                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416) 
                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_rs2_is_vec)) 
                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420) 
                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_rs2_is_vec)) 
                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424) 
                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_rs2_is_vec)) 
                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428) 
                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_rs2_is_vec)) 
                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432) 
                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_rs2_is_vec)) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436) 
                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_rs2_is_vec)) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440) 
                                                          & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_rs2_is_vec)) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444) 
                                                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_rs2_is_vec)) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448) 
                                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_rs2_is_vec)) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452) 
                                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_rs2_is_vec)) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456) 
                                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_rs2_is_vec)) 
                                                                     | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460) 
                                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_rs2_is_vec)))))))))))))))))));
    bufp->chgCData(oldp+55,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_vec_simm5)
                               : 0U) | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404)
                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_vec_simm5)
                                          : 0U) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408)
                                                     ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_vec_simm5)
                                                     : 0U) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412)
                                                        ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_vec_simm5)
                                                        : 0U) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416)
                                                           ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_vec_simm5)
                                                           : 0U) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420)
                                                              ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_vec_simm5)
                                                              : 0U) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424)
                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_vec_simm5)
                                                                 : 0U) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428)
                                                                    ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_vec_simm5)
                                                                    : 0U) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432)
                                                                       ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_vec_simm5)
                                                                       : 0U) 
                                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436)
                                                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_vec_simm5)
                                                                          : 0U) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440)
                                                                             ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_vec_simm5)
                                                                             : 0U) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444)
                                                                                ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_vec_simm5)
                                                                                : 0U) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_vec_simm5)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_vec_simm5)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_vec_simm5)
                                                                                 : 0U) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_vec_simm5)
                                                                                 : 0U))))))))))))))))),5);
    bufp->chgCData(oldp+56,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_pdest)
                               : 0U) | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404)
                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_pdest)
                                          : 0U) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408)
                                                     ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_pdest)
                                                     : 0U) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412)
                                                        ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_pdest)
                                                        : 0U) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416)
                                                           ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_pdest)
                                                           : 0U) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420)
                                                              ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_pdest)
                                                              : 0U) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424)
                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_pdest)
                                                                 : 0U) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428)
                                                                    ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_pdest)
                                                                    : 0U) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432)
                                                                       ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_pdest)
                                                                       : 0U) 
                                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436)
                                                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_pdest)
                                                                          : 0U) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440)
                                                                             ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_pdest)
                                                                             : 0U) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444)
                                                                                ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_pdest)
                                                                                : 0U) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_pdest)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_pdest)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_pdest)
                                                                                 : 0U) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_pdest)
                                                                                 : 0U))))))))))))))))),8);
    bufp->chgCData(oldp+57,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_snapshotIdx)
                               : 0U) | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404)
                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_snapshotIdx)
                                          : 0U) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408)
                                                     ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_snapshotIdx)
                                                     : 0U) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412)
                                                        ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_snapshotIdx)
                                                        : 0U) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416)
                                                           ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_snapshotIdx)
                                                           : 0U) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420)
                                                              ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_snapshotIdx)
                                                              : 0U) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424)
                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_snapshotIdx)
                                                                 : 0U) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428)
                                                                    ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_snapshotIdx)
                                                                    : 0U) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432)
                                                                       ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_snapshotIdx)
                                                                       : 0U) 
                                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436)
                                                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_snapshotIdx)
                                                                          : 0U) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440)
                                                                             ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_snapshotIdx)
                                                                             : 0U) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444)
                                                                                ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_snapshotIdx)
                                                                                : 0U) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_snapshotIdx)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_snapshotIdx)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_snapshotIdx)
                                                                                 : 0U) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_snapshotIdx)
                                                                                 : 0U))))))))))))))))),8);
    bufp->chgCData(oldp+58,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_robIdx)
                               : 0U) | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404)
                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_robIdx)
                                          : 0U) | (
                                                   ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408)
                                                     ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_robIdx)
                                                     : 0U) 
                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412)
                                                        ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_robIdx)
                                                        : 0U) 
                                                      | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416)
                                                           ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_robIdx)
                                                           : 0U) 
                                                         | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420)
                                                              ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_robIdx)
                                                              : 0U) 
                                                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424)
                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_robIdx)
                                                                 : 0U) 
                                                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428)
                                                                    ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_robIdx)
                                                                    : 0U) 
                                                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432)
                                                                       ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_robIdx)
                                                                       : 0U) 
                                                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436)
                                                                          ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_robIdx)
                                                                          : 0U) 
                                                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440)
                                                                             ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_robIdx)
                                                                             : 0U) 
                                                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444)
                                                                                ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_robIdx)
                                                                                : 0U) 
                                                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_robIdx)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_robIdx)
                                                                                 : 0U) 
                                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_robIdx)
                                                                                 : 0U) 
                                                                                | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460)
                                                                                 ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_robIdx)
                                                                                 : 0U))))))))))))))))),7);
    bufp->chgBit(oldp+59,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1299)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_6_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_6_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_6_pdest)))))));
    bufp->chgBit(oldp+60,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1300)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_7_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_7_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_7_pdest)))))));
    bufp->chgBit(oldp+61,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1314)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_21_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_21_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_21_pdest)))))));
    bufp->chgBit(oldp+62,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1315)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_22_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_22_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_22_pdest)))))));
    bufp->chgBit(oldp+63,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1316)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_23_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_23_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_23_pdest)))))));
    bufp->chgBit(oldp+64,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1317)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_24_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_24_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_24_pdest)))))));
    bufp->chgBit(oldp+65,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1318)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_25_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_25_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_25_pdest)))))));
    bufp->chgBit(oldp+66,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1320)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_27_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_27_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_27_pdest)))))));
    bufp->chgBit(oldp+67,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1321)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_28_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_28_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_28_pdest)))))));
    bufp->chgBit(oldp+68,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1322)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_29_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_29_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_29_pdest)))))));
    bufp->chgBit(oldp+69,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1323)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_30_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_30_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_30_pdest)))))));
    bufp->chgBit(oldp+70,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1325)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_32_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_32_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_32_pdest)))))));
    bufp->chgBit(oldp+71,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1326)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_33_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_33_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_33_pdest)))))));
    bufp->chgBit(oldp+72,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1327)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_34_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_34_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_34_pdest)))))));
    bufp->chgBit(oldp+73,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1332)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_39_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_39_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_39_pdest)))))));
    bufp->chgBit(oldp+74,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1338)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_45_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_45_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_45_pdest)))))));
    bufp->chgBit(oldp+75,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1339)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_46_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_46_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_46_pdest)))))));
    bufp->chgBit(oldp+76,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1341)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_48_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_48_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_48_pdest)))))));
    bufp->chgBit(oldp+77,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1343)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_50_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_50_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_50_pdest)))))));
    bufp->chgBit(oldp+78,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1344)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_51_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_51_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_51_pdest)))))));
    bufp->chgBit(oldp+79,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1345)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_52_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_52_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_52_pdest)))))));
    bufp->chgBit(oldp+80,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1347)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_54_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_54_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_54_pdest)))))));
    bufp->chgBit(oldp+81,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1348)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_55_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_55_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_55_pdest)))))));
    bufp->chgBit(oldp+82,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1349)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_56_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_56_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_56_pdest)))))));
    bufp->chgBit(oldp+83,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1351)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_58_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_58_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_58_pdest)))))));
    bufp->chgBit(oldp+84,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1354)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_61_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_61_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_61_pdest)))))));
    bufp->chgBit(oldp+85,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1356)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_63_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_63_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_63_pdest)))))));
    bufp->chgBit(oldp+86,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1357)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_64_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_64_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_64_pdest)))))));
    bufp->chgBit(oldp+87,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1358)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_65_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_65_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_65_pdest)))))));
    bufp->chgBit(oldp+88,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1360)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_67_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_67_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_67_pdest)))))));
    bufp->chgBit(oldp+89,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1362)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_69_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_69_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_69_pdest)))))));
    bufp->chgBit(oldp+90,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1363)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_70_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_70_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_70_pdest)))))));
    bufp->chgBit(oldp+91,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1364)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_71_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_71_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_71_pdest)))))));
    bufp->chgBit(oldp+92,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1368)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_75_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_75_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_75_pdest)))))));
    bufp->chgBit(oldp+93,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1369)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_76_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_76_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_76_pdest)))))));
    bufp->chgBit(oldp+94,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1371)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_78_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_78_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_78_pdest)))))));
    bufp->chgBit(oldp+95,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1372)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_79_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_79_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_79_pdest)))))));
    bufp->chgBit(oldp+96,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1373)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_80_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_80_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_80_pdest)))))));
    bufp->chgBit(oldp+97,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1374)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_81_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_81_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_81_pdest)))))));
    bufp->chgBit(oldp+98,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1375)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_82_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_82_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_82_pdest)))))));
    bufp->chgBit(oldp+99,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                            | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                  | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1379)))) 
                           & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_86_valid) 
                              & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_86_rfWen) 
                                 & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_86_pdest)))))));
    bufp->chgBit(oldp+100,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1380)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_87_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_87_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_87_pdest)))))));
    bufp->chgBit(oldp+101,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1381)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_88_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_88_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_88_pdest)))))));
    bufp->chgBit(oldp+102,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1382)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_89_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_89_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_89_pdest)))))));
    bufp->chgBit(oldp+103,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1383)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_90_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_90_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_90_pdest)))))));
    bufp->chgBit(oldp+104,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1384)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_91_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_91_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_91_pdest)))))));
    bufp->chgBit(oldp+105,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1385)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_92_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_92_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_92_pdest)))))));
    bufp->chgBit(oldp+106,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1390)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_97_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_97_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_97_pdest)))))));
    bufp->chgBit(oldp+107,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1391)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_98_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_98_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_98_pdest)))))));
    bufp->chgBit(oldp+108,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1407)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_114_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_114_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_114_pdest)))))));
    bufp->chgBit(oldp+109,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1408)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_115_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_115_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_115_pdest)))))));
    bufp->chgBit(oldp+110,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1409)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_116_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_116_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_116_pdest)))))));
    bufp->chgBit(oldp+111,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1410)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_117_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_117_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_117_pdest)))))));
    bufp->chgBit(oldp+112,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1413)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_120_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_120_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_120_pdest)))))));
    bufp->chgBit(oldp+113,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1414)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_121_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_121_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_121_pdest)))))));
    bufp->chgBit(oldp+114,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1415)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_122_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_122_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_122_pdest)))))));
    bufp->chgBit(oldp+115,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__headHasException) 
                             | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid) 
                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_is_exception) 
                                   | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT____VdfgRegularize_h9d2b670c_0_1417)))) 
                            & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_124_valid) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_124_rfWen) 
                                  & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__robEntries_124_pdest)))))));
    bufp->chgCData(oldp+116,((0xffU & (((0U == (0x1fU 
                                                & VL_SHIFTL_III(11,11,32, 
                                                                (0xffU 
                                                                 & ((0x9fU 
                                                                     < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                                     ? 
                                                                    ((IData)(0x60U) 
                                                                     + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                                     : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))), 3U)))
                                         ? 0U : (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT___GEN_5[
                                                 (((IData)(7U) 
                                                   + 
                                                   (0x7ffU 
                                                    & VL_SHIFTL_III(11,11,32, 
                                                                    (0xffU 
                                                                     & ((0x9fU 
                                                                         < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                                         ? 
                                                                        ((IData)(0x60U) 
                                                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                                         : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))), 3U))) 
                                                  >> 5U)] 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(11,11,32, 
                                                                   (0xffU 
                                                                    & ((0x9fU 
                                                                        < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                                        ? 
                                                                       ((IData)(0x60U) 
                                                                        + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                                        : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))), 3U))))) 
                                       | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT___GEN_5[
                                          (0x3fU & 
                                           (VL_SHIFTL_III(11,11,32, 
                                                          (0xffU 
                                                           & ((0x9fU 
                                                               < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                               ? 
                                                              ((IData)(0x60U) 
                                                               + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))), 3U) 
                                            >> 5U))] 
                                          >> (0x1fU 
                                              & VL_SHIFTL_III(11,11,32, 
                                                              (0xffU 
                                                               & ((0x9fU 
                                                                   < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                                   ? 
                                                                  ((IData)(0x60U) 
                                                                   + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))
                                                                   : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr))), 3U)))))),8);
    bufp->chgBit(oldp+117,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fmadd)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fmadd)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fmadd)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fmadd)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fmadd)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fmadd)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fmadd)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fmadd)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fmadd)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fmadd)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fmadd)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fmadd)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fmadd)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fmadd)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fmadd)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fmadd)))))))))))))))))));
    bufp->chgBit(oldp+118,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_400) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fnmsub)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_404) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fnmsub)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_408) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fnmsub)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_412) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fnmsub)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_416) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fnmsub)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_420) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fnmsub)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_424) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fnmsub)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_428) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fnmsub)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_432) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fnmsub)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_436) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fnmsub)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_440) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fnmsub)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_444) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fnmsub)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_448) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fnmsub)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_452) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fnmsub)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_456) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fnmsub)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_460) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fnmsub)))))))))))))))))));
    bufp->chgBit(oldp+119,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_401) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fmadd)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_405) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fmadd)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_409) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fmadd)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_413) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fmadd)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_417) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fmadd)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_421) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fmadd)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_425) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fmadd)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_429) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fmadd)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_433) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fmadd)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_437) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fmadd)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_441) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fmadd)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_445) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fmadd)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_449) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fmadd)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_453) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fmadd)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_457) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fmadd)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_461) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fmadd)))))))))))))))))));
    bufp->chgBit(oldp+120,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_401) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fnmsub)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_405) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fnmsub)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_409) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fnmsub)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_413) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fnmsub)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_417) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fnmsub)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_421) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fnmsub)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_425) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fnmsub)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_429) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fnmsub)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_433) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fnmsub)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_437) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fnmsub)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_441) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fnmsub)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_445) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fnmsub)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_449) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fnmsub)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_453) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fnmsub)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_457) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fnmsub)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_461) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fnmsub)))))))))))))))))));
    bufp->chgBit(oldp+121,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_402) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fmadd)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_406) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fmadd)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_410) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fmadd)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_414) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fmadd)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_418) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fmadd)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_422) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fmadd)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_426) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fmadd)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_430) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fmadd)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_434) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fmadd)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_438) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fmadd)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_442) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fmadd)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_446) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fmadd)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_450) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fmadd)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_454) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fmadd)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_458) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fmadd)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_462) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fmadd)))))))))))))))))));
    bufp->chgBit(oldp+122,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_402) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fnmsub)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_406) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fnmsub)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_410) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fnmsub)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_414) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fnmsub)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_418) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fnmsub)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_422) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fnmsub)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_426) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fnmsub)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_430) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fnmsub)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_434) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fnmsub)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_438) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fnmsub)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_442) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fnmsub)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_446) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fnmsub)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_450) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fnmsub)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_454) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fnmsub)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_458) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fnmsub)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_462) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fnmsub)))))))))))))))))));
    bufp->chgBit(oldp+123,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_402) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fcvt_f2i)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_406) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fcvt_f2i)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_410) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fcvt_f2i)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_414) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fcvt_f2i)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_418) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fcvt_f2i)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_422) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fcvt_f2i)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_426) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fcvt_f2i)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_430) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fcvt_f2i)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_434) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fcvt_f2i)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_438) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fcvt_f2i)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_442) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fcvt_f2i)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_446) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fcvt_f2i)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_450) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fcvt_f2i)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_454) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fcvt_f2i)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_458) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fcvt_f2i)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_462) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fcvt_f2i)))))))))))))))))));
    bufp->chgBit(oldp+124,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_403) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fmadd)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_407) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fmadd)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_411) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fmadd)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_415) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fmadd)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_419) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fmadd)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_423) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fmadd)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_427) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fmadd)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_431) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fmadd)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_435) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fmadd)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_439) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fmadd)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_443) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fmadd)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_447) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fmadd)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_451) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fmadd)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_455) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fmadd)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_459) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fmadd)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_463) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fmadd)))))))))))))))))));
    bufp->chgBit(oldp+125,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_403) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fnmsub)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_407) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fnmsub)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_411) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fnmsub)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_415) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fnmsub)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_419) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fnmsub)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_423) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fnmsub)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_427) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fnmsub)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_431) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fnmsub)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_435) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fnmsub)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_439) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fnmsub)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_443) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fnmsub)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_447) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fnmsub)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_451) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fnmsub)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_455) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fnmsub)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_459) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fnmsub)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_463) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fnmsub)))))))))))))))))));
    bufp->chgBit(oldp+126,((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_403) 
                             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_0_uop_decode_is_fcvt_f2i)) 
                            | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_407) 
                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_1_uop_decode_is_fcvt_f2i)) 
                               | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_411) 
                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_2_uop_decode_is_fcvt_f2i)) 
                                  | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_415) 
                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_3_uop_decode_is_fcvt_f2i)) 
                                     | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_419) 
                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_4_uop_decode_is_fcvt_f2i)) 
                                        | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_423) 
                                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_5_uop_decode_is_fcvt_f2i)) 
                                           | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_427) 
                                               & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_6_uop_decode_is_fcvt_f2i)) 
                                              | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_431) 
                                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_7_uop_decode_is_fcvt_f2i)) 
                                                 | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_435) 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_8_uop_decode_is_fcvt_f2i)) 
                                                    | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_439) 
                                                        & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_9_uop_decode_is_fcvt_f2i)) 
                                                       | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_443) 
                                                           & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_10_uop_decode_is_fcvt_f2i)) 
                                                          | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_447) 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_11_uop_decode_is_fcvt_f2i)) 
                                                             | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_451) 
                                                                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_12_uop_decode_is_fcvt_f2i)) 
                                                                | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_455) 
                                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_13_uop_decode_is_fcvt_f2i)) 
                                                                   | (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_459) 
                                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_14_uop_decode_is_fcvt_f2i)) 
                                                                      | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT____VdfgRegularize_hb3f26619_0_463) 
                                                                         & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_15_uop_decode_is_fcvt_f2i)))))))))))))))))));
    bufp->chgCData(oldp+127,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT___io_snapshots_18_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT____Vcellinp__snapshots__io_enqData_6)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT__snapshots_18_6))),8);
    bufp->chgCData(oldp+128,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT___io_snapshots_18_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT____Vcellinp__snapshots__io_enqData_7)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT__snapshots_18_7))),8);
    bufp->chgCData(oldp+129,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT___io_snapshots_18_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT____Vcellinp__snapshots__io_enqData_8)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT__snapshots_18_8))),8);
    bufp->chgCData(oldp+130,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT___io_snapshots_18_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT____Vcellinp__snapshots__io_enqData_9)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT__snapshots_18_9))),8);
    bufp->chgCData(oldp+131,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT___io_snapshots_19_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT____Vcellinp__snapshots__io_enqData_6)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT__snapshots_19_6))),8);
    bufp->chgCData(oldp+132,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT___io_snapshots_19_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT____Vcellinp__snapshots__io_enqData_7)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__fpRat__DOT__snapshots__DOT__snapshots_19_7))),8);
    bufp->chgBit(oldp+133,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT____Vcellinp__rat__io_commitPorts_3_wen) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT___rob_io_commits_info_3_rfWen))));
    bufp->chgCData(oldp+134,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT___io_snapshots_132_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT____Vcellinp__snapshots__io_enqData_31)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT__snapshots_132_31))),8);
    bufp->chgCData(oldp+135,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT___io_snapshots_133_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT____Vcellinp__snapshots__io_enqData_31)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT__snapshots_133_31))),8);
    bufp->chgCData(oldp+136,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT___io_snapshots_192_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT____Vcellinp__snapshots__io_enqData_31)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT__snapshots_192_31))),8);
    bufp->chgCData(oldp+137,(((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT___io_snapshots_204_T_1)
                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT____Vcellinp__snapshots__io_enqData_31)
                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT__snapshots_204_31))),8);
    bufp->chgCData(oldp+138,((0xffU & (((0U == (0x1fU 
                                                & VL_SHIFTL_III(10,10,32, 
                                                                (0x7fU 
                                                                 & ((0x5fU 
                                                                     < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                                     ? 
                                                                    ((IData)(0x20U) 
                                                                     + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                                     : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))), 3U)))
                                         ? 0U : (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT___GEN_5[
                                                 (((IData)(7U) 
                                                   + 
                                                   (0x3ffU 
                                                    & VL_SHIFTL_III(10,10,32, 
                                                                    (0x7fU 
                                                                     & ((0x5fU 
                                                                         < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                                         ? 
                                                                        ((IData)(0x20U) 
                                                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                                         : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))), 3U))) 
                                                  >> 5U)] 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(10,10,32, 
                                                                   (0x7fU 
                                                                    & ((0x5fU 
                                                                        < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                                        ? 
                                                                       ((IData)(0x20U) 
                                                                        + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                                        : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))), 3U))))) 
                                       | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT___GEN_5[
                                          (0x1fU & 
                                           (VL_SHIFTL_III(10,10,32, 
                                                          (0x7fU 
                                                           & ((0x5fU 
                                                               < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                               ? 
                                                              ((IData)(0x20U) 
                                                               + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                               : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))), 3U) 
                                            >> 5U))] 
                                          >> (0x1fU 
                                              & VL_SHIFTL_III(10,10,32, 
                                                              (0x7fU 
                                                               & ((0x5fU 
                                                                   < (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                                   ? 
                                                                  ((IData)(0x20U) 
                                                                   + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))
                                                                   : (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr))), 3U)))))),8);
    bufp->chgBit(oldp+139,((1U & (~ (IData)(vlSelfRef.reset)))));
    bufp->chgCData(oldp+140,(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ittage__DOT__tables_0__DOT__tags_ext__DOT__Memory
                             [vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ittage__DOT__tables_0__DOT__req_idx]),8);
    bufp->chgCData(oldp+141,(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ittage__DOT__tables_1__DOT__tags_ext__DOT__Memory
                             [vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ittage__DOT__tables_1__DOT__req_idx]),8);
    bufp->chgCData(oldp+142,(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__baseTable_ext__DOT__Memory
                             [(0x60U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc))]),2);
    bufp->chgCData(oldp+143,(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__baseTable_ext__DOT__Memory
                             [(0x7fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__s0_pc))]),2);
    bufp->chgCData(oldp+144,((3U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken)
                                     ? ((3U == vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__baseTable_ext__DOT__Memory
                                         [(0x60U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc))])
                                         ? 3U : ((IData)(1U) 
                                                 + 
                                                 vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__baseTable_ext__DOT__Memory
                                                 [(0x60U 
                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc))]))
                                     : ((0U == vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__baseTable_ext__DOT__Memory
                                         [(0x60U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc))])
                                         ? 0U : (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__baseTable_ext__DOT__Memory
                                                 [(0x60U 
                                                   & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc))] 
                                                 - (IData)(1U)))))),2);
    bufp->chgCData(oldp+145,(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__tables_0__DOT__tags_ext__DOT__Memory
                             [vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__tables_0__DOT__req_idx]),8);
    bufp->chgCData(oldp+146,(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__tables_1__DOT__tags_ext__DOT__Memory
                             [vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__tables_1__DOT__req_idx]),8);
    bufp->chgCData(oldp+147,(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__tables_2__DOT__tags_ext__DOT__Memory
                             [vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__tables_2__DOT__req_idx]),8);
    bufp->chgCData(oldp+148,(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__tables_3__DOT__tags_ext__DOT__Memory
                             [vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__tage__DOT__tables_3__DOT__req_idx]),8);
    bufp->chgCData(oldp+149,((3U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu_skid__DOT__slot0_valid) 
                                    + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu_skid__DOT__slot1_valid)))),2);
    bufp->chgCData(oldp+150,((0xfU & ((7U & ((3U & 
                                              ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu_skid__DOT__slot0_valid) 
                                               + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu_skid__DOT__slot1_valid))) 
                                             + (3U 
                                                & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_valid) 
                                                   + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot1_valid))))) 
                                      + (3U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu_skid__DOT__slot0_valid) 
                                               + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu_skid__DOT__slot1_valid)))))),4);
    bufp->chgBit(oldp+151,(((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ifu_skid__DOT__slot1_valid)) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_ready))));
    bufp->chgBit(oldp+152,((((~ ((IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__b_arbiter__DOT___ctrl_T_4) 
                                 | (2U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__w_state)))) 
                             | ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__b_arbiter__DOT___ctrl_T_1)) 
                                & (3U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__b_arbiter__DOT__ctrl_validMask_grantMask_lastGrant)))) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT____Vcellinp__b_arbiter__io_out_ready))));
    bufp->chgBit(oldp+153,((((~ ((IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__r_arbiter__DOT___ctrl_T_4) 
                                 | (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_state))) 
                             | ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__r_arbiter__DOT___ctrl_T_1)) 
                                & (3U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__r_arbiter__DOT__ctrl_validMask_grantMask_lastGrant)))) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT____Vcellinp__r_arbiter__io_out_ready))));
    bufp->chgQData(oldp+154,(vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__mem_ext__DOT__Memory
                             [(0x1fffffU & (IData)(
                                                   (vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__r_addr 
                                                    >> 3U)))]),64);
    bufp->chgBit(oldp+156,((((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__r_arbiter__DOT___ctrl_T_4)) 
                             | ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__r_arbiter__DOT__ctrl_validMask_1)) 
                                & (~ ((IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__r_arbiter__DOT__ctrl_validMask_grantMask_lastGrant) 
                                      >> 1U)))) & (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT____Vcellinp__r_arbiter__io_out_ready))));
    bufp->chgQData(oldp+157,((QData)((IData)(((0U == 
                                               (0x1fU 
                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_addr)))
                                               ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_spicr)
                                               : ((4U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_addr)))
                                                   ? 
                                                  ((0x10U 
                                                    & (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__tx_fifo__DOT__empty)) 
                                                        | (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__spi_state)) 
                                                       << 4U)) 
                                                   | (0xfU 
                                                      & (~ 
                                                         (((8U 
                                                            & ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__rx_fifo__DOT__full)) 
                                                               << 3U)) 
                                                           | (4U 
                                                              & ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__rx_fifo__DOT__empty)) 
                                                                 << 2U))) 
                                                          | ((2U 
                                                              & ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__tx_fifo__DOT__empty)) 
                                                                 << 1U)) 
                                                             | (1U 
                                                                & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__tx_fifo__DOT__full))))))))
                                                   : 
                                                  ((8U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_addr)))
                                                    ? 
                                                   vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__rx_fifo__DOT__ram_ext__DOT__Memory
                                                   [vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__rx_fifo__DOT__deq_ptr_value]
                                                    : 
                                                   ((0xcU 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_addr)))
                                                     ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_spissr)
                                                     : 
                                                    ((0x10U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_addr)))
                                                      ? (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_spidiv)
                                                      : 0U)))))))),64);
    bufp->chgBit(oldp+159,(((~ ((0U == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_addr))) 
                                | (4U == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_addr))))) 
                            & ((8U == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_addr))) 
                               & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_state) 
                                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT___GEN_8))))));
    bufp->chgCData(oldp+160,(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__rx_fifo__DOT__ram_ext__DOT__Memory
                             [vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__rx_fifo__DOT__deq_ptr_value]),8);
    bufp->chgBit(oldp+161,((((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__r_arbiter__DOT___ctrl_T_3)) 
                             | (0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__r_arbiter__DOT__ctrl_validMask_grantMask_lastGrant))) 
                            & (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT____Vcellinp__r_arbiter__io_out_ready))));
}

void VZaqalSoCTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VZaqalSoCTop___024root__trace_cleanup\n"); );
    // Init
    VZaqalSoCTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VZaqalSoCTop___024root*>(voidSelf);
    VZaqalSoCTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xaU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xbU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xcU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xdU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xeU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xfU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x10U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x11U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x12U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x13U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x14U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x15U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x16U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x17U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x18U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x19U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1aU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1bU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1cU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1dU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1eU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x20U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x21U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x22U] = 0U;
}
