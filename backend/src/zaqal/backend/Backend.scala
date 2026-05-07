package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class Backend(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val dispatch = Vec(decodeWidth, Flipped(Decoupled(new MicroOp)))
    val redirect = Output(new BPURedirect)
    val debug_regs = Output(Vec(logicalRegs, UInt(xLen.W)))
    val debug_fp_regs = Output(Vec(32, UInt(fLen.W)))
    val debug_cycle = Input(UInt(64.W))
  })

  val exec = Module(new Execute)

  // Day 2: Still single-issue in the backend, so we only consume from port 0
  exec.io.in <> io.dispatch(0)

  // Ports 1-5 are "stubbed" for now until Day 3 (Parallel Decoders)
  for (i <- 1 until decodeWidth) {
    io.dispatch(i).ready := false.B
  }

  // Route redirection from Execute to Frontend
  io.redirect := exec.io.redirect
  io.debug_regs := exec.io.debug_regs
  io.debug_fp_regs := exec.io.debug_fp_regs
  exec.io.debug_cycle := io.debug_cycle
}
