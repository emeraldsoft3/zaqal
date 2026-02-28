package zaqal.backend

import chisel3._
import chisel3.util._
import zaqal._

class Execute extends Module {
  val io = IO(new Bundle {
    val in       = Flipped(Decoupled(new MicroOp))
    val redirect = Output(new BPURedirect)
  })

  // Kunminghu Alignment: Main Decoder is in the Backend
  val decoder = Module(new Decoder)
  val regFile = Module(new RegFile)

  decoder.io.inst := io.in.bits.inst_raw

  // Wire up both source registers (combinational reads)
  regFile.io.rs1_addr := decoder.io.out.rs1
  regFile.io.rs2_addr := decoder.io.out.rs2
  regFile.io.wen      := false.B
  regFile.io.rd_addr  := decoder.io.out.rd
  regFile.io.rd_data  := 0.U

  val rs1_data = regFile.io.rs1_data
  val rs2_data = regFile.io.rs2_data
  val imm      = decoder.io.out.imm.asUInt

  // Default redirection (last assignment wins)
  io.redirect.valid  := false.B
  io.redirect.target := 0.U

  // -----------------------------------------------------------------------
  // Division stall state machine
  //
  //  s_idle ──(is_div fires)──► s_busy ──(31 more cycles)──► s_done ──► s_idle
  //  ready=1                    ready=0                       ready=0
  //                                                            writes result
  // -----------------------------------------------------------------------
  val s_idle :: s_busy :: s_done :: Nil = Enum(3)
  val divState = RegInit(s_idle)

  val DIV_LATENCY = 32          // architectural latency (cycles)
  val divCounter  = RegInit(0.U(6.W))

  // Everything latched on the cycle the DIV fires
  val div_rs1    = RegInit(0.U(64.W))
  val div_rs2    = RegInit(0.U(64.W))
  val div_rd     = RegInit(0.U(5.W))
  val div_pc     = RegInit(0.U(64.W))
  // Result is REGISTERED at the s_busy→s_done transition — avoids FIRRTL
  // width-inference surprises with inline SInt division expressions.
  val div_result = RegInit(0.U(64.W))

  // Stall the pipeline (deassert ready) while the divider is working
  io.in.ready := (divState === s_idle)

  // -----------------------------------------------------------------------
  // Normal (non-div) instructions — only fire in s_idle
  // -----------------------------------------------------------------------
  when(io.in.fire) {
    val rd = decoder.io.out.rd

    // ADDI: rd = rs1 + imm
    when(decoder.io.out.is_addi) {
      val res = rs1_data + imm
      when(rd =/= 0.U) {
        regFile.io.wen     := true.B
        regFile.io.rd_data := res
        printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} ADDI x$rd = x${decoder.io.out.rs1}($rs1_data) + ${decoder.io.out.imm} | Result: $res\n")
      }
    }

    // ADD: rd = rs1 + rs2
    .elsewhen(decoder.io.out.is_add) {
      val res = rs1_data + rs2_data
      when(rd =/= 0.U) {
        regFile.io.wen     := true.B
        regFile.io.rd_data := res
        printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} ADD  x$rd = x${decoder.io.out.rs1}($rs1_data) + x${decoder.io.out.rs2}($rs2_data) | Result: $res\n")
      }
    }

    // MUL: rd = rs1 * rs2  (lower 64 bits)
    .elsewhen(decoder.io.out.is_mul) {
      val res = rs1_data * rs2_data
      when(rd =/= 0.U) {
        regFile.io.wen     := true.B
        regFile.io.rd_data := res
        printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} MUL  x$rd = x${decoder.io.out.rs1}($rs1_data) * x${decoder.io.out.rs2}($rs2_data) | Result: $res\n")
      }
    }

    // DIV: latch operands and kick off the stall machine
    .elsewhen(decoder.io.out.is_div) {
      div_rs1    := rs1_data
      div_rs2    := rs2_data
      div_rd     := rd
      div_pc     := io.in.bits.pc
      divCounter := 0.U
      divState   := s_busy
    }

    // Default: Check for Ghost Jumps (BPU jumped, but this isn't a branch)
    when(io.in.fire && io.in.bits.is_predicted_taken && !decoder.io.out.is_branch) {
      io.redirect.valid := true.B
      io.redirect.target := io.in.bits.pc + 4.U
      printf(p"CORE EXECUTE: GHOST JUMP MISPREDICT! pc=${Hexadecimal(io.in.bits.pc)} (Not a branch) -> Redirecting to ${Hexadecimal(io.redirect.target)}\n")
    }

    // BNE: if rs1 != rs2, redirect to pc + imm
    .elsewhen(decoder.io.out.is_bne) {
      val taken = rs1_data =/= rs2_data
      val predicted_taken = io.in.bits.is_predicted_taken
      
      val target_pc = (io.in.bits.pc.asSInt + decoder.io.out.imm).asUInt
      val fallthrough_pc = io.in.bits.pc + 4.U

      when(taken =/= predicted_taken) {
        io.redirect.valid := true.B
        io.redirect.target := Mux(taken, target_pc, fallthrough_pc)
        printf(p"CORE EXECUTE: MISPREDICT! pc=${Hexadecimal(io.in.bits.pc)} BNE taken=$taken pred=$predicted_taken -> Redirecting to ${Hexadecimal(io.redirect.target)}\n")
      } .otherwise {
        printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} BNE taken=$taken pred=$predicted_taken (Correct)\n")
      }
    }

    .elsewhen(decoder.io.out.is_blt) {
      val taken = rs1_data.asSInt < rs2_data.asSInt
      val predicted_taken = io.in.bits.is_predicted_taken

      val target_pc = (io.in.bits.pc.asSInt + decoder.io.out.imm).asUInt
      val fallthrough_pc = io.in.bits.pc + 4.U

      when(taken =/= predicted_taken) {
        io.redirect.valid := true.B
        io.redirect.target := Mux(taken, target_pc, fallthrough_pc)
        printf(p"CORE EXECUTE: MISPREDICT! pc=${Hexadecimal(io.in.bits.pc)} BLT taken=$taken pred=$predicted_taken -> Redirecting to ${Hexadecimal(io.redirect.target)}\n")
      } .otherwise {
        printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} BLT taken=$taken pred=$predicted_taken (Correct)\n")
      }
    }
  }


  // -----------------------------------------------------------------------
  // Division stall FSM — runs every cycle independently of io.in.fire
  // -----------------------------------------------------------------------
  switch(divState) {

    is(s_busy) {
      divCounter := divCounter + 1.U
      // On the last busy cycle: compute + register the result, then move on.
      // We guard div_rs2 = 0 per RISC-V spec (result is -1 for signed divBy0).
      when(divCounter === (DIV_LATENCY - 1).U) {
        val safe_rs2 = Mux(div_rs2 === 0.U, 1.U(64.W), div_rs2)
        div_result := (div_rs1.asSInt / safe_rs2.asSInt).asUInt
        divState   := s_done
      }
    }

    is(s_done) {
      // Write the registered result back to the register file
      when(div_rd =/= 0.U) {
        regFile.io.wen     := true.B
        regFile.io.rd_addr := div_rd
        regFile.io.rd_data := div_result
        printf(p"CORE EXECUTE: pc=${Hexadecimal(div_pc)} DIV  x${div_rd} = x${div_rs1}(${div_rs1}) / x${div_rs2}(${div_rs2}) | Result: ${div_result} (after 32-cycle stall)\n")
      }
      divState := s_idle
    }
  }
}