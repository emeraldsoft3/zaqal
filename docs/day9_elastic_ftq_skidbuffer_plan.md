# Day 9 Implementation Plan: Advanced Pointer Management & Elastic Flow Unification

## 1. Architectural Overview & Objectives

In the high-performance Zaqal RISC-V frontend (XiangShan-aligned), instruction fetch relies on two key decoupled subsystems:
1. **Fetch Target Queue (FTQ)**: Maintains fetch packet metadata, branch predictions, target PCs, and assigns circular buffer tags (`ftqPtr`) to in-flight fetch blocks.
2. **SkidBuffers (Elastic Buffers)**: 2-slot registered pipeline buffers placed at inter-stage boundaries (`BPU -> FTQ`, `FTQ -> IFU/ICache`, `IFU -> IBUF`, and `IBUF -> Backend`) to break long timing paths and absorb backpressure.

### The Problem in Legacy Implementation
- **Decoupled Drifting**: `FTQ` pointer management (`enqPtr`/`deqPtr`) operated independently from downstream `SkidBuffer` occupancy. When backpressure stalled dispatch, `FTQ` entries could drift relative to in-flight instructions sitting in `SkidBuffers`.
- **Coarse Flush Recovery**: On branch mispredictions (`io.redirect.valid`), `FTQ` wiped all pointers (`enqPtr := 0.U`, `deqPtr := 0.U`), destroying valid history and breaking in-flight tag correlation.
- **Credit Mismatch**: BPU backpressure (`bpu.io.out.ready`) only checked `FTQ.ram` capacity without accounting for items parked inside intermediate `SkidBuffers`.

### Day 9 Solution: Single Elastic Flow
1. **Unified Occupancy & Credit Accounting**: Calculate total frontend in-flight fetch packets (`FTQ.ram` entries + SkidBuffer active slots) to gate BPU generation precisely.
2. **Precise FTQ Pointer Rollback**: Upon a branch misprediction (`io.redirect.valid`), restore `enqPtr` and `deqPtr` dynamically to `io.redirect.ftqPtr + 1.U` (or target allocation point) rather than resetting to `0.U`.
3. **Lockstep Synchronized Flushing**: Synchronize epoch flips (`fetch_epoch`) across FTQ metadata and all inter-stage `SkidBuffers` to ensure younger speculative instructions in skid slots are invalidated atomically without dropping valid committed pointers.

---

## 2. Detailed Code Implementation Plan

### A. Enhancing `SkidBuffer` with Occupancy Monitoring (`utility/src/zaqal/utility/Utility.scala`)

Add an `occupancy` output port to `SkidBuffer` so high-level modules can aggregate downstream in-flight credits:

```scala
class SkidBuffer[T <: Data](gen: T)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val enq       = Flipped(Decoupled(gen))
    val deq       = Decoupled(gen)
    val flush     = Input(Bool())
    val occupancy = Output(UInt(2.W)) // Outputs 0, 1, or 2 items currently stored in skid slots
  })

  // Compute Occupancy
  io.occupancy := slot0_valid.asUInt +& slot1_valid.asUInt

  // ... existing enqueue/dequeue/flush logic ...
}
```

---

### B. Refactoring `FTQ.scala` (`frontend/src/zaqal/frontend/FTQ.scala`)

We modify `FTQ` to accept redirect signals directly and perform dynamic pointer restoration (`enqPtr`/`deqPtr` rollback) while reporting unified occupancy.

```scala
// FTQ IO Bundle Updates
val io = IO(new Bundle {
  val fromBpu       = Flipped(Decoupled(new FetchRequest))
  val toIfu         = Decoupled(new FetchRequest)
  val toICache      = Decoupled(new FetchRequest)
  val redirect      = Input(new BPURedirect) // Added for dynamic pointer rollback
  val readPtr       = Input(UInt(ftqPtrWidth.W))
  val readData      = Output(new FetchPacket)
  val flush         = Input(Bool())
  val totalInFlight = Input(UInt(4.W))       // Count of items in downstream SkidBuffers
  val occupancy     = Output(UInt((ftqPtrWidth + 1).W))
})

// Unified Circular Queue & Pointer Management
val ram    = Reg(Vec(ftqEntries, new FetchRequest))
val enqPtr = RegInit(0.U(ftqPtrWidth.W))
val deqPtr = RegInit(0.U(ftqPtrWidth.W))
val count  = RegInit(0.U((ftqPtrWidth + 1).W))

// Total Frontend Occupancy (FTQ Queue + Inter-stage SkidBuffers)
val effectiveOccupancy = count +& io.totalInFlight
val full               = effectiveOccupancy >= ftqEntries.U
val empty              = count === 0.U

// Enqueue & Tag Assignment
io.fromBpu.ready := !full
when(io.fromBpu.fire && !io.flush) {
  val newReq   = Wire(new FetchRequest)
  newReq       := io.fromBpu.bits
  newReq.ftqPtr:= enqPtr
  ram(enqPtr)  := newReq
  enqPtr       := enqPtr + 1.U
}

// Redirect & Rollback Logic (Dynamic Pointer Recovery)
when(io.redirect.valid) {
  // Rollback enqPtr and deqPtr to the redirected ftqPtr target
  val recoveryPtr = io.redirect.ftqPtr + 1.U
  enqPtr := recoveryPtr
  deqPtr := recoveryPtr
  count  := 0.U // Re-synchronize active RAM count post-redirect
}.elsewhen(io.flush) {
  enqPtr := 0.U
  deqPtr := 0.U
  count  := 0.U
}.otherwise {
  val enq = io.fromBpu.fire
  val deq = io.toIfu.fire
  when(enq && !deq) {
    count := count + 1.U
  }.elsewhen(!enq && deq) {
    count := count - 1.U
  }
}
```

---

### C. Updating Inter-stage Flow Control in `Frontend.scala` (`frontend/src/zaqal/frontend/Frontend.scala`)

We link downstream `SkidBuffer` occupancy signals into `FTQ` and enforce epoch alignment across all pipeline boundaries.

```scala
// 1. Instantiating SkidBuffers with Occupancy Tracking
val bpu_skid  = Module(new SkidBuffer(new FetchRequest))
val ftq_skid  = Module(new SkidBuffer(new FetchRequest))
val ifu_skid  = Module(new SkidBuffer(new FetchPacket))

// 2. Wiring BPU -> FTQ through SkidBuffer
bpu_skid.io.enq <> bpu.io.out
bpu_skid.io.flush := is_valid_redirect
ftq.io.fromBpu <> bpu_skid.io.deq

// 3. Calculating Total Skid Buffer Occupancy
val total_skid_occupancy = bpu_skid.io.occupancy +& ftq_skid.io.occupancy +& ifu_skid.io.occupancy
ftq.io.totalInFlight := total_skid_occupancy

// 4. Wiring FTQ -> IFU / ICache through SkidBuffer
ftq_skid.io.enq <> ftq.io.toIfu
ftq_skid.io.flush := is_valid_redirect
ftq_skid.io.deq.ready := ifu.io.fetch_req.ready && icache.io.ready

ifu.io.fetch_req.valid := ftq_skid.io.deq.valid && icache.io.ready
ifu.io.fetch_req.bits  := ftq_skid.io.deq.bits

// 5. Wiring Redirect to FTQ for Dynamic Rollback
ftq.io.redirect := io.redirect
```

---

## 3. GTKWave Signal Verification Guide

To verify the unified elastic flow in **GTKWave**, load `ZaqalCore.vcd` (or `sim.vcd`) and inspect the following hierarchical signal groups:

### Signal Hierarchy Table

| Signal Name in GTKWave | Module Path | Purpose / Description | Expected Behavior |
| --- | --- | --- | --- |
| `clk` | `TOP.Core` | Main Clock | System clock edge reference |
| `reset` | `TOP.Core` | System Reset | Active high reset |
| **BPU & Prediction Signals** | | | |
| `io_out_valid` | `TOP.Core.frontend.bpu` | BPU request valid | `1` when BPU generates PC |
| `io_out_ready` | `TOP.Core.frontend.bpu` | Elastic backpressure | Drops to `0` when FTQ + SkidBuffers full |
| `io_out_bits_pc` | `TOP.Core.frontend.bpu` | Fetch PC generated | Sequential/target addresses |
| **FTQ Elastic Pointer Signals** | | | |
| `enqPtr` | `TOP.Core.frontend.ftq` | FTQ Enqueue Pointer | Increments on `bpu.fire`, rolls back on `redirect` |
| `deqPtr` | `TOP.Core.frontend.ftq` | FTQ Dequeue Pointer | Increments when issuing to IFU |
| `count` | `TOP.Core.frontend.ftq` | RAM Occupancy Count | Tracks items inside FTQ memory |
| `effectiveOccupancy` | `TOP.Core.frontend.ftq` | Unified Total Occupancy | `count + totalInFlight` |
| `io_fromBpu_ready` | `TOP.Core.frontend.ftq` | FTQ Ready Signal | Gated when `effectiveOccupancy >= ftqEntries` |
| **SkidBuffer Inter-stage Signals** | | | |
| `slot0_valid` | `TOP.Core.frontend.bpu_skid` | BPU Skid Main Slot | `1` during active streaming |
| `slot1_valid` | `TOP.Core.frontend.bpu_skid` | BPU Skid Overflow Slot | `1` only during downstream stall |
| `slot0_valid` | `TOP.Core.frontend.ftq_skid` | FTQ Skid Main Slot | `1` when fetch request ready |
| `slot1_valid` | `TOP.Core.frontend.ftq_skid` | FTQ Skid Overflow Slot | `1` when IFU stalls |
| `io_occupancy` | `TOP.Core.frontend.bpu_skid` | Skid Occupancy (0-2) | Live item count in buffer |
| **Redirect & Rollback Signals** | | | |
| `io_redirect_valid` | `TOP.Core.frontend` | Misprediction Flush | High on BRU mispredict |
| `io_redirect_ftqPtr` | `TOP.Core.frontend` | Target FTQ Tag | The `ftqPtr` of mispredicted branch |
| `fetch_epoch` | `TOP.Core.frontend` | Frontend Fetch Epoch | Flips (`0 -> 1` or `1 -> 0`) on redirect |

---

## 4. Verification Scenarios in GTKWave

### Scenario 1: Normal Elastic Streaming (Bubble-Free Flow)
- **Observation**: `bpu.io_out_valid` and `bpu.io_out_ready` remain high.
- **Waveform Pattern**:
  - `enqPtr` increments by `1` every cycle.
  - `deqPtr` follows `enqPtr` with a fixed pipeline latency offset.
  - `bpu_skid.slot0_valid` is `1`, while `slot1_valid` remains `0`.
  - `effectiveOccupancy` stays low (`1` to `3` entries).

### Scenario 2: Backpressure & Skid Absorption (Backend Stall)
- **Observation**: Backend pulls `io.dispatch(i).ready` low (e.g. ROB or IBUF full).
- **Waveform Pattern**:
  - `ftq_skid.slot0_valid` becomes `1`.
  - On the next cycle of stall, `ftq_skid.slot1_valid` becomes `1` (skidding into slot 1).
  - `ftq_skid.io_enq_ready` transitions to `0`.
  - `effectiveOccupancy` increases dynamically: `count` + `skid_occupancy` rises to `ftqEntries` (`16`).
  - `bpu.io_out_ready` transitions to `0`, cleanly pausing the prediction engine without dropping packets.

### Scenario 3: Branch Misprediction & Precise FTQ Pointer Rollback
- **Observation**: Execution unit detects misprediction; `io_redirect_valid` pulses high with `io_redirect_ftqPtr = 0x05`.
- **Waveform Pattern**:
  - `io_redirect_valid` = `1`, `io_redirect_ftqPtr` = `0x05`.
  - `fetch_epoch` flips state.
  - **In the same cycle**:
    - `bpu_skid.slot0_valid` and `slot1_valid` are cleared to `0`.
    - `ftq_skid.slot0_valid` and `slot1_valid` are cleared to `0`.
    - `FTQ.enqPtr` is restored to `0x06` (`0x05 + 1`), preserving entries `0x00`..`0x05`.
    - `FTQ.deqPtr` updates to `0x06` to resume fetch from the correct target.
  - No valid instructions are lost from committed state, and speculative instructions from the wrong path are discarded cleanly.

---

## 5. Implementation Roadmap Checklist

- [x] Create Day 9 Implementation Plan artifact.
- [ ] Add `occupancy` port to `SkidBuffer` in `utility/src/zaqal/utility/Utility.scala`.
- [ ] Update `FTQ.scala` IO with `redirect` and `totalInFlight` inputs.
- [ ] Implement `enqPtr`/`deqPtr` dynamic rollback logic in `FTQ.scala`.
- [ ] Update `Frontend.scala` to connect SkidBuffer occupancy into FTQ's credit counter.
- [ ] Run Chisel unit tests and verilator simulation to generate updated VCD trace.
- [ ] Inspect GTKWave trace against Scenarios 1, 2, and 3.
