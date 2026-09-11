package zaqal.backend.exu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FPDivider(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1    = Input(UInt(fLen.W))
    val src2    = Input(UInt(fLen.W))
    val dec     = Input(new DecodeSignals)
    val fire    = Input(Bool())
    val flush   = Input(Bool())
    
    val ready   = Output(Bool())
    val result  = Output(UInt(fLen.W))
    val done    = Output(Bool())
  })

  val s_idle :: s_busy :: s_done :: Nil = Enum(3)
  val state = RegInit(s_idle)

  // Registers for state tracking
  val is_sqrt_reg = RegInit(false.B)
  val is_dp_reg   = RegInit(false.B)
  val count       = RegInit(0.U(8.W))
  val res_s       = RegInit(false.B)
  val res_e       = RegInit(0.S(12.W))
  val res_m       = RegInit(0.U(52.W))

  // Division Registers (Restoring Divider)
  val div_reg     = RegInit(0.U(120.W))
  val divisor     = RegInit(0.U(64.W))

  // Square Root Registers
  val bit_reg     = RegInit(0.U(110.W))
  val D_reg       = RegInit(0.U(110.W))
  val Q_reg       = RegInit(0.U(110.W))

  io.ready := (state === s_idle)
  io.done  := (state === s_done)
  
  // Assemble final result
  val final_e_dp = Mux(res_e > 2046.S, 2047.U, 
                   Mux(res_e < 0.S, 0.U, res_e(10, 0)))
  val res_f64    = Cat(res_s, final_e_dp, res_m(51, 0))

  val final_e_sp = Mux(res_e > 254.S, 255.U, 
                   Mux(res_e < 0.S, 0.U, res_e(7, 0)))
  val res_f32    = Cat(res_s, final_e_sp, res_m(22, 0))
  val res_f32_boxed = Cat("hffffffff".U(32.W), res_f32)

  io.result := Mux(is_dp_reg, res_f64, res_f32_boxed)

  switch(state) {
    is(s_idle) {
      val is_div = io.dec.is_fdiv
      val is_sqrt = io.dec.is_fsqrt
      val is_dp = io.dec.is_fp_double
      
      when(io.fire && (is_div || is_sqrt) && !io.flush) {
        is_sqrt_reg := is_sqrt
        is_dp_reg   := is_dp

        // Unpack SP Operands
        val sA_sp = io.src1(31)
        val eA_sp = Cat(0.U(1.W), io.src1(30, 23)).asSInt
        val mA_sp = Cat(eA_sp =/= 0.S, io.src1(22, 0))
        
        val sB_sp = io.src2(31)
        val eB_sp = Cat(0.U(1.W), io.src2(30, 23)).asSInt
        val mB_sp = Cat(eB_sp =/= 0.S, io.src2(22, 0))

        // Unpack DP Operands
        val sA_dp = io.src1(63)
        val eA_dp = Cat(0.U(1.W), io.src1(62, 52)).asSInt
        val mA_dp = Cat(eA_dp =/= 0.S, io.src1(51, 0))
        
        val sB_dp = io.src2(63)
        val eB_dp = Cat(0.U(1.W), io.src2(62, 52)).asSInt
        val mB_dp = Cat(eB_dp =/= 0.S, io.src2(51, 0))

        when(is_sqrt) {
          when(is_dp) {
            val eA_unbiased = (eA_dp - 1023.S(32.W)).asSInt
            val is_odd = eA_unbiased(0)
            
            D_reg := Mux(is_odd, Cat(0.U(3.W), mA_dp, 0.U(54.W)), Cat(0.U(4.W), mA_dp, 0.U(53.W)))
            Q_reg := 0.U
            bit_reg := 1.U(110.W) << 106.U
            
            res_s := sA_dp
            res_e := (eA_unbiased >> 1).asSInt + 1023.S(32.W)
          } .otherwise {
            val eA_unbiased = (eA_sp - 127.S(32.W)).asSInt
            val is_odd = eA_unbiased(0)
            
            D_reg := Mux(is_odd, Cat(0.U(62.W), mA_sp << 24.U), Cat(0.U(62.W), mA_sp << 23.U))
            Q_reg := 0.U
            bit_reg := 1.U(110.W) << 46.U
            
            res_s := sA_sp
            res_e := (eA_unbiased >> 1).asSInt + 127.S(32.W)
          }
          state := s_busy
        } .otherwise { // FDIV
          when(is_dp) {
            res_s := sA_dp ^ sB_dp
            res_e := (eA_dp - eB_dp) + 1023.S(32.W)
            
            div_reg := Cat(0.U(67.W), mA_dp)
            divisor := Cat(0.U(11.W), mB_dp)
            count := 109.U // 53 cycles shift mA + 56 cycles precision
          } .otherwise {
            res_s := sA_sp ^ sB_sp
            res_e := (eA_sp - eB_sp) + 127.S(32.W)
            
            div_reg := Cat(0.U(96.W), mA_sp)
            divisor := Cat(0.U(40.W), mB_sp)
            count := 51.U // 24 cycles shift mA + 27 cycles precision
          }
          state := s_busy
        }
      }
    }
    
    is(s_busy) {
      when(is_sqrt_reg) {
        when(bit_reg =/= 0.U) {
          when(D_reg >= Q_reg + bit_reg) {
            D_reg := D_reg - (Q_reg + bit_reg)
            Q_reg := (Q_reg >> 1.U) + bit_reg
          } .otherwise {
            Q_reg := Q_reg >> 1.U
          }
          bit_reg := bit_reg >> 2.U
        } .otherwise {
          state := s_done
          when(is_dp_reg) {
            res_m := Q_reg(51, 0)
          } .otherwise {
            res_m := Cat(0.U(29.W), Q_reg(22, 0))
          }
        }
      } .otherwise { // FDIV
        when(count =/= 0.U) {
          val next_div_reg = Cat(div_reg(118, 0), 0.U(1.W))
          val rem = next_div_reg(119, 56)
          val quo = next_div_reg(55, 0)

          when(rem >= divisor) {
            div_reg := Cat(rem - divisor, quo | 1.U)
          } .otherwise {
            div_reg := next_div_reg
          }
          count := count - 1.U
        } .otherwise {
          state := s_done
          when(is_dp_reg) {
            val q_raw = div_reg(56, 0)
            when(q_raw(56)) {
              res_m := q_raw(55, 4)
            } .otherwise {
              res_m := q_raw(54, 3)
              res_e := res_e - 1.S
            }
          } .otherwise {
            val q_raw = div_reg(27, 0)
            when(q_raw(27)) {
              res_m := Cat(0.U(29.W), q_raw(26, 4))
            } .otherwise {
              res_m := Cat(0.U(29.W), q_raw(25, 3))
              res_e := res_e - 1.S
            }
          }
        }
      }
    }
    
    is(s_done) {
      state := s_idle
    }
  }

  when(io.flush) {
    state := s_idle
  }
}
