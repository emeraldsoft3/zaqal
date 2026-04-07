package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class ICache(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val pc = Input(UInt(xLen.W))
    val insts = Output(Vec(fetchWidth, UInt(instBits.W)))
    val ready = Output(Bool())
  })


val program = VecInit(Seq(
  "h00000093".U, // 00: addi x1, x0, 0      (Base address = 0)
  "h00008203".U, // 04: lb   x4, 0(x1)        (Mem[0] = 0x44)
  "h00408283".U, // 08: lb   x5, 4(x1)        (Mem[4] = 0xDD, Sign-ext)
  "h0040c303".U, // 0c: lbu  x6, 4(x1)        (Mem[4] = 0xDD, Zero-ext)
  "h00209383".U, // 10: lh   x7, 2(x1)        (Mem[2-3] = 0x1122)
  "h00609403".U, // 14: lh   x8, 6(x1)        (Mem[6-7] = 0xAABB, Sign-ext)
  "h0060d483".U, // 18: lhu  x9, 6(x1)        (Mem[6-7] = 0xAABB, Zero-ext)
  "h0000a503".U, // 1c: lw   x10, 0(x1)       (Mem[0-3] = 0x11223344)
  "h0040a583".U, // 20: lw   x11, 4(x1)       (Mem[4-7] = 0xAABBCCDD, Sign-ext)
  "h0040e603".U, // 24: lwu  x12, 4(x1)       (Mem[4-7] = 0xAABBCCDD, Zero-ext)
  "h0100b683".U, // 28: ld   x13, 16(x1)      (Mem[16-23] = 0xFFEEDDCCBBAA9988)
  "h00000013".U  // 2c: addi x0, x0, 0        (NOP)
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


