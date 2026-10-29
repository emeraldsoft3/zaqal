#include "refproxy.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cstring>
#include <getopt.h>
#include <verilated.h>
#include "VCore.h"

#define RAM_BASE 0x80000000ULL
#define RAM_SIZE (128 * 1024 * 1024ULL) // 128 MB DRAM

static uint8_t *ram = nullptr;
static uint64_t max_cycles = 1000000ULL;
static const char *image_path = nullptr;
static const char *diff_so_path = "/home/emerald/xs-env/NEMU/ready-to-run/riscv64-nemu-interpreter-so";

extern uint64_t g_commit_count;

void print_help(const char *prog) {
  std::cout << "Usage: " << prog << " [options]\n"
            << "Options:\n"
            << "  -i, --image <bin>       Path to raw binary image to load at 0x80000000\n"
            << "  -d, --diff <so>         Path to NEMU shared library (default: ready-to-run)\n"
            << "  -m, --max-cycles <num>  Maximum simulation clock cycles (default: 1M)\n"
            << "  -h, --help              Print this help menu\n";
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);

  static struct option long_options[] = {
    {"image",      required_argument, 0, 'i'},
    {"diff",       required_argument, 0, 'd'},
    {"max-cycles", required_argument, 0, 'm'},
    {"help",       no_argument,       0, 'h'},
    {0, 0, 0, 0}
  };

  int opt;
  while ((opt = getopt_long(argc, argv, "i:d:m:h", long_options, nullptr)) != -1) {
    switch (opt) {
      case 'i': image_path = optarg; break;
      case 'd': diff_so_path = optarg; break;
      case 'm': max_cycles = std::stoull(optarg); break;
      case 'h': print_help(argv[0]); return 0;
      default:  print_help(argv[0]); return 1;
    }
  }

  std::cout << "===============================================================\n"
            << "           ZAQAL 6-WIDE OoO PROCESSOR DIFFTEST HARNESS         \n"
            << "===============================================================\n";

  // 1. Allocate host RAM
  ram = new uint8_t[RAM_SIZE];
  std::memset(ram, 0, RAM_SIZE);

  // 2. Load program image
  uint64_t img_size = 0;
  if (image_path) {
    std::ifstream file(image_path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
      std::cerr << "[Error] Cannot open image file: " << image_path << "\n";
      return 1;
    }
    img_size = file.tellg();
    file.seekg(0, std::ios::beg);
    if (img_size > RAM_SIZE) {
      std::cerr << "[Error] Image size (" << img_size << " B) exceeds RAM size (" << RAM_SIZE << " B)\n";
      return 1;
    }
    file.read(reinterpret_cast<char*>(ram), img_size);
    file.close();
    std::cout << "[Init] Loaded binary '" << image_path << "' (" << img_size << " bytes) at 0x"
              << std::hex << RAM_BASE << std::dec << "\n";
  } else {
    std::cout << "[Warn] No image specified with -i; running empty memory.\n";
  }

  // 3. Attach NEMU Golden Model
  if (diff_so_path && g_ref.load(diff_so_path)) {
    if (img_size > 0) {
      g_ref.memcpy(RAM_BASE, ram, img_size, DIFFTEST_TO_REF);
      std::cout << "[Difftest] Synchronized " << img_size << " bytes of initial RAM to NEMU.\n";
    }

    // Set NEMU initial state: PC = 0x80000000, Machine Mode
    RISCV64_CPU_State init_state;
    std::memset(&init_state, 0, sizeof(init_state));
    init_state.pc = RAM_BASE;
    init_state.mode = 3; // M-mode
    g_ref.regcpy(&init_state, DIFFTEST_TO_REF);
    std::cout << "[Difftest] Initialized NEMU Golden Model PC to 0x" << std::hex << RAM_BASE << std::dec << "\n";
  } else {
    std::cout << "[Warn] Running without Golden Model co-simulation.\n";
  }

  // 4. Instantiate DUT (Zaqal Core)
  VCore *top = new VCore;

  // Initialize inputs
  top->clock = 0;
  top->reset = 1;
  top->io_plic_ext_irq = 0;
  top->io_mem_req_ready = 1;
  top->io_mem_resp_valid = 0;
  top->io_mem_d_req_ready = 1;
  top->io_mem_d_resp_valid = 0;

  std::cout << "[Sim] Starting simulation (Max Cycles: " << max_cycles << ")...\n";

  uint64_t cycle = 0;
  bool finished = false;
  bool mem_handling = false;
  bool dmem_handling = false;
  uint64_t dmem_req_addr = 0;
  uint64_t mem_req_addr = 0;

  while (!Verilated::gotFinish() && cycle < max_cycles && !finished) {
    // Clock low
    top->clock = 0;

    // Reset deassert after 10 cycles
    if (cycle > 10) {
      top->reset = 0;
    }

    // Default bus signals
    top->io_mem_req_ready = 1;
    top->io_mem_d_req_ready = 1;
    top->io_tl_d_a_ready = 1;
    top->io_tl_d_b_valid = 0;
    top->io_tl_d_c_ready = 1;
    top->io_tl_d_d_valid = 0;
    top->io_tl_d_e_ready = 1;

    // -------------------------------------------------------------
    // Stateful Memory Bus Controller (Serving L1-D Refills)
    // -------------------------------------------------------------
    if (top->io_mem_d_req_valid) {
      if (!dmem_handling) {
        dmem_handling = true;
        dmem_req_addr = top->io_mem_d_req_bits_addr;
      }
    }

    if (dmem_handling) {
      top->io_mem_d_resp_valid = 1;
      top->io_mem_d_resp_bits_last = 1;
      if (dmem_req_addr >= RAM_BASE && (dmem_req_addr - RAM_BASE) < RAM_SIZE) {
        uint64_t offset = dmem_req_addr - RAM_BASE;
        for (int b = 0; b < 8; b++) {
          top->io_mem_d_resp_bits_data[b] = ((uint32_t*)(ram + offset))[b];
        }
      } else {
        for (int b = 0; b < 8; b++) {
          top->io_mem_d_resp_bits_data[b] = 0;
        }
      }
      if (top->io_mem_d_resp_ready) {
        dmem_handling = false;
      }
    } else {
      top->io_mem_d_resp_valid = 0;
    }

    // -------------------------------------------------------------
    // Stateful Memory Bus Controller (Serving L1-I Refills)
    // -------------------------------------------------------------
    if (top->io_mem_req_valid) {
      if (!mem_handling) {
        mem_handling = true;
        mem_req_addr = top->io_mem_req_bits_addr;
        std::cout << "[Sim cycle " << cycle << "] I-Cache Fetch Request: 0x" << std::hex << mem_req_addr << std::dec << std::endl;
      }
    }

    if (mem_handling) {
      top->io_mem_resp_valid = 1;
      top->io_mem_resp_bits_last = 1;
      if (mem_req_addr >= RAM_BASE && (mem_req_addr - RAM_BASE) < RAM_SIZE) {
        uint64_t offset = mem_req_addr - RAM_BASE;
        for (int b = 0; b < 8; b++) {
          top->io_mem_resp_bits_data[b] = ((uint32_t*)(ram + offset))[b];
        }
      } else {
        for (int b = 0; b < 8; b++) {
          top->io_mem_resp_bits_data[b] = 0x00000013; // NOP
        }
      }
      if (top->io_mem_resp_ready) {
        mem_handling = false;
      }
    } else {
      top->io_mem_resp_valid = 0;
    }

    // UART Output Sniffer (MMIO print)
    if (top->io_uart_tx_valid) {
      std::cout << (char)top->io_uart_tx_char << std::flush;
    }

    top->eval();

    // Clock high (rising edge triggers RTL & DPI-C commit callbacks)
    top->clock = 1;
    top->eval();

    cycle++;
  }

  std::cout << "\n===============================================================\n"
            << "Simulation Completed!\n"
            << "  Total Cycles:    " << cycle << "\n"
            << "  Total Commits:   " << g_commit_count << "\n"
            << "  Average IPC:     " << (cycle > 0 ? (double)g_commit_count / cycle : 0.0) << "\n"
            << "===============================================================\n";

  delete top;
  delete[] ram;
  return 0;
}
