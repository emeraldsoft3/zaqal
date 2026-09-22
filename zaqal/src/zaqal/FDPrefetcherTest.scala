package zaqal

import chisel3._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.cache.prefetch._

object FDPrefetcherTest extends App {
  implicit val p: Parameters = new ZaqalConfig

  println("==================================================")
  println("  RUNNING DAY 32-33 FDP PREFETCHER TEST SUITE     ")
  println("==================================================")

  // -------------------------------------------------------------
  // Test 1: FDPrefetcher Unit Test - Stride Training & Branch Signal Prefetch
  // -------------------------------------------------------------
  println("\n--- [Test 1] FDPrefetcher: Branch Signal Driven Cache Warm-Up ---")
  RawTester.test(new FDPrefetcher(numEntries = 16)) { dut =>
    dut.io.flush.poke(false.B)
    dut.io.train.valid.poke(false.B)
    dut.io.branch_signal.valid.poke(false.B)
    dut.io.branch_signal.bits.pc.poke(0.U)
    dut.io.branch_signal.bits.target.poke(0.U)
    dut.io.branch_signal.bits.taken.poke(false.B)
    dut.clock.step(1)

    val branchPc = 0x80001020L
    val targetPc = 0x80001000L
    val baseDataAddr = 0x20000L
    val stride = 64L // 2 cache blocks

    // Step 1: Iteration 0 - Initial load execution trains BDT
    println("  Step 1: Iteration 0 -> Allocate BDT entry for loop...")
    // Frontend predicts branch taken
    dut.io.branch_signal.valid.poke(true.B)
    dut.io.branch_signal.bits.pc.poke(branchPc.U)
    dut.io.branch_signal.bits.target.poke(targetPc.U)
    dut.io.branch_signal.bits.taken.poke(true.B)
    // Backend load executes
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(targetPc.U)
    dut.io.train.bits.addr.poke(baseDataAddr.U)
    dut.clock.step(1)
    dut.io.prefetch_req.valid.expect(false.B) // Confidence = 0, no prefetch yet

    // Step 2: Iteration 1 - Learn stride = +64
    println("  Step 2: Iteration 1 -> Learn stride +64 (Confidence 0 -> 1)...")
    dut.io.branch_signal.valid.poke(true.B)
    dut.io.branch_signal.bits.pc.poke(branchPc.U)
    dut.io.branch_signal.bits.target.poke(targetPc.U)
    dut.io.branch_signal.bits.taken.poke(true.B)
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(targetPc.U)
    dut.io.train.bits.addr.poke((baseDataAddr + stride).U)
    dut.clock.step(1)
    dut.io.prefetch_req.valid.expect(false.B) // Confidence = 1 (< 2), no prefetch yet

    // Step 3: Iteration 2 - Confirm stride, reach steady confidence (Confidence 1 -> 2)
    println("  Step 3: Iteration 2 -> Confirm stride +64 (Confidence 1 -> 2: Confident!)...")
    dut.io.branch_signal.valid.poke(true.B)
    dut.io.branch_signal.bits.pc.poke(branchPc.U)
    dut.io.branch_signal.bits.target.poke(targetPc.U)
    dut.io.branch_signal.bits.taken.poke(true.B)
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(targetPc.U)
    dut.io.train.bits.addr.poke((baseDataAddr + 2 * stride).U)
    dut.clock.step(1)

    // Step 4: Iteration 3 - Frontend runs ahead! Branch signal fires BEFORE load execution!
    println("  Step 4: Frontend branch signal fires ahead -> FDP immediately generates prefetch!")
    dut.io.train.valid.poke(false.B) // No backend load yet!
    dut.io.branch_signal.valid.poke(true.B)
    dut.io.branch_signal.bits.pc.poke(branchPc.U)
    dut.io.branch_signal.bits.target.poke(targetPc.U)
    dut.io.branch_signal.bits.taken.poke(true.B)
    dut.clock.step(1)

    val expectedPfAddr = (baseDataAddr + 3 * stride) & ~31L
    dut.io.prefetch_req.valid.expect(true.B)
    dut.io.prefetch_req.bits.addr.expect(expectedPfAddr.U)
    println(s"  => PASS: FDP Prefetch Triggered on Branch! Addr: 0x${dut.io.prefetch_req.bits.addr.peek().litValue.toString(16)}")

    // Step 5: Speculation Flush Test
    println("  Step 5: Testing misprediction flush...")
    dut.io.flush.poke(true.B)
    dut.clock.step(1)
    dut.io.prefetch_req.valid.expect(false.B)
    println("  => PASS: Prefetch suppressed on pipeline flush!")
  }

  // -------------------------------------------------------------
  // Test 2: Full L1Prefetcher Top-Level Integration Test with FDP
  // -------------------------------------------------------------
  println("\n--- [Test 2] L1Prefetcher Integration with FDP Priority Arbitration ---")
  RawTester.test(new L1Prefetcher()) { dut =>
    dut.io.flush.poke(false.B)
    dut.io.train.valid.poke(false.B)
    dut.io.branch_signal.valid.poke(false.B)
    dut.io.branch_signal.bits.pc.poke(0.U)
    dut.io.branch_signal.bits.target.poke(0.U)
    dut.io.branch_signal.bits.taken.poke(false.B)
    dut.io.prefetch_req.ready.poke(false.B) // Hold queue deq until verified
    dut.clock.step(1)

    val branchPc = 0x80003020L
    val targetPc = 0x80003000L
    val baseData = 0x60000L
    val stride = 64L

    // Train FDP (3 iterations to lock confidence = 2)
    for (i <- 0 until 3) {
      dut.io.branch_signal.valid.poke(true.B)
      dut.io.branch_signal.bits.pc.poke(branchPc.U)
      dut.io.branch_signal.bits.target.poke(targetPc.U)
      dut.io.branch_signal.bits.taken.poke(true.B)
      dut.io.train.valid.poke(true.B)
      dut.io.train.bits.pc.poke(targetPc.U)
      dut.io.train.bits.addr.poke((baseData + i * stride).U)
      dut.clock.step(1)
    }

    // Deassert train, fire frontend branch signal only
    dut.io.train.valid.poke(false.B)
    dut.io.branch_signal.valid.poke(true.B)
    dut.io.branch_signal.bits.pc.poke(branchPc.U)
    dut.io.branch_signal.bits.target.poke(targetPc.U)
    dut.io.branch_signal.bits.taken.poke(true.B)
    dut.clock.step(1)

    dut.io.branch_signal.valid.poke(false.B)
    dut.clock.step(1) // Pipeline latency through FDP registered output and FIFO

    // Now check the FIFO queue:
    // When branch fired on iteration 2, it queued 0x60080
    // When branch fired on iteration 3, it queued 0x600c0
    val expectedAddr1 = (baseData + 2 * stride) & ~31L
    val expectedAddr2 = (baseData + 3 * stride) & ~31L

    dut.io.prefetch_req.valid.expect(true.B)
    dut.io.prefetch_req.bits.addr.expect(expectedAddr1.U)
    println(s"  => PASS: Prefetch 1 Dequeued: 0x${dut.io.prefetch_req.bits.addr.peek().litValue.toString(16)} (Iteration 2 warmup)")

    dut.io.prefetch_req.ready.poke(true.B)
    dut.clock.step(1)

    dut.io.prefetch_req.valid.expect(true.B)
    dut.io.prefetch_req.bits.addr.expect(expectedAddr2.U)
    println(s"  => PASS: Prefetch 2 Dequeued: 0x${dut.io.prefetch_req.bits.addr.peek().litValue.toString(16)} (Iteration 3 warmup)")

    dut.clock.step(1)
    dut.io.prefetch_req.valid.expect(false.B)
    println("  => PASS: All prefetch queue entries drained successfully!")
  }

  println("\n==================================================")
  println("  ALL FDP PREFETCHER TESTS PASSED SUCCESSFULLY!   ")
  println("==================================================")
}
