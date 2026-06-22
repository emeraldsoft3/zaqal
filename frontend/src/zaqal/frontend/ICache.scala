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
      println(s"[ICache] Warning: Using basic ADDI test program for Pipelined Dispatch verification.")
      Seq(
        "h00a00513".U, // 0x00: addi x10, x0, 10      (x10 = 10)
        "h00200593".U, // 0x04: addi x11, x0, 2       (x11 = 2)
        "h02b54633".U, // 0x08: div x12, x10, x11     (x12 = 10 / 2 = 5)
        "h00460693".U, // 0x0c: addi x13, x12, 4      (x13 = 5 + 4 = 9, dependent on div)
        "h00d02823".U, // 0x10: sw x13, 16(x0)        (Store x13 to addr 16)
        "h01002703".U, // 0x14: lw x14, 16(x0)        (Load addr 16 into x14)
        "h00170793".U  // 0x18: addi x15, x14, 1      (x15 = 9 + 1 = 10, dependent on load)
      ) ++ Seq.fill(80)("h00000013".U) ++ Seq(
        "h0000006f".U  // 0x1c + 80*4: jal x0, 0       (Halt loop)
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


