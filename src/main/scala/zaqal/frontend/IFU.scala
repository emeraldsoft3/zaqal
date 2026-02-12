package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class IFU extends Module {
  val io = IO(new Bundle {
    val fetch_req  = Flipped(Decoupled(new FetchPacket)) // From FTQ (Request)
    val toIbuffer  = Decoupled(new FetchPacket)         // To IBuffer (Direct)
    val icache_ready = Input(Bool())
    val insts_in     = Input(Vec(8, UInt(32.W)))
  })

  // IFU Logic: Take PC from FTQ
  val predecoders = Seq.fill(8)(Module(new Predecoder))
  for (i <- 0 until 8) {
    predecoders(i).io.inst := io.insts_in(i)
  }

  val packet = Wire(new FetchPacket)
  packet.pc          := io.fetch_req.bits.pc
  packet.mask        := io.fetch_req.bits.mask
  packet.prediction  := io.fetch_req.bits.prediction
  packet.ftqPtr      := io.fetch_req.bits.ftqPtr
  packet.instructions := io.insts_in
  for (i <- 0 until 8) {
    packet.pre_decoded(i) := predecoders(i).io.out
  }

  // Pass through the handshake
  io.toIbuffer.valid := io.fetch_req.valid
  io.toIbuffer.bits  := packet
  io.fetch_req.ready := io.toIbuffer.ready && io.icache_ready
}