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
      println(s"[ICache] Warning: Using Expanded Flush Verification Program.")
      Seq(
        "h00100093".U, // 0x00: addi x1, x0, 1
        "h00200113".U, // 0x04: addi x2, x0, 2
        "h02224333".U, // 0x08: div x6, x4, x2
        "h00030463".U, // 0x0c: beq x6, x0, 8      (Branch 1: dependent on x6. Target is 0x0c + 8 = 0x14. Predicted Not-Taken)
        "h00030863".U, // 0x10: beq x6, x0, 16     (Branch 2: dependent on x6. Target is 0x10 + 16 = 0x20. Predicted Not-Taken)
        "h06400713".U, // 0x14: addi x14, x0, 100  (Target of Branch 1 - CORRECT PATH)
        "h01000813".U, // 0x18: addi x16, x0, 16   (CORRECT PATH)
        "h0000006f".U, // 0x1c: jal x0, 0          (CORRECT PATH HALT)
        "h03200793".U, // 0x20: addi x15, x0, 50   (Target of Branch 2 - WRONG PATH: must never execute!)
        "h0000006f".U  // 0x24: jal x0, 0          (Infinite loop halt)
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


