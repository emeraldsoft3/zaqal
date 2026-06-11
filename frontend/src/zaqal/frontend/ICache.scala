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
        "h00200113".U, // 0x00: addi x2, x0, 2
        "h00200193".U, // 0x04: addi x3, x0, 2
        "h00400213".U, // 0x08: addi x4, x0, 4
        "h00400293".U, // 0x0c: addi x5, x0, 4
        "h00600313".U, // 0x10: addi x6, x0, 6
        "h00700393".U, // 0x14: addi x7, x0, 7
        "h00000013".U, // 0x18: nop
        "h00000013".U, // 0x1c: nop

        // Block 1: 0x20 - 0x3C
        "h00000013".U, // 0x20: nop
        "h04310E63".U, // 0x24: beq x2, x3, 92  (Branch 1: target 0x80, predicted taken, actual not-taken)
        "h06400793".U, // 0x28: addi x15, x0, 100 (CORRECT path start)
        "h0c800813".U, // 0x2c: addi x16, x0, 200
        "h08521863".U, // 0x30: bne x4, x5, 144 (Branch 2: target 0xC0, predicted not-taken, actual taken)
        "h00000013".U, // 0x34: nop
        "h00000013".U, // 0x38: nop
        "h00000013".U, // 0x3c: nop

        // Block 2: 0x40 - 0x5C
        "h00000013".U, // 0x40
        "h00000013".U, // 0x44
        "h00000013".U, // 0x48
        "h00000013".U, // 0x4c
        "h00000013".U, // 0x50
        "h00000013".U, // 0x54
        "h00000013".U, // 0x58
        "h00000013".U, // 0x5c

        // Block 3: 0x60 - 0x7C
        "h00000013".U, // 0x60
        "h00000013".U, // 0x64
        "h00000013".U, // 0x68
        "h00000013".U, // 0x6c
        "h00000013".U, // 0x70
        "h00000013".U, // 0x74
        "h00000013".U, // 0x78
        "h00000013".U, // 0x7c

        // Block 4: 0x80 - 0x9C (Wrong path target of Branch 1)
        "h3e700a13".U, // 0x80: addi x20, x0, 999 (Should be flushed!)
        "h00000013".U, // 0x84
        "h00000013".U, // 0x88
        "h00000013".U, // 0x8c
        "h00000013".U, // 0x90
        "h00000013".U, // 0x94
        "h00000013".U, // 0x98
        "h00000013".U, // 0x9c

        // Block 5: 0xa0 - 0xbc
        "h00000013".U, // 0xa0
        "h00000013".U, // 0xa4
        "h00000013".U, // 0xa8
        "h00000013".U, // 0xac
        "h00000013".U, // 0xb0
        "h00000013".U, // 0xb4
        "h00000013".U, // 0xb8
        "h00000013".U, // 0xbc

        // Block 6: 0xc0 - 0xdc (Correct path target of Branch 2)
        "h12c00893".U, // 0xc0: addi x17, x0, 300
        "h19000913".U, // 0xc4: addi x18, x0, 400
        "h0000006f".U, // 0xc8: jal x0, 0 (Halt loop)
        "h00000013".U, // 0xcc
        "h00000013".U, // 0xd0
        "h00000013".U, // 0xd4
        "h00000013".U, // 0xd8
        "h00000013".U  // 0xdc
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


