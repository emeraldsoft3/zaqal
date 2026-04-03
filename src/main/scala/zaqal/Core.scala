package zaqal

import chisel3._
import chisel3.util._
import zaqal.common._
import zaqal.frontend._
import zaqal.backend._

class Core(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val halt = Output(Bool())
  })

  val frontend = Module(new Frontend)
  val backend = Module(new Backend)

  // Connections
  backend.io.fetchPacket <> frontend.io.fetchPacket
  frontend.io.flush := backend.io.flush
  frontend.io.brpUpdate := backend.io.brpUpdate

  io.halt := false.B
}