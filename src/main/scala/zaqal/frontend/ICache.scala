package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._

class ICache(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val pc = Input(UInt(xLen.W))
    val insts = Output(Vec(fetchWidth, UInt(instBits.W)))
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

  // Block 3: Epoch Flip Test (0x60 - 0x7c)
  // Target of previous jump. Let's do a BEQ that always fails prediction to trigger a flush
  "h00000613".U, // 60: addi x12, x0, 0    (x12 = 0)
  "h00060e63".U, // 64: beq x12, x0, 28    (Jump to 0x80 - mispredict flush triggers!)
  "h00500213".U, // 68: addi x4, x0, 5     (Wrong path instruction)
  "h00060a63".U, // 6c: beq x12, x0, 20    (Shadowed branch on wrong path)
  "h00000013".U, // 70: nop

  // Block 4: Target of Epoch Test (0x80)
  "h00100693".U, // 80: addi x13, x0, 1    (Recovery success!)
  "h00000013".U, // 84: nop
  "h00000013".U, // 88: nop
  "h00000013".U, // 8c: nop
  "h00000013".U, // 90: nop
  "h00000013".U, // 94: nop
  "h00000013".U, // 98: nop

  // Block 5: Day 6 Tests - Page Boundary Branch at the last slot of packet (0x9c)
  "h0240006f".U, // 9c: jal x0, 0x24 (Jump forward to 0xc0)
  
  // (0xa0 - 0xbc padded with NOPs to actually reach 0xc0)
  "h00000013".U, // a0: nop
  "h00000013".U, // a4: nop
  "h00000013".U, // a8: nop
  "h00000013".U, // ac: nop
  "h00000013".U, // b0: nop
  "h00000013".U, // b4: nop
  "h00000013".U, // b8: nop
  "h00000013".U, // bc: nop
  
  // Block 6: Target of Page Boundary check (0xc0)
  "h00100713".U, // c0: addi x14, x0, 1    (Page boundary jump success)
  
  // Day 6 Tests - Back-to-Back branches (0xc4 - 0xc8)
  "h00000793".U, // c4: addi x15, x0, 0
  "h00078263".U, // c8: beq x15, x0, 4     (Jump to cc)
  "h00000013".U, // cc: nop (Success)
  "h00078263".U, // d0: beq x15, x0, 4     (Another branch right after)
  "h00000013".U, // d4: nop (Success)

  // Day 6 Tests - Hazard: ALU/Load to Branch (0xd8 - 0xdc)
  "h00500813".U, // d8: addi x16, x0, 5    (Producer)
  "h00080663".U, // dc: beq x16, x0, 12    (Consumer, will fail, fallthrough to 0xe0)
  
  // 0xe0 Final Halt!
  "h0000006f".U, // e0: jal x0, 0          (Halt)
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}