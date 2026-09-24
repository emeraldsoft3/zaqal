# Phase 11: Subsystem Unit & Integration Verification

The goal of this phase is rigorous, exhaustive verification of every hardware module both in complete isolation and in full subsystem integration, prior to final SoC integration and silicon tapeout.

## Verification Philosophy: "Isolate First, Combine Second"
Before subjecting the core to millions of random instructions in full-system Difftest, every submodule must pass dedicated unit testbenches with feature-isolation knobs (e.g. disabling all other branch predictors to verify TAGE alone).

---

## Day 1-3: Branch Prediction Unit (BPU) Isolation Matrix
- [ ] **RAS Standalone Verification**:
  - Test deep recursive function calls and returns (depth > 64) with `x1`/`x5` link registers.
  - Verify 1-cycle architectural recovery on speculative branch misprediction rollbacks.
- [ ] **uFTB & FTB Zero-Bubble Target Verification**:
  - Disable TAGE, ITTAGE, and SC.
  - Verify Stage-0 zero-bubble branch target prediction and FTQ pointer enqueue/dequeue.
- [ ] **TAGE Geometric History Verification**:
  - Disable RAS, ITTAGE, and SC.
  - Verify tagged geometric history tables across correlated loop benchmarks (nested loops, alternating branches).
- [ ] **ITTAGE Indirect Target Predictor**:
  - Verify polymorphic function calls, switch-case dispatch tables, and virtual method calls.
- [ ] **Statistical Corrector (SC) Bias Verification**:
  - Test low-confidence TAGE branch corrections against learned weight tables.
- [ ] **Full BPU Stack Co-Verification**:
  - Enable all predictors simultaneously under branch thrashing and misprediction storms to verify GHR/PHR consistency.

---

## Day 4-6: Backend & Register Renaming Stress Suite
- [ ] **FreeList Saturation & Circular Wrap**:
  - Inject 160+ continuous destination register instructions to force FreeList depletion.
  - Verify pipeline backpressure (decode stall) and immediate allocation recovery upon ROB retirement.
- [ ] **Rename Alias Table (RAT) Fast Mux1H Checkpoints**:
  - Stress deep speculative branches (up to maximum snapshot count).
  - Verify 1-cycle restoration using the one-hot multiplexers (`Mux1H`) and assert zero false dependencies (WAR/WAW).
- [ ] **Physical Register File (PRF) Multi-Port Collision**:
  - Concurrently assert all 11 integer and 8 floating-point write ports.
  - Verify write-priority resolution, Register Cache (RC) updates, and read-port integrity.

---

## Day 7-9: Issue Queues & Execution Engines
- [ ] **Wakeup CAM & Ready-Bit Propagation**:
  - Test variable-latency producers (single-cycle ALU, 3-cycle pipelined multiplier, iterative divider).
  - Verify instructions wake up and issue on the exact cycle their operand lands in the bypass network.
- [ ] **Age-Based Arbitration & Multi-Issue Stress**:
  - Fill all Issue Queue slots and verify oldest-first selection across all 4 ALUs, 2 BRUs, 2 MDUs, and 4 FPUs.
  - Verify no younger ready instruction starves an older ready instruction.
- [ ] **Segmented Bypass Network Stress**:
  - Exercise full back-to-back chaining across all 15 functional units, verifying 0-cycle intra-cluster express lanes and 1-cycle cross-cluster paths.

---

## Day 10-12: Memory Subsystem & LSQ Verification
- [ ] **Tree-Based Store-to-Load Forwarding (STLF)**:
  - Test exact byte/word/double-word address matches between younger loads and older stores.
  - Test non-matching address bypasses and partial word overlapping.
  - Verify the binary tournament reduction tree picks the youngest matching store without circular pointer errors.
- [ ] **Speculative Load Disambiguation & Violation Recovery**:
  - Force a younger load to execute before an older store address is known; upon store address resolution matching the load, verify ROB flushes and replays cleanly.
- [ ] **Prefetch Coordinator Dynamic Throttling**:
  - Test Stride, SMS, and FDP prefetchers independently against known memory access patterns.
  - Stress the memory bus with high demand load traffic; verify the Coordinator throttles prefetch requests through RED (freeze), YELLOW (route to L2), and GREEN (L1-D warming) states.

---

## Day 13-15: Privileged Architecture, MMU & Traps
- [ ] **Sv39 Page Table Walker & TLB Shootdowns**:
  - Test 3-level page table traversals (4KB, 2MB, 1GB superpages).
  - Verify TLB invalidations upon `sfence.vma` execution.
- [ ] **Precise Trap & Exception Recovery**:
  - Test page faults, illegal instructions, environment calls (`ecall`), and timer interrupts.
  - Verify ROB flushes younger instructions, architectural registers preserve precise state, and execution restarts cleanly at the trap vector.

---

## Day 16-18: Vector ISA & Multi-Core Coherence
- [ ] **Vector Unit Chaining & Masking**:
  - Test RVV 1.0 vector length (`vsetvli`), stride, and indexed memory operations.
  - Verify vector register renaming and element-level forwarding.
- [ ] **Litmus Testing for Weak Memory Ordering (RVWMO)**:
  - Run standard litmus test suites (Message Passing, Store Buffering, Read-after-Write races).
  - Verify TileLink/CHI cache coherence invalidation probes (MESI) across multiple harts.
