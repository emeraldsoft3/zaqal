package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class BPU extends Module {
  val io = IO(new Bundle {
    val redirect = Input(new BPURedirect)
    val out      = Decoupled(new FetchPacket)
  })

  val s0_pc = RegInit("h8000_0000".U(64.W))

  // Aligns any address to a 32-byte boundary (e.g., 0x0C becomes 0x00)
  def align(addr: UInt) = addr & (~0x1F.U(64.W))

  val is_loop_exit_block = (s0_pc === "h8000_0060".U) 

  val next_pc = Wire(UInt(64.W))
  val meta    = Wire(new PredictionMeta)
  val mask    = Wire(UInt(8.W))

  // Default: Linear flow
  meta.target := s0_pc + 32.U
  meta.taken  := false.B
  meta.slot   := 0.U
  mask        := "hFF".U

  when(io.redirect.valid) {
    next_pc := align(io.redirect.target)
    // Create mask based on target offset (e.g., if target is 0x0C, mask ignores first 3 instructions)
    val offset = io.redirect.target(4, 2)
    mask := ("hFF".U << offset)(7, 0)
  } .elsewhen(is_loop_exit_block && io.out.fire) {
    // PREDICTION: Jump from 0x6C back to 0x0C
    next_pc     := align("h8000_0000".U) // Go to the 0x00 block
    meta.target := "h8000_000c".U
    meta.taken  := true.B
    meta.slot   := 3.U                   // 0x6C is the 4th instruction (index 3)
    mask        := "h0F".U               // Only instructions 0, 1, 2, 3 in this block are valid
  } .elsewhen(io.out.fire) {
    next_pc := s0_pc + 32.U
  } .otherwise {
    next_pc := s0_pc
  }

  s0_pc := next_pc

  io.out.valid := !reset.asBool
  io.out.bits.pc         := s0_pc
  io.out.bits.mask       := mask
  io.out.bits.prediction := meta
  io.out.bits.instructions := VecInit(Seq.fill(8)(0.U(32.W)))
  io.out.bits.ftqPtr       := 0.U
  for (i <- 0 until 8) {
    io.out.bits.pre_decoded(i).is_rvc := false.B
    io.out.bits.pre_decoded(i).is_cfi := false.B
  }
}