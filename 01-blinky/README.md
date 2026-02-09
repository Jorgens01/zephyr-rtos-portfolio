# Project 01: Blinky

A multi-threaded LED blinker that demonstrates the core fundamentals of Zephyr: **DeviceTree abstraction** and **Kernel threads**.

## 🎯 Objectives
* Decouple hardware from code using **DeviceTree Overlays** (`.overlay` files).
* Create a dedicated thread for LED control (avoiding the `main` loop).
* Implement structured logging with `LOG_INF`.

## ⚙️ Hardware Setup
* **Board:** ST Nucleo F303RE
* **LED:** Onboard User LED (Green), mapped to `LD2` (PA5).

## 🧩 Code Structure

### DeviceTree Overlay
Instead of hardcoding Pin 5, I mapped the board's generic LED to a project-specific alias `my-custom-led`:

```dts
/* boards/nucleo_f303re.overlay */
/ {
    aliases {
        my-custom-led = &green_led_2;
    };
};