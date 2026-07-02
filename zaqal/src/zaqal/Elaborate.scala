package zaqal

import zaqal.common._

import circt.stage.ChiselStage

object Elaborate extends App {
  implicit val p = (new ZaqalConfig).alter((site, here, up) => {
    case ZaqalParamsKey => up(ZaqalParamsKey).copy(enableDebugPorts = false)
  })
  ChiselStage.emitSystemVerilogFile(
    new Core(),
    Array("--target-dir", "build", "--split-verilog"),
    firtoolOpts = Array("--lowering-options=disallowLocalVariables,disallowPackedArrays")
  )
}