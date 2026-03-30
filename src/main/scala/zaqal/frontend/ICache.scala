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
  // Block 0: Init & JAL (0x00 - 0x1c)
  "h014002ef".U, // 00: jal x5, 20 (0x14). Link register x5 should get PC+4 = 0x04
  "h00100a93".U, // 04: addi x21, x0, 1 (Fail if executed)
  "h00100b13".U, // 08: addi x22, x0, 1 (Fail if executed)
  "h00100b93".U, // 0c: addi x23, x0, 1 (Fail if executed)
  "h00100c13".U, // 10: addi x24, x0, 1 (Fail if executed)

  // 0x14 Target of JAL
  "h005000b3".U, // 14: add x1, x0, x5  (Copy x5 to x1 to verify it is 0x04)
  "h01c28313".U, // 18: addi x6, x5, 28 (x6 = 0x04 + 0x1c = 0x20)
  "h00030067".U, // 1c: jalr x0, 0(x6)  (Jump to 0x20)

  // Block 1: Verification (0x20 - 0x3c)
  "h06300513".U, // 20: addi x10, x0, 99 (Success marker, x10 = 99)
  "h0000006f".U  // 24: jal x0, 0 (Infinite loop to halt)

).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}