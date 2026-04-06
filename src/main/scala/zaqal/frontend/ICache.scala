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
  // === PACKET 1 (0x00 - 0x1c) ===
  // This packet will fill the IBUF immediately.
  "h00100093".U, // 00: addi x1, x0, 1
  "h00200093".U, // 04: addi x1, x0, 2
  "h00300093".U, // 08: addi x1, x0, 3
  "h00400093".U, // 0c: addi x1, x0, 4
  "h00500113".U, // 10: addi x2, x0, 5
  "h00600113".U, // 14: addi x2, x0, 6
  "h00700113".U, // 18: addi x2, x0, 7
  "h00800113".U, // 1c: addi x2, x0, 8

  // === PACKET 2 (0x20 - 0x3c) ===
  // While IBUF is busy dispatching Packet 1 (takes 8 cycles), 
  // Packet 2 will be fetched and MUST "skid" into the SkidBuffer.
  "h00900213".U, // 20: addi x4, x0, 9
  "h00a00213".U, // 24: addi x4, x0, 10
  "h00b00213".U, // 28: addi x4, x0, 11
  "h00c00213".U, // 2c: addi x4, x0, 12
  "h00d00293".U, // 30: addi x5, x0, 13
  "h00e00293".U, // 34: addi x5, x0, 14
  "h00f00293".U, // 38: addi x5, x0, 15
  "h01000293".U, // 3c: addi x5, x0, 16

  // === PACKET 3 (0x40 - 0x5c) ===
  // This third fetch will be blocked at the SkidBuffer entry, 
  // because slot0 (Packet 2) and slot1 (Packet 3) will be full.
  "h01100313".U, // 40: addi x6, x0, 17
  "h01200313".U, // 44: addi x6, x0, 18
  "h01300313".U, // 48: addi x6, x0, 19
  "h01400313".U, // 4c: addi x6, x0, 20
  
  // === HALT (0x50) ===
  "h0000006f".U, // 50: jal x0, 0          (Halt)
).padTo(256, "h00000013".U))


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(9, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}
