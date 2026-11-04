package zaqal

import zaqal.common._
import circt.stage.ChiselStage

object ElaborateSoC extends App {
  implicit val p = (new ZaqalConfig).alter((site, here, up) => {
    case ZaqalParamsKey => up(ZaqalParamsKey).copy(enableDebugPorts = false)
  })
  ChiselStage.emitSystemVerilogFile(
    new ZaqalSoCTop(),
    Array("--target-dir", "build_soc", "--split-verilog"),
    firtoolOpts = Array("--lowering-options=disallowLocalVariables")
  )
  println("[SUCCESS] ZaqalSoCTop AXI4 SoC elaborated to SystemVerilog in build_soc/")
}
