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
      println(s"[ICache] Warning: Using Custom Issue Queue OoO Verification Program.")
      Seq(
        "h00a00113".U, // 0x00: addi x2, x0, 10   (ALU - Initialize x2 = 10)
        "h00200193".U, // 0x04: addi x3, x0, 2    (ALU - Initialize x3 = 2)
        "h023140b3".U, // 0x08: div x1, x2, x3    (ALU/DIV - Long latency, writes x1)
        "h00108213".U, // 0x0c: addi x4, x1, 1    (ALU - Reads x1, waits in IQ for Wakeup)
        "h00200293".U, // 0x10: addi x5, x0, 2    (ALU - Independent, issues OoO!)
        "h00300313".U, // 0x14: addi x6, x0, 3    (ALU - Independent, issues OoO!)
        "h0000006f".U  // 0x18: jal x0, 0         (BRU - Infinite loop halt)
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


