package zaqal.backend.fu

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

  // 1. Unpack Single-Precision Operands
  val fA = io.src1(31, 0)
  val fB = io.src2(31, 0)

  val sA = fA(31)
  val eA = fA(30, 23)
  val mA = fA(22, 0)

  val sB = fB(31)
  val eB = fB(30, 23)
  val mB = fB(22, 0)

  // 2. Classification Logic
  def classify(f: UInt): UInt = {
    val s = f(31)
    val e = f(30, 23)
    val m = f(22, 0)

    val is_zero     = (e === 0.U) && (m === 0.U)
    val is_subnormal = (e === 0.U) && (m =/= 0.U)
    val is_inf      = (e === 255.U) && (m === 0.U)
    val is_nan      = (e === 255.U) && (m =/= 0.U)
    val is_snan     = is_nan && (m(22) === 0.U)
    val is_qnan     = is_nan && (m(22) === 1.U)
    val is_normal   = (e > 0.U) && (e < 255.U)

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

  val classA = classify(fA)

  // 3. Sign Injection (FSGNJ, FSGNJN, FSGNJX)
  val funct3 = io.inst(14, 12)
  val res_sgnj = Mux(io.dec.is_fsgnj, 
                 Mux(funct3 === 0.U, Cat(sB, fA(30, 0)),        // FSGNJ
                 Mux(funct3 === 1.U, Cat(!sB, fA(30, 0)),       // FSGNJN
                 Cat(sA ^ sB, fA(30, 0)))), 0.U)                         // FSGNJX
  // Note: io.src1(14, 12) is the funct3 from the instruction. 
  // In our decoder, we might need to pass funct3 or just use separate flags.
  // Wait, DecodeSignals doesn't have funct3. I'll use the raw bits if needed or add it.
  // Actually, I can use io.dec.is_fsgnj and then check funct3 from a new input.
  // Let's assume we can get funct3 from somewhere. I'll add 'inst' to io.

  // 4. Comparison Logic (FEQ, FLT, FLE)
  val is_nanA = (eA === 255.U) && (mA =/= 0.U)
  val is_nanB = (eB === 255.U) && (mB =/= 0.U)
  
  val both_zero = (eA === 0.U && mA === 0.U) && (eB === 0.U && mB === 0.U)
  
  // Real comparison logic
  val raw_lt = Mux(sA =/= sB, sA, 
               Mux(sA, Cat(eB, mB) < Cat(eA, mA), Cat(eA, mA) < Cat(eB, mB)))
  val raw_eq = (fA === fB) || both_zero
  
  val feq = raw_eq && !is_nanA && !is_nanB
  val flt = raw_lt && !is_nanA && !is_nanB
  val fle = (raw_lt || raw_eq) && !is_nanA && !is_nanB

  // 5. Min/Max
  // If one is NaN, result is the other. If both are NaN, result is canonical NaN.
  val min_res = Mux(is_nanA && is_nanB, "h7fc00000".U,
                Mux(is_nanA, fB,
                Mux(is_nanB, fA,
                Mux(raw_lt, fA, fB))))
  val max_res = Mux(is_nanA && is_nanB, "h7fc00000".U,
                Mux(is_nanA, fB,
                Mux(is_nanB, fA,
                Mux(raw_lt, fB, fA))))

  // 6. Conversions (Simplified)
  // FCVT.S.W / FCVT.S.WU (Int to Float)
  // We'll use a simple normalization loop for now
  def i2f(in: UInt, signed: Bool): UInt = {
    val is_zero = (in === 0.U)
    val abs_in = Mux(signed && in(xLen-1), (-in.asSInt).asUInt, in)
    val sign = signed && in(xLen-1)
    
    val lzc = PriorityEncoder(Reverse(abs_in(31, 0))) // Only handle 32-bit for now
    val shift = lzc
    val norm_m = (abs_in << shift)(31, 0)
    
    val exp = Mux(is_zero, 0.U, (127 + 31).U - lzc)
    val mantissa = norm_m(30, 8) // Take 23 bits after implicit 1
    
    Cat(sign, exp(7, 0), mantissa)
  }

  // FCVT.W.S / FCVT.WU.S (Float to Int)
  def f2i(f: UInt, signed: Bool): UInt = {
    val s = f(31)
    val e = f(30, 23).asSInt - 127.S
    val m = Cat(1.U(1.W), f(22, 0))
    
    val is_nan = (f(30, 23) === 255.U) && (f(22, 0) =/= 0.U)
    val is_inf = (f(30, 23) === 255.U) && (f(22, 0) === 0.U)
    
    // Shift mantissa based on exponent
    // Mantissa is 2^0, 2^-1, ... 2^-23. So multiply by 2^e.
    // Result bit 0 is 2^0. m is effectively m_val / 2^23.
    // So res = m_val * 2^(e-23)
    val res_wide = Mux(e >= 23.S, m << (e - 23.S).asUInt, m >> (23.S - e).asUInt)
    
    val res_signed = Mux(s, (-res_wide.asSInt).asUInt, res_wide)
    
    // Handle overflow and special cases
    val max_int = Mux(signed, "h7fffffff".U, "hffffffff".U)
    val min_int = Mux(signed, "h80000000".U, 0.U)
    
    val overflow = (e > 30.S) || (e === 30.S && (!signed || !s))
    
    Mux(is_nan, "h7fffffff".U,
    Mux(is_inf, Mux(s, min_int, max_int),
    Mux(overflow, Mux(s, min_int, max_int),
    res_signed(31, 0))))
  }

  // 7. Final Results Selection
  val rs2 = io.inst(24, 20)
  // Wait, Execute.scala passes io.in.bits.inst_raw to decoder. I should pass it here too.

  val result_fp_wire = WireDefault(0.U(32.W))
  io.result_int := 0.U

  when(io.dec.is_fsgnj) {
    result_fp_wire := res_sgnj
  } .elsewhen(io.dec.is_fminmax) {
    result_fp_wire := Mux(funct3 === 0.U, min_res, max_res)
  } .elsewhen(io.dec.is_fcvt_i2f) {
    result_fp_wire := i2f(io.rs1_int, rs2(0)) // rs2(0) for signed/unsigned in FCVT
  } .elsewhen(io.dec.is_fmv_w_x) {
    result_fp_wire := io.rs1_int(31, 0)
  }

  when(io.dec.is_feq) {
    io.result_int := feq
  } .elsewhen(io.dec.is_flt) {
    io.result_int := flt
  } .elsewhen(io.dec.is_fle) {
    io.result_int := fle
  } .elsewhen(io.dec.is_fclass) {
    io.result_int := classA
  } .elsewhen(io.dec.is_fmv_x_w) {
    io.result_int := fA.asSInt.asUInt // Sign-extend to xLen
  } .elsewhen(io.dec.is_fcvt_f2i) {
    io.result_int := f2i(fA, rs2(0) === 0.U) // rs2(0)=0 for W (signed), 1 for WU (unsigned)
  }

  // NaN-boxing for FP results
  io.result_fp := Cat("hffffffff".U(32.W), result_fp_wire)
}
