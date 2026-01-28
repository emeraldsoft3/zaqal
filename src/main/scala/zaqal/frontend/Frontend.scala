package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class Frontend extends Module {
  val io = IO(new Bundle {
    val redirect    = Input(new BPURedirect)
    val fetchPacket = Decoupled(new FetchPacket)
  })

  val bpu  = Module(new BPU)
  val imem = Module(new InstructionMemory)
  val ftq  = Module(new FTQ)

  // Connection: BPU -> IMEM
  imem.io.req <> bpu.io.out
  
  // Connection: IMEM -> FTQ
  ftq.io.in <> imem.io.resp
  
  // Connection: FTQ -> Core (Backend)
  io.fetchPacket <> ftq.io.out

  // Global Redirect/Flush logic
  bpu.io.redirect := io.redirect
  ftq.io.flush    := io.redirect.valid
}