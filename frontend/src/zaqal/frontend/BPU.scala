package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

// Bundle to hold branch prediction metadata at fetch time
class BPUMetaEntry(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val ghr = UInt(128.W)
  val phr = UInt(32.W)   // Path History Register (for ITTAGE)
  val ghr_spec_shifted = Bool() // Tracks if GHR was speculatively shifted at fetch time (FTB hit)
  // TAGE Metadata
  val tage_providerIdx = UInt(2.W)
  val tage_providerHit = Bool()
  val tage_providerCtr = UInt(3.W)
  val tage_altTaken = Bool()
  val tage_providerU = UInt(2.W)
  // ITTAGE Metadata
  val ittage_providerIdx = UInt(2.W)
  val ittage_providerHit = Bool()
  val ittage_altTarget = UInt(xLen.W)
  val ittage_providerU = UInt(2.W)
}

class BPU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val redirect   = Input(new BPURedirect)
    val bpu_update = Input(new BPUUpdate)
    val out        = Decoupled(new FetchRequest)
  })

  val s0_pc    = RegInit("h8000_0000".U(xLen.W))
  val mask_reg = RegInit(Fill(predictWidth, 1.U(1.W)))
  val epoch    = RegInit(false.B) // Current Fetch Epoch

  // Global History Register (GHR) — for TAGE (branch directions)
  val ghr = RegInit(0.U(128.W))

  // Path History Register (PHR) — for ITTAGE (indirect jump target PCs)
  // 32-bit register; on each taken JALR we shift in target(7, 2) (6 bits)
  val phr = RegInit(0.U(32.W))

  // Instantiate sub-predictors
  val ftb = Module(new FTB)
  val tage = Module(new TagePredictor)
  val ittage = Module(new ITTagePredictor)

  // BPU Shadow Pointer to track FTQ occupancy/index
  val bpu_enq_ptr = RegInit(0.U(ftqPtrWidth.W))
  when(io.redirect.valid) {
    bpu_enq_ptr := 0.U
  } .elsewhen(io.out.fire) {
    bpu_enq_ptr := bpu_enq_ptr + 1.U
  }

  // Circular storage for prediction metadata
  val meta_storage = Reg(Vec(ftqEntries, new BPUMetaEntry))
  val redirect_meta = meta_storage(io.redirect.ftqPtr)

  // --- LOOKUP PATH ---
  ftb.io.req_pc := s0_pc

  tage.io.req_pc  := s0_pc
  tage.io.req_ghr := ghr

  ittage.io.req_pc  := s0_pc
  ittage.io.req_phr := phr  // PHR feeds ITTAGE, not GHR

  // Override FTB's conditional branch direction with TAGE
  val final_taken = Mux(ftb.io.hit && ftb.io.br_type === 0.U, tage.io.pred.taken, ftb.io.taken)
  
  // Override FTB's indirect jump target with ITTAGE
  val final_target = Mux(ftb.io.hit && ftb.io.br_type === 2.U && ittage.io.pred.hit, ittage.io.pred.target, ftb.io.target)

  // --- UPDATE / TRAINING PATH ---
  val bpu_update_valid = io.redirect.valid || io.bpu_update.valid
  val bpu_update_pc    = Mux(io.redirect.valid, io.redirect.pc, io.bpu_update.pc)
  val bpu_update_target= Mux(io.redirect.valid, io.redirect.target, io.bpu_update.target)
  val bpu_update_taken = Mux(io.redirect.valid, io.redirect.taken, io.bpu_update.taken)
  val bpu_update_is_cfi= Mux(io.redirect.valid, io.redirect.is_cfi, io.bpu_update.is_cfi)
  val bpu_update_is_jal= Mux(io.redirect.valid, io.redirect.is_jal, io.bpu_update.is_jal)
  val bpu_update_is_jalr= Mux(io.redirect.valid, io.redirect.is_jalr, io.bpu_update.is_jalr)
  val bpu_update_ftqPtr= Mux(io.redirect.valid, io.redirect.ftqPtr, io.bpu_update.ftqPtr)
  val bpu_update_meta  = meta_storage(bpu_update_ftqPtr)

  // FTB Update
  ftb.io.update_valid  := bpu_update_valid && !(io.redirect.valid && io.redirect.is_exception)
  ftb.io.update_pc     := bpu_update_pc
  ftb.io.update_target := bpu_update_target
  ftb.io.update_taken  := bpu_update_taken
  ftb.io.update_is_cfi := bpu_update_is_cfi
  ftb.io.update_is_jal := bpu_update_is_jal
  ftb.io.update_is_jalr:= bpu_update_is_jalr

  val aligned_update_pc = bpu_update_pc & (~31.U(xLen.W))

  // TAGE Update: strictly for conditional branches (not JAL, not JALR)
  tage.io.update_valid := bpu_update_valid && !(io.redirect.valid && io.redirect.is_exception) && bpu_update_is_cfi && !bpu_update_is_jal && !bpu_update_is_jalr
  tage.io.update_pc    := aligned_update_pc
  tage.io.update_ghr   := bpu_update_meta.ghr
  tage.io.update_dir   := bpu_update_taken
  tage.io.providerIdx  := bpu_update_meta.tage_providerIdx
  tage.io.providerHit  := bpu_update_meta.tage_providerHit
  tage.io.providerCtr  := bpu_update_meta.tage_providerCtr
  tage.io.altTaken     := bpu_update_meta.tage_altTaken
  tage.io.providerU    := bpu_update_meta.tage_providerU

  // ITTAGE Update — uses snapshotted PHR from the retire packet
  ittage.io.update_valid  := bpu_update_valid && !(io.redirect.valid && io.redirect.is_exception) && bpu_update_is_cfi && bpu_update_is_jalr
  ittage.io.update_pc     := aligned_update_pc
  ittage.io.update_phr    := bpu_update_meta.phr  // PHR at the time this JALR was fetched
  ittage.io.update_target := bpu_update_target
  ittage.io.providerIdx   := bpu_update_meta.ittage_providerIdx
  ittage.io.providerHit   := bpu_update_meta.ittage_providerHit
  ittage.io.altTarget     := bpu_update_meta.ittage_altTarget
  ittage.io.providerU     := bpu_update_meta.ittage_providerU

  // --- FRONTEND CONTROL FLOW LOGIC ---
  def align(addr: UInt) = addr & (~((fetchWidth * 4) - 1).U(xLen.W))

  val current_mask = Wire(UInt(predictWidth.W))
  val is_new_redirect = io.redirect.valid

  val meta    = Wire(new PredictionMeta)
  meta.target := Mux(final_taken, final_target, s0_pc + (fetchWidth * 4).U)
  meta.taken  := final_taken && current_mask(ftb.io.slot)
  meta.slot   := ftb.io.slot

  when(is_new_redirect) {
    s0_pc    := align(io.redirect.target)
    val redirect_mask = (Fill(predictWidth, 1.U(1.W)) << io.redirect.target(log2Up(fetchWidth * 4) - 1, 1))(predictWidth - 1, 0)
    mask_reg     := redirect_mask
    current_mask := redirect_mask
    epoch        := ~epoch // Sync with Backend's new color
    printf(p"BPU REDIRECT ACCEPTED: target=${Hexadecimal(io.redirect.target)} epoch=$epoch\n")
  } .elsewhen(io.out.fire) {
    s0_pc := Mux(meta.taken, align(meta.target), s0_pc + (fetchWidth * 4).U)
    
    val next_mask = Mux(meta.taken,
                        (Fill(predictWidth, 1.U(1.W)) << meta.target(log2Up(fetchWidth * 4) - 1, 1))(predictWidth - 1, 0),
                        Fill(predictWidth, 1.U(1.W)))
    mask_reg     := next_mask
    current_mask := mask_reg
  } .otherwise {
    current_mask := mask_reg
  }

  // --- GHR UPDATE AND ROLLBACK (Strictly for Conditional Branches) ---
  val is_cond_redirect   = io.redirect.is_cfi && !io.redirect.is_jal && !io.redirect.is_jalr
  val restored_ghr       = Mux(is_cond_redirect, Cat(redirect_meta.ghr(126, 0), io.redirect.taken), redirect_meta.ghr)
  val spec_shift_val     = final_taken
  val has_spec_cond_br   = ftb.io.hit && current_mask(ftb.io.slot) && (ftb.io.br_type === 0.U)
  val do_non_spec_shift = io.bpu_update.valid && bpu_update_is_cfi && !bpu_update_is_jal && !bpu_update_is_jalr && !bpu_update_meta.ghr_spec_shifted && !io.redirect.valid

  when(io.redirect.valid) {
    ghr := restored_ghr
    printf(p"[BPU GHR RESTORE] ghr=${Hexadecimal(restored_ghr)} redirect_pc=${Hexadecimal(io.redirect.pc)} target=${Hexadecimal(io.redirect.target)}\n")
  } .elsewhen(do_non_spec_shift) {
    val non_spec_ghr = Cat(ghr(126, 0), bpu_update_taken)
    ghr := non_spec_ghr
    printf(p"[BPU GHR NON-SPEC SHIFT] ghr=${Hexadecimal(non_spec_ghr)} pc=${Hexadecimal(bpu_update_pc)} val=$bpu_update_taken\n")
  } .elsewhen(io.out.fire && has_spec_cond_br) {
    ghr := Cat(ghr(126, 0), spec_shift_val)
    printf(p"[BPU GHR SPEC SHIFT] ghr=${Hexadecimal(Cat(ghr(126, 0), spec_shift_val))} s0_pc=${Hexadecimal(s0_pc)} val=$spec_shift_val\n")
  }

  // --- PHR UPDATE AND ROLLBACK ---
  // PHR is shifted on every taken JALR (indirect jump): shift in target[7:2] (6 bits)
  // On ANY redirect, restore the snapshotted PHR (or update it if the redirect was a JALR)
  val is_spec_jalr = ftb.io.hit && ftb.io.br_type === 2.U && current_mask(ftb.io.slot) && final_taken
  val restored_phr = Mux(io.redirect.is_cfi && io.redirect.is_jalr,
                         Cat(redirect_meta.phr(25, 0), io.redirect.target(7, 2)),
                         redirect_meta.phr)

  when(io.redirect.valid) {
    phr := restored_phr
  } .elsewhen(io.out.fire && is_spec_jalr) {
    phr := Cat(phr(25, 0), final_target(7, 2))
  }

  // --- METADATA ENQUEUE AND IN-FLIGHT GHR PROPAGATION LOGIC ---
  // If an FTB-miss branch resolves non-speculatively, update in-flight metadata snapshots for instructions fetched after it
  when(do_non_spec_shift) {
    for (i <- 0 until ftqEntries) {
      val ptr = i.U(ftqPtrWidth.W)
      val start_ptr = bpu_update_ftqPtr + 1.U
      val end_ptr = bpu_enq_ptr
      val in_flight = Mux(start_ptr <= end_ptr,
                        (ptr >= start_ptr) && (ptr < end_ptr),
                        (ptr >= start_ptr) || (ptr < end_ptr))

      when(in_flight) {
        meta_storage(i).ghr := Cat(meta_storage(i).ghr(126, 0), bpu_update_taken)
      }
    }
  }

  when(io.out.fire) {
    val new_meta = Wire(new BPUMetaEntry)
    new_meta.ghr                := Mux(do_non_spec_shift, Cat(ghr(126, 0), bpu_update_taken), ghr)
    new_meta.phr                := phr   // Snapshot current PHR
    new_meta.ghr_spec_shifted   := has_spec_cond_br
    new_meta.tage_providerIdx   := tage.io.pred.providerIdx
    new_meta.tage_providerHit   := tage.io.pred.hit
    new_meta.tage_providerCtr   := tage.io.pred.providerCtr
    new_meta.tage_altTaken      := tage.io.pred.altTaken
    new_meta.tage_providerU     := tage.io.pred.providerU

    new_meta.ittage_providerIdx := ittage.io.pred.providerIdx
    new_meta.ittage_providerHit := ittage.io.pred.hit
    new_meta.ittage_altTarget   := ittage.io.pred.altTarget
    new_meta.ittage_providerU   := ittage.io.pred.providerU

    meta_storage(bpu_enq_ptr)   := new_meta
  }

  io.out.valid := !reset.asBool
  io.out.bits.pc         := s0_pc
  
  val mask_limit = Mux(meta.slot === (predictWidth - 1).U, (predictWidth - 1).U, meta.slot + 1.U)
  val taken_mask = (Fill(predictWidth, 1.U) >> ((predictWidth - 1).U - mask_limit))(predictWidth - 1, 0)
  io.out.bits.mask       := Mux(meta.taken, current_mask & taken_mask, current_mask)
  
  io.out.bits.prediction := meta
  io.out.bits.ftqPtr     := bpu_enq_ptr 
  io.out.bits.epoch      := epoch

  when(io.out.fire && meta.taken) {
    printf(p"[BPU PREDICT] pc=${Hexadecimal(s0_pc)} -> target=${Hexadecimal(meta.target)} slot=${meta.slot}\n")
  }
}
