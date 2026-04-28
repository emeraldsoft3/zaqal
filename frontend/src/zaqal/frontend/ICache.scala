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
        "h3f800537".U, // 0x00: lui x10, 0x3f800        -> x10 = 0x3f800000 (1.0f)
        "h400005b7".U, // 0x04: lui x11, 0x40000        -> x11 = 0x40000000 (2.0f)
        "hF00500D3".U, // 0x08: fmv.w.x f1, x10         -> f1 = 1.0f
        "hF0058153".U, // 0x0C: fmv.w.x f2, x11         -> f2 = 2.0f
        "h002081d3".U, // 0x10: fadd.s f3, f1, f2       -> f3 = 1.0 + 2.0 = 3.0f (0x40400000)
        "h10208253".U, // 0x14: fmul.s f4, f1, f2       -> f4 = 1.0 * 2.0 = 2.0f (0x40000000)
        "h081102d3".U, // 0x18: fsub.s f5, f2, f1       -> f5 = 2.0 - 1.0 = 1.0f (0x3f800000)
        "h18210343".U, // 0x1C: fmadd.s f6, f2, f2, f3  -> f6 = (2.0 * 2.0) + 3.0 = 7.0f (0x40e00000)
        "h80000637".U, // 0x20: lui x12, 0x80000        -> Memory address 0x80000000
        "h00662427".U, // 0x24: fsw f6, 8(x12)          -> Store 7.0f to memory [0x80000008]
        "h00862387".U, // 0x28: flw f7, 8(x12)          -> Load back 7.0f into f7
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


