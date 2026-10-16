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
    // DAY 17-20 TEST: CLINT TIMER INTERRUPT & MID-PROGRAM HARDWARE PREEMPTION
    // =========================================================================
    // DAY 21-25 TEST: VECTOR OUT-OF-ORDER INTEGRATION (RENAME & DISPATCH)
    // =========================================================================
    // Verification Flow:
    // 1. Setup base memory address:
    //    - addi       x1,  x0, 0x10        (base load address = 0x0010)
    // 2. Configure vector state: e32, m1 -> VLMAX = (128/32)*1 = 4 elements:
    //    - vsetvli    x11, x0, 0x0D0       (SEW=32-bit, LMUL=1 -> x11 := 4)
    // 3. Unit-Stride Vector Load:
    //    - vle32.v    v1, (x1)             (v1 allocated physical register pv32)
    // 4. Vector-Immediate Arithmetic:
    //    - vadd.vi    v2, v1, 10           (v2 allocated physical register pv33)
    // 5. WAW Hazard & Vector Renaming Test:
    //    - Overwrite v1 with new result! Tests Vector Rename Table (VRAT) mapping:
    //    - vadd.vi    v1, v2, 5            (v1 remapped to new physical register pv34!)
    // 6. Vector-Scalar Arithmetic reading remapped v1:
    //    - addi       x2, x0, 2            (scalar multiplier = 2)
    //    - vmul.vx    v3, v1, x2           (v3 reads new v1 (pv34), allocated pv35)
    // 7. Decoupled Vector Dispatch & Parallel Scalar Execution:
    //    - While vector operations stream, scalar integer pipeline executes concurrently:
    //    - addi       x20, x0, 100         (x20 := 100)
    //    - addi       x21, x0, 200         (x21 := 200)
    //    - add        x22, x20, x21        (x22 := 300 = 0x12c)
    // 8. Day 21-25 PASS Flag:
    //    - addi       x29, x0, 0x25        (PASS Flag: x29 := 0x25)
    // 9. Settle loop:
    //    - jal        x0, -4
    // =========================================================================
    val programMemory = Seq(
      // --- BLOCK 0 (PC 0x80000000 - 0x8000001C) ---
      "h01000093".U(32.W), // 00 [Word 0]: addi     x1,  x0, 0x10        (load base = 0x10)
      "h0d0075d7".U(32.W), // 04 [Word 1]: vsetvli  x11, x0, 0x0D0       (e32, m1 -> vl = 4)
      "h0200e087".U(32.W), // 08 [Word 2]: vle32.v  v1, (x1)             (load 4 words to v1 -> pv32)
      "h02153157".U(32.W), // 0C [Word 3]: vadd.vi  v2, v1, 10           (v2 := v1 + 10 -> pv33)
      "h0222b0d7".U(32.W), // 10 [Word 4]: vadd.vi  v1, v2, 5            (WAW! v1 remapped -> pv34)
      "h00200113".U(32.W), // 14 [Word 5]: addi     x2, x0, 2            (scalar mult = 2)
      "h961141d7".U(32.W), // 18 [Word 6]: vmul.vx  v3, v1, x2           (v3 := v1 * 2 -> pv35)
      "h06400a13".U(32.W), // 1C [Word 7]: addi     x20, x0, 100         (scalar execution)

      // --- BLOCK 1 (PC 0x80000020 - 0x8000003C) ---
      "h0c800a93".U(32.W), // 20 [Word 0]: addi     x21, x0, 200         (scalar execution)
      "h015a0b33".U(32.W), // 24 [Word 1]: add      x22, x20, x21        (scalar x22 := 300)
      "h02500e93".U(32.W), // 28 [Word 2]: addi     x29, x0, 0x25        (Day 21-25 PASS Flag: 0x25)
      "hffdff06f".U(32.W), // 2C [Word 3]: jal      x0, -4               (settle loop)
      "h00000013".U(32.W), // 30 [Word 4]: nop
      "h00000013".U(32.W), // 34 [Word 5]: nop
      "h00000013".U(32.W), // 38 [Word 6]: nop
      "h00000013".U(32.W)  // 3C [Word 7]: nop
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
      dut.io.plic_ext_irq.poke(0.U)
      
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
          // println(f"Cycle $cycle%4d: [D-Cache / MSHR Bus Request] Addr = 0x$dmemRequestedAddr%08x")
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
              // println(f"Cycle $cycle%4d: [D-Cache / MSHR Bus Response] Fulfilled Addr = 0x$dmemRequestedAddr%08x")
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
          // println(f"Cycle $cycle: Dispatch 0 PC=0x$disp0_pc%08x PDEST=p$disp0_pdest")
        }

        val uartValid = dut.io.uart_tx_valid.peek().litToBoolean
        if (uartValid) {
          val charByte = dut.io.uart_tx_char.peek().litValue.toInt
          println(f"Cycle $cycle%4d: >>> [UART SERIAL CONSOLE TX]: '${charByte.toChar}' (0x$charByte%02X) <<<")
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

    println("--- Final Vector Architecture State (RVV 1.0 - VRAT Renamed) ---")
    val v_vl = dut.debug.get.vec_vl.peek().litValue
    val v_vtype = dut.debug.get.vec_vtype.peek().litValue
    println(f"VL: 0x$v_vl%016x (Dec: $v_vl)")
    println(f"VTYPE: 0x$v_vtype%016x (vill=${v_vtype >> 63}, vsew=${(v_vtype >> 3) & 7}, vlmul=${v_vtype & 7})")
    for (i <- 0 until 32) {
      val pRegIdx = dut.debug.get.debug_vec_rat(i).peek().litValue.toInt
      val vVal = dut.debug.get.vregs(i).peek().litValue
      println(f"v$i%02d (maps to pv$pRegIdx%02d): 0x$vVal%032x")
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
