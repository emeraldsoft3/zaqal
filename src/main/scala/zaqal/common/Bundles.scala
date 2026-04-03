package zaqal.common

import chisel3._
import chisel3.util._

class CtrlBundle(implicit p: ZaqalParams) extends Bundle {
  val rfWen = Bool()
  val aluOp = UInt(4.W)
  val bruOp = UInt(4.W)
  val immSel = UInt(3.W)
  val op1Sel = UInt(2.W)
  val op2Sel = UInt(2.W)
}

class DataBundle(implicit p: ZaqalParams) extends Bundle {
  val src1 = UInt(p.xLen.W)
  val src2 = UInt(p.xLen.W)
  val imm = UInt(p.xLen.W)
}

class MicroOp(implicit p: ZaqalParams) extends Bundle {
  val pc = UInt(p.xLen.W)
  val instr = UInt(32.W)
  
  val ctrl = new CtrlBundle
  val data = new DataBundle

  val pdst = UInt(6.W)
  val psrc1 = UInt(6.W)
  val psrc2 = UInt(6.W)
  val ldst = UInt(5.W)
  val lsrc1 = UInt(5.W)
  val lsrc2 = UInt(5.W)
  
  val taken = Bool()
  val mispredict = Bool()
  val robIdx = UInt(6.W)
  val exception = Bool()
}

class FetchPacket(implicit p: ZaqalParams) extends Bundle {
  val instrs = Vec(p.nFetchInstrs, UInt(32.W))
  val pc = UInt(p.xLen.W)
  val mask = UInt(p.nFetchInstrs.W)
  val pred_target = UInt(p.xLen.W)
  val pred_taken = Bool()
  val pred_slot = UInt(log2Up(p.nFetchInstrs).W)
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
