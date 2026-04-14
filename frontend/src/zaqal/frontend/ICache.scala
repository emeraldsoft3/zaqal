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
  "h00700193".U, // 08: li   x3, 7         (Data to store)
  "h0030b023".U, // 28: sd   x3, (x1)          (Store 7 to 0x80)  
  "habc00213".U, // 2c: li   x4, 0xABC         (Random number into x4)
  "h0020b5af".U, // 30: amoadd.d  x11, x2, (x1) (7 + 0x12 = 0x19)
  "h0820b62f".U, // 34: amoswap.d x12, x2, (x1) (Swap 0x19 with 0x12)
  "h2040b6af".U, // 38: amoxor.d  x13, x4, (x1) (0x12 XOR 0xABC)
  "h8020b7af".U, // 3c: amomin.d  x15, x2, (x1)
  "hA020b82f".U, // 40: amomax.d  x16, x2, (x1)
  "h4020b8af".U, // 44: amoor.d   x17, x2, (x1)
  "h0020a72f".U, // 48: amoadd.w  x14, x2, (x1)
  "h00000013".U  // 4c: NOP
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


