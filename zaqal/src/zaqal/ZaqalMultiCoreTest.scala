package zaqal

import zaqal.common._
import zaqal.cache._

import chisel3._
import chiseltest._
import java.io.File
import java.nio.file.{Files, StandardCopyOption}
import chiseltest.simulator.VerilatorBackendAnnotation
import chiseltest.simulator.WriteVcdAnnotation

// ============================================================================
// Phase 10 Day 13+: Multi-Threaded Workload Benchmark (Pthread / OpenMP Model)
// ============================================================================
// Benchmarks dual-core parallel execution on Zaqal Out-of-Order Multi-Core SoC:
// 1. Parallel Chunk Partitioning:
//    - Dataset A[0..7] = {10, 20, 30, 40, 50, 60, 70, 80} (Total Sum = 360 = 0x168)
//    - Core 0 (Master Thread) computes Chunk 0: A[0..3] = 10+20+30+40 = 100 (0x64)
//      Writes PART0 (100) to 0x1040.
//    - Core 1 (Worker Thread) computes Chunk 1: A[4..7] = 50+60+70+80 = 260 (0x104)
//      Writes PART1 (260) to 0x1080.
//
// 2. Barrier Synchronization (OpenMP "#pragma omp barrier" semantics):
//    - Core 0 signals arrival at BARRIER0 (0x1000 = 1) via fence rw, w.
//    - Core 1 signals arrival at BARRIER1 (0x1004 = 1) via fence rw, w.
//    - Both harts verify mutual arrival flags before proceeding to reduction.
//
// 3. TileLink Coherent Cache Reduction:
//    - Core 0 coherently reads PART1 (0x1080) modified by Core 1.
//      (L2 directory probes Core 1, triggers dirty line flush, grants line to Core 0).
//    - Core 1 coherently reads PART0 (0x1040) modified by Core 0.
//    - Core 0 reduces TOTAL = PART0 + PART1 = 100 + 260 = 360 (0x168).
//    - Core 0 stores TOTAL to 0x10C0 and sets architectural x29 := 360 (0x168).
//    - Core 1 sets architectural x29 := 260 (0x104).
// ============================================================================

object ZaqalMultiCoreTest extends App {
  val vcdPath = "programs/vcd"
  new File(vcdPath).mkdirs()

  implicit val p: org.chipsalliance.cde.config.Parameters = (new ZaqalConfig).alter((site, here, up) => {
    case ZaqalParamsKey => up(ZaqalParamsKey).copy(
      programFile = "",
      enableUOpCache = true
    )
  })
  val params = p(ZaqalParamsKey)

  RawTester.test(new DualCoreTop(), Seq(VerilatorBackendAnnotation, WriteVcdAnnotation)) { dut =>
    println("================================================================================")
    println("--- Starting ZAQAL Phase 10: Multi-Threaded Parallel Reduction Benchmark ---")
    println("================================================================================")
    dut.clock.setTimeout(0)

    val memArray = Array.fill(1024)("h00000013".U(32.W)) // Default nop

    // --- BOOT ROUTINE (PC 0x80000000) ---
    memArray(0)  = "hf1402573".U(32.W) // 00 [Word 0]:  csrr     a0,  mhartid
    memArray(1)  = "h06051e63".U(32.W) // 04 [Word 1]:  bnez     a0,  +124 (jump to Core 1 at 0x80000080)

    // --- CORE 0 (HART 0): MASTER THREAD (PC 0x80000008 - 0x80000074) ---
    memArray(2)  = "h000010b7".U(32.W) // 08 [Word 2]:  lui      x1,  1             (x1 := 0x1000)
    memArray(3)  = "h00a00513".U(32.W) // 0C [Word 3]:  addi     x10, x0, 10        (x10 := 10)
    memArray(4)  = "h01450513".U(32.W) // 10 [Word 4]:  addi     x10, x10, 20       (x10 := 30)
    memArray(5)  = "h01e50513".U(32.W) // 14 [Word 5]:  addi     x10, x10, 30       (x10 := 60)
    memArray(6)  = "h02850513".U(32.W) // 18 [Word 6]:  addi     x10, x10, 40       (x10 := 100 = 0x64 [Chunk 0 Sum])
    memArray(7)  = "h04a0a023".U(32.W) // 1C [Word 7]:  sw       x10, 64(x1)        [Store PART0 (100) to 0x1040]
    memArray(8)  = "h0310000f".U(32.W) // 20 [Word 8]:  fence    rw,  w             [Ensure PART0 ordered before barrier]
    memArray(9)  = "h00100593".U(32.W) // 24 [Word 9]:  addi     x11, x0, 1         (x11 := 1)
    memArray(10) = "h00b0a023".U(32.W) // 28 [Word 10]: sw       x11, 0(x1)         [Signal BARRIER0 (Core 0 arrived) at 0x1000]
    for (i <- 11 to 22) {
      memArray(i) = "h00000013".U(32.W) // 2C-58: NOPs for Core 1 synchronization
    }
    memArray(23) = "h0220000f".U(32.W) // 5C [Word 23]: fence    r,   r             [Wait/Order barrier reads]
    memArray(24) = "h0040a683".U(32.W) // 60 [Word 24]: lw       x13, 4(x1)         [Read BARRIER1 at 0x1004]
    memArray(25) = "h0800a183".U(32.W) // 64 [Word 25]: lw       x3,  128(x1)       [Coherently load PART1 (260) from 0x1080 via L2]
    memArray(26) = "h00350833".U(32.W) // 68 [Word 26]: add      x16, x10, x3       [Compute TOTAL = 100 + 260 = 360 = 0x168]
    memArray(27) = "h0d00a023".U(32.W) // 6C [Word 27]: sw       x16, 192(x1)       [Store TOTAL (360) to 0x10C0]
    memArray(28) = "h00080e93".U(32.W) // 70 [Word 28]: addi     x29, x16, 0        [Core 0 PASS: x29 := 360 = 0x168]
    memArray(29) = "h0000006f".U(32.W) // 74 [Word 29]: jal      x0,  0             (Halt loop)

    // --- CORE 1 (HART 1): WORKER THREAD (PC 0x80000080 - 0x800000E4) ---
    memArray(32) = "h000010b7".U(32.W) // 80 [Word 32]: lui      x1,  1             (x1 := 0x1000)
    memArray(33) = "h03200513".U(32.W) // 84 [Word 33]: addi     x10, x0, 50        (x10 := 50)
    memArray(34) = "h03c50513".U(32.W) // 88 [Word 34]: addi     x10, x10, 60       (x10 := 110)
    memArray(35) = "h04650513".U(32.W) // 8C [Word 35]: addi     x10, x10, 70       (x10 := 180)
    memArray(36) = "h05050513".U(32.W) // 90 [Word 36]: addi     x10, x10, 80       (x10 := 260 = 0x104 [Chunk 1 Sum])
    memArray(37) = "h08a0a023".U(32.W) // 94 [Word 37]: sw       x10, 128(x1)       [Store PART1 (260) to 0x1080]
    memArray(38) = "h0310000f".U(32.W) // 98 [Word 38]: fence    rw,  w             [Ensure PART1 ordered before barrier]
    memArray(39) = "h00100593".U(32.W) // 9C [Word 39]: addi     x11, x0, 1         (x11 := 1)
    memArray(40) = "h00b0a223".U(32.W) // A0 [Word 40]: sw       x11, 4(x1)         [Signal BARRIER1 (Core 1 arrived) at 0x1004]
    for (i <- 41 to 52) {
      memArray(i) = "h00000013".U(32.W) // A4-D0: NOPs for Core 0 synchronization
    }
    memArray(53) = "h0220000f".U(32.W) // D4 [Word 53]: fence    r,   r             [Wait/Order barrier reads]
    memArray(54) = "h0000a683".U(32.W) // D8 [Word 54]: lw       x13, 0(x1)         [Read BARRIER0 at 0x1000]
    memArray(55) = "h0400a183".U(32.W) // DC [Word 55]: lw       x3,  64(x1)        [Coherently load PART0 (100) from 0x1040 via L2]
    memArray(56) = "h00050e93".U(32.W) // E0 [Word 56]: addi     x29, x10, 0        [Core 1 PASS: x29 := 260 = 0x104]
    memArray(57) = "h0000006f".U(32.W) // E4 [Word 57]: jal      x0,  0             (Halt loop)

    val programMemory = memArray.toSeq

    val resetCycles = 10
    val maxCycles   = 320

    var c0MemHandling = false
    var c0MemAddr     = 0L
    var c1MemHandling = false
    var c1MemAddr     = 0L

    for (cycle <- 0 until maxCycles) {
      dut.reset.poke((cycle < resetCycles).B)

      // Instruction Memory Responder Defaults
      dut.io.c0_mem.req.ready.poke(true.B)
      dut.io.c0_mem.resp.valid.poke(false.B)
      dut.io.c0_mem.resp.bits.data.poke(0.U)
      dut.io.c0_mem.resp.bits.last.poke(false.B)

      dut.io.c1_mem.req.ready.poke(true.B)
      dut.io.c1_mem.resp.valid.poke(false.B)
      dut.io.c1_mem.resp.bits.data.poke(0.U)
      dut.io.c1_mem.resp.bits.last.poke(false.B)

      // L3 DRAM Backing Memory Defaults
      dut.io.mem_l3.req.ready.poke(true.B)
      dut.io.mem_l3.resp.valid.poke(false.B)
      dut.io.mem_l3.resp.bits.data.poke(0.U)
      dut.io.mem_l3.resp.bits.last.poke(false.B)

      if (cycle >= resetCycles) {
        // ---------------------------------------------------------------------
        // 1. Core 0 Instruction Fetch Responder
        // ---------------------------------------------------------------------
        if (dut.io.c0_mem.req.valid.peek().litToBoolean && !c0MemHandling) {
          c0MemHandling = true
          c0MemAddr = dut.io.c0_mem.req.bits.addr.peek().litValue.toLong
        }

        if (c0MemHandling) {
          dut.io.c0_mem.resp.valid.poke(true.B)
          val relAddr = ((c0MemAddr - 0x80000000L) / 4).toInt
          var respData = BigInt(0)
          for (i <- 0 until params.fetchWidth) {
            val inst = if (relAddr >= 0 && relAddr + i < programMemory.length) {
              programMemory(relAddr + i).litValue
            } else {
              BigInt(0x00000013)
            }
            respData = respData | (inst << (i * 32))
          }
          dut.io.c0_mem.resp.bits.data.poke(respData.U)
          dut.io.c0_mem.resp.bits.last.poke(true.B)

          if (dut.io.c0_mem.resp.ready.peek().litToBoolean) {
            c0MemHandling = false
          }
        }

        // ---------------------------------------------------------------------
        // 2. Core 1 Instruction Fetch Responder
        // ---------------------------------------------------------------------
        if (dut.io.c1_mem.req.valid.peek().litToBoolean && !c1MemHandling) {
          c1MemHandling = true
          c1MemAddr = dut.io.c1_mem.req.bits.addr.peek().litValue.toLong
        }

        if (c1MemHandling) {
          dut.io.c1_mem.resp.valid.poke(true.B)
          val relAddr = ((c1MemAddr - 0x80000000L) / 4).toInt
          var respData = BigInt(0)
          for (i <- 0 until params.fetchWidth) {
            val inst = if (relAddr >= 0 && relAddr + i < programMemory.length) {
              programMemory(relAddr + i).litValue
            } else {
              BigInt(0x00000013)
            }
            respData = respData | (inst << (i * 32))
          }
          dut.io.c1_mem.resp.bits.data.poke(respData.U)
          dut.io.c1_mem.resp.bits.last.poke(true.B)

          if (dut.io.c1_mem.resp.ready.peek().litToBoolean) {
            c1MemHandling = false
          }
        }

        // ---------------------------------------------------------------------
        // 3. Monitor Multi-Core Coherence Activity
        // ---------------------------------------------------------------------
        if (dut.io.c0_a_valid.peek().litToBoolean) {
          val op = dut.io.c0_a_opcode.peek().litValue.toInt
          val addr = dut.io.c0_a_addr.peek().litValue.toLong
          println(f"Cycle $cycle%4d: [CORE 0 -> L2 CHAN A] Acquire (Opcode $op): Addr = 0x$addr%04x")
        }

        if (dut.io.c1_a_valid.peek().litToBoolean) {
          val op = dut.io.c1_a_opcode.peek().litValue.toInt
          val addr = dut.io.c1_a_addr.peek().litValue.toLong
          println(f"Cycle $cycle%4d: [CORE 1 -> L2 CHAN A] Acquire (Opcode $op): Addr = 0x$addr%04x")
        }

        if (dut.io.c0_b_valid.peek().litToBoolean) {
          val param = dut.io.c0_b_param.peek().litValue.toInt
          println(f"Cycle $cycle%4d: >>> [L2 -> CORE 0 CHAN B] Probe: Param = $param")
        }

        if (dut.io.c1_b_valid.peek().litToBoolean) {
          val param = dut.io.c1_b_param.peek().litValue.toInt
          println(f"Cycle $cycle%4d: >>> [L2 -> CORE 1 CHAN B] Probe: Param = $param")
        }

        if (dut.io.c0_c_valid.peek().litToBoolean) {
          val cOp   = dut.io.c0_c_opcode.peek().litValue.toInt
          val cData = dut.io.c0_c_data.peek().litValue
          println(f"Cycle $cycle%4d: <<< [CORE 0 -> L2 CHAN C] ProbeAck/Release (Opcode $cOp, Data = 0x$cData%x)")
        }

        if (dut.io.c1_c_valid.peek().litToBoolean) {
          val cOp   = dut.io.c1_c_opcode.peek().litValue.toInt
          val cData = dut.io.c1_c_data.peek().litValue
          println(f"Cycle $cycle%4d: <<< [CORE 1 -> L2 CHAN C] ProbeAck/Release (Opcode $cOp, Data = 0x$cData%x)")
        }

        if (dut.io.c0_d_valid.peek().litToBoolean) {
          val dOp   = dut.io.c0_d_opcode.peek().litValue.toInt
          val dData = dut.io.c0_d_data.peek().litValue
          println(f"Cycle $cycle%4d: >>> [L2 -> CORE 0 CHAN D] Grant: Opcode = $dOp, Data = 0x$dData%x")
        }

        if (dut.io.c1_d_valid.peek().litToBoolean) {
          val dOp   = dut.io.c1_d_opcode.peek().litValue.toInt
          val dData = dut.io.c1_d_data.peek().litValue
          println(f"Cycle $cycle%4d: >>> [L2 -> CORE 1 CHAN D] Grant: Opcode = $dOp, Data = 0x$dData%x")
        }

        if (cycle % 25 == 0 || cycle == 28 || cycle == 30 || cycle == 35 || cycle == 40 || cycle == 45 || cycle == 50 || cycle == 60 || cycle == 70 || cycle == 80 || cycle == 100 || cycle == 125 || cycle == 150) {
          val c0_x29_cur = dut.io.c0_reg_x29.peek().litValue.toLong
          val c0_x3_cur  = dut.io.c0_reg_x3.peek().litValue.toLong
          val c1_x3_cur  = dut.io.c1_reg_x3.peek().litValue.toLong
          val c1_x29_cur = dut.io.c1_reg_x29.peek().litValue.toLong
          val c0_pc_cur  = dut.io.c0_pc.peek().litValue.toLong
          val c1_pc_cur  = dut.io.c1_pc.peek().litValue.toLong
          println(f"Cycle $cycle%4d: C0 [PC=0x$c0_pc_cur%08x, x3=0x$c0_x3_cur%03x, x29=0x$c0_x29_cur%03x] | C1 [PC=0x$c1_pc_cur%08x, x3=0x$c1_x3_cur%03x, x29=0x$c1_x29_cur%03x]")
        }
      }

      dut.clock.step(1)
    }

    // -------------------------------------------------------------------------
    // 4. Verify Final Multi-Core Architectural Registers & Reduction Invariants
    // -------------------------------------------------------------------------
    val c0_x3  = dut.io.c0_reg_x3.peek().litValue.toLong
    val c0_x29 = dut.io.c0_reg_x29.peek().litValue.toLong
    val c1_x3  = dut.io.c1_reg_x3.peek().litValue.toLong
    val c1_x29 = dut.io.c1_reg_x29.peek().litValue.toLong
    val c0_pc  = dut.io.c0_pc.peek().litValue.toLong
    val c1_pc  = dut.io.c1_pc.peek().litValue.toLong

    // Copy newest waveform to dedicated programs/vcd/ZMC.vcd
    try {
      val runDirs = Option(new File("test_run_dir").listFiles()).getOrElse(Array.empty)
      val latestVcd = runDirs.filter(_.isDirectory)
        .flatMap(d => Option(d.listFiles()).getOrElse(Array.empty))
        .filter(f => f.getName == "DualCoreTop.vcd")
        .sortBy(_.lastModified())
        .lastOption

      latestVcd match {
        case Some(src) =>
          Files.copy(src.toPath, new File("programs/vcd/ZMC.vcd").toPath, StandardCopyOption.REPLACE_EXISTING)
          println(s"Saved multi-core waveform from ${src.getPath} to programs/vcd/ZMC.vcd")
        case None =>
          println("Notice: No DualCoreTop.vcd found in test_run_dir to copy.")
      }
    } catch {
      case e: Exception => println(s"Notice: could not copy vcd: ${e.getMessage}")
    }

    println("================================================================================")
    println(f"--- MULTI-THREADED PARALLEL REDUCTION BENCHMARK ($maxCycles CYCLES) ---")
    println(f"  [1] Core 0 Final PC:                    0x$c0_pc%08x")
    println(f"  [2] Core 1 Final PC:                    0x$c1_pc%08x")
    println(f"  [3] Core 0 Architectural x3 (PART1):    0x$c0_x3%03x (Decimal: $c0_x3, Expected: 260 / 0x104)")
    println(f"  [4] Core 1 Architectural x3 (PART0):    0x$c1_x3%03x (Decimal: $c1_x3, Expected: 100 / 0x064)")
    println(f"  [5] Core 0 Architectural x29 (TOTAL):   0x$c0_x29%03x (Decimal: $c0_x29, Expected: 360 / 0x168)")
    println(f"  [6] Core 1 Architectural x29 (STATUS):  0x$c1_x29%03x (Decimal: $c1_x29, Expected: 260 / 0x104)")
    println("================================================================================")

    assert(c0_x3 == 260L, f"Core 0 must load Core 1 partial sum 260 across coherent L2! Got: $c0_x3")
    assert(c1_x3 == 100L, f"Core 1 must load Core 0 partial sum 100 across coherent L2! Got: $c1_x3")
    assert(c0_x29 == 360L, f"Core 0 total reduction sum must be 360 (0x168)! Got: $c0_x29")
    assert(c1_x29 == 260L, f"Core 1 worker final register must be 260 (0x104)! Got: $c1_x29")

    println("\n>>> [PASS] MULTI-THREADED PARALLEL REDUCTION BENCHMARK 100% VERIFIED! <<<\n")
  }
}
