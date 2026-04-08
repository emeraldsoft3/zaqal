package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class DataMem(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val addr  = Input(UInt(xLen.W))
    val data  = Output(UInt(xLen.W))
    
    val wen   = Input(Bool())
    val wmask = Input(UInt(8.W)) // Byte strobe
    val wdata = Input(UInt(xLen.W))
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
  io.data := mem(index)

  // Masked Write Implementation
  val bitMask = Cat(Seq.tabulate(8)(i => Fill(8, io.wmask(i))).reverse)
  
  when(io.wen) {
    mem(index) := (mem(index) & ~bitMask) | (io.wdata & bitMask)
    printf(p"DATA MEM WRITE: addr=${Hexadecimal(io.addr)} index=$index data=${Hexadecimal(io.wdata)} mask=${Binary(io.wmask)}\n")
  }
}
