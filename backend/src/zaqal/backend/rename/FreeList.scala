package zaqal.backend.rename

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FreeListSnapshot(val ptrWidth: Int) extends Bundle {
  val headPtr = UInt(ptrWidth.W)
}

/**
  * FreeList module to manage physical registers.
  * Initially contains physical registers from numLogicalRegs to numPhyRegs - 1.
  */
class FreeList(val numPhyRegs: Int, val numLogicalRegs: Int)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Allocation Ports (Rename Stage)
    val allocateReq = Input(Vec(decodeWidth, Bool()))
    val allocateFire = Input(Vec(decodeWidth, Bool()))
    val allocatePhyReg = Output(Vec(decodeWidth, UInt(phyRegIdxWidth.W)))
    val canAllocate = Output(Bool())
    val doAllocate = Input(Bool()) // Signal that instructions actually passed rename

    // Freeing Ports (Commit Stage)
    val freeReq = Input(Vec(decodeWidth, Bool()))
    val freePhyReg = Input(Vec(decodeWidth, UInt(phyRegIdxWidth.W)))
    
    // Recovery
    val redirect = Input(Bool())
    val archHeadPtr = Input(UInt(log2Up(numPhyRegs - numLogicalRegs).W)) // From ROB/Commit
    // Checkpoint IO
    val useSnapshot    = Input(Bool())
    val snptEnq        = Input(Bool())
    val snptEnqIdx     = Input(UInt(log2Up(decodeWidth + 1).W))
    val snptDeqCount   = Input(UInt(log2Up(decodeWidth + 1).W))
    val snptFlushVec   = Input(Vec(renameSnapshotNum, Bool()))
    val snptRestoreIdx = Input(UInt(log2Up(renameSnapshotNum).W))
    val isFull         = Output(Bool())
  })

  val size = numPhyRegs - numLogicalRegs
  require(size > decodeWidth, "FreeList size must be greater than decode width")

  // The list of free physical registers
  val freeList = RegInit(VecInit(Seq.tabulate(size)(i => (i + numLogicalRegs).U(phyRegIdxWidth.W))))
  dontTouch(freeList)
  
  // Pointers for circular buffer
  val headPtr = RegInit(0.U(log2Up(size).W))   // Speculative allocation pointer
  val tailPtr = RegInit(0.U(log2Up(size).W))   // Reclaim/Free pointer (where new free regs are put)
  
  val snapshots = Module(new SnapshotGenerator(new FreeListSnapshot(log2Up(size))))

  def wrapAdd(ptr: UInt, add: UInt): UInt = {
    val next = ptr +& add
    Mux(next >= size.U, next - size.U, next)(log2Up(size) - 1, 0)
  }

  // Exact in-flight tracking: distance from tailPtr (last committed reclaim) to headPtr (latest speculative allocation)
  val inFlight = Mux(headPtr >= tailPtr, headPtr - tailPtr, size.U - (tailPtr - headPtr))
  val freeCount = size.U - inFlight

  // 1. Speculative Allocation
  val numAllocReq = PopCount(io.allocateReq)
  io.canAllocate := freeCount >= numAllocReq

  for (i <- 0 until decodeWidth) {
    val offset = PopCount(io.allocateReq.take(i))
    io.allocatePhyReg(i) := freeList(wrapAdd(headPtr, offset))
  }

  // 2. Architectural Freeing
  val effectiveFreeReq = Wire(Vec(decodeWidth, Bool()))
  for (i <- 0 until decodeWidth) {
    effectiveFreeReq(i) := io.freeReq(i) && (io.freePhyReg(i) =/= 0.U)
  }
  val numFree = PopCount(effectiveFreeReq)
  for (i <- 0 until decodeWidth) {
    val offset = PopCount(effectiveFreeReq.take(i))
    when (effectiveFreeReq(i)) {
      freeList(wrapAdd(tailPtr, offset)) := io.freePhyReg(i)
    }
  }

  val allocMask = (1.U(decodeWidth.W) << io.snptEnqIdx) - 1.U
  val numAllocPre = PopCount(io.allocateReq.asUInt & allocMask)
  val snpt_data = Wire(new FreeListSnapshot(log2Up(size)))
  snpt_data.headPtr := wrapAdd(headPtr, numAllocPre)

  snapshots.io.enq := io.snptEnq
  snapshots.io.enqData := snpt_data
  snapshots.io.deqCount := io.snptDeqCount
  snapshots.io.redirect := io.redirect
  snapshots.io.useSnapshot := io.useSnapshot
  snapshots.io.redirect_idx := io.snptRestoreIdx
  snapshots.io.flushVec := io.snptFlushVec
  io.isFull := snapshots.io.isFull

  // 3. State Update with Fast One-Hot Multiplexing (Mux1H)
  val nextTailPtr = wrapAdd(tailPtr, numFree)
  tailPtr := nextTailPtr
  when (io.redirect) {
    // Restore speculative headPtr from snapshot or reset to nextTailPtr
    val restoreOH = UIntToOH(io.snptRestoreIdx, renameSnapshotNum)
    val restoredSnpt = Mux1H(restoreOH, snapshots.io.snapshots)
    headPtr := Mux(io.useSnapshot, restoredSnpt.headPtr, nextTailPtr)
  } .otherwise {
    val numFiredReq = PopCount(io.allocateFire)
    val actualAlloc = Mux(io.doAllocate && io.canAllocate, numFiredReq, 0.U)
    headPtr := wrapAdd(headPtr, actualAlloc)
  }
}
