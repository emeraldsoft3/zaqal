package zaqal

import zaqal.common._

import chisel3._
import chiseltest._
import java.io.{File, PrintWriter}
import java.nio.file.{Files, StandardCopyOption}

import chiseltest.simulator.VerilatorBackendAnnotation

object ZaqalTest extends App {
  val vcdPath = "programs/vcd"
  new File(vcdPath).mkdirs()

  implicit val p = (new ZaqalConfig).alter((site, here, up) => {
    case ZaqalParamsKey => up(ZaqalParamsKey).copy(
      programFile = "",
      enableUOpCache = true
    )
  })
  val params = p(ZaqalParamsKey)

  // Use the native Verilator backend for 100x speedup with VCD generation
  RawTester.test(new Core(), Seq(VerilatorBackendAnnotation, WriteVcdAnnotation)) { dut =>
    println("--- Starting ZAQAL Agile V1.0 Simulation ---")
    dut.clock.setTimeout(0)
    
    // --- CSV SETUP ---
    val csvFile = new PrintWriter(new File("ftq_dump.csv"))
    csvFile.println(s"Cycle,Slot,BasePC,Mask,${(0 until params.fetchWidth).map(i => s"Inst$i").mkString(",")},PredTarget,PredTaken,PredSlot") 
    csvFile.flush() 

    // The Shadow FTQ is our software model of the hardware warehouse
    val shadowFTQ = scala.collection.mutable.Map[Int, String]()
    var manualWritePtr = 0
    var manualReadPtr = 0 
    
    def dumpToCSV(currentCycle: Int): Unit = {
      for (slot <- 0 until params.ftqEntries) {
        val data = shadowFTQ.getOrElse(slot, s"EMPTY,EMPTY,${(0 until params.fetchWidth).map(_ => "0x0").mkString(",")},0x0,false,0")
        csvFile.println(s"$currentCycle,$slot,$data")
      }
      csvFile.flush() 
    }


    // =========================================================================
    // DAY 6-7 TEST PROGRAM: PHYSICAL MEMORY PROTECTION (PMP) STORE ACCESS FAULT
    // =========================================================================
    // Block-Aligned Fetch Structure (32-byte / 8-instruction fetch blocks):
    //
    // Block 0 (PC 0x80000000 - 0x8000001C) [Machine Mode Setup Part 1: Trap/PMP Address]:
    // - 0x00: auipc x1, 0              (x1 = 0x80000000 = PC base)
    // - 0x04: addi  x2, x1, 0x40       (x2 = 0x80000040 = user mode entry PC)
    // - 0x08: csrrw x0, 0x341, x2      (mepc := 0x80000040)
    // - 0x0C: addi  x3, x1, 0x60       (x3 = 0x80000060 = trap handler PC)
    // - 0x10: csrrw x0, 0x305, x3      (mtvec := 0x80000060)
    // - 0x14: srli  x11, x1, 2         (x11 = 0x20000000 = 0x80000000 >> 2)
    // - 0x18: addi  x11, x11, 0x400    (x11 = 0x20000400 = 0x80001000 >> 2)
    // - 0x1C: csrrw x0, 0x3b0, x11     (pmpaddr0 := 0x20000400, TOR boundary)
    //
    // Block 1 (PC 0x80000020 - 0x8000003C) [Machine Mode Setup Part 2 & MRET]:
    // - 0x20: addi  x12, x0, 13        (x12 = 0x0D = TOR mode, R=1, W=0 [WRITE-PROTECTED], X=1)
    // - 0x24: csrrw x0, 0x3a0, x12     (pmpcfg0 := 0x0D, activates PMP entry 0)
    // - 0x28: csrrw x0, 0x300, x0      (mstatus := 0, clears MPP to User Mode 0)
    // - 0x2C: mret                     (Drops priv to U-mode: 3 -> 0, jumps to mepc 0x80000040!)
    // - 0x30: nop
    // - 0x34: nop
    // - 0x38: nop
    // - 0x3C: nop
    //
    // Block 2 (PC 0x80000040 - 0x8000005C) [User Mode Execution with PMP Write Violation]:
    // - 0x40: addi  x4, x0, 42         [EXECUTED IN USER MODE]: x4 = 42 (Allowed, R/X permitted)
    // - 0x44: sw    x4, 0x40(x1)       [PMP VIOLATION IN U-MODE]: Store to 0x80000040! Traps with cause 7!
    // - 0x48: addi  x6, x0, 999        [ANNULLED / SKIPPED]: Younger instruction must NEVER execute!
    // - 0x4C: nop
    // - 0x50: nop
    // - 0x54: nop
    // - 0x58: nop
    // - 0x5C: nop
    //
    // Block 3 (PC 0x80000060 - 0x8000007C) [Machine Mode Trap Handler]:
    // - 0x60: addi  x7, x0, 77         [RE-ENTERED MACHINE MODE]: x7 = 77 (0x4D, SUCCESS FLAG)
    // - 0x64: csrrw x8, 0x342, x0      (Read mcause into x8: MUST BE 7 for Store Access Fault!)
    // - 0x68: csrrw x9, 0x341, x0      (Read mepc into x9: MUST BE 0x80000044 pointing to illegal store!)
    // - 0x6C: csrrw x10, 0x343, x0     (Read mtval into x10: MUST BE 0x80000040 pointing to fault addr!)
    // - 0x70: jal   x0, 0              (Self-loop completion trap)
    // - 0x74: nop
    // - 0x78: nop
    // - 0x7C: nop
    // =========================================================================
    val programMemory = Seq(
      // --- BLOCK 0 (PC 0x80000000 - 0x8000001C): Machine Mode Setup Part 1 ---
      "h00000097".U(32.W), // 00 [Word 0]: auipc x1, 0              (x1 = 0x80000000)
      "h04008113".U(32.W), // 04 [Word 1]: addi  x2, x1, 0x40       (x2 = 0x80000040, user entry)
      "h34111073".U(32.W), // 08 [Word 2]: csrrw x0, 0x341, x2      (mepc := 0x80000040)
      "h06008193".U(32.W), // 0C [Word 3]: addi  x3, x1, 0x60       (x3 = 0x80000060, handler)
      "h30519073".U(32.W), // 10 [Word 4]: csrrw x0, 0x305, x3      (mtvec := 0x80000060)
      "h0020d593".U(32.W), // 14 [Word 5]: srli  x11, x1, 2         (x11 = 0x20000000)
      "h40058593".U(32.W), // 18 [Word 6]: addi  x11, x11, 0x400    (x11 = 0x20000400)
      "h3b059073".U(32.W), // 1C [Word 7]: csrrw x0, 0x3b0, x11     (pmpaddr0 := 0x20000400)

      // --- BLOCK 1 (PC 0x80000020 - 0x8000003C): Machine Mode Setup Part 2 & MRET ---
      "h00d00613".U(32.W), // 20 [Word 0]: addi  x12, x0, 13        (x12 = 0x0D: TOR, R=1, W=0, X=1)
      "h3a061073".U(32.W), // 24 [Word 1]: csrrw x0, 0x3a0, x12     (pmpcfg0 := 0x0D)
      "h30001073".U(32.W), // 28 [Word 2]: csrrw x0, 0x300, x0      (mstatus := 0, MPP = 0 for U-mode)
      "h30200073".U(32.W), // 2C [Word 3]: mret                     (Drops priv to U-mode, jumps to 0x80000040)
      "h00000013".U(32.W), // 30 [Word 4]: nop
      "h00000013".U(32.W), // 34 [Word 5]: nop
      "h00000013".U(32.W), // 38 [Word 6]: nop
      "h00000013".U(32.W), // 3C [Word 7]: nop

      // --- BLOCK 2 (PC 0x80000040 - 0x8000005C): User Mode Execution & PMP Violation ---
      "h02a00213".U(32.W), // 40 [Word 0]: addi  x4, x0, 42         (Executes in U-mode: x4 = 42)
      "h0440a023".U(32.W), // 44 [Word 1]: sw    x4, 0x40(x1)       (PMP VIOLATION: Store to write-protected region! Traps with cause 7!)
      "h3e700313".U(32.W), // 48 [Word 2]: addi  x6, x0, 999        (Must be discarded/never execute!)
      "h00000013".U(32.W), // 4C [Word 3]: nop
      "h00000013".U(32.W), // 50 [Word 4]: nop
      "h00000013".U(32.W), // 54 [Word 5]: nop
      "h00000013".U(32.W), // 58 [Word 6]: nop
      "h00000013".U(32.W), // 5C [Word 7]: nop

      // --- BLOCK 3 (PC 0x80000060 - 0x8000007C): Machine Mode Trap Handler ---
      "h04d00393".U(32.W), // 60 [Word 0]: addi  x7, x0, 77         (Handler: x7 = 77 / 0x4D)
      "h34201473".U(32.W), // 64 [Word 1]: csrrw x8, 0x342, x0      (Read mcause into x8: expected 7)
      "h341014f3".U(32.W), // 68 [Word 2]: csrrw x9, 0x341, x0      (Read mepc into x9: expected 0x80000044)
      "h34301573".U(32.W), // 6C [Word 3]: csrrw x10, 0x343, x0     (Read mtval into x10: expected 0x80000040)
      "h0000006f".U(32.W), // 70 [Word 4]: jal   x0, 0              (Done loop)
      "h00000013".U(32.W), // 74 [Word 5]: nop
      "h00000013".U(32.W), // 78 [Word 6]: nop
      "h00000013".U(32.W)  // 7C [Word 7]: nop
    ).padTo(1024, "h00000013".U(32.W))

    var memLatencyCounter = 0
    var memHandlingRequest = false
    var memRequestedAddr = 0L

    var dmemLatencyCounter = 0
    var dmemHandlingRequest = false
    var dmemRequestedAddr = 0L

    // --- MAIN SIMULATION LOOP ---
    val resetCycles = 5
    val maxCycles = 1000
    
    for (cycle <- 0 until maxCycles) {
      // 1. Apply Reset
      dut.reset.poke((cycle < resetCycles).B)
      
      val flush = dut.debug.get.ftq_flush.peek().litToBoolean

      // 2. Handle Flush (Clear our software model)
      if (flush) {
        // flush logic...
      }

      // 3. Memory Responder Logic (TileLink/AXI mock)
      if (cycle >= resetCycles) {
        // Read requests from the Core's L1 cache
        dut.io.mem.req.ready.poke(true.B) // We are always ready to accept a request
        
        if (dut.io.mem.req.valid.peek().litToBoolean && !memHandlingRequest) {
          memHandlingRequest = true
          memLatencyCounter = 50 // Simulate 50 cycles of DRAM latency!
          memRequestedAddr = dut.io.mem.req.bits.addr.peek().litValue.toLong
        }

        // Countdown latency
        if (memHandlingRequest) {
          if (memLatencyCounter > 0) {
            memLatencyCounter -= 1
            dut.io.mem.resp.valid.poke(false.B)
          } else {
            // Latency is over, send the data back!
            dut.io.mem.resp.valid.poke(true.B)
            
            // Build the 256-bit (8 instruction) response block
            val relativeWordAddr = ((memRequestedAddr - 0x80000000L) / 4).toInt
            var respData = BigInt(0)
            for (i <- 0 until params.fetchWidth) {
              val inst = if (relativeWordAddr >= 0 && relativeWordAddr + i < programMemory.length) {
                programMemory(relativeWordAddr + i).litValue
              } else {
                BigInt(0x00000013) // NOP
              }
              respData = respData | (inst << (i * 32))
            }
            dut.io.mem.resp.bits.data.poke(respData.U)
            dut.io.mem.resp.bits.last.poke(true.B)

            // If the core accepted the response, end the transaction
            if (dut.io.mem.resp.ready.peek().litToBoolean) {
              memHandlingRequest = false
            }
          }
        } else {
          dut.io.mem.resp.valid.poke(false.B)
        }
      } // End of Memory Responder

      // D-Cache Memory Responder Logic

      if (cycle >= resetCycles) {
        dut.io.mem_d.req.ready.poke(true.B)
        
        if (dut.io.mem_d.req.valid.peek().litToBoolean && !dmemHandlingRequest) {
          dmemHandlingRequest = true
          dmemLatencyCounter = 50 // 50 cycles for data miss too
          dmemRequestedAddr = dut.io.mem_d.req.bits.addr.peek().litValue.toLong
          println(f"Cycle $cycle%4d: [D-Cache / MSHR Bus Request] Addr = 0x$dmemRequestedAddr%08x")
        }

        if (dmemHandlingRequest) {
          if (dmemLatencyCounter > 0) {
            dmemLatencyCounter -= 1
            dut.io.mem_d.resp.valid.poke(false.B)
          } else {
            dut.io.mem_d.resp.valid.poke(true.B)
            dut.io.mem_d.resp.bits.data.poke(BigInt("DEADBEEFCAFEBABE", 16).U) // Return some dummy memory data
            dut.io.mem_d.resp.bits.last.poke(true.B)

            if (dut.io.mem_d.resp.ready.peek().litToBoolean) {
              println(f"Cycle $cycle%4d: [D-Cache / MSHR Bus Response] Fulfilled Addr = 0x$dmemRequestedAddr%08x")
              dmemHandlingRequest = false
            }
          }
        } else {
          dut.io.mem_d.resp.valid.poke(false.B)
        }
      }

      // 4. Capture ENQUEUE (Frontend -> FTQ)
      val enqValid = dut.debug.get.ftq_valid.peek().litToBoolean
      val enqReady = dut.debug.get.ftq_ready.peek().litToBoolean

      if (enqValid && enqReady && !flush && cycle >= resetCycles) {
        val pc    = dut.debug.get.ftq_pc.peek().litValue
        val mask  = dut.debug.get.ftq_mask.peek().litValue
        val insts = (0 until params.fetchWidth).map(i => f"0x${dut.debug.get.ftq_insts(i).peek().litValue}%08x").mkString(",")
        val pTarget = dut.debug.get.ftq_pred_target.peek().litValue
        val pTaken  = dut.debug.get.ftq_pred_taken.peek().litToBoolean
        val pSlot   = dut.debug.get.ftq_pred_slot.peek().litValue
        
        shadowFTQ(manualWritePtr) = f"0x$pc%08x,${mask.toString(2)},$insts,0x$pTarget%08x,$pTaken,$pSlot"
        manualWritePtr = (manualWritePtr + 1) % params.ftqEntries
      }

      // 4. Capture DEQUEUE (FTQ -> Backend)
      // This is the new logic to see the Backend "eating" instructions
      val deqValid = dut.debug.get.ftq_valid_out.peek().litToBoolean // You may need to expose this in Core
      val deqReady = dut.debug.get.ftq_ready_out.peek().litToBoolean 

      if (deqValid && deqReady && !flush && cycle >= resetCycles) {
        // Remove from shadow map to show "EMPTY" in CSV
        shadowFTQ.remove(manualReadPtr)
        manualReadPtr = (manualReadPtr + 1) % params.ftqEntries
      }

      if (cycle >= resetCycles) {
        val disp0_valid = dut.debug.get.disp0_valid.peek().litToBoolean
        if (disp0_valid) {
          val disp0_pc = dut.debug.get.disp0_pc.peek().litValue
          val disp0_pdest = dut.debug.get.disp0_pdest.peek().litValue
          println(f"Cycle $cycle: Dispatch 0 PC=0x$disp0_pc%08x PDEST=p$disp0_pdest")
        }
      }

      // 5. Periodic Dump (Disabled for speed, uncomment if debugging FTQ)
      // if (cycle >= 5 && cycle <= 800) {
      //   dumpToCSV(cycle)
      // }

      dut.clock.step(1)
    }

    csvFile.close() 
    println(s"--- Simulation Finished. CSV generated: ftq_dump.csv ---")
    
    println("--- Final Logical Integer Register State (Architectural / Speculative RAT) ---")
    for (i <- 0 until 32) {
      val pRegIdx = dut.debug.get.debug_int_rat(i).peek().litValue.toInt
      val regVal = if (i == 0) BigInt(0) else dut.debug.get.regs(pRegIdx).peek().litValue
      println(f"x$i%02d (maps to p$pRegIdx%02d): 0x$regVal%016x")
    }

    println("--- Final Logical FP Register State (Architectural / Speculative RAT) ---")
    for (i <- 0 until 32) {
      val pRegIdx = dut.debug.get.debug_fp_rat(i).peek().litValue.toInt
      val regVal = dut.debug.get.fp_regs(pRegIdx).peek().litValue
      println(f"f$i%02d (maps to pf$pRegIdx%02d): 0x$regVal%016x")
    }

    println("--- Final Physical Register State ---")
    for (i <- 0 until params.phyRegs) {
      val regVal = dut.debug.get.regs(i).peek().litValue
      println(f"p$i%02d: 0x$regVal%016x")
    }

    println("--- Final Physical FP Register State ---")
    for (i <- 0 until params.phyRegs) {
      val regVal = dut.debug.get.fp_regs(i).peek().litValue
      println(f"pf$i%02d: 0x$regVal%016x")
    }
  }

  // --- VCD CLEANUP LOGIC ---
  val targetVcd = new File("programs/vcd/Lithium.vcd")
  val testRunDir = new File("test_run_dir")
  if (testRunDir.exists()) {
    val vcdFiles = testRunDir.listFiles().filter(_.isDirectory).flatMap(_.listFiles()).filter(_.getName.endsWith(".vcd"))
    if (vcdFiles.nonEmpty) {
      Files.copy(vcdFiles.sortBy(_.lastModified()).last.toPath, targetVcd.toPath, StandardCopyOption.REPLACE_EXISTING)
    }
  }
}
