package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal._

class Backend extends Module {
  val io = IO(new Bundle {
    val dispatch = Flipped(Decoupled(new MicroOp))
    val redirect = Output(new BPURedirect)
  })

  val exec = Module(new Execute)

  // Enforce Handshake Integrity
  exec.io.in <> io.dispatch

  // Default redirect (no branch prediction logic yet in Backend)
  io.redirect.valid := false.B
  io.redirect.target := 0.U
}