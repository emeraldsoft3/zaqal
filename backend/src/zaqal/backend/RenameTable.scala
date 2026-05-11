package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class RatReadPort(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val addr = Input(UInt(5.W))
  val data = Output(UInt(phyRegIdxWidth.W))
}

class RatWritePort(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val wen  = Bool()
  val addr = UInt(5.W)
  val data = UInt(phyRegIdxWidth.W)
}

class RenameTable(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val readPorts   = Vec(decodeWidth, Vec(3, new RatReadPort))
    val renamePorts = Vec(decodeWidth, Input(new RatWritePort))
    val commitPorts = Vec(decodeWidth, Input(new RatWritePort))
    
    val old_pdest   = Vec(decodeWidth, Output(UInt(phyRegIdxWidth.W)))
    val redirect    = Input(Bool())
    
    // Debug
    val debug_rat   = Output(Vec(logicalRegs, UInt(phyRegIdxWidth.W)))
  })

  // Initial mapping: x(i) -> p(i)
  // x0 is always p0
  val table_init = VecInit(Seq.tabulate(logicalRegs)(i => i.U(phyRegIdxWidth.W)))
  val spec_table = RegInit(table_init)
  val arch_table = RegInit(table_init)

  // 1. Rename Stage (Speculative)
  // We handle intra-bundle dependencies using a cascading wire table
  val curr_spec_table = Wire(Vec(decodeWidth + 1, Vec(logicalRegs, UInt(phyRegIdxWidth.W))))
  curr_spec_table(0) := spec_table

  for (i <- 0 until decodeWidth) {
    // Read source registers (rs1, rs2, rs3)
    io.readPorts(i)(0).data := curr_spec_table(i)(io.readPorts(i)(0).addr)
    io.readPorts(i)(1).data := curr_spec_table(i)(io.readPorts(i)(1).addr)
    io.readPorts(i)(2).data := curr_spec_table(i)(io.readPorts(i)(2).addr)
    
    // Capture old pdest for rd (used for ROB commit and recovery)
    io.old_pdest(i) := curr_spec_table(i)(io.renamePorts(i).addr)
    
    // Update for next instruction in the same bundle
    curr_spec_table(i+1) := curr_spec_table(i)
    when (io.renamePorts(i).wen && io.renamePorts(i).addr =/= 0.U) {
      curr_spec_table(i+1)(io.renamePorts(i).addr) := io.renamePorts(i).data
    }
  }
  
  // State Update
  when (io.redirect) {
    // On mispredict/exception, restore speculative table from architectural state
    // In a more advanced design, we would use snapshots here.
    spec_table := arch_table
  } .otherwise {
    spec_table := curr_spec_table(decodeWidth)
  }

  // 2. Commit Stage (Architectural)
  // These are updated when instructions reach the head of the ROB and commit.
  for (i <- 0 until decodeWidth) {
    when (io.commitPorts(i).wen && io.commitPorts(i).addr =/= 0.U) {
      arch_table(io.commitPorts(i).addr) := io.commitPorts(i).data
    }
  }
  
  io.debug_rat := arch_table
}
