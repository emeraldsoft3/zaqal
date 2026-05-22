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

  // Program Loader: Reads hex from the file specified in parameters
  def loadHex(path: String): Seq[UInt] = {
    println(s"[ICache] FPU TEST MODE: Using hardcoded FP program.")
    if (false) { // Disabled for USER verification (Easier to edit here!)
      val source = scala.io.Source.fromFile(path)
      val lines = source.getLines()
        .map(_.split("//")(0).trim) // Remove comments
        .filter(_.nonEmpty)
      val insts = lines.map(l => s"h$l".U(32.W)).toSeq
      source.close()
      println(s"[ICache] Loaded ${insts.length} instructions from $path")
      insts
    } else {
      println(s"[ICache] Warning: Using Custom Dispatch Verification Program.")
      Seq(
        "h00b00093".U, // 0x00: addi x1, x0, 11   (Setup x1. Executed! -> Routed to [ALU])
        "h00100193".U, // 0x04: addi x3, x0, 1    (Unique ADDI - replacing NOP)
        "h00200213".U, // 0x08: addi x4, x0, 2    (Unique ADDI - replacing NOP)
        "h00002103".U, // 0x0c: lw x2, 0(x0)      (Load from memory. Executed! -> Routed to [MEM])
        "h00300293".U, // 0x10: addi x5, x0, 3    (Unique ADDI - replacing NOP)
        "h00400313".U, // 0x14: addi x6, x0, 4    (Unique ADDI - replacing NOP)
        "h00000c63".U, // 0x18: beq x0, x0, 24    (Branch. Executed! Predicted NOT TAKEN, actually TAKEN to 0x30 -> Routed to [BRU])
        "h00500393".U, // 0x1c: addi x7, x0, 5    (Unique ADDI - replacing NOP)
        "h00600413".U, // 0x20: addi x8, x0, 6    (Unique ADDI - replacing NOP)
        "h003100d3".U, // 0x24: fadd.s f1, f2, f3 (FPU op. Speculative path - fetched, classified, then flushed -> Routed to [FPU])
        "h00700493".U, // 0x28: addi x9, x0, 7    (Unique ADDI - replacing NOP)
        "h00800513".U, // 0x2c: addi x10, x0, 8   (Unique ADDI - replacing NOP)
        "h00102223".U, // 0x30: sw x1, 4(x0)      (Store memory. Executed post-redirect! -> Routed to [MEM])
        "h00900593".U, // 0x34: addi x11, x0, 9   (Unique ADDI - replacing NOP)
        "h00a00613".U, // 0x38: addi x12, x0, 10  (Unique ADDI - replacing NOP)
        "h00310253".U, // 0x3c: fadd.s f4, f5, f6 (FPU op. Executed non-speculatively! -> Routed to [FPU], rd=4, rs1=5, rs2=6)
        "h00c00693".U, // 0x40: addi x13, x0, 12  (Unique ADDI - replacing NOP)
        "h00d00713".U, // 0x44: addi x14, x0, 13  (Unique ADDI - replacing NOP)
        "h0000006f".U  // 0x48: jal x0, 0         (Halt loop. -> Routed to [BRU])
      )
    }
  }

  val program_seq = loadHex(programFile)
  val program = VecInit(program_seq.padTo(1024, "h00000013".U)) // Increased size for larger binaries


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(11, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


