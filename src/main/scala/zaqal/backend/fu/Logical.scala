package zaqal.backend.fu

import chisel3._
import chisel3.util._

class Logical extends Module {
  val io = IO(new Bundle {
    val src1   = Input(UInt(64.W))
    val src2   = Input(UInt(64.W))
    val is_and = Input(Bool())
    val is_or  = Input(Bool())
    val is_xor = Input(Bool())
    val result = Output(UInt(64.W))
  })

  val res_and = io.src1 & io.src2
  val res_or  = io.src1 | io.src2
  val res_xor = io.src1 ^ io.src2

  io.result := MuxCase(0.U, Seq(
    io.is_and -> res_and,
    io.is_or  -> res_or,
    io.is_xor -> res_xor
  ))
}
