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
  // Block 0: Initialization (0x00 - 0x1c)
  "h00200093".U, // 00: addi x1, x0, 2
  "h00200113".U, // 04: addi x2, x0, 2
  "h00000513".U, // 08: addi x10, x0, 0
  "h00000013".U, // 0c: nop
  "h00000013".U, // 10: nop
  "h00000013".U, // 14: nop
  "h00000013".U, // 18: nop
  "h00000013".U, // 1c: nop
  
  // Block 1: Loop (0x20 - 0x3c)
  "h00150513".U, // 20: addi x10, x10, 1   (Target)
  "h00400213".U, // 24: addi x4, x0, 4
  "hfe208ce3".U, // 28: beq x1, x2, -8      (28 -> 20) Bwd Taken Hit (Intra-block)
  "h00300193".U  // 2c: addi x3, x0, 3         (End)
).padTo(256, "h00000013".U))

  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}