package zaqal.cache.prefetch

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
  * Prefetch Coordinator & Throttling Controller
  * Day 34-35: Coordinates all L1-D prefetch engines (FDP, Stream, SMS, Stride).
  *
  * Features:
  * 1. Multi-Prefetcher Arbitration: Strict priority (FDP -> Stream -> SMS -> Stride).
  * 2. Cross-Prefetcher Deduplication: 4-entry CAM preventing duplicate requests across engines.
  * 3. Hardware Congestion Sensing & Dynamic Throttling:
  *    - GREEN  (0): Bus ready, MSHR free, no demand miss -> Full prefetch to L1.
  *    - YELLOW (1): MSHR busy or bus backpressured -> Drop low confidence (< 2), route streams to L2.
  *    - RED    (2): Active demand miss waiting -> 100% prefetch freeze to prioritize critical loads.
  */
class PrefetchCoordinator(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // 4 Prefetcher Inputs
    val in_fdp    = Flipped(Valid(new PrefetchReqBundle(xLen)))
    val in_stream = Flipped(Valid(new PrefetchReqBundle(xLen)))
    val in_sms    = Flipped(Valid(new PrefetchReqBundle(xLen)))
    val in_stride = Flipped(Valid(new PrefetchReqBundle(xLen)))

    // Congestion & Pipeline Sensing Inputs
    val mshr_busy          = Input(Bool())
    val bus_ready          = Input(Bool())
    val demand_miss_active = Input(Bool())
    val flush              = Input(Bool())

    // Coordinated & Filtered Output Request
    val out_req = Valid(new PrefetchReqBundle(xLen))

    // Debug / Telemetry Monitor Ports
    val throttle_state = Output(UInt(2.W)) // 0: Green, 1: Yellow, 2: Red
    val dropped_count  = Output(UInt(32.W))
    val l2_route_count = Output(UInt(32.W))
  })

  // -------------------------------------------------------------
  // 1. CONGESTION EVALUATION
  // -------------------------------------------------------------
  // Red State: Critical demand miss is active -> Freeze all prefetching
  val isRed = io.demand_miss_active
  // Yellow State: MSHR is busy or memory bus is stalling -> Throttle & route to L2
  val isYellow = io.mshr_busy || !io.bus_ready

  val throttleState = Wire(UInt(2.W))
  when(isRed) {
    throttleState := 2.U
  }.elsewhen(isYellow) {
    throttleState := 1.U
  }.otherwise {
    throttleState := 0.U
  }
  io.throttle_state := throttleState

  // -------------------------------------------------------------
  // 2. MULTI-PREFETCHER PRIORITY ARBITRATION
  // Priority: FDP (Earliest Frontend) -> Stream -> SMS -> Stride
  // -------------------------------------------------------------
  val candValid = io.in_fdp.valid || io.in_stream.valid || io.in_sms.valid || io.in_stride.valid
  val candBits  = Wire(new PrefetchReqBundle(xLen))
  candBits := Mux(io.in_fdp.valid, io.in_fdp.bits,
              Mux(io.in_stream.valid, io.in_stream.bits,
              Mux(io.in_sms.valid, io.in_sms.bits, io.in_stride.bits)))

  // -------------------------------------------------------------
  // 3. CROSS-PREFETCHER DEDUPLICATION (4-Entry CAM)
  // -------------------------------------------------------------
  val historySize = 4
  val recentAddrs = RegInit(VecInit(Seq.fill(historySize)(0.U(xLen.W))))
  val histPtr     = RegInit(0.U(log2Up(historySize).W))

  val isDuplicate = recentAddrs.map(_ === candBits.addr).reduce(_ || _)

  // -------------------------------------------------------------
  // 4. THROTTLING & DESTINATION ROUTING (L1 vs. L2)
  // -------------------------------------------------------------
  // In Red: All prefetch requests dropped
  val passRed = (throttleState =/= 2.U)
  // In Yellow: Low confidence (< 2) dropped
  val passYellow = Mux(throttleState === 1.U, candBits.confidence >= 2.U, true.B)

  val allowPrefetch = candValid && passRed && passYellow && !isDuplicate && !io.flush

  // Target routing:
  // In Yellow state, route passing speculative requests to L2 cache to preserve L1-D capacity
  val routeToL2 = (throttleState === 1.U)

  val finalBits = Wire(new PrefetchReqBundle(xLen))
  finalBits.addr       := candBits.addr
  finalBits.confidence := candBits.confidence
  finalBits.sink_is_l2 := routeToL2

  when(allowPrefetch) {
    recentAddrs(histPtr) := candBits.addr
    histPtr := histPtr + 1.U
  }

  when(io.flush) {
    recentAddrs.foreach(_ := 0.U)
    histPtr := 0.U
  }

  // Registered output stage for clean timing closure
  val outValidReg = RegInit(false.B)
  val outBitsReg  = Reg(new PrefetchReqBundle(xLen))

  outValidReg := allowPrefetch
  outBitsReg  := finalBits

  when(io.flush) {
    outValidReg := false.B
  }

  io.out_req.valid := outValidReg && !io.flush
  io.out_req.bits  := outBitsReg

  // -------------------------------------------------------------
  // 5. TELEMETRY COUNTERS
  // -------------------------------------------------------------
  val dropCnt = RegInit(0.U(32.W))
  val l2Cnt   = RegInit(0.U(32.W))

  val wasDropped = candValid && (!passRed || !passYellow || isDuplicate) && !io.flush
  when(wasDropped) {
    dropCnt := dropCnt + 1.U
  }

  when(allowPrefetch && routeToL2) {
    l2Cnt := l2Cnt + 1.U
  }

  when(io.flush) {
    // Keep counters monotonic for telemetry profiling
  }

  io.dropped_count  := dropCnt
  io.l2_route_count := l2Cnt
}
