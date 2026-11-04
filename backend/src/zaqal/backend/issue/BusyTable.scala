package zaqal.backend.issue

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class BusyTableReadPort(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val addr = Input(UInt(phyRegIdxWidth.W))
  val ready = Output(Bool())
}

class BusyTable(val numWakeup: Int = 14, val numFlushed: Int = 128)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val readPorts = Vec(decodeWidth, Vec(3, new BusyTableReadPort))
    // We set busy when dispatching
    val allocPorts = Vec(decodeWidth, Input(Valid(UInt(phyRegIdxWidth.W))))
    // We set ready when waking up
    val wakeupPorts = Vec(numWakeup, Input(Valid(UInt(phyRegIdxWidth.W))))
    // Flushed instructions in ROB release their busy registers
    val flushedPorts = Vec(numFlushed, Input(Valid(UInt(phyRegIdxWidth.W))))
  })

  // Physical register readiness table. Initialized to true (ready)
  val ready_table = RegInit(VecInit(Seq.fill(phyRegs)(true.B)))
  
  val next_ready_table = Wire(Vec(phyRegs, Bool()))
  
  for (i <- 0 until phyRegs) {
    next_ready_table(i) := ready_table(i)
  }

  // 1. Release flushed destinations back to ready
  for (i <- 0 until numFlushed) {
    when (io.flushedPorts(i).valid && io.flushedPorts(i).bits =/= 0.U) {
      next_ready_table(io.flushedPorts(i).bits) := true.B
    }
  }

  // 2. Wakeup ports (writeback) set destination to ready
  for (i <- 0 until numWakeup) {
    when (io.wakeupPorts(i).valid && io.wakeupPorts(i).bits =/= 0.U) {
      next_ready_table(io.wakeupPorts(i).bits) := true.B
    }
  }

  // 3. New allocations set destination to busy
  for (i <- 0 until decodeWidth) {
    when (io.allocPorts(i).valid && io.allocPorts(i).bits =/= 0.U) {
      next_ready_table(io.allocPorts(i).bits) := false.B
    }
  }

  // Register 0 is always ready
  next_ready_table(0) := true.B

  ready_table := next_ready_table

  // Read ports
  for (i <- 0 until decodeWidth) {
    for (j <- 0 until 3) {
      io.readPorts(i)(j).ready := Mux(io.readPorts(i)(j).addr === 0.U, true.B, next_ready_table(io.readPorts(i)(j).addr))
    }
  }
}
