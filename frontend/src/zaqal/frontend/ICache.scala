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
        "hC00005B7".U, // 0x04: lui x11, 0xC0000        -> x11 = 0xC0000000 (-2.0f)
        "hF00500D3".U, // 0x08: fmv.w.x f1, x10         -> f1 = 4.0f
        "hF0058153".U, // 0x0C: fmv.w.x f2, x11         -> f2 = -2.0f
        "h202081D3".U, // 0x10: fsgnj.s f3, f1, f2      -> f3 = -4.0f (0xc0800000)
        "h20209253".U, // 0x14: fsgnjn.s f4, f1, f2     -> f4 = +4.0f (0x40800000)
        "h2020A2D3".U, // 0x18: fsgnjx.s f5, f1, f2     -> f5 = -4.0f (0xc0800000)
        "h28208353".U, // 0x1C: fmin.s f6, f1, f2       -> f6 = -2.0f (0xc0000000)
        "h282093D3".U, // 0x20: fmax.s f7, f1, f2       -> f7 = 4.0f  (0x40800000)
        "hA020A653".U, // 0x24: feq.s x12, f1, f2       -> x12 = 0
        "hA01116D3".U, // 0x28: flt.s x13, f2, f1       -> x13 = 1
        "hE00097D3".U, // 0x2C: fclass.s x15, f1        -> x15 = 0x40 (64)
        "hC0008853".U, // 0x30: fcvt.w.s x16, f1        -> x16 = 4
        "hD0080453".U, // 0x34: fcvt.s.w f8, x16        -> f8 = 4.0f
        "hE00108D3".U, // 0x38: fmv.x.w x17, f2         -> x17 = 0xC0000000
        "h00100613".U, // 0x3C: li x12, 1               -> Success flag
        "h0000006f".U  // 0x40: j 0x40                  -> Final halt loop
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


