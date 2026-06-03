package zaqal.backend.issue

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class IssueQueue(val numEntries: Int, val numEnq: Int, val numDeq: Int, val numWakeup: Int)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val enq = Vec(numEnq, Flipped(Decoupled(new DecodedMicroOp)))
    val deq = Vec(numDeq, Decoupled(new DecodedMicroOp))
    val wakeup = Vec(numWakeup, Input(new WakeupBus))
    val btb_redirect = Input(Bool())
    
    val rs1_ready_in = Vec(numEnq, Input(Bool()))
    val rs2_ready_in = Vec(numEnq, Input(Bool()))
    val rs3_ready_in = Vec(numEnq, Input(Bool()))
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

    for (w <- 0 until numWakeup) {
      when (io.wakeup(w).valid) {
        when (entries(i).uop.psrs1 === io.wakeup(w).pdest && entries(i).uop.psrs1 =/= 0.U) { woken_rs1(i) := true.B }
        when (entries(i).uop.psrs2 === io.wakeup(w).pdest && entries(i).uop.psrs2 =/= 0.U) { woken_rs2(i) := true.B }
        when (entries(i).uop.psrs3 === io.wakeup(w).pdest && entries(i).uop.psrs3 =/= 0.U) { woken_rs3(i) := true.B }
      }
    }
  }

  val can_issue = Wire(Vec(numEntries, Bool()))
  for (i <- 0 until numEntries) {
    can_issue(i) := entries(i).valid && woken_rs1(i) && woken_rs2(i) && woken_rs3(i)
  }

  val ageDetector = Module(new AgeDetector(numEntries, numEnq, numDeq))
  val enq_onehot = Wire(Vec(numEnq, UInt(numEntries.W)))
  for (e <- 0 until numEnq) enq_onehot(e) := 0.U
  ageDetector.io.enq := enq_onehot

  var current_can_issue = can_issue.asUInt
  val issue_onehot = Wire(Vec(numDeq, UInt(numEntries.W)))
  for (k <- 0 until numDeq) {
    ageDetector.io.canIssue(k) := current_can_issue
    issue_onehot(k) := ageDetector.io.out(k)
    val issue_idx = OHToUInt(issue_onehot(k))
    val issue_valid = issue_onehot(k).orR

    io.deq(k).valid := issue_valid
    io.deq(k).bits := entries(issue_idx).uop
    
    val deq_fire = io.deq(k).valid && io.deq(k).ready
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

  when (io.btb_redirect) {
    for (i <- 0 until numEntries) {
      entries(i).valid := false.B
    }
  }
}
