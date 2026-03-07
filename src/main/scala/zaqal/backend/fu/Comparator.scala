package zaqal.backend.fu

import chisel3._
import chisel3.util._

class Comparator extends Module {
  val io = IO(new Bundle {
    val src1    = Input(UInt(64.W))
    val src2    = Input(UInt(64.W))
    val is_slt  = Input(Bool())
    val is_sltu = Input(Bool())
    val result  = Output(UInt(64.W))
  })

  val res_slt  = io.src1.asSInt < io.src2.asSInt
  val res_sltu = io.src1 < io.src2

  io.result := Mux(io.is_sltu, res_sltu.asUInt, res_slt.asUInt)
}
