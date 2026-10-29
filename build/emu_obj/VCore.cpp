// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VCore__pch.h"

//============================================================
// Constructors

VCore::VCore(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VCore__Syms(contextp(), _vcname__, this)}
    , reset{vlSymsp->TOP.reset}
    , io_mem_resp_bits_data{vlSymsp->TOP.io_mem_resp_bits_data}
    , io_clint_mtip{vlSymsp->TOP.io_clint_mtip}
    , io_plic_ext_irq{vlSymsp->TOP.io_plic_ext_irq}
    , io_tl_d_b_bits_param{vlSymsp->TOP.io_tl_d_b_bits_param}
    , io_tl_d_e_ready{vlSymsp->TOP.io_tl_d_e_ready}
    , io_tl_d_a_ready{vlSymsp->TOP.io_tl_d_a_ready}
    , io_tl_d_a_valid{vlSymsp->TOP.io_tl_d_a_valid}
    , io_tl_d_e_valid{vlSymsp->TOP.io_tl_d_e_valid}
    , io_tl_d_d_bits_data{vlSymsp->TOP.io_tl_d_d_bits_data}
    , io_plic_meip{vlSymsp->TOP.io_plic_meip}
    , io_tl_d_b_bits_address{vlSymsp->TOP.io_tl_d_b_bits_address}
    , io_tl_d_b_valid{vlSymsp->TOP.io_tl_d_b_valid}
    , io_mem_resp_ready{vlSymsp->TOP.io_mem_resp_ready}
    , io_mem_resp_valid{vlSymsp->TOP.io_mem_resp_valid}
    , io_mem_req_bits_addr{vlSymsp->TOP.io_mem_req_bits_addr}
    , io_mem_req_valid{vlSymsp->TOP.io_mem_req_valid}
    , io_mem_req_ready{vlSymsp->TOP.io_mem_req_ready}
    , io_tl_d_a_bits_param{vlSymsp->TOP.io_tl_d_a_bits_param}
    , io_tl_d_c_bits_opcode{vlSymsp->TOP.io_tl_d_c_bits_opcode}
    , io_tl_d_c_bits_param{vlSymsp->TOP.io_tl_d_c_bits_param}
    , io_tl_d_d_ready{vlSymsp->TOP.io_tl_d_d_ready}
    , io_tl_d_d_valid{vlSymsp->TOP.io_tl_d_d_valid}
    , io_tl_d_d_bits_param{vlSymsp->TOP.io_tl_d_d_bits_param}
    , io_tl_d_d_bits_sink{vlSymsp->TOP.io_tl_d_d_bits_sink}
    , io_tl_d_e_bits_sink{vlSymsp->TOP.io_tl_d_e_bits_sink}
    , io_uart_tx_valid{vlSymsp->TOP.io_uart_tx_valid}
    , io_uart_tx_char{vlSymsp->TOP.io_uart_tx_char}
    , io_tl_d_c_bits_data{vlSymsp->TOP.io_tl_d_c_bits_data}
    , io_tl_d_a_bits_address{vlSymsp->TOP.io_tl_d_a_bits_address}
    , io_debug_sum{vlSymsp->TOP.io_debug_sum}
    , clock{vlSymsp->TOP.clock}
    , io_success{vlSymsp->TOP.io_success}
    , io_mem_req_bits_burstLen{vlSymsp->TOP.io_mem_req_bits_burstLen}
    , io_mem_req_bits_isWrite{vlSymsp->TOP.io_mem_req_bits_isWrite}
    , io_mem_resp_bits_last{vlSymsp->TOP.io_mem_resp_bits_last}
    , io_mem_d_req_ready{vlSymsp->TOP.io_mem_d_req_ready}
    , io_mem_d_req_valid{vlSymsp->TOP.io_mem_d_req_valid}
    , io_mem_d_req_bits_burstLen{vlSymsp->TOP.io_mem_d_req_bits_burstLen}
    , io_mem_d_req_bits_isWrite{vlSymsp->TOP.io_mem_d_req_bits_isWrite}
    , io_mem_d_resp_ready{vlSymsp->TOP.io_mem_d_resp_ready}
    , io_mem_d_resp_valid{vlSymsp->TOP.io_mem_d_resp_valid}
    , io_mem_d_resp_bits_last{vlSymsp->TOP.io_mem_d_resp_bits_last}
    , io_tl_d_a_bits_opcode{vlSymsp->TOP.io_tl_d_a_bits_opcode}
    , io_tl_d_a_bits_size{vlSymsp->TOP.io_tl_d_a_bits_size}
    , io_tl_d_a_bits_source{vlSymsp->TOP.io_tl_d_a_bits_source}
    , io_tl_d_a_bits_corrupt{vlSymsp->TOP.io_tl_d_a_bits_corrupt}
    , io_tl_d_b_ready{vlSymsp->TOP.io_tl_d_b_ready}
    , io_tl_d_b_bits_opcode{vlSymsp->TOP.io_tl_d_b_bits_opcode}
    , io_tl_d_b_bits_size{vlSymsp->TOP.io_tl_d_b_bits_size}
    , io_tl_d_b_bits_source{vlSymsp->TOP.io_tl_d_b_bits_source}
    , io_tl_d_b_bits_corrupt{vlSymsp->TOP.io_tl_d_b_bits_corrupt}
    , io_tl_d_c_ready{vlSymsp->TOP.io_tl_d_c_ready}
    , io_tl_d_c_valid{vlSymsp->TOP.io_tl_d_c_valid}
    , io_tl_d_c_bits_size{vlSymsp->TOP.io_tl_d_c_bits_size}
    , io_tl_d_c_bits_source{vlSymsp->TOP.io_tl_d_c_bits_source}
    , io_tl_d_c_bits_corrupt{vlSymsp->TOP.io_tl_d_c_bits_corrupt}
    , io_tl_d_d_bits_opcode{vlSymsp->TOP.io_tl_d_d_bits_opcode}
    , io_tl_d_d_bits_size{vlSymsp->TOP.io_tl_d_d_bits_size}
    , io_tl_d_d_bits_source{vlSymsp->TOP.io_tl_d_d_bits_source}
    , io_tl_d_d_bits_denied{vlSymsp->TOP.io_tl_d_d_bits_denied}
    , io_tl_d_d_bits_corrupt{vlSymsp->TOP.io_tl_d_d_bits_corrupt}
    , io_mem_d_resp_bits_data{vlSymsp->TOP.io_mem_d_resp_bits_data}
    , io_tl_d_a_bits_mask{vlSymsp->TOP.io_tl_d_a_bits_mask}
    , io_tl_d_a_bits_data{vlSymsp->TOP.io_tl_d_a_bits_data}
    , io_tl_d_b_bits_mask{vlSymsp->TOP.io_tl_d_b_bits_mask}
    , io_tl_d_b_bits_data{vlSymsp->TOP.io_tl_d_b_bits_data}
    , io_mem_d_req_bits_addr{vlSymsp->TOP.io_mem_d_req_bits_addr}
    , io_tl_d_c_bits_address{vlSymsp->TOP.io_tl_d_c_bits_address}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VCore::VCore(const char* _vcname__)
    : VCore(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VCore::~VCore() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VCore___024root___eval_debug_assertions(VCore___024root* vlSelf);
#endif  // VL_DEBUG
void VCore___024root___eval_static(VCore___024root* vlSelf);
void VCore___024root___eval_initial(VCore___024root* vlSelf);
void VCore___024root___eval_settle(VCore___024root* vlSelf);
void VCore___024root___eval(VCore___024root* vlSelf);

void VCore::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCore::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VCore___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VCore___024root___eval_static(&(vlSymsp->TOP));
        VCore___024root___eval_initial(&(vlSymsp->TOP));
        VCore___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VCore___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VCore::eventsPending() { return false; }

uint64_t VCore::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VCore::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VCore___024root___eval_final(VCore___024root* vlSelf);

VL_ATTR_COLD void VCore::final() {
    VCore___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VCore::hierName() const { return vlSymsp->name(); }
const char* VCore::modelName() const { return "VCore"; }
unsigned VCore::threads() const { return 4; }
void VCore::prepareClone() const { contextp()->prepareClone(); }
void VCore::atClone() const {
    vlSymsp->__Vm_threadPoolp = static_cast<VlThreadPool*>(contextp()->threadPoolpOnClone());
}
