# Phase 6, Day 10: Return Address Stack (RAS) (Implementation & Verification Plan)

## Architectural Objective
In RISC-V architectures, procedure calls and returns use `JAL`/`JALR` instructions targeting link registers `x1` (`ra`) and `x5` (`t0` / alternate link register). Without a dedicated **Return Address Stack (RAS)**, function return targets must rely on dynamic indirect predictors (like ITTAGE) or suffer misprediction stalls.

The objective of **Day 10** is to implement a functional **16-entry speculative Return Address Stack (RAS)** in `RAS.scala` and wire it into the BPU frontend lookup pipeline, matching XiangShan Nanhu/Kunminghu BPU return prediction performance.

---

## Technical Specifications & Component Design

| Feature | Specification |
| :--- | :--- |
| **Capacity** | 16-entry circular register stack (`Vec(16, UInt(64.W))`) |
| **Stack Pointer (`sp`)** | 4-bit pointer (`UInt(4.W)`) with wraparound protection |
| **Link Register Detection** | Predecode identification of `rd == 1 \|\| rd == 5` (Call) and `rs1 == 1 \|\| rs1 == 5` (Return) |
| **Lookup Latency** | Single-cycle parallel lookup at stage `s0`/`s1` during BPU fetch |
| **Interface** | `push(pc)`, `pop()`, `top` output, `sp` snapshot & restore |

---

## Step-by-Step Implementation Plan

### Step 1: Upgrade `RAS.scala` Hardware Submodule
- Replace the dummy module in `RAS.scala` with a 16-entry hardware stack:
  ```scala
  class RAS(implicit val p: Parameters) extends Module with HasZaqalParameter {
    val io = IO(new Bundle {
      val push_valid = Input(Bool())
      val push_addr  = Input(UInt(xLen.W))
      val pop_valid  = Input(Bool())
      val pop_addr   = Output(UInt(xLen.W))
      val pop_valid_out = Output(Bool())
      val sp         = Output(UInt(4.W))
      val restore_sp = Input(UInt(4.W))
      val restore_en = Input(Bool())
    })

    val stack = RegInit(VecInit(Seq.fill(16)(0.U(xLen.W))))
    val sp    = RegInit(0.U(4.W))

    when(io.restore_en) {
      sp := io.restore_sp
    } .elsewhen(io.push_valid && !io.pop_valid) {
      stack(sp) := io.push_addr
      sp := sp + 1.U
    } .elsewhen(io.pop_valid && !io.push_valid) {
      sp := sp - 1.U
    } .elsewhen(io.push_valid && io.pop_valid) {
      stack(sp - 1.U) := io.push_addr // Simultaneous push/pop replace
    }

    io.pop_addr      := stack(sp - 1.U)
    io.pop_valid_out := sp > 0.U
    io.sp            := sp
  }
  ```

### Step 2: Integrate Predecoder Link-Register Hints
- In `Predecoder.scala`, extract call/return hints from instruction bits:
  - `is_call`: `(is_jal || is_jalr) && (rd === 1.U || rd === 5.U)`
  - `is_ret`: `is_jalr && (rs1 === 1.U || rs1 === 5.U) && (rd =/= rs1)`

### Step 3: Wire RAS into `BPU.scala` Lookup Path
- Connect `RAS` instance in `BPU.scala`:
  - When `is_call` is detected on a taken fetch packet, push `pc + 4` (or `pc + 2` for RVC).
  - When `is_ret` is detected on a return instruction, override branch prediction target with `ras.io.pop_addr`.

---

## Verification Plan

### 1. Unit Test Suite (`zaqal/test/src/zaqal/RASTest.scala`)
- **Test 1: Single Call-Return Matching**:
  - Issue `JAL x1, Subroutine` -> verify `pc + 4` pushed to RAS.
  - Issue `JALR x0, 0(x1)` -> verify RAS pops `pc + 4` as predicted target.
- **Test 2: Nested Subroutines (Depth 8)**:
  - Perform 8 nested function calls and returns, asserting exact LIFO order of returned PCs.
- **Test 3: Recursive Function Call Stack**:
  - Simulate recursive calls up to 16 levels, verifying circular wraparound stability.

### 2. Waveform Verification (GTKWave)
- `TOP.Core.frontend.bpu.ras.sp`
- `TOP.Core.frontend.bpu.ras.stack`
- `TOP.Core.frontend.bpu.final_target`
