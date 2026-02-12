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
    "h00100093".U, "h04000113".U, "h00000213".U, "h00120233".U,
    "h001002b3".U, "h00200313".U, "h0062d433".U, "h002404b3".U,
    "h00929463".U, "h00120233".U, "h00120213".U, "h00120213".U,
    "h00120213".U, "h00120213".U, "h00120213".U, "h00120213".U,
    "h00120213".U, "h00120213".U, "h00120213".U, "h00120213".U,
    "h00120213".U, "h00120213".U, "h00120213".U, "h00120213".U,
    "h00120213".U, "h00120213".U, "h00108093".U, "hfe20ace3".U,
    "h00625513".U, "h0000006f".U 
  ))

  val index = io.pc(7, 2) // Basic indexing logic

  for (i <- 0 until 8) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U) // NOP if out of bounds
  }

  io.ready := true.B
}