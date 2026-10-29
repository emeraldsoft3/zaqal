package zaqal.backend.rob

import chisel3._
import chisel3.util._
import chisel3.util.HasBlackBoxInline
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

// -------------------------------------------------------------
// 1. Commit Event DPI-C BlackBox
// -------------------------------------------------------------
class DifftestInstrCommit extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clock   = Input(Clock())
    val coreid  = Input(UInt(8.W))
    val index   = Input(UInt(8.W))
    val valid   = Input(Bool())
    val pc      = Input(UInt(64.W))
    val instr   = Input(UInt(32.W))
    val skip    = Input(Bool())
    val isRVC   = Input(Bool())
    val rfwen   = Input(Bool())
    val fpwen   = Input(Bool())
    val vecwen  = Input(Bool())
    val wdest   = Input(UInt(8.W))
    val data    = Input(UInt(64.W))
  })

  setInline("DifftestInstrCommit.v",
    s"""
       |import "DPI-C" function void difftest_InstrCommit (
       |  input byte    coreid,
       |  input byte    index,
       |  input bit     valid,
       |  input longint pc,
       |  input int     instr,
       |  input bit     skip,
       |  input bit     isRVC,
       |  input bit     rfwen,
       |  input bit     fpwen,
       |  input bit     vecwen,
       |  input byte    wdest,
       |  input longint data
       |);
       |
       |module DifftestInstrCommit (
       |  input        clock,
       |  input  [7:0] coreid,
       |  input  [7:0] index,
       |  input        valid,
       |  input  [63:0] pc,
       |  input  [31:0] instr,
       |  input        skip,
       |  input        isRVC,
       |  input        rfwen,
       |  input        fpwen,
       |  input        vecwen,
       |  input  [7:0] wdest,
       |  input  [63:0] data
       |);
       |`ifndef SYNTHESIS
       |  always @(posedge clock) begin
       |    if (valid) begin
       |      difftest_InstrCommit(coreid, index, valid, pc, instr, skip, isRVC, rfwen, fpwen, vecwen, wdest, data);
       |    end
       |  end
       |`endif
       |endmodule
       |""".stripMargin
  )
}

// -------------------------------------------------------------
// 2. Trap / Exception Event DPI-C BlackBox
// -------------------------------------------------------------
class DifftestTrapEvent extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clock  = Input(Clock())
    val coreid = Input(UInt(8.W))
    val valid  = Input(Bool())
    val code   = Input(UInt(8.W))
    val pc     = Input(UInt(64.W))
    val cycle  = Input(UInt(64.W))
  })

  setInline("DifftestTrapEvent.v",
    s"""
       |import "DPI-C" function void difftest_TrapEvent (
       |  input byte    coreid,
       |  input bit     valid,
       |  input byte    code,
       |  input longint pc,
       |  input longint cycle
       |);
       |
       |module DifftestTrapEvent (
       |  input        clock,
       |  input  [7:0] coreid,
       |  input        valid,
       |  input  [7:0] code,
       |  input  [63:0] pc,
       |  input  [63:0] cycle
       |);
       |`ifndef SYNTHESIS
       |  always @(posedge clock) begin
       |    if (valid) begin
       |      difftest_TrapEvent(coreid, valid, code, pc, cycle);
       |    end
       |  end
       |`endif
       |endmodule
       |""".stripMargin
  )
}

// -------------------------------------------------------------
// 3. CSR Architectural State DPI-C BlackBox
// -------------------------------------------------------------
class DifftestCSRState extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clock   = Input(Clock())
    val coreid  = Input(UInt(8.W))
    val valid   = Input(Bool())
    val mstatus = Input(UInt(64.W))
    val mie     = Input(UInt(64.W))
    val mip     = Input(UInt(64.W))
    val mepc    = Input(UInt(64.W))
    val mcause  = Input(UInt(64.W))
    val mtvec   = Input(UInt(64.W))
    val satp    = Input(UInt(64.W))
  })

  setInline("DifftestCSRState.v",
    s"""
       |import "DPI-C" function void difftest_CSRState (
       |  input byte    coreid,
       |  input bit     valid,
       |  input longint mstatus,
       |  input longint mie,
       |  input longint mip,
       |  input longint mepc,
       |  input longint mcause,
       |  input longint mtvec,
       |  input longint satp
       |);
       |
       |module DifftestCSRState (
       |  input        clock,
       |  input  [7:0] coreid,
       |  input        valid,
       |  input  [63:0] mstatus,
       |  input  [63:0] mie,
       |  input  [63:0] mip,
       |  input  [63:0] mepc,
       |  input  [63:0] mcause,
       |  input  [63:0] mtvec,
       |  input  [63:0] satp
       |);
       |`ifndef SYNTHESIS
       |  always @(posedge clock) begin
       |    if (valid) begin
       |      difftest_CSRState(coreid, valid, mstatus, mie, mip, mepc, mcause, mtvec, satp);
       |    end
       |  end
       |`endif
       |endmodule
       |""".stripMargin
  )
}

// -------------------------------------------------------------
// 4. Architectural Register File (ARF) Snapshot BlackBox
// -------------------------------------------------------------
class DifftestArchRegs extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clock   = Input(Clock())
    val coreid  = Input(UInt(8.W))
    val valid   = Input(Bool())
    val gpr_0   = Input(UInt(64.W))
    val gpr_1   = Input(UInt(64.W))
    val gpr_2   = Input(UInt(64.W))
    val gpr_3   = Input(UInt(64.W))
    val gpr_4   = Input(UInt(64.W))
    val gpr_5   = Input(UInt(64.W))
    val gpr_6   = Input(UInt(64.W))
    val gpr_7   = Input(UInt(64.W))
    val gpr_8   = Input(UInt(64.W))
    val gpr_9   = Input(UInt(64.W))
    val gpr_10  = Input(UInt(64.W))
    val gpr_11  = Input(UInt(64.W))
    val gpr_12  = Input(UInt(64.W))
    val gpr_13  = Input(UInt(64.W))
    val gpr_14  = Input(UInt(64.W))
    val gpr_15  = Input(UInt(64.W))
    val gpr_16  = Input(UInt(64.W))
    val gpr_17  = Input(UInt(64.W))
    val gpr_18  = Input(UInt(64.W))
    val gpr_19  = Input(UInt(64.W))
    val gpr_20  = Input(UInt(64.W))
    val gpr_21  = Input(UInt(64.W))
    val gpr_22  = Input(UInt(64.W))
    val gpr_23  = Input(UInt(64.W))
    val gpr_24  = Input(UInt(64.W))
    val gpr_25  = Input(UInt(64.W))
    val gpr_26  = Input(UInt(64.W))
    val gpr_27  = Input(UInt(64.W))
    val gpr_28  = Input(UInt(64.W))
    val gpr_29  = Input(UInt(64.W))
    val gpr_30  = Input(UInt(64.W))
    val gpr_31  = Input(UInt(64.W))
  })

  val portDecls = (0 until 32).map(r => s"  input  [63:0] gpr_$r").mkString(",\n")
  val dpiArgs   = (0 until 32).map(r => s"  input longint gpr_$r").mkString(",\n")
  val callArgs  = (0 until 32).map(r => s"gpr_$r").mkString(", ")

  setInline("DifftestArchRegs.v",
    s"""
       |import "DPI-C" function void difftest_ArchRegs (
       |  input byte    coreid,
       |  input bit     valid,
       |$dpiArgs
       |);
       |
       |module DifftestArchRegs (
       |  input        clock,
       |  input  [7:0] coreid,
       |  input        valid,
       |$portDecls
       |);
       |`ifndef SYNTHESIS
       |  always @(posedge clock) begin
       |    if (valid) begin
       |      difftest_ArchRegs(coreid, valid, $callArgs);
       |    end
       |  end
       |`endif
       |endmodule
       |""".stripMargin
  )
}
