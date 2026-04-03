package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal.common._

class ALU(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val a = Input(UInt(p.xLen.W))
    val b = Input(UInt(p.xLen.W))
    val op = Input(UInt(4.W))
    val res = Output(UInt(p.xLen.W))
  })

  io.res := MuxLookup(io.op, 0.U)(Seq(
    0.U -> (io.a + io.b),
    1.U -> (io.a - io.b),
    2.U -> (io.a & io.b),
    3.U -> (io.a | io.b),
    4.U -> (io.a ^ io.b)
  ))
}
