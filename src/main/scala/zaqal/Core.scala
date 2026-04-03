package zaqal

import chisel3._
import chisel3.util._
import zaqal.common._
import zaqal.frontend._
import zaqal.backend._

class Core(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val halt = Output(Bool())
    
    // Debug FTQ hooks for simulation
    val debug_ftq_valid = Output(Bool())
    val debug_ftq_ready = Output(Bool())
    val debug_ftq_pc = Output(UInt(p.xLen.W))
    val debug_ftq_mask = Output(UInt(p.nFetchInstrs.W))
    val debug_ftq_insts = Output(Vec(p.nFetchInstrs, UInt(32.W)))
    val debug_ftq_pred_target = Output(UInt(p.xLen.W))
    val debug_ftq_pred_taken = Output(Bool())
    val debug_ftq_pred_slot = Output(UInt(log2Up(p.nFetchInstrs).W))
    
    val debug_ftq_flush = Output(Bool())
    val debug_ftq_valid_out = Output(Bool())
    val debug_ftq_ready_out = Output(Bool())
  })

  val frontend = Module(new Frontend)
  val backend = Module(new Backend)

  // Connections
  backend.io.fetchPacket <> frontend.io.fetchPacket
  frontend.io.flush := backend.io.flush
  frontend.io.brpUpdate := backend.io.brpUpdate

  // Debug Wiring
  io.debug_ftq_valid         := frontend.io.debug_ftq_enq_valid
  io.debug_ftq_ready         := frontend.io.debug_ftq_enq_ready
  io.debug_ftq_pc            := frontend.io.debug_ftq_enq.pc
  io.debug_ftq_mask          := frontend.io.debug_ftq_enq.mask
  io.debug_ftq_insts         := frontend.io.debug_ftq_enq.instrs
  io.debug_ftq_pred_target   := frontend.io.debug_ftq_enq.pred_target
  io.debug_ftq_pred_taken    := frontend.io.debug_ftq_enq.pred_taken
  io.debug_ftq_pred_slot     := frontend.io.debug_ftq_enq.pred_slot
  
  io.debug_ftq_flush         := backend.io.flush.flush
  io.debug_ftq_valid_out     := frontend.io.fetchPacket.valid
  io.debug_ftq_ready_out     := frontend.io.fetchPacket.ready

  io.halt := false.B
}