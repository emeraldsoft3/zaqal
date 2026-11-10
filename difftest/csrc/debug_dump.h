#pragma once
#include <iostream>
#include <iomanip>

inline void dump_debug(VZaqalSoCTop *top) {
  std::cout << "=== IntIQ Entries ===\n";
#define DUMP_INTIQ(i) \
  if (top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_##i##_valid) { \
    std::cout << "  IntIQ[" << i << "]: robIdx=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_##i##_uop_robIdx \
              << " PC=0x" << std::hex << top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_##i##_uop_uop_pc \
              << " pdest=" << std::dec << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_##i##_uop_pdest \
              << " psrs1=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_##i##_uop_psrs1 \
              << " psrs2=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_##i##_uop_psrs2 \
              << " r1_rdy=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_##i##_rs1_ready \
              << " r2_rdy=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intIq__DOT__entries_##i##_rs2_ready \
              << "\n"; \
  }
  DUMP_INTIQ(0); DUMP_INTIQ(1); DUMP_INTIQ(2); DUMP_INTIQ(3);
  DUMP_INTIQ(4); DUMP_INTIQ(5); DUMP_INTIQ(6); DUMP_INTIQ(7);
  DUMP_INTIQ(8); DUMP_INTIQ(9); DUMP_INTIQ(10); DUMP_INTIQ(11);
  DUMP_INTIQ(12); DUMP_INTIQ(13); DUMP_INTIQ(14); DUMP_INTIQ(15);
#undef DUMP_INTIQ

  std::cout << "=== MemIQ Entries ===\n";

#define DUMP_MEMIQ(i) \
  if (top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__memIq__DOT__entries_##i##_valid) { \
    std::cout << "  MemIQ[" << i << "]: robIdx=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__memIq__DOT__entries_##i##_uop_robIdx \
              << " PC=0x" << std::hex << top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__memIq__DOT__entries_##i##_uop_uop_pc \
              << " pdest=" << std::dec << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__memIq__DOT__entries_##i##_uop_pdest \
              << " psrs1=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__memIq__DOT__entries_##i##_uop_psrs1 \
              << " r1_rdy=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__memIq__DOT__entries_##i##_rs1_ready \
              << " r2_rdy=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__memIq__DOT__entries_##i##_rs2_ready \
              << " waitBit=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__memIq__DOT__entries_##i##_uop_loadWaitBit \
              << " waitForRob=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__memIq__DOT__entries_##i##_uop_waitForRobIdx \
              << "\n"; \
  }
  DUMP_MEMIQ(0); DUMP_MEMIQ(1); DUMP_MEMIQ(2); DUMP_MEMIQ(3);
  DUMP_MEMIQ(4); DUMP_MEMIQ(5); DUMP_MEMIQ(6); DUMP_MEMIQ(7);
  DUMP_MEMIQ(8); DUMP_MEMIQ(9); DUMP_MEMIQ(10); DUMP_MEMIQ(11);
  DUMP_MEMIQ(12); DUMP_MEMIQ(13); DUMP_MEMIQ(14); DUMP_MEMIQ(15);
#undef DUMP_MEMIQ

  std::cout << "=== LQ Entries ===\n";
#define DUMP_LQ(i) \
  if (top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__lq__DOT__entries_##i##_valid) { \
    std::cout << "  LQ[" << i << "]: robIdx=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__lq__DOT__entries_##i##_robIdx \
              << " PC=0x" << std::hex << top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__lq__DOT__entries_##i##_pc \
              << " paddr=0x" << top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__lq__DOT__entries_##i##_paddr \
              << " exec=" << std::dec << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__lq__DOT__entries_##i##_executed \
              << "\n"; \
  }
  DUMP_LQ(0); DUMP_LQ(1); DUMP_LQ(2); DUMP_LQ(3);
  DUMP_LQ(4); DUMP_LQ(5); DUMP_LQ(6); DUMP_LQ(7);
  DUMP_LQ(8); DUMP_LQ(9); DUMP_LQ(10); DUMP_LQ(11);
  DUMP_LQ(12); DUMP_LQ(13); DUMP_LQ(14); DUMP_LQ(15);
#undef DUMP_LQ

  std::cout << "=== SQ Entries ===\n";
#define DUMP_SQ(i) \
  if (top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__sq__DOT__entries_##i##_valid) { \
    std::cout << "  SQ[" << i << "]: robIdx=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__sq__DOT__entries_##i##_robIdx \
              << " addr_val=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__sq__DOT__entries_##i##_addr_valid \
              << " data_val=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__sq__DOT__entries_##i##_data_valid \
              << " committed=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__sq__DOT__entries_##i##_committed \
              << " paddr=0x" << std::hex << top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__sq__DOT__entries_##i##_paddr \
              << std::dec << "\n"; \
  }
  DUMP_SQ(0); DUMP_SQ(1); DUMP_SQ(2); DUMP_SQ(3);
  DUMP_SQ(4); DUMP_SQ(5); DUMP_SQ(6); DUMP_SQ(7);
  DUMP_SQ(8); DUMP_SQ(9); DUMP_SQ(10); DUMP_SQ(11);
  DUMP_SQ(12); DUMP_SQ(13); DUMP_SQ(14); DUMP_SQ(15);
#undef DUMP_SQ

  std::cout << "=== Frontend & CSR State ===\n"
            << "  BPU exact_pc=0x" << std::hex << top->rootp->ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__exact_pc
            << " s0_pc=0x" << top->rootp->ZaqalSoCTop__DOT__core__DOT__frontend__DOT__bpu__DOT__s0_pc << "\n"
            << "  ICache state=" << std::dec << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__frontend__DOT__icache__DOT__state << "\n"
            << "  IBUF head=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT__head
            << " tail=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT__tail << "\n"
            << "  CSR priv_mode=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__csr__DOT__priv_mode
            << " mepc=0x" << std::hex << top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__csr__DOT__r_mepc
            << " mcause=0x" << top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__exec__DOT__csr__DOT__r_mcause
            << std::dec << "\n";

  std::cout << "=== Dispatch Diagnostics ===\n"
            << "  disp0_valid=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT___frontend_io_dispatch_0_valid
            << " disp0_ready=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__io_dispatch_0_ready_0 << "\n"
            << "  redirect_valid=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT___exec_io_redirect_valid
            << " rat_isFull=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT___rat_io_isFull << "\n"
            << "  canAllocate: int=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT___intFreeList_io_canAllocate
            << " fp=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT___fpFreeList_io_canAllocate
            << " vec=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT___vecFreeList_io_canAllocate << "\n"
            << "  intFreeList: head=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr
            << " tail=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__tailPtr << "\n"
            << "  fpFreeList: head=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpFreeList__DOT__headPtr
            << " tail=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__fpFreeList__DOT__tailPtr << "\n"
            << "  vecFreeList: head=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__headPtr
            << " tail=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__vecFreeList__DOT__tailPtr << "\n"
            << "  rat: snptEnqPtr=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT__snptEnqPtr
            << " snptDeqPtr=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__rat__DOT__intRat__DOT__snapshots__DOT__snptDeqPtr << "\n"
            << "  rob: elementsInRob=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__elementsInRob
            << " maybeFull=" << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__maybeFull << "\n"
            << "  skids slot0_valid=["
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_0_buf__DOT__slot0_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_1_buf__DOT__slot0_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_2_buf__DOT__slot0_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_3_buf__DOT__slot0_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_4_buf__DOT__slot0_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_5_buf__DOT__slot0_valid << "]\n"
            << "  skids slot1_valid=["
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_0_buf__DOT__slot1_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_1_buf__DOT__slot1_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_2_buf__DOT__slot1_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_3_buf__DOT__slot1_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_4_buf__DOT__slot1_valid << ","
            << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__dispatch_in_buffered_5_buf__DOT__slot1_valid << "]\n"
            << "  ibuf[7]: pc=0x" << std::hex << top->rootp->ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT__buffer_7_pc
            << " inst=0x" << top->rootp->ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT__buffer_7_inst_raw
            << " is_cfi=" << std::dec << (int)top->rootp->ZaqalSoCTop__DOT__core__DOT__frontend__DOT__ibuf__DOT__buffer_7_pre_is_cfi << "\n";
}
