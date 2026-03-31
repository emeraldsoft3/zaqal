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
  // Block 0: Init & Runtime JALR (0x00 - 0x1c)
  "h01000093".U, // 00: addi x1, x0, 0x10  (Base)
  "h01000113".U, // 04: addi x2, x0, 0x10  (Offset)
  "h002081b3".U, // 08: add x3, x1, x2     (x3 = 0x20)
  "h00018067".U, // 0c: jalr x0, x3, 0     (Jump to 0x20)
  "h00100213".U, // 10: addi x4, x0, 1     (Fail if executed)
  "h0000006f".U, // 14: jal x0, 0          (Fail halt)
  "h00000013".U, // 18: nop
  "h00000013".U, // 1c: nop

  // Block 1: Verification of JALR & 2-byte alignment test (0x20 - 0x3c)
  "h00100513".U, // 20: addi x10, x0, 1    (Success marker for Test 1)
  "h04100293".U, // 24: addi x5, x0, 0x41  (x5 = 0x41, Target = 0x40 due to LSB masking)
  "h00028067".U, // 28: jalr x0, x5, 0     (Jump to 0x40)
  "h00200213".U, // 2c: addi x4, x0, 2     (Fail if executed)
  "h0000006f".U, // 30: jal x0, 0          (Fail halt)
  "h00000013".U, // 34: nop
  "h00000013".U, // 38: nop
  "h00000013".U, // 3c: nop

  // Block 2: Verification of LSB Masking & 4-byte misalignment (0x40 - 0x5c)
  "h00100593".U, // 40: addi x11, x0, 1    (Success marker for Test 2)
  "h05e00313".U, // 44: addi x6, x0, 0x5e  (x6 = 0x5e, 4-byte misaligned)
  "h00030067".U, // 48: jalr x0, x6, 0     (Jump to 0x5e)
  "h00300213".U, // 4c: addi x4, x0, 3     (Fail if executed)
  "h0000006f".U, // 50: jal x0, 0          (Fail halt)
  "h00000013".U, // 54: nop
  "h00000013".U, // 58: nop
  "h00000013".U, // 5c: nop
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}