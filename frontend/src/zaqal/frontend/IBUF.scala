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

  val valid_bits_mask = (Fill(predictWidth, 1.U(1.W)) << (inst_idx + step))(predictWidth - 1, 0)
  val remaining_mask = current_packet.mask & valid_bits_mask
  val has_next_inst  = remaining_mask.orR
  val next_inst_idx  = PriorityEncoder(remaining_mask)

  val will_finish_packet = (io.out.fire || (busy && is_cross_line && !residual_valid)) && !has_next_inst

  val accept_new_packet  = (!busy || will_finish_packet) && io.inst_data.valid && !io.flush

  io.inst_data.ready := !busy || will_finish_packet

  when(io.flush) {
    busy := false.B
    residual_valid := false.B
  } .elsewhen(accept_new_packet) {
    current_packet := io.inst_data.bits
    busy           := true.B
    inst_idx       := PriorityEncoder(io.inst_data.bits.mask)
  } .elsewhen(io.out.fire) {
    when(residual_valid) {
      residual_valid := false.B
      val mask_after_resid = current_packet.mask & (Fill(predictWidth, 1.U(1.W)) << 1.U)(predictWidth - 1, 0)
      when(mask_after_resid.orR) {
        inst_idx := PriorityEncoder(mask_after_resid)
      } .otherwise {
        busy := false.B
      }
    } .elsewhen(has_next_inst) {
      inst_idx := next_inst_idx
    } .otherwise {
      busy := false.B
    }
  } .elsewhen(busy && is_cross_line) {
    residual_valid := true.B
    residual_inst  := current_packet.instructions(inst_idx)(15, 0)
    residual_pc    := current_packet.pc + (inst_idx << 1)
    residual_pre   := current_packet.pre_decoded(inst_idx)
    residual_ftq   := current_packet.ftqPtr 
    residual_epoch := current_packet.epoch
    busy           := false.B
  }

  io.out.valid      := (busy && current_packet.mask(inst_idx) && !is_cross_line && !residual_valid) || (busy && residual_valid)
  
  io.out.bits.inst_raw := Mux(residual_valid, 
                              Cat(current_packet.instructions(0)(15, 0), residual_inst), 
                              current_packet.instructions(inst_idx))
                              
  io.out.bits.pre      := Mux(residual_valid, residual_pre, current_packet.pre_decoded(inst_idx))
  io.out.bits.pc       := Mux(residual_valid, residual_pc, current_packet.pc + (inst_idx << 1))
  io.out.bits.ftqPtr   := Mux(residual_valid, residual_ftq, current_packet.ftqPtr)
  
  val is_pred_taken_normal = current_packet.prediction.taken && (inst_idx === current_packet.prediction.slot)
  io.out.bits.is_predicted_taken := Mux(residual_valid, false.B, is_pred_taken_normal)
  
  io.out.bits.epoch    := Mux(residual_valid, residual_epoch, current_packet.epoch)
}
