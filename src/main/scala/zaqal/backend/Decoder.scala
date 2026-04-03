package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal.common._

class Decoder(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val instr = Input(UInt(32.W))
    val uop = Output(new MicroOp)
  })

  // Basic decoder logic
  io.uop := 0.U.asTypeOf(new MicroOp)
  io.uop.pc := 0.U // Placeholder, usually passed from frontend
  
  val opcode = io.instr(6, 0)
  val rd = io.instr(11, 7)
  val rs1 = io.instr(19, 15)
  val rs2 = io.instr(24, 20)
  val funct3 = io.instr(14, 12)
  val funct7 = io.instr(31, 25)

  // Very simplified decoing
  when(opcode === "b0110011".U) { // R-type
     io.uop.ctrl.rfWen := true.B
     io.uop.ctrl.aluOp := funct3
  }
}
