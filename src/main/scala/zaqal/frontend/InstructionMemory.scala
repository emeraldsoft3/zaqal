package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class InstructionMemory extends Module {
  val io = IO(new Bundle {
    val req  = Flipped(Decoupled(UInt(64.W)))
    val resp = Decoupled(new FetchPacket)
  })

  // Hardcode the heartbeat.hex into a ROM
  val rom = VecInit(Seq(
    "h00100093".U, // addi x1, x0, 1
    "h00a00113".U, // addi x2, x0, 10
    "h00108093".U, // addi x1, x1, 1
    "hff9ff06f".U  // jal x0, loop
  ).padTo(8, 0.U)) // Pad to 8 instructions to match our width

  val s1_valid = RegNext(io.req.fire, false.B)
  val s1_pc    = RegNext(io.req.bits)

  io.resp.valid             := s1_valid
  io.resp.bits.pc           := s1_pc
  io.resp.bits.instructions := rom // Directly use the ROM
  io.resp.bits.mask         := "b11111111".U    //mask, If a jump happens in the middle of a block (e.g., at the 3rd instruction), the mask might become 00000111 to tell the CPU to ignore the instructions after the jump.
  io.resp.bits.prediction.target       := 0.U
  io.resp.bits.prediction.taken        := false.B
  io.resp.bits.prediction.slot         := 0.U
  
  io.req.ready := true.B
}