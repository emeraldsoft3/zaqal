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
  "h00000093".U, // 1c: NOP (Filler)
  "h02000093".U, // 20: addi x1, x0, 32       (Base x1 = 0x20, which is mem[4])
  "h01200113".U, // 24: addi x2, x0, 0x12     (x2 = 0x12)
  "h00208023".U, // 28: sb   x2, 0(x1)         (Mem[0x20] = 0x12, check mem_4 byte 0)
  "h34560193".U, // 2c: addi x3, x0, 0x3456   (x3 = 0x3456)
  "h00309423".U, // 30: sh   x3, 8(x1)         (Mem[0x28] = 0x3456, check mem_5 bytes 0-1)
  "h789ab237".U, // 34: lui  x4, 0x789AB      (x4 = 0x789AB000)
  "h0040a223".U, // 38: sw   x4, 4(x1)         (Mem[0x24] = 0x789AB000, check mem_4 bytes 4-7)
  "hdeada2b7".U, // 3c: lui  x5, 0xDEADA      (x5 = 0xDEADA000)
  "hbdc28293".U, // 40: addi x5, x5, 0xBDC   (x5 = 0xDEADA BDC)
  "h0050bc23".U, // 44: sd   x5, 24(x1)        (Mem[0x38] = 0xDEADA BDC, check mem_7)
  "h00000013".U  // 48: NOP
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


