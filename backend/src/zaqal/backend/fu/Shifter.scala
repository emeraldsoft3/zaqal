package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class Shifter(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1    = Input(UInt(xLen.W))
    val shamt   = Input(UInt(log2Up(xLen).W))
    val is_sll   = Input(Bool())
    val is_srl   = Input(Bool())
    val is_sra   = Input(Bool())
    val is_sllw  = Input(Bool())
    val is_srlw  = Input(Bool())
    val is_sraw  = Input(Bool())
    val is_rol   = Input(Bool())
    val is_ror   = Input(Bool())
    val is_rori  = Input(Bool())
    val is_rolw  = Input(Bool())
    val is_rorw  = Input(Bool())
    val is_roriw = Input(Bool())
    val result  = Output(UInt(xLen.W))
  })

  // 64-bit logic
  val res_sll = io.src1 << io.shamt
  val res_srl = io.src1 >> io.shamt
  val res_sra = (io.src1.asSInt >> io.shamt).asUInt
  val res_ror = (io.src1 >> io.shamt) | (io.src1 << (64.U - io.shamt))
  val res_rol = (io.src1 << io.shamt) | (io.src1 >> (64.U - io.shamt))

  // 32-bit logic (Word)
  val shamt_w  = io.shamt(4,0)
  val src1_w   = io.src1(31,0)
  val res_sllw = (src1_w << shamt_w)(31,0)
  val res_srlw = src1_w >> shamt_w
  val res_sraw = (src1_w.asSInt >> shamt_w).asUInt
  val res_rorw = (src1_w >> shamt_w) | (src1_w << (32.U - shamt_w))
  val res_rolw = (src1_w << shamt_w) | (src1_w >> (32.U - shamt_w))

  io.result := MuxCase(0.U, Seq(
    io.is_sll  -> res_sll,
    io.is_srl  -> res_srl,
    io.is_sra  -> res_sra,
    (io.is_ror || io.is_rori) -> res_ror,
    io.is_rol  -> res_rol,
    io.is_sllw -> Cat(Fill(32, res_sllw(31)), res_sllw),
    io.is_srlw -> Cat(Fill(32, res_srlw(31)), res_srlw),
    io.is_sraw -> Cat(Fill(32, res_sraw(31)), res_sraw),
    (io.is_rorw || io.is_roriw) -> Cat(Fill(32, res_rorw(31)), res_rorw(31,0)),
    io.is_rolw -> Cat(Fill(32, res_rolw(31)), res_rolw(31,0))
  ))
}
