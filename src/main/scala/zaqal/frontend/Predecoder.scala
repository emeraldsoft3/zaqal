package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal.PreDecodeSignals

class Predecoder extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val out  = Output(new PreDecodeSignals)
  })

  // RISC-V Compressed (RVC) check: last two bits are not 11
  io.out.is_rvc := io.inst(1, 0) =/= "b11".U

  // Simple Control Flow Instruction (CFI) check for RISC-V
  // JAL (1101111), JALR (1100111), BRANCH (1100011)
  val opcode = io.inst(6, 0)
  io.out.is_cfi := (opcode === "b1101111".U) || (opcode === "b1100111".U) || (opcode === "b1100011".U)
}
