# Phase 6, Day 12: Branch Checkpointing (Implementation & Verification Plan)

## Architectural Objective
In modern high-frequency out-of-order processors like **XiangShan (Kunminghu architecture)**, branch misprediction recovery delays can severely degrade IPC if predictor states (GHR, PHR, RAS) have to be sequentially rebuilt. 

The goal of **Branch Checkpointing** is to store per-fetch packet snapshots of predictor history and Return Address Stack (RAS) pointers inside the Fetch Target Queue (**FTQ**) metadata table (`meta_storage`), enabling **1-cycle instantaneous state rollback** upon a backend redirection (`io.redirect.valid`).

---

## Technical Specifications & Current State Analysis

| Parameter / Signal | Current Implementation | Day 12 Target Specification |
| :--- | :--- | :--- |
| **GHR Snapshot** | 128-bit GHR stored in `BPUMetaEntry` | Verified 1-cycle restoration + non-speculative shift propagation for in-flight slots |
| **PHR Snapshot** | 32-bit PHR stored in `BPUMetaEntry` | Verified 1-cycle restoration on JALR mispredicts |
| **RAS (Return Address Stack)** | Functional 16-entry RAS (`RAS.scala` - Day 10) | Speculative push/pop on fetch + 1-cycle `sp` and top-of-stack restoration |
| **FTQ Recovery Pointers** | `enqPtr` updated on `io.redirect.valid` | Synchronized 1-cycle atomic rollback of `enqPtr`, `deqPtr`, and `bpu_enq_ptr` |
| **Epoch Toggle** | 1-bit boolean flip on redirect | Immediate invalidation of wrong-path instructions in SkidBuffer / IBUF |

---

## Step-by-Step Implementation Plan

### Step 1: Speculative RAS Module Integration Checkpoint (`RAS.scala`)
- Utilize the 16-entry RAS hardware built in Day 10, connecting `restore_sp` and `restore_top` ports directly to FTQ snapshot outputs.

### Step 2: Metadata Extension (`BPU.scala`)
- Expand `BPUMetaEntry` to encapsulate RAS stack pointers and top targets:
  ```scala
  class BPUMetaEntry(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
    val ghr              = UInt(128.W)
    val phr              = UInt(32.W)
    val ras_sp           = UInt(4.W)       // Snapshot of 16-entry RAS Stack Pointer
    val ras_top          = UInt(xLen.W)    // Snapshot of RAS Top-of-Stack Target
    val ghr_spec_shifted = Bool()
    // TAGE & ITTAGE & SC Metadata ...
  }
  ```

### Step 3: Speculative RAS Push/Pop & Checkpoint Storage (`BPU.scala`)
- During fetch lookup (`s0_pc`), evaluate predecoder CFI hints:
  - If instruction is a function call (`JAL`/`JALR` targeting link register `x1`/`x5`), speculatively push target return address to RAS.
  - If instruction is a function return (`JALR` with `rs1 = x1/x5`), speculatively pop RAS target for branch target prediction.
- **Snapshot Capture**: Store current `ras_sp` and `ras_top` into `meta_storage(bpu_enq_ptr)` alongside GHR/PHR when `io.out.fire` is true.

### Step 4: 1-Cycle Single-Clock Rollback Engine (`BPU.scala` & `FTQ.scala`)
- Connect `io.redirect.valid` from Backend (BRU mispredict / exception) to restore predictor state in a single clock cycle.
- **Rollback Sequence (Cycle N -> N+1)**:
  1. `ghr` <= `Mux(is_cond_redirect, Cat(redirect_meta.ghr(126, 0), io.redirect.taken), redirect_meta.ghr)`
  2. `phr` <= `Mux(is_jalr, Cat(redirect_meta.phr(25, 0), io.redirect.target(7, 2)), redirect_meta.phr)`
  3. `ras.sp` <= `redirect_meta.ras_sp`
  4. `ftq.enqPtr` <= `io.redirect.ftqPtr + 1.U`
  5. `ftq.deqPtr` <= `io.redirect.ftqPtr + 1.U`
  6. `epoch` <= `~epoch` (instantaneous downstream invalidation)

---

## Comprehensive Verification Plan

### 1. Unit Test Suite (`zaqal/test/src/zaqal/BranchCheckpointTest.scala`)
We will construct dedicated ChiselSim unit tests to validate 1-cycle checkpoint restoration:

- **Test Scenario A: Basic Conditional Misprediction**
  - Fetch sequence of 4 conditional branches.
  - Predict taken for branch 2; backend resolves branch 2 as **NOT TAKEN**.
  - Assert that on cycle $N+1$, `ghr` equals `redirect_meta.ghr` with bit 0 set to 0.
  - Assert `ftq.enqPtr` instantly rolls back to `redirect.ftqPtr + 1`.

- **Test Scenario B: Speculative RAS Rollback on Wrong-Path Call**
  - Execute main code -> Call Subroutine A -> Speculative wrong-path Call Subroutine B.
  - Misprediction detected on wrong-path branch inside Subroutine B.
  - Assert that after 1-cycle redirection, RAS stack pointer `sp` and top target `ras_top` roll back to the state of Subroutine A without corrupting the return stack.

- **Test Scenario C: High-Frequency Back-to-Back Redirects**
  - Trigger consecutive mispredictions in back-to-back cycles to verify setup/hold and register update stability.

### 2. Waveform & Signal Observability (GTKWave Verification)
Key signals to log in `Full_Pipeline_Trace.gtkw`:
- `TOP.Core.frontend.bpu.io_redirect_valid`
- `TOP.Core.frontend.bpu.io_redirect_bits_ftqPtr`
- `TOP.Core.frontend.bpu.ghr`
- `TOP.Core.frontend.bpu.phr`
- `TOP.Core.frontend.bpu.ras.sp`
- `TOP.Core.frontend.ftq.enqPtr`
- `TOP.Core.frontend.ftq.deqPtr`
- `TOP.Core.frontend.ftq.occupancy`
