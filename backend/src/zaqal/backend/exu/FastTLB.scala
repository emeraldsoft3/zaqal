package zaqal.backend.exu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class TLBRefillBundle(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val vpn = UInt((xLen - 12).W)
  val ppn = UInt((xLen - 12).W)
}

class FastTLB(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val vaddr  = Input(UInt(xLen.W))
    val paddr  = Output(UInt(xLen.W))
    val hit    = Output(Bool())

    // Dynamic Refill from Page Table Walker
    val refill = Input(Valid(new TLBRefillBundle))
    val flush  = Input(Bool())
  })

  // 4-entry fully-associative TLB.
  // Entry 0 is seeded with 0x80000 for PC base bootstrap.
  // Entries 1-3 are dynamically refilled by the Page Table Walker.
  val tlb = RegInit(VecInit(Seq.tabulate(4)(i => {
    val entry = Wire(new Bundle {
      val valid = Bool()
      val vpn   = UInt((xLen - 12).W)
      val ppn   = UInt((xLen - 12).W)
    })
    entry.valid := true.B
    val baseVpn = Mux(i.U === 0.U, "h80000".U((xLen - 12).W), (i * 0x1000).U((xLen - 12).W))
    entry.vpn   := baseVpn
    entry.ppn   := baseVpn
    entry
  })))

  // Round-robin pointer for dynamic entry allocation (slots 1..3)
  val repl_ptr = RegInit(1.U(2.W))

  when(io.refill.valid) {
    tlb(repl_ptr).valid := true.B
    tlb(repl_ptr).vpn   := io.refill.bits.vpn
    tlb(repl_ptr).ppn   := io.refill.bits.ppn
    repl_ptr := Mux(repl_ptr === 3.U, 1.U, repl_ptr + 1.U)
  }

  val vpn = io.vaddr(xLen - 1, 12)
  val page_offset = io.vaddr(11, 0)

  // Fully-associative lookup in 1 cycle (combinatorial)
  val hits = tlb.map(e => e.valid && e.vpn === vpn)
  val hit_idx = OHToUInt(hits)
  io.hit := hits.reduce(_ || _)

  // Fast-path translation: if hit, use mapped ppn, else default to identity mapping
  val translated_ppn = Mux(io.hit, tlb(hit_idx).ppn, vpn)
  io.paddr := Cat(translated_ppn, page_offset)
}
