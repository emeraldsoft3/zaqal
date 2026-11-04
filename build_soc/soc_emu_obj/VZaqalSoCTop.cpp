// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VZaqalSoCTop__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VZaqalSoCTop::VZaqalSoCTop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VZaqalSoCTop__Syms(contextp(), _vcname__, this)}
    , reset{vlSymsp->TOP.reset}
    , io_spi_miso{vlSymsp->TOP.io_spi_miso}
    , io_uart_tx_valid{vlSymsp->TOP.io_uart_tx_valid}
    , io_uart_tx_char{vlSymsp->TOP.io_uart_tx_char}
    , io_spi_sck{vlSymsp->TOP.io_spi_sck}
    , io_spi_mosi{vlSymsp->TOP.io_spi_mosi}
    , io_spi_cs_n{vlSymsp->TOP.io_spi_cs_n}
    , io_plic_ext_irq{vlSymsp->TOP.io_plic_ext_irq}
    , clock{vlSymsp->TOP.clock}
    , io_success{vlSymsp->TOP.io_success}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VZaqalSoCTop::VZaqalSoCTop(const char* _vcname__)
    : VZaqalSoCTop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VZaqalSoCTop::~VZaqalSoCTop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VZaqalSoCTop___024root___eval_debug_assertions(VZaqalSoCTop___024root* vlSelf);
#endif  // VL_DEBUG
void VZaqalSoCTop___024root___eval_static(VZaqalSoCTop___024root* vlSelf);
void VZaqalSoCTop___024root___eval_initial(VZaqalSoCTop___024root* vlSelf);
void VZaqalSoCTop___024root___eval_settle(VZaqalSoCTop___024root* vlSelf);
void VZaqalSoCTop___024root___eval(VZaqalSoCTop___024root* vlSelf);

void VZaqalSoCTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VZaqalSoCTop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VZaqalSoCTop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VZaqalSoCTop___024root___eval_static(&(vlSymsp->TOP));
        VZaqalSoCTop___024root___eval_initial(&(vlSymsp->TOP));
        VZaqalSoCTop___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VZaqalSoCTop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VZaqalSoCTop::eventsPending() { return false; }

uint64_t VZaqalSoCTop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VZaqalSoCTop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VZaqalSoCTop___024root___eval_final(VZaqalSoCTop___024root* vlSelf);

VL_ATTR_COLD void VZaqalSoCTop::final() {
    VZaqalSoCTop___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VZaqalSoCTop::hierName() const { return vlSymsp->name(); }
const char* VZaqalSoCTop::modelName() const { return "VZaqalSoCTop"; }
unsigned VZaqalSoCTop::threads() const { return 4; }
void VZaqalSoCTop::prepareClone() const { contextp()->prepareClone(); }
void VZaqalSoCTop::atClone() const {
    vlSymsp->__Vm_threadPoolp = static_cast<VlThreadPool*>(contextp()->threadPoolpOnClone());
}
std::unique_ptr<VerilatedTraceConfig> VZaqalSoCTop::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{true, false, false}};
};

//============================================================
// Trace configuration

void VZaqalSoCTop___024root__trace_decl_types(VerilatedVcd* tracep);

void VZaqalSoCTop___024root__trace_init_top(VZaqalSoCTop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VZaqalSoCTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VZaqalSoCTop___024root*>(voidSelf);
    VZaqalSoCTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VZaqalSoCTop___024root__trace_decl_types(tracep);
    VZaqalSoCTop___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VZaqalSoCTop___024root__trace_register(VZaqalSoCTop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VZaqalSoCTop::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VZaqalSoCTop::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VZaqalSoCTop___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
