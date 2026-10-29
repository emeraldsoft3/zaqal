package zaqal

import zaqal.common._
import zaqal.cache._

import chisel3._
import chiseltest._
import java.io.{File, PrintWriter}
import java.nio.file.{Files, StandardCopyOption}

import chiseltest.simulator.VerilatorBackendAnnotation

// ============================================================================
// Phase 10: Multi-Hart & Coherence - Day 1-3 Verification Test
// ============================================================================
// Verification Flow:
// 1. Program Execution on Zaqal Core:
//    - addi  x1,  x0, 0x1000       (base shared memory address = 0x1000)
//    - addi  x2,  x0, 0x42         (data value to store = 0x42)
// 2. TileLink Channel A AcquireBlock (Store Miss):
//    - sw    x2,  0(x1)            (triggers Store Miss -> AcquireBlock NtoT on Channel A)
// 3. TileLink Channel D & E Handshake:
//    - Hub responds with GrantData (toT) on Channel D
//    - Core acknowledges with GrantAck on Channel E, marks cache line DIRTY
// 4. External Coherence Probe (Channel B -> Channel C):
//    - Hub injects ProbeBlock (toB) -> Core returns dirty data via ProbeAckData
//    - Hub injects ProbeBlock (toN) -> Core invalidates cache line and returns ProbeAck
// 5. Post-Invalidation Load Miss (Channel A):
//    - lw    x3,  0(x1)            (Cache line was invalidated, so lw MUST MISS!)
//    - Core issues AcquireBlock (NtoB) on Channel A
//    - Hub returns GrantData with updated coherent value (0x99)
// 6. Architectural PASS Check:
//    - addi  x29, x3, 0            (x29 := 0x99 = 153 -> PASS flag!)
//    - jal   x0, 0                 (settle loop)
// ============================================================================

object ZaqalTest extends App {
  val vcdPath = "programs/vcd"
  new File(vcdPath).mkdirs()

  implicit val p = (new ZaqalConfig).alter((site, here, up) => {
    case ZaqalParamsKey => up(ZaqalParamsKey).copy(
      programFile = "",
      enableUOpCache = true,
      enableDifftest = false
    )
  })
  val params = p(ZaqalParamsKey)

  RawTester.test(new Core(), Seq(VerilatorBackendAnnotation, WriteVcdAnnotation)) { dut =>
    println("================================================================================")
    println("--- Starting ZAQAL Phase 10: TileLink-C Core & Bus Verification ---")
    println("================================================================================")
    dut.clock.setTimeout(0)

    val csvFile = new PrintWriter(new File("ftq_dump.csv"))
    csvFile.println(s"Cycle,Slot,BasePC,Mask,${(0 until params.fetchWidth).map(i => s"Inst$i").mkString(",")},PredTarget,PredTaken,PredSlot")
    csvFile.flush()

    // =========================================================================
    // RISC-V ASSEMBLY PROGRAM MEMORY
    // =========================================================================
    val programMemory = Seq(
      // --- BLOCK 0 (PC 0x80000000 - 0x8000001C) ---
      "h000010b7".U(32.W), // 00 [Word 0]: lui      x1,  1            (x1 := 0x1000 base address)
      "h04200113".U(32.W), // 04 [Word 1]: addi     x2,  x0, 0x42     (x2 := 0x42 store data)
      "h0020a023".U(32.W), // 08 [Word 2]: sw       x2,  0(x1)        (Store: TileLink AcquireBlock NtoT!)
      "h01900213".U(32.W), // 0C [Word 3]: addi     x4,  x0, 25       (Wait loop counter: x4 := 25)
      "hfff20213".U(32.W), // 10 [Word 4]: addi     x4,  x4, -1       (Loop decrement: x4 := x4 - 1)
      "hfe021ee3".U(32.W), // 14 [Word 5]: bne      x4,  x0, -4       (Branch back to Word 4 while x4 != 0)
      "h00000013".U(32.W), // 18 [Word 6]: nop
      "h00000013".U(32.W), // 1C [Word 7]: nop

      // --- BLOCK 1 (PC 0x80000020 - 0x8000003C) ---
      "h0000a183".U(32.W), // 20 [Word 0]: lw       x3,  0(x1)        (Post-Probe load: line is invalidated, so MUST MISS!)
      "h00018e93".U(32.W), // 24 [Word 1]: addi     x29, x3, 0        (PASS Flag x29 := x3)
      "h00000013".U(32.W), // 28 [Word 2]: nop
      "h00000013".U(32.W), // 2C [Word 3]: nop
      "h00000013".U(32.W), // 30 [Word 4]: nop
      "h00000013".U(32.W), // 34 [Word 5]: nop
      "h00000013".U(32.W), // 38 [Word 6]: nop
      "h0000006f".U(32.W)  // 3C [Word 7]: jal      x0, 0             (settle loop to self)
    ).padTo(1024, "h00000013".U(32.W))

    // Simulation State
    val resetCycles = 5
    val maxCycles   = 300

    var memHandlingRequest = false
    var memRequestedAddr   = 0L

    var storeAcquireSeen = false
    var storeGrantSent   = false
    var storeAckReceived = false

    var probeStage       = 0 // 0: wait, 1: send toB, 2: wait ackData, 3: send toN, 4: wait ack, 5: done
    var probeBlockCount  = 0
    var probeAckDataSeen = false
    var probeAckSeen     = false

    var loadAcquireSeen  = false
    var loadGrantSent    = false

    val coherentNewValue = 0x99L // New value to supply when Core re-loads post-probe

    for (cycle <- 0 until maxCycles) {
      dut.reset.poke((cycle < resetCycles).B)
      dut.io.plic_ext_irq.poke(0.U)

      // Defaults
      dut.io.mem.req.ready.poke(true.B)
      dut.io.mem.resp.valid.poke(false.B)
      dut.io.mem.resp.bits.data.poke(0.U)
      dut.io.mem.resp.bits.last.poke(false.B)

      dut.io.mem_d.req.ready.poke(true.B)
      dut.io.mem_d.resp.valid.poke(false.B)
      dut.io.mem_d.resp.bits.data.poke(0.U)
      dut.io.mem_d.resp.bits.last.poke(false.B)

      dut.io.tl_d.a.ready.poke(true.B)
      dut.io.tl_d.b.valid.poke(false.B)
      dut.io.tl_d.b.bits.opcode.poke(0.U)
      dut.io.tl_d.b.bits.param.poke(0.U)
      dut.io.tl_d.b.bits.size.poke(0.U)
      dut.io.tl_d.b.bits.source.poke(0.U)
      dut.io.tl_d.b.bits.address.poke(0.U)
      dut.io.tl_d.b.bits.mask.poke(0.U)
      dut.io.tl_d.b.bits.data.poke(0.U)
      dut.io.tl_d.b.bits.corrupt.poke(false.B)

      dut.io.tl_d.c.ready.poke(true.B)

      dut.io.tl_d.d.valid.poke(false.B)
      dut.io.tl_d.d.bits.opcode.poke(0.U)
      dut.io.tl_d.d.bits.param.poke(0.U)
      dut.io.tl_d.d.bits.size.poke(0.U)
      dut.io.tl_d.d.bits.source.poke(0.U)
      dut.io.tl_d.d.bits.sink.poke(0.U)
      dut.io.tl_d.d.bits.denied.poke(false.B)
      dut.io.tl_d.d.bits.data.poke(0.U)
      dut.io.tl_d.d.bits.corrupt.poke(false.B)

      dut.io.tl_d.e.ready.poke(true.B)

      if (cycle >= resetCycles) {
        // ---------------------------------------------------------------------
        // 1. Instruction Memory Responder (L1-I Frontend Fetch)
        // ---------------------------------------------------------------------
        if (dut.io.mem.req.valid.peek().litToBoolean && !memHandlingRequest) {
          memHandlingRequest = true
          memRequestedAddr = dut.io.mem.req.bits.addr.peek().litValue.toLong
        }

        if (memHandlingRequest) {
          dut.io.mem.resp.valid.poke(true.B)
          val relativeWordAddr = ((memRequestedAddr - 0x80000000L) / 4).toInt
          var respData = BigInt(0)
          for (i <- 0 until params.fetchWidth) {
            val inst = if (relativeWordAddr >= 0 && relativeWordAddr + i < programMemory.length) {
              programMemory(relativeWordAddr + i).litValue
            } else {
              BigInt(0x00000013)
            }
            respData = respData | (inst << (i * 32))
          }
          dut.io.mem.resp.bits.data.poke(respData.U)
          dut.io.mem.resp.bits.last.poke(true.B)

          if (dut.io.mem.resp.ready.peek().litToBoolean) {
            memHandlingRequest = false
          }
        }

        // ---------------------------------------------------------------------
        // 2. TileLink Channel A: Monitor Core Acquires (Store Miss / Load Miss)
        // ---------------------------------------------------------------------
        if (dut.io.tl_d.a.valid.peek().litToBoolean) {
          val op   = dut.io.tl_d.a.bits.opcode.peek().litValue.toInt
          val prm  = dut.io.tl_d.a.bits.param.peek().litValue.toInt
          val addr = dut.io.tl_d.a.bits.address.peek().litValue.toLong

          if (op == 6 && prm == 1 && !storeAcquireSeen) { // AcquireBlock NtoT (Store Miss)
            storeAcquireSeen = true
            println(f"Cycle $cycle%3d: [TILELINK CHAN A] Core Emits AcquireBlock: Opcode = $op (AcquireBlock), Param = $prm (NtoT Exclusive), Addr = 0x$addr%08x")
          }

          if (op == 6 && prm == 0 && probeStage == 5 && !loadAcquireSeen) { // AcquireBlock NtoB (Post-Probe Load Miss)
            loadAcquireSeen = true
            println(f"Cycle $cycle%3d: [TILELINK CHAN A] Core Emits Post-Probe Load AcquireBlock: Opcode = $op (AcquireBlock), Param = $prm (NtoB Shared), Addr = 0x$addr%08x")
          }
        }

        // ---------------------------------------------------------------------
        // 3. TileLink Channel D: Respond with GrantData
        // ---------------------------------------------------------------------
        if (storeAcquireSeen && !storeGrantSent) {
          dut.io.tl_d.d.valid.poke(true.B)
          dut.io.tl_d.d.bits.opcode.poke(TLMessages.GrantData)
          dut.io.tl_d.d.bits.param.poke(TLPermissions.toT) // Exclusive permission
          dut.io.tl_d.d.bits.size.poke(5.U)
          dut.io.tl_d.d.bits.source.poke(0.U)
          dut.io.tl_d.d.bits.sink.poke(0.U)
          dut.io.tl_d.d.bits.data.poke(0.U)

          if (dut.io.tl_d.d.ready.peek().litToBoolean) {
            storeGrantSent = true
            println(f"Cycle $cycle%3d: [TILELINK CHAN D] Bus Responds with GrantData (toT Exclusive Permission Granted)")
          }
        }

        if (loadAcquireSeen && !loadGrantSent) {
          dut.io.tl_d.d.valid.poke(true.B)
          dut.io.tl_d.d.bits.opcode.poke(TLMessages.GrantData)
          dut.io.tl_d.d.bits.param.poke(TLPermissions.toB) // Shared permission
          dut.io.tl_d.d.bits.size.poke(5.U)
          dut.io.tl_d.d.bits.source.poke(0.U)
          dut.io.tl_d.d.bits.sink.poke(1.U)
          dut.io.tl_d.d.bits.data.poke(BigInt(coherentNewValue).U) // Supply new value 0x99!

          if (dut.io.tl_d.d.ready.peek().litToBoolean) {
            loadGrantSent = true
            println(f"Cycle $cycle%3d: [TILELINK CHAN D] Bus Responds with GrantData (Supplying Coherent New Value 0x$coherentNewValue%02x)")
          }
        }

        // ---------------------------------------------------------------------
        // 4. TileLink Channel E: Receive GrantAck from Core
        // ---------------------------------------------------------------------
        if (dut.io.tl_d.e.valid.peek().litToBoolean) {
          val sink = dut.io.tl_d.e.bits.sink.peek().litValue.toInt
          if (sink == 0 && !storeAckReceived) {
            storeAckReceived = true
            println(f"Cycle $cycle%3d: [TILELINK CHAN E] Core Emits GrantAck (Sink = $sink) -> Exclusive Store Line Installed & Marked Dirty!")
            probeStage = 1 // Ready to test coherence probes!
          }
          if (sink == 1) {
            println(f"Cycle $cycle%3d: [TILELINK CHAN E] Core Emits GrantAck (Sink = $sink) -> Coherent Refill Completed!")
          }
        }

        // ---------------------------------------------------------------------
        // 5. TileLink Channel B & C: External Coherence Probes
        // ---------------------------------------------------------------------
        // Probe 1: Downgrade to Shared (toB) -> Expect ProbeAckData with dirty line!
        if (probeStage == 1 && cycle > 35) {
          dut.io.tl_d.b.valid.poke(true.B)
          dut.io.tl_d.b.bits.opcode.poke(TLMessages.ProbeBlock)
          dut.io.tl_d.b.bits.param.poke(TLPermissions.toB) // Downgrade to Shared
          dut.io.tl_d.b.bits.size.poke(5.U)
          dut.io.tl_d.b.bits.source.poke(0.U)
          dut.io.tl_d.b.bits.address.poke(0x1000.U)

          if (dut.io.tl_d.b.ready.peek().litToBoolean && !probeAckDataSeen) {
            probeBlockCount += 1
            println(f"Cycle $cycle%3d: >>> [BUS -> CORE CHAN B] Injecting ProbeBlock: Param = toB (Downgrade Exclusive -> Shared)")
          }

          if (dut.io.tl_d.c.valid.peek().litToBoolean) {
            val cOp   = dut.io.tl_d.c.bits.opcode.peek().litValue.toInt
            val cData = dut.io.tl_d.c.bits.data.peek().litValue
            if (cOp == 5 && !probeAckDataSeen) { // ProbeAckData
              probeAckDataSeen = true
              println(f"Cycle $cycle%3d: <<< [CORE -> BUS CHAN C] Core Returns ProbeAckData! Dirty Cache Line Flushed = 0x$cData%x")
              probeStage = 2 // Settle cycle to let dirtyArray := false commit to flip-flops
            }
          }
        }

        // Settle cycle between probes: allow flip-flops (dirtyArray/stateArray) to latch updated values
        if (probeStage == 2 && cycle > 37) {
          probeStage = 3
        }

        // Probe 2: Invalidate Cache Line (toN) -> Expect ProbeAck
        if (probeStage == 3) {
          dut.io.tl_d.b.valid.poke(true.B)
          dut.io.tl_d.b.bits.opcode.poke(TLMessages.ProbeBlock)
          dut.io.tl_d.b.bits.param.poke(TLPermissions.toN) // Invalidate
          dut.io.tl_d.b.bits.size.poke(5.U)
          dut.io.tl_d.b.bits.source.poke(0.U)
          dut.io.tl_d.b.bits.address.poke(0x1000.U)

          if (dut.io.tl_d.b.ready.peek().litToBoolean && !probeAckSeen) {
            probeBlockCount += 1
            println(f"Cycle $cycle%3d: >>> [BUS -> CORE CHAN B] Injecting ProbeBlock: Param = toN (Invalidate Line)")
          }

          if (dut.io.tl_d.c.valid.peek().litToBoolean) {
            val cOp = dut.io.tl_d.c.bits.opcode.peek().litValue.toInt
            if (cOp == 4 && !probeAckSeen) { // ProbeAck
              probeAckSeen = true
              println(f"Cycle $cycle%3d: <<< [CORE -> BUS CHAN C] Core Returns ProbeAck! Clean Cache Line Successfully Invalidated")
              probeStage = 5 // Coherence probing complete! Core will now execute lw and miss!
            }
          }
        }
      }

      dut.clock.step(1)
    }

    // -------------------------------------------------------------------------
    // 6. Verify Architectural Registers & Coherence Protocol Invariants
    // -------------------------------------------------------------------------
    println("================================================================================")
    println("--- SIMULATION COMPLETE: VERIFYING REGISTER FILE & TILELINK PROTOCOL ---")
    println(f"  [1] Core Channel A Store AcquireBlock (NtoT):    $storeAcquireSeen")
    println(f"  [2] Bus Channel D Store GrantData (toT):         $storeGrantSent")
    println(f"  [3] Core Channel E Store GrantAck:               $storeAckReceived")
    println(f"  [4] Bus Channel B Probes Injected:               $probeBlockCount (toB downgrade + toN invalidate)")
    println(f"  [5] Core Channel C ProbeAckData (Dirty Flush):   $probeAckDataSeen")
    println(f"  [6] Core Channel C ProbeAck (Clean Invalidate):  $probeAckSeen")
    println(f"  [7] Core Channel A Post-Probe Load Miss (NtoB):  $loadAcquireSeen")
    println(f"  [8] Bus Channel D Load GrantData (0x99):         $loadGrantSent")

    // Check register x29 via debug RAT / PRF
    val ratX29Phy = dut.debug.get.debug_int_rat(29).peek().litValue.toInt
    val regX29Val = dut.debug.get.regs(ratX29Phy).peek().litValue.toLong
    println(f"  [9] Register x29 Value:                          0x$regX29Val%02x (Expected = 0x$coherentNewValue%02x)")
    println("================================================================================")

    assert(storeAcquireSeen, "Core must issue Channel A AcquireBlock (NtoT) for store miss")
    assert(storeAckReceived, "Core must complete Channel E GrantAck for store line installation")
    assert(probeAckDataSeen, "Core must flush modified dirty line via Channel C ProbeAckData upon toB probe")
    assert(probeAckSeen,     "Core must invalidate line and confirm via Channel C ProbeAck upon toN probe")
    assert(loadAcquireSeen,  "Core must miss and issue Channel A AcquireBlock after probe invalidation")
    assert(regX29Val == coherentNewValue, f"Register x29 must contain the coherent new value 0x$coherentNewValue%02x (Got: 0x$regX29Val%02x)")

    println("\n>>> [PASS] PHASE 10 DAY 1-3 TILELINK-C RISC-V CORE VERIFICATION TEST PASSED! <<<\n")

    try {
      val testDir = new File("test_run_dir")
      if (testDir.exists()) {
        def findVcdFiles(dir: File): Seq[File] = {
          val files = Option(dir.listFiles()).getOrElse(Array.empty)
          files.filter(_.getName.endsWith(".vcd")) ++ files.filter(_.isDirectory).flatMap(findVcdFiles)
        }
        val vcdFiles = findVcdFiles(testDir)
        if (vcdFiles.nonEmpty) {
          val latestVcd = vcdFiles.maxBy(_.lastModified())
          Files.copy(latestVcd.toPath, new File("programs/vcd/Lithium.vcd").toPath, StandardCopyOption.REPLACE_EXISTING)
          println(s"Saved waveform from ${latestVcd.getPath} to programs/vcd/Lithium.vcd")
        }
      }
    } catch {
      case e: Exception => println(s"Notice: could not copy vcd: ${e.getMessage}")
    }
  }
}
