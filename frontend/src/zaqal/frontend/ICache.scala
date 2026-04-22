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
  "h80000537".U, // 0x00: lui x10, 0x80000
  "h02250513".U, // 0x04: addi x10, x10, 0x22 (x10 = 0x80000022)
  "h000500e7".U, // 0x08: jalr x1, 0(x10) -> Jump to 0x80000022
  "h00000013".U, // 0x0C: nop
  "h00000013".U, // 0x10: nop
  "h00000013".U, // 0x14: nop
  "h00000013".U, // 0x18: nop
  "h00000013".U, // 0x1C: nop
  "h00010001".U, // 0x20: c.nop; c.nop (Valid RVC target at 0x22)
  "h00100613".U, // 0x24: li x12, 1 (Success Path)
  "h0000006f".U, // 0x28: j 0x28 (Halt Success)
  "h00000013".U, // 0x2C: nop
  "h00000013".U, // 0x2C: nop
  "h00000013".U, // 0x30: nop
  "h00000013".U, // 0x34: nop
  "h00000013".U, // 0x38: nop
  "h00000013".U  // 0x3C: nop
).padTo(64, "h00000013".U) ++ Seq(
  "h0ee00693".U, // 0x100 (Index 64): li x13, 0xEE (Trap Path)
  "h0000006f".U  // 0x104: j 0x104 (Halt Trap)
).padTo(128, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(11, 2) // Expanded to 11 bits (4KB range)

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


