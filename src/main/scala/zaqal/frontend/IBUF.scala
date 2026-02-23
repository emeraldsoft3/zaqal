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
  // Lookahead to see if next instruction is valid according to mask
  val next_inst_valid = (inst_idx < 7.U) && current_packet.mask(inst_idx + 1.U)
  val will_finish_packet = io.out.fire && !next_inst_valid

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
    when(next_inst_valid) {
      inst_idx := inst_idx + 1.U
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
}