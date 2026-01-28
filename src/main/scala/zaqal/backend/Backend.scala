// src/main/scala/zaqal/backend/Backend.scala
package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal._
import utility.XSDebug

class Backend extends Module {
  val io = IO(new Bundle {
    val issue    = Flipped(Decoupled(new FetchPacket))
    val redirect = Output(new BPURedirect)
  })

  val rf  = Module(new RegFile)
  val alu = Module(new ALU)
  val decoders = Seq.fill(8)(Module(new Decoder))

  for (i <- 0 until 8) { decoders(i).io.inst := io.issue.bits.instructions(i) }

  val head = decoders(0).io.out

  rf.io.rs1_addr := head.rs1_addr
  rf.io.rs2_addr := head.rs2_addr
  
  alu.io.a := rf.io.rs1_data
  alu.io.b := Mux(head.has_dest && !head.is_jump, head.imm, rf.io.rs2_data)
  alu.io.op := head.func

  // Writeback
  rf.io.wen     := io.issue.fire && head.has_dest
  rf.io.rd_addr := head.rd_addr
  rf.io.rd_data := Mux(head.is_jump, io.issue.bits.pc + 4.U, alu.io.out)

  // V1.3 Branch Logic: Check if it's a branch and if condition is met
  val is_bne = (head.func === "b0000001".U) // Example func for BNE
  val branch_taken = is_bne && (rf.io.rs1_data =/= rf.io.rs2_data)

  io.redirect.valid  := io.issue.fire && (head.is_jump || branch_taken)
  io.redirect.target := io.issue.bits.pc + head.imm

  // FORCE READY - Prevents instructions from getting stuck in IMEM/FTQ
  io.issue.ready := true.B 

  when(io.issue.fire && head.valid) {
    XSDebug("Backend: PC=%x | x%d = %x\n", io.issue.bits.pc, head.rd_addr, rf.io.rd_data)
  }
}