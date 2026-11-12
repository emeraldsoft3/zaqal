#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cstring>
#include <getopt.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VZaqalSoCTop.h"
#include "VZaqalSoCTop___024root.h"
#include "rob_dump.h"
#include "debug_dump.h"

#define DRAM_BASE 0x80000000ULL
#define DRAM_WORDS 2097152ULL

static uint64_t max_cycles = 1000ULL;
static const char *image_path = nullptr;
static const char *vcd_path = nullptr;

extern uint64_t g_commit_count;

static VZaqalSoCTop *g_soc_top = nullptr;

extern "C" uint64_t ram_read_dword(uint64_t addr) {
  if (g_soc_top && addr >= DRAM_BASE && (addr - DRAM_BASE) < (DRAM_WORDS * 8)) {
    return g_soc_top->rootp->ZaqalSoCTop__DOT__dram__DOT__mem_ext__DOT__Memory[(addr - DRAM_BASE) / 8];
  }
  return 0ULL;
}

extern "C" void ram_write_byte(uint64_t addr, uint8_t byte) {
  if (g_soc_top && addr >= DRAM_BASE && (addr - DRAM_BASE) < (DRAM_WORDS * 8)) {
    uint64_t idx = (addr - DRAM_BASE) / 8;
    uint32_t shift = (addr & 7) * 8;
    uint64_t mask = ~(0xFFULL << shift);
    g_soc_top->rootp->ZaqalSoCTop__DOT__dram__DOT__mem_ext__DOT__Memory[idx] =
      (g_soc_top->rootp->ZaqalSoCTop__DOT__dram__DOT__mem_ext__DOT__Memory[idx] & mask) | (((uint64_t)byte) << shift);
  }
}

void print_help(const char *prog) {
  std::cout << "Usage: " << prog << " [options] [image.bin]\n"
            << "Options:\n"
            << "  -i, --image <bin>       Path to raw binary image to load at 0x80000000\n"
            << "  -m, --max-cycles <num>  Maximum simulation clock cycles (default: 1k)\n"
            << "  -t, --trace <vcd>       Dump VCD waveform trace file for GTKWave\n"
            << "  -h, --help              Print this help menu\n";
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);

  static struct option long_options[] = {
    {"image",      required_argument, 0, 'i'},
    {"max-cycles", required_argument, 0, 'm'},
    {"trace",      required_argument, 0, 't'},
    {"help",       no_argument,       0, 'h'},
    {0, 0, 0, 0}
  };

  int opt;
  while ((opt = getopt_long(argc, argv, "i:m:t:h", long_options, nullptr)) != -1) {
    switch (opt) {
      case 'i': image_path = optarg; break;
      case 'm': max_cycles = std::stoull(optarg); break;
      case 't': vcd_path = optarg; break;
      case 'h': print_help(argv[0]); return 0;
      default:  print_help(argv[0]); return 1;
    }
  }

  // Handle positional argument for image binary
  if (!image_path && optind < argc) {
    image_path = argv[optind];
  }

  std::cout << "===============================================================\n"
            << "           ZAQAL AXI4 FULL-SoC SIMULATION HARNESS              \n"
            << "===============================================================\n";

  if (vcd_path) {
    Verilated::traceEverOn(true);
  }

  VZaqalSoCTop *top = new VZaqalSoCTop;
  g_soc_top = top;
  VerilatedVcdC *tfp = nullptr;

  if (vcd_path) {
    tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open(vcd_path);
    std::cout << "[GTKWave] Recording waveform trace to: " << vcd_path << "\n";
  }

  top->clock = 0;
  top->reset = 1;
  top->io_plic_ext_irq = 0;
  top->io_spi_miso = 1;

  if (image_path) {
    std::ifstream file(image_path, std::ios::binary | std::ios::ate);
    if (file.is_open()) {
      std::streamsize size = file.tellg();
      file.seekg(0, std::ios::beg);
      std::vector<uint8_t> buffer(size);
      file.read(reinterpret_cast<char*>(buffer.data()), size);
      file.close();

      for (size_t i = 0; i < (size_t)size && (i / 8) < DRAM_WORDS; i += 8) {
        uint64_t val = 0;
        for (size_t b = 0; b < 8 && (i + b) < (size_t)size; b++) {
          val |= ((uint64_t)buffer[i + b]) << (8 * b);
        }
        top->rootp->ZaqalSoCTop__DOT__dram__DOT__mem_ext__DOT__Memory[i / 8] = val;
      }
      std::cout << "[SoC Sim] Loaded " << size << " bytes to DRAM at 0x"
                << std::hex << DRAM_BASE << std::dec << ".\n";
    }
  }

  uint64_t sim_time = 0;

  // Reset pulse
  for (int r = 0; r < 20; r++) {
    top->clock = 0; top->eval();
    if (tfp) tfp->dump(sim_time++);
    top->clock = 1; top->eval();
    if (tfp) tfp->dump(sim_time++);
  }
  top->reset = 0;
  std::cout << "[SoC Sim] Reset released. Executing SoC (" << max_cycles << " cycles)...\n";
  std::cout << "---------------------------------------------------------------\n";
  std::cout << "[UART OUTPUT STREAM]:\n";

  uint64_t uart_chars = 0;
  for (uint64_t cycle = 0; cycle < max_cycles; cycle++) {
    top->clock = 0;
    top->eval();
    if (tfp && cycle >= 18310 && cycle <= 18360) tfp->dump(sim_time++);

    top->clock = 1;
    top->eval();
    if (tfp && cycle >= 18310 && cycle <= 18360) tfp->dump(sim_time++);


    if (top->io_uart_tx_valid) {
      char ch = (char)(top->io_uart_tx_char & 0xFF);
      static uint64_t null_cnt = 0;
      if (ch == 0) {
        null_cnt++;
        if (null_cnt <= 5 || null_cnt % 500 == 0) {
          std::cerr << "\n[UART NULL #" << std::dec << null_cnt << " at cycle " << cycle << "]" << std::endl;
        }
      } else {
        std::cout << ch << std::flush;
      }
      uart_chars++;
    }

    uint8_t cur_head = top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__headPtr;
    uint8_t cur_tail = top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__intFreeList__DOT__tailPtr;
    uint8_t rob_elems = top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__elementsInRob;
    int in_flight = (cur_head >= cur_tail) ? (cur_head - cur_tail) : (160 - (cur_tail - cur_head));
    if (rob_elems == 0 && cur_head != cur_tail && cycle > 500) {
      static uint64_t last_desync_cycle = 0;
      if (cycle - last_desync_cycle > 5000) {
        std::cout << "\n\033[1;31m[EMPTY ROB DESYNC]\033[0m at cycle " << cycle 
                  << " commit #" << g_commit_count
                  << ": head=" << (int)cur_head << " tail=" << (int)cur_tail
                  << " in_flight=" << in_flight
                  << "\n";
        last_desync_cycle = cycle;
      }
    }

    static uint64_t last_commit = 0;
    static uint64_t last_commit_cycle = 0;
    if (g_commit_count != last_commit) {
      last_commit = g_commit_count;
      last_commit_cycle = cycle;
    } else if (cycle - last_commit_cycle > 3000 && cycle > 500) {
      uint8_t deq = top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__deqPtr;
      uint8_t enq = top->rootp->ZaqalSoCTop__DOT__core__DOT__backend__DOT__rob__DOT__enqPtr;
      std::cout << "\n\033[1;31m[STALL DETECTED]\033[0m No instructions committed for 3000 cycles at cycle " 
                << cycle << "! Last commit #" << g_commit_count 
                << " ROB deq=" << (int)deq << " enq=" << (int)enq << "\n";
      dump_rob(top, deq, 8);
      dump_debug(top);
      break;
    }
  }

  std::cout << "\n---------------------------------------------------------------\n";
  std::cout << "===============================================================\n"
            << "  SoC Simulation Finished.\n"
            << "  Total Simulation Cycles: " << max_cycles << "\n"
            << "  Total Instructions Committed: " << g_commit_count << "\n"
            << "  Total UART Characters Received: " << uart_chars << "\n";
  if (vcd_path) {
    std::cout << "  Waveform Saved: " << vcd_path << "\n";
  }
  std::cout << "===============================================================\n";

  if (tfp) {
    tfp->close();
    delete tfp;
  }
  g_soc_top = nullptr;
  delete top;
  return 0;
}
