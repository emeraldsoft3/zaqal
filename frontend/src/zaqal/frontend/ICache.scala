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
        "h80000537".U, // 0x00: lui x10, 0x80000        -> x10 = 0x80000000 (DataMem Base)
        "h25042100".U, // 0x04: c.fld f8, 0(x10)  [16b] -> f8 = [0x00] = 0xAABBCCDD11223344
                       // 0x06: c.fld f9, 8(x10)  [16b] -> f9 = [0x08] = 0x5566778899AABBCC
        "h00940553".U, // 0x08: fadd.s f10, f8, f9      -> f10 = f8[31:0] + f9[31:0]
        "h80000137".U, // 0x0C: lui x2, 0x80000         -> sp = 0x80000000
        "h02010113".U, // 0x10: addi x2, x2, 32         -> sp = 0x80000020 (DataMem Offset 32)
        "h2582A022".U, // 0x14: c.fsdsp f8, 0(sp) [16b] -> [sp+0] = f8 (Store Double)
                       // 0x16: c.fldsp f11, 0(sp)[16b] -> f11 = [sp+0] = f8 (Load Double)
        "h00100613".U, // 0x18: li x12, 1               -> Success flag
        "h0000006f".U  // 0x1C: j 0x1C                  -> Final halt loop
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


