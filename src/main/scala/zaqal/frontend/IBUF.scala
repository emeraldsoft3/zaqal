package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class IBUF extends Module {
  val io = IO(new Bundle {
    val inst_data = Flipped(Decoupled(new FetchPacket)) // From IFU
    val flush     = Input(Bool())
    val out       = Decoupled(new MicroOp)              // To Backend
  })

  val inst_idx = RegInit(0.U(3.W))
  val current_packet = Reg(new FetchPacket)
  val busy = RegInit(false.B)

  // Logic to step through the instructions in a packet
  // Lookahead: Find the next valid instruction index in the current mask after the current index
  val remaining_mask = current_packet.mask & ("hFE".U << inst_idx)(7, 0)
  val has_next_inst  = remaining_mask.orR // has next inst is 1 if remaining mask is 0, but if there is any value, it will be 1
  val next_inst_idx  = PriorityEncoder(remaining_mask) //0 for 11111111 , 1 for 11111110, 2 for 11111100

  val will_finish_packet = io.out.fire && !has_next_inst

  // Seamless Switching: Allow accepting a new packet if we are idle OR finishing the current one
  val accept_new_packet  = (!busy || will_finish_packet) && io.inst_data.valid && !io.flush

  io.inst_data.ready := !busy || will_finish_packet
  
  when(io.flush) {
    busy := false.B
  } .elsewhen(accept_new_packet) {
    current_packet := io.inst_data.bits
    busy           := true.B
    // Start at the first bit set in the mask (usually 0, but can be >0 for branch targets)
    inst_idx       := PriorityEncoder(io.inst_data.bits.mask)
  } .elsewhen(io.out.fire) {
    when(has_next_inst) {
      inst_idx := next_inst_idx
    } .otherwise {
      busy := false.B
    }
  }

  // Dispatch logic (Kunminghu Alignment: Dispatch raw instructions + hints)
  // Ensure we only dispatch if the current instruction is valid in the mask
  io.out.valid      := busy && current_packet.mask(inst_idx)
  io.out.bits.inst_raw := current_packet.instructions(inst_idx)
  io.out.bits.pre      := current_packet.pre_decoded(inst_idx)
  io.out.bits.pc       := current_packet.pc + (inst_idx << 2)
  io.out.bits.ftqPtr   := current_packet.ftqPtr
  io.out.bits.is_predicted_taken := current_packet.prediction.taken && (inst_idx === current_packet.prediction.slot)
}