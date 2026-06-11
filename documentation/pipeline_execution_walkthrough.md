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
