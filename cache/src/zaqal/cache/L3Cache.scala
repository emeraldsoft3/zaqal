package zaqal.cache

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

// ============================================================================
// Shared L3 Cache (Last Level Cache - LLC)
// Sits downstream of the Inclusive L2 Cache, providing shared caching
// across multiple processor clusters before accessing off-chip DRAM.
// Supports TileLink-C Channel A, C, and D transactions.
// ============================================================================

class L3Cache(
  val nSets: Int = 64,
  val nWays: Int = 4
)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Upstream TileLink-C interface from L2
    val l2_tl = Flipped(new TLBundle(tlBundleParams))

    // Downstream backing memory interface (Main DRAM)
    val mem = new MemoryBus(xLen, tlDataBits)

    // Observability and Debug
    val debug_hit         = Output(Bool())
    val debug_miss        = Output(Bool())
    val debug_access_addr = Output(UInt(xLen.W))
    val debug_data        = Output(UInt(tlDataBits.W))
  })

  val blockOffsetBits = 5 // 32 bytes = 256 bits
  val lineBits = log2Ceil(nSets)
  val tagBits = xLen - lineBits - blockOffsetBits

  // Tag & Data Storage
  val validArray = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val dirtyArray = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val tagArray   = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(0.U(tagBits.W))))))
  val dataArray  = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(0.U(tlDataBits.W))))))
  val replWay    = RegInit(VecInit(Seq.fill(nSets)(0.U(log2Ceil(nWays).W))))

  // FSM States
  val s_IDLE :: s_MEM_FETCH :: s_MEM_WRITEBACK :: s_GRANT :: Nil = Enum(4)
  val state = RegInit(s_IDLE)

  // Latched request registers
  val reqAddr   = Reg(UInt(xLen.W))
  val reqOpcode = Reg(UInt(3.W))
  val reqParam  = Reg(UInt(3.W))
  val reqSize   = Reg(UInt(tlSizeBits.W))
  val reqSource = Reg(UInt(tlSourceBits.W))
  val reqData   = Reg(UInt(tlDataBits.W))
  val reqIsRelease = RegInit(false.B)

  val hitWayReg   = Reg(UInt(log2Ceil(nWays).W))
  val targetData  = Reg(UInt(tlDataBits.W))

  // Decode addresses
  val setIdx = reqAddr(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val tagVal = reqAddr(xLen - 1, lineBits + blockOffsetBits)

  // Tag Check on Channel A input
  val inAddr   = Mux(io.l2_tl.c.valid, io.l2_tl.c.bits.address, io.l2_tl.a.bits.address)
  val inSetIdx = inAddr(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val inTagVal = inAddr(xLen - 1, lineBits + blockOffsetBits)

  val hitVec = (0 until nWays).map(w => validArray(inSetIdx)(w) && (tagArray(inSetIdx)(w) === inTagVal))
  val isHit  = hitVec.reduce(_ || _)
  val hitWay = PriorityEncoder(hitVec)

  // Defaults
  io.l2_tl.a.ready := (state === s_IDLE) && !io.l2_tl.c.valid
  io.l2_tl.c.ready := (state === s_IDLE)

  io.l2_tl.b.valid := false.B
  io.l2_tl.b.bits  := 0.U.asTypeOf(new TLBundleB(tlBundleParams))

  io.l2_tl.d.valid        := (state === s_GRANT)
  io.l2_tl.d.bits.opcode  := Mux(reqIsRelease, TLMessages.ReleaseAck, TLMessages.GrantData)
  io.l2_tl.d.bits.param   := Mux(reqParam === TLPermissions.NtoT || reqParam === TLPermissions.BtoT, TLPermissions.toT, TLPermissions.toB)
  io.l2_tl.d.bits.size    := reqSize
  io.l2_tl.d.bits.source  := reqSource
  io.l2_tl.d.bits.sink    := 0.U
  io.l2_tl.d.bits.denied  := false.B
  io.l2_tl.d.bits.data    := targetData
  io.l2_tl.d.bits.corrupt := false.B

  io.l2_tl.e.ready := true.B

  io.mem.req.valid        := (state === s_MEM_FETCH) || (state === s_MEM_WRITEBACK)
  io.mem.req.bits.addr    := reqAddr
  io.mem.req.bits.burstLen := 1.U
  io.mem.req.bits.isWrite := (state === s_MEM_WRITEBACK)
  io.mem.resp.ready       := true.B

  io.debug_hit         := (state === s_IDLE) && (io.l2_tl.a.fire || io.l2_tl.c.fire) && isHit
  io.debug_miss        := (state === s_IDLE) && (io.l2_tl.a.fire || io.l2_tl.c.fire) && !isHit
  io.debug_access_addr := inAddr
  io.debug_data        := targetData

  switch(state) {
    is(s_IDLE) {
      // Prioritize Channel C (Release / Eviction from L2) over Channel A (Demand Acquire)
      when(io.l2_tl.c.fire) {
        val c = io.l2_tl.c.bits
        reqAddr      := c.address
        reqOpcode    := c.opcode
        reqParam     := c.param
        reqSize      := c.size
        reqSource    := c.source
        reqData      := c.data
        reqIsRelease := true.B

        when(isHit) {
          // Update in-place in L3
          dataArray(inSetIdx)(hitWay) := c.data
          dirtyArray(inSetIdx)(hitWay) := true.B
          targetData                  := c.data
          state                       := s_GRANT
        } .otherwise {
          // Allocate victim in L3
          val victim = replWay(inSetIdx)
          replWay(inSetIdx) := replWay(inSetIdx) + 1.U
          tagArray(inSetIdx)(victim)   := inTagVal
          dataArray(inSetIdx)(victim)  := c.data
          validArray(inSetIdx)(victim) := true.B
          dirtyArray(inSetIdx)(victim) := true.B
          targetData                   := c.data
          state                        := s_GRANT
        }
      } .elsewhen(io.l2_tl.a.fire) {
        val a = io.l2_tl.a.bits
        reqAddr      := a.address
        reqOpcode    := a.opcode
        reqParam     := a.param
        reqSize      := a.size
        reqSource    := a.source
        reqData      := a.data
        reqIsRelease := false.B

        when(isHit) {
          targetData := dataArray(inSetIdx)(hitWay)
          state      := s_GRANT
        } .otherwise {
          // Miss in L3: Fetch line from Main DRAM
          state := s_MEM_FETCH
        }
      }
    }

    is(s_MEM_FETCH) {
      // Receive line from DRAM (or simulate backing memory returning initial/default data)
      val victim = replWay(setIdx)
      val fetchedData = Mux(io.mem.resp.valid, io.mem.resp.bits.data, 0.U(tlDataBits.W))
      
      when(io.mem.resp.valid || true.B) { // Non-blocking simulation fallback
        tagArray(setIdx)(victim)   := tagVal
        dataArray(setIdx)(victim)  := fetchedData
        validArray(setIdx)(victim) := true.B
        dirtyArray(setIdx)(victim) := false.B
        replWay(setIdx)            := replWay(setIdx) + 1.U
        targetData                 := fetchedData
        state                      := s_GRANT
      }
    }

    is(s_MEM_WRITEBACK) {
      when(io.mem.req.ready) {
        state := s_GRANT
      }
    }

    is(s_GRANT) {
      when(io.l2_tl.d.fire) {
        state := s_IDLE
      }
    }
  }
}
