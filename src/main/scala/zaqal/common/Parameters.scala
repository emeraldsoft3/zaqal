package zaqal.common

import chisel3._
import chisel3.util._

case class ZaqalParams(
  nFetchBytes: Int = 16,
  nFetchInstrs: Int = 4,
  nFrontendQueues: Int = 16,
  nBtbEntries: Int = 128,
  nRasEntries: Int = 16,
  nBpuEntries: Int = 512,
  nIssueQueues: Int = 16,
  nRobEntries: Int = 64,
  nPhyRegs: Int = 64,
  xLen: Int = 64
) {
  def fetchWidth = nFetchInstrs
  def ftqEntries = nFrontendQueues
}

case object ZaqalParamsKey
