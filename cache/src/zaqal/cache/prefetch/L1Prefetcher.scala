package zaqal.cache.prefetch

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class L1PrefetchTrainBundle(val xLen: Int) extends Bundle {
  val pc   = UInt(xLen.W)
  val addr = UInt(xLen.W)
}

class L1Prefetcher(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val train        = Flipped(Valid(new L1PrefetchTrainBundle(xLen)))
    val prefetch_req = Decoupled(new PrefetchReqBundle(xLen))
    val flush        = Input(Bool())
  })

  val stridePrefetcher = Module(new StridePrefetcher(numEntries = 16, lookaheadBlocks = 2))
  val streamPrefetcher = Module(new StreamPrefetcher(numStreams = 8, lookaheadBlocks = 2))
  val smsPrefetcher    = Module(new SMSPrefetcher(numAGT = 8, numPHT = 32))

  stridePrefetcher.io.flush := io.flush
  streamPrefetcher.io.flush := io.flush
  smsPrefetcher.io.flush    := io.flush

  // Train stride prefetcher
  stridePrefetcher.io.train.valid     := io.train.valid
  stridePrefetcher.io.train.bits.pc   := io.train.bits.pc
  stridePrefetcher.io.train.bits.addr := io.train.bits.addr

  // Train stream prefetcher
  streamPrefetcher.io.train.valid     := io.train.valid
  streamPrefetcher.io.train.bits.addr := io.train.bits.addr

  // Train SMS prefetcher
  smsPrefetcher.io.train.valid        := io.train.valid
  smsPrefetcher.io.train.bits.pc      := io.train.bits.pc
  smsPrefetcher.io.train.bits.addr    := io.train.bits.addr

  // Arbiter: Stream and SMS take priority over Stride (matches XiangShan Kunminghu policy)
  val streamReq = streamPrefetcher.io.prefetch_req
  val smsReq    = smsPrefetcher.io.prefetch_req
  val strideReq = stridePrefetcher.io.prefetch_req

  val arbValid = streamReq.valid || smsReq.valid || strideReq.valid
  val arbBits  = Wire(new PrefetchReqBundle(xLen))
  arbBits := Mux(streamReq.valid, streamReq.bits,
             Mux(smsReq.valid, smsReq.bits, strideReq.bits))

  // Recent prefetch filter (suppress back-to-back duplicate requests to the same cache block)
  val lastPfAddr = RegInit(0.U(xLen.W))
  val isDuplicate = (arbBits.addr === lastPfAddr)
  val filteredValid = arbValid && !isDuplicate

  when(filteredValid) {
    lastPfAddr := arbBits.addr
  }
  when(io.flush) {
    lastPfAddr := 0.U
  }

  // 8-entry FIFO queue to buffer multi-block prefetch bursts
  val pfQueue = Module(new Queue(new PrefetchReqBundle(xLen), entries = 8))
  pfQueue.io.enq.valid := filteredValid
  pfQueue.io.enq.bits  := arbBits

  io.prefetch_req <> pfQueue.io.deq
}
