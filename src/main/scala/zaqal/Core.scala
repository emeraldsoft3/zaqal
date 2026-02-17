package zaqal

import chisel3._
import chisel3.util._
import zaqal.frontend.Frontend
import zaqal.backend.Backend

class Core extends Module {
  val io = IO(new Bundle {
    val success               = Output(Bool())
    // Signals entering the FTQ (from BPU/IFU)
    val debug_ftq_valid       = Output(Bool())
    val debug_ftq_flush       = Output(Bool())
    val debug_ftq_pc          = Output(UInt(32.W))
    val debug_ftq_mask        = Output(UInt(8.W))
    val debug_ftq_insts       = Output(Vec(8, UInt(32.W)))
    val debug_ftq_ready       = Output(Bool())
    val debug_ftq_pred_target = Output(UInt(64.W))
    val debug_ftq_pred_taken  = Output(Bool())
    val debug_ftq_pred_slot   = Output(UInt(3.W))
    val debug_ftq_occupancy   = Output(UInt(7.W))

    // Signals leaving the Frontend (heading to Backend)
    val debug_ftq_valid_out   = Output(Bool())
    val debug_ftq_ready_out   = Output(Bool())

    val debug_cycle_count     = Output(UInt(64.W))
  })

  // 1. Instantiate the Modules
  val frontend = Module(new Frontend)
  val backend  = Module(new Backend)

  // 2. Connect Frontend to Backend
  backend.io.dispatch  <> frontend.io.dispatch
  frontend.io.redirect := backend.io.redirect

  // Metadata access (XiangShan style) - Tie off for now
  frontend.io.ftq_read_ptr := 0.U 
  dontTouch(frontend.io.ftq_read_data)

  // 4. Connect Internal Signals to External Debug Pins
  io.debug_ftq_valid       := frontend.io.debug_ftq_valid
  io.debug_ftq_flush       := frontend.io.debug_ftq_flush
  io.debug_ftq_pc          := frontend.io.debug_ftq_pc
  io.debug_ftq_mask        := frontend.io.debug_ftq_mask
  io.debug_ftq_insts       := frontend.io.debug_ftq_insts
  io.debug_ftq_ready       := frontend.io.debug_ftq_ready
  io.debug_ftq_pred_target := frontend.io.debug_ftq_pred_target
  io.debug_ftq_pred_taken  := frontend.io.debug_ftq_pred_taken
  io.debug_ftq_pred_slot   := frontend.io.debug_ftq_pred_slot
  io.debug_ftq_occupancy   := frontend.io.debug_ftq_occupancy

  // Handshake with Backend
  io.debug_ftq_valid_out   := frontend.io.dispatch.valid
  io.debug_ftq_ready_out   := frontend.io.dispatch.ready

  // Cycle Counter logic
  val cycle_reg = RegInit(0.U(64.W))
  cycle_reg := cycle_reg + 1.U
  io.debug_cycle_count := cycle_reg

  io.success := true.B
}