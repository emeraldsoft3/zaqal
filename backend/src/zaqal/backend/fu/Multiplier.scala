package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class Multiplier(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1   = Input(UInt(xLen.W))
    val src2   = Input(UInt(xLen.W))
    val dec    = Input(new DecodeSignals)
    val result = Output(UInt(xLen.W))
  })

  // Stage 1 Registers: Latching inputs
  val r_src1 = RegNext(io.src1)
  val r_src2 = RegNext(io.src2)
  val r_dec  = Reg(new DecodeSignals)
  r_dec := io.dec

  // Stage 2 Logic: Perform multiplication on Stage 1 registered inputs
  val full_mul_ss = r_src1.asSInt * r_src2.asSInt
  val full_mul_uu = r_src1 * r_src2
  
  val src1_s = r_src1.asSInt
  val src2_u = Cat(0.U(1.W), r_src2).asSInt
  val full_mul_hsu = src1_s * src2_u

  val mulw_res = (r_src1(31, 0).asSInt * r_src2(31, 0).asSInt)(31, 0)

  // Stage 2 Registers: Latching results
  val r_full_mul_ss = RegNext(full_mul_ss)
  val r_full_mul_uu = RegNext(full_mul_uu)
  val r_full_mul_hsu = RegNext(full_mul_hsu)
  val r_mulw_res = RegNext(mulw_res)
  val r_dec_stage2 = RegNext(r_dec)

  // Output selection based on Stage 2 registered control signals
  io.result := MuxCase(r_full_mul_ss(63, 0).asUInt, Seq(
    r_dec_stage2.is_mul    -> r_full_mul_ss(63, 0).asUInt,
    r_dec_stage2.is_mulh   -> r_full_mul_ss(127, 64).asUInt,
    r_dec_stage2.is_mulhsu -> r_full_mul_hsu(127, 64).asUInt,
    r_dec_stage2.is_mulhu  -> r_full_mul_uu(127, 64).asUInt,
    r_dec_stage2.is_mulw   -> Cat(Fill(32, r_mulw_res(31)), r_mulw_res) // Explicit sign-extension
  ))
}
