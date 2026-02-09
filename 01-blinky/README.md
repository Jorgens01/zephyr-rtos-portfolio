# Project 01: Blinky

A multi-threaded LED blinker that demonstrates the core fundamentals of Zephyr: **DeviceTree abstraction** and **Kernel threads**.

## 🎯 Objectives
* Decouple hardware from code using **DeviceTree overlays** (`.overlay` files).
* Create a dedicated thread for LED control (avoiding the `main` loop).
* Implement structured logging with `LOG_INF`.

## ⚙️ Hardware setup
* **Board:** ST Nucleo F303RE
* **LED:** Onboard user LED (green), mapped to `LD2` (PA5).

## 🧩 Code structure

### DeviceTree overlay
Instead of hardcoding Pin 5, I mapped the board's generic LED to a project-specific alias `my-custom-led`:

```dts
/* boards/nucleo_f303re.overlay */
/ {
    aliases {
        my-custom-led = &green_led_2;
    };
};
```

### Threading model
The blinking logic runs in its own context, allowing the main thread to handle initialization or sleep.
```c
/* src/main.c snippet */
#define LED0_NODE DT_ALIAS(my_custom_led)

while (1) {
    gpio_pin_toggle_dt(&led);
    LOG_INF("LED Toggled");
    k_msleep(1000);
}
```

## Demo


