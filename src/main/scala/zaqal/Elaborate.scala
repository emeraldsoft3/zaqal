package zaqal

import chisel3._
import circt.stage.ChiselStage
import zaqal.common._

object Elaborate extends App {
  implicit val p = ZaqalParams()
  val firrtl = ChiselStage.emitCHIRRTL(new Core)
  val verilog = ChiselStage.emitSystemVerilog(new Core)
  
  // Custom emission logic if needed
  os.write.over(os.pwd / "ZaqalCore.sv", verilog)
}