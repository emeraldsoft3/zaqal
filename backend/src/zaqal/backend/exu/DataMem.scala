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

  // Memory uses RegInit to allow persistent writes
  // mem has 1024 entries (8KB) to support multi-level page tables:
  // Page 0 (0x0000 - 0x0FF8): Root Level 2 Page Table (PPN=0)
  // Page 1 (0x1000 - 0x1FF8): Level 1 Page Table (PPN=1)
  val memInit = Seq.tabulate(1024) { i =>
    if (i == 0) "h00000000200000DF".U(64.W)       // 0x0000: Sv39 1GB Root Leaf PTE for VPN[2]=0 -> PA 0x80000000 (Test 1)
    else if (i == 1) "h0000000000000401".U(64.W) // 0x0008: Sv39 Level 2 Pointer PTE for VPN[2]=1 -> Points to Level 1 table at PPN=1 (0x1000) (Test 2)
    else if (i == 2) "hFFEEDDCCBBAA9988".U(64.W) // 0x0010: Test 1 loaded data (at PA 0x80000010)
    else if (i == 3) "h706050403020100F".U(64.W) // 0x0018: Offset test
    else if (i == 4) "h1122334455667788".U(64.W) // 0x0020: Test 2 loaded data (at PA 0x80000020)
    else if (i == 513) "h00000000200000DF".U(64.W) // 0x1008: Sv39 Level 1 2MB Megapage Leaf PTE for VPN[1]=1 -> PA 0x80000000 (Test 2)
    else 0.U(64.W)
  }
  val mem = RegInit(VecInit(memInit))

  for (p <- 0 until 2) {
    val idx = io.raddr(p)(12, 3)
    val idx_next = Mux(idx === 1023.U, 0.U, idx + 1.U)
    io.rdata(p) := Cat(mem(idx_next), mem(idx))
  }

  // Basic address decoding using bits (12, 3) for 1024 doubleword capacity (8KB)
  val index = io.addr(12, 3) 
  val index_next = Mux(index === 1023.U, 0.U, index + 1.U)
  io.data := Cat(mem(index_next), mem(index))

  // Dedicated PTW port read
  io.ptw_rdata := mem(io.ptw_raddr(12, 3))

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
