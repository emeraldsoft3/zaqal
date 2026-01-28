package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal._

class Decoder extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val out  = Output(new DecodedInst)
  })

  val inst = io.inst
  val opcode = inst(6, 0)

  // Default assignments
  io.out.valid    := inst =/= 0.U
  io.out.pc       := 0.U // Filled by Execute
  io.out.rd_addr  := inst(11, 7)
  io.out.rs1_addr := inst(19, 15)
  io.out.rs2_addr := inst(24, 20)
  io.out.imm      := 0.U
  io.out.func     := Cat(inst(31, 25), inst(14, 12))
  io.out.has_dest := false.B
  io.out.is_jump  := false.B

  // Agile: Identify ADDI and JAL for our heartbeat loop
 when(opcode === "b0010011".U) { // OP-IMM (addi)
    io.out.has_dest := true.B
    io.out.imm      := Cat(Fill(52, inst(31)), inst(31, 20))
  } .elsewhen(opcode === "b1101111".U) { // JAL (Combined logic)
    io.out.has_dest := true.B
    io.out.is_jump  := true.B // Set BOTH flags here!
    val jimm = Cat(inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))
    io.out.imm := Cat(Fill(43, jimm(20)), jimm)
  }
    

}