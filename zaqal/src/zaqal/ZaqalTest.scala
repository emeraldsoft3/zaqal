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
    // DAY 8-10 / 11-13 TEST: SFENCE.VMA (TLB INVALIDATION & RE-WALK VERIFICATION)
    // =========================================================================
    // Block-Aligned Fetch Structure (32-byte / 8-instruction fetch blocks):
    //
    // Block 0 (PC 0x80000000 - 0x8000001C) [Machine Mode Setup satp for Sv39]:
    // - 0x00: auipc x1, 0              (x1 = 0x80000000 = PC base)
    // - 0x04: addi  x2, x0, 8          (x2 = 8: Sv39 MODE value)
    // - 0x08: slli  x2, x2, 60         (x2 = 0x8000000000000000)
    // - 0x0C: srli  x3, x1, 12         (x3 = 0x80000 = root page table PPN)
    // - 0x10: or    x2, x2, x3         (x2 = 0x8000000000080000 = satp with MODE=8, PPN=0x80000)
    // - 0x14: csrrw x0, 0x180, x2      (satp := x2, ENABLES SV39 VIRTUAL MEMORY TRANSLATION!)
    // - 0x18: nop
    // - 0x1C: nop
    //
    // Block 1 (PC 0x80000020 - 0x8000003C) [Pipeline Stabilization NOP Cushion]:
    // - 8x NOP (allows csrrw satp to fully commit without speculative memory requests)
    //
    // Block 2 (PC 0x80000040 - 0x8000005C) [Cold Miss & Initial TLB Refill]:
    // - 0x40: ld    x5, 0x10(x0)       [COLD MISS]: Hardware PTW refills TLB 0!
    // - 0x44..0x5C: 7x Delay addi instructions
    //
    // Block 3 (PC 0x80000060 - 0x8000007C) [Warm Hit & sfence.vma Invalidation]:
    // - 0x60: ld    x6, 0x10(x0)       [WARM HIT!]: io_hit = 1, io_paddr = 0x80000010!
    // - 0x64: sfence.vma x0, x0        [SFENCE.VMA]: Flushes all TLB entries! Valid bits -> 0!
    // - 0x68..0x7C: 6x Delay addi instructions
    //
    // Block 4 (PC 0x80000080 - 0x8000009C) [Post-Flush Cold Miss & Re-Walk]:
    // - 0x80: ld    x7, 0x10(x0)       [COLD MISS AGAIN!]: TLB entry was flushed! PTW walks again!
    // - 0x84: addi  x28, x0, 77        (SUCCESS FLAG: x28 = 77 / 0x4D)
    // - 0x88: jal   x0, 0              (Done loop)
    // - 0x8C..0x9C: 5x NOPs
    // =========================================================================
    val programMemory = Seq(
      // --- BLOCK 0 (PC 0x80000000 - 0x8000001C): Machine Mode Setup satp for Sv39 ---
      "h00000097".U(32.W), // 00 [Word 0]: auipc x1, 0              (x1 = 0x80000000)
      "h00800113".U(32.W), // 04 [Word 1]: addi  x2, x0, 8          (x2 = 8)
      "h03c11113".U(32.W), // 08 [Word 2]: slli  x2, x2, 60         (x2 = 0x8000000000000000)
      "h00c0d193".U(32.W), // 0C [Word 3]: srli  x3, x1, 12         (x3 = 0x80000)
      "h00316133".U(32.W), // 10 [Word 4]: or    x2, x2, x3         (x2 = 0x8000000000080000)
      "h18011073".U(32.W), // 14 [Word 5]: csrrw x0, 0x180, x2      (satp := x2, Activates Sv39 translation!)
      "h00000013".U(32.W), // 18 [Word 6]: nop
      "h00000013".U(32.W), // 1C [Word 7]: nop

      // --- BLOCK 1 (PC 0x80000020 - 0x8000003C): Pipeline Stabilization (NOP Cushion) ---
      "h00000013".U(32.W), // 20: nop (Allows satp CSR write to fully commit and retire)
      "h00000013".U(32.W), // 24: nop
      "h00000013".U(32.W), // 28: nop
      "h00000013".U(32.W), // 2C: nop
      "h00000013".U(32.W), // 30: nop
      "h00000013".U(32.W), // 34: nop
      "h00000013".U(32.W), // 38: nop
      "h00000013".U(32.W), // 3C: nop

      // --- BLOCK 2 (PC 0x80000040 - 0x8000005C): Cold Miss & Initial Refill ---
      "h01003283".U(32.W), // 40 [Word 0]: ld    x5, 0x10(x0)       (Cold Miss -> Hardware PTW Refills TLB!)
      "h00100513".U(32.W), // 44 [Word 1]: addi  x10, x0, 1         (Delay cycle for PTW FSM walk)
      "h00150513".U(32.W), // 48 [Word 2]: addi  x10, x10, 1        (Delay cycle)
      "h00150513".U(32.W), // 4C [Word 3]: addi  x10, x10, 1        (Delay cycle)
      "h00150513".U(32.W), // 50 [Word 4]: addi  x10, x10, 1        (Delay cycle)
      "h00150513".U(32.W), // 54 [Word 5]: addi  x10, x10, 1        (Delay cycle)
      "h00150513".U(32.W), // 58 [Word 6]: addi  x10, x10, 1        (Delay cycle)
      "h00150513".U(32.W), // 5C [Word 7]: addi  x10, x10, 1        (Delay cycle)

      // --- BLOCK 3 (PC 0x80000060 - 0x8000007C): Warm Hit & sfence.vma Flush ---
      "h01003303".U(32.W), // 60 [Word 0]: ld    x6, 0x10(x0)       (WARM HIT! io_hit=1, io_paddr=0x80000010!)
      "h12000073".U(32.W), // 64 [Word 1]: sfence.vma x0, x0        (SFENCE.VMA -> FLUSHES ALL TLB ENTRIES!)
      "h00100513".U(32.W), // 68 [Word 2]: addi  x10, x0, 1         (Delay cycle)
      "h00150513".U(32.W), // 6C [Word 3]: addi  x10, x10, 1        (Delay cycle)
      "h00150513".U(32.W), // 70 [Word 4]: addi  x10, x10, 1        (Delay cycle)
      "h00150513".U(32.W), // 74 [Word 5]: addi  x10, x10, 1        (Delay cycle)
      "h00150513".U(32.W), // 78 [Word 6]: addi  x10, x10, 1        (Delay cycle)
      "h00150513".U(32.W), // 7C [Word 7]: addi  x10, x10, 1        (Delay cycle)

      // --- BLOCK 4 (PC 0x80000080 - 0x8000009C): Post-Flush Cold Miss & Re-Walk ---
      "h01003383".U(32.W), // 80 [Word 0]: ld    x7, 0x10(x0)       (COLD MISS AGAIN! io_hit=0! Forced Re-Walk!)
      "h04d00e13".U(32.W), // 84 [Word 1]: addi  x28, x0, 77        (SUCCESS FLAG: x28 = 77 / 0x4D)
      "h0000006f".U(32.W), // 88 [Word 2]: jal   x0, 0              (Done loop)
      "h00000013".U(32.W), // 8C [Word 3]: nop
      "h00000013".U(32.W), // 90 [Word 4]: nop
      "h00000013".U(32.W), // 94 [Word 5]: nop
      "h00000013".U(32.W), // 98 [Word 6]: nop
      "h00000013".U(32.W)  // 9C [Word 7]: nop
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
