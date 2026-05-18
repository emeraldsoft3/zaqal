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
      println(s"[ICache] Warning: Using Custom Fusion Test Program.")
      Seq(
        "h00000663".U, // 0x00: beq x0, x0, 12  (Predicted NOT TAKEN, actually TAKEN to 0x0c)
        "h06300113".U, // 0x04: addi x2, x0, 99 (Speculative fallthrough!)
        "h00c0006f".U, // 0x08: jal x0, 12      (Speculative jump to 0x14)
        "h00700193".U, // 0x0c: addi x3, x0, 7   (Correct taken path target!)
        "h00300113".U, // 0x10: addi x2, x0, 3   (Correct value for x2)
        "h0000006f".U  // 0x14: jal x0, 0        (Halt)
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


