package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class RAS(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val push_valid    = Input(Bool())
    val push_addr     = Input(UInt(xLen.W))
    val pop_valid     = Input(Bool())
    val pop_addr      = Output(UInt(xLen.W))
    val pop_valid_out = Output(Bool())
    val sp            = Output(UInt(log2Up(rasEntries).W))
    val restore_en    = Input(Bool())
    val restore_sp    = Input(UInt(log2Up(rasEntries).W))
  })

  val stack = RegInit(VecInit(Seq.fill(rasEntries)(0.U(xLen.W))))
  val sp    = RegInit(0.U(log2Up(rasEntries).W))

  when(io.restore_en) {
    sp := io.restore_sp
  } .elsewhen(io.push_valid && !io.pop_valid) {
    stack(sp) := io.push_addr
    sp := sp + 1.U
  } .elsewhen(io.pop_valid && !io.push_valid) {
    sp := sp - 1.U
  } .elsewhen(io.push_valid && io.pop_valid) {
    // Simultaneous push & pop (e.g. co-call / tail call replacement)
    stack(sp - 1.U) := io.push_addr
  }

  val top_idx = Mux(sp === 0.U, (rasEntries - 1).U, sp - 1.U)
  io.pop_addr      := stack(top_idx)
  io.pop_valid_out := sp > 0.U
  io.sp            := sp
}
