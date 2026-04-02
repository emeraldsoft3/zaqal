package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._

class BPU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val redirect = Input(new BPURedirect)
    val out      = Decoupled(new FetchRequest)
  })

  val s0_pc = RegInit("h8000_0000".U(xLen.W))

  def align(addr: UInt) = addr & (~((fetchWidth * 4) - 1).U(xLen.W))

  val next_pc = Wire(UInt(xLen.W))
  val meta    = Wire(new PredictionMeta)
  val mask    = Wire(UInt(fetchWidth.W))

  // Default: Linear flow
  meta.target := s0_pc + (fetchWidth * 4).U
  meta.taken  := false.B
  meta.slot   := 0.U
  mask        := Fill(fetchWidth, 1.U(1.W))

  val mask_reg = RegInit(Fill(fetchWidth, 1.U(1.W)))

  when(io.redirect.valid) {
    next_pc := align(io.redirect.target)
    val offset = io.redirect.target(log2Up(fetchWidth * 4) - 1, 2)
    mask     := (Fill(fetchWidth, 1.U(1.W)) << offset)(fetchWidth - 1, 0)
    mask_reg := (Fill(fetchWidth, 1.U(1.W)) << offset)(fetchWidth - 1, 0)
  } .elsewhen(io.out.fire) {

    next_pc := Mux(meta.taken, align(meta.target), s0_pc + (fetchWidth * 4).U)
    
    val target_is_same_block = align(meta.target) === s0_pc
    val next_mask = Mux(meta.taken && target_is_same_block,
                        (Fill(fetchWidth, 1.U(1.W)) << meta.target(log2Up(fetchWidth * 4) - 1, 2))(fetchWidth - 1, 0),
                        Fill(fetchWidth, 1.U(1.W)))
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
  val taken_mask = (Fill(fetchWidth, 1.U) >> ( (fetchWidth - 1).U - meta.slot))(fetchWidth - 1, 0)
  io.out.bits.mask       := Mux(meta.taken, mask & taken_mask, mask)
  
  io.out.bits.prediction := meta
  io.out.bits.ftqPtr     := 0.U 
  io.out.bits.epoch      := false.B
}