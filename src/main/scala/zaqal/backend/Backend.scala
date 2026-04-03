package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal.common._

class Backend(implicit p: ZaqalParams) extends Module {
  val io = IO(new Bundle {
    val fetchPacket = Flipped(Decoupled(new FetchPacket))
    val flush = Output(new PipelineFlushBus)
    val brpUpdate = Output(new BranchPredictionBus)
  })

  val decoder = Module(new Decoder)
  val alu = Module(new ALU)
  val bru = Module(new BRU)

  val uop = Reg(new MicroOp)
  val pc = Reg(UInt(p.xLen.W))

  io.fetchPacket.ready := true.B
  
  // Pipeline registers
  when(io.fetchPacket.fire) {
    uop := decoder.io.uop
    pc := io.fetchPacket.bits.pc
  }

  decoder.io.instr := io.fetchPacket.bits.instrs(0)

  alu.io.a := uop.data.src1
  alu.io.b := uop.data.src2
  alu.io.op := uop.ctrl.aluOp

  bru.io.a := uop.data.src1
  bru.io.b := uop.data.src2
  bru.io.op := uop.ctrl.bruOp

  io.flush.flush := bru.io.taken
  io.flush.targetPC := pc + 4.U // Displacement usually comes from immediate
  
  io.brpUpdate.taken := bru.io.taken
  io.brpUpdate.target := io.flush.targetPC
  io.brpUpdate.pc := pc
}
