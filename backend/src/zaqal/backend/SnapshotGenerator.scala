package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class SnapshotGeneratorIO[T <: Data](dataType: T)(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val enq = Input(Bool())
  val enqData = Input(dataType.cloneType)
  val deq = Input(Bool())
  val redirect = Input(Bool())
  val flushVec = Input(Vec(renameSnapshotNum, Bool()))
  val snapshots = Output(Vec(renameSnapshotNum, dataType.cloneType))
  val enqPtr = Output(UInt(log2Up(renameSnapshotNum).W))
  val deqPtr = Output(UInt(log2Up(renameSnapshotNum).W))
  val valids = Output(Vec(renameSnapshotNum, Bool()))
}

class SnapshotGenerator[T <: Data](dataType: T)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new SnapshotGeneratorIO(dataType))

  val snapshots = Reg(Vec(renameSnapshotNum, dataType.cloneType))
  val snptEnqPtr = RegInit(0.U(log2Up(renameSnapshotNum).W))
  val snptDeqPtr = RegInit(0.U(log2Up(renameSnapshotNum).W))
  val snptValids = RegInit(VecInit(Seq.fill(renameSnapshotNum)(false.B)))

  for (i <- 0 until renameSnapshotNum) {
    io.snapshots(i) := Mux(io.enq && (snptEnqPtr === i.U), io.enqData, snapshots(i))
  }
  io.enqPtr := snptEnqPtr
  io.deqPtr := snptDeqPtr
  io.valids := snptValids

  def ptrAdd(ptr: UInt, add: UInt): UInt = {
    val next = ptr +& add
    Mux(next >= renameSnapshotNum.U, next - renameSnapshotNum.U, next)
  }

  val isFull = snptValids(snptEnqPtr) && (snptEnqPtr === snptDeqPtr)
  val isEmpty = !snptValids(snptDeqPtr)

  when(!isFull && io.enq) {
    snapshots(snptEnqPtr) := io.enqData
    snptValids(snptEnqPtr) := true.B
    snptEnqPtr := ptrAdd(snptEnqPtr, 1.U)
  }

  when(!io.redirect && io.deq) {
    snptValids(snptDeqPtr) := false.B
    snptDeqPtr := ptrAdd(snptDeqPtr, 1.U)
  }

  // Flushing logic
  for (i <- 0 until renameSnapshotNum) {
    when(io.flushVec(i)) {
      snptValids(i) := false.B
    }
  }

  // Recover enqPtr when a redirect flushes valid entries
  when((io.flushVec.asUInt & snptValids.asUInt).orR) {
    val candidates = Wire(Vec(renameSnapshotNum, UInt(log2Up(renameSnapshotNum).W)))
    val qualified = Wire(Vec(renameSnapshotNum, Bool()))
    
    for (i <- 0 until renameSnapshotNum) {
      candidates(i) := ptrAdd(snptDeqPtr, i.U)
    }
    
    qualified(0) := !snptValids(candidates(0)) || io.flushVec(candidates(0))
    for (i <- 1 until renameSnapshotNum) {
      val thiz = candidates(i)
      val last = candidates(i-1)
      qualified(i) := snptValids(last) && (!snptValids(thiz) || io.flushVec(thiz))
    }
    
    val defaultVal = candidates(renameSnapshotNum - 1)
    val muxCases = qualified.zip(candidates).dropRight(1).map { case (q, c) => q -> c }
    snptEnqPtr := MuxCase(defaultVal, muxCases)
  }
}
