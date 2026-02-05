package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal._

class Backend extends Module {
  val io = IO(new Bundle {
    val issue    = Flipped(Decoupled(new FetchPacket)) // Connects to FTQ out
    val redirect = Output(new BPURedirect)
  })

  // WE ARE STALLED: We never pull data from the FTQ
  io.issue.ready := false.B 

  // Default redirect values
  io.redirect.valid  := false.B
  io.redirect.target := 0.U

  // Debug: Print the FTQ status to the console
  when(io.issue.valid) {
    printf("Backend sees data is available, but is STALLED. PC: %x\n", io.issue.bits.pc)
  }
}