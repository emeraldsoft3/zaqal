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

  val decoders = Seq.fill(decodeWidth)(Module(new Decoder))
  val decoded_uops = Wire(Vec(decodeWidth, new DecodedMicroOp))

  for (i <- 0 until decodeWidth) {
    decoders(i).io.inst := io.dispatch(i).bits.inst_raw
    decoded_uops(i).uop    := io.dispatch(i).bits
    decoded_uops(i).decode := decoders(i).io.out
  }

  val exec = Module(new Execute)

  // Day 3: Parallel decoders are ready, but execution cluster is still single-issue.
  // We feed the first decoded uop to the Execute module.
  exec.io.in.valid := io.dispatch(0).valid
  exec.io.in.bits  := decoded_uops(0)
  io.dispatch(0).ready := exec.io.in.ready

  // Ports 1-5 decoders are running in parallel, but their results are currently discarded.
  // We keep them ready=false to avoid losing instructions until the Rename/Issue stages are built.
  for (i <- 1 until decodeWidth) {
    io.dispatch(i).ready := false.B
  }

  // Route redirection from Execute to Frontend
  io.redirect := exec.io.redirect
  io.debug_regs := exec.io.debug_regs
  io.debug_fp_regs := exec.io.debug_fp_regs
  exec.io.debug_cycle := io.debug_cycle
}
