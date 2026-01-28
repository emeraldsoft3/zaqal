package zaqal

import chisel3._
import chisel3.util._
import zaqal.frontend._
import zaqal.backend._
import utility.GTimer

class Core extends Module {
  val io = IO(new Bundle {
    val success = Output(Bool())
  })

  // 1. Instantiate the two major halves of the CPU
  val frontend = Module(new Frontend)
  val backend  = Module(new Backend)

  // 2. The "Golden Loop": Redirects flow from Backend back to BPU
  // This allows the 'JAL' instruction to actually change the PC
  frontend.io.redirect := backend.io.redirect

  // 3. The Instruction Flow: Connect Frontend (FTQ) to Backend (Backend)
  backend.io.issue <> frontend.io.fetchPacket

  when(!frontend.io.fetchPacket.ready) {
     // This would print if the backend was refusing instructions
     // printf("[%d] CORE STALL: Backend not ready\n", GTimer())
  }

  // 4. Global Status
  io.success := true.B
}