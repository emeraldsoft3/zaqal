package zaqal

import chisel3._
import chisel3.util._


class Core extends Module {
  // The "success" output is just a simple way to tell the testbench 
  // that the core is powered on and running without crashing.
  val io = IO(new Bundle {
    val success = Output(Bool())
  })

  val frontend = Module(new Frontend)
  val imem     = Module(new InstructionMemory)

  imem.io.req <> frontend.io.fetchOut
  imem.io.resp.ready := true.B

 

  when(imem.io.resp.fire) {
    printf("Zaqal IMEM Match! First Instruction in block: %x\n", imem.io.resp.bits(0))
  }

  when(frontend.io.fetchOut.fire) {
    // Print the PC in hex
    printf("Zaqal Fetched 8-wide block at PC: %x, Mask: %b\n", 
           frontend.io.fetchOut.bits.pc, 
           frontend.io.fetchOut.bits.mask)
  }

  // Inside ZaqalCore class:
val decoders = Seq.fill(8)(Module(new Decoder))

for (i <- 0 until 8) {
  decoders(i).io.inst := imem.io.resp.bits(i)
  
  when(imem.io.resp.fire && decoders(i).io.out.has_dest) {
    printf("Slot %d: Found instruction writing to Register x%d\n", i.U, decoders(i).io.out.dst_reg)
  }
}

  io.success := true.B
}