package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._

class Backend(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val dispatch = Flipped(Decoupled(new MicroOp))
    val redirect = Output(new BPURedirect)
  })

  val exec = Module(new Execute)

  // Enforce Handshake Integrity
  exec.io.in <> io.dispatch

  // Route redirection from Execute to Frontend
  io.redirect := exec.io.redirect
}