package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal.common._
import zaqal.frontend.cache._

class Frontend(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val flush = Input(new PipelineFlushBus)
    val fetchPacket = Decoupled(new FetchPacket)
    val brpUpdate = Flipped(Valid(new BranchPredictionBus))
    
    val debug_ftq_enq = Output(new FetchPacket)
    val debug_ftq_enq_valid = Output(Bool())
    val debug_ftq_enq_ready = Output(Bool())
  })

  val icache = Module(new ICache)
  val bpu = Module(new BPU)
  val ftq = Module(new FTQ)

  val pc = RegInit(0.U(p.xLen.W))

  // Request next instructions
  icache.io.req.valid := true.B
  icache.io.req.bits := pc

  // Branch Prediction
  bpu.io.req.valid := icache.io.req.fire
  bpu.io.req.bits := pc
  bpu.io.update := io.brpUpdate

  // Enqueue to FTQ
  ftq.io.enq <> icache.io.resp
  ftq.io.enq.bits.pred_target := bpu.io.resp.target
  ftq.io.enq.bits.pred_taken  := bpu.io.resp.taken
  ftq.io.enq.bits.pred_slot   := 0.U // Placeholder if slot-specific prediction is not yet implemented
  
  io.debug_ftq_enq := ftq.io.enq.bits
  io.debug_ftq_enq_valid := ftq.io.enq.valid
  io.debug_ftq_enq_ready := ftq.io.enq.ready

  ftq.io.flush := io.flush.flush
  io.fetchPacket <> ftq.io.deq

  // PC Update
  when(io.flush.flush) {
    pc := io.flush.targetPC
  }.elsewhen(icache.io.req.fire) {
    pc := Mux(bpu.io.resp.taken, bpu.io.resp.target, pc + 4.U)
  }
}
