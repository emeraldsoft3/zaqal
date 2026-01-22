package zaqal.frontend

import zaqal._
import chisel3._
import chisel3.util._

// This is the "Meta Information" the documentation mentions
class BPUResult extends Bundle {
  val pc        = UInt(64.W)
  val target    = UInt(64.W)
  val taken     = Bool()
  // Meta information for predictors (TAGE, RAS, etc.) - empty for now
}

class BPURedirect extends Bundle {
  val target = UInt(64.W)
  val valid  = Bool()
}

class BPU extends Module {
  val io = IO(new Bundle {
    val redirect = Input(new BPURedirect)
    val out      = Decoupled(new BPUResult) // Output to FTQ
  })

  // Stage s0: PC Generation
  val s0_pc = RegInit("h8000_0000".U(64.W))

  // Basic prediction: For now, always predict "Not Taken" (Next PC = PC + 32)
  val s0_next_pc = s0_pc + 32.U

  // Handling the Redirect (The "Misprediction Recovery" from your doc)
  when(io.redirect.valid) {
    s0_pc := io.redirect.target
  } .elsewhen(io.out.fire) {
    s0_pc := s0_next_pc
  }

  // Prediction Block output
  io.out.valid      := true.B // BPU is always trying to predict
  io.out.bits.pc    := s0_pc
  io.out.bits.target:= s0_next_pc
  io.out.bits.taken := false.B
}