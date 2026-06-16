# GTKWave Tracing Guide: Dispatch to Issue Queues Walkthrough

This document provides a detailed, step-by-step tracing guide for the Zaqal backend simulation using GTKWave. It is based on the **Expanded Flush Verification Program** loaded in `ICache.scala`.

---

## 1. Complete Simulation Program Code

The following instruction sequence is hardcoded inside `ICache.scala` for backend and pipeline verification:

```scala
Seq(
  "h00108093".U, // 0x00: addi x1, x1, 1       (ALU instruction -> intIq)
  "h00210113".U, // 0x04: addi x2, x2, 2       (ALU instruction -> intIq)
  "h00318193".U, // 0x08: addi x3, x3, 3       (ALU instruction -> intIq)
  "h00420213".U, // 0x0c: addi x4, x4, 4       (ALU instruction -> intIq)
  "h00528293".U, // 0x10: addi x5, x5, 5       (ALU instruction -> intIq)
  "h02224333".U, // 0x14: div x6, x4, x2       (ALU/DIV instruction -> intIq, dependent on x4 & x2)
  "h00130393".U, // 0x18: addi x7, x6, 1       (ALU instruction -> intIq, dependent on x6)
  "h00002403".U, // 0x1c: lw x8, 0(x0)         (MEM load instruction -> memIq)
  "h00802423".U, // 0x20: sw x8, 8(x0)         (MEM store instruction -> memIq, dependent on x8)
  "h00a48493".U, // 0x24: addi x9, x9, 10      (ALU instruction -> intIq)
  "h01450513".U, // 0x28: addi x10, x10, 20    (ALU instruction -> intIq)
  "h029545b3".U, // 0x2c: div x11, x10, x9     (ALU/DIV instruction -> intIq, dependent on x10 & x9)
  "h00000663".U, // 0x30: beq x0, x0, 12       (BRU branch -> intIq, predicted Not-Taken, actually Taken to 0x3c)
  "h02114633".U, // 0x34: div x12, x2, x1      (ALU/DIV - WRONG PATH: fetched & dispatched speculative)
  "h00160693".U, // 0x38: addi x13, x12, 1     (ALU - WRONG PATH: waits in IQ and flushed)
  "h06470713".U  // 0x3c: addi x14, x14, 100   (ALU instruction -> Correct-path target after branch recovery)
)
```
---

## 2. GTKWave Tracing Guide: Cycle-by-Cycle Analysis

### Cycle 0 to 5: Reset & Fetch Initialization
During cycles 0 through 4, the processor is held in reset. The Instruction Buffer (`IBUF`) and fetch queues clear out.
* **Key Signals**:
  * `TOP.Core.reset` = `1` (Cycles 0 to 4), then goes to `0` at Cycle 5.
  * `TOP.Core.frontend.ibuf.head[5:0]` and `tail[5:0]` reset to `0`.

---

### Cycle 5: Dispatching the First ALU Bundle (`x00`)

The first instruction packet is fetched and dispatched.

```scala
// Rename & Free List allocation in Backend.scala
intFreeList.io.allocateReq(0) := rf_wen && io.dispatch(0).valid
decoded_uops(0).pdest := intFreeList.io.allocatePhyReg(0)
```

#### GTKWave Signals to Watch:
1. **Renaming & FreeList**:
   * `TOP.Core.backend.intFreeList.headPtr[5:0]` = `0` (reaches `1` at the end of the cycle)
   * `TOP.Core.backend.dispatch.io_in_0_bits_pdest[7:0]` = `32` (speculative physical register assigned to `x1`)
   * `TOP.Core.backend.rat.io_renamePorts_0_addr[4:0]` = `1` (`rd` logical register)
   * `TOP.Core.backend.rat.io_renamePorts_0_wen` = `1` (commits map update)
2. **Busy Table Allocation**:
   * `TOP.Core.backend.busyTable.io_allocPorts_0_valid` = `1`
   * `TOP.Core.backend.busyTable.io_allocPorts_0_bits[7:0]` = `32` (sets physical register 32 to busy/not ready)
3. **Dispatcher Output**:
   * `TOP.Core.backend.dispatch.io_aluOut_0_valid` = `1`
   * `TOP.Core.backend.dispatch.io_aluOut_1_valid` = `1` (shadow parcel `x02`)
   * `TOP.Core.backend.dispatch.io_aluOut_2_valid` to `io_aluOut_5_valid` = `0` (throttled)
4. **Issue Queue Enqueue & Priority Encoder (`alloc_idx`)**:
   * `TOP.Core.backend.intIq.io_enq_0_valid` = `1`
   * `TOP.Core.backend.intIq.io_enq_1_valid` = `1`
   * **Priority Encoder signals**:
     * `TOP.Core.backend.intIq.alloc_idx_0[3:0]` = `0` (allocates `entries_0` for PC `x00`)
     * `TOP.Core.backend.intIq.alloc_idx_1[3:0]` = `1` (allocates `entries_1` for PC `x02`)
     * `TOP.Core.backend.intIq.alloc_valid_0` = `1`
     * `TOP.Core.backend.intIq.alloc_valid_1` = `1`

---

### Cycle 6: Immediate Dequeue and Dispatching `x04`

#### GTKWave Signals to Watch:
1. **Queue State**:
   * `TOP.Core.backend.intIq.entries_0_valid` = `1`, `entries_0_uop_uop_pc[63:0]` = `0000000080000000` (`x00`)
   * `TOP.Core.backend.intIq.entries_1_valid` = `1`, `entries_1_uop_uop_pc[63:0]` = `0000000080000002` (`x02` shadow)
2. **Issue/Deq execution**:
   * Since `entries_0_rs1_ready` and `entries_0_rs2_ready` are `1` (mapped to physical register 0/ready), `can_issue(0)` is true.
   * `TOP.Core.backend.intIq.io_deq_0_valid` = `1` (issues `x00` to `alu_0` over `io_int_in(0)`)
   * `TOP.Core.backend.intIq.io_deq_1_valid` = `1` (issues `x02` to `alu_1` over `io_int_in(1)`)
   * Observe `entries_0_valid` and `entries_1_valid` drop back to `0` at the next clock edge.
3. **ALU to Register File Writeback**:
   * **Register File Read**: The execution stage reads physical source register 0:
     * `TOP.Core.backend.exec.regFile.io_raddr_0` = `0` (psrs1 of `x00`)
     * `TOP.Core.backend.exec.regFile.io_rdata_0` = `0`
   * **ALU Calculation**: `alu(0)` computes the immediate addition:
     * `TOP.Core.backend.exec.alu_0.io_src1` = `0`
     * `TOP.Core.backend.exec.alu_0.io_src2` = `1` (immediate)
     * `TOP.Core.backend.exec.alu_0.io_result` = `1`
   * **Register File Write**: Write enable is asserted to write the ALU result to physical destination register `32`:
     * `TOP.Core.backend.exec.regFile.io_wen_0` = `1`
     * `TOP.Core.backend.exec.regFile.io_waddr_0` = `32` (pdest of `x00`)
     * `TOP.Core.backend.exec.regFile.io_wdata_0` = `1`
     * *Note: On the next rising clock edge (Cycle 7), the register file commits physical register 32 as `1`.*
   * **Wakeup Broadcast**: The completion is broadcast on the wakeup bus in Cycle 7:
     * `TOP.Core.backend.exec.io_wakeup_0_valid` = `1`
     * `TOP.Core.backend.exec.io_wakeup_0_pdest` = `32`
4. **Incoming Dispatch (`x04` & shadow `x06`)**:
   * `TOP.Core.backend.dispatch.io_in_0_bits_pdest[7:0]` = `33` (allocated for `x2` of `x04`)
   * `TOP.Core.backend.intIq.alloc_idx_0[3:0]` = `0` (routes `x04` to `entries_0` again since it cleared)
   * `TOP.Core.backend.intIq.alloc_idx_1[3:0]` = `1` (routes `x06` to `entries_1`)

*Note: This cycle-by-cycle "ping-pong" behavior continues identically through the initialization of `addi x3` (Cycle 7), `addi x4` (Cycle 8), and `addi x5` (Cycle 9).*

---

### Cycle 10: The Dependent Multi-Cycle Division (`x14`)

PC `x14` (`div x6, x4, x2`) enters the pipeline.

```scala
// Execution block routing in Execute.scala
div.io.src1 := Mux(is_div_op0, src0_1, src1_1)
div.io.src2 := Mux(is_div_op0, src0_2, src1_2)
div.io.fire := Mux(is_div_op0, io.int_in(0).fire, io.int_in(1).fire)
```

#### GTKWave Signals to Watch:
1. **Renaming & Source Register Bypassing**:
   * `div` reads logical `x4` and `x2`.
   * Look at `TOP.Core.backend.dispatch.io_in_5_bits_psrs1` = `35` (mapped to `pdest` of `addi x4` from Cycle 8)
   * Look at `TOP.Core.backend.dispatch.io_in_5_bits_psrs2` = `33` (mapped to `pdest` of `addi x2` from Cycle 6)
   * `pdest` allocated for `x6` = `37` (marked busy).
2. **Issue Queue Wait**:
   * In Cycle 11, `div` sits in `entries_0` of `intIq`.
   * Because `p35` and `p33` have already completed and woken up in previous cycles, `entries_0_rs1_ready` = `1` and `entries_0_rs2_ready` = `1`.
   * `div` is immediately issued to the divider.
3. **Execution Latch**:
   * `TOP.Core.backend.exec.div.io_fire` = `1`
   * `TOP.Core.backend.exec.div_rd_latch[7:0]` = `37` (latches destination tag)
   * `TOP.Core.backend.exec.div.io_ready` drops to `0` (divider is now busy executing).

---

### Cycle 11: The Dependency Stall (`x18`)

The dependent instruction `x18` (`addi x7, x6, 1`) is dispatched.

#### How `entries_0_rs1_ready` transitions to `0`:
1. **Busy Table Allocation (Cycle 10)**: 
   When `div` (`x14`) is dispatched, physical destination register `37` is allocated to its output `x6`. The Busy Table registers this allocation:
   * `TOP.Core.backend.busyTable.io_allocPorts_0_valid` = `1`
   * `TOP.Core.backend.busyTable.io_allocPorts_0_bits` = `37`
   * This sets the busy state for register 37: `ready_table(37) := false.B`.
2. **Busy Table Query (Cycle 11)**:
   When `x18` is renamed, its logical source `rs1 = x6` reads the map table and obtains physical register `37`. The backend queries the Busy Table for register 37's readiness:
   * `TOP.Core.backend.busyTable.io_readPorts_0_0_addr` = `37`
   * Because `ready_table(37)` is `false.B`, the output `TOP.Core.backend.busyTable.io_readPorts_0_0_ready` evaluates to `0`.
3. **Passing to Issue Queue**:
   This ready flag is forwarded to the Integer Issue Queue enqueue interface:
   * `TOP.Core.backend.intIq.io_rs1_ready_in_0` = `0` (which is wired to `busyTable.io.readPorts(0)(0).ready`).
4. **Capture in Queue Entry**:
   When `x18` is enqueued into `entries_0`, the queue registers this input:
   * `entries(0).rs1_ready := io.rs1_ready_in(0)`
   * Thus, in Cycle 12, `TOP.Core.backend.intIq.entries_0_rs1_ready` = `0`.

#### GTKWave Signals to Watch:
1. **Dispatcher to Issue Queue**:
   * `x18` reads `x6`, which is mapped to physical register `37` (currently being calculated by the busy divider).
   * It is enqueued into `entries_0` of `intIq` (`alloc_idx_0` = `0`).
2. **Stall inside the Queue**:
   * In Cycle 12, `TOP.Core.backend.intIq.entries_0_uop_uop_pc` = `0000000080000018`.
   * Look at `TOP.Core.backend.intIq.entries_0_rs1_ready` = `0` (waiting for `p37`).
   * `can_issue(0)` = `0`.
   * `io_deq_0_valid` remains `0`. **Entry 0 is now blocked.**

---

### Cycle 12: Queue Storage Allocation Shifts (`x1C`)

With `entries_0` blocked, a memory load `x1c: lw x8, 0(x0)` is dispatched.

```scala
// Priority Encoder mask logic in IssueQueue.scala
var current_empty_mask = is_empty.asUInt
alloc_idx(e) := PriorityEncoder(current_empty_mask)
current_empty_mask = current_empty_mask & ~(UIntToOH(alloc_idx(e)))
```

#### GTKWave Signals to Watch:
1. **Routing to LSU**:
   * `lw` is a memory instruction. The dispatcher asserts `TOP.Core.backend.dispatch.io_memOut_0_valid` = `1`.
   * It is accepted by the Memory Issue Queue: `TOP.Core.backend.memIq.io_enq_0_valid` = `1`.
2. **Shadow Parcel Routing**:
   * The shadow parcel at `x1E` goes to the Integer Issue Queue on `io_enq_1_valid` = `1`.
3. **Priority Encoder Shift**:
   * Inside `intIq`, `entries_0` is occupied by the stalled `x18` instruction.
   * Look at `TOP.Core.backend.intIq.alloc_idx_1[3:0]` = `2` (assigns the shadow `x1E` to `entries_2` instead of 0 or 1, since 0 is occupied and 1 holds the shadow `x1A` which was dispatched in Cycle 11 but is stalled).
   * Confirm `TOP.Core.backend.intIq.entries_2_uop_uop_pc[63:0]` = `000000008000001E` (in Cycle 13).

---

### Cycle 13 to 77: The Multi-Cycle Execution Gap
During this window, the processor executes independent instructions (like `lw`, `sw` at `x1c`/`x20` and the ALU instructions `x24`/`x28` which populate `entries_3`, `entries_4`, etc.) while the `div` instruction at `x14` continues its computation.

* **Memory Dependency Trace**:
  * Trace the load `x1c: lw x8, 0(x0)` enqueuing into `memIq`.
  * The store `x20: sw x8, 8(x0)` has `psrs2` (the register data to store) mapped to `x8`'s `pdest`.
  * Look at `TOP.Core.backend.memIq.entries_X_rs2_ready` = `0` (stalls the store until the load completes and writes back).

---

### Cycle 78: Divider Wakeup & Stall Resolution

The divider completes its calculation, triggering a writeback and broadcast.

```scala
// Divider wakeup propagation in Execute.scala
when(div.io.done) {
  regFile.io.wen(2) := true.B
  regFile.io.waddr(2) := div_rd_latch
}
io.wakeup(2).valid := RegNext(div.io.done && div_rd_latch =/= 0.U)
io.wakeup(2).pdest := RegNext(div_rd_latch)
```

#### GTKWave Signals to Watch:
1. **Done and Wakeup**:
   * `TOP.Core.backend.exec.div.io_done` = `1`
   * `TOP.Core.backend.exec.io_wakeup_2_valid` = `1` (in Cycle 79, due to Chisel register delay)
   * `TOP.Core.backend.exec.io_wakeup_2_pdest[7:0]` = `37` (broadcasts wakeup for physical register 37)
2. **Issue Queue Match**:
   * Inside `intIq`, `entries_0` (PC `x18`) compares `entries_0_uop_psrs1` (`37`) against the wakeup bus.
   * `TOP.Core.backend.intIq.entries_0_rs1_ready` transitions from `0` to `1`.
3. **Dequeue (Issue)**:
   * `can_issue(0)` becomes `1`.
   * `TOP.Core.backend.intIq.io_deq_0_valid` goes high, finally releasing `x18` to the ALU.

---

### Cycle 82+: Branch Misprediction & Recovery (`x30` to `0x3C`)

The branch instruction `x30: beq x0, x0, 12` executes.

```scala
// Branch check in BRU.scala & IssueQueue.scala
when (io.redirect_valid) {
  for (i <- 0 until numEntries) {
    val entry_is_younger = ... // determines if entry was fetched after the branch
    when (entry_is_younger) { entries(i).valid := false.B }
  }
}
```

#### GTKWave Signals to Watch:
1. **Misprediction Trigger**:
   * The branch is executed in `bru_0` (Cycle 82). It evaluates as **Taken** to `0x3c`.
   * Look at `TOP.Core.backend.exec.bru_0_io_mispredict` = `1`
   * `TOP.Core.backend.exec.io_redirect_valid` = `1`
   * `TOP.Core.backend.exec.io_redirect_target[63:0]` = `000000008000003C`
   * `TOP.Core.backend.exec.io_redirect_snapshotIdx[2:0]` = matches the branch's snapshot index.
2. **Issue Queue Flush**:
   * Look at `TOP.Core.backend.intIq.io_redirect_valid` = `1`
   * Check the occupancy/valid signals of entries containing the wrong-path instructions (`x34: div` and `x38: addi`):
     * `TOP.Core.backend.intIq.entries_X_valid` (where `X` represents the entries holding `x34`/`x38`) drops to `0`.
3. **Speculative Map Table Rollback**:
   * `TOP.Core.backend.rat.io_redirect` = `1`
   * `TOP.Core.backend.rat.intRat.spec_table` restores the saved register mapping from the snapshot, resetting speculative destination maps back to their Cycle 82 configurations.
4. **Correct-Path Fetch**:
   * The frontend redirects fetching to PC `0x8000003C`.
   * Locate `TOP.Core.backend.dispatch.io_in_0_bits_uop_pc` = `000000008000003C` (`addi x14, x14, 100`) entering the dispatcher.

---

## 3. Regression Test: Back-to-Back Branch Mispredictions

This regression test verifies that if multiple branches are executed and mispredicted in the exact same cycle, the out-of-order execution engine respects the age-priority of the oldest branch, redirects to its correct-path target, flushes the younger branch, and rolls back the speculative register states.

### Test Program Sequence
```scala
Seq(
  "h00100093".U, // 0x00: addi x1, x0, 1
  "h00200113".U, // 0x04: addi x2, x0, 2
  "h02224333".U, // 0x08: div x6, x4, x2
  "h00030463".U, // 0x0c: beq x6, x0, 8      (Branch 1: dependent on x6. Target is 0x0c + 8 = 0x14. Predicted Not-Taken)
  "h00030863".U, // 0x10: beq x6, x0, 16     (Branch 2: dependent on x6. Target is 0x10 + 16 = 0x20. Predicted Not-Taken)
  "h06400713".U, // 0x14: addi x14, x0, 100  (Target of Branch 1 - CORRECT PATH)
  "h01000813".U, // 0x18: addi x16, x0, 16   (CORRECT PATH)
  "h0000006f".U, // 0x1c: jal x0, 0          (CORRECT PATH HALT)
  "h03200793".U, // 0x20: addi x15, x0, 50   (Target of Branch 2 - WRONG PATH: must never execute!)
  "h0000006f".U  // 0x24: jal x0, 0          (Infinite loop halt)
)
```

### Trace Walkthrough & Signals

1. **Stall on Divider**:
   * PC `0x0c` (Branch 1) and PC `0x10` (Branch 2) read `x6` (physical register `34`).
   * They enter `intIq` and stall since `ready_table(34)` is busy due to the multi-cycle `div` instruction at `0x08`.
2. **Speculative Out-of-Order Execution**:
   * During the execution of `div`, the sequential fetch path fetches the instructions at `0x14`, `0x18`, `0x1c`, and `0x20`.
   * `addi x15, x0, 50` (at `0x20`) does not depend on `div` output `x6`. It is dispatched, renamed, allocated physical register `37`, and executed out-of-order, writing `50` to `p37` speculatively.
3. **Dual Execution & Misprediction**:
   * When `div` completes, physical register `34` is woken up.
   * Both Branch 1 (`0x0c`) and Branch 2 (`0x10`) wake up and are issued to the execute stage in the **same cycle**:
     - `TOP.Core.backend.exec.io_int_in_0_fire` = `1` (Branch 1 issued to ALU 0/BRU 0)
     - `TOP.Core.backend.exec.io_int_in_1_fire` = `1` (Branch 2 issued to ALU 1/BRU 1)
   * Both evaluate as Taken, causing both `bru_0` and `bru_1` to flag mispredictions:
     - `TOP.Core.backend.exec.bru_0_io_mispredict` = `1`
     - `TOP.Core.backend.exec.bru_1_io_mispredict` = `1`
4. **Age-Based Resolution**:
   * `Execute.scala` receives redirect requests from both lanes:
     - `r0_valid` = `1` (Branch 1 mispredicted)
     - `r1_valid` = `1` (Branch 2 mispredicted)
   * It evaluates `lane0_is_older`:
     - Since Branch 1 (`0x0c`) is older than Branch 2 (`0x10`), `lane0_is_older` evaluates to `1`.
   * The top-level redirect selects Branch 1's target (`0x14`):
     - `TOP.Core.backend.exec.io_redirect_valid` = `1`
     - `TOP.Core.backend.exec.io_redirect_target` = `0x0000000080000014`
     - `TOP.Core.backend.exec.io_redirect_snapshotIdx` = matches the snapshot of Branch 1.
5. **Rename Recovery (Speculation Rollback)**:
   * The Rename Map Table restores its state to the snapshot of Branch 1.
   * This rolls back the speculative assignment of physical register `37` to logical register `x15`. Logical register `x15` is mapped back to its pre-speculative register (e.g. `p15`).
   * The Free List is rolled back to reclaim physical register `37` (among others).
6. **Correct-Path Instruction Fetch**:
   * The frontend redirects fetching to PC `0x80000014`.
   * `0x14` (`addi x14, x0, 100`) and `0x18` (`addi x16, x0, 16`) execute and commit.
   * The loop at `0x1c` (`jal x0, 0`) halts correct-path execution.

### Success vs. Failure Criteria

* **SUCCESS**:
  * `TOP.Core.backend.exec.io_redirect_target` matches Branch 1's target (`0x80000014`), NOT Branch 2's target (`0x80000020`).
  * In the final register dump:
    - `p35` (logical `x14`) = `0x0000000000000064` (100)
    - `p36` (logical `x16`) = `0x0000000000000010` (16)
    - `p15` (logical `x15`) = `0x0000000000000000` (Since Branch 1 won and flushes the speculatively executed `addi x15`, logical `x15` remains `0`!)
* **FAILURE**:
  * `TOP.Core.backend.exec.io_redirect_target` points to `0x80000020`.
  * `p35` (logical `x14`) and `p36` (logical `x16`) remain `0`, and `x15` is updated to `50` (or maps to `p37` with `50`), meaning the younger branch overrode the older one and the rollback failed.
