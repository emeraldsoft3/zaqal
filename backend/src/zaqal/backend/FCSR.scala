package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FCSR(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Interface for CSR instructions
    val csr_addr = Input(UInt(12.W))
    val csr_wen  = Input(Bool())
    val csr_wdata = Input(UInt(xLen.W))
    val csr_rdata = Output(UInt(xLen.W))

    // Interface for FP units
    val frm      = Output(UInt(3.W))
    val set_flags = Input(Bool())
    val flags_to_set = Input(UInt(5.W))
  })

  val frm = RegInit(0.U(3.W))
  val fflags = RegInit(0.U(5.W))

  // Reading logic
  io.csr_rdata := Mux(io.csr_addr === "h001".U, fflags,
                  Mux(io.csr_addr === "h002".U, frm,
                  Mux(io.csr_addr === "h003".U, Cat(frm, fflags), 0.U)))

  // Writing logic from CSR instructions
  when(io.csr_wen) {
    when(io.csr_addr === "h001".U) {
      fflags := io.csr_wdata(4, 0)
    } .elsewhen(io.csr_addr === "h002".U) {
      frm := io.csr_wdata(2, 0)
    } .elsewhen(io.csr_addr === "h003".U) {
      frm := io.csr_wdata(7, 5)
      fflags := io.csr_wdata(4, 0)
    }
  }

  // Writing logic from FP units (accumulative)
  when(io.set_flags) {
    fflags := fflags | io.flags_to_set
  }

  io.frm := frm
}
