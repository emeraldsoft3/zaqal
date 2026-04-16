package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class Bitmanip(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1      = Input(UInt(xLen.W))
    val src2      = Input(UInt(xLen.W))
    val is_clz    = Input(Bool())
    val is_ctz    = Input(Bool())
    val is_cpop   = Input(Bool())
    val is_clzw   = Input(Bool())
    val is_ctzw   = Input(Bool())
    val is_cpopw  = Input(Bool())
    val is_rev8   = Input(Bool())
    val is_orc_b  = Input(Bool())
    val is_sextb  = Input(Bool())
    val is_sexth  = Input(Bool())
    val is_zexth  = Input(Bool())
    val is_min    = Input(Bool())
    val is_max    = Input(Bool())
    val is_minu   = Input(Bool())
    val is_maxu   = Input(Bool())
    val is_bset   = Input(Bool())
    val is_bseti  = Input(Bool())
    val is_bclr   = Input(Bool())
    val is_bclri  = Input(Bool())
    val is_binv   = Input(Bool())
    val is_binvi  = Input(Bool())
    val is_bext   = Input(Bool())
    val is_bexti  = Input(Bool())
    val result    = Output(UInt(xLen.W))
  })

  // 64-bit logic
  val clz_64  = Mux(io.src1.orR, PriorityEncoder(Reverse(io.src1)), 64.U)
  val ctz_64  = Mux(io.src1.orR, PriorityEncoder(io.src1), 64.U)
  val cpop_64 = PopCount(io.src1)

  // 32-bit (Word) logic
  val src1_w   = io.src1(31, 0)
  val clz_32   = Mux(src1_w.orR, PriorityEncoder(Reverse(src1_w)), 32.U)
  val ctz_32   = Mux(src1_w.orR, PriorityEncoder(src1_w), 32.U)
  val cpop_32  = PopCount(src1_w)

  // Zbb logic
  val rev8_res = Cat((0 until 8).reverse.map(i => io.src1(8*i+7, 8*i)))
  val orc_b_res = Cat((0 until 8).reverse.map(i => Fill(8, io.src1(8*i+7, 8*i).orR)))
  val sextb_res = Cat(Fill(xLen-8, src1_w(7)), src1_w(7, 0))
  val sexth_res = Cat(Fill(xLen-16, src1_w(15)), src1_w(15, 0))
  val zexth_res = Cat(0.U((xLen-16).W), src1_w(15, 0))

  val min_res  = Mux(io.src1.asSInt < io.src2.asSInt, io.src1, io.src2)
  val max_res  = Mux(io.src1.asSInt > io.src2.asSInt, io.src1, io.src2)
  val minu_res = Mux(io.src1 < io.src2, io.src1, io.src2)
  val maxu_res = Mux(io.src1 > io.src2, io.src1, io.src2)

  // Zbs logic
  val shamt = io.src2(5, 0)
  val bset_res = io.src1 | (1.U << shamt)
  val bclr_res = io.src1 & ~(1.U << shamt)
  val binv_res = io.src1 ^ (1.U << shamt)
  val bext_res = (io.src1 >> shamt) & 1.U

  io.result := MuxCase(0.U, Seq(
    io.is_clz   -> clz_64,
    io.is_ctz   -> ctz_64,
    io.is_cpop  -> cpop_64,
    io.is_clzw  -> clz_32,
    io.is_ctzw  -> ctz_32,
    io.is_cpopw -> cpop_32,
    io.is_rev8  -> rev8_res,
    io.is_orc_b -> orc_b_res,
    io.is_sextb -> sextb_res,
    io.is_sexth -> sexth_res,
    io.is_zexth -> zexth_res,
    io.is_min   -> min_res,
    io.is_max   -> max_res,
    io.is_minu  -> minu_res,
    io.is_maxu  -> maxu_res,
    (io.is_bset || io.is_bseti) -> bset_res,
    (io.is_bclr || io.is_bclri) -> bclr_res,
    (io.is_binv || io.is_binvi) -> binv_res,
    (io.is_bext || io.is_bexti) -> bext_res
  ))
}
