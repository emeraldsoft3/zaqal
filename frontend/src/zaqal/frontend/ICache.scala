package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class ICache(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val pc = Input(UInt(xLen.W))
    val insts = Output(Vec(fetchWidth, UInt(instBits.W)))
    val ready = Output(Bool())
  })


val program = VecInit(Seq(
  // === Day 23: Alignment Test ===
  // We want to force a 32-bit instruction to split across the packet boundary.
  // A packet is 8x 32-bit words (256 bits). 
  // Let's put a "c.nop" (0x0001) in the lower 16 bits of program(7).
  // Then the lower 16 bits of a 32-bit 'li a0, 5' (0x00500513) in the upper 16 bits of program(7).
  // Then the upper 16 bits of 'li a0, 5' in the lower 16 bits of program(8).

  "h00000013".U, // 0
  "h00000013".U, // 1
  "h00000013".U, // 2
  "h00000013".U, // 3
  "h00000013".U, // 4
  "h00000013".U, // 5
  "h00000013".U, // 6
  // Packet 0 Ends here!
  // At word 7, we place: lower 16 bits of 32-bit inst (0x0513) in upper half, c.nop (0x0001) in lower half
  "h0513_0001".U, // 7
  // Packet 1 Begins here!
  // At word 8, we place: upper 16 bits of 32-bit inst (0x0050) in lower half, NOP in upper half
  "h0001_0050".U, // 8
  
  "h00000013".U  // NOP pad
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


