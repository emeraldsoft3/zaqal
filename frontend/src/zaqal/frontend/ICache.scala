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
      println(s"[ICache] Using UOpCache Hit/Miss Verification Program")
      Seq(
        // Block 0x00 (First 8 Instructions)
        "h00108093".U, // 00: addi x1, x1, 1
        "h00210113".U, // 01: addi x2, x2, 2
        "h00318193".U, // 02: addi x3, x3, 3
        "h00420213".U, // 03: addi x4, x4, 4
        "h00528293".U, // 04: addi x5, x5, 5
        "h00630313".U, // 05: addi x6, x6, 6
        "h00738393".U, // 06: addi x7, x7, 7
        "h00840413".U, // 07: addi x8, x8, 8

        // Block 0x20 (Next 8 Instructions - Empty/NOPs)
        "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, 
        "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, 

        // Block 0x40 (Final 8 Instructions)
        "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, 
        "h00000013".U, "h00000013".U, "h00000013".U, 
        "hfa5ff06f".U  // 23: jal x0, -92 (Jump back to 00)
      ) ++ Seq.fill(100)("h00000013".U) // Padding
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
