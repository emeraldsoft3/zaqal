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
  "h00100093".U, // 00: addi x1, x0, 1
  "h12345117".U, // 04: auipc x2, 0x12345   (x2 = 0x80000004 + 0x12345000 = 0x92345004)
  "h00200193".U, // 08: addi x3, x0, 2
  "h00000217".U, // 0c: auipc x4, 0         (x4 = 0x8000000c + 0 = 0x8000000c)
  "h00300293".U, // 10: addi x5, x0, 3
  "hfffff317".U, // 14: auipc x6, 0xfffff   (x6 = 0x80000014 - 0x1000 = 0x7ffff014)
  "h0000006f".U  // 18: jal x0, 0           (Endless loop)
).padTo(128, "h00000013".U))

  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) // Index into the Vec(128)

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U) // NOP if out of bounds
  }

  io.ready := true.B
}