package zaqal.backend.dispatch

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
 * Decoupled Vector Dispatch Queue (VDQ) - Phase 9 (Day 21-25)
 *
 * Buffers renamed vector micro-ops between the Rename/Dispatch stage and the Vector
 * execution cluster. Isolates multicycle vector execution stalls from the scalar pipeline,
 * allowing scalar instructions (loop counters, branches, address calculations) to bypass
 * vector operations and execute out-of-order.
 */
class VectorDispatchQueue(val numEntries: Int = 16)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Enqueue from Dispatch (up to decodeWidth vector ops per cycle)
    val enq = Vec(decodeWidth, Flipped(Decoupled(new DecodedMicroOp)))

    // Dequeue to Vector Issue / Execution
    val deq = Decoupled(new DecodedMicroOp)

    // Redirection / Branch Recovery
    val redirect_valid        = Input(Bool())
    val redirect_is_exception = Input(Bool())
    val redirect_robIdx       = Input(UInt(log2Up(128).W))

    // Status
    val count     = Output(UInt(log2Up(numEntries + 1).W))
    val is_empty  = Output(Bool())
    val is_full   = Output(Bool())
  })

  class QueueEntry extends Bundle {
    val valid = Bool()
    val uop   = new DecodedMicroOp
  }

  val entries = RegInit(VecInit(Seq.fill(numEntries)(0.U.asTypeOf(new QueueEntry))))
  val headPtr = RegInit(0.U(log2Up(numEntries).W))
  val tailPtr = RegInit(0.U(log2Up(numEntries).W))
  val countReg = RegInit(0.U(log2Up(numEntries + 1).W))

  io.count    := countReg
  io.is_empty := countReg === 0.U
  io.is_full  := countReg === numEntries.U

  // 1. Dequeue Logic (Oldest vector uop at headPtr)
  val headEntry = entries(headPtr)
  io.deq.valid := headEntry.valid && (countReg > 0.U)
  io.deq.bits  := headEntry.uop

  val do_deq = io.deq.fire
  val next_headPtr = WireInit(headPtr)
  when(do_deq) {
    entries(headPtr).valid := false.B
    next_headPtr := Mux(headPtr === (numEntries - 1).U, 0.U, headPtr + 1.U)
    headPtr := next_headPtr
  }

  // 2. Parallel Enqueue Logic (from Dispatch lanes 0 until decodeWidth)
  val spaceAvailable = numEntries.U - countReg + Mux(do_deq, 1.U, 0.U)
  val enqFire = Wire(Vec(decodeWidth, Bool()))
  val enqOffset = Wire(Vec(decodeWidth, UInt(log2Up(decodeWidth + 1).W)))

  var curOffset = 0.U(log2Up(decodeWidth + 1).W)
  for (i <- 0 until decodeWidth) {
    enqOffset(i) := curOffset
    val canAccept = (spaceAvailable > curOffset)
    io.enq(i).ready := canAccept
    enqFire(i) := io.enq(i).fire

    curOffset = curOffset + Mux(io.enq(i).valid && canAccept, 1.U, 0.U)
  }

  val totalEnq = PopCount(enqFire)
  for (i <- 0 until decodeWidth) {
    when(enqFire(i)) {
      val writeIdx = (tailPtr + enqOffset(i)) % numEntries.U
      entries(writeIdx).valid := true.B
      entries(writeIdx).uop   := io.enq(i).bits
    }
  }

  when(totalEnq > 0.U) {
    tailPtr := (tailPtr + totalEnq) % numEntries.U
  }

  // 3. Redirection & Flush Logic
  val squashed = Wire(Vec(numEntries, Bool()))
  for (i <- 0 until numEntries) {
    val entry = entries(i)
    val entry_is_younger = (entry.uop.robIdx > io.redirect_robIdx)
    squashed(i) := io.redirect_valid && !io.redirect_is_exception && entry.valid && entry_is_younger
    when(squashed(i)) {
      entries(i).valid := false.B
    }
  }
  val numSquashed = PopCount(squashed)

  when(io.redirect_valid) {
    when(io.redirect_is_exception) {
      // Full flush on exception
      for (i <- 0 until numEntries) {
        entries(i).valid := false.B
      }
      headPtr  := 0.U
      tailPtr  := 0.U
      countReg := 0.U
    } .otherwise {
      // Squash younger instructions on branch mispredict
      val nextTail = Mux(tailPtr >= numSquashed, tailPtr - numSquashed, (numEntries.U + tailPtr) - numSquashed)
      tailPtr  := nextTail
      countReg := countReg + totalEnq - Mux(do_deq, 1.U, 0.U) - numSquashed
    }
  } .otherwise {
    countReg := countReg + totalEnq - Mux(do_deq, 1.U, 0.U)
  }
}
