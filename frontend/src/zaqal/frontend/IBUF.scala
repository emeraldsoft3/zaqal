package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class IBUF(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val inst_data = Flipped(Decoupled(new FetchPacket)) // From IFU
    val flush     = Input(Bool())
    val out       = Decoupled(new MicroOp)              // To Backend
  })

  val inst_idx = RegInit(0.U(log2Up(predictWidth).W))
  val current_packet = Reg(new FetchPacket)
  val busy = RegInit(false.B)

  val residual_valid = RegInit(false.B)
  val residual_inst  = RegInit(0.U(16.W))
  val residual_pc    = RegInit(0.U(xLen.W))
  val residual_pre   = Reg(new PreDecodeSignals)
  val residual_ftq   = RegInit(0.U(ftqPtrWidth.W))
  val residual_epoch = RegInit(false.B)

  val is_rvc = current_packet.pre_decoded(inst_idx).is_rvc
  val step = Mux(is_rvc, 1.U, 2.U)
  
  val is_cross_line = (inst_idx === (predictWidth - 1).U) && !is_rvc && current_packet.mask(inst_idx)

  val next_idx = inst_idx +& step
  val valid_bits_mask = (Fill(predictWidth, 1.U(1.W)) << next_idx)(predictWidth - 1, 0)
  val remaining_mask = current_packet.mask & valid_bits_mask
  val has_next_inst  = remaining_mask.orR
  val next_inst_idx  = PriorityEncoder(remaining_mask)

  val will_finish_packet = (io.out.fire || (busy && is_cross_line)) && !has_next_inst

  val accept_new_packet  = (!busy || will_finish_packet) && io.inst_data.valid && !io.flush

  io.inst_data.ready := !busy || will_finish_packet

  when(io.flush) {
    busy := false.B
    residual_valid := false.B
    printf("IBUF FLUSHED!\n")
  } .elsewhen(accept_new_packet) {
    busy           := true.B
    // If we are accepting a new packet while a residual is valid, we merge them.
    // The current instruction (stitched) will use residual_inst and current_packet.instructions(0).
    // We should only clear residual_valid AFTER the combined instruction fires.
    
    // However, if we were NOT in a residual state, but we detected a cross-line in the PREVIOUS packet,
    // we should have set residual_valid then.
    
    // Let's use a simpler state: If we are BUSY and see a cross-line, we must save and wait.
    current_packet := io.inst_data.bits
    
    // If we just accepted a NEW packet and we have a residual bits saved,
    // the first instruction to fire is at index 0 (the merged one).
    // If not, it's the priority encoder of the new mask.
    inst_idx := Mux(residual_valid, 0.U, PriorityEncoder(io.inst_data.bits.mask))
    printf(p"IBUF ACCEPT: pc=${Hexadecimal(io.inst_data.bits.pc)} mask=${Binary(io.inst_data.bits.mask)} epoch=${io.inst_data.bits.epoch}\n")
  } .elsewhen(io.out.fire) {
    printf(p"IBUF FIRE: pc=${Hexadecimal(io.out.bits.pc)} inst=${Hexadecimal(io.out.bits.inst_raw)} next_idx=${next_idx}\n")
    when(residual_valid) {
      residual_valid := false.B
      // After firing a stitched instruction, we move to the rest of the current packet starting from index 1.
      val mask_after_resid = current_packet.mask & (~((1.U << 1) - 1.U)).asUInt
      when(mask_after_resid.orR) {
        val next_valid_idx = PriorityEncoder(mask_after_resid)
        inst_idx := next_valid_idx
      } .otherwise {
        busy := false.B
      }
    } .elsewhen(has_next_inst) {
      inst_idx := next_inst_idx
    } .otherwise {
      busy := false.B
    }
  } 
  
  // Transition to residual state: occurs when we are busy, at the last slot, 
  // and it's a 32-bit instruction (not expanded RVC).
  when(busy && is_cross_line && !residual_valid && !io.flush) {
    residual_valid := true.B
    residual_inst  := current_packet.instructions(inst_idx)(15, 0)
    residual_pc    := current_packet.pc + (inst_idx << 1)
    residual_pre   := current_packet.pre_decoded(inst_idx)
    residual_ftq   := current_packet.ftqPtr 
    residual_epoch := current_packet.epoch
    busy           := false.B // Stop processing current packet
  }

  // An instruction is valid to fire if:
  // 1. We have a residual instruction AND a new packet has arrived (busy=true).
  // 2. We are busy and NOT at a cross-line boundary.
  io.out.valid      := busy && (residual_valid || (current_packet.mask(inst_idx) && !is_cross_line))
  
  io.out.bits.inst_raw := Mux(residual_valid, 
                              Cat(current_packet.instructions(0)(15, 0), residual_inst), 
                              Mux(is_rvc, current_packet.pre_decoded(inst_idx).expanded_inst, 
                                          current_packet.instructions(inst_idx)))
                              
  io.out.bits.pre      := Mux(residual_valid, residual_pre, current_packet.pre_decoded(inst_idx))
  io.out.bits.pc       := Mux(residual_valid, residual_pc, current_packet.pc + (inst_idx << 1))
  io.out.bits.ftqPtr   := Mux(residual_valid, residual_ftq, current_packet.ftqPtr)
  
  val is_pred_taken_normal = current_packet.prediction.taken && (inst_idx === current_packet.prediction.slot)
  io.out.bits.is_predicted_taken := Mux(residual_valid, false.B, is_pred_taken_normal)
  
  io.out.bits.epoch    := Mux(residual_valid, residual_epoch, current_packet.epoch)
  
}
