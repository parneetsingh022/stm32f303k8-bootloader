# Name of the final binary
TARGET := bootloader

# Build directory
BUILD_DIR := build

# Toolchain definitions
CC := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
STFLASH := st-flash

# Find every C source file under src/ and its subdirectories
SRCS := $(shell find src -type f -name '*.c')
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Linker script
LINKER_SCRIPT := linker.ld

# Compiler flags
CFLAGS := -mcpu=cortex-m4 \
          -mthumb \
          -O0 \
          -nostdlib \
          -ffreestanding \
          -Iincludes \
          -MMD \
          -MP

# Linker flags
LDFLAGS := -T $(LINKER_SCRIPT)

# Default target
all: $(BUILD_DIR)/$(TARGET).bin

# Link all object files into the ELF file
$(BUILD_DIR)/$(TARGET).elf: $(OBJS) $(LINKER_SCRIPT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

# Compile each source file into a matching object file.
# For example: src/uart.c -> build/src/uart.o
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Convert the ELF file into a raw binary
$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# Flash the bootloader at the beginning of STM32 flash
flash: $(BUILD_DIR)/$(TARGET).bin
	$(STFLASH) write $< 0x08000000

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)

.PHONY: all flash clean
