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
      println(s"[ICache] Warning: Using Rename Stress Test hardcoded program (Day 4).")
      Seq(
        "h00100093".U, // 0x00: addi x1, x0, 1
        "h00208113".U, // 0x04: addi x2, x1, 2 (RAW on x1)
        "h00310193".U, // 0x08: addi x3, x2, 3 (RAW on x2)
        "h00418213".U, // 0x0C: addi x4, x3, 4 (RAW on x3)
        "h00520293".U, // 0x10: addi x5, x4, 5 (RAW on x4)
        "h00628313".U, // 0x14: addi x6, x5, 6 (RAW on x5)
        "h00730393".U, // 0x18: addi x7, x6, 7 (RAW on x6)
        "h00838413".U, // 0x1C: addi x8, x7, 8
        "h00940493".U, // 0x20: addi x9, x8, 9
        "h00a48513".U, // 0x24: addi x10, x9, 10
        "h00b50593".U, // 0x28: addi x11, x10, 11
        "h00c58613".U, // 0x2C: addi x12, x11, 12
        "h0000a087".U, // 0x30: flw f1, 0(x1)  (FP Load)
        "h02108153".U, // 0x34: fadd.s f2, f1, f1 (FP RAW on f1)
        "h0a2081d3".U, // 0x38: fsub.s f3, f2, f1 (FP RAW on f2)
        "h00d60693".U, // 0x3C: addi x13, x12, 13
        "h00e68713".U, // 0x40: addi x14, x13, 14
        "h00f70793".U, // 0x44: addi x15, x14, 15
        "h0000006f".U  // 0x48: j 0x48 (Halt)
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


