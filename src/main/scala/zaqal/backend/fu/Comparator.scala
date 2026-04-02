package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.HasZaqalParameter

class Comparator(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1 = Input(UInt(xLen.W))
    val src2 = Input(UInt(xLen.W))
    val eq   = Output(Bool())
    val lt   = Output(Bool())
    val ltu  = Output(Bool())
  })

  io.eq  := io.src1 === io.src2
  io.lt  := io.src1.asSInt < io.src2.asSInt
  io.ltu := io.src1 < io.src2
}
