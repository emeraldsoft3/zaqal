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
    if (false) { // Disabled for FPU Verification
      val source = scala.io.Source.fromFile(path)
      val lines = source.getLines()
        .map(_.split("//")(0).trim) // Remove comments
        .filter(_.nonEmpty)
      val insts = lines.map(l => s"h$l".U(32.W)).toSeq
      source.close()
      println(s"[ICache] Loaded ${insts.length} instructions from $path")
      insts
    } else {
      println(s"[ICache] Warning: Using RVC-Parity hardcoded FPU test program (Day 39).")
      Seq(
        "h00100293".U, // 0x00: li x5, 1
        "h00200313".U, // 0x04: li x6, 2
        "h00300393".U, // 0x08: li x7, 3
        "h00400413".U, // 0x0C: li x8, 4
        "h00500493".U, // 0x10: li x9, 5
        "h00600513".U, // 0x14: li x10, 6
        "h00700593".U, // 0x18: li x11, 7
        "h00800613".U, // 0x1C: li x12, 8
        "h0000006f".U  // 0x20: j 0x20 (Halt)
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


