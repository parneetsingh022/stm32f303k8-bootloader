# Name of your final binary
TARGET = bootloader

# Build directory
BUILD_DIR = build

# Toolchain definitions
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
STFLASH = st-flash

# Files
SRCS = main.c
LINKER_SCRIPT = linker.ld

# Compiler Flags
CFLAGS = -mcpu=cortex-m4 -mthumb -O0 -nostdlib -T $(LINKER_SCRIPT)

# Default target: Make the .bin file
all: $(BUILD_DIR)/$(TARGET).bin

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile main.c into bootloader.elf inside the build folder
# The pipe (|) tells Make to create the folder first, but don't recompile
# everything just because the folder's modified timestamp changed.
$(BUILD_DIR)/$(TARGET).elf: $(SRCS) $(LINKER_SCRIPT) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRCS) -o $@

# Step 2: Strip the ELF into a raw bootloader.bin
$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

flash: $(BUILD_DIR)/$(TARGET).bin
	$(STFLASH) write $< 0x08000000

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all flash clean
