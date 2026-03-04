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
  val funct7 = io.inst(31, 25)

  io.out.rd  := io.inst(11, 7)
  io.out.rs1 := io.inst(19, 15)
  io.out.rs2 := io.inst(24, 20)
  // RISC-V immediate extraction
  val i_imm = io.inst(31, 20).asSInt
  val b_imm = Cat(io.inst(31), io.inst(7), io.inst(30, 25), io.inst(11, 8), 0.U(1.W)).asSInt


  io.out.is_addi := (opcode === "b0010011".U) && (funct3 === "b000".U)
  io.out.is_andi := (opcode === "b0010011".U) && (funct3 === "b111".U)
  io.out.is_ori  := (opcode === "b0010011".U) && (funct3 === "b110".U)
  io.out.is_xori := (opcode === "b0010011".U) && (funct3 === "b100".U)
  io.out.imm     := i_imm.asSInt

  io.out.is_add  := (opcode === "b0110011".U) && (funct3 === "b000".U) && (funct7 === "b0000000".U)
  io.out.is_and  := (opcode === "b0110011".U) && (funct3 === "b111".U) && (funct7 === "b0000000".U)
  io.out.is_or   := (opcode === "b0110011".U) && (funct3 === "b110".U) && (funct7 === "b0000000".U)
  io.out.is_xor  := (opcode === "b0110011".U) && (funct3 === "b100".U) && (funct7 === "b0000000".U)


  io.out.is_mul  := (opcode === "b0110011".U) && (funct3 === "b000".U) && (funct7 === "b0000001".U)


  io.out.is_div  := (opcode === "b0110011".U) && (funct3 === "b100".U) && (funct7 === "b0000001".U)


  io.out.is_bne    := (opcode === "b1100011".U) && (funct3 === "b001".U)
  io.out.is_branch := (opcode === "b1100011".U)

  io.out.is_blt := (opcode === "b1100011".U) && (funct3 === "b100".U)

  // Select immediate based on instruction type
  when(io.out.is_branch) {
    io.out.imm := b_imm
  }
}
