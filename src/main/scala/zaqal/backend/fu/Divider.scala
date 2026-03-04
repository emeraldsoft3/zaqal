package zaqal.backend.fu

import chisel3._
import chisel3.util._
import zaqal.DecodeSignals

class Divider extends Module {
  val io = IO(new Bundle {
    val src1    = Input(UInt(64.W))
    val src2    = Input(UInt(64.W))
    val dec     = Input(new DecodeSignals)
    val fire    = Input(Bool())
    
    val ready   = Output(Bool())
    val result  = Output(UInt(64.W))
    val done    = Output(Bool())
  })

  val s_idle :: s_busy :: s_done :: Nil = Enum(3)
  val state = RegInit(s_idle)

  val DIV_LATENCY = 32
  val counter = RegInit(0.U(6.W))

  val op1 = RegInit(0.U(64.W))
  val op2 = RegInit(0.U(64.W))
  val res = RegInit(0.U(64.W))

  io.ready := (state === s_idle)
  io.done  := (state === s_done)
  io.result := res

  switch(state) {
    is(s_idle) {
      when(io.fire && io.dec.is_div) {
        op1     := io.src1
        op2     := io.src2
        counter := 0.U
        state   := s_busy
      }
    }
    is(s_busy) {
      counter := counter + 1.U
      when(counter === (DIV_LATENCY - 1).U) {
        val safe_rs2 = Mux(op2 === 0.U, 1.U(64.W), op2)
        res   := (op1.asSInt / safe_rs2.asSInt).asUInt
        state := s_done
      }
    }
    is(s_done) {
      state := s_idle
    }
  }
}
