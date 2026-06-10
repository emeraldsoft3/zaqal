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
      println(s"[ICache] Warning: Using Expanded Flush Verification Program.")
      Seq(
        "h00108093".U, // 0x00: addi x1, x1, 1
        "h00210113".U, // 0x04: addi x2, x2, 2
        "h00318193".U, // 0x08: addi x3, x3, 3
        "h00420213".U, // 0x0c: addi x4, x4, 4
        "h00528293".U, // 0x10: addi x5, x5, 5
        "h02224333".U, // 0x14: div x6, x4, x2
        "h00130393".U, // 0x18: addi x7, x6, 1
        "h00002403".U, // 0x1c: lw x8, 0(x0)
        "h00802423".U, // 0x20: sw x8, 8(x0)
        "h00a48493".U, // 0x24: addi x9, x9, 10
        "h01450513".U, // 0x28: addi x10, x10, 20
        "h029545b3".U, // 0x2c: div x11, x10, x9
        "h00000663".U, // 0x30: beq x0, x0, 12    (BRU - Branch to 0x3C, predicted not-taken but taken)
        "h02114633".U, // 0x34: div x12, x2, x1   (ALU/DIV - WRONG PATH: should be flushed!)
        "h00160693".U, // 0x38: addi x13, x12, 1  (ALU - WRONG PATH: waits in IQ and flushed)
        "h06470713".U, // 0x3c: addi x14, x14, 100 (CORRECT PATH target)
        "h03278793".U, // 0x40: addi x15, x15, 50
        "h01080813".U, // 0x44: addi x16, x16, 16
        "h01188893".U, // 0x48: addi x17, x17, 17
        "h01290913".U, // 0x4c: addi x18, x18, 18
        "h00802983".U, // 0x50: lw x19, 8(x0)
        "h0229ca33".U, // 0x54: div x20, x19, x2
        "h005a8a93".U, // 0x58: addi x21, x21, 5
        "h016b0b13".U, // 0x5c: addi x22, x22, 22
        "h017b8b93".U, // 0x60: addi x23, x23, 23
        "h018c0c13".U, // 0x64: addi x24, x24, 24
        "h019c8c93".U, // 0x68: addi x25, x25, 25
        "h01ad0d13".U, // 0x6c: addi x26, x26, 26
        "h01bd8d93".U, // 0x70: addi x27, x27, 27
        "h016b0b13".U, // 0x5c: addi x22, x22, 22
        "h017b8b93".U, // 0x60: addi x23, x23, 23
        "h018c0c13".U, // 0x64: addi x24, x24, 24
        "h019c8c93".U, // 0x68: addi x25, x25, 25
        "h01ad0d13".U, // 0x6c: addi x26, x26, 26
        "h01bd8d93".U, // 0x70: addi x27, x27, 27
        "h016b0b13".U, // 0x5c: addi x22, x22, 22
        "h017b8b93".U, // 0x60: addi x23, x23, 23
        "h018c0c13".U, // 0x64: addi x24, x24, 24
        "h019c8c93".U, // 0x68: addi x25, x25, 25
        "h01ad0d13".U, // 0x6c: addi x26, x26, 26
        "h01bd8d93".U, // 0x70: addi x27, x27, 27
        "h016b0b13".U, // 0x5c: addi x22, x22, 22
        "h017b8b93".U, // 0x60: addi x23, x23, 23
        "h018c0c13".U, // 0x64: addi x24, x24, 24
        "h019c8c93".U, // 0x68: addi x25, x25, 25
        "h01ad0d13".U, // 0x6c: addi x26, x26, 26
        "h01bd8d93".U, // 0x70: addi x27, x27, 27
        "h00108093".U, // 0x00: addi x1, x1, 1
        "h00210113".U, // 0x04: addi x2, x2, 2
        "h00318193".U, // 0x08: addi x3, x3, 3
        "h00420213".U, // 0x0c: addi x4, x4, 4
        "h00528293".U, // 0x10: addi x5, x5, 5
        "h00108093".U, // 0x00: addi x1, x1, 1
        "h00210113".U, // 0x04: addi x2, x2, 2
        "h00318193".U, // 0x08: addi x3, x3, 3
        "h00420213".U, // 0x0c: addi x4, x4, 4
        "h00528293".U, // 0x10: addi x5, x5, 5
        "h00108093".U, // 0x00: addi x1, x1, 1
        "h00210113".U, // 0x04: addi x2, x2, 2
        "h00318193".U, // 0x08: addi x3, x3, 3
        "h00420213".U, // 0x0c: addi x4, x4, 4
        "h00528293".U, // 0x10: addi x5, x5, 5
        "h0000006f".U  // 0x74: jal x0, 0         (Infinite loop halt)
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


