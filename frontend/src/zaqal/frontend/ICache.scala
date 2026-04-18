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
  // Word 2: c.nop (0x0001) | c.li x10, 5 (0x4515)
  "h4515_0001".U, // 2: [x10=5] [nop]
  // Word 3: c.addi x11, -1 (0x15fd) | c.li x12, 10 (0x4629)
  "h4629_15fd".U, // 3: [x12=10] [x11=x11-1]
  
  // Word 4: c.mv x13, x10 (0x86aa) | c.add x14, x12 (0x9732)
  "h9732_86aa".U, // 4: [x14=x14+x12] [x13=x10]

  // Word 5: c.ld x10, 8(x11) (0x6588) | c.li x11, 0 (0x4581)
  "h6588_4581".U, // 5: [x10=ld 8(x11)] [x11=0]
  
  // Word 6: c.sd x12, 16(x13) (0xba90) | c.addi x12, 1 (0x4605)
  "hba90_4605".U, // 6: [sd x12, 16(x13)] [x12=x12+1]
  
  // === Day 23: Alignment Regression ===
  // Packet 0 Ends here!
  // At word 7, we place: lower 16 bits of 32-bit inst (0x0513) in upper half, c.nop (0x0001) in lower half
  "h0513_0001".U, // 7: [li x10, 5 (part 1)] [c.nop]
  // Packet 1 Begins here!
  // At word 8, we place: upper 16 bits of 32-bit inst (0x0050) in lower half, NOP in upper half
  "h0001_0050".U, // 8: [c.nop] [li x10, 5 (part 2)]
  
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


