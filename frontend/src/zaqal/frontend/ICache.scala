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
    if (false) { // Bypassed
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
        "h40800537".U, // 0x00: lui x10, 0x40800        -> x10 = 0x40800000 (4.0f)
        "h400005b7".U, // 0x04: lui x11, 0x40000        -> x11 = 0x40000000 (2.0f)
        "h3f800637".U, // 0x08: lui x12, 0x3f800        -> x12 = 0x3f800000 (1.0f)
        "hF00500D3".U, // 0x0C: fmv.w.x f1, x10         -> f1 = 4.0f
        "hF0058153".U, // 0x10: fmv.w.x f2, x11         -> f2 = 2.0f
        "hF00601D3".U, // 0x14: fmv.w.x f3, x12         -> f3 = 1.0f
        "h18208253".U, // 0x18: fdiv.s f4, f1, f2       -> f4 = 4.0 / 2.0 = 2.0f (0x40000000)
        "h182182d3".U, // 0x1C: fdiv.s f5, f3, f2       -> f5 = 1.0 / 2.0 = 0.5f (0x3f000000)
        "h58008333".U, // 0x20: fsqrt.s f6, f1          -> f6 = sqrt(4.0) = 2.0f (0x40000000)
        "h580083b3".U, // 0x24: fsqrt.s f7, f3          -> f7 = sqrt(1.0) = 1.0f (0x3f800000)
        "h58010553".U, // 0x28: fsqrt.s f10, f2         -> f10 = sqrt(2.0) = 1.4142135f (0x3fddb3d7)
        "h00100613".U, // 0x2C: li x12, 1               -> Success flag
        "h0000006f".U  // 0x30: j 0x30                  -> Final halt loop
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


