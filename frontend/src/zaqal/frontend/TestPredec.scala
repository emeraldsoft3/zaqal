import chisel3._
import chisel3.simulator.EphemeralSimulator._
import zaqal.frontend._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

object TestPredec extends App {
  implicit val p = (new ZaqalConfig).alter((site, here, up) => {
    case ZaqalParamsKey => up(ZaqalParamsKey)
  })

  simulate(new Predecoder) { dut =>
    dut.io.inst.poke("h00008067".U)
    println(s"is_call: ${dut.io.out.is_call.peek().litValue}")
    println(s"is_ret: ${dut.io.out.is_ret.peek().litValue}")
  }
}
