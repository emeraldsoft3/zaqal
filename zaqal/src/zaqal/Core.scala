package zaqal

import zaqal.common._

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.frontend.Frontend
import zaqal.backend.Backend
import zaqal.utility.SkidBuffer


class Core(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val success               = Output(Bool())
    // Signals entering the FTQ (from BPU/IFU)
    val debug_ftq_valid       = Output(Bool())
    val debug_ftq_flush       = Output(Bool())
    val debug_ftq_pc          = Output(UInt(xLen.W))
    val debug_ftq_mask        = Output(UInt(fetchWidth.W))
    val debug_ftq_insts       = Output(Vec(fetchWidth, UInt(instBits.W)))
    val debug_ftq_ready       = Output(Bool())
    val debug_ftq_pred_target = Output(UInt(xLen.W))
    val debug_ftq_pred_taken  = Output(Bool())
    val debug_ftq_pred_slot   = Output(UInt(log2Up(fetchWidth).W))
    val debug_ftq_occupancy   = Output(UInt((ftqPtrWidth + 1).W))

    // Signals leaving the Frontend (heading to Backend)
    val debug_ftq_valid_out   = Output(Bool())
    val debug_ftq_ready_out   = Output(Bool())

    val debug_cycle_count     = Output(UInt(64.W))
    val debug_regs            = Output(Vec(phyRegs, UInt(xLen.W)))
    val debug_fp_regs         = Output(Vec(phyRegs, UInt(fLen.W)))
  })

  // Cycle Counter logic
  val cycle_reg = RegInit(0.U(64.W))
  cycle_reg := cycle_reg + 1.U

  // 1. Instantiate the Modules
  val frontend = Module(new Frontend)
  val backend  = Module(new Backend)

  // 2. Connect Frontend to Backend (Buffered Dispatch!)
  for (i <- 0 until decodeWidth) {
    if (i >= 2) {
      frontend.io.dispatch(i).ready := false.B
      backend.io.dispatch(i).valid  := false.B
      backend.io.dispatch(i).bits   := DontCare
    } else {
      backend.io.dispatch(i) <> SkidBuffer(frontend.io.dispatch(i), frontend.io.debug_ftq_flush)
    }
  }
  frontend.io.redirect := backend.io.redirect
  backend.io.debug_cycle := cycle_reg

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
  io.debug_ftq_valid_out   := frontend.io.dispatch(0).valid
  io.debug_ftq_ready_out   := frontend.io.dispatch(0).ready

  io.debug_cycle_count := cycle_reg
  io.debug_regs := backend.io.debug_regs
  io.debug_fp_regs := backend.io.debug_fp_regs

  io.success := true.B
}