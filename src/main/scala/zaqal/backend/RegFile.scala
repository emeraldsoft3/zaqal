package zaqal.backend

import chisel3._
import zaqal._

class RegFile extends Module {
  val io = IO(new Bundle {
    val rs1_addr = Input(UInt(5.W))
    val rs1_data = Output(UInt(64.W))
    val rs2_addr = Input(UInt(5.W))
    val rs2_data = Output(UInt(64.W))
    
    val wen      = Input(Bool())
    val rd_addr  = Input(UInt(5.W))
    val rd_data  = Input(UInt(64.W))
  })

  val regs = RegInit(VecInit(Seq.fill(32)(0.U(64.W))))

  // x0 is hardwired to 0
  io.rs1_data := Mux(io.rs1_addr === 0.U, 0.U, regs(io.rs1_addr))
  io.rs2_data := Mux(io.rs2_addr === 0.U, 0.U, regs(io.rs2_addr))

  // Inside RegFile.scala
  when(io.wen && io.rd_addr =/= 0.U) { // ONLY write if destination is NOT x0
    regs(io.rd_addr) := io.rd_data
  }
}