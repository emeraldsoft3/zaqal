package zaqal

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
  * Complete AMBA AXI4 System-on-Chip (SoC) Top-Level for Zaqal
  *
  * Integrates:
  * 1. Zaqal 6-wide Out-of-Order RV64GCV Core
  * 2. AXI4 Burst Protocol Adapters for I-Cache & D-Cache
  * 3. AXI4 Multi-Master Interconnect / Crossbar (2 Masters x 4 Slaves)
  * 4. Slave 0: Boot ROM (Base 0x00010000)
  * 5. Slave 1: 16550 UART Serial Controller (Base 0x10000000)
  * 6. Slave 2: SPI Flash & SD Controller (Base 0x10040000)
  * 7. Slave 3: High-Throughput Burst DRAM Main Memory Controller (Base 0x80000000)
  */
class ZaqalSoCTop(val hartId: Int = 0)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val success       = Output(Bool())
    // UART Console Pins
    val uart_tx_valid = Output(Bool())
    val uart_tx_char  = Output(UInt(8.W))
    // SPI Flash / SD Card Pins
    val spi_sck       = Output(Bool())
    val spi_mosi      = Output(Bool())
    val spi_miso      = Input(Bool())
    val spi_cs_n      = Output(UInt(4.W))
    // Interrupt Inputs
    val plic_ext_irq  = Input(UInt(32.W))
  })

  // 1. Instantiate Core
  val core = Module(new Core(hartId))
  io.success := core.io.success
  core.io.plic_ext_irq := io.plic_ext_irq

  // Tie off TileLink-C ports (since AXI4 handles the system memory interconnect)
  core.io.tl_d.a.ready := true.B
  core.io.tl_d.b.valid := false.B
  core.io.tl_d.b.bits  := DontCare
  core.io.tl_d.c.ready := true.B
  core.io.tl_d.d.valid := false.B
  core.io.tl_d.d.bits  := DontCare
  core.io.tl_d.e.ready := true.B

  // 2. Bus Configurations
  val coreAxiConfig   = AXI4Config(addrWidth = 64, dataWidth = 64, idWidth = 4)
  val xbarSlaveConfig = AXI4Config(addrWidth = 64, dataWidth = 64, idWidth = 6) // extra ID bits for master index

  // 3. I-Cache & D-Cache MemoryBus to AXI4 Protocol Bridges
  val icache_bridge = Module(new MemoryBusToAXI4(
    memAddrWidth = xLen,
    memDataWidth = instBits * fetchWidth, // 256-bit cache line
    axiConfig    = coreAxiConfig
  ))
  icache_bridge.io.mem <> core.io.mem

  val dcache_bridge = Module(new MemoryBusToAXI4(
    memAddrWidth = xLen,
    memDataWidth = 256,
    axiConfig    = coreAxiConfig
  ))
  dcache_bridge.io.mem <> core.io.mem_d

  // 4. Address Map for SoC Peripherals & Memories
  val romRange  = AddressRange(base = BigInt("00000000", 16), size = BigInt("100000", 16))    // 64KB Boot ROM
  val uartRange = AddressRange(base = BigInt("10000000", 16), size = BigInt("1000", 16))     // 4KB UART
  val spiRange  = AddressRange(base = BigInt("10040000", 16), size = BigInt("10000", 16))    // 64KB SPI
  val dramRange = AddressRange(base = BigInt("80000000", 16), size = BigInt("10000000", 16)) // 256MB DRAM

  val addressMap = Seq(romRange, uartRange, spiRange, dramRange)

  // 5. Instantiate AXI4 Interconnect / Crossbar (2 Masters, 4 Slaves)
  val xbar = Module(new AXI4Xbar(
    masterConfigs = Seq(coreAxiConfig, coreAxiConfig),
    slaveConfig   = xbarSlaveConfig,
    addressMap    = addressMap
  ))
  xbar.io.masters(0) <> icache_bridge.io.axi
  xbar.io.masters(1) <> dcache_bridge.io.axi

  // 6. Slave 0: Boot ROM
  val bootrom = Module(new AXI4ROM(xbarSlaveConfig, romSizeBytes = 64 * 1024))
  bootrom.io.in <> xbar.io.slaves(0)

  // 7. Slave 1: 16550 Serial UART Console
  val uart = Module(new AXI4UART16550(xbarSlaveConfig))
  uart.io.in <> xbar.io.slaves(1)
  io.uart_tx_valid := uart.io.tx_valid || core.io.uart_tx_valid
  io.uart_tx_char  := Mux(uart.io.tx_valid, uart.io.tx_char, core.io.uart_tx_char)

  // 8. Slave 2: SPI Flash & SD Controller
  val spi = Module(new AXI4SPI(xbarSlaveConfig))
  spi.io.in <> xbar.io.slaves(2)
  io.spi_sck  := spi.io.sck
  io.spi_mosi := spi.io.mosi
  spi.io.miso := io.spi_miso
  io.spi_cs_n := spi.io.cs_n

  // 9. Slave 3: Main Memory Burst RAM Controller
  val dram = Module(new AXI4RAM(xbarSlaveConfig, memSizeBytes = 16 * 1024 * 1024))
  dram.io.in <> xbar.io.slaves(3)
}
