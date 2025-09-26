# swoop

## Overview

The swoop project is a custom keyboard firmware configuration built on the ZMK (Zephyr Mechanical Keyboard) framework. This project focuses on a split keyboard design with trackball integration using the PMW3610 optical sensor. The keyboard features a 64-key layout distributed across two halves, with advanced pointing device capabilities for enhanced user interaction.

## User Preferences

Preferred communication style: Simple, everyday language.

## Recent Changes

**September 26, 2025**: Completed comprehensive PMW3610 trackball firmware migration and fixes:
- **Driver Migration**: Switched to ihlinuxdude/zmk-pmw3610-driver64key fork optimized for canted trackballs
- **Configuration Consolidation**: Moved all systematic fixes from ignored 64key-3610-3/ directory to root level where GitHub Actions actually reads them
- **SPI Fixes**: Corrected electrical issues (MISO=P0.17, MOSI=P0.24), implemented SPI Mode 3, proper pin assignments
- **Build System**: Removed problematic studio-rpc-usb-uart snippet, clean logging without CONFIG_ZMK_LOG_LEVEL conflicts
- **Axis Transformation**: Configured swap-xy; and invert-x; device tree properties for 45° canted trackball
- **Power Management**: Applied 1000ms power-up delay for Nice!Nano v2 stability
- **Status**: All systematic fixes architect-approved and ready for GitHub Actions testing

## System Architecture

### Keyboard Firmware Architecture
- **Framework**: Built on ZMK (Zephyr-based mechanical keyboard firmware)
- **Target Hardware**: Nice!Nano v2 controllers with nRF52832 microcontrollers
- **Split Design**: Two-half keyboard configuration with wireless communication between halves
- **Pointing Device Integration**: PMW3610 optical sensor for trackball functionality

### Hardware Configuration
- **Microcontroller**: nRF52832 (ARM Cortex-M4) via Nice!Nano v2 boards
- **Communication Protocol**: Bluetooth Low Energy for wireless connectivity
- **Sensor Interface**: SPI communication for PMW3610 trackball sensor
- **Pin Mapping**: Custom GPIO assignments for SPI (MOSI: P0.06, MISO: P0.07, IRQ: P0.26)

### Layout and Key Matrix
- **Total Keys**: 64 keys arranged in a 4x12 matrix per half
- **Layout Format**: JSON-based configuration defining physical key positions
- **Coordinate System**: X/Y positioning for keymap visualization and configuration

### Build System
- **CI/CD**: GitHub Actions for automated firmware compilation
- **Build Targets**: Multiple configurations including USB and Bluetooth variants
- **Matrix Builds**: Support for different hardware configurations and feature sets

### Device Tree Configuration
- **Hardware Abstraction**: Device tree overlays for hardware-specific configurations
- **Sensor Configuration**: PMW3610 device node with SPI parameters and GPIO assignments
- **Pin Conflict Resolution**: Careful GPIO allocation to avoid hardware conflicts

## External Dependencies

### Core Framework
- **ZMK Firmware**: Zephyr-based mechanical keyboard firmware framework
- **Zephyr RTOS**: Real-time operating system providing hardware abstraction

### Hardware Drivers
- **PMW3610 Driver**: Custom or community driver for PixArt PMW3610 optical sensor
- **nRF52832 HAL**: Hardware abstraction layer for Nordic Semiconductor's nRF52832

### Development Tools
- **GitHub Actions**: Automated build and deployment pipeline
- **Device Tree Compiler**: For processing hardware configuration files

### Communication Protocols
- **Bluetooth LE Stack**: For wireless keyboard communication
- **SPI Protocol**: For trackball sensor communication
- **USB HID**: For wired keyboard operation

### Build Dependencies
- **ARM GCC Toolchain**: Cross-compilation tools for ARM Cortex-M4
- **Zephyr SDK**: Development kit for Zephyr-based applications