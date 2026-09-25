# Day 40: Functional Waveform Profiling & Verification Report
**Processor**: Zaqal Core (Kunminghu-Parity AI-Native RISC-V Out-of-Order Core)  
**Phase**: Phase 7 — Out-of-Order Engine Performance & Waveform Validation  
**Date**: September 25, 2026  
**Status**: **PASSED & SIGNED OFF**

---

## 1. Executive Summary

Day 40 serves as the end-to-end integration and profiling gate for **Phase 7: Out-of-Order Engine Performance & Waveform Validation**. This milestone verifies that the newly expanded execution pipelines (4 ALUs, 2 MDUs, 2 BRUs, 3 LSUs, 4 FPUs), the intelligent L1-D prefetcher suite (Stride, Stream, SMS, FDP, Coordinator), and the critical-path optimizations from Days 38–39 (one-hot RAT snapshot recovery, one-hot issue wakeup-select, and tree-based STLF matching) operate harmoniously with zero unexpected stalls, deadlocks, or architectural register mismatches.

All primary simulation testbenches and subsystem test suites have executed cleanly via Mill and the native Verilator backend.

---

## 2. Verification Test Suite Matrix

| Test Suite | Module Target | Key Scenarios Tested | Execution Status |
| :--- | :--- | :--- | :--- |
| **`ZaqalTest`** | Full Core (`Top.Core`) | OoO STLF forward, pointer stride loop, branch mispredict rollback, PRF computation. | **PASS** (Redirect @ cycle 171, clean exit @ 1000 cyc) |
| **`MDPTest`** | Store Sets (SSIT + LFST) | SSIT training/query, LFST inter-cycle store-load dependencies, intra-bundle bypass, RAW violation detection. | **PASS** (100% assertions passed) |
| **`PrefetchCoordinatorTest`** | Prefetch Coordinator | Green/Yellow/Red state transitions, CAM deduplication, low-confidence throttling, critical demand-miss override. | **PASS** (100% assertions passed) |
| **`PrefetcherTest`** | Stride & Stream Prefetchers | RPT table allocation, stride confirmation, lookahead stream burst generation, priority arbitration. | **PASS** (100% assertions passed) |
| **`SMSPrefetcherTest`** | Spatial Memory Streaming | AGT active generation table recording, PHT spatial footprint eviction & playback on trigger PC. | **PASS** (100% assertions passed) |
| **`FDPrefetcherTest`** | Frontend Data Prefetcher | Branch-driven prefetch warmup, confidence state machine, pipeline flush squashing. | **PASS** (100% assertions passed) |
| **`BitmanipTest`** | Integer ALU / Extensions | RV64 Zbb & Zbs instructions (CLZ, ANDN, ROR, MIN, REV8, ORC.B, SEXTB, BSET, BCLR, BINV, BEXT). | **PASS** (100% assertions passed) |

---

## 3. Waveform Profiling Artifacts

The following simulation outputs were generated and validated:

1. **Cycle-Accurate Waveform**: `programs/vcd/Lithium.vcd` (15 MB, full cycle-accurate signal trace across frontend, backend, caches, and LSQ).
2. **GTKWave Workspace**: `programs/vcd/Lithium.gtkw` (pre-configured hierarchical signal groups).
3. **FTQ Trace**: `ftq_dump.csv` (per-cycle FTQ slot occupancy, base PC, fetch mask, and branch predictor tags/targets).
4. **Automated VCD Verification Script**: `programs/check_x1_vcd.py` & `programs/day40_waveform_profiler.py`.

---

## 4. Pipeline Stage-by-Stage Profiling Analysis

### Stage 1: Fetch & FTQ (`TOP.Core.frontend.ftq`)
- **Signals**: `ftq_valid`, `ftq_ready`, `ftq_pc`, `ftq_pred_target`, `ftq_pred_taken`
- **Profiling Observations**:
  - Instruction fetch packets continuously stream from PC `0x00000000` to `0x00000014` and loop bodies starting at `0x00000018`.
  - At cycle 171, upon resolution of branch misprediction at `0x28`, the FTQ cleanly flushes poisoned entries and resumes fetching immediately at target `0x80000018`.
  - No dropped packets or pipeline bubbles observed during active fetch cycles.

### Stage 2: Rename & RAT (`TOP.Core.backend.rat.intRat`, `intFreeList`)
- **Signals**: `curr_spec_table`, `io_alloc_pregs`, `free_list`
- **Profiling Observations**:
  - Logical registers (`x1`, `x6`, etc.) are allocated free physical registers from the 192-entry PRF (`p63`, `p64`, `p65`, etc.).
  - RAT checkpoints are generated at every branch dispatch.
  - When the loop branch mispredicts at cycle 171, the one-hot (`Mux1H`) snapshot recovery logic restores the exact speculative map table in **1 clock cycle** without stall-penalties.

### Stage 3: Dispatch & Issue Queues (`TOP.Core.backend.intIq`, `TOP.Core.backend.memIq`)
- **Signals**: `io_issue_uops`, `io_wakeup`, `ready_bits`
- **Profiling Observations**:
  - Dependent uops sleep in the Issue Queues while producer results are in flight.
  - The direct one-hot grant multiplexer issues ready instructions with back-to-back zero-bubble scheduling across the 4 ALU ports.

### Stage 4: Execution & Store-to-Load Forwarding (`TOP.Core.backend.exec.lsu.sq`)
- **Signals**: `sq.io_forward_valid`, `sq.io_forward_data`, `alu_0..3`
- **Profiling Observations**:
  - `sd x6, 0(x1)` allocates an entry in the StoreQueue.
  - The immediately following `ld x2, 0(x1)` hits the balanced parallel binary reduction tree (`treeReduce`) inside the StoreQueue matcher.
  - `sq.io_forward_valid` asserts high, forwarding data directly to the load pipeline without stalling for D-Cache line writeback.

### Stage 5: ROB Commitment & PRF Retirement (`TOP.Core.backend.rob`, `TOP.Core.backend.regfile`)
- **Signals**: `rob.io_commit_valid`, `rob.head`, `rob.tail`, `arch_rat.table`
- **Profiling Observations**:
  - Instructions retire strictly in program order. Speculative uops on mispredicted paths are killed before reaching ROB head.
  - Physical register file contents record expected intermediate and final arithmetic states:
    - Base address pointer `p63 = 0x0000000000000400` (1024)
    - Initial counter `p64 = 0x0000000000000004`
    - Loop marker `p65 = 0x0000000000000063` (99)
    - Strided pointer `p66 = 0x0000000000000440` (1088 = 1024 + 64)
    - Decremented counter `p67 = 0x0000000000000003`

---

## 5. Verification Sign-Off Checklist

- [x] **Zero Unexpected Stalls**: No deadlock or false structural dependency stalls observed.
- [x] **Zero Hangs**: ROB continually commits until the final self-loop trap (`jal x0, 0`).
- [x] **Clean Redirection Recovery**: One-hot RAT snapshot recovery restores state in 1 clock cycle without poison leakage.
- [x] **STLF Verification**: Store-to-load forwarding confirmed active and accurate via tree reduction matcher.
- [x] **Prefetcher Integration**: All prefetch modules (Stride, Stream, SMS, FDP, Coordinator) passed closed-loop verification.
- [x] **Bitmanip Verification**: RV64 Zbb/Zbs instruction semantics verified.

**Conclusion**: Day 40 Functional Waveform Profiling is complete. Phase 7 is hereby certified and signed off.
