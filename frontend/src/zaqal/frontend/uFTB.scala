package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class MicroFTBEntry(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val valid   = Bool()
  val tag     = UInt((xLen - 4).W) // 16-byte aligned tag
  val target  = UInt(xLen.W)
  val br_type = UInt(2.W) // 0: cond, 1: jal, 2: jalr, 3: call
}

class uFTB(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val req_pc      = Input(UInt(xLen.W))
    val pred_hit    = Output(Bool())
    val pred_target = Output(UInt(xLen.W))
    val pred_br_type= Output(UInt(2.W))

    // Update from BRU (acts as L0 fill)
    val update_valid  = Input(Bool())
    val update_pc     = Input(UInt(xLen.W))
    val update_target = Input(UInt(xLen.W))
    val update_br_type= Input(UInt(2.W))
  })

  val uftbEntries = 16 // Small, fully associative array for 0-cycle lookup
  val entries = RegInit(VecInit(Seq.fill(uftbEntries)(0.U.asTypeOf(new MicroFTBEntry))))
  val alloc_ptr = RegInit(0.U(log2Up(uftbEntries).W))

  // Combinational Lookup (Stage 0)
  val req_tag = io.req_pc(xLen - 1, 4)
  val hits = VecInit(entries.map(e => e.valid && (e.tag === req_tag)))
  val hit_idx = PriorityEncoder(hits)
  val is_hit = hits.asUInt.orR

  io.pred_hit     := is_hit
  io.pred_target  := Mux(is_hit, entries(hit_idx).target, 0.U)
  io.pred_br_type := Mux(is_hit, entries(hit_idx).br_type, 0.U)

  // Update / Allocate logic (FIFO replacement)
  when(io.update_valid) {
    val update_tag = io.update_pc(xLen - 1, 4)
    val update_hits = VecInit(entries.map(e => e.valid && (e.tag === update_tag)))
    val update_hit_idx = PriorityEncoder(update_hits)
    val is_update_hit = update_hits.asUInt.orR

    when(is_update_hit) {
      // Update existing entry
      entries(update_hit_idx).target  := io.update_target
      entries(update_hit_idx).br_type := io.update_br_type
    } .otherwise {
      // Allocate new entry
      entries(alloc_ptr).valid   := true.B
      entries(alloc_ptr).tag     := update_tag
      entries(alloc_ptr).target  := io.update_target
      entries(alloc_ptr).br_type := io.update_br_type
      alloc_ptr := alloc_ptr + 1.U
    }
  }
}
