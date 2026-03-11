package zaqal.backend.fu

import chisel3._
import chisel3.util._

class Adder extends Module {
  val io = IO(new Bundle {
    val src1    = Input(UInt(64.W))
    val src2    = Input(UInt(64.W))
    val is_sub  = Input(Bool())
    val is_word = Input(Bool())
    val result  = Output(UInt(64.W))
  })

  val res = Mux(io.is_sub, io.src1 - io.src2, io.src1 + io.src2)
  
  // For word operations, we take the lower 32 bits and sign-extend to 64 bits
  io.result := Mux(io.is_word, Cat(Fill(32, res(31)), res(31, 0)), res)
}
