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
    val hexFile = new java.io.File(path)
    if (hexFile.exists()) {
      val source = scala.io.Source.fromFile(path)
      val lines = source.getLines()
        .map(_.split("//")(0).trim) // Remove comments
        .filter(_.nonEmpty)
      val insts = lines.map(l => s"h$l".U(32.W)).toSeq
      source.close()
      println(s"[ICache] Loaded ${insts.length} instructions from $path")
      insts
    } else {
      println(s"[ICache] Warning: $path not found, using default hardcoded program.")
      Seq(
        "h80000537".U, // 0x00: lui x10, 0x80000
        "h02250513".U, // 0x04: addi x10, x10, 0x22 (x10 = 0x80000022)
        "h000500e7".U, // 0x08: jalr x1, 0(x10) -> Jump to 0x80000022
        "h00000013".U, // 0x0C: nop
        "h00000013".U, // 0x10: nop
        "h00000013".U, // 0x14: nop
        "h00000013".U, // 0x18: nop
        "h00010001".U, // 0x20: c.nop; c.nop (Valid RVC target at 0x22)
        "h00100613".U, // 0x24: li x12, 1 (Success Path)
        "h0000006f".U  // 0x28: j 0x28 (Halt Success)
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


