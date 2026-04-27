package zaqal.backend.fu

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

  // --- 1. Architectural Operand Mapping (XiangShan/Rocket Style) ---
  val rs1 = io.src1(31, 0)
  val rs2 = Mux(io.dec.is_fadd || io.dec.is_fsub, "h3f800000".U, io.src2(31, 0)) // 1.0f for add/sub
  val rs3 = Mux(io.dec.is_fmul, 0.U, 
            Mux(io.dec.is_fadd || io.dec.is_fsub, io.src2(31, 0), io.src3(31, 0)))

  // Unpack A, B, C
  val sA = rs1(31); val eA = rs1(30, 23); val mA = Cat(eA =/= 0.U, rs1(22, 0))
  val sB = rs2(31); val eB = rs2(30, 23); val mB = Cat(eB =/= 0.U, rs2(22, 0))
  val sC = rs3(31); val eC = rs3(30, 23); val mC = Cat(eC =/= 0.U, rs3(22, 0))

  // --- 2. Multiply Stage (A * B) ---
  val prod_m = mA * mB // 48-bit significand (bit 46 is the 1.x integer bit if normalized)
  val prod_e = (eA.asSInt + eB.asSInt - 127.S)
  val prod_s = sA ^ sB

  // --- 3. Alignment Stage (Align C to Product) ---
  val exp_diff = prod_e - eC.asSInt
  
  // Internal data path width (Significand + guard/sticky bits)
  val mC_ext = Cat(mC, 0.U(50.W))
  val prod_m_ext = Cat(prod_m, 0.U(26.W))
  
  // Shift C to match the product's exponent
  val mC_align = Mux(exp_diff > 60.S, 0.U,
                 Mux(exp_diff < -60.S, mC_ext << 60, 
                 Mux(exp_diff > 0.S, mC_ext >> exp_diff.asUInt, mC_ext << (-exp_diff).asUInt)))

  // --- 4. Addition Stage ---
  val effective_sub = prod_s ^ sC ^ io.dec.is_fsub
  val res_m_wide = Mux(effective_sub, prod_m_ext.asSInt - mC_align.asSInt, prod_m_ext.asSInt + mC_align.asSInt)
  val res_s = Mux(res_m_wide < 0.S, !prod_s, prod_s)
  val res_m_abs = res_m_wide.abs.asUInt

  // --- 5. Normalization Stage (Leading Zero Counter) ---
  // We look for the first '1' and shift the mantissa/exponent accordingly
  val lead_zero = PriorityEncoder(Reverse(res_m_abs))
  val shift_val = lzc_helper(res_m_abs)
  val norm_m = (res_m_abs << shift_val)
  
  // Adjust exponent: Base exponent is the larger of (prod_e, eC)
  val base_e = Mux(prod_e > eC.asSInt, prod_e, eC.asSInt)
  val final_e_val = (base_e + 24.S - shift_val.asSInt)

  // Special Zero Case Detection
  val final_is_zero = (res_m_abs === 0.U)
  val final_s = Mux(final_is_zero, sA & sC, res_s)
  val final_e = Mux(final_is_zero, 0.U, final_e_val(7, 0))
  val final_m = Mux(final_is_zero, 0.U, norm_m(73, 51)) // Extract 23 bits

  val res_f32 = Cat(final_s, final_e, final_m)

  // Output selection and NaN-boxing
  io.result := Cat("hffffffff".U(32.W), res_f32)

  // Helper for LZC (Leading Zero Counter)
  def lzc_helper(in: UInt): UInt = {
    val reverse_in = Reverse(in)
    PriorityEncoder(reverse_in)
  }
}
