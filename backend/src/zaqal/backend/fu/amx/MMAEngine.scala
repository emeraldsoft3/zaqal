package zaqal.backend.fu.amx

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

object MMAPrecision {
  val INT8 = 0.U(2.W)
  val BF16 = 1.U(2.W)
  val FP32 = 2.U(2.W)
}

/**
 * Matrix Multiply-Accumulate (MMA) Engine (Phase 9, Day 6-12)
 *
 * Hardware Acceleration for GEMM: C += A * B
 * Supports:
 * 1. INT8: 16x16 matrix multiply with 32-bit internal accumulators,
 *          saturating back to 8-bit output per element.
 * 2. BF16: 8x8 matrix multiply with FP32 internal accumulation,
 *          rounded back to BF16 output per element.
 * 3. FP32: 4x4 matrix multiply with native FP32 accumulation.
 */
class MMAEngine(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val start       = Input(Bool())
    val prec        = Input(UInt(2.W)) // MMAPrecision
    val active_rows = Input(UInt(5.W)) // 1 to 16

    // 2D Matrix Inputs from TileRegFile
    val matrix_a    = Input(Vec(16, UInt(128.W)))
    val matrix_b    = Input(Vec(16, UInt(128.W)))
    val matrix_c    = Input(Vec(16, UInt(128.W))) // Current Tile C contents for accumulation

    // Row-level Writeback to TileRegFile
    val write_en    = Output(Bool())
    val write_row   = Output(UInt(4.W))
    val write_data  = Output(UInt(128.W))

    val busy        = Output(Bool())
    val done        = Output(Bool())
  })

  def bf16_to_fp32(bf: UInt): UInt = Cat(bf(15, 0), 0.U(16.W))
  def fp32_to_bf16(fp: UInt): UInt = {
    val lsb = fp(16)
    val round_bit = fp(15)
    val sticky = fp(14, 0).orR
    val round_up = round_bit && (sticky || lsb)
    (fp(31, 16) + round_up.asUInt)(15, 0)
  }

  // Combinational FP32 MAC function: result = c + a * b
  def fp32_mac(a: UInt, b: UInt, c: UInt): UInt = {
    val s_a = a(31); val e_a = a(30, 23); val m_a = Cat(e_a =/= 0.U, a(22, 0))
    val s_b = b(31); val e_b = b(30, 23); val m_b = Cat(e_b =/= 0.U, b(22, 0))
    val a_zero = (e_a === 0.U)
    val b_zero = (e_b === 0.U)
    val prod_zero = a_zero || b_zero

    val prod_s = s_a ^ s_b
    val prod_m = m_a * m_b // 48 bits (bit 47 is high integer bit)
    val norm = prod_m(47)
    val prod_e = e_a +& e_b - 127.U + norm.asUInt
    val final_prod_exp = Mux(prod_zero, 0.U(8.W), prod_e(7, 0))
    val final_prod_mant = Mux(norm, prod_m(46, 24), prod_m(45, 23))
    val prod = Cat(prod_s && !prod_zero, final_prod_exp, final_prod_mant)

    val s_c = c(31); val e_c = c(30, 23); val m_c = Cat(e_c =/= 0.U, c(22, 0))
    val c_zero = (e_c === 0.U)

    val a_ge_b = (final_prod_exp > e_c) || ((final_prod_exp === e_c) && (final_prod_mant >= m_c))
    val (s_l, e_l, m_l, s_s, e_s, m_s) = (
      Mux(a_ge_b, prod_s, s_c),
      Mux(a_ge_b, final_prod_exp, e_c),
      Mux(a_ge_b, final_prod_mant, m_c),
      Mux(a_ge_b, s_c, prod_s),
      Mux(a_ge_b, e_c, final_prod_exp),
      Mux(a_ge_b, m_c, final_prod_mant)
    )
    val exp_diff = e_l - e_s
    val m_s_shifted = m_s >> Mux(exp_diff > 24.U, 24.U, exp_diff)
    val same_sign = (s_l === s_s)
    val m_sum = Mux(same_sign, Cat(0.U(1.W), m_l) +& m_s_shifted, Cat(0.U(1.W), m_l) -& m_s_shifted)
    val carry = m_sum(24)
    val final_exp = Mux(carry, e_l + 1.U, e_l)
    val final_m = Mux(carry, m_sum(23, 1), m_sum(22, 0))

    Mux(prod_zero, c, Mux(c_zero, prod, Cat(s_l, final_exp(7, 0), final_m(22, 0))))
  }

  // Accumulator arrays
  // INT8: 16x16 signed 32-bit accumulators
  val acc_i8 = Reg(Vec(16, Vec(16, SInt(32.W))))
  // FP32 & BF16: 8x8 FP32 accumulators
  val acc_fp = Reg(Vec(8, Vec(8, UInt(32.W))))

  val s_idle :: s_compute :: s_writeback :: s_done :: Nil = Enum(4)
  val state = RegInit(s_idle)

  val r_step      = RegInit(0.U(5.W))
  val r_wb_row    = RegInit(0.U(4.W))
  val r_prec      = RegInit(0.U(2.W))
  val r_num_steps = RegInit(16.U(5.W))
  val r_num_rows  = RegInit(16.U(5.W))

  // Defaults
  io.write_en   := false.B
  io.write_row  := 0.U
  io.write_data := 0.U
  io.busy       := (state =/= s_idle) && (state =/= s_done)
  io.done       := (state === s_done)

  // Static byte unpacking for Matrix A and Matrix B (INT8)
  val k_i8 = r_step(3, 0)
  val matrix_a_bytes = VecInit((0 until 16).map(i => VecInit((0 until 16).map(b => io.matrix_a(i)(b * 8 + 7, b * 8).asSInt))))
  val a_col_i8 = VecInit((0 until 16).map(i => matrix_a_bytes(i)(k_i8)))
  val b_row_bits = io.matrix_b(k_i8)
  val b_row_i8 = VecInit((0 until 16).map(j => b_row_bits(j * 8 + 7, j * 8).asSInt))

  // Static word unpacking for BF16 and FP32
  val k_fp = r_step(2, 0)
  val matrix_a_words_bf16 = VecInit((0 until 8).map(i => VecInit((0 until 8).map(w => io.matrix_a(i)(w * 16 + 15, w * 16)))))
  val matrix_a_words_fp32 = VecInit((0 until 4).map(i => VecInit((0 until 4).map(w => io.matrix_a(i)(w * 32 + 31, w * 32)))))
  val b_row_fp_bits = io.matrix_b(k_fp.pad(4))
  val b_words_bf16 = VecInit((0 until 8).map(j => b_row_fp_bits(j * 16 + 15, j * 16)))
  val b_words_fp32 = VecInit((0 until 4).map(j => b_row_fp_bits(j * 32 + 31, j * 32)))

  switch(state) {
    is(s_idle) {
      when(io.start) {
        r_prec := io.prec
        val steps = Mux(io.prec === MMAPrecision.INT8, io.active_rows,
                    Mux(io.prec === MMAPrecision.BF16, 8.U, 4.U))
        r_num_steps := steps
        r_num_rows  := steps
        r_step      := 0.U
        r_wb_row    := 0.U

        // Initialize accumulators from existing matrix_c
        when(io.prec === MMAPrecision.INT8) {
          for (i <- 0 until 16) {
            val c_row = io.matrix_c(i)
            for (j <- 0 until 16) {
              acc_i8(i)(j) := c_row(j * 8 + 7, j * 8).asSInt
            }
          }
        }.elsewhen(io.prec === MMAPrecision.BF16) {
          for (i <- 0 until 8) {
            val c_row = io.matrix_c(i)
            for (j <- 0 until 8) {
              acc_fp(i)(j) := bf16_to_fp32(c_row(j * 16 + 15, j * 16))
            }
          }
        }.otherwise { // FP32
          for (i <- 0 until 4) {
            val c_row = io.matrix_c(i)
            for (j <- 0 until 4) {
              acc_fp(i)(j) := c_row(j * 32 + 31, j * 32)
            }
          }
        }
        state := s_compute
      }
    }

    is(s_compute) {
      when(r_prec === MMAPrecision.INT8) {
        for (i <- 0 until 16) {
          val a_val = a_col_i8(i)
          for (j <- 0 until 16) {
            val b_val = b_row_i8(j)
            acc_i8(i)(j) := acc_i8(i)(j) + (a_val * b_val)
          }
        }
      }.elsewhen(r_prec === MMAPrecision.BF16) {
        for (i <- 0 until 8) {
          val a_bf = matrix_a_words_bf16(i)(k_fp)
          val a_fp = bf16_to_fp32(a_bf)
          for (j <- 0 until 8) {
            acc_fp(i)(j) := fp32_mac(a_fp, bf16_to_fp32(b_words_bf16(j)), acc_fp(i)(j))
          }
        }
      }.otherwise { // FP32
        for (i <- 0 until 4) {
          val a_fp = matrix_a_words_fp32(i)(k_fp(1, 0))
          for (j <- 0 until 4) {
            acc_fp(i)(j) := fp32_mac(a_fp, b_words_fp32(j), acc_fp(i)(j))
          }
        }
      }

      when(r_step === (r_num_steps - 1.U)) {
        state    := s_writeback
        r_wb_row := 0.U
      }.otherwise {
        r_step := r_step + 1.U
      }
    }

    is(s_writeback) {
      io.write_en  := true.B
      io.write_row := r_wb_row

      when(r_prec === MMAPrecision.INT8) {
        val row_bytes = VecInit((0 until 16).map { j =>
          val sval = acc_i8(r_wb_row)(j)
          val sat = Mux(sval > 127.S, 127.S(8.W), Mux(sval < -128.S, -128.S(8.W), sval(7, 0).asSInt)).asUInt
          sat
        })
        io.write_data := Cat(row_bytes.reverse)
      }.elsewhen(r_prec === MMAPrecision.BF16) {
        val row_words = VecInit((0 until 8).map { j =>
          fp32_to_bf16(acc_fp(r_wb_row(2, 0))(j))
        })
        io.write_data := Cat(row_words.reverse)
      }.otherwise { // FP32
        val row_words = VecInit((0 until 4).map { j =>
          acc_fp(r_wb_row(2, 0))(j)
        })
        io.write_data := Cat(row_words.reverse)
      }

      when(r_wb_row === (r_num_rows - 1.U)) {
        state := s_done
      }.otherwise {
        r_wb_row := r_wb_row + 1.U
      }
    }

    is(s_done) {
      state := s_idle
    }
  }
}
