package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class LSU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1  = Input(UInt(xLen.W)) // Base address
    val imm   = Input(SInt(xLen.W)) // Offset
    val dec   = Input(new DecodeSignals)
    
    // Memory Interface
    val mem_addr = Output(UInt(xLen.W))
    val mem_data = Input(UInt(xLen.W)) // Raw 64-bit data from memory

    val result   = Output(UInt(xLen.W)) // Extended data for WB
  })

  // Address Calculation
  val addr = (io.src1.asSInt + io.imm).asUInt
  io.mem_addr := addr

  // Data Extraction and Extension
  // The DataMem returns a 64-bit aligned doubleword. 
  // We need to pick the right byte/halfword/word based on the lower bits of 'addr'.
  val offset = addr(2, 0) // Byte offset within the 64-bit word

  val res = WireDefault(0.U(xLen.W))

  // Byte (LB/LBU)
  val byte = (io.mem_data >> (offset << 3))(7, 0)
  
  // Halfword (LH/LHU) - assumes 2-byte alignment for simplicity in Day 13
  val half = (io.mem_data >> (offset(2, 1) << 4))(15, 0)
  
  // Word (LW/LWU) - assumes 4-byte alignment
  val word = (io.mem_data >> (offset(2) << 5))(31, 0)

  // Doubleword (LD)
  val dword = io.mem_data

  when(io.dec.is_lb) {
    res := byte.asSInt.pad(xLen).asUInt
  } .elsewhen(io.dec.is_lbu) {
    res := byte.asUInt.pad(xLen)
  } .elsewhen(io.dec.is_lh) {
    res := half.asSInt.pad(xLen).asUInt
  } .elsewhen(io.dec.is_lhu) {
    res := half.asUInt.pad(xLen)
  } .elsewhen(io.dec.is_lw) {
    res := word.asSInt.pad(xLen).asUInt
  } .elsewhen(io.dec.is_lwu) {
    res := word.asUInt.pad(xLen)
  } .elsewhen(io.dec.is_ld) {
    res := dword
  }

  io.result := res
}
