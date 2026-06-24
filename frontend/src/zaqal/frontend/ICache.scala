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
        "h00500513".U, // 0x00: addi x10, x0, 5        (x10 = 5)
        "h00c00593".U, // 0x04: addi x11, x0, 12       (x11 = 12)
        "h20b52633".U, // 0x08: sh1add x12, x10, x11   (x12 = (5 << 1) + 12 = 22)
        "h20b546b3".U, // 0x0c: sh2add x13, x10, x11   (x13 = (5 << 2) + 12 = 32)
        "h20b56733".U, // 0x10: sh3add x14, x10, x11   (x14 = (5 << 3) + 12 = 52)
        "h20b527bb".U, // 0x14: sh1add.uw x15, x10, x11 (x15 = (5 << 1) + 12 = 22)
        "h20b5483b".U, // 0x18: sh2add.uw x16, x10, x11 (x16 = (5 << 2) + 12 = 32)
        "h20b568bb".U, // 0x1c: sh3add.uw x17, x10, x11 (x17 = (5 << 3) + 12 = 52)
        "h02b50933".U, // 0x20: mul x18, x10, x11      (x18 = 5 * 12 = 60)
        "h02b509bb".U  // 0x24: mulw x19, x10, x11     (x19 = 5 * 12 = 60)
      ) ++ Seq.fill(80)("h00000013".U) ++ Seq(
        "h0000006f".U  // Halt loop
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


