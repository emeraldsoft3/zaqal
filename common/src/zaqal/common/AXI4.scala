package zaqal.common

import chisel3._
import chisel3.util._

/**
  * AMBA AXI4 Standard Constants
  */
object AXI4Parameters {
  // Burst Type Encoding (AxBURST)
  val BURST_FIXED = 0.U(2.W) // Fixed address burst (FIFO / peripherals)
  val BURST_INCR  = 1.U(2.W) // Incrementing address burst (normal memory)
  val BURST_WRAP  = 2.U(2.W) // Wrapping burst (cache line fills)

  // Response Type Encoding (xRESP)
  val RESP_OKAY   = 0.U(2.W) // Normal access success
  val RESP_EXOKAY = 1.U(2.W) // Exclusive access success
  val RESP_SLVERR = 2.U(2.W) // Slave error (device failure)
  val RESP_DECERR = 3.U(2.W) // Decode error (unmapped address)

  // Cache Allocation Encoding (AxCACHE)
  val CACHE_DEVICE_NONBUF = "b0000".U(4.W)
  val CACHE_BUFFERABLE    = "b0001".U(4.W)
  val CACHE_MODIFIABLE    = "b0010".U(4.W)
  val CACHE_LOOKUP        = "b0100".U(4.W)
  val CACHE_ALLOCATE      = "b1000".U(4.W)

  // Protection Attributes (AxPROT)
  val PROT_PRIVILEGED  = 1.U(3.W) // bit 0: 0=unprivileged, 1=privileged
  val PROT_NONSECURE   = 2.U(3.W) // bit 1: 0=secure, 1=non-secure
  val PROT_INSTRUCTION = 4.U(3.W) // bit 2: 0=data, 1=instruction
}

/**
  * AXI4 Bus Configuration Parameters
  */
case class AXI4Config(
  addrWidth: Int = 64,
  dataWidth: Int = 64,
  idWidth:   Int = 4,
  userWidth: Int = 0
) {
  require(dataWidth == 32 || dataWidth == 64 || dataWidth == 128 || dataWidth == 256 || dataWidth == 512,
    s"AXI4 dataWidth ($dataWidth) must be a power of two between 32 and 512")
  val strbWidth: Int = dataWidth / 8
  val sizeBytes: Int = log2Ceil(strbWidth) // e.g. 3 for 64-bit (8 bytes)
}

/**
  * AXI4 Address Channel Bundle (Shared by AW and AR channels)
  */
class AXI4BundleA(val config: AXI4Config) extends Bundle {
  val id    = UInt(config.idWidth.W)
  val addr  = UInt(config.addrWidth.W)
  val len   = UInt(8.W) // Number of beats minus 1 (0 = 1 beat, 7 = 8 beats)
  val size  = UInt(3.W) // Burst size: 2^size bytes per beat (e.g. 3 = 8 bytes)
  val burst = UInt(2.W) // Burst type: 0=FIXED, 1=INCR, 2=WRAP
  val lock  = Bool()
  val cache = UInt(4.W)
  val prot  = UInt(3.W)
  val qos   = UInt(4.W)
}

/**
  * AXI4 Write Data Channel Bundle (W)
  */
class AXI4BundleW(val config: AXI4Config) extends Bundle {
  val data  = UInt(config.dataWidth.W)
  val strb  = UInt(config.strbWidth.W) // Byte write strobes
  val last  = Bool()                  // Asserted on the last beat of a write burst
}

/**
  * AXI4 Write Response Channel Bundle (B)
  */
class AXI4BundleB(val config: AXI4Config) extends Bundle {
  val id    = UInt(config.idWidth.W)
  val resp  = UInt(2.W) // Write transaction status (OKAY, SLVERR, DECERR)
}

/**
  * AXI4 Read Data Channel Bundle (R)
  */
class AXI4BundleR(val config: AXI4Config) extends Bundle {
  val id    = UInt(config.idWidth.W)
  val data  = UInt(config.dataWidth.W)
  val resp  = UInt(2.W) // Read transaction status (OKAY, SLVERR, DECERR)
  val last  = Bool()    // Asserted on the last beat of a read burst
}

/**
  * Standard AMBA AXI4 Master/Slave Interface Bundle
  */
class AXI4Bundle(val config: AXI4Config) extends Bundle {
  // 1. Write Address Channel (Master -> Slave)
  val aw = Decoupled(new AXI4BundleA(config))

  // 2. Write Data Channel (Master -> Slave)
  val w  = Decoupled(new AXI4BundleW(config))

  // 3. Write Response Channel (Slave -> Master)
  val b  = Flipped(Decoupled(new AXI4BundleB(config)))

  // 4. Read Address Channel (Master -> Slave)
  val ar = Decoupled(new AXI4BundleA(config))

  // 5. Read Data Channel (Slave -> Master)
  val r  = Flipped(Decoupled(new AXI4BundleR(config)))

  /**
    * Convenience method to tie off write channels for read-only masters (e.g., I-Cache)
    */
  def tieOffWriteMaster(): Unit = {
    aw.valid := false.B
    aw.bits  := DontCare
    w.valid  := false.B
    w.bits   := DontCare
    b.ready  := true.B
  }

  /**
    * Convenience method to tie off read channels for write-only masters
    */
  def tieOffReadMaster(): Unit = {
    ar.valid := false.B
    ar.bits  := DontCare
    r.ready  := true.B
  }
}

object AXI4Bundle {
  def apply(addrWidth: Int = 64, dataWidth: Int = 64, idWidth: Int = 4): AXI4Bundle = {
    new AXI4Bundle(AXI4Config(addrWidth, dataWidth, idWidth))
  }
}
