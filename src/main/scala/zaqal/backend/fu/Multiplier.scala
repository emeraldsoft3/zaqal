package zaqal.backend.fu

import chisel3._
import chisel3.util._
import zaqal.DecodeSignals

class Multiplier extends Module {
  val io = IO(new Bundle {
    val src1   = Input(UInt(64.W))
    val src2   = Input(UInt(64.W))
    val dec    = Input(new DecodeSignals)
    val result = Output(UInt(64.W))
  })

  // Simple combinatorial multiplier for now
  io.result := io.src1 * io.src2
}
