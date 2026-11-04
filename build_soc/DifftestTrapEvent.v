
import "DPI-C" function void difftest_TrapEvent (
  input byte    coreid,
  input bit     valid,
  input byte    code,
  input longint pc,
  input longint cycle
);

module DifftestTrapEvent (
  input        clock,
  input  [7:0] coreid,
  input        valid,
  input  [7:0] code,
  input  [63:0] pc,
  input  [63:0] cycle
);
`ifndef SYNTHESIS
  always @(posedge clock) begin
    if (valid) begin
      difftest_TrapEvent(coreid, valid, code, pc, cycle);
    end
  end
`endif
endmodule
