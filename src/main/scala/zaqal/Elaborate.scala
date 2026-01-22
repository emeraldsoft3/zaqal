package zaqal

import circt.stage.ChiselStage

object Elaborate extends App {
  // This generates the Verilog (.sv file) for your core
  ChiselStage.emitSystemVerilogFile(
    new Core(),
    Array("--target-dir", "build")
  )
}