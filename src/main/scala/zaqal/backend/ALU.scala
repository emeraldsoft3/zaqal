package zaqal.backend

import chisel3._
import chisel3.util._

class ALU extends Module {
  val io = IO(new Bundle {
    val a    = Input(UInt(64.W))
    val b    = Input(UInt(64.W))
    val op   = Input(UInt(7.W)) 
    val out  = Output(UInt(64.W))
  })

  // RISC-V uses funct7 and funct3 to define the ALU op. 
  // We concatenated them in the decoder into 'func'.
  io.out := MuxLookup(io.op, io.a + io.b)(Seq(
    "b0000000000".U -> (io.a + io.b), // ADD / ADDI
    "b0100000000".U -> (io.a - io.b), // SUB
    "b0000000111".U -> (io.a & io.b), // AND
    "b0000000110".U -> (io.a | io.b)  // OR
  ))
}