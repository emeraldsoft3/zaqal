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
    val train              = Flipped(Valid(new L1PrefetchTrainBundle(xLen)))
    val branch_signal      = Input(Valid(new BranchPredictionBus))
    val prefetch_req       = Decoupled(new PrefetchReqBundle(xLen))
    val mshr_busy          = Input(Bool())
    val bus_ready          = Input(Bool())
    val demand_miss_active = Input(Bool())
    val flush              = Input(Bool())

    // Telemetry & Debug
    val throttle_state     = Output(UInt(2.W))
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

  // Day 34-35: Prefetch Coordinator & Throttling Controller
  val coordinator = Module(new PrefetchCoordinator)
  coordinator.io.in_fdp    := fdpPrefetcher.io.prefetch_req
  coordinator.io.in_stream := streamPrefetcher.io.prefetch_req
  coordinator.io.in_sms    := smsPrefetcher.io.prefetch_req
  coordinator.io.in_stride := stridePrefetcher.io.prefetch_req

  coordinator.io.mshr_busy          := io.mshr_busy
  coordinator.io.bus_ready          := io.bus_ready
  coordinator.io.demand_miss_active := io.demand_miss_active
  coordinator.io.flush              := io.flush

  io.throttle_state := coordinator.io.throttle_state

  // 8-entry FIFO queue to buffer multi-block prefetch bursts
  val pfQueue = Module(new Queue(new PrefetchReqBundle(xLen), entries = 8))
  pfQueue.io.enq.valid := coordinator.io.out_req.valid
  pfQueue.io.enq.bits  := coordinator.io.out_req.bits

  io.prefetch_req <> pfQueue.io.deq
}
