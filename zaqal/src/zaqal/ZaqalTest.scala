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


    // Day 25.8: Full XiangShan-Parity Micro-op Fusion Comprehensive Verification Program
    // Tests:
    // 1.  LUI + ADDI (Fused LUI32: x1 = 0x12345678)
    // 2.  SLLI 1 + ADD (Fused SH1ADD: x4 = (10 << 1) + 5 = 25 = 0x19)
    // 3.  SLLI 2 + ADD (Fused SH2ADD: x5 = (10 << 2) + 5 = 45 = 0x2D)
    // 4.  SLLI 3 + ADD (Fused SH3ADD: x6 = (10 << 3) + 5 = 85 = 0x55)
    // 5.  SLLI 32 + SRLI 32 (Fused ZEXT.W: x9 = 0x00000000FFFFFFFF)
    // 6.  SRLI 8 + ANDI 255 (Fused BYTE2: x11 = 0x56)
    // 7.  ADD + ANDI 255 (Fused ADD_BYTE: x17 = (200 + 100) & 255 = 44 = 0x2C)
    // 8.  LW + ADDI (Fused LOAD_ALU: x20 = 42 + 10 = 52 = 0x34)
    // 9.  SRLI 32 + ADD (Fused SR32ADD: x22 = (x8 >> 32) + x3 = 0x0000000100000004)
    // 10. SLLI 32 + SRLI 31 (Fused SZEWL1: x25 = (10(31,0) << 1) = 20 = 0x14)
    // 11. ANDI 1 + ADD (Fused ODDADD: x27 = (15 & 1) + 5 = 6 = 0x06)
    // 12. ANDI 1 + ADDW (Fused ODDADDW: x29 = (24 & 1) + 5 = 5 = 0x05)
    val programMemory = Seq(
      "h123450b7".U(32.W), // 00: lui  x1, 0x12345
      "h67808093".U(32.W), // 04: addi x1, x1, 0x678        (Fused LUI32: x1 = 0x12345678)
      "h00a00113".U(32.W), // 08: addi x2, x0, 10           (x2 = 10)
      "h00500193".U(32.W), // 0C: addi x3, x0, 5            (x3 = 5)
      "h00111213".U(32.W), // 10: slli x4, x2, 1
      "h00320233".U(32.W), // 14: add  x4, x4, x3           (Fused SH1ADD: x4 = 25 = 0x19)
      "h00211293".U(32.W), // 18: slli x5, x2, 2
      "h003282b3".U(32.W), // 1C: add  x5, x5, x3           (Fused SH2ADD: x5 = 45 = 0x2D)
      "h00311313".U(32.W), // 20: slli x6, x2, 3
      "h00330333".U(32.W), // 24: add  x6, x6, x3           (Fused SH3ADD: x6 = 85 = 0x55)
      "hfff00413".U(32.W), // 28: addi x8, x0, -1           (x8 = 0xFFFFFFFFFFFFFFFF)
      "h02041493".U(32.W), // 2C: slli x9, x8, 32
      "h0204d493".U(32.W), // 30: srli x9, x9, 32           (Fused ZEXT.W: x9 = 0x00000000FFFFFFFF)
      "h0080d593".U(32.W), // 34: srli x11, x1, 8
      "h0ff5f593".U(32.W), // 38: andi x11, x11, 255        (Fused BYTE2: x11 = 0x56)
      "h0c800793".U(32.W), // 3C: addi x15, x0, 200         (x15 = 200)
      "h06400813".U(32.W), // 40: addi x16, x0, 100         (x16 = 100)
      "h010788b3".U(32.W), // 44: add  x17, x15, x16
      "h0ff8f8b3".U(32.W), // 48: andi x17, x17, 255        (Fused ADD_BYTE: x17 = 44 = 0x2C)
      "h10000913".U(32.W), // 4C: addi x18, x0, 256         (x18 = 256, address base)
      "h02a00993".U(32.W), // 50: addi x19, x0, 42          (x19 = 42, store data)
      "h01392023".U(32.W), // 54: sw   x19, 0(x18)          (Mem[256] = 42)
      "h00092a03".U(32.W), // 58: lw   x20, 0(x18)
      "h00aa0a13".U(32.W), // 5C: addi x20, x20, 10         (Fused LOAD_ALU: x20 = 42 + 10 = 52 = 0x34)
      "h02045b13".U(32.W), // 60: srli x22, x8, 32
      "h003b0b33".U(32.W), // 64: add  x22, x22, x3         (Fused SR32ADD: x22 = (x8 >> 32) + x3 = 0x100000004)
      "h02011c93".U(32.W), // 68: slli x25, x2, 32
      "h01fcdc93".U(32.W), // 6C: srli x25, x25, 31         (Fused SZEWL1: x25 = (10(31,0) << 1) = 20 = 0x14)
      "h00f00d13".U(32.W), // 70: addi x26, x0, 15          (x26 = 15, odd)
      "h001d7d93".U(32.W), // 74: andi x27, x26, 1
      "h003d8db3".U(32.W), // 78: add  x27, x27, x3         (Fused ODDADD: x27 = (x26 & 1) + 5 = 6)
      "h01800e13".U(32.W), // 7C: addi x28, x0, 24          (x28 = 24, even)
      "h001e7e93".U(32.W), // 80: andi x29, x28, 1
      "h003e8ebb".U(32.W), // 84: addw x29, x29, x3         (Fused ODDADDW: x29 = (x28 & 1) + 5 = 5)
      "h0000006f".U(32.W)  // 88: j    0x88                 (infinite loop trap)
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
