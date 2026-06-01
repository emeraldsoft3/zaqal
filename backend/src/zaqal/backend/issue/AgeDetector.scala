package zaqal.backend.issue

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters

class AgeDetector(numEntries: Int, numEnq: Int, numDeq: Int)(implicit p: Parameters) extends Module {
  val io = IO(new Bundle {
    val enq = Vec(numEnq, Input(UInt(numEntries.W)))
    val canIssue = Vec(numDeq, Input(UInt(numEntries.W)))
    val out = Vec(numDeq, Output(UInt(numEntries.W)))
  })

  // age(i)(j): true if entry i is older than entry j
  val age = Seq.fill(numEntries)(Seq.fill(numEntries)(RegInit(false.B)))
  val nextAge = Seq.fill(numEntries)(Seq.fill(numEntries)(Wire(Bool())))

  def get_age(row: Int, col: Int): Bool = {
    if (row < col) age(row)(col)
    else if (row == col) true.B
    else !age(col)(row)
  }

  def isEnq(i: Int): Bool = {
    VecInit(io.enq.map(_(i))).asUInt.orR
  }

  def isEnqNport(i: Int, numPorts: Int = 0): Bool = {
    if (numPorts == 0) false.B
    else VecInit(io.enq.take(numPorts).map(_(i))).asUInt.orR
  }

  for ((row, i) <- nextAge.zipWithIndex) {
    for ((elem, j) <- row.zipWithIndex) {
      if (i == j) {
        elem := true.B
      } else if (i < j) {
        when (isEnq(i) && isEnq(j)) {
          val sel = io.enq.map(_(i))
          val result = (0 until numEnq).map(k => isEnqNport(j, k))
          elem := !Mux1H(sel, result)
        } .elsewhen (isEnq(i)) {
          // i enqueues now, so it is youngest
          elem := false.B
        } .elsewhen (isEnq(j)) {
          // j enqueues now, so i is older
          elem := true.B
        } .otherwise {
          elem := get_age(i, j)
        }
      } else {
        elem := !nextAge(j)(i)
      }
      age(i)(j) := Mux(isEnq(i) | isEnq(j), elem, age(i)(j))
    }
  }

  def getOldestCanIssue(get: (Int, Int) => Bool, canIssue: UInt): UInt = {
    VecInit((0 until numEntries).map(i => {
      (VecInit((0 until numEntries).map(j => get(i, j))).asUInt | ~canIssue).andR & canIssue(i)
    })).asUInt
  }

  io.out.zip(io.canIssue).foreach { case (out, canIssue) =>
    out := getOldestCanIssue(get_age, canIssue)
  }
}
