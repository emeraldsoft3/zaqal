package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class IFU extends Module {
  val io = IO(new Bundle {
    val fetch_req  = Flipped(Decoupled(new FetchPacket)) // From FTQ (Request)
    val fetch_resp = Decoupled(new FetchPacket)         // To FTQ (Data)
  })

  val icache = Module(new ICache)

  // IFU Logic: Take PC from FTQ, get insts from ICache
  icache.io.pc := io.fetch_req.bits.pc

  val packet = Wire(new FetchPacket)
  packet.pc          := io.fetch_req.bits.pc
  packet.mask        := io.fetch_req.bits.mask
  packet.prediction  := io.fetch_req.bits.prediction
  packet.instructions := icache.io.insts

  // Pass through the handshake
  io.fetch_resp.valid := io.fetch_req.valid
  io.fetch_resp.bits  := packet
  io.fetch_req.ready  := io.fetch_resp.ready
}