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
  // --- Setup ---
  "h00100093".U, // 00: addi x1, x0, 1      (x1 = 1)
  "hfff00113".U, // 04: addi x2, x0, -1     (x2 = All 1s / -1)
  "h00400193".U, // 08: addi x3, x0, 4      (x3 = 4)

  // --- 64-bit Shifts ---
  "h00309233".U, // 0c: sll  x4, x1, x3     (1 << 4 = 16)
  "h003252b3".U, // 10: srl  x5, x4, x3     (16 >> 4 = 1)
  "h40315333".U, // 14: sra  x6, x2, x3     (-1 >> 4 = -1)

  "hff000113".U, // addi x2, x0, -16    (x2 = 0xFFFFFFFFFFFFFFF0)
"h00200193".U, // addi x3, x0, 2      (x3 = 2)
"h40315333".U,  // sra  x6, x2, x3     (x6 should become -4 / 0xFFFFFFFFFFFFFFFC)

  // --- 32-bit "W" Shifts ---
  "h003093bb".U, // 18: sllw x7, x1, x3     (1 << 2 = 4)
  "h0032543b".U, // 1c: srlw x8, x7, x3     (4 >> 2 = 1)
  "h4033d83b".U, // 20: sraw x16, x7, x3    (4 >> 2 = 1)

  // --- Immediate Shifts (64-bit) ---
  "h00409493".U, // 24: slli x9, x1, 4      (1 << 4 = 16)
  "h0044d513".U, // 28: srli x10, x9, 4     (16 >> 4 = 1)
  "h40215a13".U, // 2c: srai x20, x2, 2      (-16 >> 2 = -4)

  // --- Word-Immediate Shifts (32-bit) ---
  "h00409a9b".U, // 30: slliw x21, x1, 4     (1 << 4 = 16)
  "h002a5b1b".U, // 34: srliw x22, x20, 2    (-4 as 32-bit >> 2 = 0x3fffffff)
  "h402a5b9b".U, // 38: sraiw x23, x20, 2    (-4 as 32-bit >> 2 = -1)

  // --- Logic Setup ---
  "h00000593".U, // 28: addi x11, x0, 0     (x11 = 0)
  "hfff00613".U, // 2c: addi x12, x0, -1    (x12 = -1)
  "h00f00693".U, // 30: addi x13, x0, 15    (x13 = 15)

  // --- Logic Register-Immediate ---
  "h00f67713".U, // 34: andi x14, x12, 15   (x14 = 15)
  "h00f5e793".U, // 38: ori  x15, x11, 15   (x15 = 15)
  "h00f74813".U, // 3c: xori x16, x14, 15   (x16 = 0)

  // --- Logic Register-Register ---
  "h00d678b3".U, // 40: and  x17, x12, x13  (x17 = 15)
  "h00d5e933".U, // 44: or   x18, x11, x13  (x18 = 15)
  "h00d749b3".U, // 48: xor  x19, x14, x13  (x19 = 0)
  
 // "h0000006f".U  // 4c: jal x0, 0           (Endless loop)
).padTo(128, "h00000013".U))

  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) // Index into the Vec(128)

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U) // NOP if out of bounds
  }

  io.ready := true.B
}