package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.common._

class Predecoder(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val inst = Input(UInt(instBits.W))
    val out  = Output(new PreDecodeSignals)
  })

  // RVC Expander instantiation (XiangShan Parity)
  val rvc_expander = Module(new RVCExpander)
  rvc_expander.io.inst := io.inst(15, 0)
  
  val is_rvc = rvc_expander.io.is_rvc
  io.out.is_rvc := is_rvc

  val expanded = Mux(is_rvc, rvc_expander.io.out, io.inst)
  io.out.expanded_inst := expanded

  // Simple Control Flow Instruction (CFI) check for RISC-V
  // Use expanded instruction for CFI check to support compressed branches/jumps in future
  val opcode = expanded(6, 0)
  io.out.is_cfi := (opcode === "b1101111".U) || (opcode === "b1100111".U) || (opcode === "b1100011".U)
}
