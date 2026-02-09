# Hardware setup

## Development board
I am using the **STM32 Nucleo-64 (F303RE)**. This board features:
* **MCU:** STM32F303RET6 (ARM Cortex-M4, 72 MHz)
* **Flash:** 512 KB
* **SRAM:** 64 KB
* **Debugger:** Onboard ST-LINK/V2-1

## Connections
For the *Blinky* project, no external wiring is required.
* **USB:** Connected to PC for power + ST-LINK (Programming/UART).
* **Green LED (LD2):** Connected to PA5.
* **User button (B1):** Connected to PC13 (Blue button).
