package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal.common._
import zaqal.frontend.cache._

class BPU(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val req = Flipped(Valid(UInt(p.xLen.W)))
    val resp = Output(new BranchPredictionBus)
    val update = Flipped(Valid(new BranchPredictionBus))
  })

  val btb = Module(new BTB)
  val ras = Module(new RAS)

  btb.io.req := io.req
  io.resp := btb.io.resp

  btb.io.update := io.update

  // Initialize RAS push inputs to satisfy FIRRTL
  ras.io.push.valid := false.B
  ras.io.push.bits := 0.U
}
