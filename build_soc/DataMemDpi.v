
import "DPI-C" function longint ram_read_dword (input longint addr);
import "DPI-C" function void ram_write_byte (input longint addr, input byte data);

module DataMemDpi (
  input             clock,
  input      [63:0] raddr0,
  output reg [63:0] rdata0_lo,
  output reg [63:0] rdata0_hi,
  input      [63:0] raddr1,
  output reg [63:0] rdata1_lo,
  output reg [63:0] rdata1_hi,
  input      [63:0] ptw_raddr,
  output reg [63:0] ptw_rdata,
  input      [63:0] waddr,
  output reg [63:0] wdata_lo,
  output reg [63:0] wdata_hi,
  input             wen,
  input      [63:0] store_addr,
  input      [63:0] store_wdata_lo,
  input      [63:0] store_wdata_hi,
  input      [15:0] store_wmask
);

`ifndef SYNTHESIS
  always @* begin
    rdata0_lo = ram_read_dword(raddr0 & 64'hfffffffffffffff8);
    rdata0_hi = ram_read_dword((raddr0 & 64'hfffffffffffffff8) + 64'd8);
    rdata1_lo = ram_read_dword(raddr1 & 64'hfffffffffffffff8);
    rdata1_hi = ram_read_dword((raddr1 & 64'hfffffffffffffff8) + 64'd8);
    ptw_rdata = ram_read_dword(ptw_raddr & 64'hfffffffffffffff8);
    wdata_lo  = ram_read_dword(waddr & 64'hfffffffffffffff8);
    wdata_hi  = ram_read_dword((waddr & 64'hfffffffffffffff8) + 64'd8);
  end

  always @(posedge clock) begin
    if (wen) begin
      for (int i = 0; i < 8; i = i + 1) begin
        if (store_wmask[i]) begin
          ram_write_byte((store_addr & 64'hfffffffffffffff8) + i, store_wdata_lo[i*8 +: 8]);
        end
      end
      for (int i = 0; i < 8; i = i + 1) begin
        if (store_wmask[i + 8]) begin
          ram_write_byte((store_addr & 64'hfffffffffffffff8) + 8 + i, store_wdata_hi[i*8 +: 8]);
        end
      end
    end
  end

`else
  always @* begin
    rdata0_lo = 64'd0;
    rdata0_hi = 64'd0;
    rdata1_lo = 64'd0;
    rdata1_hi = 64'd0;
    ptw_rdata = 64'd0;
    wdata_lo  = 64'd0;
    wdata_hi  = 64'd0;
  end
`endif
endmodule
