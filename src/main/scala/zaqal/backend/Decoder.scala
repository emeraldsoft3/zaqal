package zaqal.backend

import zaqal._
import chisel3._
import chisel3.util._

class DecodeOut extends Bundle {
  // Instruction Types
  val inst_lui   = Bool()
  val inst_addi  = Bool()
  val inst_addiw = Bool()
  val inst_slli  = Bool()
  val inst_blt   = Bool()
  
  // Register Files
  val rs1      = UInt(5.W)
  val rs2      = UInt(5.W)
  val rd       = UInt(5.W)
  val has_dest = Bool() // Does it write to rd?
  
  // Immediate value (sign-extended to 64 bits)
  val imm      = UInt(64.W)
}

class Decoder extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val out  = Output(new DecodeOut())
  })

  val inst = io.inst
  val opcode = inst(6, 0)
  val funct3 = inst(14, 12)
  val funct7 = inst(31, 25)

  // 1. Decode Logic (Matching RISC-V Opcode Map)
  io.out.inst_lui   := (opcode === "b0110111".U)
  io.out.inst_addi  := (opcode === "b0010011".U && funct3 === "b000".U)
  io.out.inst_slli  := (opcode === "b0010011".U && funct3 === "b001".U)
  io.out.inst_addiw := (opcode === "b0011011".U && funct3 === "b000".U)
  io.out.inst_blt   := (opcode === "b1100011".U && funct3 === "b100".U)

  // 2. Register Extraction
  io.out.rd  := inst(11, 7)
  io.out.rs1 := inst(19, 15)
  io.out.rs2 := inst(24, 20)
  
  // 3. Simple Destination Check
  io.out.has_dest := io.out.inst_lui || io.out.inst_addi || io.out.inst_addiw || io.out.inst_slli

  // 4. Immediate Extraction (The tricky part of RISC-V)
  // We extract the 12-bit I-type immediate and sign-extend to 64-bits
  val imm_i = inst(31, 20)
  val imm_i_sext = Cat(Fill(52, imm_i(11)), imm_i)
  
  // U-type (for LUI)
  val imm_u = Cat(inst(31, 12), 0.U(12.W))
  val imm_u_sext = Cat(Fill(32, imm_u(31)), imm_u)

  io.out.imm := Mux(io.out.inst_lui, imm_u_sext, imm_i_sext)
}