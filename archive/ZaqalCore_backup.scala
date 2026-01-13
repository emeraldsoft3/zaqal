package zaqal

import chisel3._
import _root_.circt.stage.ChiselStage

class ZaqalCore extends Module {
  val io = IO(new Bundle {
    val out = Output(UInt(8.W))
  })
  val countReg = RegInit(0.U(8.W))
  countReg := countReg + 1.U
  io.out := countReg
}

object Elaborate extends App {
  println("SUCCESS: Chisel is generating Verilog for ZaqalCore...")
  ChiselStage.emitSystemVerilogFile(
    new ZaqalCore,
    Array("--target-dir", "build")
  )
}