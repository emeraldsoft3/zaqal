package zaqal.backend.fu

import chisel3._
import chisel3.util._
import zaqal.DecodeSignals

class ALU extends Module {
  val io = IO(new Bundle {
    val src1   = Input(UInt(64.W))
    val src2   = Input(UInt(64.W))
    val pc     = Input(UInt(64.W))
    val dec    = Input(new DecodeSignals)
    val result = Output(UInt(64.W))
  })

  // 1. Sub-Modules
  val adder      = Module(new Adder)
  val logical    = Module(new Logical)
  val shifter    = Module(new Shifter)
  val comparator = Module(new Comparator)

  // 2. Wiring
  adder.io.src1    := io.src1
  adder.io.src2    := io.src2
  adder.io.is_sub  := io.dec.is_sub || io.dec.is_subw
  adder.io.is_word := io.dec.is_addw || io.dec.is_subw || io.dec.is_addiw

  logical.io.src1   := io.src1
  logical.io.src2   := io.src2
  logical.io.is_and := io.dec.is_and || io.dec.is_andi
  logical.io.is_or  := io.dec.is_or  || io.dec.is_ori
  logical.io.is_xor := io.dec.is_xor || io.dec.is_xori

  shifter.io.src1   := io.src1
  shifter.io.shamt  := io.src2(5, 0)
  shifter.io.is_sll  := io.dec.is_sll || io.dec.is_slli
  shifter.io.is_srl  := io.dec.is_srl || io.dec.is_srli
  shifter.io.is_sra  := io.dec.is_sra || io.dec.is_srai
  shifter.io.is_sllw := io.dec.is_sllw || io.dec.is_slliw
  shifter.io.is_srlw := io.dec.is_srlw || io.dec.is_srliw
  shifter.io.is_sraw := io.dec.is_sraw || io.dec.is_sraiw

  comparator.io.src1    := io.src1
  comparator.io.src2    := io.src2
  comparator.io.is_slt  := io.dec.is_slt || io.dec.is_slti
  comparator.io.is_sltu := io.dec.is_sltu || io.dec.is_sltiu

  // 3. Result Selection
  io.result := MuxCase(0.U, Seq(
    (io.dec.is_add || io.dec.is_addi || io.dec.is_sub || 
     io.dec.is_addw || io.dec.is_subw || io.dec.is_addiw) -> adder.io.result,
    (io.dec.is_auipc) -> (io.pc + io.src2), // Direct PC + Imm
    (io.dec.is_lui)   -> io.src2,           // Direct Imm
    (io.dec.is_and || io.dec.is_andi || 
     io.dec.is_or  || io.dec.is_ori  || 
     io.dec.is_xor || io.dec.is_xori) -> logical.io.result,
    (io.dec.is_sll || io.dec.is_srl || io.dec.is_sra ||
     io.dec.is_slli || io.dec.is_srli || io.dec.is_srai ||
     io.dec.is_sllw || io.dec.is_srlw || io.dec.is_sraw ||
     io.dec.is_slliw || io.dec.is_srliw || io.dec.is_sraiw) -> shifter.io.result,
    (io.dec.is_slt || io.dec.is_sltu || io.dec.is_slti || io.dec.is_sltiu) -> comparator.io.result
  ))
}
