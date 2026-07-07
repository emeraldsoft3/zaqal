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
      val useTageTest = true // Set to true to run the TAGE/ITTAGE stress test
      if (useTageTest) {
        println(s"[ICache] Warning: Using TAGE & ITTAGE stress-test program with alternating conditional branch and indirect branch.")
        Seq(
          "h00a00093".U, // 0x00: addi x1, x0, 10   (Outer loop counter: x1 = 10)
          "h00000293".U, // 0x04: addi x5, x0, 0    (Alternating index counter: x5 = 0)
          "h00628293".U, // 0x08: addi x5, x5, 6    (Modify counter by adding 6)
          "h0032f713".U, // 0x0c: andi x14, x5, 3   (x14 = x5 % 4; sequence: 2, 0, 2, 0...)
          "h00070463".U, // 0x10: beq x14, x0, 8    (Taken if x14 == 0; Jumps to 0x18)
          "h00100793".U, // 0x14: addi x15, x0, 1   (Executed only on odd iterations)
          "h00271893".U, // 0x18: slli x17, x14, 2  (x17 = x14 * 4; alternates between 0 and 8)
          "h0140026f".U, // 0x1c: jal x4, 20        (Jal to helper at 0x30, link address 0x20 saved in x4)
          "h00a00793".U, // 0x20: addi x15, x0, 10  (Target A: Executed if x14 == 0)
          "h0180006f".U, // 0x24: jal x0, 24        (Jump to Loop End at 0x3c)
          "h01400793".U, // 0x28: addi x15, x0, 20  (Target B: Executed if x14 == 2)
          "h0100006f".U, // 0x2c: jal x0, 16        (Jump to Loop End at 0x3c)
          "h01120233".U, // 0x30: add x4, x4, x17   (Add offset: x4 = 0x20 + x17)
          "h000200e7".U, // 0x34: jalr x1, x4, 0    (Dynamic indirect jump to Target A or B)
          "hfff08093".U, // 0x38: addi x1, x1, -1   (Decrement outer loop counter)
          "hfc0096e3".U, // 0x3c: bne x1, x0, -52   (If x1 != 0, branch to Loop Start at 0x08)
          "h06300613".U  // 0x40: addi x12, x0, 99  (Done marker: x12 = 99)
        ) ++ Seq.fill(80)("h00000013".U) ++ Seq(
          "h0000006f".U  // Halt loop
        )
      } else {
        println(s"[ICache] Warning: Using rich branch stress-test program with nested loops and alternating branches.")
        Seq(
          "h00a00093".U, // 0x00: addi x1, x0, 10   (Outer loop counter: x1 = 10) p32
          "h00200113".U, // 0x04: addi x2, x0, 2    (Inner loop limit: x2 = 2) p33
          "h00000193".U, // 0x08: addi x3, x0, 0    (Accumulator: x3 = 0)
          "h00000213".U, // 0x0c: addi x4, x0, 0    (Outer accumulator: x4 = 0)
          "h00000693".U, // 0x10: addi x13, x0, 0   (Alternating counter: x13 = 0) p36
          "h00120233".U, // 0x14: add x4, x4, x1    (Outer loop logic: x4 += x1) p37=10
          "h00000293".U, // 0x18: addi x5, x0, 0    (Inner loop counter: x5 = 0)
          "h004181b3".U, // 0x1c: add x3, x3, x4    (Inner loop accumulator: x3 += x4) p39=10
          "h00128293".U, // 0x20: addi x5, x5, 1    (Increment inner counter) p40 =1
          "hfe229ce3".U, // 0x24: bne x5, x2, -8     (If x5 != x2, branch to 0x1c) 
          "h00168693".U, // 0x28: addi x13, x13, 1  (Increment alternating counter) p41
          "h0016f713".U, // 0x2c: andi x14, x13, 1  (x14 = x13 & 1)
          "h00070663".U, // 0x30: beq x14, x0, 12   (If x14 == 0, branch to 0x3c)
          "h06400793".U, // 0x34: addi x15, x0, 100 (Odd iteration: x15 = 100)
          "h0080006f".U, // 0x38: jal x0, 8         (Jump to 0x40)
          "h0c800793".U, // 0x3c: addi x15, x0, 200 (Even iteration: x15 = 200)
          "h00f181b3".U, // 0x40: add x3, x3, x15   (Accumulate x15)
          "hfff08093".U, // 0x44: addi x1, x1, -1   (Decrement outer counter)
          "hfc0096e3".U, // 0x48: bne x1, x0, -52   (If x1 != 0, branch to 0x14)
          "h06300613".U  // 0x4c: addi x12, x0, 99  (Done marker: x12 = 99)
        ) ++ Seq.fill(80)("h00000013".U) ++ Seq(
          "h0000006f".U  // Halt loop
        )
      }
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


