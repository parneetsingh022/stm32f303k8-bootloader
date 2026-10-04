# Name of the final binary
TARGET := bootloader

# Build directory
BUILD_DIR := build

# Source directories for the project
SRC_DIRS := bootloader drivers

# Toolchain definitions
CC := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
STFLASH := st-flash

# Find every C source file under the specified directories
SRCS := $(shell find $(SRC_DIRS) -type f -name '*.c')
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
# For example: bootloader/main.c -> build/bootloader/main.o
#              drivers/uart.c     -> build/drivers/uart.o
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
