package zaqal.backend.fu.vector

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
 * Vector Register File (VRF) - RVV 1.0 (Phase 9, Day 13-17)
 *
 * Implements 32 architectural vector registers (v0 - v31).
 * Width: Configurable VLEN (128-bit, 256-bit, or 512-bit).
 * Supports:
 * - Multi-port read interface (vs1, vs2, vd/vs3, and mask v0).
 * - Byte-masked write interface for tail and inactive element preservation.
 * - LMUL (Length Multiplier) register grouping.
 * - Complete debug port exposing all 32 vector registers for waveform inspection.
 */
class VectorRegFile(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Read Port 1 (vs1)
    val raddr1   = Input(UInt(phyRegIdxWidth.W))
    val rdata1   = Output(UInt(vLen.W))

    // Read Port 2 (vs2)
    val raddr2   = Input(UInt(phyRegIdxWidth.W))
    val rdata2   = Output(UInt(vLen.W))

    // Read Port 3 (vd / accumulator source)
    val raddr3   = Input(UInt(phyRegIdxWidth.W))
    val rdata3   = Output(UInt(vLen.W))

    // Vector Mask Read Port (Mapped physical register for v0)
    val mask_raddr = Input(UInt(phyRegIdxWidth.W))
    val mask_v0    = Output(UInt(vLen.W))

    // Write Port
    val wen      = Input(Bool())
    val waddr    = Input(UInt(phyRegIdxWidth.W))
    val wdata    = Input(UInt(vLen.W))
    val wmask    = Input(UInt(vLenB.W)) // Byte-level write enable mask (e.g. 16 bits for 128-bit VLEN)

    // Architectural RAT debug mapping input
    val debug_vec_rat = Input(Vec(numVRegs, UInt(phyRegIdxWidth.W)))

    // Debug Ports (Exposes 32 architectural vector registers via RAT mapping)
    val debug_vregs = Output(Vec(numVRegs, UInt(vLen.W)))
  })

  // Physical Vector Registers (XiangShan Kunminghu Parity: vecPhyRegs entries)
  val vregs = RegInit(VecInit(Seq.fill(vecPhyRegs)(0.U(vLen.W))))

  // Asynchronous / Combinational Reads
  io.rdata1  := vregs(io.raddr1)
  io.rdata2  := vregs(io.raddr2)
  io.rdata3  := vregs(io.raddr3)
  io.mask_v0 := vregs(io.mask_raddr)

  // Synchronous Byte-Masked Write
  when(io.wen) {
    val current_val = vregs(io.waddr)
    val new_bytes = Wire(Vec(vLenB, UInt(8.W)))

    for (b <- 0 until vLenB) {
      val byte_we = io.wmask(b)
      val write_byte = io.wdata(b * 8 + 7, b * 8)
      val orig_byte  = current_val(b * 8 + 7, b * 8)
      new_bytes(b) := Mux(byte_we, write_byte, orig_byte)
    }

    vregs(io.waddr) := Cat(new_bytes.reverse)
  }

  // Debug Output: Maps architectural vector registers v0-v31 through VRAT to their physical locations
  for (i <- 0 until numVRegs) {
    io.debug_vregs(i) := vregs(io.debug_vec_rat(i))
  }
}
