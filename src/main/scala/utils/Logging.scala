package utility

import chisel3._

object XSDebug {
  def apply(fmt: String, args: Bits*) = {
    // We explicitly cast the sequence to Bits to satisfy the compiler
    printf(s"[%d] " + fmt, GTimer() +: args: _*)
  }
}