package zaqal.backend.exu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class DataMem(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val raddr = Vec(2, Input(UInt(xLen.W)))
    val rdata = Vec(2, Output(UInt((xLen * 2).W)))
    val addr  = Input(UInt(xLen.W))
    val data  = Output(UInt((xLen * 2).W)) // Returns 128-bit window
    
    val wen   = Input(Bool())
    val wmask = Input(UInt(16.W))          // 16-bit strobe for 128 bits
    val wdata = Input(UInt((xLen * 2).W))

    // Dedicated Page Table Walker Read Port
    val ptw_raddr = Input(UInt(xLen.W))
    val ptw_rdata = Output(UInt(64.W))
  })

  // Memory now uses RegInit to allow persistent writes
  // mem(0) initialized as Sv39 Level 2 1GB Gigapage Leaf PTE (PPN=0x80000, D=1, A=1, U=1, X=1, W=1, R=1, V=1)
  val mem = RegInit(VecInit(Seq(
    "h00000000200000DF".U, // 0x00: Sv39 1GB Root Leaf PTE for VPN[2]=0 -> PA 0x80000000
    "h5566778899AABBCC".U, // 0x08: Distinct bytes
    "hFFEEDDCCBBAA9988".U, // 0x10: MSB set (0xFF)
    "h706050403020100F".U  // 0x18: Offset test
  ).padTo(64, 0.U)))

  for (p <- 0 until 2) {
    val idx = io.raddr(p)(8, 3)
    val idx_next = idx + 1.U
    io.rdata(p) := Cat(mem(idx_next), mem(idx))
  }

  // Basic address decoding (ignoring higher bits for now)
  // We divide by 8 because the Vec is indexed by Doubleword (64-bit)
  val index = io.addr(8, 3) 
  val index_next = index + 1.U
  io.data := Cat(mem(index_next), mem(index))

  // Dedicated PTW port read
  io.ptw_rdata := mem(io.ptw_raddr(8, 3))

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
