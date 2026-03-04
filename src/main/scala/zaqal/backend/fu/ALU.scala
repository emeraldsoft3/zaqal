package zaqal.backend.fu

import chisel3._
import chisel3.util._
import zaqal.DecodeSignals

class ALU extends Module {
  val io = IO(new Bundle {
    val src1   = Input(UInt(64.W))
    val src2   = Input(UInt(64.W))
    val dec    = Input(new DecodeSignals)
    val result = Output(UInt(64.W))
  })

  val res_addi = io.src1 + io.src2 // src2 is already the immediate in Execute.scala
  val res_add  = io.src1 + io.src2
  val res_and  = io.src1 & io.src2
  val res_or   = io.src1 | io.src2
  val res_xor  = io.src1 ^ io.src2

  io.result := MuxCase(0.U, Seq(
    (io.dec.is_addi || io.dec.is_add) -> res_add,
    (io.dec.is_andi || io.dec.is_and) -> res_and,
    (io.dec.is_ori  || io.dec.is_or)  -> res_or,
    (io.dec.is_xori || io.dec.is_xor) -> res_xor
  ))
}
