package zaqal.backend.exu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FPU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1   = Input(UInt(fLen.W))
    val src2   = Input(UInt(fLen.W))
    val src3   = Input(UInt(fLen.W))
    val dec    = Input(new DecodeSignals)
    val result = Output(UInt(fLen.W))
  })

  val is_dp = io.dec.is_fp_double

  // --- 1. Single Precision Operands Unpack ---
  val rs1_sp = io.src1(31, 0)
  val rs2_sp = Mux(io.dec.is_fadd || io.dec.is_fsub, "h3f800000".U(32.W), io.src2(31, 0)) // 1.0f
  val rs3_sp = Mux(io.dec.is_fmul, 0.U(32.W), 
               Mux(io.dec.is_fadd || io.dec.is_fsub, io.src2(31, 0), io.src3(31, 0)))

  val sA_sp = rs1_sp(31); val eA_sp = Cat(0.U(1.W), rs1_sp(30, 23)).asSInt; val mA_sp = Cat(eA_sp =/= 0.S, rs1_sp(22, 0))
  val sB_sp = rs2_sp(31); val eB_sp = Cat(0.U(1.W), rs2_sp(30, 23)).asSInt; val mB_sp = Cat(eB_sp =/= 0.S, rs2_sp(22, 0))
  val sC_sp = rs3_sp(31); val eC_sp = Cat(0.U(1.W), rs3_sp(30, 23)).asSInt; val mC_sp = Cat(eC_sp =/= 0.S, rs3_sp(22, 0))

  val prod_m_sp = mA_sp * mB_sp // 48-bit significand (bit 46 is integer bit)
  val prod_e_sp = eA_sp + eB_sp - 127.S

  // --- 2. Double Precision Operands Unpack ---
  val rs1_dp = io.src1(63, 0)
  val rs2_dp = Mux(io.dec.is_fadd || io.dec.is_fsub, "h3ff0000000000000".U(64.W), io.src2(63, 0)) // 1.0d
  val rs3_dp = Mux(io.dec.is_fmul, 0.U(64.W),
               Mux(io.dec.is_fadd || io.dec.is_fsub, io.src2(63, 0), io.src3(63, 0)))

  val sA_dp = rs1_dp(63); val eA_dp = Cat(0.U(1.W), rs1_dp(62, 52)).asSInt; val mA_dp = Cat(eA_dp =/= 0.S, rs1_dp(51, 0))
  val sB_dp = rs2_dp(63); val eB_dp = Cat(0.U(1.W), rs2_dp(62, 52)).asSInt; val mB_dp = Cat(eB_dp =/= 0.S, rs2_dp(51, 0))
  val sC_dp = rs3_dp(63); val eC_dp = Cat(0.U(1.W), rs3_dp(62, 52)).asSInt; val mC_dp = Cat(eC_dp =/= 0.S, rs3_dp(51, 0))

  val prod_m_dp = mA_dp * mB_dp // 106-bit significand (bit 104 is integer bit)
  val prod_e_dp = eA_dp + eB_dp - 1023.S

  // --- 3. Unified Representation ---
  val sA = Mux(is_dp, sA_dp, sA_sp)
  val sB = Mux(is_dp, sB_dp, sB_sp)
  val sC = Mux(is_dp, sC_dp, sC_sp)
  val eC = Mux(is_dp, eC_dp, eC_sp)

  val prod_m_unified = Mux(is_dp, prod_m_dp, Cat(prod_m_sp, 0.U(58.W))) // 106 bits, integer bit at 104
  val prod_e = Mux(is_dp, prod_e_dp, prod_e_sp)
  val mC_unified = Mux(is_dp, mC_dp, Cat(mC_sp, 0.U(29.W)))             // 53 bits, integer bit at 52

  val prod_s   = sA ^ sB ^ (io.dec.is_fnmsub || io.dec.is_fnmadd)
  val addend_s = sC ^ (io.dec.is_fsub || io.dec.is_fmsub || io.dec.is_fnmadd)

  // --- 4. Alignment Stage ---
  val prod_m_ext_80 = Cat(prod_m_unified, 0.U(60.W)) // 166 bits, bit 104 becomes 164
  val mC_ext_80     = Cat(mC_unified,     0.U(112.W)) // 165 bits, bit 52 becomes 164

  val exp_diff = prod_e - eC
  val base_e = Mux(prod_e > eC, prod_e, eC)

  val op1_wide = Mux(prod_e >= eC, prod_m_ext_80 << 20, 
                 Mux(exp_diff < -150.S, 0.U, (prod_m_ext_80 << 20) >> (-exp_diff).asUInt))
  val op2_wide = Mux(eC >= prod_e, mC_ext_80 << 20,
                 Mux(exp_diff > 150.S, 0.U, (mC_ext_80 << 20) >> exp_diff.asUInt))

  // --- 5. Addition Stage ---
  val effective_sub = prod_s ^ addend_s
  val s_op1 = Cat(0.U(2.W), op1_wide).asSInt
  val s_op2 = Cat(0.U(2.W), op2_wide).asSInt
  
  val res_m_wide = Mux(effective_sub, s_op1 - s_op2, s_op1 + s_op2)
  
  // Sign of result
  val res_s = Mux(res_m_wide < 0.S, !prod_s, prod_s)
  val res_m_abs = res_m_wide.abs.asUInt

  // --- 6. Normalization Stage ---
  // Integer bit was at 184 (164 + 20)
  val wide_abs = res_m_abs.pad(256)               // 256 bits
  val lzc = PriorityEncoder(Reverse(wide_abs))      // 0 to 255
  val norm_m = (wide_abs << lzc)                   // Leading 1 at bit 255
  
  val exp_adj = (255.S - lzc.asSInt) - 184.S
  val final_e_val = base_e + exp_adj

  // Special Zero Case Detection
  val final_is_zero = (res_m_abs === 0.U)
  val final_s = Mux(final_is_zero, 0.U, res_s)

  // Double precision result
  val final_e_dp = Mux(final_is_zero, 0.U, 
                   Mux(final_e_val > 2046.S, 2047.U, 
                   Mux(final_e_val < 0.S, 0.U, final_e_val(10, 0))))
  val final_m_dp = Mux(final_is_zero, 0.U, norm_m(254, 203)) // 52 bits
  val res_f64    = Cat(final_s, final_e_dp, final_m_dp)

  // Single precision result
  val final_e_sp = Mux(final_is_zero, 0.U, 
                   Mux(final_e_val > 254.S, 255.U, 
                   Mux(final_e_val < 0.S, 0.U, final_e_val(7, 0))))
  val final_m_sp = Mux(final_is_zero, 0.U, norm_m(254, 232)) // 23 bits
  val res_f32    = Cat("hffffffff".U(32.W), final_s, final_e_sp, final_m_sp)

  io.result := Mux(is_dp, res_f64, res_f32)
}
