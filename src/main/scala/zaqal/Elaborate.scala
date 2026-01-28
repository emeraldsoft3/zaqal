package zaqal

import circt.stage.ChiselStage

object Elaborate extends App {
  ChiselStage.emitSystemVerilogFile(
    new Core(),
    Array("--target-dir", "build"),
    // Add this line to split files by module
    Array("--split-verilog") 
  )
}