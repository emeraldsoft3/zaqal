package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class FTQ extends Module {
  val io = IO(new Bundle {
    val fromBpu   = Flipped(Decoupled(new FetchPacket))
    val toIfu     = Decoupled(new FetchPacket)
    val fromIfu   = Flipped(Decoupled(new FetchPacket))
    val toBackend = Decoupled(new FetchPacket)
    val flush     = Input(Bool())
    val occupancy = Output(UInt(7.W))
  })

  // Two-stage structure:
  // 1. Prediction Queue (Wait for IFU)
  val predQueue = Module(new Queue(new FetchPacket, entries = 32))
  predQueue.io.enq <> io.fromBpu
  io.toIfu         <> predQueue.io.deq

  // 2. Ready Queue (Wait for Backend)
  val readyQueue = Module(new Queue(new FetchPacket, entries = 32))
  readyQueue.io.enq <> io.fromIfu
  io.toBackend      <> readyQueue.io.deq

  // EXPOSE THESE FOR THE DEBUGGER
  //val write_ptr = GtkwaveWorkaround.getWritePtr(queue) // We'll look for this in GTK
  //val debug_enq_fire = io.in.valid && io.in.ready // This was for the old single queue

  // Global Flushes
  predQueue.reset  := reset.asBool || io.flush
  readyQueue.reset := reset.asBool || io.flush
  
  // Debug Output
  
  io.occupancy := predQueue.io.count + readyQueue.io.count
  chisel3.dontTouch(io.occupancy)

  
}