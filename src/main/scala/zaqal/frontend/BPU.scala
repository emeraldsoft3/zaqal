package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class BPU extends Module {
  val io = IO(new Bundle {
    val redirect = Input(new BPURedirect)
    val out      = Decoupled(new FetchRequest)
  })

  val s0_pc = RegInit("h8000_0000".U(64.W))

  // Aligns any address to a 32-byte boundary (e.g., 0x0C becomes 0x00)
  def align(addr: UInt) = addr & (~0x1F.U(64.W))

  val is_loop_exit_block = (s0_pc === "h8000_0060".U) 
  val is_test_bne_block   = (s0_pc === "h8000_0020".U)

  val next_pc = Wire(UInt(64.W))
  val meta    = Wire(new PredictionMeta)
  val mask    = Wire(UInt(8.W))

  // Default: Linear flow
  meta.target := s0_pc + 32.U
  meta.taken  := false.B
  meta.slot   := 0.U
  mask        := "hFF".U

  val mask_reg = RegInit("hFF".U(8.W))

  val is_bne_at_20 = (s0_pc === "h8000_0020".U) && mask_reg(0)
  val is_loop_exit_at_6c = (s0_pc === "h8000_0060".U) && mask_reg(3)

  when(io.redirect.valid) {
    next_pc := align(io.redirect.target)
    val offset = io.redirect.target(4, 2)
    mask := ("hFF".U << offset)(7, 0)
    mask_reg := ("hFF".U << offset)(7, 0)
   } 
  //.elsewhen(is_bne_at_20 && io.out.fire) {
  //   // Prediction: BNE at 0x20 (slot 0) is TAKEN to 0x28 (slot 2)
  //   // We fetch 0x20, skip 0x24, and fetch 0x28-0x3c in this same block.
  //   next_pc     := s0_pc + 32.U
  //   meta.target := "h8000_0028".U
  //   meta.taken  := true.B
  //   meta.slot   := 0.U
  //   mask        := "hFD".U // Binary 1111_1101: Bit 1 (0x24) skipped
  //   mask_reg    := "hFF".U
  //   printf("BPU: Predicting BNE at 0x20 TAKEN to 0x28 (Intra-block jump)\n")
  // } //.elsewhen(is_loop_exit_at_6c && io.out.fire) {
    // // Prediction: Loop exit at 0x6c (slot 3) is TAKEN to 0x0c (slot 3 of block 00)
    // next_pc     := align("h8000_000c".U) // 0x8000_0000
    // meta.target := "h8000_0000".U
    // meta.taken  := true.B
    // meta.slot   := 3.U // Instruction at 0x6c
    // mask        := "h0F".U // Only 0x60, 64, 68, 6c valid in this packet
    // mask_reg    := ("hFF".U << 3)(7, 0) // Next packet starts at slot 3 (0x0c)
    // printf("BPU: Predicting Loop Exit at 0x6c TAKEN to 0x0c\n")
 // } 
  .elsewhen(io.out.fire) {
    next_pc := s0_pc + 32.U
    mask    := mask_reg
    mask_reg := "hFF".U // Reset after use
  } .otherwise {
    next_pc := s0_pc
    mask    := mask_reg
  }

  s0_pc := next_pc

  io.out.valid := !reset.asBool
  io.out.bits.pc         := s0_pc
  io.out.bits.mask       := mask
  io.out.bits.prediction := meta
  io.out.bits.ftqPtr     := 0.U // Initialized as dummy, FTQ will overwrite
}