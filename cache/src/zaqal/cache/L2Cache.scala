package zaqal.cache

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

// ============================================================================
// Inclusive L2 Cache with Hardware MESI Directory Protocol
// Serves as the Coherence Serialization Point across multiple L1 caches (Core 0 & Core 1).
// Enforces strict multi-level cache inclusion with automatic back-invalidation,
// cache-to-cache dirty line forwarding, and downstream L3 caching.
// ============================================================================

object MESIState {
  val Invalid   = 0.U(2.W)
  val Shared    = 1.U(2.W)
  val Exclusive = 2.U(2.W)
  val Modified  = 3.U(2.W)
}

class L2Cache(
  val nClients: Int = 2,
  val nSets: Int = 32,
  val nWays: Int = 4
)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Multi-core client endpoints (L1 DCaches)
    val clients = Vec(nClients, Flipped(new TLBundle(tlBundleParams)))

    // Downstream TileLink-C interface to Shared L3 Cache
    val downstream_tl = new TLBundle(tlBundleParams)

    // Coherence Observability & Debug Ports (for GTKWave verification)
    val debug_l2_hit              = Output(Bool())
    val debug_l2_miss             = Output(Bool())
    val debug_l2_eviction         = Output(Bool())
    val debug_l2_back_inv_fire    = Output(Vec(nClients, Bool()))
    val debug_probe_fire          = Output(Vec(nClients, Bool()))
    val debug_probe_ack_fire      = Output(Vec(nClients, Bool()))
    val debug_probe_ack_data_fire = Output(Vec(nClients, Bool()))
    val debug_grant_fire          = Output(Vec(nClients, Bool()))
    val debug_grant_ack_fire      = Output(Vec(nClients, Bool()))
    val debug_mesi_state          = Output(UInt(2.W))
    val debug_sharer_mask         = Output(UInt(nClients.W))
    val debug_active_way          = Output(UInt(log2Ceil(nWays).W))
    val debug_active_addr         = Output(UInt(xLen.W))
    val debug_line_data           = Output(UInt(tlDataBits.W))
    val debug_fsm_state           = Output(UInt(4.W))
  })

  val blockOffsetBits = 5 // 32 bytes = 256 bits
  val lineBits = log2Ceil(nSets)
  val tagBits = xLen - lineBits - blockOffsetBits

  // --------------------------------------------------------------------------
  // L2 Directory & Cache Storage Arrays
  // --------------------------------------------------------------------------
  val validArray  = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val dirtyArray  = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val tagArray    = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(0.U(tagBits.W))))))
  val dataArray   = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(0.U(tlDataBits.W))))))
  val mesiArray   = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(MESIState.Invalid)))))
  val sharerArray = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(0.U(nClients.W))))))
  val replWay     = RegInit(VecInit(Seq.fill(nSets)(0.U(log2Ceil(nWays).W))))

  // --------------------------------------------------------------------------
  // FSM Controller States
  // --------------------------------------------------------------------------
  val s_IDLE :: s_PROBE :: s_BACK_INV :: s_L3_ACQUIRE :: s_L3_WAIT :: s_L3_RELEASE :: s_GRANT :: s_WAIT_E :: Nil = Enum(8)
  val state = RegInit(s_IDLE)

  // Active Transaction Registers
  val activeClient   = RegInit(0.U(log2Ceil(nClients).W))
  val activeAddr     = Reg(UInt(xLen.W))
  val activeOpcode   = Reg(UInt(3.W))
  val activeParam    = Reg(UInt(3.W))
  val activeSize     = Reg(UInt(tlSizeBits.W))
  val activeSource   = Reg(UInt(tlSourceBits.W))
  val activeData     = Reg(UInt(tlDataBits.W))
  val activeWay      = Reg(UInt(log2Ceil(nWays).W))

  val probeTarget    = RegInit(0.U(log2Ceil(nClients).W))
  val probeParam     = RegInit(0.U(3.W))
  val probeDone      = RegInit(false.B)

  val backInvVictimWay = Reg(UInt(log2Ceil(nWays).W))
  val backInvTarget    = RegInit(0.U(log2Ceil(nClients).W))
  val backInvAddr      = Reg(UInt(xLen.W))
  val backInvDone      = RegInit(false.B)

  // Address Decoding
  val activeSet = activeAddr(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val activeTag = activeAddr(xLen - 1, lineBits + blockOffsetBits)

  // Client Channel A Round-Robin Arbiter
  val aArb = Module(new RRArbiter(new TLBundleA(tlBundleParams), nClients))
  for (i <- 0 until nClients) {
    aArb.io.in(i) <> io.clients(i).a
  }

  // --------------------------------------------------------------------------
  // Default Port Assignments
  // --------------------------------------------------------------------------
  aArb.io.out.ready := (state === s_IDLE)

  for (i <- 0 until nClients) {
    // Channel B (L2 -> L1 Probe / Invalidation)
    val isPeerProbe = (state === s_PROBE) && (probeTarget === i.U) && !probeDone
    val isBackInv   = (state === s_BACK_INV) && (backInvTarget === i.U) && !backInvDone

    io.clients(i).b.valid        := isPeerProbe || isBackInv
    io.clients(i).b.bits.opcode  := TLMessages.ProbeBlock
    io.clients(i).b.bits.param   := Mux(isBackInv, TLPermissions.toN, probeParam)
    io.clients(i).b.bits.size    := 5.U
    io.clients(i).b.bits.source  := i.U
    io.clients(i).b.bits.address := Mux(isBackInv, backInvAddr, activeAddr)
    io.clients(i).b.bits.mask    := ~0.U((tlDataBits / 8).W)
    io.clients(i).b.bits.data    := 0.U
    io.clients(i).b.bits.corrupt := false.B

    // Channel C (L1 -> L2 ProbeAck / ProbeAckData)
    io.clients(i).c.ready := true.B

    // Channel D (L2 -> L1 GrantData / Grant)
    io.clients(i).d.valid        := (state === s_GRANT) && (activeClient === i.U)
    io.clients(i).d.bits.opcode  := TLMessages.GrantData
    io.clients(i).d.bits.param   := Mux(activeParam === TLPermissions.NtoT || activeParam === TLPermissions.BtoT, TLPermissions.toT, TLPermissions.toB)
    io.clients(i).d.bits.size    := activeSize
    io.clients(i).d.bits.source  := activeSource
    io.clients(i).d.bits.sink    := activeClient
    io.clients(i).d.bits.denied  := false.B
    io.clients(i).d.bits.data    := activeData
    io.clients(i).d.bits.corrupt := false.B

    // Channel E (L1 -> L2 GrantAck)
    io.clients(i).e.ready := (state === s_WAIT_E) && (activeClient === i.U)

    // Observability signals
    io.debug_l2_back_inv_fire(i)       := isBackInv && io.clients(i).b.fire
    io.debug_probe_fire(i)          := isPeerProbe && io.clients(i).b.fire
    io.debug_probe_ack_fire(i)      := io.clients(i).c.fire && (io.clients(i).c.bits.opcode === TLMessages.ProbeAck)
    io.debug_probe_ack_data_fire(i) := io.clients(i).c.fire && (io.clients(i).c.bits.opcode === TLMessages.ProbeAckData)
    io.debug_grant_fire(i)          := io.clients(i).d.fire
    io.debug_grant_ack_fire(i)      := io.clients(i).e.fire
  }

  // Downstream TileLink Interface to Shared L3 Cache
  io.downstream_tl.a.valid        := (state === s_L3_ACQUIRE)
  io.downstream_tl.a.bits.opcode  := TLMessages.AcquireBlock
  io.downstream_tl.a.bits.param   := activeParam
  io.downstream_tl.a.bits.size    := activeSize
  io.downstream_tl.a.bits.source  := activeClient
  io.downstream_tl.a.bits.address := activeAddr
  io.downstream_tl.a.bits.mask    := ~0.U((tlDataBits / 8).W)
  io.downstream_tl.a.bits.data    := 0.U
  io.downstream_tl.a.bits.corrupt := false.B

  io.downstream_tl.c.valid        := (state === s_L3_RELEASE)
  io.downstream_tl.c.bits.opcode  := TLMessages.ReleaseData
  io.downstream_tl.c.bits.param   := TLPermissions.TtoN
  io.downstream_tl.c.bits.size    := 5.U
  io.downstream_tl.c.bits.source  := 0.U
  io.downstream_tl.c.bits.address := backInvAddr
  io.downstream_tl.c.bits.data    := activeData
  io.downstream_tl.c.bits.corrupt := false.B

  io.downstream_tl.b.ready := true.B
  io.downstream_tl.d.ready := (state === s_L3_WAIT) || (state === s_L3_RELEASE)
  io.downstream_tl.e.valid := false.B
  io.downstream_tl.e.bits.sink := 0.U

  // Debug Observability
  io.debug_l2_hit      := (state === s_IDLE) && aArb.io.out.fire && {
    val reqSet = aArb.io.out.bits.address(lineBits + blockOffsetBits - 1, blockOffsetBits)
    val reqTag = aArb.io.out.bits.address(xLen - 1, lineBits + blockOffsetBits)
    (0 until nWays).map(w => validArray(reqSet)(w) && (tagArray(reqSet)(w) === reqTag)).reduce(_ || _)
  }
  io.debug_l2_miss     := (state === s_IDLE) && aArb.io.out.fire && !io.debug_l2_hit
  io.debug_l2_eviction := (state === s_BACK_INV)
  io.debug_mesi_state  := mesiArray(activeSet)(activeWay)
  io.debug_sharer_mask := sharerArray(activeSet)(activeWay)
  io.debug_active_way  := activeWay
  io.debug_active_addr := activeAddr
  io.debug_line_data   := activeData
  io.debug_fsm_state   := state.asUInt

  // --------------------------------------------------------------------------
  // Main Coherence State Machine
  // --------------------------------------------------------------------------
  switch(state) {
    is(s_IDLE) {
      probeDone   := false.B
      backInvDone := false.B

      when(aArb.io.out.fire) {
        val reqClient = aArb.io.chosen
        val reqAddr   = aArb.io.out.bits.address
        val reqSet    = reqAddr(lineBits + blockOffsetBits - 1, blockOffsetBits)
        val reqTag    = reqAddr(xLen - 1, lineBits + blockOffsetBits)
        val reqParam  = aArb.io.out.bits.param

        activeClient := reqClient
        activeAddr   := reqAddr
        activeOpcode := aArb.io.out.bits.opcode
        activeParam  := reqParam
        activeSize   := aArb.io.out.bits.size
        activeSource := aArb.io.out.bits.source

        // 1. Tag Check across all ways in this set
        val wayHits = (0 until nWays).map(w => validArray(reqSet)(w) && (tagArray(reqSet)(w) === reqTag))
        val isL2Hit = wayHits.reduce(_ || _)
        val hitWay  = PriorityEncoder(wayHits)

        // 2. Identify victim way in case of Miss
        val hasEmptyWay = (0 until nWays).map(w => !validArray(reqSet)(w)).reduce(_ || _)
        val emptyWay    = PriorityEncoder((0 until nWays).map(w => !validArray(reqSet)(w)))
        val victimWay   = Mux(hasEmptyWay, emptyWay, replWay(reqSet))

        when(isL2Hit) {
          activeWay  := hitWay
          activeData := dataArray(reqSet)(hitWay)

          val currentSharers = sharerArray(reqSet)(hitWay)
          val currentMesi    = mesiArray(reqSet)(hitWay)
          val peerClient     = Mux(reqClient === 0.U, 1.U, 0.U)
          val peerHoldsLine  = currentSharers(peerClient)

          // Coherence Actions on Hit:
          when(reqParam === TLPermissions.NtoT || reqParam === TLPermissions.BtoT) {
            // Write / Upgrade request: Must invalidate peer core if holding
            when(peerHoldsLine) {
              probeTarget := peerClient
              probeParam  := TLPermissions.toN
              state       := s_PROBE
            } .otherwise {
              state       := s_GRANT
            }
          } .otherwise {
            // Read request (NtoB): If peer holds dirty/modified copy, downgrade to Shared
            when(peerHoldsLine && (currentMesi === MESIState.Modified || dirtyArray(reqSet)(hitWay))) {
              probeTarget := peerClient
              probeParam  := TLPermissions.toB
              state       := s_PROBE
            } .otherwise {
              state       := s_GRANT
            }
          }
        } .otherwise {
          // L2 Cache Miss
          activeWay := victimWay

          // 3. Inclusion Check: Does an L1 core still hold the line in this victim way?
          val victimValid   = validArray(reqSet)(victimWay)
          val victimSharers = sharerArray(reqSet)(victimWay)
          val victimTag     = tagArray(reqSet)(victimWay)
          val reconstructedVictimAddr = Cat(victimTag, reqSet, 0.U(blockOffsetBits.W))

          when(victimValid && victimSharers.orR) {
            // INCLUSION ENFORCEMENT: Send Back-Invalidation Probe to all L1 sharers!
            val targetCore = PriorityEncoder(victimSharers)
            backInvVictimWay := victimWay
            backInvTarget    := targetCore
            backInvAddr      := reconstructedVictimAddr
            activeData       := dataArray(reqSet)(victimWay)
            state            := s_BACK_INV
          } .otherwise {
            // Victim way is already empty/clean: fetch requested line from Shared L3 Cache
            state := s_L3_ACQUIRE
          }
        }
      }
    }

    // ------------------------------------------------------------------------
    // S_PROBE: In-flight Coherence Probe to Peer Core (Cache-to-Cache Forwarding)
    // ------------------------------------------------------------------------
    is(s_PROBE) {
      when(io.clients(probeTarget).b.fire) {
        probeDone := true.B
      }

      when(io.clients(probeTarget).c.fire) {
        val c = io.clients(probeTarget).c.bits
        when(c.opcode === TLMessages.ProbeAckData) {
          // Peer core forwarded modified dirty line! Update L2 data storage
          activeData := c.data
          dataArray(activeSet)(activeWay) := c.data
          dirtyArray(activeSet)(activeWay) := true.B
        }

        // Update directory sharers and MESI states
        when(probeParam === TLPermissions.toN) {
          sharerArray(activeSet)(activeWay) := sharerArray(activeSet)(activeWay) & (~(1.U << probeTarget)).asUInt
        } .otherwise {
          // toB downgrade: peer is now Shared
          mesiArray(activeSet)(activeWay) := MESIState.Shared
          dirtyArray(activeSet)(activeWay) := false.B
        }

        probeDone := false.B
        state     := s_GRANT
      }
    }

    // ------------------------------------------------------------------------
    // S_BACK_INV: Enforce Multi-Level Inclusion by Evicting Victim from L1
    // ------------------------------------------------------------------------
    is(s_BACK_INV) {
      when(io.clients(backInvTarget).b.fire) {
        backInvDone := true.B
      }

      when(io.clients(backInvTarget).c.fire) {
        val c = io.clients(backInvTarget).c.bits
        when(c.opcode === TLMessages.ProbeAckData) {
          // Evicted line had modified data in L1! Writeback to downstream L3
          activeData := c.data
          state      := s_L3_RELEASE
        } .otherwise {
          // Clean back-invalidation complete: clear sharers and fetch new line from L3
          sharerArray(activeSet)(backInvVictimWay) := 0.U
          validArray(activeSet)(backInvVictimWay)  := false.B
          state := s_L3_ACQUIRE
        }
        backInvDone := false.B
      }
    }

    // ------------------------------------------------------------------------
    // S_L3_RELEASE: Write back evicted dirty victim line to Shared L3 Cache
    // ------------------------------------------------------------------------
    is(s_L3_RELEASE) {
      when(io.downstream_tl.c.fire) {
        sharerArray(activeSet)(backInvVictimWay) := 0.U
        validArray(activeSet)(backInvVictimWay)  := false.B
        state := s_L3_ACQUIRE
      }
    }

    // ------------------------------------------------------------------------
    // S_L3_ACQUIRE: Request refill line from Shared L3 Cache
    // ------------------------------------------------------------------------
    is(s_L3_ACQUIRE) {
      when(io.downstream_tl.a.fire) {
        state := s_L3_WAIT
      }
    }

    is(s_L3_WAIT) {
      when(io.downstream_tl.d.fire) {
        val refillData = io.downstream_tl.d.bits.data
        activeData := refillData

        // Install new line into L2 cache victim way
        tagArray(activeSet)(activeWay)   := activeTag
        dataArray(activeSet)(activeWay)  := refillData
        validArray(activeSet)(activeWay) := true.B
        dirtyArray(activeSet)(activeWay) := false.B
        replWay(activeSet)               := replWay(activeSet) + 1.U

        state := s_GRANT
      }
    }

    // ------------------------------------------------------------------------
    // S_GRANT: Deliver GrantData to Requesting Core
    // ------------------------------------------------------------------------
    is(s_GRANT) {
      when(io.clients(activeClient).d.fire) {
        state := s_WAIT_E
      }
    }

    // ------------------------------------------------------------------------
    // S_WAIT_E: Await GrantAck from Core and Finalize Directory State
    // ------------------------------------------------------------------------
    is(s_WAIT_E) {
      when(io.clients(activeClient).e.fire) {
        when(activeParam === TLPermissions.NtoT || activeParam === TLPermissions.BtoT) {
          mesiArray(activeSet)(activeWay)   := MESIState.Modified
          sharerArray(activeSet)(activeWay) := (1.U << activeClient)
          dirtyArray(activeSet)(activeWay)  := true.B
        } .otherwise {
          mesiArray(activeSet)(activeWay)   := MESIState.Shared
          sharerArray(activeSet)(activeWay) := sharerArray(activeSet)(activeWay) | (1.U << activeClient)
        }

        state := s_IDLE
      }
    }
  }
}
