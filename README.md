# UMRT CIRC 2024 Embedded Controller (EMCU) Firmware

This repository contains firmware for the Embedded Controller Unit (EMCU).

## Prerequisites

- CMake 3.13 (or newer)
- Raspberry Pi Pico C/C++ Toolchain
- OpenOCD and GDB (Optional, used for debugging)
- VSCode with cortex-debug and CMake plugins (Optional, used for debugging)

## Building

To build the contents of this repository, follow the steps in [the Raspberry Pi Pico C SDK Documentation](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) to setup your toolchain.

Once complete, pull the FreeRTOS kernel by calling: 

```sh
git submodule update --init
```

Then, build the project using CMake:

```sh
mkdir build && cd build
cmake ..
make
```

(Hint: Speed up build times using `make -jN`, where `N` is the number of available CPU Cores)

The `.uf2` file produced by the toolchain can be uploaded to the Pico development board, or alternatively the `.elf` binary can be flashed using OpenOCD/GDB for debugging.
