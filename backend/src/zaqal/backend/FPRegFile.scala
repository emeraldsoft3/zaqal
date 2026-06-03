package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FPRegFile(val numReadPorts: Int = 4, val numWritePorts: Int = 3)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val raddr = Vec(numReadPorts, Input(UInt(phyRegIdxWidth.W)))
    val rdata = Vec(numReadPorts, Output(UInt(fLen.W)))
    
    val wen   = Vec(numWritePorts, Input(Bool()))
    val waddr = Vec(numWritePorts, Input(UInt(phyRegIdxWidth.W)))
    val wdata = Vec(numWritePorts, Input(UInt(fLen.W)))

    val debug_regs = Output(Vec(phyRegs, UInt(fLen.W)))
  })

  val regs = RegInit(VecInit(Seq.fill(phyRegs)(0.U(fLen.W))))
  
  for (i <- 0 until numReadPorts) {
    io.rdata(i) := regs(io.raddr(i))
  }

  for (i <- 0 until numWritePorts) {
    when(io.wen(i)) {
      regs(io.waddr(i)) := io.wdata(i)
    }
  }

  io.debug_regs := regs
}
