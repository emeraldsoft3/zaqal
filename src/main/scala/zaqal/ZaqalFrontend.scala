package zaqal

import chisel3._
import chisel3.util._

class ZaqalFrontend extends Module {
  val io = IO(new Bundle {
    val fetchOut = Decoupled(new ZaqalFetchPacket)
  })

  val pcReg = RegInit("h8000_0000".U(64.W)) // Standard RISC-V start address
  
  // Create a Queue with 8 entries to buffer our 8-wide blocks
  val ftq = Module(new Queue(new ZaqalFetchPacket, 8))

 
  // Logic: Always push a new 8-instruction block if there is room
  ftq.io.enq.valid := true.B
  ftq.io.enq.bits.pc     := pcReg
  ftq.io.enq.bits.mask   := "b1111_1111".U 
  
  // FIX: You must initialize these or Chisel will complain!
  ftq.io.enq.bits.taken  := false.B        // No branch predicted yet
  ftq.io.enq.bits.target := 0.U            // No target yet
  // When the queue accepts the data (fire), move to the next 32-byte block
  when(ftq.io.enq.fire) {
    pcReg := pcReg + 32.U // 8 instructions * 4 bytes = 32
  }

  io.fetchOut <> ftq.io.deq
}