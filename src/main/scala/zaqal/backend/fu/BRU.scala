package zaqal.backend.fu

import chisel3._
import chisel3.util._
import zaqal.DecodeSignals

class BRU extends Module {
  val io = IO(new Bundle {
    val src1            = Input(UInt(64.W))
    val src2            = Input(UInt(64.W))
    val dec             = Input(new DecodeSignals)
    val pc              = Input(UInt(64.W))
    val pred_taken      = Input(Bool())
    
    val taken           = Output(Bool())
    val mispredict      = Output(Bool())
    val target          = Output(UInt(64.W))
  })

  val taken_beq = io.src1 === io.src2
  val taken_bne = io.src1 =/= io.src2
  val taken_blt = io.src1.asSInt < io.src2.asSInt
  
  val actual_taken = MuxCase(false.B, Seq(
    io.dec.is_beq -> taken_beq,
    io.dec.is_bne -> taken_bne,
    io.dec.is_blt -> taken_blt
  ))

  val target_pc = (io.pc.asSInt + io.dec.imm).asUInt
  val fallthrough_pc = io.pc + 4.U

  io.taken      := actual_taken
  io.mispredict := (actual_taken =/= io.pred_taken) || (io.pred_taken && !io.dec.is_branch)
  io.target     := Mux(actual_taken, target_pc, fallthrough_pc)
}
