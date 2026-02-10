package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal.DecodeSignals

class Decoder extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val out  = Output(new DecodeSignals)
  })

  val opcode = io.inst(6, 0)
  val funct3 = io.inst(14, 12)
  
  io.out.rd   := io.inst(11, 7)
  io.out.rs1  := io.inst(19, 15)
  // RISC-V I-Type immediate extraction (Sign-extended)
  io.out.imm  := io.inst(31, 20).asSInt
  
  // Logic to identify ADDI
  io.out.is_addi := (opcode === "b0010011".U) && (funct3 === "b000".U)
}
