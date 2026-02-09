#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

/* Register log module */
LOG_MODULE_REGISTER(blinky, LOG_LEVEL_INF);

/* 1000 msec */
#define SLEEP_TIME_MS 1000

/* Get the node spec from the devicetree alias */
#define LED0_NODE DT_ALIAS(my_custom_led)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
    int ret;

    LOG_INF("Starting blinky on STM32F303RE");

    if (!gpio_is_ready_dt(&led)) {
        LOG_ERR("Error: LED device not ready");
    }

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        LOG_ERR("Error: Could not configure LED");
    }

    for (;;) {
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            LOG_ERR("Error: Could not toggle LED");
            break;
        }

        LOG_INF("LED toggled");
        k_msleep(SLEEP_TIME_MS);
    }

    return 0;
}