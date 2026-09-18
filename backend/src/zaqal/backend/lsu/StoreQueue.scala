package zaqal.backend.lsu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class StoreQueueEntry(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val valid        = Bool()
  val committed    = Bool()
  val addr_valid   = Bool()
  val data_valid   = Bool()
  val robIdx       = UInt(log2Up(128).W)
  val snapshotIdx  = UInt(log2Up(renameSnapshotNum).W)
  val paddr        = UInt(xLen.W)
  val wmask        = UInt(16.W)
  val wdata        = UInt((xLen * 2).W)
}

class StoreQueue(val numEntries: Int = 16)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // 1. Allocation Interface (from Dispatch)
    val enq = Vec(decodeWidth, Flipped(Decoupled(new Bundle {
      val robIdx      = UInt(log2Up(128).W)
      val snapshotIdx = UInt(log2Up(renameSnapshotNum).W)
    })))
    val enq_indices = Output(Vec(decodeWidth, UInt(log2Up(numEntries).W)))
    val count       = Output(UInt((log2Up(numEntries) + 1).W))

    // 2. Execution / Write Interface (from Memory Stage AGU & PRF)
    val write = Input(new Bundle {
      val valid   = Bool()
      val robIdx  = UInt(log2Up(128).W)
      val paddr   = UInt(xLen.W)
      val wmask   = UInt(16.W)
      val wdata   = UInt((xLen * 2).W)
    })

    // 3. Store-to-Load Forwarding (STLF) Query (from Load AGUs)
    val stlf_query = Vec(2, Input(new Bundle {
      val valid   = Bool()
      val robIdx  = UInt(log2Up(128).W)
      val paddr   = UInt(xLen.W)
      val mask    = UInt(16.W)
    }))
    val stlf_resp = Vec(2, Output(new Bundle {
      val hit     = Bool()
      val wdata   = UInt((xLen * 2).W)
      val wmask   = UInt(16.W)
    }))

    // 4. Commit Interface (from ROB)
    val commit = Input(new Bundle {
      val valid   = Vec(decodeWidth, Bool())
      val robIdx  = Vec(decodeWidth, UInt(log2Up(128).W))
    })

    // 5. Commit Drain to L1 Data Cache / DataMem
    val drain = Output(new Bundle {
      val valid   = Bool()
      val paddr   = UInt(xLen.W)
      val wmask   = UInt(16.W)
      val wdata   = UInt((xLen * 2).W)
    })
    val drain_ready = Input(Bool())

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
    val e = Wire(new StoreQueueEntry)
    e.valid        := false.B
    e.committed    := false.B
    e.addr_valid   := false.B
    e.data_valid   := false.B
    e.robIdx       := 0.U
    e.snapshotIdx  := 0.U
    e.paddr        := 0.U
    e.wmask        := 0.U
    e.wdata        := 0.U
    e
  })))

  val enqPtr = RegInit(0.U(log2Up(numEntries).W))
  val deqPtr = RegInit(0.U(log2Up(numEntries).W))

  val currentCount = PopCount(entries.map(_.valid))
  io.count := currentCount

  def isOlderInRob(idxA: UInt, idxB: UInt, head: UInt): Bool = {
    val distA = Mux(idxA >= head, idxA - head, idxA + 128.U - head)
    val distB = Mux(idxB >= head, idxB - head, idxB + 128.U - head)
    distA < distB
  }

  def isYoungerThanSnpt(snpt: UInt, restoreSnpt: UInt, deqPtr: UInt): Bool = {
    def circDist(ptr: UInt): UInt = Mux(ptr >= deqPtr, ptr - deqPtr, ptr + renameSnapshotNum.U - deqPtr)
    circDist(snpt) > circDist(restoreSnpt)
  }

  // ---------------- 1. ALLOCATION (DISPATCH) ----------------
  val canEnq = (numEntries.U - currentCount) >= decodeWidth.U
  val enqFires = io.enq.map(_.fire)

  for (i <- 0 until decodeWidth) {
    io.enq(i).ready := canEnq
    val allocOffset = if (i == 0) 0.U else PopCount(enqFires.take(i))
    val targetPtr = enqPtr + allocOffset
    io.enq_indices(i) := targetPtr

    when(io.enq(i).fire) {
      entries(targetPtr).valid       := true.B
      entries(targetPtr).committed   := false.B
      entries(targetPtr).addr_valid  := false.B
      entries(targetPtr).data_valid  := false.B
      entries(targetPtr).robIdx      := io.enq(i).bits.robIdx
      entries(targetPtr).snapshotIdx := io.enq(i).bits.snapshotIdx
      entries(targetPtr).paddr       := 0.U
      entries(targetPtr).wmask       := 0.U
      entries(targetPtr).wdata       := 0.U
    }
  }

  val totalEnq = PopCount(enqFires)
  enqPtr := enqPtr + totalEnq

  // ---------------- 2. EXECUTION / WRITE UPDATE ----------------
  when(io.write.valid) {
    for (i <- 0 until numEntries) {
      when(entries(i).valid && entries(i).robIdx === io.write.robIdx) {
        entries(i).addr_valid := true.B
        entries(i).data_valid := true.B
        entries(i).paddr      := io.write.paddr
        entries(i).wmask      := io.write.wmask
        entries(i).wdata      := io.write.wdata
      }
    }
  }

  // ---------------- 3. STORE-TO-LOAD FORWARDING (STLF) ----------------
  for (q <- 0 until 2) {
    val match_valids = Wire(Vec(numEntries, Bool()))

    for (i <- 0 until numEntries) {
      val e = entries(i)
      val is_older = e.valid && e.addr_valid && isOlderInRob(e.robIdx, io.stlf_query(q).robIdx, io.robHeadPtr)
      val addr_match = (e.paddr(xLen - 1, 3) === io.stlf_query(q).paddr(xLen - 1, 3))
      val mask_overlap = (e.wmask & io.stlf_query(q).mask) =/= 0.U

      match_valids(i) := io.stlf_query(q).valid && is_older && addr_match && mask_overlap && e.data_valid
    }

    val has_match = match_valids.asUInt.orR
    val best_match_idx = WireDefault(0.U(log2Up(numEntries).W))

    for (i <- 0 until numEntries) {
      when(match_valids(i)) {
        best_match_idx := i.U
      }
    }

    io.stlf_resp(q).hit   := has_match
    io.stlf_resp(q).wdata := entries(best_match_idx).wdata
    io.stlf_resp(q).wmask := entries(best_match_idx).wmask
  }

  // ---------------- 4. COMMIT MARKING (FROM ROB) ----------------
  for (c <- 0 until decodeWidth) {
    when(io.commit.valid(c)) {
      for (i <- 0 until numEntries) {
        when(entries(i).valid && entries(i).robIdx === io.commit.robIdx(c)) {
          entries(i).committed := true.B
        }
      }
    }
  }

  // ---------------- 5. COMMIT DRAIN TO DATA CACHE ----------------
  val headEntry = entries(deqPtr)
  val canDrain = headEntry.valid && headEntry.committed && headEntry.addr_valid && headEntry.data_valid

  io.drain.valid := canDrain
  io.drain.paddr := headEntry.paddr
  io.drain.wmask := headEntry.wmask
  io.drain.wdata := headEntry.wdata

  val drained = canDrain && io.drain_ready
  when(drained) {
    headEntry.valid     := false.B
    headEntry.committed := false.B
    deqPtr := deqPtr + 1.U
  }

  // ---------------- 6. FLUSH & REDIRECTION HANDLING ----------------
  when(io.redirect.valid) {
    when(io.redirect.is_exception) {
      for (i <- 0 until numEntries) {
        when(!entries(i).committed) {
          entries(i).valid      := false.B
          entries(i).addr_valid := false.B
          entries(i).data_valid := false.B
        }
      }
      enqPtr := deqPtr
    } .otherwise {
      for (i <- 0 until numEntries) {
        when(entries(i).valid && !entries(i).committed && isYoungerThanSnpt(entries(i).snapshotIdx, io.redirect.snapshotIdx, io.snptDeqPtr)) {
          entries(i).valid      := false.B
          entries(i).addr_valid := false.B
          entries(i).data_valid := false.B
        }
      }
    }
  }
}
