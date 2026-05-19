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
      println(s"[ICache] Warning: Using Custom Fusion Test Program.")
      Seq(
        "h00a00093".U, // 0x00: addi x1, x0, 10
        "h00700493".U, // 0x04: addi x9, x0, 7
        "h00300513".U, // 0x08: addi x10, x0, 3
        "h00000c63".U, // 0x0c: beq x0, x0, 24  (Predicted NOT TAKEN, actually TAKEN to 0x24)
        "h06300113".U, // 0x10: addi x2, x0, 99 (Speculative fallthrough!)
        "h00500593".U, // 0x14: addi x11, x0, 5
        "h00900613".U, // 0x18: addi x12, x0, 9
        "h00b00693".U, // 0x1c: addi x13, x0, 11
        "h00b00693".U, // 0x20: addi x13, x0, 11
        "h00608093".U, // 0x24: addi x1, x1, 6  (Correct taken path target!)
        "h00700493".U, // 0x28: addi x9, x0, 7
        "h00300513".U, // 0x2c: addi x10, x0, 3
        "h00300113".U, // 0x30: addi x2, x0, 3   (Correct value for x2)
        "h00500593".U, // 0x34: addi x11, x0, 5
        "h00900613".U, // 0x38: addi x12, x0, 9
        "h02800313".U, // 0x3c: addi x6, x0, 40
        "h03200393".U, // 0x40: addi x7, x0, 50
        "h00700493".U, // 0x44: addi x9, x0, 7
        "h00300513".U, // 0x48: addi x10, x0, 3
        "h03c00413".U, // 0x4c: addi x8, x0, 60
        "h00500593".U, // 0x50: addi x11, x0, 5
        "h00900613".U, // 0x54: addi x12, x0, 9
        "h0000006f".U  // 0x58: jal x0, 0        (Halt)
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


