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
  // Block 0: Init (0x00 - 0x1c)
  "hFFF00093".U, // 00: addi x1, x0, -1 (xFFF...FF)
  "h00100113".U, // 04: addi x2, x0, 1
  "h00000a93".U, // 08: addi x21, x0, 0
  "h00000b13".U, // 0c: addi x22, x0, 0
  "h00000b93".U, // 10: addi x23, x0, 0
  "h00000c13".U, // 14: addi x24, x0, 0
  "h00128293".U, // 18: addi x5, x5, 1
  "h00128293".U, // 1c: addi x5, x5, 1

  // Block 1: Test BLT (Signed) (0x20 - 0x3c)
  "h0220c063".U, // 20: blt x1, x2, 32 (Tgt 0x40) (-1 < 1 is True)
  "h00100a93".U, // 24: addi x21, x0, 1 (Fail)
  "h0200006f".U, // 28: jal x0, 32 (Next)
  "h00128293".U, // 2c: addi x5, x5, 1
  "h00128293".U, // 30: addi x5, x5, 1
  "h00128293".U, // 34: addi x5, x5, 1
  "h00128293".U, // 38: addi x5, x5, 1
  "h00128293".U, // 3c: addi x5, x5, 1

  // Block 2: Test BLTU (Unsigned) (0x40 - 0x5c)
  "h00200a93".U, // 40: addi x21, x0, 2 (Success 1)
  "h0020e663".U, // 44: bltu x1, x2, 12 (Tgt 0x50) (FF < 1 is False)
  "h00200b13".U, // 48: addi x22, x0, 2 (Success 2)
  "h0140006f".U, // 4c: jal x0, 20 (Tgt 0x60)
  "h00100b13".U, // 50: addi x22, x0, 1 (Fail)
  "h00128293".U, // 54: addi x5, x5, 1
  "h00128293".U, // 58: addi x5, x5, 1
  "h00128293".U, // 5c: addi x5, x5, 1

  // Block 3: Test BGE (Signed) & BGEU (Unsigned) (0x60 - 0x7c)
  "h00115863".U, // 60: bge x2, x1, 16 (Tgt 0x70) (1 >= -1 is True)
  "h00100b93".U, // 64: addi x23, x0, 1 (Fail)
  "h0100006f".U, // 68: jal x0, 16 (Next)
  "h00000013".U, // 6c: nop
  "h00200b93".U, // 70: addi x23, x0, 2 (Success 3)
  "h00117663".U, // 74: bgeu x2, x1, 12 (Tgt 0x80) (1 >= FF is False)
  "h00200c13".U, // 78: addi x24, x0, 2 (Success 4)
  "h00000013".U  // 7c: nop
).padTo(256, "h00128293".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}