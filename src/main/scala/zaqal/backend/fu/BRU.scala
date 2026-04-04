package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.common._

class BRU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1            = Input(UInt(xLen.W))
    val src2            = Input(UInt(xLen.W))
    val dec             = Input(new DecodeSignals)
    val pc              = Input(UInt(xLen.W))
    val pred_taken      = Input(Bool())
    
    val taken           = Output(Bool())
    val mispredict      = Output(Bool())
    val target          = Output(UInt(xLen.W))
  })

  val comparator = Module(new Comparator)
  comparator.io.src1 := io.src1
  comparator.io.src2 := io.src2

  val taken_beq  = comparator.io.eq
  val taken_bne  = !comparator.io.eq
  val taken_blt  = comparator.io.lt
  val taken_bge  = !comparator.io.lt
  val taken_bltu = comparator.io.ltu
  val taken_bgeu = !comparator.io.ltu
  
  val actual_taken = MuxCase(false.B, Seq(
    io.dec.is_beq  -> taken_beq,
    io.dec.is_bne  -> taken_bne,
    io.dec.is_blt  -> taken_blt,
    io.dec.is_bge  -> taken_bge,
    io.dec.is_bltu -> taken_bltu,
    io.dec.is_bgeu -> taken_bgeu,
    io.dec.is_jal  -> true.B,
    io.dec.is_jalr -> true.B
  ))

  val target_pc = Mux(io.dec.is_jalr,
    (io.src1 + io.dec.imm.asUInt) & ~1.U(xLen.W),
    (io.pc.asSInt + io.dec.imm).asUInt
  )
  val fallthrough_pc = io.pc + 4.U

  val is_cfi = io.dec.is_branch || io.dec.is_jal || io.dec.is_jalr

  io.taken      := actual_taken
  io.mispredict := (actual_taken =/= io.pred_taken) || (io.pred_taken && !is_cfi)
  io.target     := Mux(actual_taken, target_pc, fallthrough_pc)
}
