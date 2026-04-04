package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.common._

class Multiplier(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1   = Input(UInt(xLen.W))
    val src2   = Input(UInt(xLen.W))
    val dec    = Input(new DecodeSignals)
    val result = Output(UInt(xLen.W))
  })

  // Simple combinatorial multiplier for now
  io.result := io.src1 * io.src2
}
