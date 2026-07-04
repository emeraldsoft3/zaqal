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

class RenameTable(val numLogicalRegs: Int, val isFP: Boolean = false)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val readPorts   = Vec(decodeWidth, Vec(3, new RatReadPort))
    val renamePorts = Vec(decodeWidth, Input(new RatWritePort))
    val commitPorts = Vec(decodeWidth, Input(new RatWritePort))
    
    val old_pdest   = Vec(decodeWidth, Output(UInt(phyRegIdxWidth.W)))
    val redirect    = Input(Bool())
    val useSnapshot = Input(Bool())
    
    // Checkpoint IO
    val snptEnq        = Input(Bool())
    val snptEnqIdx     = Input(UInt(log2Up(decodeWidth + 1).W))
    val snptDeq        = Input(Bool())
    val snptFlushVec   = Input(Vec(renameSnapshotNum, Bool()))
    val snptRestoreIdx = Input(UInt(log2Up(renameSnapshotNum).W))
    val snptEnqPtr     = Output(UInt(log2Up(renameSnapshotNum).W))
    val snptDeqPtr     = Output(UInt(log2Up(renameSnapshotNum).W))
    val snptValids     = Output(Vec(renameSnapshotNum, Bool()))
    
    // Debug
    val debug_rat   = Output(Vec(numLogicalRegs, UInt(phyRegIdxWidth.W)))
  })

  // Initial mapping: x(i) -> p(i)
  val table_init = VecInit(Seq.tabulate(numLogicalRegs)(i => i.U(phyRegIdxWidth.W)))
  val spec_table = RegInit(table_init)
  val arch_table = RegInit(table_init)

  val snapshots = Module(new SnapshotGenerator(Vec(numLogicalRegs, UInt(phyRegIdxWidth.W))))

  // 1. Rename Stage (Speculative)
  // We handle intra-bundle dependencies using a cascading wire table
  val curr_spec_table = Wire(Vec(decodeWidth + 1, Vec(numLogicalRegs, UInt(phyRegIdxWidth.W))))
  curr_spec_table(0) := spec_table

  for (i <- 0 until decodeWidth) {
    // Read source registers (rs1, rs2, rs3)
    // Intra-bundle bypassing: rs uses the latest mapping from previous instructions in the same bundle
    if (isFP) {
      io.readPorts(i)(0).data := curr_spec_table(i)(io.readPorts(i)(0).addr)
      io.readPorts(i)(1).data := curr_spec_table(i)(io.readPorts(i)(1).addr)
      io.readPorts(i)(2).data := curr_spec_table(i)(io.readPorts(i)(2).addr)
    } else {
      io.readPorts(i)(0).data := Mux(io.readPorts(i)(0).addr === 0.U, 0.U, curr_spec_table(i)(io.readPorts(i)(0).addr))
      io.readPorts(i)(1).data := Mux(io.readPorts(i)(1).addr === 0.U, 0.U, curr_spec_table(i)(io.readPorts(i)(1).addr))
      io.readPorts(i)(2).data := Mux(io.readPorts(i)(2).addr === 0.U, 0.U, curr_spec_table(i)(io.readPorts(i)(2).addr))
    }
    
    // Capture old pdest for rd (used for ROB commit and recovery)
    io.old_pdest(i) := curr_spec_table(i)(io.renamePorts(i).addr)
    
    // Update for next instruction in the same bundle
    curr_spec_table(i+1) := curr_spec_table(i)
    val wen = if (isFP) io.renamePorts(i).wen else io.renamePorts(i).wen && io.renamePorts(i).addr =/= 0.U
    when (wen) {
      curr_spec_table(i+1)(io.renamePorts(i).addr) := io.renamePorts(i).data
    }
  }

  snapshots.io.enq := io.snptEnq
  snapshots.io.enqData := curr_spec_table(io.snptEnqIdx)
  snapshots.io.deq := io.snptDeq
  snapshots.io.redirect := io.redirect && io.useSnapshot
  snapshots.io.flushVec := io.snptFlushVec
  
  io.snptEnqPtr := snapshots.io.enqPtr
  io.snptDeqPtr := snapshots.io.deqPtr
  io.snptValids := snapshots.io.valids

  // State Update
  when (io.redirect) {
    spec_table := Mux(io.useSnapshot, snapshots.io.snapshots(io.snptRestoreIdx), arch_table)
  } .otherwise {
    spec_table := curr_spec_table(decodeWidth)
  }

  // 2. Commit Stage (Architectural)
  for (i <- 0 until decodeWidth) {
    val wen = if (isFP) io.commitPorts(i).wen else io.commitPorts(i).wen && io.commitPorts(i).addr =/= 0.U
    when (wen) {
      arch_table(io.commitPorts(i).addr) := io.commitPorts(i).data
    }
  }
  
  io.debug_rat := spec_table
}
