package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FPRegFile(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val rs1_addr = Input(UInt(phyRegIdxWidth.W))
    val rs1_data = Output(UInt(fLen.W))
    val rs2_addr = Input(UInt(phyRegIdxWidth.W))
    val rs2_data = Output(UInt(fLen.W))
    val rs3_addr = Input(UInt(phyRegIdxWidth.W))
    val rs3_data = Output(UInt(fLen.W))
    
    val wen      = Input(Bool())
    val rd_addr  = Input(UInt(phyRegIdxWidth.W))
    val rd_data  = Input(UInt(fLen.W))

    val debug_regs = Output(Vec(phyRegs, UInt(fLen.W)))
  })

  // In a renamed architecture, FPRegFile stores physical registers
  val regs = RegInit(VecInit(Seq.fill(phyRegs)(0.U(fLen.W))))
  
  io.rs1_data := regs(io.rs1_addr)
  io.rs2_data := regs(io.rs2_addr)
  io.rs3_data := regs(io.rs3_addr)

  when(io.wen) {
    regs(io.rd_addr) := io.rd_data
  }

  io.debug_regs := regs
}
