package zaqal.backend.fu.vector

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
 * Standard RVV 1.0 Element Width (SEW) Encoding
 */
object VSew {
  val e8  = 0.U(3.W) // 8-bit elements
  val e16 = 1.U(3.W) // 16-bit elements
  val e32 = 2.U(3.W) // 32-bit elements
  val e64 = 3.U(3.W) // 64-bit elements

  def isReserved(vsew: UInt): Bool = vsew > 3.U
}

/**
 * Standard RVV 1.0 Register Group Multiplier (LMUL) Encoding
 */
object VLmul {
  val m1  = 0.U(3.W) // LMUL = 1
  val m2  = 1.U(3.W) // LMUL = 2
  val m4  = 2.U(3.W) // LMUL = 4
  val m8  = 3.U(3.W) // LMUL = 8
  val mf2 = 7.U(3.W) // LMUL = 1/2
  val mf4 = 6.U(3.W) // LMUL = 1/4
  val mf8 = 5.U(3.W) // LMUL = 1/8
  val reserved = 4.U(3.W) // Reserved

  def isReserved(vlmul: UInt): Bool = vlmul === reserved
}

/**
 * RVV 1.0 Vector Type Bundle (vtype register content)
 * Format:
 * [63]: vill (illegal value flag)
 * [7]:  vma  (mask agnostic)
 * [6]:  vta  (tail agnostic)
 * [5:3]: vsew (selected element width)
 * [2:0]: vlmul (vector register group multiplier)
 */
class VType(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val vill  = Bool()
  val vma   = Bool()
  val vta   = Bool()
  val vsew  = UInt(3.W)
  val vlmul = UInt(3.W)

  def asUInt64: UInt = {
    Mux(vill,
      Cat(1.U(1.W), 0.U((xLen - 1).W)),
      Cat(0.U((xLen - 8).W), vma.asUInt, vta.asUInt, vsew, vlmul)
    )
  }
}

object VType {
  def fromUInt(u: UInt)(implicit p: Parameters): VType = {
    val res = Wire(new VType)
    res.vill  := u(p(ZaqalParamsKey).xLen - 1)
    res.vma   := u(7)
    res.vta   := u(6)
    res.vsew  := u(5, 3)
    res.vlmul := u(2, 0)
    res
  }

  def init(implicit p: Parameters): VType = {
    val res = Wire(new VType)
    res.vill  := true.B
    res.vma   := false.B
    res.vta   := false.B
    res.vsew  := 0.U
    res.vlmul := 0.U
    res
  }
}

/**
 * Combined Dynamic Vector Configuration State
 */
class VConfig(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val vtype = new VType
  val vl    = UInt(xLen.W)
  val vlmax = UInt(xLen.W)
}
