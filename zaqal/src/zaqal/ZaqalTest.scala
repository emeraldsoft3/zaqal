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


    // Day 29-31: Spatial Memory Streaming (SMS) Prefetcher Verification Program (Option C)
    // - Region 0: Base pointer x1 = 0. Reads pre-initialized DataMem test values into PRF!
    //   Touches Block 0 (offset 0), Block 5 (offset 160), Block 7 (offset 224).
    //   AGT tracks footprint bitmask: {0, 5, 7} for PC 0x04.
    // - Eviction Phase: Touches 8 distinct 1KB regions (2048, 3072, 4096, 5120, 6144, 7168, 8192, 9216).
    //   This causes AGT round-robin eviction, writing back Region 0's footprint to PHT!
    // - Region 1: Base pointer x6 = 1024 (0x400).
    //   Load at PC 0x04 (or same hashed PC) immediately triggers SMS prefetch!
    //   SMS recalls footprint and prefetches Block 5 (0x4A0) and Block 7 (0x4E0)!
    val programMemory = Seq(
      // --- PACKET 0 (PC 0x00 - 0x14): Base Address Init & Region 0 Training ---
      "h00000093".U(32.W), // 00 [Slot 0]: addi x1, x0, 0            (x1 = 0, Option C base)
      "h0000b103".U(32.W), // 04 [Slot 1]: ld   x2, 0(x1)            (Block 0 -> loads 0xAABBCCDD11223344, trigger PC!)
      "h0080b183".U(32.W), // 08 [Slot 2]: ld   x3, 8(x1)            (Block 0 -> loads 0x5566778899AABBCC)
      "h0a00b203".U(32.W), // 0C [Slot 3]: ld   x4, 160(x1)          (Block 5 -> touches offset 160)
      "h0e00b283".U(32.W), // 10 [Slot 4]: ld   x5, 224(x1)          (Block 7 -> touches offset 224)
      "h00000013".U(32.W), // 14 [Slot 5]: nop

      // --- PACKET 1 (PC 0x18 - 0x2C): AGT Eviction Dummy 1 & 2 ---
      "h80000313".U(32.W), // 18 [Slot 0]: addi x6, x0, 2048         (Region 2)
      "h00033383".U(32.W), // 1C [Slot 1]: ld   x7, 0(x6)
      "hc0000313".U(32.W), // 20 [Slot 2]: addi x6, x0, -1024        (or 3072)
      "h00033383".U(32.W), // 24 [Slot 3]: ld   x7, 0(x6)
      "h00000013".U(32.W), // 28 [Slot 4]: nop
      "h00000013".U(32.W), // 2C [Slot 5]: nop

      // --- PACKET 2 (PC 0x30 - 0x44): AGT Eviction Dummy 3 & 4 ---
      "h00200313".U(32.W), // 30 [Slot 0]: addi x6, x0, 2            
      "h00c31313".U(32.W), // 34 [Slot 1]: slli x6, x6, 12           (x6 = 8192)
      "h00033383".U(32.W), // 38 [Slot 2]: ld   x7, 0(x6)
      "h00300313".U(32.W), // 3C [Slot 3]: addi x6, x0, 3
      "h00c31313".U(32.W), // 40 [Slot 4]: slli x6, x6, 12           (x6 = 12288)
      "h00033383".U(32.W), // 44 [Slot 5]: ld   x7, 0(x6)

      // --- PACKET 3 (PC 0x48 - 0x5C): AGT Eviction Dummy 5 & 6 ---
      "h00400313".U(32.W), // 48 [Slot 0]: addi x6, x0, 4
      "h00c31313".U(32.W), // 4C [Slot 1]: slli x6, x6, 12           (x6 = 16384)
      "h00033383".U(32.W), // 50 [Slot 2]: ld   x7, 0(x6)
      "h00500313".U(32.W), // 54 [Slot 3]: addi x6, x0, 5
      "h00c31313".U(32.W), // 58 [Slot 4]: slli x6, x6, 12           (x6 = 20480)
      "h00033383".U(32.W), // 5C [Slot 5]: ld   x7, 0(x6)

      // --- PACKET 4 (PC 0x60 - 0x74): AGT Eviction Dummy 7 & 8 ---
      "h00600313".U(32.W), // 60 [Slot 0]: addi x6, x0, 6
      "h00c31313".U(32.W), // 64 [Slot 1]: slli x6, x6, 12           (x6 = 24576)
      "h00033383".U(32.W), // 68 [Slot 2]: ld   x7, 0(x6)
      "h00700313".U(32.W), // 6C [Slot 3]: addi x6, x0, 7
      "h00c31313".U(32.W), // 70 [Slot 4]: slli x6, x6, 12           (x6 = 28672 -> Evicts Region 0 to PHT!)
      "h00033383".U(32.W), // 74 [Slot 5]: ld   x7, 0(x6)

      // --- PACKET 5 (PC 0x78 - 0x8C): Set New Base (Region 1 = 1024) and Trigger PC ---
      "h40000313".U(32.W), // 78 [Slot 0]: addi x6, x0, 1024         (x6 = 1024 = 0x400)
      "h00000013".U(32.W), // 7C [Slot 1]: nop
      "h00000013".U(32.W), // 80 [Slot 2]: nop
      "h00000013".U(32.W), // 84 [Slot 3]: nop
      "h00000013".U(32.W), // 88 [Slot 4]: nop
      "h00000013".U(32.W), // 8C [Slot 5]: nop

      // --- PACKET 6 (PC 0x90 - 0xA4): Region 1 Recall & SMS Prefetch ---
      // Note: We loop back to PC 0x00 with x1 = 1024 so PC 0x04 triggers PHT match!
      "h00030093".U(32.W), // 90 [Slot 0]: addi x1, x6, 0            (x1 = 1024)
      "h00000313".U(32.W), // 94 [Slot 1]: addi x6, x0, 0            (clear x6 so loop runs once)
      "hf6dff06f".U(32.W), // 98 [Slot 2]: jal  x0, -148             (jump to PC 0x04! Trigger PC matches!)
      "h00000013".U(32.W), // 9C [Slot 3]: nop
      "h00000013".U(32.W), // A0 [Slot 4]: nop
      "h00000013".U(32.W), // A4 [Slot 5]: nop

      // --- PACKET 7 (PC 0xA8): Infinite Loop Trap ---
      "h0000006f".U(32.W)  // A8: j    0xA8
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
