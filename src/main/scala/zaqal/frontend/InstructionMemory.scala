package zaqal

import chisel3._
import chisel3.util._
import chisel3.util.experimental.loadMemoryFromFile

class InstructionMemory extends Module {
  val io = IO(new Bundle {
    val req  = Flipped(Decoupled(new FetchPacket)) 
    val resp = Decoupled(Vec(8, UInt(32.W)))
  })

  // 1. Define the Memory (1024 rows of 8 instructions)
  val mem = SyncReadMem(1024, Vec(8, UInt(32.W)))

  // 2. Load the Hex file 
  // Note: For Mill/Verilator, the path is relative to the project root
  loadMemoryFromFile(mem, "src/main/resources/program.hex")

  // 3. Logic for Reading
  val ren = io.req.fire
  // Align PC to the 32-byte block index
  // 0x8000_0000 >> 5 becomes the index for the first block
  val raddr = io.req.bits.pc(log2Up(1024 * 32) - 1, 5) 
  
  val outData = mem.read(raddr, ren)

  // 4. Fallback ROM (If loadMemoryFromFile fails in simulation, this ensures you see data)
  // This is a common "Safety Net" in high-end core development
  val romData = VecInit(Seq(
    "h00008137".U(32.W), // lui sp, 0x8
    "h00000113".U(32.W), // li sp, sp (placeholder)
    "h00000413".U(32.W), // li sp, sp (placeholder)
    "h00000413".U(32.W), // li sp, sp (placeholder)
    "h11111537".U(32.W), // lui a0, 0x11111
    "h1115051b".U(32.W), // addiw a0, a0, 273
    "h00010001".U(32.W), // nop
    "h00010001".U(32.W)  // nop
  ))

  // 5. Handshake & Pipelining
  io.req.ready := io.resp.ready
  
  // The data takes 1 cycle to arrive from the memory
  val validDelay = RegNext(io.req.fire, false.B)
  io.resp.valid := validDelay
  
  // If memory is empty (all zeros), use the ROM fallback for now so we can debug
  val isMemEmpty = outData.asUInt === 0.U
  io.resp.bits := Mux(isMemEmpty, romData, outData)
}