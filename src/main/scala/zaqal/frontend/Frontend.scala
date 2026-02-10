package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class Frontend extends Module {
  val io = IO(new Bundle {
    val redirect     = Input(new BPURedirect)
    val dispatch     = Decoupled(new MicroOp) // Renamed for clarity: this is the output of Frontend
    
    // Debug ports for our CSV Tracer
    val debug_ftq_valid       = Output(Bool())
    val debug_ftq_flush       = Output(Bool())
    val debug_ftq_pc          = Output(UInt(32.W))
    val debug_ftq_mask        = Output(UInt(8.W))
    val debug_ftq_insts       = Output(Vec(8, UInt(32.W)))
    val debug_ftq_ready       = Output(Bool())
    val debug_ftq_pred_target = Output(UInt(64.W))
    val debug_ftq_pred_taken  = Output(Bool())
    val debug_ftq_pred_slot   = Output(UInt(3.W))

    val debug_ftq_occupancy = Output(UInt(7.W))
  })

  // 1. Instantiate the sub-modules
  val bpu  = Module(new BPU)
  val ftq  = Module(new FTQ)
  val ifu  = Module(new IFU)
  val ibuf = Module(new IBUF)

  // 1. BPU -> FTQ (Prediction Path)
  ftq.io.fromBpu <> bpu.io.out

  // 2. FTQ <-> IFU (Fetch Path)
  ifu.io.fetch_req  <> ftq.io.toIfu
  ftq.io.fromIfu    <> ifu.io.fetch_resp

  // 3. FTQ -> IBUF (Data Path)
  ibuf.io.inst_data <> ftq.io.toBackend

  // 4. IBUF -> Backend (Dispatch Path)
  io.dispatch <> ibuf.io.out

  // Handlers for Redirects (Branch Mispredictions)
  ftq.io.flush := io.redirect.valid
  bpu.io.redirect := io.redirect

  // 6. Debug Port Mapping
  io.debug_ftq_valid       := ftq.io.fromBpu.valid
  io.debug_ftq_flush       := ftq.io.flush
  io.debug_ftq_pc          := ftq.io.fromBpu.bits.pc
  io.debug_ftq_mask        := ftq.io.fromBpu.bits.mask
  io.debug_ftq_insts       := ftq.io.fromBpu.bits.instructions
  io.debug_ftq_ready       := ftq.io.fromBpu.ready
  io.debug_ftq_pred_target := ftq.io.fromBpu.bits.prediction.target
  io.debug_ftq_pred_taken  := ftq.io.fromBpu.bits.prediction.taken
  io.debug_ftq_pred_slot   := ftq.io.fromBpu.bits.prediction.slot

  io.debug_ftq_occupancy := ftq.io.occupancy
}