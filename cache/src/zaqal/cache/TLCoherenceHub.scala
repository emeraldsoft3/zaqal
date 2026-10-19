package zaqal.cache

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

// ============================================================================
// TileLink-C Coherence Hub (Snooping Crossbar & Directory Hub)
// Coordinates multi-core cache coherence using Channels A, B, C, D, and E.
// Inspired by XiangShan's Coherent Bus & TileLink Broadcast Hub.
// ============================================================================

class TLCoherenceHub(val nClients: Int = 2)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Multi-core client endpoints (L1 D-Caches)
    val clients = Vec(nClients, Flipped(new TLBundle(tlBundleParams)))

    // Backing memory bus (LLC / DRAM)
    val mem = new MemoryBus(xLen, tlDataBits)

    // Coherence Observability & Debug Ports
    val debug_probe_fire          = Output(Vec(nClients, Bool()))
    val debug_probe_addr          = Output(UInt(xLen.W))
    val debug_probe_param         = Output(UInt(3.W))
    val debug_probe_ack_fire      = Output(Vec(nClients, Bool()))
    val debug_probe_ack_data_fire = Output(Vec(nClients, Bool()))
    val debug_grant_fire          = Output(Vec(nClients, Bool()))
    val debug_grant_ack_fire      = Output(Vec(nClients, Bool()))
    val debug_shared_data         = Output(UInt(tlDataBits.W))
    val debug_state               = Output(UInt(3.W))
  })

  val numSets = 64
  val lineBits = log2Ceil(numSets)
  val blockOffsetBits = 5 // 32 bytes = 256 bits
  val tagBits = xLen - lineBits - blockOffsetBits

  // Directory tracking table: which clients hold which lines, and dirty status
  val dirValid = RegInit(VecInit(Seq.fill(numSets)(VecInit(Seq.fill(nClients)(false.B)))))
  val dirDirty = RegInit(VecInit(Seq.fill(numSets)(VecInit(Seq.fill(nClients)(false.B)))))
  val dirTag   = RegInit(VecInit(Seq.fill(numSets)(0.U(tagBits.W))))

  // Shared Backing Storage (Simulated LLC cache-lines)
  val backingStore = RegInit(VecInit(Seq.fill(numSets)(0.U(tlDataBits.W))))

  // FSM States
  val s_IDLE :: s_PROBE :: s_GRANT :: s_WAIT_E :: Nil = Enum(4)
  val state = RegInit(s_IDLE)

  // Active Transaction Registers
  val activeClient   = RegInit(0.U(log2Ceil(nClients).W))
  val probeTarget    = RegInit(0.U(log2Ceil(nClients).W))
  val activeAddr     = Reg(UInt(xLen.W))
  val activeOpcode   = Reg(UInt(3.W))
  val activeParam    = Reg(UInt(3.W))
  val activeSize     = Reg(UInt(tlSizeBits.W))
  val activeSource   = Reg(UInt(tlSourceBits.W))
  val activeData     = Reg(UInt(tlDataBits.W))
  val needProbe      = RegInit(false.B)
  val probeParam     = RegInit(0.U(3.W))
  val probeDone      = RegInit(false.B)

  // Decode active address
  val activeIndex = activeAddr(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val activeTag   = activeAddr(xLen - 1, lineBits + blockOffsetBits)

  // Channel A Round-Robin Arbiter across clients
  val aArb = Module(new RRArbiter(new TLBundleA(tlBundleParams), nClients))
  for (i <- 0 until nClients) {
    aArb.io.in(i) <> io.clients(i).a
  }

  // Default Channel Connections
  for (i <- 0 until nClients) {
    // Channel B (Hub -> Client Probe): Assert until probed client accepts probe request
    io.clients(i).b.valid         := (state === s_PROBE) && (probeTarget === i.U) && !probeDone
    io.clients(i).b.bits.opcode   := TLMessages.ProbeBlock
    io.clients(i).b.bits.param    := probeParam
    io.clients(i).b.bits.size     := 5.U
    io.clients(i).b.bits.source   := i.U
    io.clients(i).b.bits.address  := activeAddr
    io.clients(i).b.bits.mask     := ~0.U((tlDataBits / 8).W)
    io.clients(i).b.bits.data     := 0.U
    io.clients(i).b.bits.corrupt  := false.B

    // Channel C (Client -> Hub ProbeAck / Release): Hub is always ready to receive responses
    io.clients(i).c.ready         := true.B

    // Channel D (Hub -> Client Grant)
    io.clients(i).d.valid         := (state === s_GRANT) && (activeClient === i.U)
    io.clients(i).d.bits.opcode   := TLMessages.GrantData
    io.clients(i).d.bits.param    := Mux(activeParam === TLPermissions.NtoT || activeParam === TLPermissions.BtoT, TLPermissions.toT, TLPermissions.toB)
    io.clients(i).d.bits.size     := activeSize
    io.clients(i).d.bits.source   := activeSource
    io.clients(i).d.bits.sink     := activeClient
    io.clients(i).d.bits.denied   := false.B
    io.clients(i).d.bits.data     := activeData
    io.clients(i).d.bits.corrupt  := false.B

    // Channel E (Client -> Hub GrantAck)
    io.clients(i).e.ready         := (state === s_WAIT_E) && (activeClient === i.U)

    // Observability outputs
    io.debug_probe_fire(i)          := io.clients(i).b.fire
    io.debug_probe_ack_fire(i)      := io.clients(i).c.fire && (io.clients(i).c.bits.opcode === TLMessages.ProbeAck)
    io.debug_probe_ack_data_fire(i) := io.clients(i).c.fire && (io.clients(i).c.bits.opcode === TLMessages.ProbeAckData)
    io.debug_grant_fire(i)          := io.clients(i).d.fire
    io.debug_grant_ack_fire(i)      := io.clients(i).e.fire
  }

  io.debug_probe_addr  := activeAddr
  io.debug_probe_param := probeParam
  io.debug_shared_data := activeData
  io.debug_state       := state.asUInt

  // Backing Memory defaults
  io.mem.req.valid     := false.B
  io.mem.req.bits.addr := activeAddr
  io.mem.req.bits.burstLen := 1.U
  io.mem.req.bits.isWrite  := false.B
  io.mem.resp.ready    := true.B

  // Channel A is only consumed when Hub is IDLE
  aArb.io.out.ready := (state === s_IDLE)

  // Coherence Controller State Machine
  switch(state) {
    is(s_IDLE) {
      probeDone := false.B
      when(aArb.io.out.fire) {
        val reqClient = aArb.io.chosen
        val reqAddr   = aArb.io.out.bits.address
        val reqIndex  = reqAddr(lineBits + blockOffsetBits - 1, blockOffsetBits)
        val reqTag    = reqAddr(xLen - 1, lineBits + blockOffsetBits)
        val reqParam  = aArb.io.out.bits.param

        activeClient  := reqClient
        activeAddr    := reqAddr
        activeOpcode  := aArb.io.out.bits.opcode
        activeParam   := reqParam
        activeSize    := aArb.io.out.bits.size
        activeSource  := aArb.io.out.bits.source
        activeData    := backingStore(reqIndex)

        // Conflict Detection: Does another client j != reqClient hold this line?
        val otherClient = Wire(UInt(log2Ceil(nClients).W))
        val hasConflict = Wire(Bool())

        if (nClients == 2) {
          otherClient := Mux(reqClient === 0.U, 1.U, 0.U)
          val otherValid = dirValid(reqIndex)(otherClient)
          val sameTag    = (dirTag(reqIndex) === reqTag)
          hasConflict    := otherValid && sameTag
        } else {
          otherClient := 0.U
          hasConflict := false.B
        }

        probeTarget := otherClient

        when(hasConflict) {
          // If acquiring exclusive permissions (NtoT / BtoT), must invalidate other core (toN)
          // If acquiring shared read (NtoB) and other core is dirty, must downgrade other core (toB)
          when(reqParam === TLPermissions.NtoT || reqParam === TLPermissions.BtoT) {
            needProbe  := true.B
            probeParam := TLPermissions.toN
            state      := s_PROBE
          } .elsewhen(dirDirty(reqIndex)(otherClient)) {
            needProbe  := true.B
            probeParam := TLPermissions.toB
            state      := s_PROBE
          } .otherwise {
            needProbe  := false.B
            state      := s_GRANT
          }
        } .otherwise {
          needProbe := false.B
          state     := s_GRANT
        }
      }
    }

    is(s_PROBE) {
      when(io.clients(probeTarget).b.fire) {
        probeDone := true.B
      }

      // Check Channel C (ProbeAck / ProbeAckData) from probed target
      when(io.clients(probeTarget).c.fire) {
        val cBits = io.clients(probeTarget).c.bits
        when(cBits.opcode === TLMessages.ProbeAckData) {
          // Probed core supplied updated dirty data! Forward to requester and update backing store
          activeData := cBits.data
          backingStore(activeIndex) := cBits.data
        }

        // Update directory state for probed core
        when(probeParam === TLPermissions.toN) {
          dirValid(activeIndex)(probeTarget) := false.B
          dirDirty(activeIndex)(probeTarget) := false.B
        } .otherwise { // toB (Downgrade to Shared)
          dirDirty(activeIndex)(probeTarget) := false.B
          // dirValid remains true
        }

        probeDone := false.B
        state := s_GRANT
      }
    }

    is(s_GRANT) {
      // Send GrantData on Channel D to the requesting core
      when(io.clients(activeClient).d.fire) {
        state := s_WAIT_E
      }
    }

    is(s_WAIT_E) {
      // Await GrantAck on Channel E
      when(io.clients(activeClient).e.fire) {
        // Finalize directory ownership
        dirTag(activeIndex) := activeTag
        dirValid(activeIndex)(activeClient) := true.B
        when(activeParam === TLPermissions.NtoT || activeParam === TLPermissions.BtoT) {
          dirDirty(activeIndex)(activeClient) := true.B
        }

        state := s_IDLE
      }
    }
  }
}
