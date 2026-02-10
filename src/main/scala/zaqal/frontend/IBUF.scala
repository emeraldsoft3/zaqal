package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class IBUF extends Module {
  val io = IO(new Bundle {
    val inst_data = Flipped(Decoupled(new FetchPacket)) // From IFU
    val out       = Decoupled(new MicroOp)              // To Backend
  })

  val inst_idx = RegInit(0.U(3.W))
  val current_packet = Reg(new FetchPacket)
  val busy = RegInit(false.B)

  val predecoder = Module(new Predecoder)
  
  // Logic to step through the 8 instructions in a packet
  io.inst_data.ready := !busy
  
  when(!busy && io.inst_data.valid) {
    current_packet := io.inst_data.bits
    busy := true.B
    inst_idx := 0.U
  }

  predecoder.io.inst := current_packet.instructions(inst_idx)

  // Dispatch logic (Kunminghu Alignment: Dispatch raw instructions + hints)
  io.out.valid      := busy
  io.out.bits.inst_raw := current_packet.instructions(inst_idx)
  io.out.bits.pre      := predecoder.io.out
  io.out.bits.pc       := current_packet.pc + (inst_idx << 2)

  when(io.out.fire) {
    inst_idx := inst_idx + 1.U
    when(inst_idx === 7.U) {
      busy := false.B
    }
  }
}