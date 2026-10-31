package zaqal.backend.rob

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.backend.rob.RobBundles._
import zaqal.common._

class Rob(val numWb: Int = 14)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val enq = Vec(decodeWidth, Flipped(Decoupled(new DecodedMicroOp)))
    val exuWriteback = Vec(numWb, Flipped(ValidIO(new ExuOutput)))
    val commits = Output(new RobCommitIO)
    val commitRobIdx = Output(Vec(decodeWidth, UInt(log2Up(128).W)))
    val robDeqPtr = Output(UInt(log2Up(128).W))
    val allocPtrs = Output(Vec(decodeWidth, UInt(log2Up(128).W)))
    val bpu_redirect = Input(new BPURedirect)
    val flushOut = Output(Valid(new BPURedirect))
    val robFull = Output(Bool())
    val headNotReady = Output(Bool())
    val cpu_halt = Output(Bool())
  })
  
  // Phase 7 Day 1-5: ROB Core buffer logic, Pointer Management, & Circular Commitment
  val robSize = 128
  val initEntry = WireDefault(0.U.asTypeOf(new RobEntryBundle))
  val robEntries = RegInit(VecInit.fill(robSize)(initEntry))
  
  val enqPtr = RegInit(0.U(log2Up(robSize).W))
  val deqPtr = RegInit(0.U(log2Up(robSize).W))

  val headEntry = robEntries(deqPtr)
  val headHasException = headEntry.valid && headEntry.stdWritebacked && (headEntry.exceptionVec =/= 0.U)

  val maybeFull = RegInit(false.B)
  
  val isEmpty = (enqPtr === deqPtr) && !maybeFull
  val isFull  = (enqPtr === deqPtr) && maybeFull
  
  val elementsInRob = Mux(isFull, robSize.U,
                      Mux(enqPtr >= deqPtr, enqPtr - deqPtr,
                          robSize.U - (deqPtr - enqPtr)))

  def robDist(idx: UInt): UInt = Mux(idx >= deqPtr, idx - deqPtr, idx + robSize.U - deqPtr)
                          
  val spaceAvailable = robSize.U - elementsInRob
  val canAcceptAll = spaceAvailable >= decodeWidth.U
  val can_enq = canAcceptAll && !io.bpu_redirect.valid && !headHasException
  
  val enqCount = PopCount(io.enq.map(req => req.valid && can_enq))
  
  io.allocPtrs(0) := enqPtr
  for (i <- 1 until decodeWidth) {
    io.allocPtrs(i) := io.allocPtrs(i-1) + Mux(io.enq(i-1).valid && can_enq, 1.U, 0.U)
  }
  
  for (i <- 0 until decodeWidth) {
    io.enq(i).ready := can_enq
    when(io.enq(i).valid && can_enq) {
      val idx = io.allocPtrs(i)
      val entry = robEntries(idx)
      entry.valid := true.B
      entry.vls := false.B
      entry.interrupt_safe := true.B
      entry.vecWen := io.enq(i).bits.decode.rd_is_vec
      entry.fpWen  := io.enq(i).bits.decode.rd_is_fp
      entry.rfWen  := (io.enq(i).bits.decode.rd =/= 0.U) && !io.enq(i).bits.decode.rd_is_fp && !io.enq(i).bits.decode.rd_is_vec && !io.enq(i).bits.decode.is_branch && !io.enq(i).bits.decode.is_store && !io.enq(i).bits.decode.is_fstore

      entry.wflags := false.B
      entry.isRVC := io.enq(i).bits.decode.is_rvc
      entry.fflags := 0.U
      entry.mmio := false.B
      entry.stdWritebacked := false.B
      entry.needFlush := false.B
      entry.exceptionVec := 0.U
      entry.old_pdest := io.enq(i).bits.old_pdest
      entry.pdest := io.enq(i).bits.pdest
      entry.rd := io.enq(i).bits.decode.rd
      
      entry.pc := io.enq(i).bits.uop.pc
      entry.instr := io.enq(i).bits.uop.inst_raw
      entry.wbData := 0.U
      entry.target := Mux(io.enq(i).bits.decode.is_jal, io.enq(i).bits.uop.pc + io.enq(i).bits.decode.imm.asUInt, 0.U) // Target written back later for jalr? For now it's okay.
      entry.ftqPtr := io.enq(i).bits.uop.ftqPtr
      entry.is_cfi := io.enq(i).bits.decode.is_branch || io.enq(i).bits.decode.is_jal || io.enq(i).bits.decode.is_jalr
      entry.is_jal := io.enq(i).bits.decode.is_jal
      entry.is_jalr := io.enq(i).bits.decode.is_jalr
      entry.is_call := io.enq(i).bits.uop.pre.is_call
      entry.is_ret := io.enq(i).bits.uop.pre.is_ret
    }
  }
  
  when (enqCount > 0.U && !io.bpu_redirect.valid && !headHasException) {
    enqPtr := enqPtr + enqCount
  }
  
  // -------------------------------------------------------------
  // 2. Out-of-Order Writeback Logic
  // -------------------------------------------------------------
  for (wb <- io.exuWriteback) {
    when(wb.valid) {
      val idx = wb.bits.robIdx
      when(robEntries(idx).valid) {
        robEntries(idx).stdWritebacked := true.B
        robEntries(idx).wbData := wb.bits.data
        robEntries(idx).exceptionVec := wb.bits.exceptionVec
        when(robEntries(idx).is_jalr) {
          robEntries(idx).target := wb.bits.data
        }
      }
    }
  }

  // -------------------------------------------------------------
  // 3. Exception & Flush Logic (Day 6-8)
  // -------------------------------------------------------------

  io.flushOut.valid := headHasException
  io.flushOut.bits.valid := headHasException
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
  io.flushOut.bits.robIdx := deqPtr

  // If the head throws an exception, instantly wipe the entire ROB pipeline
  when(headHasException) {
    enqPtr := deqPtr // Dump all speculative entries by snapping enqPtr to deqPtr
    for (i <- 0 until robSize) {
      robEntries(i).valid := false.B
    }
  } .elsewhen(io.bpu_redirect.valid) {
    when(io.bpu_redirect.is_exception) {
      // Full pipeline flush on Exception / Trap / Interrupt / MRET
      enqPtr := 0.U
      deqPtr := 0.U
      for (i <- 0 until robSize) {
        robEntries(i).valid := false.B
      }
      maybeFull := false.B
    } .otherwise {
      // Flush branch misprediction: only younger speculative entries
      val dist_branch = robDist(io.bpu_redirect.robIdx)
      enqPtr := Mux(io.bpu_redirect.robIdx === (robSize - 1).U, 0.U, io.bpu_redirect.robIdx + 1.U)
      for (i <- 0 until robSize) {
        val dist_i = robDist(i.U)
        when(robEntries(i).valid && (dist_i > dist_branch)) {
          robEntries(i).valid := false.B
        }
      }
      maybeFull := false.B // A flush always frees up space
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
  
  val dist_branch = robDist(io.bpu_redirect.robIdx)
  for (i <- 0 until decodeWidth) {
    val entry = robEntries(walkDeqPtrs(i))
    val dist_commit = robDist(walkDeqPtrs(i))
    val commit_is_killed_by_redirect = io.bpu_redirect.valid && (io.bpu_redirect.is_exception || (dist_commit > dist_branch))
    val isReadyToCommit = entry.valid && entry.stdWritebacked && (entry.exceptionVec === 0.U) && !commit_is_killed_by_redirect
    
    // An instruction is blocked if an older instruction in the bundle couldn't commit, or if the head had an exception
    if (i == 0) {
      blockCommitCascade(i) := !isReadyToCommit || headHasException
    } else {
      blockCommitCascade(i) := blockCommitCascade(i-1) || !isReadyToCommit || headHasException
    }
    
    commitValidThisLine(i) := isReadyToCommit && (if (i == 0) !headHasException else !blockCommitCascade(i-1)) && (elementsInRob > i.U)

    io.commitRobIdx(i) := walkDeqPtrs(i)
    io.commits.commitValid(i) := commitValidThisLine(i)
    io.commits.info(i).commit_v := entry.valid
    io.commits.info(i).walk_v := false.B
    io.commits.info(i).commit_v := commitValidThisLine(i)
    io.commits.info(i).commit_w := entry.stdWritebacked
    io.commits.info(i).interrupt_safe := entry.interrupt_safe
    io.commits.info(i).needFlush := entry.needFlush
    io.commits.info(i).rfWen := entry.rfWen
    io.commits.info(i).fpWen := entry.fpWen
    io.commits.info(i).vecWen := entry.vecWen
    io.commits.info(i).is_call := entry.is_call
    io.commits.info(i).is_ret := entry.is_ret
    io.commits.info(i).target := entry.target
    io.commits.info(i).pc := entry.pc
    io.commits.info(i).instr := entry.instr
    io.commits.info(i).data := entry.wbData
    io.commits.info(i).isRVC := entry.isRVC
    io.commits.info(i).mmio := entry.mmio
    io.commits.info(i).old_pdest := entry.old_pdest
    io.commits.info(i).pdest := entry.pdest
    io.commits.info(i).rd := entry.rd
    
    when(commitValidThisLine(i)) {
      entry.valid := false.B // Free the entry
      // printf(p"ROB COMMIT [Port $i]: pc=${Hexadecimal(entry.pc)} is_call=${entry.is_call} is_ret=${entry.is_ret}\n")
    }
  }

  val commitCount = PopCount(commitValidThisLine)
  // Only advance the deqPtr if we aren't currently flushing
  when (commitCount > 0.U && !headHasException && !(io.bpu_redirect.valid && io.bpu_redirect.is_exception)) {
    deqPtr := deqPtr + commitCount
  }
  
  when(headHasException) {
    maybeFull := false.B
  } .elsewhen(io.bpu_redirect.valid && !io.bpu_redirect.is_exception) {
    maybeFull := false.B // Flush drains the ROB
  } .elsewhen (enqCount > commitCount) {
    maybeFull := true.B
  } .elsewhen (commitCount > enqCount) {
    maybeFull := false.B
  }

  io.robDeqPtr := deqPtr
  io.robFull := !canAcceptAll
  io.headNotReady := isEmpty
  io.cpu_halt := false.B

  // -------------------------------------------------------------
  // 5. Phase 12 Difftest Verification Hooks (DPI-C)
  // -------------------------------------------------------------
  if (enableDifftest) {
    for (i <- 0 until decodeWidth) {
      val entry = robEntries(walkDeqPtrs(i))
      val dt = Module(new DifftestInstrCommit)
      dt.io.clock  := clock
      dt.io.coreid := 0.U
      dt.io.index  := i.U
      dt.io.valid  := commitValidThisLine(i)
      dt.io.pc     := entry.pc
      dt.io.instr  := entry.instr
      dt.io.skip   := entry.mmio
      dt.io.isRVC  := entry.isRVC
      dt.io.rfwen  := entry.rfWen
      dt.io.fpwen  := entry.fpWen
      dt.io.vecwen := entry.vecWen
      dt.io.wdest  := entry.rd
      dt.io.data   := entry.wbData
    }

    val dtTrap = Module(new DifftestTrapEvent)
    dtTrap.io.clock  := clock
    dtTrap.io.coreid := 0.U
    dtTrap.io.valid  := headHasException
    dtTrap.io.code   := headEntry.exceptionVec(7, 0)
    dtTrap.io.pc     := headEntry.pc
    dtTrap.io.cycle  := 0.U
  }
}
