# Phase 6, Day 11: uFTB (Micro Fetch Target Buffer) (Implementation & Verification Plan)

## Architectural Objective
In high-frequency out-of-order processors like **XiangShan (Nanhu/Kunminghu)**, main branch predictors (FTB + TAGE + SC) require 2 to 3 pipeline cycles to query large SRAM arrays. Without a Stage-0 predictor, the frontend introduces **1-cycle fetch bubbles** on every predicted taken branch.

The objective of **Day 11** is to implement the **uFTB (Micro Fetch Target Buffer)**, an ultra-low latency, 32-entry Stage-0 (`s0_uFTB`) predictor that provides zero-bubble target prediction to keep the instruction fetch stream continuously full.

---

## Component Specifications (XiangShan Parity)

| Feature | Main FTB (Stage 1) | uFTB (Stage 0 - Micro FTB) |
| :--- | :--- | :--- |
| **Capacity** | 256–1024 entries (SRAM) | 32–64 entries (CAM / Fast Flip-Flops) |
| **Latency** | 1–2 clock cycles | **0-bubble / 1-cycle (Stage 0 lookup)** |
| **Associativity** | 2-way / 4-way Set Associative | Fully Associative / Direct Mapped |
| **Target Fields** | PC, Target, Mask, BrType, Slot | PC Tag, Target, Fallthrough PC, Slot |

---

## Implementation Workflow

### Step 1: Submodule Architecture (`uFTB.scala`)
Create `uFTB.scala` under `frontend/src/zaqal/frontend/`:
```scala
package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class MicroFTBEntry(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val tag    = UInt((xLen - 4).W)
  val target = UInt(xLen.W)
  val slot   = UInt(log2Up(predictWidth).W)
  val valid  = Bool()
}

class uFTB(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val req_pc = Input(UInt(xLen.W))
    val pred_hit    = Output(Bool())
    val pred_target = Output(UInt(xLen.W))
    val pred_slot   = Output(UInt(log2Up(predictWidth).W))

    val update_valid  = Input(Bool())
    val update_pc     = Input(UInt(xLen.W))
    val update_target = Input(UInt(xLen.W))
    val update_slot   = Input(UInt(log2Up(predictWidth).W))
  })

  val entries = RegInit(VecInit(Seq.fill(32)(0.U.asTypeOf(new MicroFTBEntry))))

  val req_tag = io.req_pc(xLen - 1, 4)
  val hits    = VecInit(entries.map(e => e.valid && e.tag === req_tag))
  val hit_idx = PriorityEncoder(hits)

  io.pred_hit    := hits.reduce(_ || _)
  io.pred_target := Mux(io.pred_hit, entries(hit_idx).target, 0.U)
  io.pred_slot   := Mux(io.pred_hit, entries(hit_idx).slot, 0.U)

  val alloc_ptr = RegInit(0.U(5.W))
  when(io.update_valid) {
    entries(alloc_ptr).tag    := io.update_pc(xLen - 1, 4)
    entries(alloc_ptr).target := io.update_target
    entries(alloc_ptr).slot   := io.update_slot
    entries(alloc_ptr).valid  := true.B
    alloc_ptr := alloc_ptr + 1.U
  }
}
```

### Step 2: BPU Stage-0 Integration (`BPU.scala`)
- Query `uFTB` at `s0_pc` in parallel with main FTB/TAGE.
- If `uFTB` hits in Stage 0, immediately set `s0_pc` to `uFTB.pred_target` without waiting for Stage 1 FTB evaluation, eliminating fetch bubble latency.
- If Stage 1 FTB/TAGE disagrees with Stage 0 uFTB, override Stage 0 and update `uFTB` entry.

---

## Verification Plan

### 1. Unit Verification (`zaqal/test/src/zaqal/uFTBTest.scala`)
- **Hit Latency Test**: Verify `pred_hit` and `pred_target` are available in cycle 0.
- **Replacement Policy Test**: Verify round-robin allocation on new branch targets.

### 2. Performance Metric (IPC & Bubble Reduction)
- Measure frontend stall cycles per 1000 instructions before and after uFTB integration.
- Expectation: 15–20% reduction in fetch bubble cycles on tight loop branches.
