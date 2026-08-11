# GTKWave Tracing Guide: Speculative Rollback & Pipeline Integrity Walkthrough

This document provides a detailed, step-by-step tracing guide for the Zaqal backend simulation using GTKWave. It is based on the **Speculative Rollback Verification Program** loaded in `ICache.scala`.

---

## 1. Complete Simulation Program Code

The following instruction sequence is hardcoded inside `ICache.scala` for backend and pipeline verification:

```scala
Seq(
  "h00100093".U, // 0x00: addi x1, x0, 1       (Correct Path: Setup)
  "h00200113".U, // 0x04: addi x2, x0, 2       (Correct Path: Setup)
  "h02224333".U, // 0x08: div x6, x4, x2       (Correct Path: Setup - dependent on x4 & x2)
  "h00030463".U, // 0x0c: beq x6, x0, 8        (Branch 1: dependent on x6. Target is 0x0c + 8 = 0x14. Predicted Not-Taken)
  "h00030863".U, // 0x10: beq x6, x0, 16       (Branch 2: dependent on x6. Target is 0x10 + 16 = 0x20. Predicted Not-Taken)
  "h06400713".U, // 0x14: addi x14, x0, 100    (Target of Branch 1 - CORRECT PATH)
  "h01078813".U, // 0x18: addi x16, x15, 16    (CORRECT PATH - reads x15 to verify it is 0)
  "h0240006f".U, // 0x1c: jal x0, 36           (CORRECT PATH JAL - jumps to 0x40)
  "h03200793".U, // 0x20: addi x15, x0, 50     (Target of Branch 2 - WRONG PATH: must never execute!)
  "h0000006f".U, // 0x24: jal x0, 0            (Infinite loop halt on wrong path)
  "h00000013".U, // 0x28: nop
  "h00000013".U, // 0x2c: nop
  "h00000013".U, // 0x30: nop
  "h00000013".U, // 0x34: nop
  "h00000013".U, // 0x38: nop
  "h00000013".U, // 0x3c: nop
  "h0c878793".U, // 0x40: addi x15, x15, 200   (CORRECT PATH Section 3: reads x15, writes x15)
  "h00a78893".U, // 0x44: addi x17, x15, 10    (Reads x15, writes x17)
  "h0000006f".U  // 0x48: jal x0, 0            (CORRECT PATH HALT)
)
```

---

## 2. GTKWave Tracing Guide: Cycle-by-Cycle Analysis

### Cycle 0 to 4: Reset & Fetch Initialization
During cycles 0 through 4, the processor is held in reset. The Instruction Buffer (`IBUF`) and fetch queues clear out.
* **Key Signals**:
  * `TOP.Core.reset` = `1`
  * `TOP.Core.frontend.ibuf.head[5:0]` and `tail[5:0]` reset to `0`.

---

### Cycle 5: Dispatching the First ALU Packet (`x00` and `x02`)
The first instruction packet is fetched and dispatched.
* **Rename & Free List allocation in Backend.scala**:
  `intFreeList.io.allocateReq(i) := rf_wen && io.dispatch(i).valid`
  `decoded_uops(i).pdest := intFreeList.io.allocatePhyReg(i)`

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
   * `TOP.Core.backend.dispatch.io_aluOut_2_valid` to `io_aluOut_5_valid` = `0` (throttled to 2-wide dispatch)
4. **Issue Queue Enqueue & Priority Encoder (`alloc_idx`)**:
   * `TOP.Core.backend.intIq.io_enq_0_valid` = `1`
   * `TOP.Core.backend.intIq.io_enq_1_valid` = `1`
   * **Priority Encoder signals**:
     * `TOP.Core.backend.intIq.alloc_idx_0[3:0]` = `0` (allocates `entries_0` for PC `x00`)
     * `TOP.Core.backend.intIq.alloc_idx_1[3:0]` = `1` (allocates `entries_1` for PC `x02` shadow)

---

### Cycle 6: Immediate Dequeue and Dispatching `x04` & `x06`
* **Queue State**:
  * `TOP.Core.backend.intIq.entries_0_valid` = `1`, `entries_0_uop_uop_pc[63:0]` = `0000000080000000` (`x00`)
  * `TOP.Core.backend.intIq.entries_1_valid` = `1`, `entries_1_uop_uop_pc[63:0]` = `0000000080000002` (`x02` shadow)
* **Issue/Deq execution**:
  * Since `entries_0_rs1_ready` and `entries_0_rs2_ready` are `1` (mapped to physical register 0/ready), `can_issue(0)` is true.
  * `TOP.Core.backend.intIq.io_deq_0_valid` = `1` (issues `x00` to `alu_0`)
  * `TOP.Core.backend.intIq.io_deq_1_valid` = `1` (issues `x02` to `alu_1`)
  * Observe `entries_0_valid` and `entries_1_valid` drop back to `0` at the next clock edge.
* **ALU to Register File Writeback**:
  * **Register File Read**: The execution stage reads physical source register 0:
    * `TOP.Core.backend.exec.regFile.io_raddr_0` = `0`
  * **ALU Calculation**: `alu(0)` computes the immediate addition:
    * `TOP.Core.backend.exec.alu_0.io_src1` = `0`
    * `TOP.Core.backend.exec.alu_0.io_src2` = `1`
    * `TOP.Core.backend.exec.alu_0.io_result` = `1`
  * **Register File Write**: Write enable is asserted to write the ALU result to physical destination register `32`:
    * `TOP.Core.backend.exec.regFile.io_wen_0` = `1`
    * `TOP.Core.backend.exec.regFile.io_waddr_0` = `32` (pdest of `x00`)
    * `TOP.Core.backend.exec.regFile.io_wdata_0` = `1`
  * **Wakeup Broadcast**: The completion is broadcast on the wakeup bus in Cycle 7:
    * `TOP.Core.backend.exec.io_wakeup_0_valid` = `1`
    * `TOP.Core.backend.exec.io_wakeup_0_pdest` = `32`
* **Incoming Dispatch (`x04` & shadow `x06`)**:
  * `TOP.Core.backend.dispatch.io_in_0_bits_pdest[7:0]` = `33` (allocated for `x2` of `x04`)
  * `TOP.Core.backend.intIq.alloc_idx_0[3:0]` = `0` (routes `x04` to `entries_0` again since it cleared)
  * `TOP.Core.backend.intIq.alloc_idx_1[3:0]` = `1` (routes `x06` to `entries_1`)

---

### Cycle 7: Dispatching the Multi-Cycle Division (`x08` and `x0a`)
PC `x08` (`div x6, x4, x2`) enters the pipeline.
* **Renaming & Source Register Bypassing**:
  * `div` reads logical `x4` and `x2`.
  * `TOP.Core.backend.dispatch.io_in_0_bits_psrs1` = `0` (x4 is initialized to 0)
  * `TOP.Core.backend.dispatch.io_in_0_bits_psrs2` = `33` (mapped to `pdest` of `addi x2` from Cycle 6)
  * `pdest` allocated for `x6` = `34` (marked busy).
* **Execution Latch**:
  * `TOP.Core.backend.exec.div.io_fire` = `1`
  * `TOP.Core.backend.exec.div_rd_latch[7:0]` = `34` (latches destination tag)
  * `TOP.Core.backend.exec.div.io_ready` drops to `0` (divider is now busy executing).

---

### Cycle 8: The Dependency Stall and Dispatch of Branch 1 (`x0c`) and Branch 2 (`x10`)
PC `x0c` (Branch 1: `beq x6, x0, 8`) and PC `x10` (Branch 2: `beq x6, x0, 16`) enter the pipeline.

#### How `entries_0_rs1_ready` transitions to `0` for Branches:
1. **Busy Table Allocation (Cycle 7)**:
   When `div` (`x08`) was dispatched, physical destination register `34` was allocated. The Busy Table registered this allocation:
   * `TOP.Core.backend.busyTable.io_allocPorts_0_valid` = `1`
   * `TOP.Core.backend.busyTable.io_allocPorts_0_bits` = `34`
   * This sets the busy state for register 34: `ready_table(34) := false.B`.
2. **Busy Table Query (Cycle 8)**:
   When Branch 1 is renamed, its logical source `rs1 = x6` reads the map table and obtains physical register `34`. The backend queries the Busy Table for register 34's readiness:
   * `TOP.Core.backend.busyTable.io_readPorts_0_0_addr` = `34`
   * Because `ready_table(34)` is `false.B`, the output `TOP.Core.backend.busyTable.io_readPorts_0_0_ready` evaluates to `0`.
3. **Passing to Issue Queue**:
   This ready flag is forwarded to the Integer Issue Queue enqueue interface:
   * `TOP.Core.backend.intIq.io_rs1_ready_in_0` = `0`
4. **Capture in Queue Entry**:
   When Branch 1 is enqueued into `entries_0`, the queue registers this input:
   * `entries(0).rs1_ready := io.rs1_ready_in(0)`
   * Thus, in Cycle 9, `TOP.Core.backend.intIq.entries_0_rs1_ready` = `0`.

#### GTKWave Signals to Watch:
* **Stall inside the Queue**:
  * In Cycle 9, `TOP.Core.backend.intIq.entries_0_uop_uop_pc` = `000000008000000C`.
  * Look at `TOP.Core.backend.intIq.entries_0_rs1_ready` = `0` (waiting for `p34`).
  * `can_issue(0)` = `0`.
  * `io_deq_0_valid` remains `0`. **Entry 0 is blocked.**
  * Branch 2 (`0x10`) similarly stalls in `entries_2` waiting for `p34`.

---

### Cycle 10 to 18: Speculative Execution of Wrong Path (`x20: addi x15, x0, 50`)
Since Branch 1 and Branch 2 are stalled waiting for the divider, the frontend continues speculative fetch:
- **Cycle 8**: `0x14` (`addi x14, x0, 100`) and `0x16` (shadow) are renamed.
- **Cycle 9**: `0x18` (`addi x16, x15, 16`) and `0x1a` (shadow) are renamed.
- **Cycle 10**: `0x1c` (`jal x0, 36`) and `0x1e` (shadow) are renamed.
- **Cycle 11**: `0x20` (`addi x15, x0, 50` - wrong-path target of Branch 2) is renamed.

* **Speculative Renaming**:
  * In Cycle 11, Port 4 renames `0x20`:
    * `lrd = 15` -> `pdest = 37` (allocated for speculative `x15`)
    * `old = 15` (previous non-speculative mapping)
  * Since `0x20` does not depend on `div`, it executes speculatively in the ALU and writes `50` to physical register `p37` (Cycle 12).
  * However, `0x1c` (the `jal` instruction) is a control flow instruction. During its rename in Cycle 11, a rename checkpoint snapshot is enqueued.
  * Since `0x20` has not fired yet at Cycle 11, the rename table snapshot for `0x1c` correctly captures the state where `x15` is mapped to `p15` (value 0).

---

### Cycle 19: Divider Completion and Dual Misprediction Execution
* **Divider completes**:
  * `TOP.Core.backend.exec.div.io_done` = `1`.
  * Physical register `34` is woken up.
* **Branches Issue & Execute**:
  * Both Branch 1 (`0x0c`) and Branch 2 (`0x10`) wake up and are issued to the execution stage in the same cycle:
    - Lane 0: `0x0c` issued to `bru(0)`
    - Lane 1: `0x10` issued to `bru(1)`
  * Since `x6` is computed as `0`, both branches evaluate as Taken (mispredicted).
  * `bru(0).io.mispredict` = `1` and `bru(1).io.mispredict` = `1`.

---

### Cycle 20: Age-Based Redirection and Snapshot Rollback
* **Age-Priority Resolution**:
  * `Execute.scala` receives redirect requests from both lanes.
  * Since Branch 1 (`0x0c`) is older than Branch 2 (`0x10`), the top-level redirect selects Branch 1's target (`0x14`):
    - `TOP.Core.backend.exec.io_redirect_valid` = `1`
    - `TOP.Core.backend.exec.io_redirect_target` = `0x0000000080000014`
    - `TOP.Core.backend.exec.io_redirect_snapshotIdx` = matches the snapshot of Branch 1.
* **Rename Table Recovery**:
  * The Rename Map Table (`rat.io.redirect`) is asserted.
  * The spec table restores its state to the snapshot of Branch 1 (restoring `x15 -> p15`).
  * The Free List rolls back to reclaim physical register `37` (cancelling the speculative allocation of `0x20`).
* **Frontend Redirect**:
  * The frontend is flushed and redirected to fetch from `0x14`.

---

### Cycle 20 (End) to 21: Correct-Path Execution Section 3 (`0x40` & `0x44`)
* The frontend fetches starting from `0x14` (`addi x14, x0, 100`), `0x18` (`addi x16, x15, 16`), and `0x1c` (`jal x0, 36`).
* `0x1c` redirects the pipeline to `0x40`.
* In Cycle 20, the correct-path instructions at `0x40` (`addi x15, x15, 200`) and `0x44` (`addi x17, x15, 10`) reach the dispatch/rename stage:
  * **Port 0 (pc=0x40)**:
    * `lrs1 = 15` -> `prs1 = 15` (correctly reads the restored non-speculative register mapping which contains `0`).
    * `lrd = 15` -> `pdest = 37` (since `p37` was returned to the Free List, it is reallocated for the correct-path `x15`).
  * **Port 2 (pc=0x44)**:
    * `lrs1 = 15` -> `prs1 = 37` (correctly reads `x15` as `p37` via intra-bundle rename bypassing).
    * `lrd = 17` -> `pdest = 38`.
* When `0x40` executes, it reads `0` from `p15`, adds `200`, and writes `200` to `p37`.
* When `0x44` executes, it reads `200` from `p37`, adds `10`, and writes `210` to `p38`.

---

## 3. Register Verification & Success Criteria

### Expected Final Register State
At the end of the simulation run, the physical registers should contain the following values:

| Physical Register | Logical Register | Expected Value | Description |
|---|---|---|---|
| `p32` | `x1` | `0x0000000000000001` | Correct-path setup |
| `p33` | `x2` | `0x0000000000000002` | Correct-path setup |
| `p34` | `x6` | `0x0000000000000000` | Division result (`0 / 2`) |
| `p35` | `x14` | `0x0000000000000064` | Correct-path instruction (`100`) |
| `p36` | `x16` | `0x0000000000000010` | Correct-path instruction reading `x15` before it was modified (`0 + 16 = 16`) |
| `p37` | `x15` | `0x00000000000000c8` | Correct-path instruction after redirect (`0 + 200 = 200` = `0xc8`) |
| `p38` | `x17` | `0x00000000000000d2` | Correct-path instruction after redirect (`200 + 10 = 210` = `0xd2`) |

### Verification of Speculative Rollback Integrity
* **No Wrong-Path Contamination**: Although the speculative wrong-path instruction `0x20: addi x15, x0, 50` transiently wrote `50` into physical register `p37` before the flush, the RAT rollback correctly wiped this mapping out.
* When the correct path resumed, `0x40` correctly read `x15` as `p15` (value 0).
* Since `p37` was returned to the Free List, it was reused for the new correct-path mapping of `x15`. The new value `200` safely overwrote the stale `50` that was left in the physical register.
* The fact that `p38` holds `210` and `p36` holds `16` confirms that correct-path instructions successfully read the restored non-speculative register mappings after the pipeline flush.
