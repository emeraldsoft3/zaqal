package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class ICache extends Module {
  val io = IO(new Bundle {
    val pc = Input(UInt(64.W))
    val insts = Output(Vec(8, UInt(32.W)))
    val ready = Output(Bool())
  })

 val program = VecInit(Seq(
  // Step 1: Initialize registers using addi (our "li" substitute)
  "h00000093".U, // 00: addi x1, x0, 0     (x1 = 0)
  "hfff00113".U, // 04: addi x2, x0, -1    (x2 = 0xFFFFFFFFFFFFFFFF via sign-extension)
  "h00f00193".U, // 08: addi x3, x0, 15    (x3 = 15)

  // Step 2: Test Logic (Register-Immediate)
  "h00f17213".U, // 0c: andi x4, x2, 15    (x4 = x2 & 15 -> Should be 15)
  "h00f06293".U, // 10: ori  x5, x1, 15    (x5 = x1 | 15 -> Should be 15)
  "h00f24313".U, // 14: xori x6, x4, 15    (x6 = x4 ^ 15 -> Should be 0)

  // Step 3: Test Logic (Register-Register)
  "h003173b3".U, // 18: and  x7, x2, x3    (x7 = x2 & x3 -> Should be 15)
  "h0030e433".U, // 1c: or   x8, x1, x3    (x8 = x1 | x3 -> Should be 15)
  "h003244b3".U, // 20: xor  x9, x4, x3    (x9 = x4 ^ x3 -> Should be 0)

  
))

  val index = io.pc(8, 2) // 5 bits (0-31), sufficient for 30 instructions

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U) // NOP if out of bounds
  }

  io.ready := true.B
}