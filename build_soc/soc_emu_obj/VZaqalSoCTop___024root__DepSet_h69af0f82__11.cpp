// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VZaqalSoCTop.h for the primary calling header

#include "VZaqalSoCTop__pch.h"
#include "VZaqalSoCTop___024root.h"

VL_INLINE_OPT void VZaqalSoCTop___024root___nba_sequent__TOP__28(VZaqalSoCTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VZaqalSoCTop___024root___nba_sequent__TOP__28\n"); );
    VZaqalSoCTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8742) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_9_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_9_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8704) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_36_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_36_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8739) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_6_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8966) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_39_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_39_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8630) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_27_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_27_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8714) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_46_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_46_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_46_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8718) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_50_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_50_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_50_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8669) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_1_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_1_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8641) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_38_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_38_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8936) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_9_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_9_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8920) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_57_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_57_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8926) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_63_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8979) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_52_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_52_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8912) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_49_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_49_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8933) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_6_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_6_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_6_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_6_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8912) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_49_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8945) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_18_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8965) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_38_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_38_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8567) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_29_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_29_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_29_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8958) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_31_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8770) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_37_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_37_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_37_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8958) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_31_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_31_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_31_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8463) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_26_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_26_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8974) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_47_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_47_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8662) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_59_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_59_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_59_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8925) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_62_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_62_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8707) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_39_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_39_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_39_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8925) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_62_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8713) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_45_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8715) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_47_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_47_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_47_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8725) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8726) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8725) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_57_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8726) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_58_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8728) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_60_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8697) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_29_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_29_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8939) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_12_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_12_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8538) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_0_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8702) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_34_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_34_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8656) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_53_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_53_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_53_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8967) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_40_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8451) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_20_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_20_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8657) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_54_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_54_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8658) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_55_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_55_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8661) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_58_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_58_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8924) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_61_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8927) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_0_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8957) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_30_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8927) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_0_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8956) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_29_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_29_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8929) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_2_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_2_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_2_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_2_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8931) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_4_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_4_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8935) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_8_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_8_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_8_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8937) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_10_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_10_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_10_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8949) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_22_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8937) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_10_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8938) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_11_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_11_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8948) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_21_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_21_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8947) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_20_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8938) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_11_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8943) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_16_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_16_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_16_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8946) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_19_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_19_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_19_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_19_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8947) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_20_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8948) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_21_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8783) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8782) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8949) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_22_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8541) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_3_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_3_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8972) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_45_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8956) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_29_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8957) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_30_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8961) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_34_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_34_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_34_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8963) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_36_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8967) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_40_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8968) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_41_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_41_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_41_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8972) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_45_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8976) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_49_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_49_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8708) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_40_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_40_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8982) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_55_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_55_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8984) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8779) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8778) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8984) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_57_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8544) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_6_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8986) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_59_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_59_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_59_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8988) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8767) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_34_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_34_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8766) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8765) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8764) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8988) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_61_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8544) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_6_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_6_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8545) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_7_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_7_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_7_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8709) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_41_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_41_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_31_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_30_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_29_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_28_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_27_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_26_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_25_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_24_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_23_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_22_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_21_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_8_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_7_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_6_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_5_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_4_taken = 0U;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_37) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_31_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_36) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_30_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_35) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_29_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_34) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_28_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_33) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_27_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_32) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_26_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_31) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_25_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_30) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_24_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_29) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_23_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_28) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_22_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_27) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_21_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_14) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_8_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_13) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_7_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_12) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_6_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_11) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_5_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_10) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_4_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8745) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_12_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_1_taken = 0U;
    } else if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_7) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_1_taken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8744) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_11_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_11_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8743) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_10_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_10_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_0_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_2_taken = 0U;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_6) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_0_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_8) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_2_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8741) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_8_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_8_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8740) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_7_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_7_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_3_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_9_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_10_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_11_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_12_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_13_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_14_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_15_taken = 0U;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_9) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_3_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_15) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_9_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_16) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_10_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_17) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_11_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_18) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_12_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_19) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_13_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_20) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_14_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_21) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_15_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8749) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8736) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_3_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_3_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8735) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_2_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_2_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8733) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_0_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_0_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8748) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8747) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_16_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_17_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_18_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_19_taken = 0U;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_22) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_16_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_23) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_17_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_24) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_18_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_25) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_19_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8633) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_20_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_42_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_43_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_44_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_45_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_46_taken = 0U;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_26) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_20_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_48) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_42_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_49) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_43_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_50) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_44_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_51) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_45_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_52) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_46_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8515) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_52_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_52_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8687) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8509) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8686) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8687) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_47_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_60_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_61_taken = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_7_offset = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_6_offset = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_5_offset = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_4_offset = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_1_offset = 0U;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_53) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_47_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_66) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_60_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_67) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_61_taken 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_13) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_7_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_12) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_6_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_11) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_5_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_10) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_4_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_7) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_1_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8629) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_0_offset = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_2_offset = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_3_offset = 0U;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_6) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_0_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_8) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_2_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_9) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_3_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8501) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8628) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_25_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8501) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_9_offset = 0U;
    } else if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_15) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_9_offset 
            = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                               >> 1U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8499) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_44_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_44_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8626) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_23_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_23_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8680) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_12_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8495) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_42_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8680) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_12_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8682) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_14_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_10_offset = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_46_offset = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_47_offset = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_14_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_13_tag = 0ULL;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_16) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_10_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_52) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_46_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_53) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_47_offset 
                = (0xfU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                                   >> 1U)));
        }
        if ((1U & (~ (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT____Vcellinp__uftb__io_update_valid)) 
                       | (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT___is_update_hit_T))) 
                      | (0xeU != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr)))))) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_14_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 4U);
        }
        if ((1U & (~ (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT____Vcellinp__uftb__io_update_valid)) 
                       | (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT___is_update_hit_T))) 
                      | (0xdU != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr)))))) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_13_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 4U);
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8673) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_12_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_8_tag = 0ULL;
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_15_valid = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_15_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_15_target = 0ULL;
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr = 0U;
    } else {
        if ((1U & (~ (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT____Vcellinp__uftb__io_update_valid)) 
                       | (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT___is_update_hit_T))) 
                      | (0xcU != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr)))))) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_12_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 4U);
        }
        if ((1U & (~ (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT____Vcellinp__uftb__io_update_valid)) 
                       | (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT___is_update_hit_T))) 
                      | (8U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr)))))) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_8_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 4U);
        }
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_15_valid 
            = ((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT____Vcellinp__uftb__io_update_valid) 
                 & (~ (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT___is_update_hit_T)))) 
                & (0xfU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr))) 
               | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_15_valid));
        if ((1U & (~ (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT____Vcellinp__uftb__io_update_valid)) 
                       | (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT___is_update_hit_T))) 
                      | (~ (0xfU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr))))))) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_15_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 4U);
        }
        if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT____Vcellinp__uftb__io_update_valid) 
             & ((0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT___is_update_hit_T))
                 ? (0xfU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__update_hit_idx))
                 : (0xfU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr))))) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__entries_15_target 
                = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_target;
        }
        if ((1U & (~ ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT____Vcellinp__uftb__io_update_valid)) 
                      | (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT___is_update_hit_T)))))) {
            vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__uftb__DOT__alloc_ptr)));
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8623) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_20_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_20_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_42_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_38_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_36_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_34_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_32_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_30_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_28_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_26_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_24_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_22_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_9_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_8_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_7_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_6_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_5_tag = 0ULL;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_48) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_42_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_44) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_38_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_42) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_36_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_40) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_34_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_38) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_32_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_36) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_30_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_34) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_28_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_32) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_26_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_30) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_24_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_28) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_22_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_15) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_9_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_14) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_8_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_13) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_7_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_12) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_6_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_11) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_5_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8487) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8675) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_1_tag = 0ULL;
    } else if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_7) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_1_tag 
            = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
               >> 0xbU);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8483) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8477) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8670) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_2_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8475) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_32_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8477) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8483) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8674) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_6_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_0_tag = 0ULL;
    } else if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_6) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_0_tag 
            = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
               >> 0xbU);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8473) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_31_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_31_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_31_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8471) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_30_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_30_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8668) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_0_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_2_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_3_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_4_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_10_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_13_tag = 0ULL;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_8) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_2_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_9) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_3_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_10) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_4_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_16) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_10_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_19) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_13_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8665) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_62_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8467) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_28_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_15_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_18_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_19_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_44_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_46_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_47_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_55_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_57_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_59_tag = 0ULL;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_61_tag = 0ULL;
    } else {
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_21) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_15_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_24) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_18_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_25) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_19_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_50) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_44_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_52) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_46_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_53) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_47_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_61) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_55_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_63) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_57_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_65) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_59_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT___GEN_67) {
            vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb__DOT__entries_61_tag 
                = (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_pc 
                   >> 0xbU);
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8525) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_spicr = 3U;
        vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_spissr = 0xfU;
        vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__r_mcr = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__r_scr = 0U;
    } else {
        if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT___GEN_2) 
             & (0U == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr))))) {
            vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_spicr = 0U;
        }
        if ((1U & (~ ((((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT___GEN_2)) 
                        | (0U == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                       | (8U == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                      | (0xcU != (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr))))))) {
            vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_spissr = 0U;
        }
        if ((1U & (~ (((((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT___GEN)) 
                         | (0U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                        | (1U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                       | (3U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                      | (4U != (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr))))))) {
            vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__r_mcr = 0U;
        }
        if ((1U & (~ ((((((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT___GEN)) 
                          | (0U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                         | (1U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                        | (3U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                       | (4U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                      | (7U != (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr))))))) {
            vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__r_scr = 0U;
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8413) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8639) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_36_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__r_lcr = 3U;
        vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__r_ier = 0U;
        vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_spidiv = 4U;
        vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__w_state = 0U;
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__dram__DOT__w_beat_cnt = 0U;
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr = 0U;
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr = 0U;
    } else {
        if ((1U & (~ ((((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT___GEN)) 
                        | (0U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                       | (1U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                      | (3U != (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr))))))) {
            vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__r_lcr = 0U;
        }
        if ((1U & (~ (((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT___GEN)) 
                       | (0U == (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                      | (1U != (7U & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr))))))) {
            vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__r_ier = 0U;
        }
        if ((1U & (~ (((((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT___GEN_2)) 
                         | (0U == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                        | (8U == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                       | (0xcU == (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr)))) 
                      | (0x10U != (0x1fU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__uart__DOT__w_addr))))))) {
            vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__r_spidiv = 0U;
        }
        if (((((~ ((IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__b_arbiter__DOT___ctrl_T_4) 
                   | (2U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__spi__DOT__w_state)))) 
               | ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__b_arbiter__DOT___ctrl_T_1)) 
                  & (3U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__b_arbiter__DOT__ctrl_validMask_grantMask_lastGrant)))) 
              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT____Vcellinp__b_arbiter__io_out_ready)) 
             & (IData)(vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__io_in_b_valid_0))) {
            vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__w_state = 0U;
        } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__mem_MPORT_en) 
                    & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__xbar__DOT__io_slaves_3_w_bits_last_0) 
                       | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__w_beat_cnt) 
                          == (IData)(vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__w_len))))) {
            vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__w_state = 2U;
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__mem_MPORT_en) {
            vlSelfRef.__Vdly__ZaqalSoCTop__DOT__dram__DOT__w_beat_cnt 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__dram__DOT__w_beat_cnt)));
        }
        if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__is_valid_redirect) {
            vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr 
                = (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_is_cfi) 
                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_is_jalr))
                    ? (((((0U == (0x1fU & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U)))
                           ? 0U : (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___GEN_0[
                                   (((IData)(0x19U) 
                                     + (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U))) 
                                    >> 5U)] << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U))))) 
                         | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___GEN_0[
                            (0x3fU & (VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U) 
                                      >> 5U))] >> (0x1fU 
                                                   & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U)))) 
                        << 6U) | (0x3fU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_target 
                                                   >> 2U))))
                    : (((0U == (0x1fU & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U)))
                         ? 0U : (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___GEN_0[
                                 (((IData)(0x1fU) + 
                                   (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U))) 
                                  >> 5U)] << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U))))) 
                       | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___GEN_0[
                          (0x3fU & (VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U) 
                                    >> 5U))] >> (0x1fU 
                                                 & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT___backend_io_redirect_ftqPtr), 5U)))));
            vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr = 0U;
        } else {
            if ((((((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
                    & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ftb_valid)) 
                   & (2U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ftb_io_br_type))) 
                  & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___is_spec_jalr_T_4)) 
                 & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__final_taken))) {
                vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr 
                    = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr 
                        << 6U) | (0x3fU & (IData)((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__final_target 
                                                   >> 2U))));
            }
            if ((1U & ((~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu_skid__DOT__slot1_valid)) 
                       & (~ (IData)(vlSelfRef.reset))))) {
                vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)));
            }
        }
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8645) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_42_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_42_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8547) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_9_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8711) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_43_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8519) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8712) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_44_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_44_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8549) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_11_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_11_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8550) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_12_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_12_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8551) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_13_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_13_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_13_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8915) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8552) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_14_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_14_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8511) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8634) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_31_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_31_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8552) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_14_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_14_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8553) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_15_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_15_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8554) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_16_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8555) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_17_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_17_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_17_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8688) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_20_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_20_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8719) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_51_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8699) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_31_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_31_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8533) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8719) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_51_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8557) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_19_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_19_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8786) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8919) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_56_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_56_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8786) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8785) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8781) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8731) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8780) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8776) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8775) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8774) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8776) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8781) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8773) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8505) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8773) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8666) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8570) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8491) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8666) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8625) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_22_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8521) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8643) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_40_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_40_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8644) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8455) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_22_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_22_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8427) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_8_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_8_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8659) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8469) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_29_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8435) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_12_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_12_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8539) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_1_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_1_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8419) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8621) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_18_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_18_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8469) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_29_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_29_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_29_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8625) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_22_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8679) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_11_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8637) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8703) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8637) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8679) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_11_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8493) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_41_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8677) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_9_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_9_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_9_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8489) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8622) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_19_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_19_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_19_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8676) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_8_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_8_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_8_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8493) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_41_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8648) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8773) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8772) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8771) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8447) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_18_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_18_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8507) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8655) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8507) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8772) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8763) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8655) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8763) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8635) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_32_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_32_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8763) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8762) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8737) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_4_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_4_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_4_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8761) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8760) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8751) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8760) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8750) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8760) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8763) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8769) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_36_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8437) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_13_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_13_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8650) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8437) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_13_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8769) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_36_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8785) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8768) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8698) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_30_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_30_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_30_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_30_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8768) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8557) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_19_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8784) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8721) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_53_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_53_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8723) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_55_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_55_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8559) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_21_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_21_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8560) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_22_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8561) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_23_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_23_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_23_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8562) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_24_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_24_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_24_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_24_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8727) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_59_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_59_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_59_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8564) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_26_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_26_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8433) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_11_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_11_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8568) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_30_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8651) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8443) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_16_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8653) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_50_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8654) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_51_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8443) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_16_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8651) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8568) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_30_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8569) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_31_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8571) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_33_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_33_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_33_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8575) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_37_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_37_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8576) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_38_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_38_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8582) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_44_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8453) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8583) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_45_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8457) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8583) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_45_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8439) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8461) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_25_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_25_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8459) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8439) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8584) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8461) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_25_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8584) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_46_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8585) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_47_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_47_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8586) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_48_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_48_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_48_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8587) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_49_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8461) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_25_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8786) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_53_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8785) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_52_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8784) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_51_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8783) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_50_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8782) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_pc_11 
            = (0x16ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_49_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8781) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_48_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8780) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_47_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8779) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_46_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8778) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_45_pc_11 
            = (0x16ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8587) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_49_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8776) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_43_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8775) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_42_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8774) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_41_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8773) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_40_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8772) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_39_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8771) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_38_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8769) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_36_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8768) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_35_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8767) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_34_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8766) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_33_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8765) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_32_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8764) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_31_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8763) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_30_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8762) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_29_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8761) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_28_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8760) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_27_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8588) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_50_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8589) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_51_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8590) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_52_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_52_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_52_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8591) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_53_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8592) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_54_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_54_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8596) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_58_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_58_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8597) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_59_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_59_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_59_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8599) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_61_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_61_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8601) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_63_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_63_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8603) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_0_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_0_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8607) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_4_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_4_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8610) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_7_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_7_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_7_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8611) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_8_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8612) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_9_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_9_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_9_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_9_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8614) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_11_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_11_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8615) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_12_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_12_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_12_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_12_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_12_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8616) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_13_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_13_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_13_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_13_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8617) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_14_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_14_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_14_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_14_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8618) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_15_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_15_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8619) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_16_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_16_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_16_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8789) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_56_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_56_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8790) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_57_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8792) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_59_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_59_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8794) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_61_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_61_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8795) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_62_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_62_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8799) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_1_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_1_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8751) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8517) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8751) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_18_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8750) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_17_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8749) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8691) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_23_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8749) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_16_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8748) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_15_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8747) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_14_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8800) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_2_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_2_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_2_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8803) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_5_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8745) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_12_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_12_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8744) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_11_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_11_pc_11 
            = (0x16ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_11_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8743) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_10_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_10_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8741) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_8_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8740) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_7_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_7_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8803) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_5_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_5_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8737) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_4_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8736) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_3_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_3_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_3_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8735) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_2_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_2_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8804) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_6_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8733) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_0_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8804) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_6_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8515) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_52_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8635) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_32_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8805) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_7_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_7_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_7_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_7_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8806) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_8_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_8_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_8_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_8_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8807) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_9_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_9_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_9_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_9_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8633) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_30_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8687) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_19_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8509) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_49_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8808) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_10_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_10_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_10_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8809) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_11_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_11_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_11_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_11_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8810) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_12_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_12_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_12_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8465) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_27_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_27_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_27_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8686) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_18_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8507) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_48_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8629) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_26_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8810) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_12_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8811) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_13_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8812) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_14_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8501) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_45_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8628) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_25_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_25_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_25_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8682) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_14_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8499) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_44_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8626) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_23_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8680) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_12_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_12_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8495) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_42_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8625) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_22_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_22_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8679) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_11_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_11_pc_11 
            = (0x16ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_11_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8493) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_41_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8623) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_20_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_20_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8677) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_9_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_9_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8489) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_39_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8622) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_19_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8676) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_8_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8487) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_38_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8675) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_7_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8812) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_14_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_14_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8815) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_17_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_17_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8816) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_18_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_18_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8818) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_20_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_20_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8820) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_22_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8674) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_6_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_6_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_6_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_6_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_6_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8483) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_36_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8673) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8421) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_5_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8673) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_5_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8820) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_22_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8821) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_23_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_23_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8823) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_25_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8527) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8823) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_25_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_25_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8824) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_26_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8825) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_27_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_27_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8664) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8642) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8664) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8692) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8497) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8825) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_27_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8828) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_30_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_30_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_30_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8829) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_31_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_31_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8497) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8830) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8441) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8830) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_32_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8663) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_60_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8831) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_33_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_33_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_33_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8832) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_34_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_34_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8477) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8647) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8477) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_33_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8670) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_2_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_2_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8475) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_32_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8473) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_31_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8668) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_0_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_0_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8471) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_30_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8666) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_63_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8469) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_29_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_29_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8665) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_62_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8467) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_28_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_28_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8419) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8636) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8423) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_6_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8636) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8423) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_6_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8636) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8419) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_4_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8425) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_7_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8531) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_60_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8832) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_34_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8833) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_35_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_35_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8429) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8535) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8429) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8701) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8429) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8833) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_35_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8834) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8525) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_57_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8834) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_36_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8835) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8413) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8445) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8413) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_1_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8919) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_56_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8692) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_24_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8519) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_54_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8835) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8581) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_43_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8636) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_33_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8835) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_37_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8836) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_38_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8837) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_39_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8915) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_52_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8634) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_31_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8511) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_50_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8639) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_36_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8837) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_39_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8839) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_41_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8521) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_55_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8659) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_56_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8645) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_42_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8455) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_22_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8427) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_8_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8691) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_23_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_23_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8688) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_20_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8699) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_31_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_31_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_31_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_31_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8533) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_61_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8631) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_28_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8664) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_61_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8577) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_39_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8465) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_27_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_27_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_27_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8693) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8540) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_2_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8693) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_25_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8685) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_17_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8505) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8540) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_2_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8505) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_47_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8570) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_32_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8839) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_41_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_41_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8840) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_42_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8841) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_43_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_43_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8843) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_45_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_45_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8441) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_15_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8439) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_14_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8637) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_34_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8517) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_53_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8624) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_21_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8435) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_12_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_12_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8845) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_47_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_47_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8703) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_35_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8621) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_18_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_18_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8539) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_1_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_1_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8731) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_63_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8491) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_40_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8905) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_42_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8421) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_5_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_5_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8663) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_60_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_60_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8527) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_58_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8642) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_39_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8696) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_28_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8497) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_43_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8681) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_13_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8908) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_45_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8684) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_16_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8846) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_48_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8849) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_51_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_51_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8850) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_52_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8853) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_55_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_55_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8854) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_56_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8417) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_3_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8523) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_56_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8854) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_56_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_56_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8855) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_57_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_57_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_57_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8856) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_58_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8857) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_59_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_59_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_59_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8858) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_60_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_60_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_60_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8859) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8447) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_18_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8655) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_52_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8859) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_61_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8860) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8423) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_6_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_6_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8860) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8643) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_40_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8425) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_7_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_7_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8531) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_60_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_60_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8644) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_41_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8698) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_30_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8453) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_21_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8429) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_9_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8535) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_62_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8646) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_43_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8700) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_32_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8457) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_23_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8431) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_10_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8536) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_63_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8647) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_44_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8701) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_33_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8459) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_24_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8433) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_11_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_11_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_11_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8648) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_45_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8461) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_25_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8437) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_13_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8540) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_2_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_2_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8650) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_47_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8651) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_48_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8443) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_16_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8653) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_50_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8445) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_17_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8654) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_51_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_51_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8860) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_62_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8861) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_63_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8863) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_0_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_0_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_0_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8865) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_2_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_2_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_2_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8866) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_3_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8867) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_4_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_4_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8869) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_6_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_6_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_6_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8870) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_7_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_7_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8871) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_8_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_8_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_8_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8872) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_9_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8875) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_12_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_12_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_12_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8876) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_13_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_13_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_13_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8879) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_16_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_16_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8880) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_17_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_17_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_17_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8881) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_18_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_18_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8882) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_19_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8883) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_20_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_20_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_20_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8884) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_21_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_21_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_21_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8885) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_22_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_22_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_22_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_22_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_22_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8886) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_23_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_23_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_23_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_23_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8887) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_24_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8890) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_27_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_27_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_27_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8891) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_28_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_28_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8894) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_31_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_31_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_31_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8896) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_33_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8898) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_35_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_35_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8900) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_37_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_37_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_37_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8901) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_38_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_38_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8904) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_41_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_41_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_41_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8906) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_43_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8909) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_46_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_46_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_46_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8910) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_47_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8913) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_50_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_50_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8914) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_51_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_51_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8916) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_53_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_53_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_53_pre_decoded_3_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8917) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_54_pre_decoded_2_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_54_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8921) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_58_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_58_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8928) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_1_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_1_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_1_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8930) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_3_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8934) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_7_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_7_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_7_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8941) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_14_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8950) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_23_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8953) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_26_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_26_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_26_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8954) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_27_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8955) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_28_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8962) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_35_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_35_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_35_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8978) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_51_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_51_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8980) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_53_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8983) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_56_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_56_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8987) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_60_instructions_2 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_1;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_60_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if ((1U & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT___GEN_115)))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_37_1 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[1U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_37_0 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[0U];
    }
    if ((1U & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT___GEN_114)))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_36_1 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[1U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_36_0 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[0U];
    }
    if ((1U & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT___GEN_111)))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_33_1 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[1U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_33_0 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[0U];
    }
    if ((1U & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT___GEN_79)))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_1_1 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[1U];
    }
    if ((1U & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT___GEN_137)))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_59_1 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[1U];
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8787) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_54_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8777) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_44_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_44_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_44_pc_10 
            = (0x14ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8759) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_26_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8755) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_22_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8754) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_21_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8734) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_1_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_1_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8689) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_21_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8632) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_29_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8485) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_37_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8671) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_3_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_3_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_3_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_3_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8695) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_27_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_27_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_27_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_27_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_27_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_27_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8638) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_35_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8694) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_26_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8503) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_46_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_46_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_46_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8911) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_48_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_48_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_48_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8542) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_4_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8716) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_48_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8717) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_49_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8563) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_25_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8565) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_27_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8729) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_61_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8593) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_55_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8595) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_57_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8600) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_62_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8606) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_3_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8613) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_10_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8788) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_55_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_55_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8793) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_60_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8813) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_15_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_15_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8814) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_16_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_16_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8819) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_21_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8838) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_40_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8844) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_46_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8848) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_50_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_50_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_50_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8864) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_1_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8888) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_25_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_25_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8889) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_26_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8895) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_32_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8907) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_44_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8918) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_55_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_55_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_55_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8923) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_60_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_60_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8940) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_13_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8952) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_25_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_25_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8959) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_32_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_32_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_32_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8960) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_33_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_33_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_33_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8964) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_37_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8971) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_44_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_44_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8977) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_50_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_50_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_50_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8985) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_58_pre_decoded_0_is_rvc 
            = (3U != (3U & vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_58_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8989) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_62_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8990) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_63_instructions_0 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___ifu_io_toIbuffer_bits_instructions_0;
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8481) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_35_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8690) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_22_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_22_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_22_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_22_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8652) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_49_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8649) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_46_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_46_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_46_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8678) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_10_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_10_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_10_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8640) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_37_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8660) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_57_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8705) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_37_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8706) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_38_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8543) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_5_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8710) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_42_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8580) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_42_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8594) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_56_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8604) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_1_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8605) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_2_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8609) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_6_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8620) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_17_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8796) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_63_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8798) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_0_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8802) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_4_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8822) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_24_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8827) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_29_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8847) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_49_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8851) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_53_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8852) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_5_54_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8868) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_5_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8873) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_10_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8874) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_11_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8877) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_14_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8878) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_15_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8892) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_29_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8893) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_30_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8902) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_39_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8922) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_6_59_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8932) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_5_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8942) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_15_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8951) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_24_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8981) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_7_54_pre_decoded_1_is_rvc 
            = (3U != (3U & (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT___icache_io_insts_0 
                            >> 0x10U)));
    }
    if ((1U & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT___GEN_119)))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_41_0 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[0U];
    }
    if ((1U & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT___GEN_110)))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_32_0 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[0U];
    }
    if ((1U & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT___GEN_112)))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_34_0 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[0U];
    }
    if ((1U & (~ (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT___GEN_113)))) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__dataArray_35_0 
            = vlSelfRef.ZaqalSoCTop__DOT___icache_bridge_io_mem_resp_bits_data[0U];
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0U == (0x3fU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))
                    : ((0U == (0x3fU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (0U != (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_0_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (1U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((2U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (0U != (0x1fU & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr) 
                                          >> 1U))))
                    : (IData)(((0U != (0x3eU & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))) 
                               | (2U > (0x3fU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))))))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_1_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (2U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((3U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_19))
                    : ((3U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_19))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_2_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (3U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((4U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (0U != (0xfU & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr) 
                                         >> 2U)))) : (IData)(
                                                             ((0U 
                                                               != 
                                                               (0x3cU 
                                                                & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))) 
                                                              | (4U 
                                                                 > 
                                                                 (0x3fU 
                                                                  & ((IData)(1U) 
                                                                     + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))))))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_3_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (4U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((5U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_33))
                    : ((5U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_33))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_4_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (5U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((6U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_40))
                    : ((6U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_40))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_5_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (6U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((7U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_47))
                    : ((7U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_47))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_6_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (7U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((8U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (0U != (7U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr) 
                                       >> 3U)))) : (IData)(
                                                           ((0U 
                                                             != 
                                                             (0x38U 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))) 
                                                            | (8U 
                                                               > 
                                                               (0x3fU 
                                                                & ((IData)(1U) 
                                                                   + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))))))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_7_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (8U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((9U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_61))
                    : ((9U > (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_61))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_8_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (9U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0xaU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_68))
                    : ((0xaU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_68))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_9_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0xaU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0xbU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_75))
                    : ((0xbU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_75))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_10_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0xbU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0xcU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_82))
                    : ((0xcU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_82))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_11_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0xcU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0xdU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_89))
                    : ((0xdU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_89))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_12_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0xdU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0xeU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_96))
                    : ((0xeU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_96))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_13_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0xeU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0xfU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_103))
                    : ((0xfU > (0x3fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_103))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_14_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0xfU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x10U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (0U != (3U & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr) 
                                       >> 4U)))) : (IData)(
                                                           ((0U 
                                                             != 
                                                             (0x30U 
                                                              & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))) 
                                                            | (0x10U 
                                                               > 
                                                               (0x3fU 
                                                                & ((IData)(1U) 
                                                                   + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))))))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_15_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x10U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x11U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_117))
                    : ((0x11U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_117))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_16_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x11U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x12U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_124))
                    : ((0x12U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_124))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_17_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x12U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x13U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_131))
                    : ((0x13U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_131))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_18_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x13U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x14U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_138))
                    : ((0x14U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_138))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_19_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x14U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x15U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_145))
                    : ((0x15U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_145))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_20_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x15U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x16U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_152))
                    : ((0x16U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_152))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_21_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x16U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x17U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_159))
                    : ((0x17U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_159))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_22_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x17U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x18U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_166))
                    : ((0x18U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_166))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_23_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x18U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x19U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_173))
                    : ((0x19U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_173))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_24_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x19U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x1aU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_180))
                    : ((0x1aU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_180))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_25_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x1aU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x1bU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_187))
                    : ((0x1bU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_187))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_26_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x1bU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x1cU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_194))
                    : ((0x1cU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_194))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_27_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x1cU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x1dU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_201))
                    : ((0x1dU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_201))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_28_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x1dU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x1eU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_208))
                    : ((0x1eU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_208))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_29_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x1eU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x1fU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_215))
                    : ((0x1fU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_215))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_30_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x1fU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((~ (1U & (((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                 >> 5U))) & ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr) 
                                             >> 5U))
                    : ((~ (1U & (((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                 >> 5U))) | ((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr) 
                                             >> 5U))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_31_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x20U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x21U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_229))
                    : ((0x21U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_229))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_32_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x21U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x22U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_236))
                    : ((0x22U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_236))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_33_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x22U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x23U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_243))
                    : ((0x23U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_243))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_34_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x23U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x24U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_250))
                    : ((0x24U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_250))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_35_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x24U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x25U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_257))
                    : ((0x25U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_257))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_36_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x25U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x26U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_264))
                    : ((0x26U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_264))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_37_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x26U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x27U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_271))
                    : ((0x27U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_271))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_38_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x27U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x28U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_278))
                    : ((0x28U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_278))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_39_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x28U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x29U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_285))
                    : ((0x29U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_285))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_40_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x29U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x2aU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_292))
                    : ((0x2aU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_292))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_41_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x2aU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x2bU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_299))
                    : ((0x2bU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_299))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_42_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x2bU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x2cU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_306))
                    : ((0x2cU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_306))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_43_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x2cU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x2dU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_313))
                    : ((0x2dU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_313))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_44_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x2dU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x2eU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_320))
                    : ((0x2eU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_320))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_45_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x2eU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x2fU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_327))
                    : ((0x2fU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_327))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_46_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x2fU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((3U != (3U & (((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                     >> 4U))) & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_334))
                    : ((3U != (3U & (((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                     >> 4U))) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_334))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_47_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x30U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x31U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_341))
                    : ((0x31U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_341))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_48_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x31U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x32U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_348))
                    : ((0x32U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_348))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_49_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x32U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x33U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_355))
                    : ((0x33U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_355))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_50_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x33U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x34U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_362))
                    : ((0x34U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_362))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_51_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x34U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x35U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_369))
                    : ((0x35U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_369))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_52_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x35U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x36U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_376))
                    : ((0x36U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_376))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_53_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x36U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x37U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_383))
                    : ((0x37U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_383))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_54_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x37U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((7U != (7U & (((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                     >> 3U))) & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_390))
                    : ((7U != (7U & (((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                     >> 3U))) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_390))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_55_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x38U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x39U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_397))
                    : ((0x39U > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_397))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_56_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x39U == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x3aU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_404))
                    : ((0x3aU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_404))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_57_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x3aU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x3bU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_411))
                    : ((0x3bU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_411))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_58_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x3bU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0xfU != (0xfU & (((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                         >> 2U))) & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_418))
                    : ((0xfU != (0xfU & (((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                         >> 2U))) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_418))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_59_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x3cU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x3dU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_425))
                    : ((0x3dU > (0x3fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_425))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_60_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x3dU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x1fU != (0x1fU & (((IData)(1U) 
                                            + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                           >> 1U))) 
                       & (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_432))
                    : ((0x1fU != (0x1fU & (((IData)(1U) 
                                            + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)) 
                                           >> 1U))) 
                       | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___in_flight_T_432))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_61_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x3eU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & (((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                    <= (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr))
                    ? ((0x3fU != (0x3fU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       & (0x3fU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))
                    : ((0x3fU != (0x3fU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr)))) 
                       | (0x3fU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_62_ghr[3U] 
                             << 1U));
    }
    if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ras_io_spec_pop_valid_T) 
         & (0x3fU == (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[0U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[0U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[1U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[1U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[2U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[2U];
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[3U] 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__new_meta_ghr[3U];
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_phr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__phr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ras_sp 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__ras__DOT__spec_sp;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr_spec_shifted 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__has_spec_cond_br;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_tage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_tage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_tage_providerCtr 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerCtr;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_tage_altTaken 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_altTaken;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_tage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___tage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ittage_providerIdx 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerIdx;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ittage_providerHit 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_hit;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ittage_altTarget 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_altTarget;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ittage_providerU 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___ittage_io_pred_providerU;
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_sc_sum 
            = vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT___sc_io_pred_sum;
    } else if (((IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__do_non_spec_shift) 
                & ((0x3fU & ((IData)(1U) + (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_ftqPtr))) 
                   > (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_enq_ptr)))) {
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[0U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[0U] 
                << 1U) | (IData)(vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__bpu_update_taken));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[1U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[0U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[1U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[2U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[1U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[2U] 
                             << 1U));
        vlSelfRef.__Vdly__ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[3U] 
            = ((vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[2U] 
                >> 0x1fU) | (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__meta_storage_63_ghr[3U] 
                             << 1U));
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8411) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_0_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8758) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_25_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8757) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_24_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8756) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_23_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8753) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_20_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8752) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_19_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8746) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_13_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_13_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_13_pc_5 
            = (0xaULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_13_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8738) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_5_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_4_5_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8513) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_51_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8683) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_15_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_15_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_15_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8672) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_3_4_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8479) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_34_pc_3 
            = (6ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8415) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_2_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_2_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8627) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_1 
            = (2ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_2 
            = (4ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_4 
            = (8ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_6 
            = (0xcULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_7 
            = (0xeULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_8 
            = (0x10ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_14 
            = (0x1cULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_2_24_pc_15 
            = (0x1eULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8573) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_1_35_pc_13 
            = (0x1aULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
    if (vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT___GEN_8529) {
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_59_pc_9 
            = (0x12ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
        vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__uopCache__DOT__data_0_59_pc_12 
            = (0x18ULL + vlSelfRef.ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ftq_skid__DOT__slot0_data_pc);
    }
}
