package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class FTQ extends Module {
  val io = IO(new Bundle {
    val in    = Flipped(Decoupled(new FetchPacket))
    val out   = Decoupled(new FetchPacket)
    val flush = Input(Bool())
  })

  // Agile: Use a standard Chisel Queue as our initial FTQ
  val queue = Module(new Queue(new FetchPacket, entries = 4))
  
  queue.io.enq <> io.in
  io.out       <> queue.io.deq

  // When a redirect happens, we clear the queue
  when(io.flush) {
    queue.reset := true.B // Simplest way to flush in Agile V1
  }
}