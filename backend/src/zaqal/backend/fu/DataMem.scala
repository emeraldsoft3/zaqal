package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class DataMem(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val addr  = Input(UInt(xLen.W))
    val data  = Output(UInt((xLen * 2).W)) // Returns 128-bit window
    
    val wen   = Input(Bool())
    val wmask = Input(UInt(16.W))          // 16-bit strobe for 128 bits
    val wdata = Input(UInt((xLen * 2).W))
  })

  // Memory now uses RegInit to allow persistent writes
  val mem = RegInit(VecInit(Seq(
    "hAABBCCDD11223344".U, // 0x00: Distinct bytes
    "h5566778899AABBCC".U, // 0x08: Distinct bytes
    "hFFEEDDCCBBAA9988".U, // 0x10: MSB set (0xFF)
    "h706050403020100F".U  // 0x18: Offset test
  ).padTo(64, 0.U)))

  // Basic address decoding (ignoring higher bits for now)
  // We divide by 8 because the Vec is indexed by Doubleword (64-bit)
  val index = io.addr(8, 3) 
  
  // Read 128-bit window (current + next word)
  // We handle the wrap-around case by padding the memory or checking bounds.
  // For simplicity, we assume we don't go out of bounds of the 64-entry vec.
  val index_next = index + 1.U
  io.data := Cat(mem(index_next), mem(index))

  // Masked Write Implementation (16-bit)
  val bitMask = Cat(Seq.tabulate(16)(i => Fill(8, io.wmask(i))).reverse)
  
  when(io.wen) {
    val fullData = (io.data & ~bitMask) | (io.wdata & bitMask)
    mem(index)      := fullData(63, 0)
    mem(index_next) := fullData(127, 64)
    
    printf(p"DATA MEM WRITE: addr=${Hexadecimal(io.addr)} index=$index wmask=${Binary(io.wmask)}\n")
    printf(p"                index=${index} data=${Hexadecimal(fullData(63,0))}\n")
    printf(p"                index=${index_next} data=${Hexadecimal(fullData(127,64))}\n")
  }
}
