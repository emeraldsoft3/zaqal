package zaqal

import zaqal.common._

import chisel3._
import chiseltest._
import java.io.{File, PrintWriter}
import java.nio.file.{Files, StandardCopyOption}

object ZaqalTest extends App {
  val vcdPath = "programs/vcd"
  new File(vcdPath).mkdirs()

  implicit val p = (new ZaqalConfig).alter((site, here, up) => {
    case ZaqalParamsKey => up(ZaqalParamsKey).copy(programFile = "programs/hex/rvc_test.hex")
  })
  val params = p(ZaqalParamsKey)

  RawTester.test(new Core(), Seq(WriteVcdAnnotation)) { dut =>
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

    // --- MAIN SIMULATION LOOP ---
    val resetCycles = 5
    val maxCycles = 60 // Reduced as per user request
    
    for (cycle <- 0 until maxCycles) {
      // 1. Apply Reset
      dut.reset.poke((cycle < resetCycles).B)
      
      val flush = dut.io.debug_ftq_flush.peek().litToBoolean

      // 2. Handle Flush (Clear our software model)
      if (flush) {
        shadowFTQ.clear()
        manualWritePtr = 0
        manualReadPtr = 0
        println(s"[Cycle $cycle] FTQ Flushed! Shadow copy cleared.")
      }

      // 3. Capture ENQUEUE (Frontend -> FTQ)
      val enqValid = dut.io.debug_ftq_valid.peek().litToBoolean
      val enqReady = dut.io.debug_ftq_ready.peek().litToBoolean

      if (enqValid && enqReady && !flush && cycle >= resetCycles) {
        val pc    = dut.io.debug_ftq_pc.peek().litValue
        val mask  = dut.io.debug_ftq_mask.peek().litValue
        val insts = (0 until params.fetchWidth).map(i => f"0x${dut.io.debug_ftq_insts(i).peek().litValue}%08x").mkString(",")
        val pTarget = dut.io.debug_ftq_pred_target.peek().litValue
        val pTaken  = dut.io.debug_ftq_pred_taken.peek().litToBoolean
        val pSlot   = dut.io.debug_ftq_pred_slot.peek().litValue
        
        shadowFTQ(manualWritePtr) = f"0x$pc%08x,${mask.toString(2)},$insts,0x$pTarget%08x,$pTaken,$pSlot"
        manualWritePtr = (manualWritePtr + 1) % params.ftqEntries
      }

      // 4. Capture DEQUEUE (FTQ -> Backend)
      // This is the new logic to see the Backend "eating" instructions
      val deqValid = dut.io.debug_ftq_valid_out.peek().litToBoolean // You may need to expose this in Core
      val deqReady = dut.io.debug_ftq_ready_out.peek().litToBoolean 

      if (deqValid && deqReady && !flush && cycle >= resetCycles) {
        // Remove from shadow map to show "EMPTY" in CSV
        shadowFTQ.remove(manualReadPtr)
        manualReadPtr = (manualReadPtr + 1) % params.ftqEntries
      }

      // 5. Periodic Dump (Dump every cycle to see the movement)
      if (cycle >= 5 && cycle <= 80) {
        dumpToCSV(cycle)
      }

      dut.clock.step(1)
    }

    csvFile.close() 
    println(s"--- Simulation Finished. CSV generated: ftq_dump.csv ---")
    
    println("--- Final Register State ---")
    for (i <- 0 until 32) {
      val regVal = dut.io.debug_regs(i).peek().litValue
      println(f"x$i%02d: 0x$regVal%016x")
    }

    println("--- Final FP Register State ---")
    for (i <- 0 until 32) {
      val regVal = dut.io.debug_fp_regs(i).peek().litValue
      println(f"f$i%02d: 0x$regVal%016x")
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
