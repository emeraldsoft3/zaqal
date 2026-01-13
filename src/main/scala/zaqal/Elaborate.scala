package zaqal

import circt.stage.ChiselStage

object Elaborate extends App {
  // This generates the Verilog (.sv file) for your core
  ChiselStage.emitSystemVerilogFile(
    new ZaqalCore(),
    Array("--target-dir", "build")
  )
}