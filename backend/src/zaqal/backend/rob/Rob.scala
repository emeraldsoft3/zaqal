package zaqal.backend.rob

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.backend.rob.RobBundles._
import zaqal.common._

class Rob(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val enq = Vec(decodeWidth, Flipped(Decoupled(new DecodedMicroOp)))
    val exuWriteback = Vec(6, Flipped(ValidIO(new ExuOutput)))
    val commits = Output(new RobCommitIO)
    val robFull = Output(Bool())
    val headNotReady = Output(Bool())
    val cpu_halt = Output(Bool())
  })
  
  // Phase 7 Day 1-5: ROB Core buffer logic, Pointer Management, & Circular Commitment
  val robSize = 128
  val robEntries = RegInit(VecInit.fill(robSize)((new RobEntryBundle).Lit(
    _.valid -> false.B,
    _.stdWritebacked -> false.B,
    _.exceptionVec -> 0.U
  )))
  
  val enqPtr = RegInit(0.U(log2Up(robSize).W))
  val deqPtr = RegInit(0.U(log2Up(robSize).W))

  val isEmpty = enqPtr === deqPtr
  
  // -------------------------------------------------------------
  // 1. Enqueue (Dispatch) Logic
  // -------------------------------------------------------------
  val elementsInRob = enqPtr - deqPtr
  val spaceAvailable = robSize.U - elementsInRob
  val canAcceptAll = spaceAvailable >= decodeWidth.U
  
  val enqCount = PopCount(io.enq.map(req => req.valid && canAcceptAll))
  
  val allocPtrs = Wire(Vec(decodeWidth, UInt(log2Up(robSize).W)))
  allocPtrs(0) := enqPtr
  for (i <- 1 until decodeWidth) {
    allocPtrs(i) := allocPtrs(i-1) + Mux(io.enq(i-1).valid && canAcceptAll, 1.U, 0.U)
  }
  
  for (i <- 0 until decodeWidth) {
    io.enq(i).ready := canAcceptAll
    when(io.enq(i).valid && canAcceptAll) {
      val idx = allocPtrs(i)
      val entry = robEntries(idx)
      entry.valid := true.B
      entry.vls := false.B
      entry.interrupt_safe := true.B
      entry.fpWen := io.enq(i).bits.decode.rd_is_fp
      entry.rfWen := (io.enq(i).bits.decode.rd =/= 0.U) && !io.enq(i).bits.decode.rd_is_fp
      entry.wflags := false.B
      entry.isRVC := io.enq(i).bits.decode.is_rvc
      entry.fflags := 0.U
      entry.mmio := false.B
      entry.stdWritebacked := false.B
      entry.needFlush := false.B
      entry.exceptionVec := 0.U
    }
  }
  
  when (enqCount > 0.U) {
    enqPtr := enqPtr + enqCount
  }
  
  // -------------------------------------------------------------
  // 2. Out-of-Order Writeback Logic
  // -------------------------------------------------------------
  for (wb <- io.exuWriteback) {
    when(wb.valid) {
      val idx = wb.bits.robIdx
      robEntries(idx).stdWritebacked := true.B
      robEntries(idx).exceptionVec := wb.bits.exceptionVec
    }
  }

  // -------------------------------------------------------------
  // 3. In-Order Commit (Graduation) Logic
  // -------------------------------------------------------------
  val commitValidThisLine = Wire(Vec(decodeWidth, Bool()))
  val walkDeqPtrs = Wire(Vec(decodeWidth, UInt(log2Up(robSize).W)))
  walkDeqPtrs(0) := deqPtr
  for (i <- 1 until decodeWidth) {
    walkDeqPtrs(i) := walkDeqPtrs(i-1) + 1.U
  }

  // Block commits if an older instruction hasn't committed or hit an exception
  var blockCommit = false.B
  for (i <- 0 until decodeWidth) {
    val entry = robEntries(walkDeqPtrs(i))
    val isReadyToCommit = entry.valid && entry.stdWritebacked && (entry.exceptionVec === 0.U)
    
    commitValidThisLine(i) := isReadyToCommit && !blockCommit && (elementsInRob > i.U)
    
    when (!isReadyToCommit || entry.exceptionVec =/= 0.U) {
      blockCommit = true.B
    }

    io.commits.commitValid(i) := commitValidThisLine(i)
    io.commits.info(i).commit_v := entry.valid
    io.commits.info(i).commit_w := entry.stdWritebacked
    io.commits.info(i).rfWen := entry.rfWen
    io.commits.info(i).fpWen := entry.fpWen
    
    when(commitValidThisLine(i)) {
      entry.valid := false.B // Free the entry
    }
  }

  val commitCount = PopCount(commitValidThisLine)
  when (commitCount > 0.U) {
    deqPtr := deqPtr + commitCount
  }

  io.robFull := !canAcceptAll
  io.headNotReady := isEmpty
  io.cpu_halt := false.B
}
