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
  "h00000093".U, // 00: NOP
  "h02000093".U, // 04: addi x1, x0, 0x20
  "h01200113".U, // 08: addi x2, x0, 0x12
  "h00000013".U, // 0c: NOP
  "h00000013".U, // 10: NOP
  "h02208533".U, // 14: mul  x10, x1, x2       (0x20 * 0x12 = 0x240)
  "h00000013".U, // 18: NOP
  "h00000013".U, // 1c: NOP
  "h022095B3".U, // 20: mulh x11, x1, x2       (high bits = 0)
  "h00000013".U, // 24: NOP
  "h00000013".U, // 28: NOP
  "hfff00093".U, // 2c: li   x1, -1            (0xFFFFFFFFFFFFFFFF)
  "h00200113".U, // 30: li   x2, 2             (0x2)
  "h00000013".U, // 34: NOP
  "h00000013".U, // 38: NOP
  "h02209633".U, // 3c: mulh x12, x1, x2       (-1 * 2 = -2 -> high bits=0xFF...FF)
  "h022086BB".U, // 40: mulw x13, x1, x2       (word mul)
  "h02254733".U, // 44: div  x14, x10, x2      (0x240 / 2 = 0x120)
  "h022567B3".U, // 48: rem  x15, x10, x2      (0x240 % 2 = 0)
  "h0220d833".U, // 4c: divu x16, x1, x2       (0xFF...FF / 2 = 0x7F...FF)
  "h0200C8B3".U, // 50: div  x17, x1, x0       (-1 / 0 = -1)
  "h0200E933".U, // 54: rem  x18, x1, x0       (-1 % 0 = -1)
  "h00000013".U  // 58: NOP
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


