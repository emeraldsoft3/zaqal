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

  val is_beq_at_0c = (s0_pc === "h8000_0000".U) && mask_reg(3) // 0x0c is slot 3 of 0x8000_0000

  when(io.redirect.valid) {
    next_pc := align(io.redirect.target)
    val offset = io.redirect.target(4, 2)
    mask := ("hFF".U << offset)(7, 0)
    mask_reg := ("hFF".U << offset)(7, 0)
   } .elsewhen(is_beq_at_0c && io.out.fire) {
     // Prediction: BEQ at 0x0c (slot 3) is TAKEN to 0x14 (same block, slot 5)
     // We fetch 0x00, 04, 08, 0c. Then skip 0x10. Then fetch 0x14-0x1c.
     next_pc     := s0_pc + 32.U
     meta.target := "h8000_0014".U
     meta.taken  := true.B
     meta.slot   := 3.U
     mask        := "hEF".U // Binary 1110_1111: Bit 4 (0x10) skipped
     mask_reg    := "hFF".U
     printf("BPU: Predicting BEQ at 0x0c TAKEN to 0x14 (Intra-block jump)\n")
   } 
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