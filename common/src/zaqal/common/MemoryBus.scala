package zaqal.common

import chisel3._
import chisel3.util._

// Simplified AXI-like Memory Bus for L1 Cache Refill
class MemoryBusReq(val addrWidth: Int) extends Bundle {
  val addr = UInt(addrWidth.W)
  val burstLen = UInt(8.W) // Number of beats
  val isWrite = Bool()
  // write data would go here for D-Cache
}

class MemoryBusResp(val dataWidth: Int) extends Bundle {
  val data = UInt(dataWidth.W)
  val last = Bool() // True on the last beat of a burst
}

class MemoryBus(val addrWidth: Int, val dataWidth: Int) extends Bundle {
  val req = Decoupled(new MemoryBusReq(addrWidth))
  val resp = Flipped(Decoupled(new MemoryBusResp(dataWidth)))
}
