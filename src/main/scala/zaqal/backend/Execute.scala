package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal._

class Execute extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new MicroOp))
  })

  // Kunminghu Alignment: Main Decoder is in the Backend
  val decoder = Module(new Decoder)
  val regFile = Module(new RegFile)

  decoder.io.inst := io.in.bits.inst_raw

  // Wire up both source registers
  regFile.io.rs1_addr := decoder.io.out.rs1
  regFile.io.rs2_addr := decoder.io.out.rs2
  regFile.io.wen      := false.B
  regFile.io.rd_addr  := decoder.io.out.rd
  regFile.io.rd_data  := 0.U

  // Decoupled handshake
  io.in.ready := true.B

  val rs1_data = regFile.io.rs1_data
  val rs2_data = regFile.io.rs2_data
  val imm      = decoder.io.out.imm.asUInt

  // ALU Logic
  when(io.in.fire) {
    val rd = decoder.io.out.rd

    // ADDI: rd = rs1 + imm
    when(decoder.io.out.is_addi) {
      val res = rs1_data + imm
      when(rd =/= 0.U) {
        regFile.io.wen     := true.B
        regFile.io.rd_data := res
        printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} ADDI x$rd = x${decoder.io.out.rs1}($rs1_data) + ${decoder.io.out.imm} | Result: $res\n")
      }
    }

    // ADD: rd = rs1 + rs2
    .elsewhen(decoder.io.out.is_add) {
      val res = rs1_data + rs2_data
      when(rd =/= 0.U) {
        regFile.io.wen     := true.B
        regFile.io.rd_data := res
        printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} ADD  x$rd = x${decoder.io.out.rs1}($rs1_data) + x${decoder.io.out.rs2}($rs2_data) | Result: $res\n")
      }
    }

    // MUL: rd = rs1 * rs2  (lower 64 bits)
    .elsewhen(decoder.io.out.is_mul) {
      val res = rs1_data * rs2_data
      when(rd =/= 0.U) {
        regFile.io.wen     := true.B
        regFile.io.rd_data := res
        printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} MUL  x$rd = x${decoder.io.out.rs1}($rs1_data) * x${decoder.io.out.rs2}($rs2_data) | Result: $res\n")
      }
    }

    // DIV: rd = rs1 / rs2  (signed)
    .elsewhen(decoder.io.out.is_div) {
      val res = (rs1_data.asSInt / rs2_data.asSInt).asUInt
      when(rd =/= 0.U) {
        regFile.io.wen     := true.B
        regFile.io.rd_data := res
        printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} DIV  x$rd = x${decoder.io.out.rs1}($rs1_data) / x${decoder.io.out.rs2}($rs2_data) | Result: $res\n")
      }
    }
  }
}