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
        "h123450b7".U, // 0x00: lui x1, 0x12345
        "h67808093".U, // 0x04: addi x1, x1, 0x678 (SHOULD FUSE: x1 = 0x12345678)
        "h00000217".U, // 0x08: auipc x2, 0x0
        "h01010113".U, // 0x0c: addi x2, x2, 0x10  (SHOULD FUSE: x2 = PC + 0x10)
        "habcde337".U, // 0x10: lui x6, 0xABCDE
        "h12330313".U, // 0x14: addi x6, x6, 0x123 (SHOULD FUSE: x6 = 0xABCDE123)
        "h111113b7".U, // 0x18: lui x7, 0x11111
        "h22238393".U, // 0x1c: addi x7, x7, 0x222 (SHOULD FUSE: x7 = 0x11111222)
        "h0000006f".U  // 0x20: j 0x20 (Halt)
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


