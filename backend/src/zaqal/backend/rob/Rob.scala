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
    val flushOut = Output(Valid(new BPURedirect))
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
      
      // Day 6-8: Flush Recovery Metadata
      entry.pc := io.enq(i).bits.uop.pc
      entry.ftqPtr := io.enq(i).bits.uop.ftqPtr
      entry.is_cfi := io.enq(i).bits.decode.is_branch || io.enq(i).bits.decode.is_jal || io.enq(i).bits.decode.is_jalr
      entry.is_jal := io.enq(i).bits.decode.is_jal
      entry.is_jalr := io.enq(i).bits.decode.is_jalr
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
  // 3. Exception & Flush Logic (Day 6-8)
  // -------------------------------------------------------------
  val headEntry = robEntries(deqPtr)
  val headHasException = headEntry.valid && headEntry.stdWritebacked && (headEntry.exceptionVec =/= 0.U)

  io.flushOut.valid := headHasException
  io.flushOut.bits.target := 0.U // Handled downstream by resolution logic
  io.flushOut.bits.epoch := 0.U 
  io.flushOut.bits.is_exception := true.B
  io.flushOut.bits.exc_cause := headEntry.exceptionVec
  io.flushOut.bits.snapshotIdx := 0.U // Recover RAT state
  io.flushOut.bits.pc := headEntry.pc
  io.flushOut.bits.taken := false.B
  io.flushOut.bits.is_cfi := headEntry.is_cfi
  io.flushOut.bits.is_jal := headEntry.is_jal
  io.flushOut.bits.is_jalr := headEntry.is_jalr
  io.flushOut.bits.ftqPtr := headEntry.ftqPtr

  // If the head throws an exception, instantly wipe the entire ROB pipeline
  when(headHasException) {
    enqPtr := deqPtr // Dump all speculative entries by snapping enqPtr to deqPtr
    for (i <- 0 until robSize) {
      robEntries(i).valid := false.B
    }
  }

  // -------------------------------------------------------------
  // 4. In-Order Commit (Graduation) Logic
  // -------------------------------------------------------------
  val commitValidThisLine = Wire(Vec(decodeWidth, Bool()))
  val walkDeqPtrs = Wire(Vec(decodeWidth, UInt(log2Up(robSize).W)))
  walkDeqPtrs(0) := deqPtr
  for (i <- 1 until decodeWidth) {
    walkDeqPtrs(i) := walkDeqPtrs(i-1) + 1.U
  }

  // Cascade commit block signal to prevent out-of-order retirement
  val blockCommitCascade = Wire(Vec(decodeWidth, Bool()))
  
  for (i <- 0 until decodeWidth) {
    val entry = robEntries(walkDeqPtrs(i))
    val isReadyToCommit = entry.valid && entry.stdWritebacked && (entry.exceptionVec === 0.U)
    
    // An instruction is blocked if an older instruction in the bundle couldn't commit, or if the head had an exception
    if (i == 0) {
      blockCommitCascade(i) := !isReadyToCommit || headHasException
    } else {
      blockCommitCascade(i) := blockCommitCascade(i-1) || !isReadyToCommit || headHasException
    }
    
    commitValidThisLine(i) := isReadyToCommit && (if (i == 0) !headHasException else !blockCommitCascade(i-1)) && (elementsInRob > i.U)

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
  // Only advance the deqPtr if we aren't currently flushing
  when (commitCount > 0.U && !headHasException) {
    deqPtr := deqPtr + commitCount
  }

  io.robFull := !canAcceptAll
  io.headNotReady := isEmpty
  io.cpu_halt := false.B
}
