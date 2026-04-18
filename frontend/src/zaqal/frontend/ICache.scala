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
  "h00000013".U, // 0: NOP
  "h00000013".U, // 1: NOP
  
  // === Day 24: RVC Tests ===
  // Word 2: c.nop (0x0001) | c.li a0, 5 (0x4515)
  "h4515_0001".U, // 2: [a0=5] [nop]
  // Word 3: c.addi a1, -1 (0x15fd) | c.li a2, 10 (0x4629)
  "h4629_15fd".U, // 3: [a2=10] [a1=a1-1]
  
  // Word 4: c.mv a3, a0 (0x86aa) | c.add a4, a2 (0x9732)
  "h9732_86aa".U, // 4: [a4=a4+a2] [a3=a0]

  // Word 5: c.ld a0, 8(a1) (0x6588) | c.li a1, 0 (0x4581)
  "h6588_4581".U, // 5: [a0=ld 8(a1)] [a1=0]
  
  // Word 6: c.sd a2, 16(a3) (0xba90) | c.addi a2, 1 (0x4605)
  "hba90_4605".U, // 6: [sd a2, 16(a3)] [a2=a2+1]
  
  // === Day 23: Alignment Regression ===
  // Packet 0 Ends here!
  // At word 7, we place: lower 16 bits of 32-bit inst (0x0513) in upper half, c.nop (0x0001) in lower half
  "h0513_0001".U, // 7: [li a0, 5 (part 1)] [c.nop]
  // Packet 1 Begins here!
  // At word 8, we place: upper 16 bits of 32-bit inst (0x0050) in lower half, NOP in upper half
  "h0001_0050".U, // 8: [c.nop] [li a0, 5 (part 2)]
  
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


