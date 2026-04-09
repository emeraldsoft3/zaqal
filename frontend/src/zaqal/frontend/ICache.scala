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
  "h02000093".U, // 04: addi x1, x0, 0x20     (Base x1 = 0x20)
  "h01200113".U, // 08: addi x2, x0, 0x12     (x2 = 0x12)
  "h0020A0A3".U, // 0c: sw   x2, 1(x1)         (Mem[0x21] = 0x12, UNALIGNED)
  "h0010A303".U, // 10: lw   x6, 1(x1)         (x6 = 0x12, check Load)
  "hdeada2b7".U, // 14: lui  x5, 0xDEADA      (x5 = 0xDEADA000)
  "hbdc28293".U, // 18: addi x5, x5, 0xBDC    (x5 = 0xDEADA BDC)
  "h0050B3A3".U, // 1c: sd   x5, 7(x1)         (Mem[0x27] = 0xDEADABDC, CROSS BOUNDARY 0x27-0x2E)
  "h0070B603".U, // 20: ld   x12, 7(x1)        (x12 = 0xDEADABDC, check Load)
  "h00000013".U  // 24: NOP
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


