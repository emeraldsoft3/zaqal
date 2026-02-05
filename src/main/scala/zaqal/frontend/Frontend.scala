package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class Frontend extends Module {
  val io = IO(new Bundle {
    val redirect    = Input(new BPURedirect)
    val fetchPacket = Decoupled(new FetchPacket)
    val debug_ftq_valid = Output(Bool())
    val debug_ftq_flush = Output(Bool())
    val debug_ftq_pc    = Output(UInt(32.W))
    val debug_ftq_mask  = Output(UInt(8.W))
    val debug_ftq_insts = Output(Vec(8, UInt(32.W)))
    val debug_ftq_ready = Output(Bool())
    val debug_ftq_pred_target = Output(UInt(64.W))
    val debug_ftq_pred_taken  = Output(Bool())
    val debug_ftq_pred_slot   = Output(UInt(3.W))
  })

  val bpu  = Module(new BPU)
  val ftq  = Module(new FTQ)

  val program = VecInit(Seq(
    "h00100093".U, "h04000113".U, "h00000213".U, "h00120233".U,
    "h001002b3".U, "h00200313".U, "h0062d433".U, "h002404b3".U, // fixed h024 to h0024
    "h00929463".U, "h00120233".U, "h00120213".U, "h00120213".U,
    "h00120213".U, "h00120213".U, "h00120213".U, "h00120213".U,
    "h00120213".U, "h00120213".U, "h00120213".U, "h00120213".U,
    "h00120213".U, "h00120213".U, "h00120213".U, "h00120213".U,
    "h00120213".U, "h00120213".U, "h00108093".U, "hfe20ace3".U,
    "h00625513".U, "h0000006f".U // Added average and halt
  ))

  // Use the BPU's requested PC
  val s0_pc_index = bpu.io.out.bits.pc(7, 2)

  // Pass-through the BPU's metadata to the packet
  val packet = Wire(new FetchPacket)
  packet.pc         := bpu.io.out.bits.pc
  packet.mask       := bpu.io.out.bits.mask
  packet.prediction := bpu.io.out.bits.prediction
  
  for (i <- 0 until 8) {
    val idx = s0_pc_index + i.U
    packet.instructions(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

chisel3.dontTouch(packet)
  // Handshake
  ftq.io.in.valid  := bpu.io.out.valid
  ftq.io.in.bits   := packet
  bpu.io.out.ready := ftq.io.in.ready

  bpu.io.redirect  := io.redirect
  ftq.io.flush     := io.redirect.valid

  io.fetchPacket   <> ftq.io.out
  io.debug_ftq_valid := ftq.io.in.valid
  io.debug_ftq_flush := ftq.io.flush
  io.debug_ftq_pc    := ftq.io.in.bits.pc
  io.debug_ftq_mask  := ftq.io.in.bits.mask
  io.debug_ftq_insts := ftq.io.in.bits.instructions
  io.debug_ftq_ready := ftq.io.in.ready
  io.debug_ftq_pred_target := ftq.io.in.bits.prediction.target
  io.debug_ftq_pred_taken  := ftq.io.in.bits.prediction.taken
  io.debug_ftq_pred_slot   := ftq.io.in.bits.prediction.slot
}