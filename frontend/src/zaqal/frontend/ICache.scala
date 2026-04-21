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
  "h0000_0013".U, // Index 0 (0x00): NOP
  "h4585_4515".U, // Index 1 (0x04): [c.li x11, 1 (4585)] [c.li x10, 5 (4515)]
  "h0585_952e".U, // Index 2 (0x08): [c.addi x11, 1 (0585)] [c.add x10, x11 (952e)]
  "h0001_a011".U, // Index 3 (0x0C): [c.nop (0001)] [c.j +4 (a011)]
  "h0000_0013".U, // Index 4 (0x10): NOP (Skipped by jump)
  "h00a5_0613".U, // Index 5 (0x14): [addi x12, x10, 10] -> 32-bit (x10=5, x11=2, so x12=16)
  "h0000_0013".U, // Index 6 (0x18): NOP
  
  // Cross-line test at end of Cache Line (Index 7 & 8 = Byte 28-35)
  "h0513_0001".U, // Index 7 (0x1C): [li x10, 5 (Low: 0513 - Part 1)] [c.nop]
  "h0001_0050".U, // Index 8 (0x20): [c.nop] [li x10, 5 (High: 0050 - Part 2)]
  
  "ha001_0001".U, // Index 9 (0x24): [c.nop] [c.j 0 (a001 - Halt Loop)]
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


