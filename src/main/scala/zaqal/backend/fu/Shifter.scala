package zaqal.backend.fu

import chisel3._
import chisel3.util._

class Shifter extends Module {
  val io = IO(new Bundle {
    val src1    = Input(UInt(64.W))
    val shamt   = Input(UInt(6.W))
    val is_sll  = Input(Bool())
    val is_srl  = Input(Bool())
    val is_sra  = Input(Bool())
    val is_sllw = Input(Bool())
    val is_srlw = Input(Bool())
    val is_sraw = Input(Bool())
    val result  = Output(UInt(64.W))
  })

  // 64-bit logic
  val res_sll = io.src1 << io.shamt
  val res_srl = io.src1 >> io.shamt
  val res_sra = (io.src1.asSInt >> io.shamt).asUInt

  // 32-bit logic (Word)
  val shamt_w  = io.shamt(4,0)
  val src1_w   = io.src1(31,0)
  val res_sllw = (src1_w << shamt_w)(31,0)
  val res_srlw = src1_w >> shamt_w
  val res_sraw = (src1_w.asSInt >> shamt_w).asUInt

  io.result := MuxCase(0.U, Seq(
    io.is_sll  -> res_sll,
    io.is_srl  -> res_srl,
    io.is_sra  -> res_sra,
    io.is_sllw -> Cat(Fill(32, res_sllw(31)), res_sllw),
    io.is_srlw -> Cat(Fill(32, res_srlw(31)), res_srlw),
    io.is_sraw -> Cat(Fill(32, res_sraw(31)), res_sraw)
  ))
}
