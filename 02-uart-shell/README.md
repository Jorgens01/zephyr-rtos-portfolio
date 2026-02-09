# Project 02: UART shell interface

This project enables the **Zephyr shell subsystem** over UART (USB Serial). It demonstrates how to register custom shell commands to control hardware, allowing for interactive debugging and manual control without recompiling.

## 🎯 Objectives
* Enable the UART Console and Shell subsystem via Kconfig.
* Register custom commands (`led on`, `led off`) using `SHELL_CMD_REGISTER`.
* Parse command-line arguments in C.

## 🛠️ Usage
1.  **Flash** the board.
2.  **Connect** via serial terminal (e.g., `tio /dev/ttyACM0` or PuTTY) at **115200 baud**.
3.  **Run commands:**
    * Type `help` to see available commands.
    * Type `led on` to turn the Green LED on.
    * Type `led off` to turn the Green LED off.

## 📝 Terminal session
```text
uart:~$ help
Please press the <Tab> button to see all available commands.
See 'help <command>' to get help for that command.

uart:~$ led on
LED is ON
uart:~$ led off
LED is OFF