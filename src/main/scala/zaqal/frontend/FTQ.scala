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

  // Increased to 64 for stress testing
  val queue = Module(new Queue(new FetchPacket, entries = 64))
  
  queue.io.enq <> io.in
  io.out       <> queue.io.deq

  // EXPOSE THESE FOR THE DEBUGGER
  //val write_ptr = GtkwaveWorkaround.getWritePtr(queue) // We'll look for this in GTK
  val debug_enq_fire = io.in.valid && io.in.ready

  // The FTQ must be cleared if the BPU was wrong
  queue.reset := reset.asBool || io.flush
  
  // Debug Output
  val occupancy = queue.io.count
  chisel3.dontTouch(occupancy)

  
}