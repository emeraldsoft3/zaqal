package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal.common._

class BRU(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val a = Input(UInt(p.xLen.W))
    val b = Input(UInt(p.xLen.W))
    val op = Input(UInt(4.W))
    val taken = Output(Bool())
  })

  io.taken := MuxLookup(io.op, false.B)(Seq(
    0.U -> (io.a === io.b),      // BEQ
    1.U -> (io.a =/= io.b),      // BNE
    2.U -> (io.a.asSInt < io.b.asSInt), // BLT
    3.U -> (io.a.asSInt >= io.b.asSInt), // BGE
    4.U -> (io.a < io.b),        // BLTU
    5.U -> (io.a >= io.b)        // BGEU
  ))
}
