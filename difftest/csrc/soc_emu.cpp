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

#define DRAM_BASE 0x80000000ULL
#define DRAM_WORDS 2097152ULL

static uint64_t max_cycles = 1000ULL;
static const char *image_path = nullptr;
static const char *vcd_path = nullptr;

extern uint64_t g_commit_count;

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
    if (tfp) tfp->dump(sim_time++);

    top->clock = 1;
    top->eval();
    if (tfp) tfp->dump(sim_time++);

    if (top->io_uart_tx_valid) {
      char ch = (char)(top->io_uart_tx_char & 0xFF);
      std::cout << ch << std::flush;
      uart_chars++;
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
  delete top;
  return 0;
}
