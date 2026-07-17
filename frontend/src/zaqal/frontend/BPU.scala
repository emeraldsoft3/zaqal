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
    val redirect = Input(new BPURedirect)
    val out      = Decoupled(new FetchRequest)
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
  // FTB Update
  ftb.io.update_valid  := io.redirect.valid && !io.redirect.is_exception
  ftb.io.update_pc     := io.redirect.pc
  ftb.io.update_target := io.redirect.target
  ftb.io.update_taken  := io.redirect.taken
  ftb.io.update_is_cfi := io.redirect.is_cfi
  ftb.io.update_is_jalr:= io.redirect.is_jalr

  val aligned_update_pc = io.redirect.pc & (~31.U(xLen.W))

  // TAGE Update
  tage.io.update_valid := io.redirect.valid && !io.redirect.is_exception && io.redirect.is_cfi && !io.redirect.is_jalr
  tage.io.update_pc    := aligned_update_pc
  tage.io.update_ghr   := redirect_meta.ghr
  tage.io.update_dir   := io.redirect.taken
  tage.io.providerIdx  := redirect_meta.tage_providerIdx
  tage.io.providerHit  := redirect_meta.tage_providerHit
  tage.io.providerCtr  := redirect_meta.tage_providerCtr
  tage.io.altTaken     := redirect_meta.tage_altTaken
  tage.io.providerU    := redirect_meta.tage_providerU

  // ITTAGE Update — uses snapshotted PHR from the retire packet
  ittage.io.update_valid  := io.redirect.valid && !io.redirect.is_exception && io.redirect.is_cfi && io.redirect.is_jalr
  ittage.io.update_pc     := aligned_update_pc
  ittage.io.update_phr    := redirect_meta.phr  // PHR at the time this JALR was fetched
  ittage.io.update_target := io.redirect.target
  ittage.io.providerIdx   := redirect_meta.ittage_providerIdx
  ittage.io.providerHit   := redirect_meta.ittage_providerHit
  ittage.io.altTarget     := redirect_meta.ittage_altTarget
  ittage.io.providerU     := redirect_meta.ittage_providerU

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
    
    val target_is_same_block = align(meta.target) === s0_pc
    val next_mask = Mux(meta.taken && target_is_same_block,
                        (Fill(predictWidth, 1.U(1.W)) << meta.target(log2Up(fetchWidth * 4) - 1, 1))(predictWidth - 1, 0),
                        Fill(predictWidth, 1.U(1.W)))
    mask_reg     := next_mask
    current_mask := mask_reg
  } .otherwise {
    current_mask := mask_reg
  }

  // --- GHR UPDATE AND ROLLBACK ---
  val restored_ghr = Mux(io.redirect.is_cfi, Cat(redirect_meta.ghr(126, 0), io.redirect.taken), redirect_meta.ghr)
  val spec_shift_val = Mux(ftb.io.br_type === 0.U, final_taken, 1.B)
  val has_spec_cfi = ftb.io.hit && (ftb.io.br_type === 0.U || ftb.io.br_type === 1.U || ftb.io.br_type === 2.U) && current_mask(ftb.io.slot)

  when(io.redirect.valid) {
    ghr := restored_ghr
  } .elsewhen(io.out.fire && has_spec_cfi) {
    ghr := Cat(ghr(126, 0), spec_shift_val)
  }

  // --- PHR UPDATE AND ROLLBACK ---
  // PHR is shifted on every taken JALR (indirect jump): shift in target[7:2] (6 bits)
  val is_spec_jalr = ftb.io.hit && ftb.io.br_type === 2.U && current_mask(ftb.io.slot) && final_taken
  val restored_phr = Cat(redirect_meta.phr(25, 0), io.redirect.target(7, 2))

  when(io.redirect.valid && io.redirect.is_jalr) {
    phr := restored_phr
  } .elsewhen(io.out.fire && is_spec_jalr) {
    phr := Cat(phr(25, 0), final_target(7, 2))
  }

  // --- METADATA ENQUEUE LOGIC ---
  when(io.out.fire) {
    val new_meta = Wire(new BPUMetaEntry)
    new_meta.ghr                := ghr
    new_meta.phr                := phr   // Snapshot current PHR
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
