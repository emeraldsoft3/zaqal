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
    val train         = Flipped(Valid(new L1PrefetchTrainBundle(xLen)))
    val branch_signal = Input(Valid(new BranchPredictionBus))
    val prefetch_req  = Decoupled(new PrefetchReqBundle(xLen))
    val flush         = Input(Bool())
  })

  val fdpPrefetcher    = Module(new FDPrefetcher(numEntries = 16))
  val stridePrefetcher = Module(new StridePrefetcher(numEntries = 16, lookaheadBlocks = 2))
  val streamPrefetcher = Module(new StreamPrefetcher(numStreams = 8, lookaheadBlocks = 2))
  val smsPrefetcher    = Module(new SMSPrefetcher(numAGT = 8, numPHT = 32))

  fdpPrefetcher.io.flush    := io.flush
  stridePrefetcher.io.flush := io.flush
  streamPrefetcher.io.flush := io.flush
  smsPrefetcher.io.flush    := io.flush

  // Connect frontend branch signals to FDP
  fdpPrefetcher.io.branch_signal := io.branch_signal

  // Train FDP prefetcher
  fdpPrefetcher.io.train.valid     := io.train.valid
  fdpPrefetcher.io.train.bits.pc   := io.train.bits.pc
  fdpPrefetcher.io.train.bits.addr := io.train.bits.addr

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

  // Arbiter: FDP (Earliest Frontend lookahead), Stream, and SMS take priority over Stride
  val fdpReq    = fdpPrefetcher.io.prefetch_req
  val streamReq = streamPrefetcher.io.prefetch_req
  val smsReq    = smsPrefetcher.io.prefetch_req
  val strideReq = stridePrefetcher.io.prefetch_req

  val arbValid = fdpReq.valid || streamReq.valid || smsReq.valid || strideReq.valid
  val arbBits  = Wire(new PrefetchReqBundle(xLen))
  arbBits := Mux(fdpReq.valid, fdpReq.bits,
             Mux(streamReq.valid, streamReq.bits,
             Mux(smsReq.valid, smsReq.bits, strideReq.bits)))

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
