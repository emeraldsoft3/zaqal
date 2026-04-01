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

  def align(addr: UInt) = addr & (~0x1F.U(64.W))

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
    mask     := ("hFF".U << offset)(7, 0)
    mask_reg := ("hFF".U << offset)(7, 0)
  } .elsewhen(io.out.fire) {

    next_pc := Mux(meta.taken, align(meta.target), s0_pc + 32.U)
    
    val target_is_same_block = align(meta.target) === s0_pc
    val next_mask = Mux(meta.taken && target_is_same_block,
                        ("hFF".U << meta.target(4,2))(7,0),
                        "hFF".U)
    mask     := mask_reg
    mask_reg := next_mask
  } .otherwise {
    next_pc := s0_pc
    mask    := mask_reg
  }

  s0_pc := next_pc

  io.out.valid := !reset.asBool
  io.out.bits.pc         := s0_pc
  
  // Truncate mask if a branch is TAKEN within this packet
  // If slot N is taken, mask should only include bits 0 to N.
  val taken_mask = (Fill(8, 1.U) >> (7.U - meta.slot))(7,0)
  io.out.bits.mask       := Mux(meta.taken, mask & taken_mask, mask)
  
  io.out.bits.prediction := meta
  io.out.bits.ftqPtr     := 0.U 
  io.out.bits.epoch      := false.B
}