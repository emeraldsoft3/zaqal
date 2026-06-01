package zaqal.backend.issue

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class BusyTableReadPort(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val addr = Input(UInt(phyRegIdxWidth.W))
  val ready = Output(Bool())
}

class BusyTable(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val readPorts = Vec(decodeWidth, Vec(3, new BusyTableReadPort))
    // We set busy when dispatching
    val allocPorts = Vec(decodeWidth, Input(Valid(UInt(phyRegIdxWidth.W))))
    // We set ready when waking up
    val wakeupPorts = Vec(decodeWidth, Input(Valid(UInt(phyRegIdxWidth.W))))
  })

  // Physical register readiness table. Initialized to true (ready)
  val ready_table = RegInit(VecInit(Seq.fill(phyRegs)(true.B)))
  
  val next_ready_table = Wire(Vec(phyRegs, Bool()))
  
  for (i <- 0 until phyRegs) {
    next_ready_table(i) := ready_table(i)
  }

  for (i <- 0 until decodeWidth) {
    when (io.wakeupPorts(i).valid && io.wakeupPorts(i).bits =/= 0.U) {
      next_ready_table(io.wakeupPorts(i).bits) := true.B
    }
    when (io.allocPorts(i).valid && io.allocPorts(i).bits =/= 0.U) {
      next_ready_table(io.allocPorts(i).bits) := false.B
    }
  }

  ready_table := next_ready_table

  // Read ports
  for (i <- 0 until decodeWidth) {
    for (j <- 0 until 3) {
      io.readPorts(i)(j).ready := Mux(io.readPorts(i)(j).addr === 0.U, true.B, next_ready_table(io.readPorts(i)(j).addr))
    }
  }
}
