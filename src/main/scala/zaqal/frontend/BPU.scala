package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class BPU extends Module {
  val io = IO(new Bundle {
    val redirect = Input(new BPURedirect)
    val out      = Decoupled(new FetchRequest)
  })

  val s0_pc = RegInit("h8000_0000".U(64.W))

  // Aligns any address to a 32-byte boundary (e.g., 0x0C becomes 0x00)
  def align(addr: UInt) = addr & (~0x1F.U(64.W))

  val is_loop_exit_block = (s0_pc === "h8000_0060".U) 

  val next_pc = Wire(UInt(64.W))
  val meta    = Wire(new PredictionMeta)
  val mask    = Wire(UInt(8.W))

  // Default: Linear flow
  meta.target := s0_pc + 32.U
  meta.taken  := false.B
  meta.slot   := 0.U
  mask        := "hFF".U

  val mask_reg = RegInit("hFF".U(8.W))

  when(io.redirect.valid) {
    next_pc := align(io.redirect.target)
    val offset = io.redirect.target(4, 2)
    mask := ("hFF".U << offset)(7, 0)
    mask_reg := ("hFF".U << offset)(7, 0)
  } .elsewhen(is_loop_exit_block && io.out.fire) {
    next_pc     := align("h8000_0000".U)
    meta.target := "h8000_000c".U
    meta.taken  := true.B
    meta.slot   := 3.U
    mask        := "h0F".U
    mask_reg    := "hFF".U // Reset for next block
  } .elsewhen(io.out.fire) {
    next_pc := s0_pc + 32.U
    mask    := mask_reg
    mask_reg := "hFF".U // Reset after use
  } .otherwise {
    next_pc := s0_pc
    mask    := mask_reg
  }

  s0_pc := next_pc

  io.out.valid := !reset.asBool
  io.out.bits.pc         := s0_pc
  io.out.bits.mask       := mask
  io.out.bits.prediction := meta
  io.out.bits.ftqPtr     := 0.U // Initialized as dummy, FTQ will overwrite
}