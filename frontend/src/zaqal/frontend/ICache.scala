package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class ICache(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val pc = Input(UInt(xLen.W))
    val insts = Output(Vec(fetchWidth, UInt(instBits.W)))
    val ready = Output(Bool())
  })


val program = VecInit(Seq(
  // === Day 22: Zbs Single-bit Manipulation Test ===
  "h00000513".U, // 00: li a0, 0
  "h28051593".U, // 04: bseti a1, a0, 0  (a1 = 1)
  "h28159613".U, // 08: bseti a2, a1, 1  (a2 = 3)
  "h29F51693".U, // 0C: bseti a3, a0, 63 (a3 = 0x8000000000000000)
  "h48061713".U, // 10: bclri a4, a2, 0  (a4 = 2)
  "h68171793".U, // 14: binvi a5, a4, 1  (a5 = 0)
  "h48161813".U, // 18: bexti a6, a2, 1  (a6 = 1)
  "h48061893".U, // 1C: bexti a7, a2, 0  (a7 = 1)
  "h00000013".U, // 20: NOP
  "h00000013".U  // 24: NOP
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


