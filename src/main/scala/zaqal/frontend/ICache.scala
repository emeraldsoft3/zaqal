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
  "h01400113".U, // 04: addi x2, x0, 20
  "h402081b3".U, // 08: sub x3, x1, x2         (x3 = -10 = 0xfffffffffffffff6)
  "h80000237".U, // 0c: lui x4, 0x80000        (x4 = 0xffffffff80000000)
  "h0012029b".U, // 10: addiw x5, x4, 1        (x5 = 0xffffffff80000001)
  "hfff0031b".U, // 14: addiw x6, x0, -1       (x6 = 0xffffffffffffffff)
  "h406003bb".U, // 18: subw x7, x0, x6        (x7 = 1)
  "h0062043b".U, // 1c: addw x8, x4, x6        (0x80000000 + 0xffffffff = 0x7fffffff, sign-extend -> 0x000000007fffffff)
  "h0000006f".U  // 20: jal x0, 0              (Endless loop)
).padTo(128, "h00000013".U))

  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) // Index into the Vec(128)

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U) // NOP if out of bounds
  }

  io.ready := true.B
}