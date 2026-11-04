package zaqal.common

import chisel3._
import chisel3.util._

/**
  * Address Range Descriptor for AXI4 Memory Mapping
  */
case class AddressRange(base: BigInt, size: BigInt) {
  val mask: BigInt = size - 1
  def contains(addr: UInt): Bool = {
    (addr >= base.U(64.W)) && (addr < (base + size).U(64.W))
  }
}

/**
  * Fully-Pipelined AMBA AXI4 Crossbar (M Masters to N Slaves)
  *
  * Features:
  * - Arbitrated non-blocking read and write channels.
  * - Dynamic address decoding per master request.
  * - Automatic transaction routing back to requesting master via ID tagging.
  * - Default error responder for unmapped address accesses (DECERR).
  */
class AXI4Xbar(
  val masterConfigs: Seq[AXI4Config],
  val slaveConfig:   AXI4Config,
  val addressMap:    Seq[AddressRange]
) extends Module {
  val numMasters = masterConfigs.length
  val numSlaves  = addressMap.length

  // Ensure slave ID width has enough bits to include master index
  val masterIdBits = log2Ceil(numMasters)
  require(slaveConfig.idWidth >= masterConfigs.map(_.idWidth).max + masterIdBits,
    s"Slave idWidth (${slaveConfig.idWidth}) must be at least max master idWidth + masterIdBits")

  val io = IO(new Bundle {
    val masters = Vec(numMasters, Flipped(new AXI4Bundle(masterConfigs.head)))
    val slaves  = Vec(numSlaves, new AXI4Bundle(slaveConfig))
  })

  // =========================================================================
  // 1. READ ADDRESS (AR) ARBITRATION & ROUTING
  // =========================================================================
  val ar_arbiter = Module(new RRArbiter(new AXI4BundleA(slaveConfig), numMasters))

  val idPadBits = slaveConfig.idWidth - masterIdBits
  for (m <- 0 until numMasters) {
    ar_arbiter.io.in(m).valid := io.masters(m).ar.valid
    io.masters(m).ar.ready    := ar_arbiter.io.in(m).ready

    val orig_id = io.masters(m).ar.bits.id.asUInt
    val padded_id = if (orig_id.getWidth < idPadBits) orig_id.pad(idPadBits) else orig_id(idPadBits - 1, 0)
    val tagged_id = Cat(m.U(masterIdBits.W), padded_id)

    ar_arbiter.io.in(m).bits       := io.masters(m).ar.bits
    ar_arbiter.io.in(m).bits.id    := tagged_id
  }

  val chosen_ar = ar_arbiter.io.out
  val ar_slave_matches = VecInit(addressMap.map(_.contains(chosen_ar.bits.addr)))
  val ar_has_match     = ar_slave_matches.asUInt.orR
  val ar_slave_idx     = PriorityEncoder(ar_slave_matches)

  // Route AR to matched slave
  for (s <- 0 until numSlaves) {
    io.slaves(s).ar.valid := chosen_ar.valid && (ar_slave_idx === s.U) && ar_has_match
    io.slaves(s).ar.bits  := chosen_ar.bits
  }
  chosen_ar.ready := Mux(ar_has_match, io.slaves(ar_slave_idx).ar.ready, true.B)

  // =========================================================================
  // 2. READ DATA (R) ROUTING BACK TO MASTERS
  // =========================================================================
  val r_arbiter = Module(new RRArbiter(new AXI4BundleR(slaveConfig), numSlaves))
  for (s <- 0 until numSlaves) {
    r_arbiter.io.in(s).valid := io.slaves(s).r.valid
    r_arbiter.io.in(s).bits  := io.slaves(s).r.bits
    io.slaves(s).r.ready     := r_arbiter.io.in(s).ready
  }

  val chosen_r = r_arbiter.io.out
  val r_target_master = if (numMasters > 1) {
    chosen_r.bits.id(slaveConfig.idWidth - 1, slaveConfig.idWidth - masterIdBits)
  } else 0.U

  for (m <- 0 until numMasters) {
    val is_this_master = (r_target_master === m.U)
    io.masters(m).r.valid     := chosen_r.valid && is_this_master
    io.masters(m).r.bits.id   := chosen_r.bits.id(masterConfigs(m).idWidth - 1, 0)
    io.masters(m).r.bits.data := chosen_r.bits.data
    io.masters(m).r.bits.resp := chosen_r.bits.resp
    io.masters(m).r.bits.last := chosen_r.bits.last
  }
  chosen_r.ready := Mux1H((0 until numMasters).map(m => (r_target_master === m.U) -> io.masters(m).r.ready))

  // =========================================================================
  // 3. WRITE ADDRESS (AW) ARBITRATION & ROUTING
  // =========================================================================
  val aw_arbiter = Module(new RRArbiter(new AXI4BundleA(slaveConfig), numMasters))

  for (m <- 0 until numMasters) {
    aw_arbiter.io.in(m).valid := io.masters(m).aw.valid
    io.masters(m).aw.ready    := aw_arbiter.io.in(m).ready

    val orig_id = io.masters(m).aw.bits.id.asUInt
    val padded_id = if (orig_id.getWidth < idPadBits) orig_id.pad(idPadBits) else orig_id(idPadBits - 1, 0)
    val tagged_id = Cat(m.U(masterIdBits.W), padded_id)

    aw_arbiter.io.in(m).bits       := io.masters(m).aw.bits
    aw_arbiter.io.in(m).bits.id    := tagged_id
  }

  val chosen_aw = aw_arbiter.io.out
  val aw_slave_matches = VecInit(addressMap.map(_.contains(chosen_aw.bits.addr)))
  val aw_has_match     = aw_slave_matches.asUInt.orR
  val aw_slave_idx     = PriorityEncoder(aw_slave_matches)

  // Track active write target slave across multi-beat bursts
  val in_write_burst = RegInit(false.B)
  val active_w_slave = RegInit(0.U(log2Up(numSlaves).W))
  val active_w_master = RegInit(0.U(log2Up(numMasters).W))

  when(chosen_aw.fire) {
    in_write_burst  := true.B
    active_w_slave  := aw_slave_idx
    active_w_master := aw_arbiter.io.chosen
  }

  for (s <- 0 until numSlaves) {
    io.slaves(s).aw.valid := chosen_aw.valid && (aw_slave_idx === s.U) && aw_has_match && !in_write_burst
    io.slaves(s).aw.bits  := chosen_aw.bits
  }
  chosen_aw.ready := Mux(aw_has_match && !in_write_burst, io.slaves(aw_slave_idx).aw.ready, false.B)

  // =========================================================================
  // 4. WRITE DATA (W) ROUTING
  // =========================================================================
  val curr_w_master = Mux(in_write_burst, active_w_master, aw_arbiter.io.chosen)
  val curr_w_slave  = Mux(in_write_burst, active_w_slave, aw_slave_idx)

  for (s <- 0 until numSlaves) {
    val is_this_slave = (curr_w_slave === s.U) && (in_write_burst || (chosen_aw.valid && aw_has_match))
    io.slaves(s).w.valid := io.masters(curr_w_master).w.valid && is_this_slave
    io.slaves(s).w.bits  := io.masters(curr_w_master).w.bits
  }

  for (m <- 0 until numMasters) {
    val is_active = (m.U === curr_w_master)
    io.masters(m).w.ready := is_active && (in_write_burst || (chosen_aw.valid && aw_has_match)) && io.slaves(curr_w_slave).w.ready
  }

  when(io.slaves(curr_w_slave).w.fire && io.slaves(curr_w_slave).w.bits.last) {
    in_write_burst := false.B
  }

  // =========================================================================
  // 5. WRITE RESPONSE (B) ROUTING BACK TO MASTERS
  // =========================================================================
  val b_arbiter = Module(new RRArbiter(new AXI4BundleB(slaveConfig), numSlaves))
  for (s <- 0 until numSlaves) {
    b_arbiter.io.in(s).valid := io.slaves(s).b.valid
    b_arbiter.io.in(s).bits  := io.slaves(s).b.bits
    io.slaves(s).b.ready     := b_arbiter.io.in(s).ready
  }

  val chosen_b = b_arbiter.io.out
  val b_target_master = if (numMasters > 1) {
    chosen_b.bits.id(slaveConfig.idWidth - 1, slaveConfig.idWidth - masterIdBits)
  } else 0.U

  for (m <- 0 until numMasters) {
    val is_this_master = (b_target_master === m.U)
    io.masters(m).b.valid     := chosen_b.valid && is_this_master
    io.masters(m).b.bits.id   := chosen_b.bits.id(masterConfigs(m).idWidth - 1, 0)
    io.masters(m).b.bits.resp := chosen_b.bits.resp
  }
  chosen_b.ready := Mux1H((0 until numMasters).map(m => (b_target_master === m.U) -> io.masters(m).b.ready))
}
