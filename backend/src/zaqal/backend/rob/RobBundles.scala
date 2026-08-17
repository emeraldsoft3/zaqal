package zaqal.backend.rob

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters

object RobBundles {
  class ExuOutput(implicit p: Parameters) extends Bundle {
    val robIdx = UInt(log2Up(128).W) // robSize
    val data = UInt(64.W) // xLen
    val exceptionVec = UInt(16.W)
  }

  class RobCommitIO(implicit p: Parameters) extends Bundle {
    val commitValid = Vec(6, Output(Bool())) // decodeWidth
    val info = Vec(6, Output(new RobCommitEntryBundle))
  }

  class RobEntryBundle(implicit p: Parameters) extends Bundle {
    val vls = Bool()
    val interrupt_safe = Bool()
    val fpWen = Bool()
    val rfWen = Bool()
    val wflags = Bool()
    val isRVC = Bool()
    val valid = Bool()
    val fflags = UInt(5.W)
    val mmio = Bool()
    val stdWritebacked = Bool()
    val needFlush = Bool()
    val exceptionVec = UInt(16.W)
  }

  class RobCommitEntryBundle(implicit p: Parameters) extends Bundle {
    val walk_v = Bool()
    val commit_v = Bool()
    val commit_w = Bool()
    val interrupt_safe = Bool()
    val rfWen = Bool()
    val fpWen = Bool()
    val needFlush = Bool()
  }
}
