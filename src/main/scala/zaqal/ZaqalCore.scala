package zaqal

import chisel3._
import chisel3.util._


class ZaqalCore extends Module {
  // The "success" output is just a simple way to tell the testbench 
  // that the core is powered on and running without crashing.
  val io = IO(new Bundle {
    val success = Output(Bool())
  })

  val frontend = Module(new ZaqalFrontend)

  // Draining the frontend for now
  frontend.io.fetchOut.ready := true.B 

  when(frontend.io.fetchOut.fire) {
    // Print the PC in hex
    printf("Zaqal Fetched 8-wide block at PC: %x, Mask: %b\n", 
           frontend.io.fetchOut.bits.pc, 
           frontend.io.fetchOut.bits.mask)
  }

  io.success := true.B
}