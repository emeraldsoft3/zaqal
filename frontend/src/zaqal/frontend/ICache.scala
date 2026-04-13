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
  "h08000093".U, // 04: li   x1, 0x80          (Base address for tests)
  "h01200113".U, // 08: li   x2, 0x12          (Data to store)
  "h01100493".U, //  addi x9, x0, 17
  "h02500513".U, //  addi x10, x0, 37
  "h1000b1af".U, // 0c: lr.d x3, (x1)          (Load Reserved from x1)
  "h1820b22f".U, // 10: sc.d x4, x2, (x1)      (SC success, return 0 in x4)
  "h1820b2af".U, // 14: sc.d x5, x2, (x1)      (SC failure, return 1 in x5)
  "h1000b1af".U, // 18: lr.d x3, (x1)          (Reload reserved)
  "h00408313".U, // 1c: addi x6, x1, 4         (Different address)
  "h182333af".U, // 20: sc.d x7, x2, (x6)      (SC failure, return 1 in x7)
  "h1000b1af".U, // 24: lr.d x3, (x1)          (Reserve 0x80)
  "h0090b023".U, // 28: sd   x9, (x1)          (Store to same addr - should CLEAR)
  "h18a0b42f".U, // 2c: sc.d x8, x10, (x1)      (Should FAIL, return 1 in x8)
  "h00000013".U  // 30: NOP
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


