package zaqal

import chisel3._
import chisel3.util._
import zaqal.frontend.Frontend
import zaqal.backend.Backend

class Core extends Module {
  val io = IO(new Bundle {
    val success = Output(Bool())
    val debug_ftq_valid = Output(Bool())
    val debug_ftq_flush = Output(Bool())
    val debug_ftq_pc    = Output(UInt(32.W))
    val debug_ftq_mask  = Output(UInt(8.W))
    val debug_ftq_insts = Output(Vec(8, UInt(32.W)))
    val debug_ftq_ready = Output(Bool())
    val debug_ftq_pred_target = Output(UInt(64.W))
    val debug_ftq_pred_taken  = Output(Bool())
    val debug_ftq_pred_slot   = Output(UInt(3.W))
  })

  val frontend = Module(new Frontend)
  val backend  = Module(new Backend)

  io.debug_ftq_valid := frontend.io.debug_ftq_valid
  io.debug_ftq_flush := frontend.io.debug_ftq_flush
  io.debug_ftq_pc    := frontend.io.debug_ftq_pc
  io.debug_ftq_mask  := frontend.io.debug_ftq_mask
  io.debug_ftq_insts := frontend.io.debug_ftq_insts
  io.debug_ftq_ready := frontend.io.debug_ftq_ready
  io.debug_ftq_pred_target := frontend.io.debug_ftq_pred_target
  io.debug_ftq_pred_taken  := frontend.io.debug_ftq_pred_taken
  io.debug_ftq_pred_slot   := frontend.io.debug_ftq_pred_slot



  // 1. The Feedback Path: Redirects flow from Backend execution back to BPU
  // This is how the 'Real' result of a branch corrects the BPU
  frontend.io.redirect := backend.io.redirect

  // 2. The Instruction Path: Handing packets from FTQ to the Decoder
  backend.io.issue <> frontend.io.fetchPacket

  // 3. Performance Monitoring (View these in GTKWave)
  val stall = frontend.io.fetchPacket.valid && !frontend.io.fetchPacket.ready
  
  // Default success signal
  io.success := true.B
}