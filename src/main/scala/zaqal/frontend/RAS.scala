package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal.common._

class RAS(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val push = Flipped(Valid(UInt(p.xLen.W)))
    val pop = Output(Valid(UInt(p.xLen.W)))
  })

  // Simple RAS implementation
  val stack = RegInit(VecInit(Seq.fill(8)(0.U(p.xLen.W))))
  val sp = RegInit(0.U(3.W))

  // Dummy logic
  io.pop.valid := false.B
  io.pop.bits := 0.U
}
