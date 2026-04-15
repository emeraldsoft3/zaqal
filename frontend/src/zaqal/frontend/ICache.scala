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
  // === Day 20: Zba Address Generation Test ===
  "h00000013".U, // 00: NOP
  "h00500513".U, // 04: li   a0, 5                    (rs1 for 64-bit tests)
  "h10000593".U, // 08: li   a1, 0x100                (rs2 = base address)
  "hFFF00613".U, // 0C: li   a2, -1                   (a2 = 0xFFFFFFFFFFFFFFFF)
  "h02061613".U, // 10: slli a2, a2, 32               (a2 = 0xFFFFFFFF00000000)
  "h00366613".U, // 14: ori  a2, a2, 3                (a2 = 0xFFFFFFFF00000003)
  // --- 64-bit SHxADD tests (rs1=a0=5, rs2=a1=0x100) ---
  "h20B522B3".U, // 18: sh1add  t0, a0, a1            (t0 = 0x100 + (5 << 1) = 0x10A)
  "h20B54333".U, // 1C: sh2add  t1, a0, a1            (t1 = 0x100 + (5 << 2) = 0x114)
  "h20B563B3".U, // 20: sh3add  t2, a0, a1            (t2 = 0x100 + (5 << 3) = 0x128)
  // --- .UW tests (rs1=a2=0xFFFFFFFF00000003, rs2=a1=0x100) ---
  "h20B62E3B".U, // 24: sh1add.uw t3, a2, a1          (t3 = 0x100 + (zext32(3) << 1) = 0x106)
  "h20B64EBB".U, // 28: sh2add.uw t4, a2, a1          (t4 = 0x100 + (zext32(3) << 2) = 0x10C)
  "h20B66F3B".U, // 2C: sh3add.uw t5, a2, a1          (t5 = 0x100 + (zext32(3) << 3) = 0x118)
  "h00000013".U  // 30: NOP
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


