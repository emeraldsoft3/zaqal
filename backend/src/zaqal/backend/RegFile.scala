package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class RegFile(val numReadPorts: Int = 7, val numWritePorts: Int = 5)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val raddr = Vec(numReadPorts, Input(UInt(phyRegIdxWidth.W)))
    val rdata = Vec(numReadPorts, Output(UInt(xLen.W)))
    
    val wen   = Vec(numWritePorts, Input(Bool()))
    val waddr = Vec(numWritePorts, Input(UInt(phyRegIdxWidth.W)))
    val wdata = Vec(numWritePorts, Input(UInt(xLen.W)))

    val debug_regs = Output(Vec(phyRegs, UInt(xLen.W)))
  })

  val regs = RegInit(VecInit(Seq.fill(phyRegs)(0.U(xLen.W))))
  io.debug_regs := regs

  for (i <- 0 until numReadPorts) {
    io.rdata(i) := Mux(io.raddr(i) === 0.U, 0.U, regs(io.raddr(i)))
  }

  for (i <- 0 until numWritePorts) {
    when(io.wen(i) && io.waddr(i) =/= 0.U) {
      regs(io.waddr(i)) := io.wdata(i)
    }
  }
}
