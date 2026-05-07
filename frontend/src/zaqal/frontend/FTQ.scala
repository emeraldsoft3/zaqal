package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class FTQ(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val fromBpu   = Flipped(Decoupled(new FetchRequest))
    val toIfu     = Decoupled(new FetchRequest)
    val toICache  = Decoupled(new FetchRequest)
    val readPtr   = Input(UInt(ftqPtrWidth.W))
    val readData  = Output(new FetchPacket)
    val flush     = Input(Bool())
    val occupancy = Output(UInt((ftqPtrWidth + 1).W))
  })

  // Manual Circular Queue for Metadata (XiangShan style)
  val ram = Reg(Vec(ftqEntries, new FetchRequest))
  val enqPtr = RegInit(0.U(ftqPtrWidth.W))
  val deqPtr = RegInit(0.U(ftqPtrWidth.W)) // This acts as the 'next to fetch' pointer
  val count  = RegInit(0.U((ftqPtrWidth + 1).W))

  val full  = count === ftqEntries.U
  val empty = count === 0.U

  // 1. Enqueue from BPU
  io.fromBpu.ready := !full
  when(io.fromBpu.fire) {
    val newReq = Wire(new FetchRequest)
    newReq := io.fromBpu.bits
    newReq.ftqPtr := enqPtr // Tag it with the entry index
    
    ram(enqPtr) := newReq
    enqPtr := enqPtr + 1.U
  }

  // 2. Issuing to IFU and ICache
  io.toIfu.valid := !empty
  io.toIfu.bits  := ram(deqPtr)

  io.toICache.valid := io.toIfu.valid
  io.toICache.bits  := io.toIfu.bits

  when(io.toIfu.fire) {
    deqPtr := deqPtr + 1.U
  }

  // 3. Backend Read Port (This is metadata only now)
  val readPacket = Wire(new FetchPacket)
  readPacket := DontCare
  for (i <- 0 until predictWidth) {
    readPacket.pc(i) := ram(io.readPtr).pc + (i * 2).U
    readPacket.exception_type(i) := 0.U
    readPacket.debug_seqNum(i)   := 0.U
  }
  readPacket.mask       := ram(io.readPtr).mask
  readPacket.prediction := ram(io.readPtr).prediction
  readPacket.ftqPtr     := io.readPtr

  io.readData := readPacket

  // Flush and Count Logic
  when(io.flush) {
    enqPtr := 0.U
    deqPtr := 0.U
    count  := 0.U
  } .otherwise {
    val enq = io.fromBpu.fire
    val deq = io.toIfu.fire
    when(enq && !deq) {
      count := count + 1.U
    } .elsewhen(!enq && deq) {
      count := count - 1.U
    }
  }
  
  io.occupancy := count
  chisel3.dontTouch(io.occupancy)
}
