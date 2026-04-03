package zaqal.frontend.cache

import chisel3._
import chisel3.util._
import zaqal.common._

class ICache(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val req = Flipped(Decoupled(UInt(p.xLen.W)))
    val resp = Decoupled(new FetchPacket)
  })

  // Mock instruction memory with some test programs
  val mem = VecInit(Seq(
    // Simple loop or branch test
    0x00100093, // li x1, 1
    0x00200113, // li x2, 2
    0x002081b3, // add x3, x1, x2  (x3 = 3)
    0x00310863, // beq x2, x3, label (skip next) -> not taken
    0x001101b3, // add x3, x2, x1  (x3 = 3)
    0x0000006f  // j . (infinite loop)
  ).map(_.U(32.W)))

  val addr = io.req.bits >> 2
  io.resp.valid := io.req.valid
  io.req.ready := io.resp.ready

  io.resp.bits.pc := io.req.bits
  io.resp.bits.instrs.foreach(_ := 0.U) // Initialize all to 0
  io.resp.bits.instrs(0) := mem(addr(log2Up(mem.length)-1, 0))
  io.resp.bits.mask := 1.U
  io.resp.bits.pred_target := 0.U
  io.resp.bits.pred_taken := false.B
  io.resp.bits.pred_slot := 0.U
}
