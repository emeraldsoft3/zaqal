package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FastTLB(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val vaddr  = Input(UInt(xLen.W))
    val paddr  = Output(UInt(xLen.W))
    val hit    = Output(Bool())
  })

  // Simple direct-mapped or fully-associative TLB cache.
  // We model 4 entries. For simulation convenience, we initialize them with
  // identity mapping for expected address ranges (e.g. 0x80000000, 0x00000000).
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

  val vpn = io.vaddr(xLen - 1, 12)
  val page_offset = io.vaddr(11, 0)

  // Fully-associative lookup in 1 cycle (combinatorial)
  val hits = tlb.map(e => e.valid && e.vpn === vpn)
  val hit_idx = OHToUInt(hits)
  io.hit := hits.reduce(_ || _)

  // Fast-path translation: if hit, use mapped ppn, else default to identity mapping (to not break the simulation)
  val translated_ppn = Mux(io.hit, tlb(hit_idx).ppn, vpn)
  io.paddr := Cat(translated_ppn, page_offset)
}
