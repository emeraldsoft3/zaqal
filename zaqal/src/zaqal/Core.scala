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
    val success   = Output(Bool())
    val debug_sum = if (!enableDebugPorts) Some(Output(UInt(xLen.W))) else None
  })

  val debug = if (enableDebugPorts) Some(IO(new Bundle {
    // Signals entering the FTQ (from BPU/IFU)
    val ftq_valid       = Output(Bool())
    val ftq_flush       = Output(Bool())
    val ftq_pc          = Output(UInt(xLen.W))
    val ftq_mask        = Output(UInt(fetchWidth.W))
    val ftq_insts       = Output(Vec(fetchWidth, UInt(instBits.W)))
    val ftq_ready       = Output(Bool())
    val ftq_pred_target = Output(UInt(xLen.W))
    val ftq_pred_taken  = Output(Bool())
    val ftq_pred_slot   = Output(UInt(log2Up(fetchWidth).W))
    val ftq_occupancy   = Output(UInt((ftqPtrWidth + 1).W))

    // Signals leaving the Frontend (heading to Backend)
    val ftq_valid_out   = Output(Bool())
    val ftq_ready_out   = Output(Bool())

    val cycle_count     = Output(UInt(64.W))
    val regs            = Output(Vec(phyRegs, UInt(xLen.W)))
    val fp_regs         = Output(Vec(phyRegs, UInt(fLen.W)))
    val debug_int_rat   = Output(Vec(32, UInt(phyRegIdxWidth.W)))
    val debug_fp_rat    = Output(Vec(32, UInt(phyRegIdxWidth.W)))
  })) else None

  // Cycle Counter logic
  val cycle_reg = RegInit(0.U(64.W))
  cycle_reg := cycle_reg + 1.U

  // 1. Instantiate the Modules
  val frontend = Module(new Frontend)
  val backend  = Module(new Backend)

  // 2. Connect Frontend to Backend (Buffered Dispatch!)
  for (i <- 0 until decodeWidth) {
    backend.io.dispatch(i) <> frontend.io.dispatch(i)
  }
  frontend.io.redirect := backend.io.redirect
  backend.io.debug_cycle := cycle_reg

  // Metadata access (XiangShan style) - Tie off for now
  frontend.io.ftq_read_ptr := 0.U 
  dontTouch(frontend.io.ftq_read_data)

  // 4. Connect Internal Signals to External Debug Pins
  if (enableDebugPorts) {
    val d = debug.get
    d.ftq_valid       := frontend.io.debug_ftq_valid
    d.ftq_flush       := frontend.io.debug_ftq_flush
    d.ftq_pc          := frontend.io.debug_ftq_pc
    d.ftq_mask        := frontend.io.debug_ftq_mask
    d.ftq_insts       := frontend.io.debug_ftq_insts
    d.ftq_ready       := frontend.io.debug_ftq_ready
    d.ftq_pred_target := frontend.io.debug_ftq_pred_target
    d.ftq_pred_taken  := frontend.io.debug_ftq_pred_taken
    d.ftq_pred_slot   := frontend.io.debug_ftq_pred_slot
    d.ftq_occupancy   := frontend.io.debug_ftq_occupancy

    // Handshake with Backend
    d.ftq_valid_out   := frontend.io.dispatch(0).valid
    d.ftq_ready_out   := frontend.io.dispatch(0).ready

    d.cycle_count     := cycle_reg
    d.regs            := backend.io.debug_regs
    d.fp_regs         := backend.io.debug_fp_regs
    d.debug_int_rat   := backend.io.debug_int_rat
    d.debug_fp_rat    := backend.io.debug_fp_rat
  } else {
    io.debug_sum.get := backend.io.debug_regs.reduce(_ ^ _) ^ backend.io.debug_fp_regs.reduce(_ ^ _) ^ frontend.io.debug_ftq_pc
  }

  io.success := true.B
}