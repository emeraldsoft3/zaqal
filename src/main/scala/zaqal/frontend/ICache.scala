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
 //00108093 means x24 skips , 00008093 means no skip
 "h00108093".U, // 00: addi x1, x1, 1 | 00008093 for zero| 00108093 for one|  BNE control , 1 means BNE is true and branch is taken, meaning instruction 24 skips
 "h00a10113".U, // 04: addi x2, x2, 10 | a number for division
 "h00218193".U, // 08: addi x3, x3, 2 | divided by
 "h00320213".U, // 0C: addi x4, x4, 3 | Buffer instructions
 "h00320213".U, // 10: addi x4, x4, 3 | Buffer instructions
 "h00320213".U, // 14: addi x4, x4, 3 | Buffer instructions
 "h00320213".U, // 18: addi x4, x4, 3 | Buffer instructions
 "h023142b3".U, // 1c: div  x5, x2, x3   (x5 = x2 / 3) 
 "h00101463".U, // 20: bne  x0, x1, 8    
 "h00738393".U, // 24: addi x7, x7, 7    (Bonus add to x7 if even)

  // --- Long Straight Path (FTQ Stress Test) ---
  "h00120213".U, // 28: addi x4, x4, 1    (total_sum++)
  "h00120213".U, // 2c: addi x4, x4, 1
  "h00120213".U, // 30: addi x4, x4, 1
  "h00120213".U, // 34: addi x4, x4, 1
  "h00120213".U, // 38: addi x4, x4, 1
  "h00120213".U, // 3c: addi x4, x4, 1
  "h00120213".U, // 40: addi x4, x4, 1
  "h00120213".U, // 44: addi x4, x4, 1
  "h00120213".U, // 48: addi x4, x4, 1
  "h00120213".U, // 4c: addi x4, x4, 1
  "h00120213".U, // 50: addi x4, x4, 1
  "h00120213".U, // 54: addi x4, x4, 1
  "h00120213".U, // 58: addi x4, x4, 1
  "h00120213".U, // 5c: addi x4, x4, 1
  "h00120213".U, // 60: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1

  //
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  "h00120213".U, // 64: addi x4, x4, 1
  //

  // --- Loop Control ---
  //"h00108093".U, // 68: addi x1, x1, 1    (counter++)
  //"hfe20ace3".U, // 6c: blt  x1, x2, -72  (If counter < limit, jump back to 0x0C)

  // --- Exit ---
 // "h00625513".U, // 70: srli x10, x4, 6   (x10 = total_sum >> 6)
 // "h0000006f".U  // 74: jal  x0, 0        (Halt/Infinite Loop)
))

  val index = io.pc(8, 2) // 5 bits (0-31), sufficient for 30 instructions

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U) // NOP if out of bounds
  }

  io.ready := true.B
}