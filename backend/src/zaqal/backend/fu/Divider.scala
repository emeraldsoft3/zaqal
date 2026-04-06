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

  val DIV_LATENCY = 32
  val counter = RegInit(0.U(6.W))

  val op1 = RegInit(0.U(xLen.W))
  val op2 = RegInit(0.U(xLen.W))
  val res = RegInit(0.U(xLen.W))

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
        val safe_rs2 = Mux(op2 === 0.U, 1.U(xLen.W), op2)
        res   := (op1.asSInt / safe_rs2.asSInt).asUInt
        state := s_done
      }
    }
    is(s_done) {
      state := s_idle
    }
  }
}
