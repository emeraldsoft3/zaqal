
import "DPI-C" function void difftest_InstrCommit (
  input byte    coreid,
  input byte    index,
  input bit     valid,
  input longint pc,
  input int     instr,
  input bit     skip,
  input bit     isRVC,
  input bit     rfwen,
  input bit     fpwen,
  input bit     vecwen,
  input byte    wdest,
  input longint data
);

module DifftestInstrCommit (
  input        clock,
  input  [7:0] coreid,
  input  [7:0] index,
  input        valid,
  input  [63:0] pc,
  input  [31:0] instr,
  input        skip,
  input        isRVC,
  input        rfwen,
  input        fpwen,
  input        vecwen,
  input  [7:0] wdest,
  input  [63:0] data
);
`ifndef SYNTHESIS
  always @(posedge clock) begin
    if (valid) begin
      difftest_InstrCommit(coreid, index, valid, pc, instr, skip, isRVC, rfwen, fpwen, vecwen, wdest, data);
    end
  end
`endif
endmodule
