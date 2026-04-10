package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.common._

class Multiplier(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1   = Input(UInt(xLen.W))
    val src2   = Input(UInt(xLen.W))
    val dec    = Input(new DecodeSignals)
    val result = Output(UInt(xLen.W))
  })

  // Combinatorial Multiplier
  val mul_res = io.src1.asSInt * io.src2.asSInt
  val mulhsu_res = io.src1.asSInt * io.src2.asUInt.asSInt // Wait, this doesn't work for MULHSU easily in Chisel
  
  // High bit variants
  val full_mul_ss = io.src1.asSInt * io.src2.asSInt
  val full_mul_uu = io.src1 * io.src2
  val full_mul_su = io.src1.asSInt * io.src2.asSInt // Need to zero-extend src2 for su
  
  // Correct MULHSU approach:
  // src1 is signed, src2 is unsigned.
  // We can zero-extend src2 to xLen+1 bits and treat it as signed.
  val src1_s = io.src1.asSInt
  val src2_u = Cat(0.U(1.W), io.src2).asSInt
  val full_mul_hsu = src1_s * src2_u

  // MULW: 32-bit multiplication
  val mulw_res = (io.src1(31, 0).asSInt * io.src2(31, 0).asSInt)(31, 0)

  io.result := MuxCase(full_mul_ss(63, 0).asUInt, Seq(
    io.dec.is_mul    -> full_mul_ss(63, 0).asUInt,
    io.dec.is_mulh   -> full_mul_ss(127, 64).asUInt,
    io.dec.is_mulhsu -> full_mul_hsu(127, 64).asUInt,
    io.dec.is_mulhu  -> full_mul_uu(127, 64).asUInt,
    io.dec.is_mulw   -> Cat(Fill(32, mulw_res(31)), mulw_res) // Explicit sign-extension
  ))
}
