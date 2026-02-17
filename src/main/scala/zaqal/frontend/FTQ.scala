package zaqal.frontend

import chisel3._
import chisel3.util._
import zaqal._

class FTQ extends Module {
  val io = IO(new Bundle {
    val fromBpu   = Flipped(Decoupled(new FetchRequest))
    val toIfu     = Decoupled(new FetchRequest)
    val toICache  = Decoupled(new FetchRequest)
    val readPtr   = Input(UInt(6.W))
    val readData  = Output(new FetchPacket)
    val flush     = Input(Bool())
    val occupancy = Output(UInt(7.W))
  })

  // Manual Circular Queue for Metadata (XiangShan style)
  val entriesSize = 64
  val ram = Reg(Vec(entriesSize, new FetchRequest))
  val enqPtr = RegInit(0.U(6.W))
  val deqPtr = RegInit(0.U(6.W)) // This acts as the 'next to fetch' pointer
  val count  = RegInit(0.U(7.W))

  val full  = count === entriesSize.U
  val empty = count === 0.U

  // 1. Enqueue from BPU
  io.fromBpu.ready := !full
  when(io.fromBpu.fire) {
    val newReq = Wire(new FetchRequest)
    newReq := io.fromBpu.bits
    newReq.ftqPtr := enqPtr // Tag it with the entry index
    
    ram(enqPtr) := newReq
    enqPtr := enqPtr + 1.U
    count  := count + 1.U
  }

  // 2. Issuing to IFU and ICache
  io.toIfu.valid := !empty
  io.toIfu.bits  := ram(deqPtr)

  io.toICache.valid := io.toIfu.valid
  io.toICache.bits  := io.toIfu.bits

  when(io.toIfu.fire) {
    deqPtr := deqPtr + 1.U
    count  := count - 1.U
  }

  // 3. Backend Read Port (This is metadata only now)
  val readPacket = Wire(new FetchPacket)
  readPacket := DontCare
  readPacket.pc         := ram(io.readPtr).pc
  readPacket.mask       := ram(io.readPtr).mask
  readPacket.prediction := ram(io.readPtr).prediction
  readPacket.ftqPtr     := io.readPtr

  io.readData := readPacket

  // Flush logic
  when(io.flush) {
    enqPtr := 0.U
    deqPtr := 0.U
    count  := 0.U
  }
  
  io.occupancy := count
  chisel3.dontTouch(io.occupancy)
}