package zaqal.backend.fu

import chisel3._
import chisel3.util._

class Adder extends Module {
  val io = IO(new Bundle {
    val src1   = Input(UInt(64.W))
    val src2   = Input(UInt(64.W))
    val is_add = Input(Bool())
    val result = Output(UInt(64.W))
  })

  // Basic addition for now, will expand for SUB/Word ops later
  io.result := io.src1 + io.src2
}
