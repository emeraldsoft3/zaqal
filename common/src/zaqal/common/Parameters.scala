package zaqal.common

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.{Config, Field, Parameters, View}

// 1. Define the actual parameters dataset
case class ZaqalParams(
  xLen: Int = 64,
  fetchWidth: Int = 8,
  instBits: Int = 32,
  ftqEntries: Int = 64,
  ftqPtrWidth: Int = 6,
  logicalRegs: Int = 32,
  phyRegs: Int = 192, // Upgraded to XiangShan Kunminghu Parity
  hasCExtension: Boolean = true,
  hasFExtension: Boolean = true,
  fLen: Int = 64,
  decodeWidth: Int = 6,
  programFile: String = "programs/hex/program.hex",
  renameSnapshotNum: Int = 256,
  ibufSize: Int = 48,
  enableDebugPorts: Boolean = true,
  ftbEntries: Int = 64,
  
  // BPU Parameters
  rasEntries: Int = 16,
  enableBpuTage: Boolean = true,
  enableBpuIttage: Boolean = true,
  enableBpuSc: Boolean = true,
  enableBpuRas: Boolean = true,
  
  // SC Predictor Parameters
  scHistLen: Int = 8,
  scNumWeights: Int = 64,
  scWeightWidth: Int = 6,
  
  // TAGE Parameters
  tageNTables: Int = 4,
  tageCtrBits: Int = 3,
  tageUBits: Int = 2,
  tageHistoryLengths: Seq[Int] = Seq(4, 12, 36, 108),
  tageTableRows: Int = 128,
  tageTagWidth: Int = 8,
  
  // ITTAGE Parameters
  ittageNTables: Int = 4,
  ittageUBits: Int = 2,
  ittageHistoryLengths: Seq[Int] = Seq(4, 12, 36, 108),
  ittageTableRows: Int = 64,
  ittageTagWidth: Int = 8,
  
  // UOp Cache Parameters (XiangShan Parity)
  enableUOpCache: Boolean = true,
  uopCacheSets: Int = 64,
  uopCacheWays: Int = 8
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
  def hasCExtension = zP.hasCExtension
  def hasFExtension = zP.hasFExtension
  def fLen = zP.fLen
  def decodeWidth = zP.decodeWidth
  def programFile = zP.programFile
  def renameSnapshotNum = zP.renameSnapshotNum
  def ibufSize = zP.ibufSize
  def enableDebugPorts = zP.enableDebugPorts
  def ftbEntries = zP.ftbEntries
  def phyRegIdxWidth = log2Up(phyRegs)
  def predictWidth = fetchWidth * (if (hasCExtension) 2 else 1)
  
  def rasEntries = zP.rasEntries
  def enableBpuTage = zP.enableBpuTage
  def enableBpuIttage = zP.enableBpuIttage
  def enableBpuSc = zP.enableBpuSc
  def enableBpuRas = zP.enableBpuRas
  def scHistLen = zP.scHistLen
  def scNumWeights = zP.scNumWeights
  def scWeightWidth = zP.scWeightWidth
  
  def tageNTables = zP.tageNTables
  def tageCtrBits = zP.tageCtrBits
  def tageUBits = zP.tageUBits
  def tageHistoryLengths = zP.tageHistoryLengths
  def tageTableRows = zP.tageTableRows
  def tageTagWidth = zP.tageTagWidth
  
  def ittageNTables = zP.ittageNTables
  def ittageUBits = zP.ittageUBits
  def ittageHistoryLengths = zP.ittageHistoryLengths
  def ittageTableRows = zP.ittageTableRows
  def ittageTagWidth = zP.ittageTagWidth
  
  def enableUOpCache = zP.enableUOpCache
  def uopCacheSets = zP.uopCacheSets
  def uopCacheWays = zP.uopCacheWays
}

// 4. Default configuration overlay
class ZaqalConfig extends Config((site, here, up) => {
  case ZaqalParamsKey => ZaqalParams()
})
