package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class Logical(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1   = Input(UInt(xLen.W))
    val src2   = Input(UInt(xLen.W))
    val is_and  = Input(Bool())
    val is_or   = Input(Bool())
    val is_xor  = Input(Bool())
    val is_andn = Input(Bool())
    val is_orn  = Input(Bool())
    val is_xorn = Input(Bool())
    val result = Output(UInt(xLen.W))
  })

  val res_and  = io.src1 & io.src2
  val res_or   = io.src1 | io.src2
  val res_xor  = io.src1 ^ io.src2
  val res_andn = io.src1 & ~io.src2
  val res_orn  = io.src1 | ~io.src2
  val res_xorn = io.src1 ^ ~io.src2

  io.result := MuxCase(0.U, Seq(
    io.is_and  -> res_and,
    io.is_or   -> res_or,
    io.is_xor  -> res_xor,
    io.is_andn -> res_andn,
    io.is_orn  -> res_orn,
    io.is_xorn -> res_xorn
  ))
}
