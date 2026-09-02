import chisel3._
import chisel3.simulator.EphemeralSimulator._
import zaqal.frontend._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal._

object TestFetch extends App {
  implicit val p = (new ZaqalConfig).alter((site, here, up) => {
    case ZaqalParamsKey => up(ZaqalParamsKey)
  })

  simulate(new IFU) { dut =>
    val raw_bits = BigInt("00008067" + "02210a63" + "00200113" + "00000000000000000000000000000000000000000000000000000000000000000000000000000000", 16)
    
    dut.io.insts_in.zipWithIndex.foreach { case (port, i) =>
      val chunk = (raw_bits >> (i * 32)) & BigInt("FFFFFFFF", 16)
      port.poke(chunk.U)
    }
    
    dut.io.icache_ready.poke(true.B)
    dut.io.fetch_req.valid.poke(true.B)
    dut.io.fetch_req.bits.pc.poke("h28".U)
    dut.io.fetch_req.bits.mask.poke("hFFFF".U) // BPU next_mask is all 1s
    
    dut.clock.step(1)
    
    println(s"Packet Mask: ${dut.io.toIbuffer.bits.mask.peek().litValue.toString(2)}")
    for (i <- 0 until 6) {
      val inst = dut.io.toIbuffer.bits.instructions(i).peek().litValue
      val rvc = dut.io.toIbuffer.bits.pre_decoded(i).is_rvc.peek().litValue
      println(s"Slot $i: inst=${inst.toString(16)} rvc=$rvc")
    }
  }
}
