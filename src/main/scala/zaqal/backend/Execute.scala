package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal._
import zaqal.backend.fu._

class Execute extends Module {
  val io = IO(new Bundle {
    val in       = Flipped(Decoupled(new MicroOp))
    val redirect = Output(new BPURedirect)
  })

  // Coordination state
  val div_rd_latch = RegInit(0.U(5.W))
  val div_pc_latch = RegInit(0.U(64.W))

  // 1. Decoder & Register File
  val decoder = Module(new Decoder)
  val regFile = Module(new RegFile)
  
  decoder.io.inst := io.in.bits.inst_raw
  regFile.io.rs1_addr := decoder.io.out.rs1
  regFile.io.rs2_addr := decoder.io.out.rs2
  
  val src1 = regFile.io.rs1_data
  val src2 = Mux(decoder.io.out.is_branch, src1, // placeholder if needed
             Mux(decoder.io.out.is_addi || decoder.io.out.is_andi || decoder.io.out.is_ori || decoder.io.out.is_xori, 
                 decoder.io.out.imm.asUInt, 
                 regFile.io.rs2_data))
                 
  // Correction: src2 logic for immediate instructions
  val operand2 = Mux(decoder.io.out.is_addi || decoder.io.out.is_andi || decoder.io.out.is_ori || decoder.io.out.is_xori,
                     decoder.io.out.imm.asUInt,
                     regFile.io.rs2_data)

  // 2. Functional Units
  val alu  = Module(new ALU)
  val bru  = Module(new BRU)
  val mul  = Module(new Multiplier)
  val div  = Module(new Divider)

  // 3. Connect FUs
  alu.io.src1 := src1
  alu.io.src2 := operand2
  alu.io.dec  := decoder.io.out

  bru.io.src1 := src1
  bru.io.src2 := regFile.io.rs2_data
  bru.io.dec  := decoder.io.out
  bru.io.pc   := io.in.bits.pc
  bru.io.pred_taken := io.in.bits.is_predicted_taken

  mul.io.src1 := src1
  mul.io.src2 := regFile.io.rs2_data
  mul.io.dec  := decoder.io.out

  div.io.src1 := src1
  div.io.src2 := regFile.io.rs2_data
  div.io.dec  := decoder.io.out
  div.io.fire := io.in.fire

  // 4. Coordination & Handshake
  io.in.ready := div.io.ready
  
  // Default RegFile write values
  regFile.io.wen     := false.B
  regFile.io.rd_addr := decoder.io.out.rd
  regFile.io.rd_data := 0.U

  // Branch redirection
  io.redirect.valid  := false.B
  io.redirect.target := bru.io.target

  when(io.in.fire) {
    // Writeback for single-cycle instructions
    when(decoder.io.out.rd =/= 0.U) {
      val result = Mux(decoder.io.out.is_mul, mul.io.result, alu.io.result)
      regFile.io.wen     := (alu.io.result =/= 0.U || decoder.io.out.is_mul) // simplified
      regFile.io.wen     := !decoder.io.out.is_branch && !decoder.io.out.is_div
      regFile.io.rd_data := result
    }

    // Branch Redirection Logic
    when(bru.io.mispredict) {
      io.redirect.valid := true.B
      printf(p"CORE EXECUTE: MISPREDICT! pc=${Hexadecimal(io.in.bits.pc)} -> Redirecting to ${Hexadecimal(bru.io.target)}\n")
    } .elsewhen(decoder.io.out.is_branch) {
      printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} Branch Correct\n")
    }

    // Latch DIV metadata
    when(decoder.io.out.is_div) {
      div_rd_latch := decoder.io.out.rd
      div_pc_latch := io.in.bits.pc
    }

    // Printfs for ALU/MUL
    when(decoder.io.out.is_addi || decoder.io.out.is_add || decoder.io.out.is_andi || decoder.io.out.is_ori || decoder.io.out.is_xori || decoder.io.out.is_and || decoder.io.out.is_or || decoder.io.out.is_xor) {
       printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} ALU res: ${alu.io.result}\n")
    }
  }

  // Handle Multi-cycle (DIV) writeback
  when(div.io.done) {
    regFile.io.wen     := true.B
    regFile.io.rd_addr := div_rd_latch
    regFile.io.rd_data := div.io.result
    printf(p"CORE EXECUTE: pc=${Hexadecimal(div_pc_latch)} DIV Result: ${div.io.result} (after stall)\n")
  }
}