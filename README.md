# STM32F303K8 Bootloader

A bare-metal bootloader for the **STM32F303K8** microcontroller. The project includes a UART driver that allows a host computer to send a new application firmware image to the device for in-field firmware updates.

## Features

- Designed for the STM32F303K8
- Bare-metal register-level implementation
- UART driver for host communication
- Firmware image transfer and application update support
- Separation between bootloader and user application

## Update Flow

1. The microcontroller resets and starts the bootloader.
2. The bootloader initializes the required clocks and UART peripheral.
3. It checks whether a firmware update has been requested.
4. If an update is requested, the bootloader receives the application image over UART.
5. The received image is written to the application flash region.
6. After a successful update, the bootloader verifies the image and jumps to the application.

If no update is requested, the bootloader can jump directly to the existing application.

## Hardware

- STM32F303K8 development board
- USB-to-UART adapter
- UART TX, RX, and GND connections

Connect the USB-to-UART adapter's TX line to the STM32's RX pin and its RX line to the STM32's TX pin. Make sure both devices share a common ground and use compatible logic levels.

## UART Configuration

The UART settings are defined in the source code and should match the host-side update tool.

Typical settings:

```text
Baud rate: 115200
Data bits: 8
Parity:    None
Stop bits: 1
```

## Firmware Packet Format

The firmware-update protocol is under development. The planned packet format is:

```text
+---------+--------+---------+------+------+
| Command | Length | Address | Data | CRC  |
+---------+--------+---------+------+------+
| 1 byte  | 2 bytes| 4 bytes | N    |4 byte|
+---------+--------+---------+------+------+
```

## Building and Flashing

Build and flashing commands depend on the selected toolchain and project files. A typical ARM GNU toolchain workflow is:

```bash
make
make flash
```

The exact flash address, linker script, and build commands must match the memory layout used by the project.

## Memory Layout

The bootloader and application must occupy separate flash regions. The application linker script must use the application start address rather than the default flash start address.

```text
0x08000000  Bootloader
0x08004000  Application
```

The final addresses and sizes will be defined in the linker scripts.

## Safety Considerations

- Do not erase the bootloader region while updating the application.
- Validate the firmware size before erasing or programming flash.
- Verify the firmware image using a CRC or another integrity check.
- Only jump to an application with a valid initial stack pointer and reset handler.
- Handle interrupted or corrupted updates safely.

## Status

Work in progress. UART communication and the firmware-update protocol are being developed alongside the bootloader.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
