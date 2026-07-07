package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

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
    val snptDeq        = Input(Bool())
    val snptFlushVec   = Input(Vec(renameSnapshotNum, Bool()))
    val snptRestoreIdx = Input(UInt(log2Up(renameSnapshotNum).W))
  })

  val size = numPhyRegs - numLogicalRegs
  require(size > decodeWidth, "FreeList size must be greater than decode width")

  // The list of free physical registers
  val freeList = RegInit(VecInit(Seq.tabulate(size)(i => (i + numLogicalRegs).U(phyRegIdxWidth.W))))
  dontTouch(freeList)
  
  // Pointers for circular buffer
  val headPtr = RegInit(0.U(log2Up(size).W))   // Speculative allocation pointer
  val tailPtr = RegInit(0.U(log2Up(size).W))   // Reclaim/Free pointer (where new free regs are put)
  
  // Available count tracking
  val freeCount = RegInit(size.U(log2Up(size + 1).W))

  val snapshots = Module(new SnapshotGenerator(UInt(log2Up(size).W)))

  def wrapAdd(ptr: UInt, add: UInt): UInt = {
    val next = ptr +& add
    Mux(next >= size.U, next - size.U, next)
  }

  // 1. Speculative Allocation
  val numAllocReq = PopCount(io.allocateReq)
  io.canAllocate := freeCount >= numAllocReq

  for (i <- 0 until decodeWidth) {
    val offset = PopCount(io.allocateReq.take(i))
    // We always output the candidates, but they are only "taken" if doAllocate is high
    io.allocatePhyReg(i) := freeList(wrapAdd(headPtr, offset))
  }

  // 2. Architectural Freeing
  val numFree = PopCount(io.freeReq)
  for (i <- 0 until decodeWidth) {
    val offset = PopCount(io.freeReq.take(i))
    when (io.freeReq(i)) {
      freeList(wrapAdd(tailPtr, offset)) := io.freePhyReg(i)
    }
  }

  val allocMask = (1.U(decodeWidth.W) << io.snptEnqIdx) - 1.U
  val snpt_head_ptr = wrapAdd(headPtr, PopCount(io.allocateReq.asUInt & allocMask))
  snapshots.io.enq := io.snptEnq
  snapshots.io.enqData := snpt_head_ptr
  snapshots.io.deq := io.snptDeq
  snapshots.io.redirect := io.redirect && io.useSnapshot
  snapshots.io.flushVec := io.snptFlushVec

  // 3. State Update
  when (io.redirect) {
    // Restore speculative state from architectural state or snapshot
    val targetHeadPtr = Mux(io.useSnapshot, snapshots.io.snapshots(io.snptRestoreIdx), io.archHeadPtr)
    headPtr := targetHeadPtr
    // Recalculate freeCount based on distance between tailPtr and archHeadPtr
    val dist = Mux(tailPtr === targetHeadPtr,
                   size.U,
                   Mux(tailPtr > targetHeadPtr, 
                       tailPtr - targetHeadPtr, 
                       size.U - (targetHeadPtr - tailPtr)))
    freeCount := dist 
  } .otherwise {
    val numFiredReq = PopCount(io.allocateFire)
    val actualAlloc = Mux(io.doAllocate && io.canAllocate, numFiredReq, 0.U)
    headPtr := wrapAdd(headPtr, actualAlloc)
    tailPtr := wrapAdd(tailPtr, numFree)
    freeCount := freeCount - actualAlloc + numFree
  }

  // Debug
  // assert(freeCount <= size.U, "FreeList overflow")
}
