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
      println(s"[ICache] Warning: Using rich branch stress-test program with nested loops and alternating branches.")
      Seq(
        "h00c00093".U, // 0x00: addi x1, x0, 12   (Outer loop counter: x1 = 12)
        "h00000213".U, // 0x04: addi x4, x0, 0    (Accumulator x4 = 0)
        "h00000313".U, // 0x08: addi x6, x0, 0    (Accumulator path A: x6 = 0)
        "h00000393".U, // 0x0c: addi x7, x0, 0    (Accumulator path B: x7 = 0)
        "h00000413".U, // 0x10: addi x8, x0, 0    (Accumulator path C: x8 = 0)
        "h00300113".U, // 0x14: addi x2, x0, 3    (Middle loop limit: x2 = 3)
        "h00200193".U, // 0x18: addi x3, x0, 2    (Inner loop limit: x3 = 2)
        "h00120233".U, // 0x1c: add x4, x4, x1    (Accumulate x4 += x1)
        "hfff18193".U, // 0x20: addi x3, x3, -1   (Decrement inner counter)
        "hfe019ce3".U, // 0x24: bne x3, x0, -8    (If x3 != 0, branch to 0x1c)
        "hfff10113".U, // 0x28: addi x2, x2, -1   (Decrement middle counter)
        "hfe0116e3".U, // 0x2c: bne x2, x0, -20   (If x2 != 0, branch to 0x18)
        "h0010f493".U, // 0x30: andi x9, x1, 1    (x9 = x1 & 1)
        "h00048663".U, // 0x34: beq x9, x0, 12    (If x9 == 0, branch to 0x40)
        "h00530313".U, // 0x38: addi x6, x6, 5    (Odd path: x6 += 5)
        "h0080006f".U, // 0x3c: jal x0, 8         (Jump to 0x44)
        "h00a38393".U, // 0x40: addi x7, x7, 10   (Even path: x7 += 10)
        "h00600513".U, // 0x44: addi x10, x0, 6   (x10 = 6)
        "h00a0c663".U, // 0x48: blt x1, x10, 12   (If x1 < 6, branch to 0x54)
        "h01440413".U, // 0x4c: addi x8, x8, 20   (Upper path: x8 += 20)
        "h0080006f".U, // 0x50: jal x0, 8         (Jump to 0x58)
        "h00140413".U, // 0x54: addi x8, x8, 1    (Lower path: x8 += 1)
        "hfff08093".U, // 0x58: addi x1, x1, -1   (Decrement outer counter)
        "hfc009ce3".U, // 0x5c: bne x1, x0, -72   (If x1 != 0, branch to 0x14)
        "h06300613".U  // 0x60: addi x12, x0, 99  (Done marker: x12 = 99)
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


