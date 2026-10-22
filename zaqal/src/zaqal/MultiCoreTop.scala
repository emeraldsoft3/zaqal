package zaqal

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.cache._
import zaqal.cache.prefetch._

// ============================================================================
// MultiCoreCoherenceTop
// Dual-Core Multi-Level Cache Coherence Verification Framework integrating:
// - Core 0 & Core 1 Coherent L1 D-Caches (DCache)
// - Inclusive L2 Cache with Hardware MESI Directory & Back-Invalidation (L2Cache)
// - Shared Multi-Cluster L3 Cache (L3Cache)
// - Complete 5-Channel TileLink-C Snoop, Probe, and Dirty-Line Forwarding
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

    // ------------------------------------------------------------------------
    // Inclusive L2 Cache Observability & Coherence Signals
    // ------------------------------------------------------------------------
    val l2_fsm_state              = Output(UInt(4.W))
    val l2_hit                    = Output(Bool())
    val l2_miss                   = Output(Bool())
    val l2_eviction               = Output(Bool())
    val l2_mesi_state             = Output(UInt(2.W))
    val l2_sharer_mask            = Output(UInt(2.W))
    val l2_active_way             = Output(UInt(2.W))
    val l2_active_addr            = Output(UInt(xLen.W))
    val l2_line_data              = Output(UInt(tlDataBits.W))

    val debug_probe_fire          = Output(Vec(2, Bool()))
    val debug_probe_ack_fire      = Output(Vec(2, Bool()))
    val debug_probe_ack_data_fire = Output(Vec(2, Bool()))
    val debug_grant_fire          = Output(Vec(2, Bool()))
    val debug_grant_ack_fire      = Output(Vec(2, Bool()))
    val debug_back_inv_fire       = Output(Vec(2, Bool()))

    // ------------------------------------------------------------------------
    // Shared L3 Cache Observability Signals
    // ------------------------------------------------------------------------
    val l3_hit                    = Output(Bool())
    val l3_miss                   = Output(Bool())
    val l3_data                   = Output(UInt(tlDataBits.W))

    // ------------------------------------------------------------------------
    // Core 0 TileLink-C Channel Monitor
    // ------------------------------------------------------------------------
    val c0_a_valid   = Output(Bool())
    val c0_a_opcode  = Output(UInt(3.W))
    val c0_a_param   = Output(UInt(3.W))
    val c0_a_addr    = Output(UInt(xLen.W))
    val c0_b_valid   = Output(Bool())
    val c0_b_param   = Output(UInt(3.W))
    val c0_c_valid   = Output(Bool())
    val c0_c_opcode  = Output(UInt(3.W))
    val c0_c_param   = Output(UInt(3.W))
    val c0_c_data    = Output(UInt(tlDataBits.W))
    val c0_d_valid   = Output(Bool())
    val c0_d_opcode  = Output(UInt(3.W))
    val c0_d_param   = Output(UInt(3.W))
    val c0_d_data    = Output(UInt(tlDataBits.W))
    val c0_e_valid   = Output(Bool())

    // ------------------------------------------------------------------------
    // Core 1 TileLink-C Channel Monitor
    // ------------------------------------------------------------------------
    val c1_a_valid   = Output(Bool())
    val c1_a_opcode  = Output(UInt(3.W))
    val c1_a_param   = Output(UInt(3.W))
    val c1_a_addr    = Output(UInt(xLen.W))
    val c1_b_valid   = Output(Bool())
    val c1_b_param   = Output(UInt(3.W))
    val c1_c_valid   = Output(Bool())
    val c1_c_opcode  = Output(UInt(3.W))
    val c1_c_param   = Output(UInt(3.W))
    val c1_c_data    = Output(UInt(tlDataBits.W))
    val c1_d_valid   = Output(Bool())
    val c1_d_opcode  = Output(UInt(3.W))
    val c1_d_param   = Output(UInt(3.W))
    val c1_d_data    = Output(UInt(tlDataBits.W))
    val c1_e_valid   = Output(Bool())
  })

  // 1. Instantiate Private L1 D-Caches
  val dcache0 = Module(new DCache)
  val dcache1 = Module(new DCache)

  // 2. Instantiate Inclusive L2 Cache (4-way set-associative with MESI Directory)
  val l2 = Module(new L2Cache(nClients = 2, nSets = 32, nWays = 4))

  // 3. Instantiate Shared L3 Cache (4-way set-associative Last Level Cache)
  val l3 = Module(new L3Cache(nSets = 64, nWays = 4))

  // Connect L1 D-Caches to Inclusive L2 Cache
  l2.io.clients(0) <> dcache0.io.tl
  l2.io.clients(1) <> dcache1.io.tl

  // Connect Inclusive L2 Cache downstream to Shared L3 Cache
  l3.io.l2_tl <> l2.io.downstream_tl

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

  // Tie off L3 backing memory bus (DRAM responder simulation)
  l3.io.mem.req.ready := true.B
  l3.io.mem.resp.valid := false.B
  l3.io.mem.resp.bits := 0.U.asTypeOf(new MemoryBusResp(tlDataBits))

  // Export Inclusive L2 Cache Signals
  io.l2_fsm_state              := l2.io.debug_fsm_state
  io.l2_hit                    := l2.io.debug_l2_hit
  io.l2_miss                   := l2.io.debug_l2_miss
  io.l2_eviction               := l2.io.debug_l2_eviction
  io.l2_mesi_state             := l2.io.debug_mesi_state
  io.l2_sharer_mask            := l2.io.debug_sharer_mask
  io.l2_active_way             := l2.io.debug_active_way
  io.l2_active_addr            := l2.io.debug_active_addr
  io.l2_line_data              := l2.io.debug_line_data
  io.debug_probe_fire          := l2.io.debug_probe_fire
  io.debug_probe_ack_fire      := l2.io.debug_probe_ack_fire
  io.debug_probe_ack_data_fire := l2.io.debug_probe_ack_data_fire
  io.debug_grant_fire          := l2.io.debug_grant_fire
  io.debug_grant_ack_fire      := l2.io.debug_grant_ack_fire
  io.debug_back_inv_fire       := l2.io.debug_l2_back_inv_fire

  // Export Shared L3 Cache Signals
  io.l3_hit                    := l3.io.debug_hit
  io.l3_miss                   := l3.io.debug_miss
  io.l3_data                   := l3.io.debug_data

  // Export Core 0 TileLink Channel Monitor
  io.c0_a_valid  := dcache0.io.tl.a.valid
  io.c0_a_opcode := dcache0.io.tl.a.bits.opcode
  io.c0_a_param  := dcache0.io.tl.a.bits.param
  io.c0_a_addr   := dcache0.io.tl.a.bits.address
  io.c0_b_valid  := dcache0.io.tl.b.valid
  io.c0_b_param  := dcache0.io.tl.b.bits.param
  io.c0_c_valid  := dcache0.io.tl.c.valid
  io.c0_c_opcode := dcache0.io.tl.c.bits.opcode
  io.c0_c_param  := dcache0.io.tl.c.bits.param
  io.c0_c_data   := dcache0.io.tl.c.bits.data
  io.c0_d_valid  := dcache0.io.tl.d.valid
  io.c0_d_opcode := dcache0.io.tl.d.bits.opcode
  io.c0_d_param  := dcache0.io.tl.d.bits.param
  io.c0_d_data   := dcache0.io.tl.d.bits.data
  io.c0_e_valid  := dcache0.io.tl.e.valid

  // Export Core 1 TileLink Channel Monitor
  io.c1_a_valid  := dcache1.io.tl.a.valid
  io.c1_a_opcode := dcache1.io.tl.a.bits.opcode
  io.c1_a_param  := dcache1.io.tl.a.bits.param
  io.c1_a_addr   := dcache1.io.tl.a.bits.address
  io.c1_b_valid  := dcache1.io.tl.b.valid
  io.c1_b_param  := dcache1.io.tl.b.bits.param
  io.c1_c_valid  := dcache1.io.tl.c.valid
  io.c1_c_opcode := dcache1.io.tl.c.bits.opcode
  io.c1_c_param  := dcache1.io.tl.c.bits.param
  io.c1_c_data   := dcache1.io.tl.c.bits.data
  io.c1_d_valid  := dcache1.io.tl.d.valid
  io.c1_d_opcode := dcache1.io.tl.d.bits.opcode
  io.c1_d_param  := dcache1.io.tl.d.bits.param
  io.c1_d_data   := dcache1.io.tl.d.bits.data
  io.c1_e_valid  := dcache1.io.tl.e.valid
}

// ============================================================================
// DualCoreTop
// Full Multi-Hart System-on-Chip integrating:
// - Two Full Out-of-Order RISC-V Cores (Hart 0 and Hart 1)
// - Coherent Inclusive L2 Cache with Hardware MESI Directory
// - Shared Multi-Cluster L3 Cache (LLC)
// - Independent L1 Instruction Memory Ports (c0_mem, c1_mem)
// - Backing DRAM Memory Bus
// ============================================================================
class DualCoreTop(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Instruction Memory Busses for Core 0 & Core 1
    val c0_mem = new MemoryBus(xLen, instBits * fetchWidth)
    val c1_mem = new MemoryBus(xLen, instBits * fetchWidth)

    // Backing DRAM Memory Bus for L3 Cache
    val mem_l3 = new MemoryBus(xLen, tlDataBits)

    // Status & Direct Architectural Observability
    val c0_success   = Output(Bool())
    val c1_success   = Output(Bool())
    val c0_pc        = Output(UInt(xLen.W))
    val c1_pc        = Output(UInt(xLen.W))

    val c0_reg_x1    = Output(UInt(xLen.W))
    val c0_reg_x2    = Output(UInt(xLen.W))
    val c0_reg_x3    = Output(UInt(xLen.W))
    val c0_reg_x29   = Output(UInt(xLen.W))

    val c1_reg_x1    = Output(UInt(xLen.W))
    val c1_reg_x2    = Output(UInt(xLen.W))
    val c1_reg_x3    = Output(UInt(xLen.W))
    val c1_reg_x29   = Output(UInt(xLen.W))

    // Inclusive L2 Cache Coherence Observability
    val l2_fsm_state   = Output(UInt(4.W))
    val l2_hit         = Output(Bool())
    val l2_miss        = Output(Bool())
    val l2_eviction    = Output(Bool())
    val l2_mesi_state  = Output(UInt(2.W))
    val l2_sharer_mask = Output(UInt(2.W))

    // Shared L3 Cache Observability
    val l3_hit         = Output(Bool())
    val l3_miss        = Output(Bool())

    // TileLink Monitors
    val c0_a_valid     = Output(Bool())
    val c0_a_opcode    = Output(UInt(3.W))
    val c0_a_addr      = Output(UInt(xLen.W))
    val c0_b_valid     = Output(Bool())
    val c0_b_param     = Output(UInt(3.W))
    val c0_c_valid     = Output(Bool())
    val c0_c_opcode    = Output(UInt(3.W))
    val c0_c_data      = Output(UInt(tlDataBits.W))
    val c0_d_valid     = Output(Bool())
    val c0_d_opcode    = Output(UInt(3.W))
    val c0_d_data      = Output(UInt(tlDataBits.W))
    val c0_e_valid     = Output(Bool())

    val c1_a_valid     = Output(Bool())
    val c1_a_opcode    = Output(UInt(3.W))
    val c1_a_addr      = Output(UInt(xLen.W))
    val c1_b_valid     = Output(Bool())
    val c1_b_param     = Output(UInt(3.W))
    val c1_c_valid     = Output(Bool())
    val c1_c_opcode    = Output(UInt(3.W))
    val c1_c_data      = Output(UInt(tlDataBits.W))
    val c1_d_valid     = Output(Bool())
    val c1_d_opcode    = Output(UInt(3.W))
    val c1_d_data      = Output(UInt(tlDataBits.W))
    val c1_e_valid     = Output(Bool())
  })

  // 1. Instantiate the Two Complete Out-of-Order RISC-V Cores
  val core0 = Module(new Core(hartId = 0))
  val core1 = Module(new Core(hartId = 1))

  // 2. Instantiate Inclusive L2 Cache and Shared L3 Cache
  val l2 = Module(new L2Cache(nClients = 2, nSets = 32, nWays = 4))
  val l3 = Module(new L3Cache(nSets = 64, nWays = 4))

  // 3. Connect Cores' TileLink D-Cache ports to L2 Clients
  l2.io.clients(0) <> core0.io.tl_d
  l2.io.clients(1) <> core1.io.tl_d

  // 4. Connect Inclusive L2 Cache downstream to Shared L3 Cache
  l3.io.l2_tl <> l2.io.downstream_tl

  // 5. Connect Frontend Instruction Memory ports
  core0.io.mem <> io.c0_mem
  core1.io.mem <> io.c1_mem

  // 6. Connect Backing DRAM port
  io.mem_l3 <> l3.io.mem

  // Tie off legacy uncached ports
  core0.io.mem_d.req.ready  := true.B
  core0.io.mem_d.resp.valid := false.B
  core0.io.mem_d.resp.bits  := 0.U.asTypeOf(new MemoryBusResp(256))

  core1.io.mem_d.req.ready  := true.B
  core1.io.mem_d.resp.valid := false.B
  core1.io.mem_d.resp.bits  := 0.U.asTypeOf(new MemoryBusResp(256))

  core0.io.plic_ext_irq := 0.U
  core1.io.plic_ext_irq := 0.U

  // Status
  io.c0_success := core0.io.success
  io.c1_success := core1.io.success

  // Architectural Register Sampling
  if (enableDebugPorts) {
    io.c0_pc := core0.debug.get.ftq_pc
    io.c1_pc := core1.debug.get.ftq_pc

    val c0_rat1  = core0.debug.get.debug_int_rat(1)
    val c0_rat2  = core0.debug.get.debug_int_rat(2)
    val c0_rat3  = core0.debug.get.debug_int_rat(3)
    val c0_rat29 = core0.debug.get.debug_int_rat(29)

    val c1_rat1  = core1.debug.get.debug_int_rat(1)
    val c1_rat2  = core1.debug.get.debug_int_rat(2)
    val c1_rat3  = core1.debug.get.debug_int_rat(3)
    val c1_rat29 = core1.debug.get.debug_int_rat(29)

    io.c0_reg_x1  := core0.debug.get.regs(c0_rat1)
    io.c0_reg_x2  := core0.debug.get.regs(c0_rat2)
    io.c0_reg_x3  := core0.debug.get.regs(c0_rat3)
    io.c0_reg_x29 := core0.debug.get.regs(c0_rat29)

    io.c1_reg_x1  := core1.debug.get.regs(c1_rat1)
    io.c1_reg_x2  := core1.debug.get.regs(c1_rat2)
    io.c1_reg_x3  := core1.debug.get.regs(c1_rat3)
    io.c1_reg_x29 := core1.debug.get.regs(c1_rat29)
  } else {
    io.c0_pc := 0.U
    io.c1_pc := 0.U
    io.c0_reg_x1  := 0.U
    io.c0_reg_x2  := 0.U
    io.c0_reg_x3  := 0.U
    io.c0_reg_x29 := 0.U
    io.c1_reg_x1  := 0.U
    io.c1_reg_x2  := 0.U
    io.c1_reg_x3  := 0.U
    io.c1_reg_x29 := 0.U
  }

  // L2 & L3 Observability
  io.l2_fsm_state   := l2.io.debug_fsm_state
  io.l2_hit         := l2.io.debug_l2_hit
  io.l2_miss        := l2.io.debug_l2_miss
  io.l2_eviction    := l2.io.debug_l2_eviction
  io.l2_mesi_state  := l2.io.debug_mesi_state
  io.l2_sharer_mask := l2.io.debug_sharer_mask
  io.l3_hit         := l3.io.debug_hit
  io.l3_miss        := l3.io.debug_miss

  // Core 0 TileLink Channel Monitor
  io.c0_a_valid  := core0.io.tl_d.a.valid
  io.c0_a_opcode := core0.io.tl_d.a.bits.opcode
  io.c0_a_addr   := core0.io.tl_d.a.bits.address
  io.c0_b_valid  := core0.io.tl_d.b.valid
  io.c0_b_param  := core0.io.tl_d.b.bits.param
  io.c0_c_valid  := core0.io.tl_d.c.valid
  io.c0_c_opcode := core0.io.tl_d.c.bits.opcode
  io.c0_c_data   := core0.io.tl_d.c.bits.data
  io.c0_d_valid  := core0.io.tl_d.d.valid
  io.c0_d_opcode := core0.io.tl_d.d.bits.opcode
  io.c0_d_data   := core0.io.tl_d.d.bits.data
  io.c0_e_valid  := core0.io.tl_d.e.valid

  // Core 1 TileLink Channel Monitor
  io.c1_a_valid  := core1.io.tl_d.a.valid
  io.c1_a_opcode := core1.io.tl_d.a.bits.opcode
  io.c1_a_addr   := core1.io.tl_d.a.bits.address
  io.c1_b_valid  := core1.io.tl_d.b.valid
  io.c1_b_param  := core1.io.tl_d.b.bits.param
  io.c1_c_valid  := core1.io.tl_d.c.valid
  io.c1_c_opcode := core1.io.tl_d.c.bits.opcode
  io.c1_c_data   := core1.io.tl_d.c.bits.data
  io.c1_d_valid  := core1.io.tl_d.d.valid
  io.c1_d_opcode := core1.io.tl_d.d.bits.opcode
  io.c1_d_data   := core1.io.tl_d.d.bits.data
  io.c1_e_valid  := core1.io.tl_d.e.valid
}

