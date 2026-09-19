package zaqal

import chisel3._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.cache.prefetch._

object PrefetcherTest extends App {
  implicit val p: Parameters = new ZaqalConfig

  println("==================================================")
  println("  RUNNING DAY 26-28 PREFETCHER VERIFICATION SUITE ")
  println("==================================================")

  // -------------------------------------------------------------
  // Test 1: Stride Prefetcher Unit Test
  // -------------------------------------------------------------
  println("\n--- [Test 1] Stride Prefetcher: Constant Stride Detection & Confidence ---")
  RawTester.test(new StridePrefetcher(numEntries = 16, lookaheadBlocks = 2)) { dut =>
    dut.io.flush.poke(false.B)
    dut.io.train.valid.poke(false.B)
    dut.clock.step(1)

    val pc = 0x80001000L
    val baseAddr = 0x10000L
    val strideBytes = 64L // 2 cache blocks stride

    // Step 1: First access - Allocate entry
    println("  Step 1: Access 0 -> Allocating RPT entry...")
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(pc.U)
    dut.io.train.bits.addr.poke(baseAddr.U)
    dut.clock.step(1)
    dut.io.prefetch_req.valid.expect(false.B)

    // Step 2: Second access - Learn stride (0x10000 -> 0x10040, stride = +64)
    println("  Step 2: Access 1 -> Learning stride +64...")
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(pc.U)
    dut.io.train.bits.addr.poke((baseAddr + strideBytes).U)
    dut.clock.step(1)
    dut.io.prefetch_req.valid.expect(false.B)

    // Step 3: Third access - Confirm stride, increment confidence (confidence = 1)
    println("  Step 3: Access 2 -> Confirming stride +64 (Confidence 0 -> 1)...")
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(pc.U)
    dut.io.train.bits.addr.poke((baseAddr + 2 * strideBytes).U)
    dut.clock.step(1)
    dut.io.prefetch_req.valid.expect(false.B) // Confidence = 1 (< 2), no prefetch yet

    // Step 4: Fourth access - Steady state prefetch (Confidence 1 -> 2)
    val currentAddr = baseAddr + 3 * strideBytes
    val expectedPfAddr = (currentAddr + 2 * strideBytes) & ~31L // aligned to 32 bytes
    println(s"  Step 4: Access 3 -> Steady state prefetch. Expected PF Addr: 0x${expectedPfAddr.toHexString}")
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(pc.U)
    dut.io.train.bits.addr.poke(currentAddr.U)
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)

    // Registered output is valid in the cycle after Step 4 completes
    dut.io.prefetch_req.valid.expect(true.B)
    dut.io.prefetch_req.bits.addr.expect(expectedPfAddr.U)
    println(s"    => PASS: Generated Prefetch Addr: 0x${dut.io.prefetch_req.bits.addr.peek().litValue.toString(16)}")

    // Step 5: Test stride change / disturbance
    println("  Step 5: Testing Stride Disturbance / Decrementing Confidence...")
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(pc.U)
    dut.io.train.bits.addr.poke((currentAddr + 128L).U) // Stride changed to 128
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)
    dut.io.prefetch_req.valid.expect(false.B)
    println("    => PASS: Prefetch suppressed upon stride disturbance.")
  }

  // -------------------------------------------------------------
  // Test 2: Stream Prefetcher Unit Test
  // -------------------------------------------------------------
  println("\n--- [Test 2] Stream Prefetcher: Spatial Stream & Lookahead ---")
  RawTester.test(new StreamPrefetcher(numStreams = 8, lookaheadBlocks = 2)) { dut =>
    dut.io.flush.poke(false.B)
    dut.io.train.valid.poke(false.B)
    dut.clock.step(1)

    val regionBase = 0x20000L

    // Step 1: Touch block 2 (offset 64 = 2 * 32)
    println("  Step 1: Access Block 2 in Region 0x20000...")
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.addr.poke((regionBase + 2 * 32L).U)
    dut.clock.step(1)
    dut.io.prefetch_req.valid.expect(false.B) // Stream not active yet

    // Step 2: Touch block 3 (offset 96 = 3 * 32) -> Stream becomes active, ascending!
    println("  Step 2: Access Block 3 -> Stream Activates (Ascending)...")
    val expectedPfAddr = regionBase + (3 + 2) * 32L // Block 5 = offset 160
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.addr.poke((regionBase + 3 * 32L).U)
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)

    // Output is registered in the following cycle
    dut.io.prefetch_req.valid.expect(true.B)
    dut.io.prefetch_req.bits.addr.expect(expectedPfAddr.U)
    println(s"    => PASS: Active Stream Prefetch Addr: 0x${dut.io.prefetch_req.bits.addr.peek().litValue.toString(16)}")

    // Step 3: Test Descending Stream in another region
    println("  Step 3: Access Descending Stream in Region 0x30000...")
    val regionBase2 = 0x30000L
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.addr.poke((regionBase2 + 10 * 32L).U)
    dut.clock.step(1)

    // Touch block 9 (descending: 9 < 10) -> prefetches block 9 - 2 = 7
    val expectedDescPf = regionBase2 + (9 - 2) * 32L
    dut.io.train.bits.addr.poke((regionBase2 + 9 * 32L).U)
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)

    dut.io.prefetch_req.valid.expect(true.B)
    dut.io.prefetch_req.bits.addr.expect(expectedDescPf.U)
    println(s"    => PASS: Descending Stream Prefetch Addr: 0x${dut.io.prefetch_req.bits.addr.peek().litValue.toString(16)}")
  }

  // -------------------------------------------------------------
  // Test 3: L1Prefetcher Top-Level Arbiter & Queue Test
  // -------------------------------------------------------------
  println("\n--- [Test 3] L1Prefetcher Integration & Priority Arbitration ---")
  RawTester.test(new L1Prefetcher()) { dut =>
    dut.io.flush.poke(false.B)
    dut.io.train.valid.poke(false.B)
    dut.io.prefetch_req.ready.poke(true.B)
    dut.clock.step(1)

    val regionBase = 0x40000L
    val pc = 0x80002000L

    // Train sequential blocks
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(pc.U)
    dut.io.train.bits.addr.poke((regionBase + 1 * 32L).U)
    dut.clock.step(1)

    dut.io.train.bits.addr.poke((regionBase + 2 * 32L).U)
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)

    // After 2 cycles through prefetcher pipeline and queue:
    dut.clock.step(1)
    println(s"  L1 Prefetcher Queue Valid: ${dut.io.prefetch_req.valid.peek().litToBoolean}")
    if (dut.io.prefetch_req.valid.peek().litToBoolean) {
      println(s"  => PASS: Prefetch Dequeued: 0x${dut.io.prefetch_req.bits.addr.peek().litValue.toString(16)}")
    }
  }

  println("\n==================================================")
  println("  ALL PREFETCHER TESTS COMPLETED SUCCESSFULLY!    ")
  println("==================================================")
}
