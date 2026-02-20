package qalam

import chisel3._
import chisel3.util._

class Core extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val pc   = Output(UInt(64.W))

    // Debug outputs to compare with Zaqal
    val rd_addr = Output(UInt(5.W))
    val rd_data = Output(UInt(64.W))
    val wen     = Output(Bool())
  })

  // Program Counter
  val pcReg = RegInit(0.U(64.W))
  pcReg := pcReg + 4.U
  io.pc := pcReg

  // Instruction Fields
  val opcode = io.inst(6, 0)
  val funct3 = io.inst(14, 12)
  val funct7 = io.inst(31, 25)
  val rd     = io.inst(11, 7)
  val rs1    = io.inst(19, 15)
  val rs2    = io.inst(24, 20)
  val imm    = io.inst(31, 20).asSInt

  // Simple Register File
  val regs = RegInit(VecInit(Seq.fill(32)(0.U(64.W))))

  // Source register reads (x0 hardwired to 0)
  val rs1_data = Mux(rs1 === 0.U, 0.U, regs(rs1))
  val rs2_data = Mux(rs2 === 0.U, 0.U, regs(rs2))

  // -------------------------------------------------------
  // Instruction Decodes
  // -------------------------------------------------------
  // I-Type: ADDI  -> opcode=0010011, funct3=000
  val is_addi = (opcode === "b0010011".U) && (funct3 === "b000".U)

  // R-Type: ADD   -> opcode=0110011, funct3=000, funct7=0000000
  val is_add  = (opcode === "b0110011".U) && (funct3 === "b000".U) && (funct7 === "b0000000".U)

  // M-extension: MUL -> opcode=0110011, funct3=000, funct7=0000001
  val is_mul  = (opcode === "b0110011".U) && (funct3 === "b000".U) && (funct7 === "b0000001".U)

  // M-extension: DIV -> opcode=0110011, funct3=100, funct7=0000001
  val is_div  = (opcode === "b0110011".U) && (funct3 === "b100".U) && (funct7 === "b0000001".U)

  // -------------------------------------------------------
  // ALU
  // -------------------------------------------------------
  val alu_res = MuxCase(0.U, Seq(
    is_addi -> (rs1_data + imm.asUInt),
    is_add  -> (rs1_data + rs2_data),
    is_mul  -> (rs1_data * rs2_data),
    is_div  -> (rs1_data.asSInt / rs2_data.asSInt).asUInt
  ))

  val any_op = is_addi || is_add || is_mul || is_div
  val wen    = any_op && (rd =/= 0.U)

  // Write Back
  when(wen) {
    regs(rd) := alu_res
  }

  // Debug outputs
  io.rd_addr := rd
  io.rd_data := alu_res
  io.wen     := wen

  // Console output
  when(is_addi) {
    printf(p"QALAM EXECUTE: pc=${Hexadecimal(pcReg)} ADDI x$rd = x$rs1($rs1_data) + $imm | Result: $alu_res\n")
  }
  when(is_add) {
    printf(p"QALAM EXECUTE: pc=${Hexadecimal(pcReg)} ADD  x$rd = x$rs1($rs1_data) + x$rs2($rs2_data) | Result: $alu_res\n")
  }
  when(is_mul) {
    printf(p"QALAM EXECUTE: pc=${Hexadecimal(pcReg)} MUL  x$rd = x$rs1($rs1_data) * x$rs2($rs2_data) | Result: $alu_res\n")
  }
  when(is_div) {
    printf(p"QALAM EXECUTE: pc=${Hexadecimal(pcReg)} DIV  x$rd = x$rs1($rs1_data) / x$rs2($rs2_data) | Result: $alu_res\n")
  }
}
