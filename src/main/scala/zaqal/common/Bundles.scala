package zaqal.common

import chisel3._
import chisel3.util._

class MicroOp(implicit p: ZaqalParams) extends Bundle {
  val pc = UInt(p.xLen.W)
  val instr = UInt(32.W)
  val pdst = UInt(6.W)
  val psrc1 = UInt(6.W)
  val psrc2 = UInt(6.W)
  val ldst = UInt(5.W)
  val lsrc1 = UInt(5.W)
  val lsrc2 = UInt(5.W)
  val brType = UInt(4.W)
  val opType = UInt(5.W)
  val imm = UInt(p.xLen.W)
  val rs1Val = UInt(p.xLen.W)
  val rs2Val = UInt(p.xLen.W)
  val resVal = UInt(p.xLen.W)
  val taken = Bool()
  val mispredict = Bool()
  val robIdx = UInt(6.W)
  val exception = Bool()
}

class FetchPacket(implicit p: ZaqalParams) extends Bundle {
  val instrs = Vec(p.nFetchInstrs, UInt(32.W))
  val pc = UInt(p.xLen.W)
  val mask = UInt(p.nFetchInstrs.W)
}

class BranchPredictionBus(implicit p: ZaqalParams) extends Bundle {
  val pc = UInt(p.xLen.W)
  val target = UInt(p.xLen.W)
  val taken = Bool()
}

class PipelineFlushBus(implicit p: ZaqalParams) extends Bundle {
  val flush = Bool()
  val targetPC = UInt(p.xLen.W)
}
