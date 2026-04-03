package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal.common._

class FTQ(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val enq = Flipped(Decoupled(new FetchPacket))
    val deq = Decoupled(new FetchPacket)
    val flush = Input(Bool())
  })

  val queue = Module(new Queue(new FetchPacket, 16))
  queue.io.enq <> io.enq
  io.deq <> queue.io.deq
  
  when(io.flush) {
    queue.reset := true.B
  }
}
