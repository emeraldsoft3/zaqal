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
    if (true) { // Enabled for Benchmarking
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
        "h00000537".U, // 0x00: lui x10, 0              -> x10 = 0
        "h00052087".U, // 0x04: flw f1, 0(x10)          -> f1 = [0x00] = 0x11223344
        "h00452107".U, // 0x08: flw f2, 4(x10)          -> f2 = [0x04] = 0xAABBCCDD
        "h00152827".U, // 0x0C: fsw f1, 16(x10)         -> [16] = f1 (0x11223344)
        "h00252A27".U, // 0x10: fsw f2, 20(x10)         -> [20] = f2 (0xAABBCCDD)
        "h00853187".U, // 0x14: fld f3, 8(x10)          -> f3 = [0x08] = 0x5566778899AABBCC
        "h00353C27".U, // 0x18: fsd f3, 24(x10)         -> [24] = f3 (0x5566778899AABBCC)
        "h00208253".U, // 0x1C: fadd.s f4, f1, f2       -> f4 = f1 + f2
        "h00100613".U, // 0x20: li x12, 1               -> Success flag
        "h0000006f".U  // 0x24: j 0x24                  -> Final halt loop
      )
    }
  }

  // val hexFile = "programs/hex/coremark_fp.hex"
  val hexFile = "programs/hex/rvc_fp.hex"
  val program_seq = loadHex(hexFile)
  val program = VecInit(program_seq.padTo(1024, "h00000013".U)) // Increased size for larger binaries


  val relative_pc = io.pc - "h8000_0000".U
  val index = relative_pc(11, 2) 

  for (i <- 0 until fetchWidth) {
    val idx = index + i.U
    io.insts(i) := Mux(idx < program.length.U, program(idx), "h00000013".U)
  }

  io.ready := true.B
}


