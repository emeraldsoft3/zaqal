package zaqal.backend.rename

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class SnapshotGeneratorIO[T <: Data](dataType: T)(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val enq = Input(Bool())
  val enqData = Input(dataType.cloneType)
  val deq = Input(Bool())
  val redirect = Input(Bool())
  val redirect_idx = Input(UInt(log2Up(renameSnapshotNum).W))
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

  // Recover enqPtr directly from the checkpoint index
  when(io.redirect) {
    snptEnqPtr := ptrAdd(io.redirect_idx, 1.U)
  }
}
