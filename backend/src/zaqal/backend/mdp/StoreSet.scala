package zaqal.backend.mdp

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
 * Store Set Identifier Table (SSIT) Entry.
 * Direct parity with XiangShan's SSITEntry.
 */
class SSITEntry(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val valid  = Bool()
  val ssid   = UInt(ssidWidth.W)
  val strict = Bool()
}

/**
 * Store Set Identifier Table (SSIT).
 * Indexed by folded/hashed instruction PC. Maps Load and Store PCs into a shared Store Set Identifier (SSID).
 */
class SSIT(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Read ports from Decode stage
    val pc   = Vec(decodeWidth, Input(UInt(xLen.W)))
    val resp = Vec(decodeWidth, Output(new SSITEntry))

    // Update port from memory ordering violation redirect
    val update = Input(new MemPredUpdateReq)
  })

  // Fold PC bits to create index into SSIT
  def getIndex(pc: UInt): UInt = {
    val hash = pc(11, 2) ^ pc(19, 12) ^ pc(27, 20)
    hash(log2Up(ssitEntries) - 1, 0)
  }

  val valid_array  = RegInit(VecInit(Seq.fill(ssitEntries)(false.B)))
  val ssid_array   = Reg(Vec(ssitEntries, UInt(ssidWidth.W)))
  val strict_array = RegInit(VecInit(Seq.fill(ssitEntries)(false.B)))

  // Periodic table decay to prevent stale load serialization
  val resetCounter = RegInit(0.U(16.W))
  resetCounter := resetCounter + 1.U
  when(resetCounter === 0.U) {
    for (i <- 0 until ssitEntries) {
      valid_array(i) := false.B
    }
  }

  // Read ports (Decode Stage)
  for (i <- 0 until decodeWidth) {
    val idx = getIndex(io.pc(i))
    io.resp(i).valid  := valid_array(idx)
    io.resp(i).ssid   := ssid_array(idx)
    io.resp(i).strict := strict_array(idx)
  }

  // Update port on Memory Order Violation Flush (XiangShan 4-case Set Merging Algorithm)
  when(io.update.valid) {
    val ldIdx = getIndex(io.update.ldpc)
    val stIdx = getIndex(io.update.stpc)

    val ldAssigned = valid_array(ldIdx)
    val stAssigned = valid_array(stIdx)
    val ldSSID     = ssid_array(ldIdx)
    val stSSID     = ssid_array(stIdx)

    // Dynamic SSID allocation based on PC hashing
    val ldAllocSsid = io.update.ldpc(ssidWidth + 1, 2)
    val stAllocSsid = io.update.stpc(ssidWidth + 1, 2)
    val nextSsid    = Mux(ldAllocSsid < stAllocSsid, ldAllocSsid, stAllocSsid)
    val winnerSSID  = Mux(ldSSID < stSSID, ldSSID, stSSID)

    switch(Cat(ldAssigned, stAssigned)) {
      // 1. Neither assigned: Allocate a new shared Store Set ID for both
      is("b00".U(2.W)) {
        valid_array(ldIdx)  := true.B
        ssid_array(ldIdx)   := nextSsid
        strict_array(ldIdx) := false.B

        valid_array(stIdx)  := true.B
        ssid_array(stIdx)   := nextSsid
        strict_array(stIdx) := false.B
      }
      // 2. Load assigned, Store not: Add Store to Load's existing Store Set
      is("b10".U(2.W)) {
        valid_array(stIdx)  := true.B
        ssid_array(stIdx)   := ldSSID
        strict_array(stIdx) := false.B
      }
      // 3. Store assigned, Load not: Add Load to Store's existing Store Set
      is("b01".U(2.W)) {
        valid_array(ldIdx)  := true.B
        ssid_array(ldIdx)   := stSSID
        strict_array(ldIdx) := false.B
      }
      // 4. Both already assigned: Merge both sets to the winner (smaller) SSID
      is("b11".U(2.W)) {
        valid_array(ldIdx) := true.B
        ssid_array(ldIdx)  := winnerSSID

        valid_array(stIdx) := true.B
        ssid_array(stIdx)  := winnerSSID
        when(ldSSID === stSSID) {
          strict_array(ldIdx) := true.B
        }
      }
    }
  }
}

/**
 * Last Fetched Store Table (LFST) Request and Response Bundles.
 */
class LFSTReq(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val isStore = Bool()
  val ssid    = UInt(ssidWidth.W)
  val robIdx  = UInt(log2Up(128).W)
}

class LFSTResp(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val shouldWait = Bool()
  val robIdx     = UInt(log2Up(128).W)
}

/**
 * Last Fetched Store Table (LFST).
 * Direct parity with XiangShan's LFST.
 * Indexed by SSID. Tracks the ROB index of the most recently dispatched store in that store set.
 */
class LFST(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Dispatch query & allocation interface
    val req  = Vec(decodeWidth, Input(Valid(new LFSTReq)))
    val resp = Vec(decodeWidth, Output(new LFSTResp))

    // Store execution / AGU resolution event (clears the wait condition)
    val storeResolved = Input(Valid(UInt(log2Up(128).W)))

    // Pipeline Flush / Redirection handling
    val redirect = Input(new Bundle {
      val valid        = Bool()
      val is_exception = Bool()
      val robIdx       = UInt(log2Up(128).W)
    })

    val robHeadPtr = Input(UInt(log2Up(128).W))
  })

  def isYoungerInRob(idxA: UInt, idxB: UInt, head: UInt): Bool = {
    val distA = Mux(idxA >= head, idxA - head, idxA + 128.U - head)
    val distB = Mux(idxB >= head, idxB - head, idxB + 128.U - head)
    distA > distB
  }

  val validVec  = RegInit(VecInit(Seq.fill(lfstEntries)(false.B)))
  val robIdxVec = Reg(Vec(lfstEntries, UInt(log2Up(128).W)))

  // 1. Dispatch Query & Allocation (Superscalar intra-bundle dependency forwarding)
  for (i <- 0 until decodeWidth) {
    val req_i = io.req(i)
    val ssid  = req_i.bits.ssid

    // Check if an older store in the exact same dispatch bundle belongs to this SSID
    val hitInBundleVec = if (i > 0) {
      WireInit(VecInit((0 until i).map { j =>
        io.req(j).valid && io.req(j).bits.isStore && (io.req(j).bits.ssid === ssid)
      }))
    } else {
      WireInit(VecInit(Seq(false.B)))
    }
    val hitInBundle = hitInBundleVec.asUInt.orR
    val bundleStoreRobIdx = WireDefault(0.U(log2Up(128).W))
    if (i > 0) {
      for (j <- 0 until i) {
        when(hitInBundleVec(j)) {
          bundleStoreRobIdx := io.req(j).bits.robIdx
        }
      }
    }

    val entryValid = validVec(ssid)
    io.resp(i).shouldWait := req_i.valid && !req_i.bits.isStore && (entryValid || hitInBundle)
    io.resp(i).robIdx     := Mux(hitInBundle, bundleStoreRobIdx, robIdxVec(ssid))
  }

  // 2. Dispatch Store Allocation into LFST
  for (i <- 0 until decodeWidth) {
    when(io.req(i).valid && io.req(i).bits.isStore) {
      val ssid = io.req(i).bits.ssid
      validVec(ssid)  := true.B
      robIdxVec(ssid) := io.req(i).bits.robIdx
    }
  }

  // 3. Store Resolution (Invalidate LFST entry once the store finishes AGU)
  when(io.storeResolved.valid) {
    for (k <- 0 until lfstEntries) {
      when(validVec(k) && robIdxVec(k) === io.storeResolved.bits) {
        validVec(k) := false.B
      }
    }
  }

  // 4. Redirection / Pipeline Flush
  when(io.redirect.valid) {
    when(io.redirect.is_exception) {
      for (k <- 0 until lfstEntries) {
        validVec(k) := false.B
      }
    } .otherwise {
      for (k <- 0 until lfstEntries) {
        when(validVec(k) && isYoungerInRob(robIdxVec(k), io.redirect.robIdx, io.robHeadPtr)) {
          validVec(k) := false.B
        }
      }
    }
  }
}

/**
 * Top-Level Memory Dependence Predictor (MDP) with Store Sets.
 * Integrates SSIT (Decode PC -> SSID) and LFST (SSID -> in-flight Store robIdx).
 */
class StoreSet(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Decode Stage: PC probe to get SSID
    val decode_pc   = Vec(decodeWidth, Input(UInt(xLen.W)))
    val decode_ssit = Vec(decodeWidth, Output(new SSITEntry))

    // Dispatch Stage: Query & allocate in LFST
    val dispatch_req  = Vec(decodeWidth, Input(Valid(new LFSTReq)))
    val dispatch_resp = Vec(decodeWidth, Output(new LFSTResp))

    // Memory Execution / Store AGU Resolution
    val store_resolved = Input(Valid(UInt(log2Up(128).W)))

    // Redirection / Pipeline Flush
    val redirect = Input(new Bundle {
      val valid        = Bool()
      val is_exception = Bool()
      val robIdx       = UInt(log2Up(128).W)
    })

    val robHeadPtr = Input(UInt(log2Up(128).W))

    // Training on Memory Ordering Violation
    val update = Input(new MemPredUpdateReq)
  })

  val ssit = Module(new SSIT)
  val lfst = Module(new LFST)

  // SSIT Connections
  ssit.io.pc     := io.decode_pc
  io.decode_ssit := ssit.io.resp
  ssit.io.update := io.update

  // LFST Connections
  lfst.io.req           := io.dispatch_req
  io.dispatch_resp      := lfst.io.resp
  lfst.io.storeResolved := io.store_resolved
  lfst.io.redirect      := io.redirect
  lfst.io.robHeadPtr    := io.robHeadPtr
}
