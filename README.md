# Zephyr RTOS portfolio: STM32 Nucleo

This repository documents my journey mastering the Zephyr Real-Time Operating System (RTOS). It features a collection of modular, self-contained projects running on the **STM32 Nucleo F303RE** board.

**Key highlights:**
* 🐳 **Containerized environment:** Fully reproducible build system using Podman/Docker.
* 🛠️ **West workflow:** Custom workspace management for dependency handling.
* ⚡ **Hardware abstraction:** Extensive use of DeviceTree overlays and driver APIs.

## 📂 Project roadmap

| # | Project | Key Concepts | Status |
|:-:|:---|:---|:---|
| **01** | [Blinky](./01-blinky) | Threading, DeviceTree Overlays, GPIO | ✅ Complete |
| **02** | UART Shell | Interrupts, Serial Console, Logging | 🚧 Planned |
| **03** | I2C Sensor | I2C Drivers, Sensor Subsystem | 🚧 Planned |

## 🚀 Getting started

This repository uses a containerized toolchain to ensure "it works on your machine" immediately.

### Prerequisites
* Linux (Fedora/Ubuntu) or WSL2
* Docker or Podman
* `west` (Python tool) and `openocd` (for flashing only)

### Build instructions

1.  **Initialize the environment:**
    Launch the container (auto-detects Podman/Docker):
    ```bash
    ./scripts/run_dev.sh
    ```

2.  **Setup Zephyr (First run only):**
    Inside the container:
    ```bash
    west init -l config
    west update
    west zephyr-export
    ```

3.  **Build a project:**
    ```bash
    west build -p always -b nucleo_f303re 01-blinky-plus
    ```

### Flashing (Host side)

Connect your Nucleo board via USB and run:
```bash
./scripts/flash.sh