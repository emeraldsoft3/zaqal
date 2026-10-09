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
    // Flow:
    // 1. Core starts in M-mode.
    // 2. Setup (Block 0 & Block 1):
    //    - Sets mtvec = 0x80000080 (Trap Handler Vector)
    //    - Programs CLINT mtimecmp (0x02004000) = 80 cycles
    //    - Enables mie.MTIE (bit 7)
    //    - Enables mstatus.MIE (bit 3)
    // 3. Workload Loop (Block 1):
    //    - Executes infinite counter increment: x10 = x10 + 1; j loop
    // 4. Hardware Preemption:
    //    - When mtime >= 80, CLINT asserts mtip wire directly into CSRFile.
    //    - CSRFile arbitrates Machine Timer Interrupt (mcause = 0x8000000000000007).
    //    - Execute stage preempts the loop, snapshots mepc, and redirects to mtvec!
    // 5. Interrupt Handler (Block 4 at 0x80000080):
    //    - Writes 'T' (0x54) to UART 16550 THR (0x10000000)
    //    - Sets preemption verification flag x29 = 0xAA
    //    - Pushes mtimecmp far into future (0xFFFFFFFFFFFFFFFF)
    //    - Executes mret -> returns to mepc and restores mstatus.MIE!
    // 6. Resumption:
    //    - The counting loop resumes seamlessly, incrementing x10!
    // =========================================================================
    val programMemory = Seq(
      // --- BLOCK 0 (PC 0x80000000 - 0x8000001C): Setup Trap Vector mtvec = 0x80000080 ---
      "h00000297".U(32.W), // 00 [Word 0]: auipc x5, 0              (x5 = 0x80000000)
      "h08028293".U(32.W), // 04 [Word 1]: addi  x5, x5, 0x80       (x5 = 0x80000080 = Trap Handler)
      "h30529073".U(32.W), // 08 [Word 2]: csrrw x0, 0x305, x5      (mtvec := 0x80000080)
      "h00000013".U(32.W), // 0C [Word 3]: nop
      "h00000013".U(32.W), // 10 [Word 4]: nop
      "h00000013".U(32.W), // 14 [Word 5]: nop
      "h00000013".U(32.W), // 18 [Word 6]: nop
      "h00000013".U(32.W), // 1C [Word 7]: nop

      // --- BLOCK 1 (PC 0x80000020 - 0x8000003C): Program CLINT mtimecmp ---
      "h02004337".U(32.W), // 20 [Word 0]: lui   x6, 0x02004        (x6 = 0x02004000 = CLINT mtimecmp)
      "h15e00393".U(32.W), // 24 [Word 1]: addi  x7, x0, 350        (x7 = 350 cycles threshold)
      "h00733023".U(32.W), // 28 [Word 2]: sd    x7, 0(x6)          (CLINT mtimecmp := 150)
      "h00000013".U(32.W), // 2C [Word 3]: nop
      "h00000013".U(32.W), // 30 [Word 4]: nop
      "h00000013".U(32.W), // 34 [Word 5]: nop
      "h00000013".U(32.W), // 38 [Word 6]: nop
      "h00000013".U(32.W), // 3C [Word 7]: nop

      // --- BLOCK 2 (PC 0x80000040 - 0x8000005C): Enable MTIE & MIE ---
      "h08000413".U(32.W), // 40 [Word 0]: addi  x8, x0, 0x80       (x8 = 0x80 = MTIE)
      "h30441073".U(32.W), // 44 [Word 1]: csrrw x0, 0x304, x8      (mie := 0x80)
      "h00800493".U(32.W), // 48 [Word 2]: addi  x9, x0, 0x08       (x9 = 0x08 = MIE)
      "h30049073".U(32.W), // 4C [Word 3]: csrrw x0, 0x300, x9      (mstatus := 0x08: Interrupts enabled!)
      "h00000013".U(32.W), // 50 [Word 4]: nop
      "h00000013".U(32.W), // 54 [Word 5]: nop
      "h00000013".U(32.W), // 58 [Word 6]: nop
      "h00000013".U(32.W), // 5C [Word 7]: nop

      // --- BLOCK 3 (PC 0x80000060 - 0x8000007C): Workload Loop (To be Preempted!) ---
      "h00150513".U(32.W), // 60 [Word 0]: addi  x10, x10, 1        (counter++)
      "hffdff06f".U(32.W), // 64 [Word 1]: jal   x0, -4             (loop to 0x60)
      "h00000013".U(32.W), // 68 [Word 2]: nop
      "h00000013".U(32.W), // 6C [Word 3]: nop
      "h00000013".U(32.W), // 70 [Word 4]: nop
      "h00000013".U(32.W), // 74 [Word 5]: nop
      "h00000013".U(32.W), // 78 [Word 6]: nop
      "h00000013".U(32.W), // 7C [Word 7]: nop

      // --- BLOCK 4 (PC 0x80000080 - 0x8000009C): Trap Handler in M-mode ---
      "h100002b7".U(32.W), // 80 [Word 0]: lui   x5, 0x10000        (x5 = 0x10000000 = UART Base)
      "h05400e93".U(32.W), // 84 [Word 1]: addi  x29, x0, 0x54      (x29 = 'T' = 0x54)
      "h01d28023".U(32.W), // 88 [Word 2]: sb    x29, 0(x5)         (UART THR := 'T': Print to console!)
      "h0aa00e93".U(32.W), // 8C [Word 3]: addi  x29, x0, 0xaa      (SUCCESS FLAG: x29 := 0xAA)
      "h02004337".U(32.W), // 90 [Word 4]: lui   x6, 0x02004        (x6 = 0x02004000 = mtimecmp)
      "hfff00393".U(32.W), // 94 [Word 5]: addi  x7, x0, -1         (x7 = 0xFFFFFFFFFFFFFFFF)
      "h00733023".U(32.W), // 98 [Word 6]: sd    x7, 0(x6)          (CLINT mtimecmp := max: disarm timer)
      "h30200073".U(32.W)  // 9C [Word 7]: mret                     (RESUME INTERRUPTED WORKLOAD LOOP AT mepc!)
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
