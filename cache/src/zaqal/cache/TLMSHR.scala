package zaqal.cache

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

// ============================================================================
// TileLink-C MSHR (Miss Status Holding Register)
// Implements Channel A (Acquire), Channel D (Grant), Channel E (GrantAck)
// Supports Grow permissions: NtoB (Shared Load), NtoT (Exclusive Store),
// and BtoT (Upgrade Shared to Exclusive)
// ============================================================================

class TLMSHR(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val alloc = Flipped(Decoupled(new Bundle {
      val addr        = UInt(xLen.W)
      val data        = UInt(xLen.W) // Latched 64-bit write data for store misses
      val load_id     = UInt(phyRegIdxWidth.W)
      val is_write    = Bool()
      val is_upgrade  = Bool()       // True if upgrading existing Shared line to Exclusive (BtoT)
      val is_prefetch = Bool()
      val sink_is_l2  = Bool()
    }))

    // TileLink-C Master Ports (Channels A, D, E)
    val tl_a = Decoupled(new TLBundleA(tlBundleParams))
    val tl_d = Flipped(Decoupled(new TLBundleD(tlBundleParams)))
    val tl_e = Decoupled(new TLBundleE(tlBundleParams))

    // Refill Output to L1 D-Cache Data/Tag Arrays
    val refill_out = Decoupled(new Bundle {
      val addr          = UInt(xLen.W)
      val data          = UInt(256.W)
      val write_data    = UInt(xLen.W)
      val load_id       = UInt(phyRegIdxWidth.W)
      val is_write      = Bool()
      val is_prefetch   = Bool()
      val sink_is_l2    = Bool()
      val granted_param = UInt(3.W)
    })
  })

  val s_IDLE :: s_ACQUIRE :: s_WAIT_GRANT :: s_GRANT_ACK :: s_REFILL :: Nil = Enum(5)
  val state = RegInit(s_IDLE)

  val reqAddr         = Reg(UInt(xLen.W))
  val reqWriteData    = Reg(UInt(xLen.W))
  val reqLoadId       = Reg(UInt(phyRegIdxWidth.W))
  val reqIsWrite      = RegInit(false.B)
  val reqIsUpgrade    = RegInit(false.B)
  val reqIsPrefetch   = RegInit(false.B)
  val reqSinkIsL2     = RegInit(false.B)
  val refillData      = Reg(UInt(256.W))
  val grantSink       = Reg(UInt(tlSinkBits.W))
  val grantParam      = Reg(UInt(3.W))

  // 1. Allocation
  io.alloc.ready := (state === s_IDLE)
  when(io.alloc.fire) {
    reqAddr         := io.alloc.bits.addr
    reqWriteData    := io.alloc.bits.data
    reqLoadId       := io.alloc.bits.load_id
    reqIsWrite      := io.alloc.bits.is_write
    reqIsUpgrade    := io.alloc.bits.is_upgrade
    reqIsPrefetch   := io.alloc.bits.is_prefetch
    reqSinkIsL2     := io.alloc.bits.sink_is_l2
    state           := s_ACQUIRE
  }

  // 2. Channel A: AcquireBlock
  io.tl_a.valid         := (state === s_ACQUIRE)
  io.tl_a.bits.opcode   := TLMessages.AcquireBlock
  // BtoT for upgrade, NtoT for exclusive store miss, NtoB for shared load miss
  io.tl_a.bits.param    := Mux(reqIsUpgrade, TLPermissions.BtoT, Mux(reqIsWrite, TLPermissions.NtoT, TLPermissions.NtoB))
  io.tl_a.bits.size     := 5.U // log2Ceil(32 bytes) = 5
  io.tl_a.bits.source   := 0.U
  // Cache line aligned address (32 bytes = 256 bits)
  io.tl_a.bits.address  := Cat(reqAddr(xLen - 1, 5), 0.U(5.W))
  io.tl_a.bits.mask     := ~0.U((tlDataBits / 8).W)
  io.tl_a.bits.data     := 0.U
  io.tl_a.bits.corrupt  := false.B

  when(io.tl_a.fire) {
    state := s_WAIT_GRANT
  }

  // 3. Channel D: Grant / GrantData
  io.tl_d.ready := (state === s_WAIT_GRANT)
  when(io.tl_d.fire) {
    refillData  := io.tl_d.bits.data
    grantSink   := io.tl_d.bits.sink
    grantParam  := io.tl_d.bits.param
    state       := s_GRANT_ACK
  }

  // 4. Channel E: GrantAck
  io.tl_e.valid     := (state === s_GRANT_ACK)
  io.tl_e.bits.sink := grantSink

  when(io.tl_e.fire) {
    state := s_REFILL
  }

  // 5. Refill Cache & Wakeup LSU
  io.refill_out.valid               := (state === s_REFILL)
  io.refill_out.bits.addr           := reqAddr
  io.refill_out.bits.data           := refillData
  io.refill_out.bits.write_data     := reqWriteData
  io.refill_out.bits.load_id        := reqLoadId
  io.refill_out.bits.is_write       := reqIsWrite
  io.refill_out.bits.is_prefetch    := reqIsPrefetch
  io.refill_out.bits.sink_is_l2     := reqSinkIsL2
  io.refill_out.bits.granted_param  := grantParam

  when(io.refill_out.fire) {
    state := s_IDLE
  }
}
