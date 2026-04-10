package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.common._

class Divider(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1    = Input(UInt(xLen.W))
    val src2    = Input(UInt(xLen.W))
    val dec     = Input(new DecodeSignals)
    val fire    = Input(Bool())
    
    val ready   = Output(Bool())
    val result  = Output(UInt(xLen.W))
    val done    = Output(Bool())
  })

  val s_idle :: s_busy :: s_done :: Nil = Enum(3)
  val state = RegInit(s_idle)

  val count    = RegInit(0.U(7.W))
  val divisor  = RegInit(0.U(xLen.W))
  val div_reg  = RegInit(0.U((2 * xLen + 1).W)) 
  
  val is_w_lat      = RegInit(false.B)
  val is_signed_lat = RegInit(false.B)
  val is_rem_op_lat = RegInit(false.B)
  val div_by_zero   = RegInit(false.B)
  val overflow      = RegInit(false.B)
  val dividend_sign = RegInit(false.B)
  val divisor_sign  = RegInit(false.B)
  val dividend_orig = RegInit(0.U(xLen.W))

  val res_reg = RegInit(0.U(xLen.W))

  io.ready := (state === s_idle)
  io.done  := (state === s_done)
  io.result := res_reg

  switch(state) {
    is(s_idle) {
      val is_div_any = io.dec.is_div || io.dec.is_divu || io.dec.is_rem || io.dec.is_remu ||
                       io.dec.is_divw || io.dec.is_divuw || io.dec.is_remw || io.dec.is_remuw
      when(io.fire && is_div_any) {
        val is_w = io.dec.is_divw || io.dec.is_divuw || io.dec.is_remw || io.dec.is_remuw
        val is_signed = io.dec.is_div || io.dec.is_rem || io.dec.is_divw || io.dec.is_remw
        val sign1 = Mux(is_w, io.src1(31), io.src1(xLen-1)) && is_signed
        val sign2 = Mux(is_w, io.src2(31), io.src2(xLen-1)) && is_signed
        val d1_abs = Mux(sign1, (-io.src1).asUInt, io.src1)
        val d2_abs = Mux(sign2, (-io.src2).asUInt, io.src2)
        val op1 = Mux(is_w, d1_abs(31, 0), d1_abs)
        val op2 = Mux(is_w, d2_abs(31, 0), d2_abs)

        dividend_orig := io.src1
        dividend_sign := sign1
        divisor_sign  := sign2
        is_w_lat      := is_w
        is_signed_lat := is_signed
        is_rem_op_lat := io.dec.is_rem || io.dec.is_remu || io.dec.is_remw || io.dec.is_remuw
        div_by_zero   := io.src2 === 0.U
        overflow      := is_signed && !is_w && (io.src1 === (1.U << (xLen-1)).asUInt) && (io.src2 === (-1.S(xLen.W).asUInt))
        
        divisor  := op2
        div_reg  := op1
        count    := Mux(is_w, 32.U, 64.U)
        state    := s_busy
      }
    }
    is(s_busy) {
      val next_div_reg = Cat(div_reg(2*xLen-1, 0), 0.U(1.W))
      val rem = next_div_reg(2*xLen, xLen)
      val quo = next_div_reg(xLen-1, 0)
      
      when(rem >= divisor) {
        div_reg := Cat(rem - divisor, quo | 1.U)
      } .otherwise {
        div_reg := next_div_reg
      }

      count := count - 1.U
      when(count === 1.U) {
        state := s_done
        // The values that will be in div_reg on the NEXT clock edge (the s_done cycle)
        val res_rem = Mux(rem >= divisor, rem - divisor, rem)
        val res_quo = Mux(rem >= divisor, quo | 1.U, quo)
        
        val q_signed = Mux(dividend_sign ^ divisor_sign, (-res_quo).asUInt, res_quo)
        val r_signed = Mux(dividend_sign, (-res_rem).asUInt, res_rem)
        
        val final_q = Mux(is_w_lat, Cat(Fill(32, q_signed(31)), q_signed(31, 0)), q_signed)
        val final_r = Mux(is_w_lat, Cat(Fill(32, r_signed(31)), r_signed(31, 0)), r_signed)

        res_reg := Mux(div_by_zero,   Mux(is_rem_op_lat, dividend_orig, -1.S(xLen.W).asUInt),
                   Mux(overflow,      Mux(is_rem_op_lat, 0.U, (1.U << (xLen-1)).asUInt),
                   Mux(is_rem_op_lat, final_r, final_q)))
      }
    }
    is(s_done) {
      state := s_idle
    }
  }
}
