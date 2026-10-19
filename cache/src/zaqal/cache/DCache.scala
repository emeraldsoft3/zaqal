package zaqal.cache

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.cache.prefetch._

// ============================================================================
// TileLink-C Coherent L1 Data Cache (DCache)
// Implements 5-Channel Coherence (MESI/TileLink-C Parity):
// - Channel A: Emits AcquireBlock (NtoB, NtoT, BtoT upgrade)
// - Channel B: Receives ProbeBlock from Interconnect/Hub
// - Channel C: Sends ProbeAck (clean) or ProbeAckData (dirty)
// - Channel D: Receives Grant / GrantData
// - Channel E: Sends GrantAck
// ============================================================================

class DCache(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val req = Flipped(Decoupled(new Bundle {
      val addr = UInt(xLen.W)
      val data = UInt(xLen.W)
      val is_write = Bool()
      val load_id = UInt(6.W)
    }))
    val resp = Decoupled(new Bundle {
      val data = UInt(xLen.W)
      val load_id = UInt(6.W)
    })

    // Coherent TileLink-C Port (Phase 10 Multi-Core Bus)
    val tl = new TLBundle(tlBundleParams)

    // Legacy Memory Bus port (retained for uniprocessor testing)
    val mem = new MemoryBus(xLen, 256)

    val pf_train = Flipped(Valid(new L1PrefetchTrainBundle(xLen)))
    val branch_signal = Input(Valid(new BranchPredictionBus))
    val flush = Input(Bool())
  })

  // Basic Cache Parameters (Direct Mapped 64 sets, 32 bytes/line = 256 bits = 4 x 64-bit doublewords)
  val numSets = 64
  val lineBits = log2Ceil(numSets)
  val blockOffsetBits = 5 // 32 bytes = 256 bits

  val validArray = RegInit(VecInit(Seq.fill(numSets)(false.B)))
  val dirtyArray = RegInit(VecInit(Seq.fill(numSets)(false.B)))
  // Coherence State: 0 = None (Invalid), 1 = Branch (Shared Read-Only), 2 = Trunk (Exclusive Read-Write)
  val stateArray = RegInit(VecInit(Seq.fill(numSets)(0.U(2.W))))
  val tagArray   = RegInit(VecInit(Seq.fill(numSets)(0.U((xLen - lineBits - blockOffsetBits).W))))
  val dataArray  = RegInit(VecInit(Seq.fill(numSets)(VecInit(Seq.fill(4)(0.U(64.W))))))

  // Decode Demand Address
  val reqIndex       = io.req.bits.addr(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val reqTag         = io.req.bits.addr(xLen - 1, lineBits + blockOffsetBits)
  val reqDWordOffset = io.req.bits.addr(blockOffsetBits - 1, 3) // 3 bits: selects 0..3 (64-bit doubleword)

  // Hit Logic for Demand Access:
  // Load Hit: Valid and tag match (either Shared or Exclusive)
  // Store Hit: Valid, tag match, AND held in Exclusive (Trunk = 2.U) state!
  val isTagMatch  = validArray(reqIndex) && (tagArray(reqIndex) === reqTag)
  val isExclusive = (stateArray(reqIndex) === 2.U)
  val isHit       = isTagMatch && (!io.req.bits.is_write || isExclusive)
  val isUpgrade   = isTagMatch && io.req.bits.is_write && !isExclusive // Upgrade Shared -> Exclusive

  // TileLink MSHR Integration (Channels A, D, E)
  val tl_mshr = Module(new TLMSHR)
  tl_mshr.io.tl_a <> io.tl.a
  tl_mshr.io.tl_d <> io.tl.d
  tl_mshr.io.tl_e <> io.tl.e

  // Legacy mem bus defaults (tied off when TileLink is in use)
  io.mem.req.valid     := false.B
  io.mem.req.bits      := 0.U.asTypeOf(new MemoryBusReq(xLen))
  io.mem.resp.ready    := true.B

  // Prefetcher Integration
  val prefetcher = Module(new L1Prefetcher)
  prefetcher.io.train := io.pf_train
  prefetcher.io.branch_signal := io.branch_signal
  prefetcher.io.mshr_busy := !tl_mshr.io.alloc.ready
  prefetcher.io.bus_ready := io.tl.a.ready
  prefetcher.io.demand_miss_active := io.req.valid && !isHit
  prefetcher.io.flush := io.flush

  val pfAddr = prefetcher.io.prefetch_req.bits.addr
  val pfIndex = pfAddr(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val pfTag = pfAddr(xLen - 1, lineBits + blockOffsetBits)
  val isPfHit = validArray(pfIndex) && (tagArray(pfIndex) === pfTag)

  // Demand Defaults
  io.req.ready := false.B
  io.resp.valid := false.B
  io.resp.bits.data := 0.U
  io.resp.bits.load_id := 0.U
  prefetcher.io.prefetch_req.ready := false.B

  tl_mshr.io.alloc.valid := false.B
  tl_mshr.io.alloc.bits.addr := io.req.bits.addr
  tl_mshr.io.alloc.bits.data := io.req.bits.data
  tl_mshr.io.alloc.bits.load_id := io.req.bits.load_id
  tl_mshr.io.alloc.bits.is_write := io.req.bits.is_write
  tl_mshr.io.alloc.bits.is_upgrade := isUpgrade
  tl_mshr.io.alloc.bits.is_prefetch := false.B
  tl_mshr.io.alloc.bits.sink_is_l2 := false.B
  tl_mshr.io.refill_out.ready := true.B

  // Demand Request Handling
  when(io.req.valid) {
    when(isHit) {
      io.req.ready := true.B
      when(io.req.bits.is_write) {
        dataArray(reqIndex)(reqDWordOffset) := io.req.bits.data
        dirtyArray(reqIndex) := true.B
      } .otherwise {
        io.resp.valid := true.B
        io.resp.bits.data := dataArray(reqIndex)(reqDWordOffset)
        io.resp.bits.load_id := io.req.bits.load_id
      }
    } .otherwise {
      // Miss or Upgrade - Allocate TLMSHR to issue AcquireBlock on Channel A
      io.req.ready := tl_mshr.io.alloc.ready
      tl_mshr.io.alloc.valid := true.B
      tl_mshr.io.alloc.bits.addr := io.req.bits.addr
      tl_mshr.io.alloc.bits.data := io.req.bits.data
      tl_mshr.io.alloc.bits.load_id := io.req.bits.load_id
      tl_mshr.io.alloc.bits.is_write := io.req.bits.is_write
      tl_mshr.io.alloc.bits.is_upgrade := isUpgrade
      tl_mshr.io.alloc.bits.is_prefetch := false.B
      tl_mshr.io.alloc.bits.sink_is_l2 := false.B
    }
  } .otherwise {
    // Non-blocking Prefetch Handling when cache pipeline is idle
    when(prefetcher.io.prefetch_req.valid) {
      when(isPfHit) {
        prefetcher.io.prefetch_req.ready := true.B
      } .otherwise {
        when(tl_mshr.io.alloc.ready) {
          prefetcher.io.prefetch_req.ready := true.B
          tl_mshr.io.alloc.valid := true.B
          tl_mshr.io.alloc.bits.addr := pfAddr
          tl_mshr.io.alloc.bits.data := 0.U
          tl_mshr.io.alloc.bits.load_id := 0.U
          tl_mshr.io.alloc.bits.is_write := false.B
          tl_mshr.io.alloc.bits.is_upgrade := false.B
          tl_mshr.io.alloc.bits.is_prefetch := true.B
          tl_mshr.io.alloc.bits.sink_is_l2 := prefetcher.io.prefetch_req.bits.sink_is_l2
        }
      }
    }
  }

  // Refill Handling from TLMSHR
  when(tl_mshr.io.refill_out.fire) {
    val refillIndex       = tl_mshr.io.refill_out.bits.addr(lineBits + blockOffsetBits - 1, blockOffsetBits)
    val refillTag         = tl_mshr.io.refill_out.bits.addr(xLen - 1, lineBits + blockOffsetBits)
    val refillDWordOffset = tl_mshr.io.refill_out.bits.addr(blockOffsetBits - 1, 3)

    when(!tl_mshr.io.refill_out.bits.sink_is_l2) {
      validArray(refillIndex) := true.B
      tagArray(refillIndex)   := refillTag
      stateArray(refillIndex) := Mux(tl_mshr.io.refill_out.bits.granted_param === TLPermissions.toT, 2.U, 1.U)

      when(tl_mshr.io.refill_out.bits.is_write) {
        // Install fetched line, apply 64-bit write update, and mark dirty
        dirtyArray(refillIndex) := true.B
        for (i <- 0 until 4) {
          when(i.U === refillDWordOffset) {
            dataArray(refillIndex)(i) := tl_mshr.io.refill_out.bits.write_data
          } .otherwise {
            dataArray(refillIndex)(i) := tl_mshr.io.refill_out.bits.data((i + 1) * 64 - 1, i * 64)
          }
        }
      } .otherwise {
        dirtyArray(refillIndex) := false.B
        for (i <- 0 until 4) {
          dataArray(refillIndex)(i) := tl_mshr.io.refill_out.bits.data((i + 1) * 64 - 1, i * 64)
        }
      }
    }

    // Wakeup LSU via resp only for demand load misses
    when(!tl_mshr.io.refill_out.bits.is_prefetch && !tl_mshr.io.refill_out.bits.is_write) {
      io.resp.valid := true.B
      val dwordOffset = tl_mshr.io.refill_out.bits.addr(blockOffsetBits - 1, 3)
      io.resp.bits.data := tl_mshr.io.refill_out.bits.data >> (dwordOffset * 64.U)
      io.resp.bits.load_id := tl_mshr.io.refill_out.bits.load_id
    }
  }

  // ==========================================================================
  // Coherence Probe Handling (Channels B and C)
  // Handles incoming ProbeBlock / ProbePerm from Coherent Hub.
  // Performs cache tag check, invalidation or permission downgrade,
  // and returns ProbeAck or ProbeAckData (with dirty line).
  // ==========================================================================
  val probeAddr    = io.tl.b.bits.address
  val probeIndex   = probeAddr(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val probeTag     = probeAddr(xLen - 1, lineBits + blockOffsetBits)
  val isProbeHit   = validArray(probeIndex) && (tagArray(probeIndex) === probeTag)
  val isProbeDirty = dirtyArray(probeIndex)
  val probeData    = Cat((0 until 4).reverse.map(i => dataArray(probeIndex)(i)))

  io.tl.b.ready := io.tl.c.ready
  io.tl.c.valid := io.tl.b.valid

  io.tl.c.bits.size    := io.tl.b.bits.size
  io.tl.c.bits.source  := io.tl.b.bits.source
  io.tl.c.bits.address := io.tl.b.bits.address
  io.tl.c.bits.corrupt := false.B

  when(io.tl.b.valid) {
    when(isProbeHit) {
      when(io.tl.b.bits.param === TLPermissions.toB) {
        // Downgrade to Shared (Branch)
        stateArray(probeIndex) := 1.U
        when(isProbeDirty) {
          io.tl.c.bits.opcode := TLMessages.ProbeAckData
          io.tl.c.bits.param  := TLPermissions.TtoB
          io.tl.c.bits.data   := probeData
          when(io.tl.c.fire) {
            dirtyArray(probeIndex) := false.B
          }
        } .otherwise {
          io.tl.c.bits.opcode := TLMessages.ProbeAck
          io.tl.c.bits.param  := TLPermissions.TtoB
          io.tl.c.bits.data   := 0.U
        }
      } .otherwise {
        // Invalidate (Cap to None)
        when(io.tl.c.fire) {
          validArray(probeIndex) := false.B
          stateArray(probeIndex) := 0.U
        }
        when(isProbeDirty) {
          io.tl.c.bits.opcode := TLMessages.ProbeAckData
          io.tl.c.bits.param  := TLPermissions.TtoN
          io.tl.c.bits.data   := probeData
          when(io.tl.c.fire) {
            dirtyArray(probeIndex) := false.B
          }
        } .otherwise {
          io.tl.c.bits.opcode := TLMessages.ProbeAck
          io.tl.c.bits.param  := TLPermissions.BtoN
          io.tl.c.bits.data   := 0.U
        }
      }
    } .otherwise {
      // Probe Miss: core does not hold this line
      io.tl.c.bits.opcode := TLMessages.ProbeAck
      io.tl.c.bits.param  := TLPermissions.NtoN
      io.tl.c.bits.data   := 0.U
    }
  } .otherwise {
    io.tl.c.bits.opcode := TLMessages.ProbeAck
    io.tl.c.bits.param  := TLPermissions.NtoN
    io.tl.c.bits.data   := 0.U
  }
}
