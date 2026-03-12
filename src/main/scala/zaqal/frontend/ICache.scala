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
  "h00a00093".U, // 00: addi x1, x0, 10
  "h00a00113".U, // 04: addi x2, x0, 10
  "h01400193".U, // 08: addi x3, x0, 20
  "h00208463".U, // 0c: beq x1, x2, +8      (0x0c + 8 = 0x14) -> TAKEN
  "h00100093".U, // 10: addi x1, x0, 1       (Should be skipped by flush/redirect)
  "h00308863".U, // 14: beq x1, x3, +16     (0x14 + 16 = 0x24) -> NOT TAKEN
  "h00100093".U, // 18: addi x1, x0, 1       (Correct path instruction)
  "h00100113".U, // 1c: addi x2, x0, 1       (Correct path instruction)
  "h00100193".U, // 20: addi x3, x0, 1       (Correct path instruction)
  "h0000006f".U  // 24: jal x0, 0            (Repeat/End)
).padTo(128, "h00000013".U))

  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) // Index into the Vec(128)

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U) // NOP if out of bounds
  }

  io.ready := true.B
}