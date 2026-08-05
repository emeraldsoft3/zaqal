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
      println(s"[ICache] Using Dedicated RAS Test Program (Call & Return)")
      Seq(
        // Block 0x00
        "h03200a13".U, // 0x00: addi x20, x0, 50  (loop counter = 50)
        "h00000a93".U, // 0x04: addi x21, x0, 0   (state = 0)
        "h040a0c63".U, // 0x08: beq x20, x0, 0x60 (if counter == 0, go to Done)
        "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, // Padding to 0x20

        // Block 0x20
        "h060000ef".U, // 0x20: jal x1, 0x80      (Call Subroutine A)
        "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, // Padding to 0x40

        // Block 0x40
        "hfffa0a13".U, // 0x40: addi x20, x20, -1 (counter--)
        "hfc5ff06f".U, // 0x44: jal x0, 0x08      (Jump to Loop Start)
        "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, // Padding to 0x60

        // Block 0x60 (Done)
        "h0000006f".U, // 0x60: jal x0, 0x60      (Infinite loop)
        "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, "h00000013".U, // Padding to 0x80

        // Block 0x80 (Subroutine A)
        "h001a8a93".U, // 0x80: addi x21, x21, 1  (state++)
        "h00008067".U  // 0x84: jalr x0, x1, 0    (Return -> RAS Predicts this)
      ) ++ Seq.fill(100)("h00000013".U) // Padding
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
