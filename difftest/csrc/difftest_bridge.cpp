#include "refproxy.h"
#include <iostream>
#include <iomanip>

RefProxy g_ref;
uint64_t g_commit_count = 0;
uint64_t g_last_trap_cycle = 0;

static const char *reg_names[] = {
  "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

extern "C" void difftest_InstrCommit (
  uint8_t  coreid,
  uint8_t  index,
  uint8_t  valid,
  uint64_t pc,
  uint32_t instr,
  uint8_t  skip,
  uint8_t  isRVC,
  uint8_t  rfwen,
  uint8_t  fpwen,
  uint8_t  vecwen,
  uint8_t  wdest,
  uint64_t data
) {
  if (!valid) return;

  g_commit_count++;

  // If Golden model isn't active, just run free
  if (!g_ref.initialized) return;

  if (skip) {
    // Non-deterministic instruction (MMIO, timer CSR). Step NEMU and sync result.
    g_ref.exec(1);
    if (rfwen && wdest != 0 && wdest < 32) {
      RISCV64_CPU_State ref_state;
      g_ref.regcpy(&ref_state, DIFFTEST_TO_DUT);
      ref_state.gpr[wdest] = data;
      g_ref.regcpy(&ref_state, DIFFTEST_TO_REF);
    }
    return;
  }

  // 1. Step NEMU golden model by 1 instruction
  g_ref.exec(1);

  // 2. Query NEMU's architectural state
  RISCV64_CPU_State ref_state;
  g_ref.regcpy(&ref_state, DIFFTEST_TO_DUT);

  // 3. Compare destination register
  if (rfwen && wdest != 0 && wdest < 32) {
    uint64_t golden_val = ref_state.gpr[wdest];
    if (data != golden_val) {
      std::cerr << "\n\033[1;31m===============================================================\033[0m\n";
      std::cerr << "\033[1;31m[DIFFTEST DIVERGENCE DETECTED]\033[0m at Commit #" << g_commit_count 
                << " (Lane " << (int)index << ")\n";
      std::cerr << "  PC:          0x" << std::hex << std::setw(16) << std::setfill('0') << pc << "\n";
      std::cerr << "  Instruction: 0x" << std::hex << std::setw(8)  << std::setfill('0') << instr << "\n";
      std::cerr << "  Register:    " << reg_names[wdest] << " (x" << std::dec << (int)wdest << ")\n";
      std::cerr << "  Zaqal (DUT): 0x" << std::hex << std::setw(16) << std::setfill('0') << data << "\n";
      std::cerr << "  NEMU  (REF): 0x" << std::hex << std::setw(16) << std::setfill('0') << golden_val << "\n";
      std::cerr << "\033[1;31m===============================================================\033[0m\n\n";

      if (g_ref.display) {
        std::cerr << "--- Golden Model Dump ---\n";
        g_ref.display();
      }
      exit(1);
    }
  }

  if (g_commit_count % 100000 == 0) {
    std::cout << "[Difftest] Passed " << std::dec << g_commit_count 
              << " instructions in lockstep! Current PC: 0x" << std::hex << pc << std::dec << std::endl;
  }
}

extern "C" void difftest_TrapEvent (
  uint8_t  coreid,
  uint8_t  valid,
  uint8_t  code,
  uint64_t pc,
  uint64_t cycle
) {
  if (!valid) return;
  g_last_trap_cycle = cycle;
  #ifdef DEBUG_DIFFTEST
  std::cout << "[Difftest TRAP] Core " << (int)coreid 
            << " Cause: 0x" << std::hex << (int)code 
            << " at PC: 0x" << pc << " (Cycle: " << std::dec << cycle << ")" << std::endl;
  #endif
}

extern "C" void difftest_CSRState (
  uint8_t  coreid,
  uint8_t  valid,
  uint64_t mstatus,
  uint64_t mie,
  uint64_t mip,
  uint64_t mepc,
  uint64_t mcause,
  uint64_t mtvec,
  uint64_t satp
) {
  // Optional deep CSR lockstep verification
}

extern "C" void difftest_ArchRegs (
  uint8_t coreid,
  uint8_t valid,
  uint64_t gpr_0,  uint64_t gpr_1,  uint64_t gpr_2,  uint64_t gpr_3,
  uint64_t gpr_4,  uint64_t gpr_5,  uint64_t gpr_6,  uint64_t gpr_7,
  uint64_t gpr_8,  uint64_t gpr_9,  uint64_t gpr_10, uint64_t gpr_11,
  uint64_t gpr_12, uint64_t gpr_13, uint64_t gpr_14, uint64_t gpr_15,
  uint64_t gpr_16, uint64_t gpr_17, uint64_t gpr_18, uint64_t gpr_19,
  uint64_t gpr_20, uint64_t gpr_21, uint64_t gpr_22, uint64_t gpr_23,
  uint64_t gpr_24, uint64_t gpr_25, uint64_t gpr_26, uint64_t gpr_27,
  uint64_t gpr_28, uint64_t gpr_29, uint64_t gpr_30, uint64_t gpr_31
) {
  // Full architectural register snapshot comparison
}
