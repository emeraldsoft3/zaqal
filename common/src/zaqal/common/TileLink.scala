package zaqal.common

import chisel3._
import chisel3.util._

// ============================================================================
// TileLink-C (Cached TileLink) Protocol Specification
// Inspired by XiangShan & SiFive TileLink Standard Specifications
// ============================================================================

// 1. Channel Opcodes
object TLMessages {
  // Channel A (Client -> Hub / Outward)
  val PutFullData    = 0.U(3.W)
  val PutPartialData = 1.U(3.W)
  val ArithmeticData = 2.U(3.W)
  val LogicalData    = 3.U(3.W)
  val Get            = 4.U(3.W)
  val Hint           = 5.U(3.W)
  val AcquireBlock   = 6.U(3.W)
  val AcquirePerm    = 7.U(3.W)

  // Channel B (Hub -> Client / Inward Probes)
  val ProbeBlock     = 6.U(3.W)
  val ProbePerm      = 7.U(3.W)

  // Channel C (Client -> Hub / Outward ProbeAcks & Releases)
  val AccessAck      = 0.U(3.W)
  val AccessAckData  = 1.U(3.W)
  val HintAck        = 2.U(3.W)
  val ProbeAck       = 4.U(3.W)
  val ProbeAckData   = 5.U(3.W)
  val Release        = 6.U(3.W)
  val ReleaseData    = 7.U(3.W)

  // Channel D (Hub -> Client / Inward Grants)
  val Grant          = 4.U(3.W)
  val GrantData      = 5.U(3.W)
  val ReleaseAck     = 6.U(3.W)
}

// 2. Coherence Permissions (Cap, Grow, Prune)
object TLPermissions {
  // Grow: Used in Channel A Acquire (Client requesting permissions)
  val NtoB = 0.U(3.W) // None to Branch (Read-Only / Shared)
  val NtoT = 1.U(3.W) // None to Trunk (Read-Write / Exclusive)
  val BtoT = 2.U(3.W) // Branch to Trunk (Upgrade Shared to Exclusive)

  // Cap: Used in Channel B Probe (Hub capping client permissions)
  val toT  = 0.U(3.W) // Cap to Trunk
  val toB  = 1.U(3.W) // Cap to Branch (Downgrade to Shared)
  val toN  = 2.U(3.W) // Cap to None (Invalidate)

  // Prune: Used in Channel C ProbeAck & Release (Client reporting new permissions)
  val TtoB = 0.U(3.W) // Trunk to Branch (Downgraded Exclusive -> Shared)
  val TtoN = 1.U(3.W) // Trunk to None (Evicted Exclusive -> Invalid)
  val BtoN = 2.U(3.W) // Branch to None (Evicted Shared -> Invalid)
  val TtoT = 3.U(3.W) // Retain Trunk
  val BtoB = 4.U(3.W) // Retain Branch
  val NtoN = 5.U(3.W) // Did not hold line (Miss)
}

// 3. TileLink Bundle Parameters
case class TLBundleParameters(
  addrBits: Int = 64,
  dataBits: Int = 256,
  sourceBits: Int = 6,
  sinkBits: Int = 6,
  sizeBits: Int = 4
)

// 4. Channel A: Memory Requests & Cache Acquires (Master -> Slave)
class TLBundleA(val params: TLBundleParameters) extends Bundle {
  val opcode  = UInt(3.W)
  val param   = UInt(3.W)
  val size    = UInt(params.sizeBits.W)
  val source  = UInt(params.sourceBits.W)
  val address = UInt(params.addrBits.W)
  val mask    = UInt((params.dataBits / 8).W)
  val data    = UInt(params.dataBits.W)
  val corrupt = Bool()
}

// 5. Channel B: Cache Probes & Invalidation Requests (Slave -> Master)
class TLBundleB(val params: TLBundleParameters) extends Bundle {
  val opcode  = UInt(3.W)
  val param   = UInt(3.W)
  val size    = UInt(params.sizeBits.W)
  val source  = UInt(params.sourceBits.W)
  val address = UInt(params.addrBits.W)
  val mask    = UInt((params.dataBits / 8).W)
  val data    = UInt(params.dataBits.W)
  val corrupt = Bool()
}

// 6. Channel C: Probe Acknowledgments & Dirty Releases (Master -> Slave)
class TLBundleC(val params: TLBundleParameters) extends Bundle {
  val opcode  = UInt(3.W)
  val param   = UInt(3.W)
  val size    = UInt(params.sizeBits.W)
  val source  = UInt(params.sourceBits.W)
  val address = UInt(params.addrBits.W)
  val data    = UInt(params.dataBits.W)
  val corrupt = Bool()
}

// 7. Channel D: Grants, GrantData, and ReleaseAcks (Slave -> Master)
class TLBundleD(val params: TLBundleParameters) extends Bundle {
  val opcode  = UInt(3.W)
  val param   = UInt(3.W)
  val size    = UInt(params.sizeBits.W)
  val source  = UInt(params.sourceBits.W)
  val sink    = UInt(params.sinkBits.W)
  val denied  = Bool()
  val data    = UInt(params.dataBits.W)
  val corrupt = Bool()
}

// 8. Channel E: Grant Final Acknowledgment (Master -> Slave)
class TLBundleE(val params: TLBundleParameters) extends Bundle {
  val sink    = UInt(params.sinkBits.W)
}

// 9. Standard TileLink-C 5-Channel Interface
class TLBundle(val params: TLBundleParameters) extends Bundle {
  val a = Decoupled(new TLBundleA(params))            // Outward: Requests & Acquires
  val b = Flipped(Decoupled(new TLBundleB(params)))   // Inward: Probes
  val c = Decoupled(new TLBundleC(params))            // Outward: ProbeAcks & Releases
  val d = Flipped(Decoupled(new TLBundleD(params)))   // Inward: Grants & Responses
  val e = Decoupled(new TLBundleE(params))            // Outward: GrantAcks

  def tieoffSlave(): Unit = {
    a.ready := true.B
    b.valid := false.B
    b.bits  := 0.U.asTypeOf(new TLBundleB(params))
    c.ready := true.B
    d.valid := false.B
    d.bits  := 0.U.asTypeOf(new TLBundleD(params))
    e.ready := true.B
  }

  def tieoffMaster(): Unit = {
    a.valid := false.B
    a.bits  := 0.U.asTypeOf(new TLBundleA(params))
    b.ready := true.B
    c.valid := false.B
    c.bits  := 0.U.asTypeOf(new TLBundleC(params))
    d.ready := true.B
    e.valid := false.B
    e.bits  := 0.U.asTypeOf(new TLBundleE(params))
  }
}

// 10. TileLink to Legacy MemoryBus Bridge (Allows single-core legacy testbenches to operate unchanged)
class TLToMemoryBusBridge(val params: TLBundleParameters) extends Module {
  val io = IO(new Bundle {
    val tl = Flipped(new TLBundle(params))
    val mem = new MemoryBus(params.addrBits, params.dataBits)
  })

  // Channel A -> mem.req
  io.mem.req.valid := io.tl.a.valid
  io.mem.req.bits.addr := io.tl.a.bits.address
  io.mem.req.bits.burstLen := 1.U
  io.mem.req.bits.isWrite := (io.tl.a.bits.opcode === TLMessages.PutFullData || io.tl.a.bits.opcode === TLMessages.PutPartialData)
  io.tl.a.ready := io.mem.req.ready

  // mem.resp -> Channel D
  io.tl.d.valid := io.mem.resp.valid
  io.tl.d.bits.opcode := Mux(io.mem.req.bits.isWrite, TLMessages.AccessAck, TLMessages.GrantData)
  io.tl.d.bits.param := TLPermissions.toT
  io.tl.d.bits.size := log2Ceil(params.dataBits / 8).U
  io.tl.d.bits.source := 0.U
  io.tl.d.bits.sink := 0.U
  io.tl.d.bits.denied := false.B
  io.tl.d.bits.data := io.mem.resp.bits.data
  io.tl.d.bits.corrupt := false.B
  io.mem.resp.ready := io.tl.d.ready

  // Channel B: No external probes in standalone uniprocessor mode
  io.tl.b.valid := false.B
  io.tl.b.bits := 0.U.asTypeOf(new TLBundleB(params))

  // Channel C: Sink ProbeAck / Release
  io.tl.c.ready := true.B

  // Channel E: Sink GrantAck
  io.tl.e.ready := true.B
}

