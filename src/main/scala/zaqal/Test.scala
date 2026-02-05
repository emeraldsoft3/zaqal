package zaqal

import chisel3._
import chiseltest._
import chiseltest.experimental.expose // Crucial for peeking inside
import java.io.{File, PrintWriter}
import java.nio.file.{Files, StandardCopyOption}

object ZaqalTest extends App {
  val vcdPath = "programs/vcd"
  new File(vcdPath).mkdirs()

  // We wrap the Core and expose the FTQ signals we need
  RawTester.test(new Core(), Seq(WriteVcdAnnotation)) { dut =>
    println("--- Starting ZAQAL Agile V1.0 Simulation ---")
    dut.clock.setTimeout(0)
    
    // --- CSV SETUP ---
    val csvFile = new PrintWriter(new File("ftq_dump.csv"))
    csvFile.println("SnapshotCycle,SlotIndex,BasePC,Mask,Inst0_Hex,Inst1_Hex,Inst2_Hex,Inst3_Hex,Inst4_Hex,Inst5_Hex,Inst6_Hex,Inst7_Hex,PredTarget,PredTaken,PredSlot") 
    csvFile.flush() 

    val shadowFTQ = scala.collection.mutable.Map[Int, String]()
    var manualWritePtr = 0
    
    // Reset Sequence
    dut.reset.poke(true.B)
    dut.clock.step(5)
    dut.reset.poke(false.B)

    def dumpToCSV(currentCycle: Int): Unit = {
      for (slot <- 0 until 64) {
        val data = shadowFTQ.getOrElse(slot, "EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY")
        csvFile.println(s"$currentCycle,$slot,$data")
      }
      csvFile.flush() // Force write to disk so you can see it immediately
    }

    // --- MAIN SIMULATION LOOP ---
    val maxCycles = 60
    for (cycle <- 0 until maxCycles) {
      val flush = dut.io.debug_ftq_flush.peek().litToBoolean

      // Handle Flush: If flushed, we must clear our shadow copy to match hardware
      if (flush) {
        shadowFTQ.clear()
        manualWritePtr = 0
        println(s"[Cycle $cycle] FTQ Flushed! Shadow copy cleared.")
      }

      // Capture Enqueue (Write)
      val isValid = dut.io.debug_ftq_valid.peek().litToBoolean
      val isReady = dut.io.debug_ftq_ready.peek().litToBoolean

      if (isValid && isReady && !flush) {
        val pc    = dut.io.debug_ftq_pc.peek().litValue
        val mask  = dut.io.debug_ftq_mask.peek().litValue
        val insts = (0 until 8).map(i => f"0x${dut.io.debug_ftq_insts(i).peek().litValue}%08x").mkString(",")
        val pTarget = dut.io.debug_ftq_pred_target.peek().litValue
        val pTaken  = dut.io.debug_ftq_pred_taken.peek().litToBoolean
        val pSlot   = dut.io.debug_ftq_pred_slot.peek().litValue
        
        shadowFTQ(manualWritePtr) = f"0x$pc%08x,${mask.toString(2)},$insts,0x$pTarget%08x,$pTaken,$pSlot"
        manualWritePtr = (manualWritePtr + 1) % 64
      }

      // Dump to CSV specifically from cycle 4 to 50 inclusive
      if (cycle >= 4 && cycle <= 50) {
        dumpToCSV(cycle)
        println(s"Captured FTQ Snapshot to CSV at cycle $cycle")
      }

      dut.clock.step(1)
    }

    csvFile.close() 
    println(s"--- Simulation Finished. CSV generated: ftq_dump.csv ---")
  }

  // VCD Copying Logic...
  val targetVcd = new File("programs/vcd/Lithium.vcd")
  val testRunDir = new File("test_run_dir")
  if (testRunDir.exists()) {
    val vcdFiles = testRunDir.listFiles().filter(_.isDirectory).flatMap(_.listFiles()).filter(_.getName.endsWith(".vcd"))
    if (vcdFiles.nonEmpty) {
      Files.copy(vcdFiles.sortBy(_.lastModified()).last.toPath, targetVcd.toPath, StandardCopyOption.REPLACE_EXISTING)
    }
  }
}