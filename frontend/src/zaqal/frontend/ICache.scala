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
  "h0000_0013".U, // 0: NOP
  "h0000_0013".U, // 1: NOP
  
  // === Day 24: RVC Tests ===
  "h4515_0001".U, // 2: [c.li x10, 5] [c.nop]
  "h4629_15fd".U, // 3: [c.li x12, 10] [c.addi x11, -1]
  "h9732_86aa".U, // 4: [c.add x14, x14, x12] [c.mv x13, x10]
  "h6588_4581".U, // 5: [c.ld x10, 8(x11)] [c.li x11, 0]
  "hba90_4605".U, // 6: [c.sd x12, 16(x13)] [c.li x12, 1]
  
  // === Day 23: Alignment Regression ===
  "h0513_0001".U, // 7: [li x10, 5 (part 1: 0513)] [c.nop]
  "h0001_0050".U, // 8: [c.nop] [li x10, 5 (part 2: 0050)]
  
  // === Day 25: Enhanced RVC Coverage ===
  "h838d_6785".U, // 9: [c.srli x15, 2] [c.lui x15, 1]
  "ha00a_6105".U, // 10: [c.j +4 (to word 12)] [c.addi16sp 32]
  "h0000_0013".U, // 11: Jump target skip
  "hc6b8_46b8".U, // 12: [c.sw x14, 4(x13)] [c.lw x15, 4(x13)]

  "h0000_0013".U  // NOP pad
).padTo(256, "h0000_0013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


