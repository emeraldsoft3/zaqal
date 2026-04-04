package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class RegFile(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val rs1_addr = Input(UInt(log2Up(logicalRegs).W))
    val rs1_data = Output(UInt(xLen.W))
    val rs2_addr = Input(UInt(log2Up(logicalRegs).W))
    val rs2_data = Output(UInt(xLen.W))
    
    val wen      = Input(Bool())
    val rd_addr  = Input(UInt(log2Up(logicalRegs).W))
    val rd_data  = Input(UInt(xLen.W))
  })

  val regs = RegInit(VecInit(Seq.fill(logicalRegs)(0.U(xLen.W))))

  // x0 is hardwired to 0
  io.rs1_data := Mux(io.rs1_addr === 0.U, 0.U, regs(io.rs1_addr))
  io.rs2_data := Mux(io.rs2_addr === 0.U, 0.U, regs(io.rs2_addr))

  // Inside RegFile.scala
  when(io.wen && io.rd_addr =/= 0.U) { // ONLY write if destination is NOT x0
    regs(io.rd_addr) := io.rd_data
  }
}
