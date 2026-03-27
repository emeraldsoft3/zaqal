package zaqal.backend.fu

import chisel3._
import chisel3.util._

class Comparator extends Module {
  val io = IO(new Bundle {
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val eq   = Output(Bool())
    val lt   = Output(Bool())
    val ltu  = Output(Bool())
  })

  io.eq  := io.src1 === io.src2
  io.lt  := io.src1.asSInt < io.src2.asSInt
  io.ltu := io.src1 < io.src2
}
