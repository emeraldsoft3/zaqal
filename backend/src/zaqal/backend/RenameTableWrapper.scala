package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class RenameTableWrapper(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val dec = Vec(decodeWidth, Input(new DecodeSignals))
    val renamePorts = Vec(decodeWidth, Input(new RatWritePort)) // Logical addr + Physical data
    val commitPorts = Vec(decodeWidth, Input(new RatWritePort)) // Note: Needs rd_is_fp flag eventually
    val commit_is_fp = Vec(decodeWidth, Input(Bool()))         // Temporary flag for commit
    val redirect = Input(Bool())
    
    // Outputs to Backend/Dispatch
    val psrs1 = Vec(decodeWidth, Output(UInt(phyRegIdxWidth.W)))
    val psrs2 = Vec(decodeWidth, Output(UInt(phyRegIdxWidth.W)))
    val psrs3 = Vec(decodeWidth, Output(UInt(phyRegIdxWidth.W)))
    val old_pdest = Vec(decodeWidth, Output(UInt(phyRegIdxWidth.W)))
    
    // Debug
    val debug_int_rat = Output(Vec(32, UInt(phyRegIdxWidth.W)))
    val debug_fp_rat  = Output(Vec(32, UInt(phyRegIdxWidth.W)))
  })

  val intRat = Module(new RenameTable(32, isFP = false))
  val fpRat  = Module(new RenameTable(32, isFP = true))

  intRat.io.redirect := io.redirect
  fpRat.io.redirect  := io.redirect

  for (i <- 0 until decodeWidth) {
    // 1. Route Read Ports based on DecodeSignals
    intRat.io.readPorts(i)(0).addr := io.dec(i).rs1
    intRat.io.readPorts(i)(1).addr := io.dec(i).rs2
    intRat.io.readPorts(i)(2).addr := io.dec(i).rs3

    fpRat.io.readPorts(i)(0).addr := io.dec(i).rs1
    fpRat.io.readPorts(i)(1).addr := io.dec(i).rs2
    fpRat.io.readPorts(i)(2).addr := io.dec(i).rs3

    io.psrs1(i) := Mux(io.dec(i).rs1_is_fp, fpRat.io.readPorts(i)(0).data, intRat.io.readPorts(i)(0).data)
    io.psrs2(i) := Mux(io.dec(i).rs2_is_fp, fpRat.io.readPorts(i)(1).data, intRat.io.readPorts(i)(1).data)
    io.psrs3(i) := Mux(io.dec(i).rs3_is_fp, fpRat.io.readPorts(i)(2).data, intRat.io.readPorts(i)(2).data)

    // 2. Route Rename Ports (Speculative Update)
    intRat.io.renamePorts(i).wen  := io.renamePorts(i).wen && !io.dec(i).rd_is_fp
    intRat.io.renamePorts(i).addr := io.renamePorts(i).addr
    intRat.io.renamePorts(i).data := io.renamePorts(i).data

    fpRat.io.renamePorts(i).wen   := io.renamePorts(i).wen && io.dec(i).rd_is_fp
    fpRat.io.renamePorts(i).addr  := io.renamePorts(i).addr
    fpRat.io.renamePorts(i).data  := io.renamePorts(i).data

    io.old_pdest(i) := Mux(io.dec(i).rd_is_fp, fpRat.io.old_pdest(i), intRat.io.old_pdest(i))

    // 3. Route Commit Ports (Architectural Update)
    intRat.io.commitPorts(i).wen  := io.commitPorts(i).wen && !io.commit_is_fp(i)
    intRat.io.commitPorts(i).addr := io.commitPorts(i).addr
    intRat.io.commitPorts(i).data := io.commitPorts(i).data

    fpRat.io.commitPorts(i).wen   := io.commitPorts(i).wen && io.commit_is_fp(i)
    fpRat.io.commitPorts(i).addr  := io.commitPorts(i).addr
    fpRat.io.commitPorts(i).data  := io.commitPorts(i).data
  }

  io.debug_int_rat := intRat.io.debug_rat
  io.debug_fp_rat  := fpRat.io.debug_rat
}
