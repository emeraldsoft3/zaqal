package zaqal

import chisel3._
import org.chipsalliance.cde.config.{Config, Field, Parameters}

// 1. Define the actual parameters dataset
case class ZaqalParams(
  xLen: Int = 64,
  fetchWidth: Int = 8,
  instBits: Int = 32,
  ftqEntries: Int = 64,
  ftqPtrWidth: Int = 6,
  logicalRegs: Int = 32,
  phyRegs: Int = 64
)

// 2. Define the Field Key that CDE uses to locate ZaqalParams
case object ZaqalParamsKey extends Field[ZaqalParams]()

// 3. Define the Trait that provides implicit access shortcuts for modules
trait HasZaqalParameter {
  implicit val p: Parameters

  def zP = p(ZaqalParamsKey)

  def xLen = zP.xLen
  def fetchWidth = zP.fetchWidth
  def instBits = zP.instBits
  def ftqEntries = zP.ftqEntries
  def ftqPtrWidth = zP.ftqPtrWidth
  def logicalRegs = zP.logicalRegs
  def phyRegs = zP.phyRegs
}

// 4. Default configuration overlay
class ZaqalConfig extends Config((site, here, up) => {
  case ZaqalParamsKey => ZaqalParams()
})
