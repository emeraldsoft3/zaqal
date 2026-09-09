package zaqal.backend.lsu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class LoadQueueEntry(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val valid        = Bool()
  val executed     = Bool()
  val robIdx       = UInt(log2Up(128).W)
  val snapshotIdx  = UInt(log2Up(renameSnapshotNum).W)
  val paddr        = UInt(xLen.W)
  val mask         = UInt(16.W)
  val pc           = UInt(xLen.W)
}

class LoadQueue(val numEntries: Int = 16)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // 1. Allocation Interface (from Dispatch)
    val enq = Vec(decodeWidth, Flipped(Decoupled(new Bundle {
      val robIdx      = UInt(log2Up(128).W)
      val snapshotIdx = UInt(log2Up(renameSnapshotNum).W)
      val pc          = UInt(xLen.W)
    })))
    val count       = Output(UInt((log2Up(numEntries) + 1).W))

    // 2. Execution Update (from Load AGU in Execute stage)
    val exec_update = Input(new Bundle {
      val valid   = Bool()
      val robIdx  = UInt(log2Up(128).W)
      val paddr   = UInt(xLen.W)
      val mask    = UInt(16.W)
      val pc      = UInt(xLen.W)
    })

    // 3. Store Execution Snoop Interface (Memory Violation Detection)
    val store_snoop = Input(new Bundle {
      val valid   = Bool()
      val robIdx  = UInt(log2Up(128).W)
      val paddr   = UInt(xLen.W)
      val mask    = UInt(16.W)
      val pc      = UInt(xLen.W)
    })

    // 4. Memory Ordering Violation Alert
    val violation = Output(new Bundle {
      val valid       = Bool()
      val loadRobIdx  = UInt(log2Up(128).W)
      val snapshotIdx = UInt(log2Up(renameSnapshotNum).W)
      val loadPC      = UInt(xLen.W)
      val storePC     = UInt(xLen.W)
    })

    // 5. Commit Interface (from ROB)
    val commit = Input(new Bundle {
      val valid   = Vec(decodeWidth, Bool())
      val robIdx  = Vec(decodeWidth, UInt(log2Up(128).W))
    })

    // 6. Branch Mispredict / Exception Redirect
    val redirect = Input(new Bundle {
      val valid        = Bool()
      val is_exception = Bool()
      val snapshotIdx  = UInt(log2Up(renameSnapshotNum).W)
      val robIdx       = UInt(log2Up(128).W)
    })

    val robHeadPtr   = Input(UInt(log2Up(128).W))
    val snptDeqPtr   = Input(UInt(log2Up(renameSnapshotNum).W))
  })

  val entries = RegInit(VecInit(Seq.fill(numEntries)({
    val e = Wire(new LoadQueueEntry)
    e.valid        := false.B
    e.executed     := false.B
    e.robIdx       := 0.U
    e.snapshotIdx  := 0.U
    e.paddr        := 0.U
    e.mask         := 0.U
    e.pc           := 0.U
    e
  })))

  val enqPtr = RegInit(0.U(log2Up(numEntries).W))

  val currentCount = PopCount(entries.map(_.valid))
  io.count := currentCount

  def isYoungerThanSnpt(snpt: UInt, restoreSnpt: UInt, deqPtr: UInt): Bool = {
    def circDist(ptr: UInt): UInt = Mux(ptr >= deqPtr, ptr - deqPtr, ptr + renameSnapshotNum.U - deqPtr)
    circDist(snpt) > circDist(restoreSnpt)
  }

  def isYoungerInRob(idxA: UInt, idxB: UInt, head: UInt): Bool = {
    val distA = Mux(idxA >= head, idxA - head, idxA + 128.U - head)
    val distB = Mux(idxB >= head, idxB - head, idxB + 128.U - head)
    distA > distB
  }

  // 1. Allocation (Dispatch)
  val canEnq = (numEntries.U - currentCount) >= decodeWidth.U
  val enqFires = io.enq.map(_.fire)

  for (i <- 0 until decodeWidth) {
    io.enq(i).ready := canEnq
    val allocOffset = if (i == 0) 0.U else PopCount(enqFires.take(i))
    val targetPtr = enqPtr + allocOffset

    when(io.enq(i).fire) {
      entries(targetPtr).valid       := true.B
      entries(targetPtr).executed    := false.B
      entries(targetPtr).robIdx      := io.enq(i).bits.robIdx
      entries(targetPtr).snapshotIdx := io.enq(i).bits.snapshotIdx
      entries(targetPtr).paddr       := 0.U
      entries(targetPtr).mask        := 0.U
      entries(targetPtr).pc          := io.enq(i).bits.pc
    }
  }

  val totalEnq = PopCount(enqFires)
  enqPtr := enqPtr + totalEnq

  // 2. Execution Update
  when(io.exec_update.valid) {
    for (i <- 0 until numEntries) {
      when(entries(i).valid && entries(i).robIdx === io.exec_update.robIdx) {
        entries(i).executed := true.B
        entries(i).paddr    := io.exec_update.paddr
        entries(i).mask     := io.exec_update.mask
        entries(i).pc       := io.exec_update.pc
      }
    }
  }

  // 3. Store Snoop Violation Check (XiangShan LoadQueueRAW Parity)
  val match_valids = Wire(Vec(numEntries, Bool()))
  for (i <- 0 until numEntries) {
    val e = entries(i)
    val is_younger = e.valid && e.executed && isYoungerInRob(e.robIdx, io.store_snoop.robIdx, io.robHeadPtr)
    val addr_match = (e.paddr(xLen - 1, 3) === io.store_snoop.paddr(xLen - 1, 3))
    val mask_overlap = (e.mask & io.store_snoop.mask) =/= 0.U
    match_valids(i) := io.store_snoop.valid && is_younger && addr_match && mask_overlap
  }
  val has_match = match_valids.asUInt.orR
  val best_match_idx = PriorityEncoder(match_valids)

  io.violation.valid       := has_match
  io.violation.loadRobIdx  := entries(best_match_idx).robIdx
  io.violation.snapshotIdx := entries(best_match_idx).snapshotIdx
  io.violation.loadPC      := entries(best_match_idx).pc
  io.violation.storePC     := io.store_snoop.pc

  // 3. Commit Retirement (Free entries on ROB commit)
  for (c <- 0 until decodeWidth) {
    when(io.commit.valid(c)) {
      for (i <- 0 until numEntries) {
        when(entries(i).valid && entries(i).robIdx === io.commit.robIdx(c)) {
          entries(i).valid    := false.B
          entries(i).executed := false.B
        }
      }
    }
  }

  // 4. Flush Handling
  when(io.redirect.valid) {
    when(io.redirect.is_exception) {
      for (i <- 0 until numEntries) {
        entries(i).valid    := false.B
        entries(i).executed := false.B
      }
      enqPtr := 0.U
    } .otherwise {
      for (i <- 0 until numEntries) {
        when(entries(i).valid && isYoungerThanSnpt(entries(i).snapshotIdx, io.redirect.snapshotIdx, io.snptDeqPtr)) {
          entries(i).valid    := false.B
          entries(i).executed := false.B
        }
      }
    }
  }
}
