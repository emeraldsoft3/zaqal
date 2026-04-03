package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal.common._

class BTB(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val req = Flipped(Valid(UInt(p.xLen.W)))
    val resp = Output(new BranchPredictionBus)
    val update = Flipped(Valid(new BranchPredictionBus))
  })

  // Simple BTB implementation
  val entries = RegInit(VecInit(Seq.fill(16)(0.U.asTypeOf(new BranchPredictionBus))))
  
  // Dummy logic for now
  io.resp := entries(io.req.bits(5, 2))
}
