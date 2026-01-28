package utility

import chisel3._

object GTimer {
  def apply(): UInt = {
    val cycleReg = RegInit(0.U(64.W))
    cycleReg := cycleReg + 1.U
    cycleReg
  }
}