package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._
import utility.GTimer

class BPU extends Module {
  val io = IO(new Bundle {
    val redirect = Input(new BPURedirect)
    val out      = Decoupled(UInt(64.W)) // Sending PC to IMEM
  })

  val s0_pc = RegInit("h8000_0000".U(64.W))

  // Redirect has highest priority
  when(io.redirect.valid) {
    s0_pc := io.redirect.target
  } .elsewhen(io.out.fire) {  //fire is not a physical wire. It is a Scala "helper" function that is actually io.out.valid && io.out.ready
    s0_pc := s0_pc + 32.U // Move to next 8-instruction block
  }

  io.out.valid := true.B // Always trying to fetch
  io.out.bits  := s0_pc

  printf("[%d] BPU: s0_pc=%x | fire=%d\n", GTimer(), s0_pc, io.out.fire)
}