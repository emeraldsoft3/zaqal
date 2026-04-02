package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._

class IFU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val fetch_req  = Flipped(Decoupled(new FetchRequest)) // From FTQ (Request - metadata only)
    val toIbuffer  = Decoupled(new FetchPacket)         // To IBuffer (Direct)
    val icache_ready = Input(Bool())
    val insts_in     = Input(Vec(fetchWidth, UInt(instBits.W)))
  })

  // IFU Logic: Take PC from FTQ
  val predecoders = Seq.fill(fetchWidth)(Module(new Predecoder))
  for (i <- 0 until fetchWidth) {
    predecoders(i).io.inst := io.insts_in(i)
  }

  val packet = Wire(new FetchPacket)
  packet.pc          := io.fetch_req.bits.pc
  packet.mask        := io.fetch_req.bits.mask
  packet.prediction  := io.fetch_req.bits.prediction
  packet.ftqPtr      := io.fetch_req.bits.ftqPtr
  packet.epoch       := io.fetch_req.bits.epoch
  packet.instructions := io.insts_in
  for (i <- 0 until fetchWidth) {
    packet.pre_decoded(i) := predecoders(i).io.out
  }

  // Pass through the handshake
  io.toIbuffer.valid := io.fetch_req.valid
  io.toIbuffer.bits  := packet
  io.fetch_req.ready := io.toIbuffer.ready && io.icache_ready
}