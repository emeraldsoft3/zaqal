package zaqal.backend.devices

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
  * Platform-Level Interrupt Controller (PLIC)
  * Standard RISC-V specification:
  *   0x0C00_0000 - 0x0C00_007F: Source Priorities (Sources 0-31, 4 bytes each)
  *   0x0C00_1000 - 0x0C00_1003: Pending bitmap (Sources 0-31)
  *   0x0C00_2000 - 0x0C00_2003: Context 0 (Hart 0 M-mode) Enable bitmap
  *   0x0C00_2080 - 0x0C00_2083: Context 1 (Hart 0 S-mode) Enable bitmap
  *   0x0C20_0000 - 0x0C20_0003: Context 0 Priority Threshold
  *   0x0C20_0004 - 0x0C20_0007: Context 0 Claim / Complete
  *   0x0C20_1000 - 0x0C20_1003: Context 1 Priority Threshold
  *   0x0C20_1004 - 0x0C20_1007: Context 1 Claim / Complete
  */
class PLICIO(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  // MMIO Dual Read Channels
  val raddr  = Vec(2, Input(UInt(xLen.W)))
  val rdata  = Vec(2, Output(UInt(128.W)))
  val rvalid = Vec(2, Output(Bool()))

  // MMIO Write Channel
  val wen   = Input(Bool())
  val waddr = Input(UInt(xLen.W))
  val wdata = Input(UInt(128.W))
  val wmask = Input(UInt(16.W))

  // External Peripheral Interrupt Lines (Bit 0 reserved, Bits 1..31 for devices)
  val external_sources = Input(UInt(32.W))

  // CPU Interrupt Notification Wires
  val meip = Output(Bool())
  val seip = Output(Bool())
}

class PLIC(val numSources: Int = 32)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new PLICIO)

  // Architectural Registers
  val r_priority    = RegInit(VecInit(Seq.fill(numSources)(0.U(3.W)))) // 3-bit priorities (0-7)
  val r_pending     = RegInit(0.U(numSources.W))
  val r_in_flight   = RegInit(0.U(numSources.W)) // Gateway in-flight tracking
  val r_enable_m    = RegInit(0.U(numSources.W))
  val r_enable_s    = RegInit(0.U(numSources.W))
  val r_threshold_m = RegInit(0.U(3.W))
  val r_threshold_s = RegInit(0.U(3.W))

  // Gateway: Detect incoming external interrupt edges/levels
  val ext_latch = VecInit((0 until numSources).map { i =>
    if (i == 0) false.B
    else io.external_sources(i) && !r_in_flight(i)
  }).asUInt

  val next_pending = r_pending | ext_latch

  // =========================================================================
  // PLIC Arbiter: Determine Highest Priority Pending Interrupt
  // =========================================================================
  def findBestCandidate(pending: UInt, enable: UInt, threshold: UInt): (Bool, UInt) = {
    var best_id   = 0.U(log2Up(numSources).W)
    var max_prio  = 0.U(3.W)
    var any_valid = false.B

    for (i <- 1 until numSources) {
      val is_cand = pending(i) && enable(i) && (r_priority(i) > threshold)
      val is_better = is_cand && (!any_valid || (r_priority(i) > max_prio))
      best_id   = Mux(is_better, i.U, best_id)
      max_prio  = Mux(is_better, r_priority(i), max_prio)
      any_valid = any_valid || is_cand
    }
    (any_valid, best_id)
  }

  val (has_m_irq, best_m_id) = findBestCandidate(r_pending, r_enable_m, r_threshold_m)
  val (has_s_irq, best_s_id) = findBestCandidate(r_pending, r_enable_s, r_threshold_s)

  io.meip := has_m_irq
  io.seip := has_s_irq

  // =========================================================================
  // MMIO Write Handling
  // =========================================================================
  val is_plic_write = io.wen && (io.waddr >= "h0C000000".U && io.waddr < "h0C400000".U)
  val w_offset = io.waddr(23, 0)
  val w_lane   = io.waddr(3)
  val w_val64  = Mux(w_lane, io.wdata(127, 64), io.wdata(63, 0))
  val w_val32  = Mux(io.waddr(2), w_val64(63, 32), w_val64(31, 0))

  val completed_mask = WireDefault(0.U(numSources.W))

  when(is_plic_write) {
    when(w_offset < "h0080".U) {
      // Source Priorities (0x0C00_0000 + 4*i)
      val src_idx = w_offset(6, 2)
      when(src_idx =/= 0.U) {
        r_priority(src_idx) := w_val32(2, 0)
        printf(p"[PLIC WRITE] Priority($src_idx) := ${w_val32(2, 0)}\n")
      }
    } .elsewhen(w_offset === "h2000".U) {
      // Context 0 Enable
      r_enable_m := w_val32
      printf(p"[PLIC WRITE] Context 0 M-Enable := ${Hexadecimal(w_val32)}\n")
    } .elsewhen(w_offset === "h2080".U) {
      // Context 1 Enable
      r_enable_s := w_val32
      printf(p"[PLIC WRITE] Context 1 S-Enable := ${Hexadecimal(w_val32)}\n")
    } .elsewhen(w_offset === "h200000".U) {
      // Context 0 Threshold
      r_threshold_m := w_val32(2, 0)
      printf(p"[PLIC WRITE] Context 0 M-Threshold := ${w_val32(2, 0)}\n")
    } .elsewhen(w_offset === "h200004".U) {
      // Context 0 Complete: signals servicing done to gateway
      val comp_id = w_val32(4, 0)
      completed_mask := 1.U << comp_id
      printf(p"[PLIC COMPLETE] Context 0 M completed source $comp_id\n")
    } .elsewhen(w_offset === "h201000".U) {
      // Context 1 Threshold
      r_threshold_s := w_val32(2, 0)
      printf(p"[PLIC WRITE] Context 1 S-Threshold := ${w_val32(2, 0)}\n")
    } .elsewhen(w_offset === "h201004".U) {
      // Context 1 Complete
      val comp_id = w_val32(4, 0)
      completed_mask := 1.U << comp_id
      printf(p"[PLIC COMPLETE] Context 1 S completed source $comp_id\n")
    }
  }

  // =========================================================================
  // MMIO Read Handling & Claim Logic
  // =========================================================================
  val claimed_m_vec = Wire(Vec(2, UInt(numSources.W)))
  val claimed_s_vec = Wire(Vec(2, UInt(numSources.W)))

  for (i <- 0 until 2) {
    val is_plic_read = io.raddr(i) >= "h0C000000".U && io.raddr(i) < "h0C400000".U
    val r_offset = io.raddr(i)(23, 0)
    val r_val32  = WireDefault(0.U(32.W))
    claimed_m_vec(i) := 0.U
    claimed_s_vec(i) := 0.U

    when(r_offset < "h0080".U) {
      val src_idx = r_offset(6, 2)
      r_val32 := r_priority(src_idx)
    } .elsewhen(r_offset === "h1000".U) {
      r_val32 := r_pending
    } .elsewhen(r_offset === "h2000".U) {
      r_val32 := r_enable_m
    } .elsewhen(r_offset === "h2080".U) {
      r_val32 := r_enable_s
    } .elsewhen(r_offset === "h200000".U) {
      r_val32 := r_threshold_m
    } .elsewhen(r_offset === "h200004".U) {
      // Context 0 Claim
      r_val32 := best_m_id
      when(has_m_irq && is_plic_read) {
        claimed_m_vec(i) := 1.U << best_m_id
        printf(p"[PLIC CLAIM] Context 0 M claimed source $best_m_id\n")
      }
    } .elsewhen(r_offset === "h201000".U) {
      r_val32 := r_threshold_s
    } .elsewhen(r_offset === "h201004".U) {
      // Context 1 Claim
      r_val32 := best_s_id
      when(has_s_irq && is_plic_read) {
        claimed_s_vec(i) := 1.U << best_s_id
        printf(p"[PLIC CLAIM] Context 1 S claimed source $best_s_id\n")
      }
    }

    io.rvalid(i) := is_plic_read
    val r_shift = io.raddr(i)(3, 2) << 5
    io.rdata(i) := (r_val32.pad(128)) << r_shift
  }

  val total_claimed_mask = claimed_m_vec(0) | claimed_m_vec(1) | claimed_s_vec(0) | claimed_s_vec(1)

  // Update pending and in-flight registers
  r_pending   := (next_pending & ~total_claimed_mask)
  r_in_flight := (r_in_flight | total_claimed_mask) & ~completed_mask
}
