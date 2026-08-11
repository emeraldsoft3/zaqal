# Zaqal 6-Wide Superscalar Pipeline Execution & Recovery Walkthrough

This document explains the architectural concepts of the Zaqal out-of-order backend and traces the execution of the stress-test program cycle-by-cycle, explaining snapshots, issue queues, execute units, and register renaming.

---

## 1. Zaqal Backend Architectural Concepts

### A. Rename & Dispatch
When instructions exit the instruction buffer (IBuffer), they enter the **Rename Table (RAT)**:
1. **Logical to Physical Map**: Architectural registers (`x0-x31`) are mapped to physical registers (`p0-p63`).
2. **Free List**: A FIFO of unused physical registers. A destination register `rd` is allocated a new physical register (`pdest`) from the free list, and the old mapping (`old_pdest`) is saved for rollback/retirement.
3. **Speculative Snapshots**: For every branch or control-flow instruction (CFI) that depends on register values, we take a copy (snapshot) of the entire RAT mapping. Zaqal supports up to 16 active snapshots.

### B. Issue Queue (IQ)
The issue queue holds instructions until their source operands are ready:
1. **Payload Storage**: Stows renamed instructions, their source physical register tags (`psrs1`, `psrs2`), ready flags, and their associated `snapshotIdx`.
2. **Wakeup Logic**: When a functional unit executes and completes an instruction, it broadcasts the destination physical register tag. Any queue entry waiting for this register updates its source ready flag.
3. **Issue Logic (Age-Based)**: An `AgeDetector` inspects all ready entries in the queue and selects the oldest ready instructions to issue to the execution stage (`deq(0)` and `deq(1)`).
4. **Selective Invalidation (Flush)**:
   - When a branch mispredicts, the backend broadcasts a redirect valid command along with the `restore_idx` (the branch's snapshot index).
   - The issue queue compares each entry's `uop_snapshotIdx` with the `restore_idx` relative to the current snapshot enqueue pointer (`enq_ptr`).
   - If an entry's snapshot is younger than the `restore_idx`, its valid bit is cleared to `0` (flushed). Independent or older instructions remain untouched.

---

## 2. Step-by-Step Program Execution Trace

### The Stress-Test Program Structure
```lispy
0x00 - 0x1c: Initial register setup (x2 = 2, x3 = 2, x4 = 4, x5 = 4)
0x20: nop
0x24: beq x2, x3, 92  // Branch 1 (targets 0x80, predicted NOT-taken, actual TAKEN)
0x28: addi x15, x0, 100 // Slot 4: Incorrect BPU branch slot target (predicted taken to 0xC0)
0x2c: addi x16, x0, 200 // Masked out by BPU
0x30: bne x4, x5, 144   // Masked out by BPU (Branch 2)
0x80: addi x20, x0, 999 // Correct path target of Branch 1
0xC0: addi x17, x0, 300 // Correct path target of Branch 2 (Wrong path of Branch 1)
```

### Cycle-by-Cycle Execution and Analysis

#### Phase 1: Fetch and IBuffer Processing
1. The BPU predicts for the block starting at `0x20` (`s0_pc === 0x80000020`):
   - `meta.taken := true`
   - `meta.slot := 4.U` (corresponding to slot 4, which aligns with PC `0x28`).
   - `meta.target := 0x800000C0`.
2. Because of this prediction:
   - The instructions fetched in the `0x20` bundle are valid up to slot 4 (`0x28`).
   - Slot 5 and onwards are **masked out** by the taken prediction. Thus, PC `0x2c` (`addi x16`) and PC `0x30` (Branch 2) are **never fetched or processed**.
   - The frontend immediately redirects fetching to the target `0x800000C0`.
3. The IBuffer contains the merged sequence:
   - `0x20` (NOP)
   - `0x24` (Branch 1)
   - `0x28` (`addi x15, x0, 100`)
   - `0xC0` (`addi x17, x0, 300`)
   - `0xC4` (`addi x18, x0, 400`)

#### Phase 2: Rename and Dispatch (Cycles 13-14)
- **Cycle 13**:
  - The Rename Table processes the instructions.
  - PC `0x24` (Branch 1) is recognized as a branch, allocating snapshot index `S` (e.g., `S = 2`).
  - PC `0x28` (`addi x15, x0, 100`) is younger than Branch 1 in the dispatch bundle, so it is assigned `snapshotIdx := S + 1` (speculative).
  - Register `x15` is mapped to physical register `p38`.
- **Cycle 14**:
  - PC `0xC0` (`addi x17, x0, 300`) is renamed. It inherits `snapshotIdx := S + 1` (or younger) and maps to `p39`.
  - PC `0xC4` (`addi x18, x0, 400`) is renamed and maps to `p40`.
  - All these instructions are dispatched into the issue queues.

#### Phase 3: Speculative Execution (Cycles 15-18)
- Speculative instructions issue out-of-order as their operands are ready:
  - `addi x15, x0, 100` executes on Lane 1 and writes `100` into `p38`.
  - `addi x17` and `addi x18` execute and write `300` and `400` to `p39` and `p40`.
- **Why `bru_1_io_mispredict` goes high:**
  - When the `addi x15, x0, 100` instruction at PC `0x28` executes on Lane 1, `bru(1)` receives its inputs.
  - In `BPU.scala`, PC `0x28` was slot 4, which had `is_predicted_taken = true` set by the frontend.
  - In `BRU.scala`, the logic `io.mispredict := (actual_taken =/= io.pred_taken) || (io.pred_taken && !is_cfi)` evaluates to `true` because `pred_taken = 1` and `is_cfi = 0`.
  - Thus, `bru_1_io_mispredict` asserts high at Cycle 18.
- **Why `lane0_is_older` never rises:**
  - The instruction at `0x28` is not an actual branch. When it was renamed, **no branch snapshot was allocated for it**.
  - In the execute stage, `r1_valid` is gated by `io.snptValids(r1_snap)`. Because `r1_snap` (snapshot `S+1`) is invalid in `snptValids`, `r1_valid` evaluates to `false`.
  - Since `r1_valid` is `false` and only `r0_valid` (for PC `0x24` Branch 1) is `true`, the execute stage selects the `.elsewhen(r0_valid)` path.
  - Because `r0_valid && r1_valid` is never satisfied, the prioritization branch containing `lane0_is_older` is skipped. This is the correct design behavior.

#### Phase 4: Resolution, Rollback, and Overwriting (Cycles 20-22)
1. **Branch 1 Resolves**:
   - Branch 1 (`beq x2, x3`) at PC `0x24` executes on Lane 0.
   - It is actually taken, but was predicted NOT-taken. Thus, `bru_0_io_mispredict` asserts.
   - Since its snapshot `S` is valid in `snptValids`, `r0_valid` evaluates to `true`.
   - The execute stage issues a redirect to `0x80000080` with snapshot `S`.
2. **Rename Rollback**:
   - The Rename Table rolls back its map using the checkpoint snapshot `S`.
   - Physical register `p38` (previously allocated to `x15`) is returned to the free list.
   - Register `x15` is reverted to its pre-branch physical register mapping (`p15`), restoring its value to `0`.
3. **Selective IQ Flush**:
   - The issue queue invalidates all entries with `snapshotIdx > S` (which flushes `addi x16` and any other wrong-path instructions).
4. **Correct-Path Execution**:
   - Fetching resumes at `0x80000080`.
   - PC `0x80` (`addi x20, x0, 999`) is renamed and allocated physical register `p38` (now free).
   - It executes and writes `999` into `p38`.
   - This explains why `p38` was initially written with `100` (speculatively) and then overwritten with `999` (correct path).

---

## 3. GTKWave Signal Guide: Backtracing a Register Commit (e.g., x2 = 2 mapped to p32)

To trace how a logical register commit is executed and tracked in GTKWave (using the example of `addi x2, x0, 2` mapping to physical register `p32` and committing the value `2` at Cycle 7), monitor the following signals across the pipeline stages.

### A. Rename Stage (Logical-to-Physical Mapping)
The mapping of logical registers to physical registers is managed entirely in the **Rename Table (RAT)** (`intRat`). The ALUs and subsequent stages do not know about logical registers; they only work with physical register indices.

To see how logical register `x2` is mapped to physical register `p32`:
* **Logical Register Address Port 2**: `TOP.Core.backend.rat.intRat.io_renamePorts_2_addr[4:0]` (will show `2` for `x2`)
* **Allocated Physical Register Data**: `TOP.Core.backend.rat.intRat.io_renamePorts_2_data[7:0]` (will show `32` / `0x20` for `p32`)
* **Rename Write Enable**: `TOP.Core.backend.rat.intRat.io_renamePorts_2_wen` (asserts `1` to commit the new mapping to the table)
* **Speculative Renaming Table Output**: `TOP.Core.backend.rat.intRat.curr_spec_table_1_2[7:0]` (shows that logical `x2` at the second instruction slot of the current rename bundle has been speculatively mapped to physical register `32`).

Once renamed, the logical name `x2` is discarded. The instruction is packed into a renamed Micro-Op (`uop`) containing physical register tags (`prs1`, `prs2`, `pdest = 32`) and sent to the **Issue Queue (IQ)**.

### B. Issue & Register Read Stage
The Issue Queue waits until the physical source registers are marked ready (via the Wakeup Bus). Once ready, the instruction is issued to the execution unit.
* **Operand Values**: The scheduler reads the operand values from the Physical Register File (`RegFile`) using the physical source register tags as addresses.
* **Bypass/Wakeup Tracking**: The IQ monitors the wakeup bus (`TOP.Core.backend.exec.wakeup`) to wake up dependent instructions waiting for physical register tags.

#### GTKWave Signals to Watch (Issue Queue to ALU):
* **Port 0 Handshake (ALU 0)**:
  * `TOP.Core.backend.intIq.io_deq_0_valid`: Dequeue valid (asserts high when an instruction is issued to ALU 0).
  * `TOP.Core.backend.intIq.io_deq_0_ready`: Dequeue ready.
* **Port 0 Payload (ALU 0)**:
  * `TOP.Core.backend.intIq.io_deq_0_bits_uop_pc[63:0]`: Program Counter of the issuing instruction.
  * `TOP.Core.backend.intIq.io_deq_0_bits_uop_inst_raw[31:0]`: Raw 32-bit instruction bits (e.g. `0x00210113` for `addi x2, x2, 2`).
  * `TOP.Core.backend.intIq.io_deq_0_bits_psrs1[7:0]` / `io_deq_0_bits_psrs2[7:0]`: Physical source register tags.
  * `TOP.Core.backend.intIq.io_deq_0_bits_pdest[7:0]`: Allocated physical destination register tag (e.g. `32` / `33`).
* **Port 1 Handshake & Payload (ALU 1)**:
  * `TOP.Core.backend.intIq.io_deq_1_valid`, `TOP.Core.backend.intIq.io_deq_1_ready`.
  * `TOP.Core.backend.intIq.io_deq_1_bits_uop_pc[63:0]`, `TOP.Core.backend.intIq.io_deq_1_bits_uop_inst_raw[31:0]`.
  * `TOP.Core.backend.intIq.io_deq_1_bits_psrs1[7:0]` / `io_deq_1_bits_psrs2[7:0]`.
  * `TOP.Core.backend.intIq.io_deq_1_bits_pdest[7:0]`.

> [!NOTE]
> **Optimized/Pruned Signals**: Unused signals in the execution block (e.g. `inst_raw` which is already decoded in the rename stage and not read by the ALU, or specific decode flags like `is_sraw` when not active) are often optimized away/pruned by FIRRTL/Verilator during compilation. Hence, `io_deq_1_bits_uop_inst_raw` may not appear in the waveforms.

### C. Execution Stage (ALU Computation)
The ALU receives the raw 64-bit operand values and the physical destination tag (`pdest`). The ALU is a pure combinational block and does not access the RAT.
* **ALU Inputs**:
  * `TOP.Core.backend.exec.alu_0.io_src1[63:0]`: The first operand value (e.g., `0`).
  * `TOP.Core.backend.exec.alu_0.io_src2[63:0]`: The immediate value (e.g., `2`).
  * `TOP.Core.backend.exec.alu_0.io_dec_is_addi`: Controls the ALU operation (asserts `1`).
* **Adder/ALU Output**:
  * `TOP.Core.backend.exec.alu_0.io_result[63:0]` (or `TOP.Core.backend.exec.alu_0.adder_io_result[63:0]`): Evaluates to the sum `2`.

The physical destination tag `pdest = 32` is pipelined alongside the ALU computation to direct the writeback.

### D. Writeback / Physical Register Write Stage
At the writeback stage of execution, the result computed by the ALU is written into the Physical Register File (`RegFile`) at index `32`.
To confirm that the value `2` is written into physical register `p32`, watch the writeback ports of the RegFile:
* **Write Enable**: `TOP.Core.backend.exec.regFile.io_wen_0` (or `io_wen_1` if executed on ALU 1) asserts `1`.
* **Write Address**: `TOP.Core.backend.exec.regFile.io_waddr_0[6:0]` (or `io_waddr_1[6:0]`) shows `32` (`0x20` in hex).
* **Write Data**: `TOP.Core.backend.exec.regFile.io_wdata_0[63:0]` (or `io_wdata_1[63:0]`) shows `2`.

### E. Trace Backwards: Issue Queue Scheduling and Physical Tag Generation
If you trace the signals one step backward from the execution and writeback stages:

1. **Where does `waddr` / `pdest` come from, and is there anything in between?**
   - The write address `regFile.io.waddr(0)` is tied **directly** via a wire to the Issue Queue dequeue port, with absolutely no logic or register stages in between.
   - Specifically:
     * In `Backend.scala`, the Issue Queue dequeue port is connected directly to the Execution port:
       ```scala
       exec.io.int_in(0) <> intIq.io.deq(0)
       ```
     * In `Execute.scala`, that port's `pdest` field is connected directly to the physical register file's write address:
       ```scala
       regFile.io.waddr(0) := io.int_in(0).bits.pdest
       ```
   - Therefore, `regFile.io.waddr(0)` is just a wire alias of `intIq.io.deq(0).bits.pdest` (which is `TOP.Core.backend.intIq.io_deq_0_bits_pdest[7:0]`).

2. **How is `TOP.Core.backend.intIq.io_deq_0_bits_pdest[7:0]` calculated?**
   - It is allocated dynamically in the Rename stage of the backend (`Backend.scala`):
     * The decoder determines if the instruction writes to a register (`rf_wen` is high).
     * If true, it requests a free physical register from the **Integer Free List** module (`intFreeList`):
       ```scala
       intFreeList.io.allocateReq(i) := rf_wen && io.dispatch(i).valid
       ```
     * The Free List allocator responds with the next available physical register index:
       ```scala
       decoded_uops(i).pdest := MuxCase(0.U, Seq(
         intFreeList.io.allocateReq(i) -> intFreeList.io.allocatePhyReg(i),
         // ...
       ))
       ```
     * In our cycle trace, the Free List popped index `32`, so `decoded_uops(i).pdest` became `32`.
     * This renamed instruction payload is then dispatched, enqueued into the Issue Queue, and eventually dequeued onto `io_deq_0_bits_pdest`.

3. **How are the Issue Queue outputs split between the Register File and the ALU?**
   - The Issue Queue output (`intIq.io.deq(0)` / `io.int_in(0)`) splits its fields to coordinate both register reading and ALU execution:
     * **To the Register File (Read Address)**: The source physical tags `psrs1` and `psrs2` are routed to the register file's read addresses to fetch the actual data values:
       ```scala
       regFile.io.raddr(0) := io.int_in(0).bits.psrs1
       regFile.io.raddr(1) := io.int_in(0).bits.psrs2
       ```
     * **To the ALU (Computation)**: The ALU receives the fetched 64-bit source values (or bypassed results) and the decode signals (like `is_addi`):
       ```scala
       alu(0).io.src1 := src1_val
       alu(0).io.src2 := src2_val // Muxed between regFile.io.rdata(1) and immediate
       alu(0).io.dec  := dec0
       ```
     * **To the Register File (Write Tag & Data)**: 
       - The destination physical tag `pdest` bypasses the ALU entirely and goes directly to the register file's write address: `regFile.io.waddr(0) := io.int_in(0).bits.pdest`.
       - The ALU's result output is routed to the register file's write data input: `regFile.io.wdata(0) := result`.

4. **How is the choice between ALU 0 and ALU 1 decided?**
   - The Issue Queue contains a dual-issue interface `io.deq(0)` (which drives ALU 0) and `io.deq(1)` (which drives ALU 1).
   - The routing decision is made dynamically each cycle by the **AgeDetector** module:
     - **ALU 0 (`deq(0)`) Selection**: The Issue Queue calculates a bitmask of all queue entries that are valid and have their source operands ready (`can_issue`). It queries the `AgeDetector` with this mask. The `AgeDetector` uses its internal `age(i)(j)` priority matrix (which tracks which instruction enqueued earlier) to find the **oldest ready instruction** and issues it to `deq(0)` (ALU 0).
     - **ALU 1 (`deq(1)`) Selection**: The Issue Queue masks out the instruction issued to ALU 0 (clearing its bit in `current_can_issue`), and queries the `AgeDetector` a second time. The `AgeDetector` selects the **second-oldest ready instruction** to issue to `deq(1)` (ALU 1).
