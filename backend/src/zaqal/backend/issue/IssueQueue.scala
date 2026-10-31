package zaqal.backend.issue

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class IssueQueue(val numEntries: Int, val numEnq: Int, val numDeq: Int, val numWakeup: Int, val isMem: Boolean = false)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val enq = Vec(numEnq, Flipped(Decoupled(new DecodedMicroOp)))
    val deq = Vec(numDeq, Decoupled(new DecodedMicroOp))
    val wakeup = Vec(numWakeup, Input(new WakeupBus))
    val redirect_valid = Input(Bool())
    val redirect_restore_idx = Input(UInt(log2Up(renameSnapshotNum).W))
    val redirect_enq_ptr = Input(UInt(log2Up(renameSnapshotNum).W))
    val redirect_deq_ptr = Input(UInt(log2Up(renameSnapshotNum).W))
    val redirect_is_exception = Input(Bool())
    val redirect_robIdx = Input(UInt(log2Up(128).W))
    
    val rs1_ready_in = Vec(numEnq, Input(Bool()))
    val rs2_ready_in = Vec(numEnq, Input(Bool()))
    val rs3_ready_in = Vec(numEnq, Input(Bool()))

    // Store AGU resolution port (XiangShan Store Sets MDP)
    val store_resolved = Input(Valid(UInt(log2Up(128).W)))
    val robDeqPtr = Input(UInt(log2Up(128).W))
  })

  class IQEntry extends Bundle {
    val valid = Bool()
    val uop = new DecodedMicroOp
    val rs1_ready = Bool()
    val rs2_ready = Bool()
    val rs3_ready = Bool()
  }

  val entries = RegInit(VecInit(Seq.fill(numEntries)(0.U.asTypeOf(new IQEntry))))

  val woken_rs1 = Wire(Vec(numEntries, Bool()))
  val woken_rs2 = Wire(Vec(numEntries, Bool()))
  val woken_rs3 = Wire(Vec(numEntries, Bool()))

  for (i <- 0 until numEntries) {
    woken_rs1(i) := entries(i).rs1_ready
    woken_rs2(i) := entries(i).rs2_ready
    woken_rs3(i) := entries(i).rs3_ready

    val r1_is_fp = entries(i).uop.decode.rs1_is_fp
    val r2_is_fp = entries(i).uop.decode.rs2_is_fp
    val r3_is_fp = entries(i).uop.decode.rs3_is_fp

    for (w <- 0 until numWakeup) {
      when (io.wakeup(w).valid) {
        when (entries(i).uop.psrs1 === io.wakeup(w).pdest && entries(i).uop.psrs1 =/= 0.U && io.wakeup(w).is_fp === r1_is_fp) { woken_rs1(i) := true.B }
        when (entries(i).uop.psrs2 === io.wakeup(w).pdest && entries(i).uop.psrs2 =/= 0.U && io.wakeup(w).is_fp === r2_is_fp) { woken_rs2(i) := true.B }
        when (entries(i).uop.psrs3 === io.wakeup(w).pdest && entries(i).uop.psrs3 =/= 0.U && io.wakeup(w).is_fp === r3_is_fp) { woken_rs3(i) := true.B }
      }
    }
  }

  val ageDetector = Module(new AgeDetector(numEntries, numEnq, numDeq))
  val enq_onehot = Wire(Vec(numEnq, UInt(numEntries.W)))
  for (e <- 0 until numEnq) enq_onehot(e) := 0.U
  ageDetector.io.enq := enq_onehot

  val is_sys = VecInit((0 until numEntries).map { i =>
    entries(i).valid && (
      entries(i).uop.decode.is_csr ||
      entries(i).uop.decode.is_ecall ||
      entries(i).uop.decode.is_ebreak ||
      entries(i).uop.decode.is_mret ||
      entries(i).uop.decode.is_sret ||
      entries(i).uop.decode.is_wfi ||
      entries(i).uop.decode.is_sfence_vma ||
      entries(i).uop.decode.is_amx ||
      entries(i).uop.decode.is_vset ||
      entries(i).uop.decode.is_vec_arith ||
      entries(i).uop.decode.is_vec_mem
    )
  })

  def robDist(idx: UInt): UInt = Mux(idx >= io.robDeqPtr, idx - io.robDeqPtr, idx + 128.U - io.robDeqPtr)

  val can_issue = Wire(Vec(numEntries, Bool()))
  for (i <- 0 until numEntries) {
    val is_cfi = entries(i).uop.decode.is_branch || entries(i).uop.decode.is_jal || entries(i).uop.decode.is_jalr
    val has_older_cfi = VecInit((0 until numEntries).map { j =>
      val j_valid = entries(j).valid
      val j_is_cfi = j_valid && (entries(j).uop.decode.is_branch || entries(j).uop.decode.is_jal || entries(j).uop.decode.is_jalr)
      val j_snap = entries(j).uop.snapshotIdx
      val i_snap = entries(i).uop.snapshotIdx
      val deqPtr = io.redirect_deq_ptr
      def circDist(ptr: UInt): UInt = Mux(ptr >= deqPtr, ptr - deqPtr, ptr + renameSnapshotNum.U - deqPtr)
      val j_is_older = circDist(j_snap) < circDist(i_snap)
      (i.U =/= j.U) && j_is_cfi && j_is_older
    }).asUInt.orR

    // A system instruction is only allowed to issue when it reaches the head of the ROB
    val sys_at_rob_head = entries(i).uop.robIdx === io.robDeqPtr
    val sys_can_issue = !is_sys(i) || sys_at_rob_head

    // No younger instruction can issue ahead of an older system instruction in the ROB
    val has_older_sys = VecInit((0 until numEntries).map { j =>
      entries(j).valid && is_sys(j) && (i.U =/= j.U) && (robDist(entries(j).uop.robIdx) < robDist(entries(i).uop.robIdx))
    }).asUInt.orR

    can_issue(i) := entries(i).valid && woken_rs1(i) && woken_rs2(i) && woken_rs3(i) &&
                    !entries(i).uop.loadWaitBit &&
                    !(is_cfi && has_older_cfi) &&
                    sys_can_issue &&
                    !has_older_sys
  }

  val sys_mask = is_sys.asUInt

  val cfi_mask = VecInit((0 until numEntries).map { i =>
    entries(i).uop.decode.is_branch || entries(i).uop.decode.is_jal || entries(i).uop.decode.is_jalr
  }).asUInt

  val mul_div_mask = VecInit((0 until numEntries).map { i =>
    val d = entries(i).uop.decode
    d.is_mul || d.is_mulh || d.is_mulhsu || d.is_mulhu || d.is_mulw ||
    d.is_div || d.is_divu || d.is_rem || d.is_remu || d.is_divw || d.is_divuw || d.is_remw || d.is_remuw
  }).asUInt

  val load_mask = VecInit((0 until numEntries).map { i =>
    val d = entries(i).uop.decode
    d.is_load || d.is_fload || d.is_atomic
  }).asUInt

  val store_mask = VecInit((0 until numEntries).map { i =>
    val d = entries(i).uop.decode
    d.is_store || d.is_fstore
  }).asUInt

  var current_can_issue = can_issue.asUInt
  val issue_onehot = Wire(Vec(numDeq, UInt(numEntries.W)))
  for (k <- 0 until numDeq) {
    val port_can_issue = if (isMem) {
      if (k < 2) current_can_issue & load_mask
      else current_can_issue & store_mask
    } else {
      if (k == 0) {
        current_can_issue
      } else if (k == 1) {
        current_can_issue & ~sys_mask
      } else {
        current_can_issue & ~sys_mask & ~cfi_mask & ~mul_div_mask
      }
    }
    ageDetector.io.canIssue(k) := port_can_issue
    issue_onehot(k) := ageDetector.io.out(k)
    val issue_idx = OHToUInt(issue_onehot(k))
    val issue_valid = issue_onehot(k).orR

    io.deq(k).valid := issue_valid
    io.deq(k).bits := Mux1H(issue_onehot(k), entries.map(_.uop))
    
    val deq_fire = io.deq(k).valid && io.deq(k).ready
    // when (deq_fire) {
    //   printf(p"    [IQ ISSUE Port $k]: pc=${Hexadecimal(io.deq(k).bits.uop.pc)} entry_idx=${OHToUInt(issue_onehot(k))}\n")
    // }
    current_can_issue = current_can_issue & ~Mux(deq_fire, issue_onehot(k), 0.U)
  }

  val is_empty = Wire(Vec(numEntries, Bool()))
  for (i <- 0 until numEntries) {
    val issued_this_cycle = (0 until numDeq).map(k => io.deq(k).valid && io.deq(k).ready && issue_onehot(k)(i)).reduce(_ || _)
    is_empty(i) := !entries(i).valid || issued_this_cycle
  }

  val alloc_idx = Wire(Vec(numEnq, UInt(log2Ceil(numEntries).W)))
  val alloc_valid = Wire(Vec(numEnq, Bool()))
  
  var current_empty_mask = is_empty.asUInt
  for (e <- 0 until numEnq) {
    alloc_valid(e) := current_empty_mask.orR
    alloc_idx(e) := PriorityEncoder(current_empty_mask)
    io.enq(e).ready := alloc_valid(e)

    when (io.enq(e).valid && io.enq(e).ready) {
      enq_onehot(e) := UIntToOH(alloc_idx(e))
    }
    
    current_empty_mask = current_empty_mask & ~(UIntToOH(alloc_idx(e)))
  }

  for (i <- 0 until numEntries) {
    when (entries(i).valid) {
      entries(i).rs1_ready := woken_rs1(i)
      entries(i).rs2_ready := woken_rs2(i)
      entries(i).rs3_ready := woken_rs3(i)
    }

    val issued_this_cycle = (0 until numDeq).map(k => io.deq(k).valid && io.deq(k).ready && issue_onehot(k)(i)).reduce(_ || _)
    when (issued_this_cycle) {
      entries(i).valid := false.B
    }

    for (e <- 0 until numEnq) {
      when (io.enq(e).valid && io.enq(e).ready && alloc_idx(e) === i.U) {
        entries(i).valid := true.B
        entries(i).uop := io.enq(e).bits
        
        entries(i).rs1_ready := io.rs1_ready_in(e)
        entries(i).rs2_ready := io.rs2_ready_in(e)
        entries(i).rs3_ready := io.rs3_ready_in(e)
        
        for (w <- 0 until numWakeup) {
          when (io.wakeup(w).valid) {
            when (io.enq(e).bits.psrs1 === io.wakeup(w).pdest && io.enq(e).bits.psrs1 =/= 0.U) { entries(i).rs1_ready := true.B }
            when (io.enq(e).bits.psrs2 === io.wakeup(w).pdest && io.enq(e).bits.psrs2 =/= 0.U) { entries(i).rs2_ready := true.B }
            when (io.enq(e).bits.psrs3 === io.wakeup(w).pdest && io.enq(e).bits.psrs3 =/= 0.U) { entries(i).rs3_ready := true.B }
          }
        }
      }
    }
  }

  // Clear loadWaitBit when the store it is waiting for calculates its address
  when (io.store_resolved.valid) {
    for (i <- 0 until numEntries) {
      when (entries(i).valid && entries(i).uop.loadWaitBit && (entries(i).uop.waitForRobIdx === io.store_resolved.bits)) {
        entries(i).uop.loadWaitBit := false.B
      }
    }
  }

  when (io.redirect_valid) {
    for (i <- 0 until numEntries) {
      val entry_is_younger = robDist(entries(i).uop.robIdx) > robDist(io.redirect_robIdx)
      when (entry_is_younger) {
        entries(i).valid := false.B
      }
    }
  }

  // for (i <- 0 until numEntries) {
  //   when (entries(i).valid) {
  //     printf(p"  [IQ Entry $i]: pc=${Hexadecimal(entries(i).uop.uop.pc)} rs1_ready=${entries(i).rs1_ready} rs2_ready=${entries(i).rs2_ready} psrs1=${entries(i).uop.psrs1} psrs2=${entries(i).uop.psrs2} pdest=${entries(i).uop.pdest} snapIdx=${entries(i).uop.snapshotIdx}\n")
  //   }
  // }

  val deq1_valid = if (numDeq > 1) io.deq(1).valid else false.B
  val deq1_ready = if (numDeq > 1) io.deq(1).ready else false.B
  // printf(p"  [IQ STATE] is_empty_mask=${is_empty.asUInt} deq_val0=${io.deq(0).valid} deq_rdy0=${io.deq(0).ready} deq_val1=${deq1_valid} deq_rdy1=${deq1_ready}\n")
  // for (e <- 0 until numEnq) {
  //   when (io.enq(e).valid && io.enq(e).ready) {
  //     printf(p"    Enq $e: pc=${Hexadecimal(io.enq(e).bits.uop.pc)} alloc_idx=${alloc_idx(e)}\n")
  //   }
  // }
}
