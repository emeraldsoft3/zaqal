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

 "h00008093".U, // 00: addi x1, x1, 1 | 00008093 for zero| 00108093 for one|  BNE control , 1 means BNE is true and branch is taken, meaning instruction 24 skips
 "h00310113".U, // 04: addi x2, x2, 3 | Buffer instructions
 "h00310113".U, // 08: addi x2, x2, 3 | Buffer instructions
 "h00310113".U, // 0C: addi x2, x2, 3 | Buffer instructions
 "h00310113".U, // 10: addi x2, x2, 3 | Buffer instructions
 "h00310113".U, // 14: addi x2, x2, 3 | Buffer instructions
  // --- Initialization ---
  //"h00a00093".U, // 00: addi x1, x0, 10   (x1 = 10, counter) //00900093 counter 9 , 00a00093 counter 10
  //"h00000093".U, // 00: addi x1, x0, 1 | 00000093 for zero| 00100093 for one|  BNE control , 1 means BNE is true and branch is taken, meaning instruction 24 skips
  //"h00b00113".U, // 04: addi x2, x0, 11   (x2 = 11, limit)
  //"h00000213".U, // 08: addi x4, x0, 0    (x4 = 0, total_sum)

  // --- Start of Outer Loop (PC: 0x0C) ---
  //"h00120233".U, // 0c: add  x4, x4, x1   (total_sum += counter)
  //"h001002b3".U, // 10: add  x5, x0, x1   (temp x5 = counter)
  //"h00200313".U, // 14: addi x6, x0, 2    (divisor = 2)

  // --- Even/Odd Check (Inner Logic) ---
  "h0262c433".U, // 18: div  x8, x5, x6   (x8 = x5 / 2)
  // "h0262c433".U, // 18: div  x8, x5, x6   (x8 = x5 / 2)
  // "h0262c433".U, // 18: div  x8, x5, x6   (x8 = x5 / 2)
  // "h0262c433".U, // 18: div  x8, x5, x6   (x8 = x5 / 2)
  // "h0262c433".U, // 18: div  x8, x5, x6   (x8 = x5 / 2)
  
 // "h026404b3".U, // 1c: mul  x9, x8, x6   (x9 = x8 * 2)
 "h00310113".U, // 14: addi x2, x2, 3 | Buffer instructions
  //"h00929463".U, // 20: bne  x5, x9, 8    (If temp % 2 != 0, skip to 0x28)
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