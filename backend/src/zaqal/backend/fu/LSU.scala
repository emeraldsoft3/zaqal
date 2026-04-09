package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class LSU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1  = Input(UInt(xLen.W)) // Base address
    val src2  = Input(UInt(xLen.W)) // Data to store
    val imm   = Input(SInt(xLen.W)) // Offset
    val dec   = Input(new DecodeSignals)
    
    // Memory Interface (Updated for 128-bit unaligned support)
    val mem_addr  = Output(UInt(xLen.W))
    val mem_data  = Input(UInt((xLen * 2).W)) // 128-bit window (current + next word)
    val mem_wen   = Output(Bool())
    val mem_wmask = Output(UInt(16.W))        // 16-bit strobe for 128 bits
    val mem_wdata = Output(UInt((xLen * 2).W))

    val result   = Output(UInt(xLen.W)) // Extended data for WB
  })

  // Address Calculation
  val addr = (io.src1.asSInt + io.imm).asUInt
  io.mem_addr := addr

  // Data Extraction and Extension (Generic for any offset)
  val offset = addr(2, 0) // Byte offset (0-7)
  
  // Shift the 128-bit window right by the byte offset
  val shifted_data = io.mem_data >> (offset << 3)
  
  val res = WireDefault(0.U(xLen.W))

  when(io.dec.is_lb) {
    res := shifted_data(7, 0).asSInt.pad(xLen).asUInt
  } .elsewhen(io.dec.is_lbu) {
    res := shifted_data(7, 0).pad(xLen)
  } .elsewhen(io.dec.is_lh) {
    res := shifted_data(15, 0).asSInt.pad(xLen).asUInt
  } .elsewhen(io.dec.is_lhu) {
    res := shifted_data(15, 0).pad(xLen)
  } .elsewhen(io.dec.is_lw) {
    res := shifted_data(31, 0).asSInt.pad(xLen).asUInt
  } .elsewhen(io.dec.is_lwu) {
    res := shifted_data(31, 0).pad(xLen)
  } .elsewhen(io.dec.is_ld) {
    res := shifted_data(63, 0)
  }

  io.result := res
  
  // Store Logic (Handling 128-bit width)
  val wmask = WireDefault(0.U(16.W))
  val wdata = WireDefault(0.U((xLen * 2).W))
  
  when(io.dec.is_sb) {
    wmask := "h0001".U(16.W) << offset
    wdata := io.src2(7, 0).pad(xLen * 2) << (offset << 3)
  } .elsewhen(io.dec.is_sh) {
    wmask := "h0003".U(16.W) << offset
    wdata := io.src2(15, 0).pad(xLen * 2) << (offset << 3)
  } .elsewhen(io.dec.is_sw) {
    wmask := "h000f".U(16.W) << offset
    wdata := io.src2(31, 0).pad(xLen * 2) << (offset << 3)
  } .elsewhen(io.dec.is_sd) {
    wmask := "h00ff".U(16.W) << offset
    wdata := io.src2(63, 0).pad(xLen * 2) << (offset << 3)
  }
  
  io.mem_wen   := io.dec.is_store
  io.mem_wmask := wmask
  io.mem_wdata := wdata
}
