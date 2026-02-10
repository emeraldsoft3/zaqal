package zaqal

import chisel3._
import chiseltest._
import java.io.{File, PrintWriter}
import java.nio.file.{Files, StandardCopyOption}

object ZaqalTest extends App {
  val vcdPath = "programs/vcd"
  new File(vcdPath).mkdirs()

  RawTester.test(new Core(), Seq(WriteVcdAnnotation)) { dut =>
    println("--- Starting ZAQAL Agile V1.0 Simulation ---")
    dut.clock.setTimeout(0)
    
    // --- CSV SETUP ---
    val csvFile = new PrintWriter(new File("ftq_dump.csv"))
    csvFile.println("Cycle,Slot,BasePC,Mask,Inst0,Inst1,Inst2,Inst3,Inst4,Inst5,Inst6,Inst7,PredTarget,PredTaken,PredSlot") 
    csvFile.flush() 

    // The Shadow FTQ is our software model of the hardware warehouse
    val shadowFTQ = scala.collection.mutable.Map[Int, String]()
    var manualWritePtr = 0
    var manualReadPtr = 0 
    
    def dumpToCSV(currentCycle: Int): Unit = {
      for (slot <- 0 until 64) {
        val data = shadowFTQ.getOrElse(slot, "EMPTY,EMPTY,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,false,0")
        csvFile.println(s"$currentCycle,$slot,$data")
      }
      csvFile.flush() 
    }

    // --- MAIN SIMULATION LOOP ---
    val resetCycles = 5
    val maxCycles = 100 // Increased to see the Backend "breathing"
    
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
        val insts = (0 until 8).map(i => f"0x${dut.io.debug_ftq_insts(i).peek().litValue}%08x").mkString(",")
        val pTarget = dut.io.debug_ftq_pred_target.peek().litValue
        val pTaken  = dut.io.debug_ftq_pred_taken.peek().litToBoolean
        val pSlot   = dut.io.debug_ftq_pred_slot.peek().litValue
        
        shadowFTQ(manualWritePtr) = f"0x$pc%08x,${mask.toString(2)},$insts,0x$pTarget%08x,$pTaken,$pSlot"
        manualWritePtr = (manualWritePtr + 1) % 64
      }

      // 4. Capture DEQUEUE (FTQ -> Backend)
      // This is the new logic to see the Backend "eating" instructions
      val deqValid = dut.io.debug_ftq_valid_out.peek().litToBoolean // You may need to expose this in Core
      val deqReady = dut.io.debug_ftq_ready_out.peek().litToBoolean 

      if (deqValid && deqReady && !flush && cycle >= resetCycles) {
        // Remove from shadow map to show "EMPTY" in CSV
        shadowFTQ.remove(manualReadPtr)
        manualReadPtr = (manualReadPtr + 1) % 64
      }

      // 5. Periodic Dump (Dump every cycle to see the movement)
      if (cycle >= 5 && cycle <= 80) {
        dumpToCSV(cycle)
      }

      dut.clock.step(1)
    }

    csvFile.close() 
    println(s"--- Simulation Finished. CSV generated: ftq_dump.csv ---")
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