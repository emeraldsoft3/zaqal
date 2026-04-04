package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class RAS(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val push = Flipped(Valid(UInt(xLen.W)))
    val pop = Output(Valid(UInt(xLen.W)))
  })

  // Simple RAS implementation
  val stack = RegInit(VecInit(Seq.fill(8)(0.U(xLen.W))))
  val sp = RegInit(0.U(3.W))

  // Dummy logic
  io.pop.valid := false.B
  io.pop.bits := 0.U
}
