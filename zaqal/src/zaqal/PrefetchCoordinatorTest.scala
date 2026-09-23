package zaqal

import chisel3._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.cache.prefetch._

object PrefetchCoordinatorTest extends App {
  implicit val p: Parameters = new ZaqalConfig

  println("==================================================")
  println("  RUNNING DAY 34-35 PREFETCH COORDINATOR TESTS    ")
  println("==================================================")

  // -------------------------------------------------------------
  // Test 1: PrefetchCoordinator Unit Test - Congestion States & Throttling
  // -------------------------------------------------------------
  println("\n--- [Test 1] PrefetchCoordinator: Green, Yellow & Red State Transitions ---")
  RawTester.test(new PrefetchCoordinator()) { dut =>
    dut.io.flush.poke(false.B)
    dut.io.in_fdp.valid.poke(false.B)
    dut.io.in_stream.valid.poke(false.B)
    dut.io.in_sms.valid.poke(false.B)
    dut.io.in_stride.valid.poke(false.B)

    dut.io.mshr_busy.poke(false.B)
    dut.io.bus_ready.poke(true.B)
    dut.io.demand_miss_active.poke(false.B)
    dut.clock.step(1)

    // 1. GREEN State: Bus ready, MSHR idle, no demand miss
    println("  Step 1: Testing GREEN State (Normal L1 Prefetch)...")
    dut.io.throttle_state.expect(0.U)

    dut.io.in_fdp.valid.poke(true.B)
    dut.io.in_fdp.bits.addr.poke(0x10000.U)
    dut.io.in_fdp.bits.confidence.poke(2.U)
    dut.io.in_fdp.bits.sink_is_l2.poke(false.B)
    dut.clock.step(1)

    dut.io.out_req.valid.expect(true.B)
    dut.io.out_req.bits.addr.expect(0x10000.U)
    dut.io.out_req.bits.sink_is_l2.expect(false.B)
    println(s"  => PASS: Green State Prefetch allowed to L1: 0x${dut.io.out_req.bits.addr.peek().litValue.toString(16)}")

    // Deduplication check: duplicate address 0x10000 in CAM should be filtered
    dut.clock.step(1)
    dut.io.out_req.valid.expect(false.B)
    println("  => PASS: Cross-prefetcher duplicate suppressed by CAM filter!")

    dut.io.in_fdp.valid.poke(false.B)

    // 2. YELLOW State: Bus backpressure (!bus_ready) or MSHR busy
    println("\n  Step 2: Testing YELLOW State (Throttling & L2 Routing)...")
    dut.io.bus_ready.poke(false.B) // Simulate downstream memory bus congestion
    dut.clock.step(1)
    dut.io.throttle_state.expect(1.U)

    // Low confidence request (confidence = 1) -> Must be dropped
    println("    Testing low-confidence filter (Confidence = 1)...")
    dut.io.in_stride.valid.poke(true.B)
    dut.io.in_stride.bits.addr.poke(0x20000.U)
    dut.io.in_stride.bits.confidence.poke(1.U)
    dut.io.in_stride.bits.sink_is_l2.poke(false.B)
    dut.clock.step(1)
    dut.io.out_req.valid.expect(false.B)
    println("    => PASS: Low-confidence speculative request dropped during bus congestion!")

    // High confidence request (confidence = 3) -> Allowed, but routed to L2
    println("    Testing high-confidence request routed to L2...")
    dut.io.in_stride.bits.confidence.poke(3.U)
    dut.clock.step(1)
    dut.io.out_req.valid.expect(true.B)
    dut.io.out_req.bits.addr.expect(0x20000.U)
    dut.io.out_req.bits.sink_is_l2.expect(true.B) // Rerouted to L2 to protect L1-D!
    println(s"    => PASS: Speculative request routed to L2 (sink_is_l2 = ${dut.io.out_req.bits.sink_is_l2.peek().litToBoolean})!")

    dut.io.in_stride.valid.poke(false.B)

    // 3. RED State: Active demand miss waiting for memory bus
    println("\n  Step 3: Testing RED State (Critical Demand Miss Override)...")
    dut.io.demand_miss_active.poke(true.B)
    dut.clock.step(1)
    dut.io.throttle_state.expect(2.U)

    // Even highest confidence FDP request must be FROZEN
    dut.io.in_fdp.valid.poke(true.B)
    dut.io.in_fdp.bits.addr.poke(0x30000.U)
    dut.io.in_fdp.bits.confidence.poke(3.U)
    dut.io.in_fdp.bits.sink_is_l2.poke(false.B)
    dut.clock.step(1)
    dut.io.out_req.valid.expect(false.B)
    println("  => PASS: Prefetches 100% frozen during active demand miss to prioritize CPU load!")
  }

  // -------------------------------------------------------------
  // Test 2: Full L1Prefetcher Top-Level Integration with Coordinator
  // -------------------------------------------------------------
  println("\n--- [Test 2] L1Prefetcher Top-Level Integration & Throttle Sensing ---")
  RawTester.test(new L1Prefetcher()) { dut =>
    dut.io.flush.poke(false.B)
    dut.io.train.valid.poke(false.B)
    dut.io.branch_signal.valid.poke(false.B)
    dut.io.branch_signal.bits.pc.poke(0.U)
    dut.io.branch_signal.bits.target.poke(0.U)
    dut.io.branch_signal.bits.taken.poke(false.B)
    dut.io.prefetch_req.ready.poke(true.B)

    dut.io.mshr_busy.poke(false.B)
    dut.io.bus_ready.poke(true.B)
    dut.io.demand_miss_active.poke(false.B)
    dut.clock.step(1)

    // In normal state, train sequential stream
    val regionBase = 0x50000L
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(0x80004000L.U)
    dut.io.train.bits.addr.poke((regionBase + 1 * 32L).U)
    dut.clock.step(1)

    dut.io.train.bits.addr.poke((regionBase + 2 * 32L).U)
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)

    dut.clock.step(2)
    println(s"  L1Prefetcher Throttle State (Normal): ${dut.io.throttle_state.peek().litValue} (0=Green)")
    dut.io.throttle_state.expect(0.U)

    // Now assert demand miss active: verify throttle transitions to RED (2)
    dut.io.demand_miss_active.poke(true.B)
    dut.clock.step(1)
    println(s"  L1Prefetcher Throttle State (Demand Miss): ${dut.io.throttle_state.peek().litValue} (2=Red)")
    dut.io.throttle_state.expect(2.U)
    println("  => PASS: L1Prefetcher correctly senses and propagates hardware congestion!")
  }

  println("\n==================================================")
  println("  ALL PREFETCH COORDINATOR TESTS PASSED!          ")
  println("==================================================")
}
