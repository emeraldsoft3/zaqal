package zaqal

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.cache._
import zaqal.cache.prefetch._

// ============================================================================
// MultiCoreCoherenceTop
// Dual-Core Coherence Verification Framework integrating:
// - Core 0 & Core 1 Coherent L1 D-Caches (TLCoherentDCache)
// - Central TLCoherenceHub (Channels A, B, C, D, E)
// - Coherence Snooping, Probing, and Dirty-Line Forwarding
// ============================================================================

class MultiCoreCoherenceTop(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Core 0 LSU Demand Interface
    val c0_req = Flipped(Decoupled(new Bundle {
      val addr     = UInt(xLen.W)
      val data     = UInt(xLen.W)
      val is_write = Bool()
      val load_id  = UInt(6.W)
    }))
    val c0_resp = Decoupled(new Bundle {
      val data    = UInt(xLen.W)
      val load_id = UInt(6.W)
    })

    // Core 1 LSU Demand Interface
    val c1_req = Flipped(Decoupled(new Bundle {
      val addr     = UInt(xLen.W)
      val data     = UInt(xLen.W)
      val is_write = Bool()
      val load_id  = UInt(6.W)
    }))
    val c1_resp = Decoupled(new Bundle {
      val data    = UInt(xLen.W)
      val load_id = UInt(6.W)
    })

    // Coherence Hub Observability & Channel Debug Signals (for GTKWave verification)
    val hub_state                 = Output(UInt(3.W))
    val debug_probe_fire          = Output(Vec(2, Bool()))
    val debug_probe_addr          = Output(UInt(xLen.W))
    val debug_probe_param         = Output(UInt(3.W))
    val debug_probe_ack_fire      = Output(Vec(2, Bool()))
    val debug_probe_ack_data_fire = Output(Vec(2, Bool()))
    val debug_grant_fire          = Output(Vec(2, Bool()))
    val debug_grant_ack_fire      = Output(Vec(2, Bool()))
    val debug_shared_data         = Output(UInt(tlDataBits.W))

    // Core 0 TileLink-C Channel Monitor
    val c0_a_valid   = Output(Bool())
    val c0_a_opcode  = Output(UInt(3.W))
    val c0_a_param   = Output(UInt(3.W))
    val c0_a_addr    = Output(UInt(xLen.W))
    val c0_b_valid   = Output(Bool())
    val c0_b_param   = Output(UInt(3.W))
    val c0_c_valid   = Output(Bool())
    val c0_c_opcode  = Output(UInt(3.W))
    val c0_c_param   = Output(UInt(3.W))
    val c0_d_valid   = Output(Bool())
    val c0_d_opcode  = Output(UInt(3.W))
    val c0_d_param   = Output(UInt(3.W))
    val c0_e_valid   = Output(Bool())

    // Core 1 TileLink-C Channel Monitor
    val c1_a_valid   = Output(Bool())
    val c1_a_opcode  = Output(UInt(3.W))
    val c1_a_param   = Output(UInt(3.W))
    val c1_a_addr    = Output(UInt(xLen.W))
    val c1_b_valid   = Output(Bool())
    val c1_b_param   = Output(UInt(3.W))
    val c1_c_valid   = Output(Bool())
    val c1_c_opcode  = Output(UInt(3.W))
    val c1_c_param   = Output(UInt(3.W))
    val c1_d_valid   = Output(Bool())
    val c1_d_opcode  = Output(UInt(3.W))
    val c1_d_param   = Output(UInt(3.W))
    val c1_e_valid   = Output(Bool())
  })

  // Instantiate Coherent L1 Caches for Core 0 and Core 1
  val dcache0 = Module(new DCache)
  val dcache1 = Module(new DCache)

  // Instantiate Central Coherence Hub
  val hub = Module(new TLCoherenceHub(nClients = 2))

  // Connect TileLink-C 5-Channel Interfaces
  hub.io.clients(0) <> dcache0.io.tl
  hub.io.clients(1) <> dcache1.io.tl

  // Connect Demand LSU Interfaces
  dcache0.io.req  <> io.c0_req
  io.c0_resp      <> dcache0.io.resp

  dcache1.io.req  <> io.c1_req
  io.c1_resp      <> dcache1.io.resp

  // Tie off auxiliary cache ports
  dcache0.io.pf_train.valid := false.B
  dcache0.io.pf_train.bits  := 0.U.asTypeOf(new L1PrefetchTrainBundle(xLen))
  dcache0.io.branch_signal.valid := false.B
  dcache0.io.branch_signal.bits  := 0.U.asTypeOf(new BranchPredictionBus)
  dcache0.io.flush := false.B

  dcache1.io.pf_train.valid := false.B
  dcache1.io.pf_train.bits  := 0.U.asTypeOf(new L1PrefetchTrainBundle(xLen))
  dcache1.io.branch_signal.valid := false.B
  dcache1.io.branch_signal.bits  := 0.U.asTypeOf(new BranchPredictionBus)
  dcache1.io.flush := false.B

  // Tie off legacy memory bus ports
  dcache0.io.mem.req.ready := true.B
  dcache0.io.mem.resp.valid := false.B
  dcache0.io.mem.resp.bits := 0.U.asTypeOf(new MemoryBusResp(256))

  dcache1.io.mem.req.ready := true.B
  dcache1.io.mem.resp.valid := false.B
  dcache1.io.mem.resp.bits := 0.U.asTypeOf(new MemoryBusResp(256))

  hub.io.mem.req.ready := true.B
  hub.io.mem.resp.valid := false.B
  hub.io.mem.resp.bits := 0.U.asTypeOf(new MemoryBusResp(tlDataBits))

  // Export Hub Observability Signals
  io.hub_state                 := hub.io.debug_state
  io.debug_probe_fire          := hub.io.debug_probe_fire
  io.debug_probe_addr          := hub.io.debug_probe_addr
  io.debug_probe_param         := hub.io.debug_probe_param
  io.debug_probe_ack_fire      := hub.io.debug_probe_ack_fire
  io.debug_probe_ack_data_fire := hub.io.debug_probe_ack_data_fire
  io.debug_grant_fire          := hub.io.debug_grant_fire
  io.debug_grant_ack_fire      := hub.io.debug_grant_ack_fire
  io.debug_shared_data         := hub.io.debug_shared_data

  // Export Core 0 Channel Monitor
  io.c0_a_valid  := dcache0.io.tl.a.valid
  io.c0_a_opcode := dcache0.io.tl.a.bits.opcode
  io.c0_a_param  := dcache0.io.tl.a.bits.param
  io.c0_a_addr   := dcache0.io.tl.a.bits.address
  io.c0_b_valid  := dcache0.io.tl.b.valid
  io.c0_b_param  := dcache0.io.tl.b.bits.param
  io.c0_c_valid  := dcache0.io.tl.c.valid
  io.c0_c_opcode := dcache0.io.tl.c.bits.opcode
  io.c0_c_param  := dcache0.io.tl.c.bits.param
  io.c0_d_valid  := dcache0.io.tl.d.valid
  io.c0_d_opcode := dcache0.io.tl.d.bits.opcode
  io.c0_d_param  := dcache0.io.tl.d.bits.param
  io.c0_e_valid  := dcache0.io.tl.e.valid

  // Export Core 1 Channel Monitor
  io.c1_a_valid  := dcache1.io.tl.a.valid
  io.c1_a_opcode := dcache1.io.tl.a.bits.opcode
  io.c1_a_param  := dcache1.io.tl.a.bits.param
  io.c1_a_addr   := dcache1.io.tl.a.bits.address
  io.c1_b_valid  := dcache1.io.tl.b.valid
  io.c1_b_param  := dcache1.io.tl.b.bits.param
  io.c1_c_valid  := dcache1.io.tl.c.valid
  io.c1_c_opcode := dcache1.io.tl.c.bits.opcode
  io.c1_c_param  := dcache1.io.tl.c.bits.param
  io.c1_d_valid  := dcache1.io.tl.d.valid
  io.c1_d_opcode := dcache1.io.tl.d.bits.opcode
  io.c1_d_param  := dcache1.io.tl.d.bits.param
  io.c1_e_valid  := dcache1.io.tl.e.valid
}
