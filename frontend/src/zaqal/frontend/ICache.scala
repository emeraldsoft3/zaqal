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
      println(s"[ICache] Warning: Using SC/TAGE/ITTAGE stress-test program with spaced out branches.")
      Seq(
        // Block 0: Init
        "h01400093".U, // 0x00: addi x1, x0, 20  (outer loop counter = 20)
        "h00000293".U, // 0x04: addi x5, x0, 0   (state = 0)
        "h00200113".U, // 0x08: addi x2, x0, 2   (marker)
        "h00300193".U, // 0x0c: addi x3, x0, 3   (marker)
        // Block 0 continued: Loop Start
        "h00628293".U, // 0x10: addi x5, x5, 6   (state += 6)
        "h0032f713".U, // 0x14: andi x14, x5, 3  (cond = state % 4)
        "h00070863".U, // 0x18: beq x14, x0, 0x28(Target1)  -> TAGE Predicts this
        "h00600313".U, // 0x1c: addi x6, x0, 6   (Fallthrough marker)
        // Block 1
        "h00700393".U, // 0x20: addi x7, x0, 7   (Fallthrough marker)
        "h00c0006f".U, // 0x24: jal x0, 0x30     (Jump to target_join)
        "h00800413".U, // 0x28: addi x8, x0, 8   (Target1 marker)
        "h00900493".U, // 0x2c: addi x9, x0, 9   (Target1 marker)
        // Block 1 continued: Join
        "h00271893".U, // 0x30: slli x17, x14, 2 (offset = cond * 4)
        "h0180026f".U, // 0x34: jal x4, 0x4c     (helper call, saves link 0x38 in x4)
        // Block 1 continued: Return Targets
        "h00a00513".U, // 0x38: addi x10, x0, 10 (Ret A)
        "h01c0006f".U, // 0x3c: jal x0, 0x58     (Jump to loop_end)
        // Block 2
        "h00b00593".U, // 0x40: addi x11, x0, 11 (Ret B)
        "h00c00613".U, // 0x44: addi x12, x0, 12 (Ret B marker)
        "h0100006f".U, // 0x48: jal x0, 0x58     (Jump to loop_end)
        // Block 2 continued: Helper
        "h01120233".U, // 0x4c: add x4, x4, x17  (x4 = 0x38 + offset)
        "h00d00693".U, // 0x50: addi x13, x0, 13 (marker)
        "h000200e7".U, // 0x54: jalr x0, x4, 0   -> ITTAGE Predicts this
        // Block 2 continued: Loop End
        "hfff08093".U, // 0x58: addi x1, x1, -1  (decrement counter)
        "hfa009ae3".U, // 0x5c: bne x1, x0, 0x10 (loop back)
        // Block 3: Done
        "h06300613".U, // 0x60: addi x12, x0, 99
        "hffdff06f".U  // 0x64: jal x0, 0x60
      ) ++ Seq.fill(60)("h00000013".U) // Padding
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
