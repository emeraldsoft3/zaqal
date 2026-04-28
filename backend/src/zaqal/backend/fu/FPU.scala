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
  val sA = rs1(31); val eA = Cat(0.U(1.W), rs1(30, 23)).asSInt; val mA = Cat(eA =/= 0.S, rs1(22, 0))
  val sB = rs2(31); val eB = Cat(0.U(1.W), rs2(30, 23)).asSInt; val mB = Cat(eB =/= 0.S, rs2(22, 0))
  val sC = rs3(31); val eC = Cat(0.U(1.W), rs3(30, 23)).asSInt; val mC = Cat(eC =/= 0.S, rs3(22, 0))

  // --- 2. Multiply Stage (A * B) ---
  val prod_m = mA * mB // 48-bit significand (bit 46 is the 1.x integer bit if normalized)
  val prod_e = (eA + eB - 127.S)
  val prod_s = sA ^ sB

  // --- 3. Alignment Stage (Align C to Product) ---
  // We use a wide internal format to handle alignment and normalization
  // Bit 80 is our reference integer bit (scaled 2^80)
  val prod_m_ext = Cat(0.U(1.W), prod_m, 0.U(33.W)) // 1 + 48 + 33 = 82 bits. Bit 46 becomes bit 79.
                                                    // Wait, 46 + 33 = 79. Let's make it 80.
  val prod_m_ext_80 = Cat(prod_m, 0.U(34.W))        // 48 + 34 = 82 bits. Bit 46 becomes bit 80.
  val mC_ext_80     = Cat(mC,     0.U(57.W))        // 24 + 57 = 81 bits. Bit 23 becomes bit 80.

  val exp_diff = prod_e - eC.asSInt
  val base_e = Mux(prod_e > eC.asSInt, prod_e, eC.asSInt)

  // Align operands to the base exponent
  // We'll use 128 bits for the shifted operands to be safe
  val op1_wide = Mux(prod_e >= eC.asSInt, prod_m_ext_80 << 20, 
                 Mux(exp_diff < -100.S, 0.U, (prod_m_ext_80 << 20) >> (-exp_diff).asUInt))
  val op2_wide = Mux(eC.asSInt >= prod_e, mC_ext_80 << 20,
                 Mux(exp_diff > 100.S, 0.U, (mC_ext_80 << 20) >> exp_diff.asUInt))

  // --- Addition Stage ---
  val effective_sub = prod_s ^ sC ^ io.dec.is_fsub
  // Use 130-bit SInt to avoid overflow and sign issues
  val s_op1 = Cat(0.U(2.W), op1_wide).asSInt
  val s_op2 = Cat(0.U(2.W), op2_wide).asSInt
  
  val res_m_wide = Mux(effective_sub, s_op1 - s_op2, s_op1 + s_op2)
  
  // Sign of result
  val res_s = Mux(res_m_wide < 0.S, !prod_s, prod_s)
  val res_m_abs = res_m_wide.abs.asUInt

  // --- 5. Normalization Stage ---
  // Leading 1 should ideally be at bit 100 (which was bit 80 << 20)
  val wide_abs = Cat(0.U(30.W), res_m_abs) // Padding to 128+ bits
  val lzc = lzc_helper(wide_abs) 
  val norm_m = (wide_abs(127, 0) << lzc) // Leading 1 at bit 127
  
  // Adjust exponent: If bit 127 is the 1, original position was (127 - lzc)
  // Target position was 100.
  val exp_adj = (127.S - lzc.asSInt) - 100.S
  val final_e_val = base_e + exp_adj

  // Special Zero Case Detection
  val final_is_zero = (res_m_abs === 0.U)
  val final_s = Mux(final_is_zero, 0.U, res_s)
  val final_e = Mux(final_is_zero, 0.U, 
                Mux(final_e_val > 254.S, 255.U, 
                Mux(final_e_val < 0.S, 0.U, final_e_val(7, 0))))
  val final_m = Mux(final_is_zero, 0.U, norm_m(126, 104)) // Extract 23 bits (127 implicit)

  val res_f32 = Cat(final_s, final_e, final_m)

  // Output selection and NaN-boxing
  io.result := Cat("hffffffff".U(32.W), res_f32)

  // Helper for LZC (Leading Zero Counter) on 128 bits
  def lzc_helper(in: UInt): UInt = {
    val padded = in(127, 0)
    PriorityEncoder(Reverse(padded))
  }
}
