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

  // Default connections for RegFile
  regFile.io.rs1_addr := decoder.io.out.rs1
  regFile.io.rs2_addr := 0.U // Not used for ADDI
  regFile.io.wen      := false.B
  regFile.io.rd_addr  := decoder.io.out.rd
  regFile.io.rd_data  := 0.U

  // Decoupled handshake
  io.in.ready := true.B

  // ALU Logic for ADDI
  when(io.in.fire && decoder.io.out.is_addi) {
    val rs1_data = regFile.io.rs1_data
    val imm      = decoder.io.out.imm.asUInt
    val res      = rs1_data + imm
    
    when(decoder.io.out.rd =/= 0.U) {
      regFile.io.wen     := true.B
      regFile.io.rd_data := res
      
      // Monitor for console
      printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} x${decoder.io.out.rd} = x${decoder.io.out.rs1}($rs1_data) + ${decoder.io.out.imm} | Result: $res\n")
    }
  }
}