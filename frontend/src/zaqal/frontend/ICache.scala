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
        "h02a00593".U, // 0x00: addi x11, x0, 42      (x11 = 42)
        "h00800513".U, // 0x04: addi x10, x0, 8       (x10 = 8)
        "h00b53023".U, // 0x08: sd x11, 0(x10)        (store 42 to address 8)
        "h00053603".U, // 0x0c: ld x12, 0(x10)        (load from address 8 to x12)
        "h06460693".U, // 0x10: addi x13, x12, 100    (x13 = x12 + 100 = 142)
        "h01000713".U, // 0x14: addi x14, x0, 16      (x14 = 16)
        "h0ff00793".U, // 0x18: addi x15, x0, 255     (x15 = 255)
        "h00f70023".U, // 0x1c: sb x15, 0(x14)        (store 0xFF byte to 16)
        "h00074803".U, // 0x20: lbu x16, 0(x14)       (load unsigned byte -> 255)
        "h00070883".U, // 0x24: lb x17, 0(x14)        (load signed byte -> -1)
        "h01800913".U, // 0x28: addi x18, x0, 24      (x18 = 24)
        "h12300993".U, // 0x2c: addi x19, x0, 291     (x19 = 291)
        "h01391023".U, // 0x30: sh x19, 0(x18)        (store half-word to 24)
        "h00091a03".U  // 0x34: lh x20, 0(x18)        (load signed half-word -> 291)
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


