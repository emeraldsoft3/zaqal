package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class BPU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val redirect = Input(new BPURedirect)
    val out      = Decoupled(new FetchRequest)
  })

  val s0_pc    = RegInit("h8000_0000".U(xLen.W))
  val mask_reg = RegInit(Fill(predictWidth, 1.U(1.W)))
  val epoch    = RegInit(false.B) // Current Fetch Epoch

  // Instantiate the Fetch Target Buffer (FTB)
  val ftb = Module(new FTB)
  ftb.io.req_pc := s0_pc

  // FTB Update Path from resolved branches
  ftb.io.update_valid  := io.redirect.valid && !io.redirect.is_exception
  ftb.io.update_pc     := io.redirect.pc
  ftb.io.update_target := io.redirect.target
  ftb.io.update_taken  := io.redirect.taken
  ftb.io.update_is_cfi := io.redirect.is_cfi
  ftb.io.update_is_jalr:= io.redirect.is_jalr

  def align(addr: UInt) = addr & (~((fetchWidth * 4) - 1).U(xLen.W))

  val meta    = Wire(new PredictionMeta)
  meta.target := Mux(ftb.io.taken, ftb.io.target, s0_pc + (fetchWidth * 4).U)
  meta.taken  := ftb.io.taken
  meta.slot   := ftb.io.slot

  val current_mask = Wire(UInt(predictWidth.W))
  
  // Logic: Only accept a redirect if the redirect is valid
  val is_new_redirect = io.redirect.valid

  when(is_new_redirect) {
    s0_pc    := align(io.redirect.target)
    val redirect_mask = (Fill(predictWidth, 1.U(1.W)) << io.redirect.target(log2Up(fetchWidth * 4) - 1, 1))(predictWidth - 1, 0)
    mask_reg     := redirect_mask
    current_mask := redirect_mask
    epoch        := ~epoch // Sync with Backend's new color
    printf(p"BPU REDIRECT ACCEPTED: target=${Hexadecimal(io.redirect.target)} epoch=$epoch\n")
  } .elsewhen(io.out.fire) {
    s0_pc := Mux(meta.taken, align(meta.target), s0_pc + (fetchWidth * 4).U)
    
    val target_is_same_block = align(meta.target) === s0_pc
    val next_mask = Mux(meta.taken && target_is_same_block,
                        (Fill(predictWidth, 1.U(1.W)) << meta.target(log2Up(fetchWidth * 4) - 1, 1))(predictWidth - 1, 0),
                        Fill(predictWidth, 1.U(1.W)))
    mask_reg     := next_mask
    current_mask := mask_reg
  } .otherwise {
    current_mask := mask_reg
  }

  io.out.valid := !reset.asBool
  io.out.bits.pc         := s0_pc
  
  val mask_limit = Mux(meta.slot === (predictWidth - 1).U, (predictWidth - 1).U, meta.slot + 1.U)
  val taken_mask = (Fill(predictWidth, 1.U) >> ((predictWidth - 1).U - mask_limit))(predictWidth - 1, 0)
  io.out.bits.mask       := Mux(meta.taken, current_mask & taken_mask, current_mask)
  
  io.out.bits.prediction := meta
  io.out.bits.ftqPtr     := 0.U 
  io.out.bits.epoch      := epoch // Tag every instruction with the current Color

  when(io.out.fire && meta.taken) {
    printf(p"[BPU FTB PREDICT] pc=${Hexadecimal(s0_pc)} -> target=${Hexadecimal(meta.target)} slot=${meta.slot}\n")
  }
}
