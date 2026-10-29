BUILD_DIR = $(abspath ../build)
EMU_BIN   = $(BUILD_DIR)/emu
OBJ_DIR   = $(BUILD_DIR)/emu_obj
CSRC_DIR  = $(abspath ./csrc)

VERILATOR ?= verilator
MILL      ?= ./mill

VERILATOR_FLAGS = \
	--cc \
	--exe \
	--threads 4 \
	-O3 \
	--top-module Core \
	-Mdir $(OBJ_DIR) \
	-Wno-fatal \
	-Wno-WIDTH \
	-Wno-CASEINCOMPLETE \
	-Wno-TIMESCALEMOD \
	-Wno-UNOPTFLAT \
	-Wno-PINMISSING \
	--x-initial 0 \
	--x-assign 0 \
	--autoflush \
	-CFLAGS "-O3 -std=c++17 -I$(CSRC_DIR)" \
	-LDFLAGS "-ldl"

SRCS_V = $(wildcard $(BUILD_DIR)/*.v) $(wildcard $(BUILD_DIR)/*.sv)
SRCS_C = $(CSRC_DIR)/emu_main.cpp $(CSRC_DIR)/difftest_bridge.cpp

.PHONY: all emu elaborate clean

all: emu

elaborate:
	cd .. && $(MILL) zaqal.runMain zaqal.Elaborate

$(EMU_BIN): $(SRCS_V) $(SRCS_C)
	@mkdir -p $(OBJ_DIR)
	@echo "--- [1/2] Verilating Zaqal RTL with DPI-C Harness ---"
	$(VERILATOR) $(VERILATOR_FLAGS) $(SRCS_V) $(SRCS_C)
	@echo "--- [2/2] Compiling Native C++ Simulation Binary ($(EMU_BIN)) ---"
	$(MAKE) -j$$(nproc) -C $(OBJ_DIR) -f VCore.mk VCore
	@cp $(OBJ_DIR)/VCore $(EMU_BIN)
	@echo "==============================================================="
	@echo "  SUCCESS: Native Difftest Binary Built at: $(EMU_BIN)"
	@echo "==============================================================="

emu: $(EMU_BIN)

clean:
	rm -rf $(OBJ_DIR) $(EMU_BIN)
