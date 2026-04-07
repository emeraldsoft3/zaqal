package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class DataMem(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val addr = Input(UInt(xLen.W))
    val data = Output(UInt(xLen.W))
  })

  // Pre-initialized memory for testing
  // Indices are 8-byte aligned (Doublewords)
  val mem = VecInit(Seq(
    "hAABBCCDD11223344".U, // 0x00: Distinct bytes
    "h5566778899AABBCC".U, // 0x08: Distinct bytes
    "hFFEEDDCCBBAA9988".U, // 0x10: MSB set (0xFF)
    "h706050403020100F".U  // 0x18: Offset test
  ).padTo(64, 0.U))

  // Basic address decoding (ignoring higher bits for now)
  // We divide by 8 because the Vec is indexed by Doubleword (64-bit)
  val index = io.addr(8, 3) 
  io.data := mem(index)
}
