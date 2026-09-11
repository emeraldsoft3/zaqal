package zaqal.backend.exu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FPMisc(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1    = Input(UInt(fLen.W))
    val src2    = Input(UInt(fLen.W))
    val rs1_int = Input(UInt(xLen.W))
    val dec     = Input(new DecodeSignals)
    val inst    = Input(UInt(32.W))
    
    val result_int = Output(UInt(xLen.W))
    val result_fp  = Output(UInt(fLen.W))
  })

  val is_dp = io.dec.is_fp_double
  val funct3 = io.inst(14, 12)
  val rs2_field = io.inst(24, 20)

  // 1. Unpack Single-Precision Operands
  val fA = io.src1(31, 0)
  val fB = io.src2(31, 0)

  val sA = fA(31)
  val eA = fA(30, 23)
  val mA = fA(22, 0)

  val sB = fB(31)
  val eB = fB(30, 23)
  val mB = fB(22, 0)

  // 2. Unpack Double-Precision Operands
  val fA_dp = io.src1(63, 0)
  val fB_dp = io.src2(63, 0)

  val sA_dp = fA_dp(63)
  val eA_dp = fA_dp(62, 52)
  val mA_dp = fA_dp(51, 0)

  val sB_dp = fB_dp(63)
  val eB_dp = fB_dp(62, 52)
  val mB_dp = fB_dp(51, 0)

  // 3. Classification Logic
  def classify_sp(f: UInt): UInt = {
    val s = f(31)
    val e = f(30, 23)
    val m = f(22, 0)

    val is_zero      = (e === 0.U) && (m === 0.U)
    val is_subnormal = (e === 0.U) && (m =/= 0.U)
    val is_inf       = (e === 255.U) && (m === 0.U)
    val is_nan       = (e === 255.U) && (m =/= 0.U)
    val is_snan      = is_nan && (m(22) === 0.U)
    val is_qnan      = is_nan && (m(22) === 1.U)
    val is_normal    = (e > 0.U) && (e < 255.U)

    Cat(
      is_qnan,           // bit 9
      is_snan,           // bit 8
      !s && is_inf,      // bit 7
      !s && is_normal,   // bit 6
      !s && is_subnormal,// bit 5
      !s && is_zero,     // bit 4
      s && is_zero,      // bit 3
      s && is_subnormal, // bit 2
      s && is_normal,    // bit 1
      s && is_inf        // bit 0
    )
  }

  def classify_dp(f: UInt): UInt = {
    val s = f(63)
    val e = f(62, 52)
    val m = f(51, 0)

    val is_zero      = (e === 0.U) && (m === 0.U)
    val is_subnormal = (e === 0.U) && (m =/= 0.U)
    val is_inf       = (e === 2047.U) && (m === 0.U)
    val is_nan       = (e === 2047.U) && (m =/= 0.U)
    val is_snan      = is_nan && (m(51) === 0.U)
    val is_qnan      = is_nan && (m(51) === 1.U)
    val is_normal    = (e > 0.U) && (e < 2047.U)

    Cat(
      is_qnan,
      is_snan,
      !s && is_inf,
      !s && is_normal,
      !s && is_subnormal,
      !s && is_zero,
      s && is_zero,
      s && is_subnormal,
      s && is_normal,
      s && is_inf
    )
  }

  val classA_sp = classify_sp(fA)
  val classA_dp = classify_dp(fA_dp)

  // 4. Sign Injection (FSGNJ, FSGNJN, FSGNJX)
  val res_sgnj_sp = Mux(funct3 === 0.U, Cat(sB, fA(30, 0)),
                    Mux(funct3 === 1.U, Cat(!sB, fA(30, 0)),
                    Cat(sA ^ sB, fA(30, 0))))

  val res_sgnj_dp = Mux(funct3 === 0.U, Cat(sB_dp, fA_dp(62, 0)),
                    Mux(funct3 === 1.U, Cat(!sB_dp, fA_dp(62, 0)),
                    Cat(sA_dp ^ sB_dp, fA_dp(62, 0))))

  // 5. Comparison Logic (FEQ, FLT, FLE)
  val is_nanA_sp = (eA === 255.U) && (mA =/= 0.U)
  val is_nanB_sp = (eB === 255.U) && (mB =/= 0.U)
  val both_zero_sp = (eA === 0.U && mA === 0.U) && (eB === 0.U && mB === 0.U)
  val raw_lt_sp = Mux(sA =/= sB, sA, Mux(sA, Cat(eB, mB) < Cat(eA, mA), Cat(eA, mA) < Cat(eB, mB)))
  val raw_eq_sp = (fA === fB) || both_zero_sp
  val feq_sp = raw_eq_sp && !is_nanA_sp && !is_nanB_sp
  val flt_sp = raw_lt_sp && !is_nanA_sp && !is_nanB_sp
  val fle_sp = (raw_lt_sp || raw_eq_sp) && !is_nanA_sp && !is_nanB_sp

  val is_nanA_dp = (eA_dp === 2047.U) && (mA_dp =/= 0.U)
  val is_nanB_dp = (eB_dp === 2047.U) && (mB_dp =/= 0.U)
  val both_zero_dp = (eA_dp === 0.U && mA_dp === 0.U) && (eB_dp === 0.U && mB_dp === 0.U)
  val raw_lt_dp = Mux(sA_dp =/= sB_dp, sA_dp, Mux(sA_dp, Cat(eB_dp, mB_dp) < Cat(eA_dp, mA_dp), Cat(eA_dp, mA_dp) < Cat(eB_dp, mB_dp)))
  val raw_eq_dp = (fA_dp === fB_dp) || both_zero_dp
  val feq_dp = raw_eq_dp && !is_nanA_dp && !is_nanB_dp
  val flt_dp = raw_lt_dp && !is_nanA_dp && !is_nanB_dp
  val fle_dp = (raw_lt_dp || raw_eq_dp) && !is_nanA_dp && !is_nanB_dp

  // 6. Min/Max
  val min_sp = Mux(is_nanA_sp && is_nanB_sp, "h7fc00000".U, Mux(is_nanA_sp, fB, Mux(is_nanB_sp, fA, Mux(raw_lt_sp, fA, fB))))
  val max_sp = Mux(is_nanA_sp && is_nanB_sp, "h7fc00000".U, Mux(is_nanA_sp, fB, Mux(is_nanB_sp, fA, Mux(raw_lt_sp, fB, fA))))

  val min_dp = Mux(is_nanA_dp && is_nanB_dp, "h7ff8000000000000".U, Mux(is_nanA_dp, fB_dp, Mux(is_nanB_dp, fA_dp, Mux(raw_lt_dp, fA_dp, fB_dp))))
  val max_dp = Mux(is_nanA_dp && is_nanB_dp, "h7ff8000000000000".U, Mux(is_nanA_dp, fB_dp, Mux(is_nanB_dp, fA_dp, Mux(raw_lt_dp, fB_dp, fA_dp))))

  // 7. Int to Float Conversions
  def i2f_sp(in: UInt, signed: Bool): UInt = {
    val is_zero = (in(31, 0) === 0.U)
    val abs_in = Mux(signed && in(31), (-in(31, 0).asSInt).asUInt, in(31, 0))
    val sign = signed && in(31)
    
    val lzc = PriorityEncoder(Reverse(abs_in(31, 0)))
    val norm_m = (abs_in << lzc)(31, 0)
    
    val exp = Mux(is_zero, 0.U, (127 + 31).U - lzc)
    val mantissa = norm_m(30, 8) // 23 bits
    
    Cat(sign, exp(7, 0), mantissa)
  }

  def i2f_dp(in: UInt, signed: Bool, is_64: Bool): UInt = {
    val raw_in = Mux(is_64, in, Mux(signed, in(31, 0).asSInt.asUInt, in(31, 0)))
    val is_neg = signed && Mux(is_64, raw_in(63), raw_in(31))
    val abs_in = Mux(is_neg, (-raw_in.asSInt).asUInt, raw_in)
    val is_zero = (abs_in === 0.U)
    
    val lzc = PriorityEncoder(Reverse(abs_in))
    val norm_m = (abs_in << lzc)(63, 0)
    
    val exp = Mux(is_zero, 0.U, (1023 + 63).U - lzc)
    val mantissa = norm_m(62, 11) // 52 bits
    Cat(is_neg, exp(10, 0), mantissa)
  }

  // 8. Float to Int Conversions
  def f2i_sp(f: UInt, signed: Bool): UInt = {
    val s = f(31)
    val e = f(30, 23).asSInt - 127.S
    val m = Cat(1.U(1.W), f(22, 0))
    
    val is_nan = (f(30, 23) === 255.U) && (f(22, 0) =/= 0.U)
    val is_inf = (f(30, 23) === 255.U) && (f(22, 0) === 0.U)
    
    val res_wide = Mux(e >= 23.S, m << (e - 23.S).asUInt, m >> (23.S - e).asUInt)
    val res_signed = Mux(s, (-res_wide.asSInt).asUInt, res_wide)
    
    val max_int = Mux(signed, "h7fffffff".U, "hffffffff".U)
    val min_int = Mux(signed, "h80000000".U, 0.U)
    val overflow = (e > 30.S) || (e === 30.S && (!signed || !s))
    
    Mux(is_nan, "h7fffffff".U,
    Mux(is_inf, Mux(s, min_int, max_int),
    Mux(overflow, Mux(s, min_int, max_int),
    res_signed(31, 0))))
  }

  def f2i_dp(f: UInt, signed: Bool, is_64: Bool): UInt = {
    val s = f(63)
    val e = f(62, 52).asSInt - 1023.S
    val m = Cat(1.U(1.W), f(51, 0))
    
    val is_nan = (f(62, 52) === 2047.U) && (f(51, 0) =/= 0.U)
    val is_inf = (f(62, 52) === 2047.U) && (f(51, 0) === 0.U)
    
    val res_wide = Mux(e >= 52.S, m << (e - 52.S).asUInt, m >> (52.S - e).asUInt)
    val res_signed = Mux(s, (-res_wide.asSInt).asUInt, res_wide)
    
    val max_int = Mux(is_64, Mux(signed, "h7fffffffffffffff".U(64.W), "hffffffffffffffff".U(64.W)),
                             Mux(signed, "h000000007fffffff".U(64.W), "h00000000ffffffff".U(64.W)))
    val min_int = Mux(is_64, Mux(signed, "h8000000000000000".U(64.W), 0.U(64.W)),
                             Mux(signed, "hffffffff80000000".U(64.W), 0.U(64.W)))
    
    val limit_exp = Mux(is_64, 62.S, 30.S)
    val overflow = (e > limit_exp) || (e === limit_exp && (!signed || !s))
    val normal_res = Mux(is_64, res_signed(63, 0), res_signed(31, 0).asSInt.asUInt)
    
    Mux(is_nan, max_int,
    Mux(is_inf, Mux(s, min_int, max_int),
    Mux(overflow, Mux(s, min_int, max_int),
    normal_res)))
  }

  // 9. Precision Conversion (FCVT.S.D and FCVT.D.S)
  val fcvt_s_d_res = {
    val s = io.src1(63)
    val e = io.src1(62, 52).asSInt - 1023.S
    val m = io.src1(51, 0)
    val is_zero = (io.src1(62, 52) === 0.U) && (m === 0.U)
    val is_nan  = (io.src1(62, 52) === 2047.U) && (m =/= 0.U)
    val is_inf  = (io.src1(62, 52) === 2047.U) && (m === 0.U)
    val new_e   = e + 127.S
    val s_res = Mux(is_zero, 0.U(32.W),
                Mux(is_nan, "h7fc00000".U(32.W),
                Mux(is_inf, Cat(s, "hff".U(8.W), 0.U(23.W)),
                Mux(new_e >= 255.S, Cat(s, "hff".U(8.W), 0.U(23.W)),
                Mux(new_e <= 0.S, 0.U(32.W),
                Cat(s, new_e(7, 0), m(51, 29)))))))
    Cat("hffffffff".U(32.W), s_res)
  }

  val fcvt_d_s_res = {
    val s = io.src1(31)
    val e = io.src1(30, 23).asSInt - 127.S
    val m = io.src1(22, 0)
    val is_zero = (io.src1(30, 23) === 0.U) && (m === 0.U)
    val is_nan  = (io.src1(30, 23) === 255.U) && (m =/= 0.U)
    val is_inf  = (io.src1(30, 23) === 255.U) && (m === 0.U)
    val new_e   = (e + 1023.S)(10, 0)
    Mux(is_zero, 0.U(64.W),
    Mux(is_nan, "h7ff8000000000000".U(64.W),
    Mux(is_inf, Cat(s, "h7ff".U(11.W), 0.U(52.W)),
    Cat(s, new_e, m, 0.U(29.W)))))
  }

  // 10. Output Selection
  val result_fp_wire = WireDefault(0.U(fLen.W))
  val result_int_wire = WireDefault(0.U(xLen.W))

  when(io.dec.is_fsgnj) {
    result_fp_wire := Mux(is_dp, res_sgnj_dp, Cat("hffffffff".U(32.W), res_sgnj_sp))
  } .elsewhen(io.dec.is_fminmax) {
    val sel_sp = Mux(funct3 === 0.U, min_sp, max_sp)
    val sel_dp = Mux(funct3 === 0.U, min_dp, max_dp)
    result_fp_wire := Mux(is_dp, sel_dp, Cat("hffffffff".U(32.W), sel_sp))
  } .elsewhen(io.dec.is_fcvt_i2f) {
    val is_signed = (rs2_field(0) === 0.U)
    val is_64     = (rs2_field(1) === 1.U)
    result_fp_wire := Mux(is_dp, i2f_dp(io.rs1_int, is_signed, is_64), Cat("hffffffff".U(32.W), i2f_sp(io.rs1_int, is_signed)))
  } .elsewhen(io.dec.is_fmv_w_x) {
    result_fp_wire := Cat("hffffffff".U(32.W), io.rs1_int(31, 0))
  } .elsewhen(io.dec.is_fmv_d_x) {
    result_fp_wire := io.rs1_int(63, 0)
  } .elsewhen(io.dec.is_fcvt_s_d) {
    result_fp_wire := fcvt_s_d_res
  } .elsewhen(io.dec.is_fcvt_d_s) {
    result_fp_wire := fcvt_d_s_res
  }

  when(io.dec.is_feq) {
    result_int_wire := Mux(is_dp, feq_dp, feq_sp)
  } .elsewhen(io.dec.is_flt) {
    result_int_wire := Mux(is_dp, flt_dp, flt_sp)
  } .elsewhen(io.dec.is_fle) {
    result_int_wire := Mux(is_dp, fle_dp, fle_sp)
  } .elsewhen(io.dec.is_fclass) {
    result_int_wire := Mux(is_dp, classA_dp, classA_sp)
  } .elsewhen(io.dec.is_fmv_x_w) {
    result_int_wire := fA.asSInt.asUInt // Sign-extend to xLen
  } .elsewhen(io.dec.is_fmv_x_d) {
    result_int_wire := fA_dp
  } .elsewhen(io.dec.is_fcvt_f2i) {
    val is_signed = (rs2_field(0) === 0.U)
    val is_64     = (rs2_field(1) === 1.U)
    result_int_wire := Mux(is_dp, f2i_dp(io.src1, is_signed, is_64), f2i_sp(fA, is_signed).asSInt.asUInt)
  }

  io.result_fp  := result_fp_wire
  io.result_int := result_int_wire
}
