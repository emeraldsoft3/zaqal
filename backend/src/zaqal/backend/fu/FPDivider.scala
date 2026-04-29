package zaqal.backend.fu

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
    
    val ready   = Output(Bool())
    val result  = Output(UInt(fLen.W))
    val done    = Output(Bool())
  })

  val s_idle :: s_busy :: s_done :: Nil = Enum(3)
  val state = RegInit(s_idle)

  // Registers for state tracking
  val is_sqrt_reg = RegInit(false.B)
  val count       = RegInit(0.U(6.W))
  val res_s       = RegInit(false.B)
  val res_e       = RegInit(0.S(10.W))
  val res_m       = RegInit(0.U(23.W))

  // Division Registers (Restoring Divider)
  val div_reg     = RegInit(0.U(65.W))
  val divisor     = RegInit(0.U(32.W))

  // Square Root Registers
  val bit_reg     = RegInit(0.U(48.W))
  val D_reg       = RegInit(0.U(48.W))
  val Q_reg       = RegInit(0.U(48.W))

  io.ready := (state === s_idle)
  io.done  := (state === s_done)
  
  // Assemble final result
  val final_e = Mux(res_e > 254.S, 255.U, 
                Mux(res_e < 0.S, 0.U, res_e(7, 0)))
  val res_f32 = Cat(res_s, final_e, res_m)
  io.result := Cat("hffffffff".U(32.W), res_f32) // NaN-boxing

  switch(state) {
    is(s_idle) {
      val is_div = io.dec.is_fdiv
      val is_sqrt = io.dec.is_fsqrt
      
      when(io.fire && (is_div || is_sqrt)) {
        is_sqrt_reg := is_sqrt
        
        // Unpack Operands
        val sA = io.src1(31)
        val eA = Cat(0.U(1.W), io.src1(30, 23)).asSInt
        val mA = Cat(eA =/= 0.S, io.src1(22, 0))
        
        val sB = io.src2(31)
        val eB = Cat(0.U(1.W), io.src2(30, 23)).asSInt
        val mB = Cat(eB =/= 0.S, io.src2(22, 0))

        when(is_sqrt) {
          val eA_unbiased = eA - 127.S
          val is_odd = eA_unbiased(0)
          
          D_reg := Mux(is_odd, mA << 24.U, mA << 23.U)
          Q_reg := 0.U
          bit_reg := 1.U << 46.U
          
          res_s := sA
          res_e := (eA_unbiased >> 1) + 127.S
          state := s_busy
        } .otherwise { // FDIV
          res_s := sA ^ sB
          res_e := eA - eB + 127.S
          
          div_reg := mA << 27.U
          divisor := mB
          count := 27.U
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
          // Extract 23 bits (bits 22:0 of Q_reg, assuming leading 1 is at bit 23)
          res_m := Q_reg(22, 0)
        }
      } .otherwise { // FDIV
        when(count =/= 0.U) {
          val next_div_reg = Cat(div_reg(63, 0), 0.U(1.W))
          val rem = next_div_reg(64, 32)
          val quo = next_div_reg(31, 0)

          when(rem >= divisor) {
            div_reg := Cat(rem - divisor, quo | 1.U)
          } .otherwise {
            div_reg := next_div_reg
          }
          count := count - 1.U
        } .otherwise {
          state := s_done
          // Extract quotient and normalize
          val q_raw = div_reg(26, 0)
          val bit26 = q_raw(26)
          val bit25 = q_raw(25)
          
          when(bit26) {
            res_m := q_raw(25, 3)
          } .otherwise {
            res_m := q_raw(24, 2)
            res_e := res_e - 1.S
          }
        }
      }
    }
    
    is(s_done) {
      state := s_idle
    }
  }
}
