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

  // Control Flow Instruction (CFI) check for RISC-V
  val opcode = expanded(6, 0)
  val rd     = expanded(11, 7)
  val rs1    = expanded(19, 15)

  val is_jal  = opcode === "b1101111".U
  val is_jalr = opcode === "b1100111".U
  val is_br   = opcode === "b1100011".U

  io.out.is_cfi := is_jal || is_jalr || is_br

  // RISC-V Calling Convention Link Registers: x1 (ra) and x5 (t0)
  val rd_link  = (rd === 1.U) || (rd === 5.U)
  val rs1_link = (rs1 === 1.U) || (rs1 === 5.U)

  io.out.is_call := (is_jal || is_jalr) && rd_link
  io.out.is_ret  := is_jalr && rs1_link && (rd =/= rs1)
}
