#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/shell/shell.h>
#include <stdlib.h>

/* Hardware setup */
#define LED0_NODE DT_ALIAS(my_custom_led)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

/* Command handler */
static int cmd_led_on(const struct shell *sh, size_t argc, char **argv)
{
    gpio_pin_set_dt(&led, 1);
    shell_print(sh, "LED is ON");
    return 0;
}

/* LED off */
static int cmd_led_off(const struct shell *sh, size_t argc, char **argv)
{
    gpio_pin_set_dt(&led, 0);
    shell_print(sh, "LED is OFF");
    return 0;
}

/* Subcommands */
SHELL_STATIC_SUBCMD_SET_CREATE(sub_led,
    SHELL_CMD(on, NULL, "Turn LED on", cmd_led_on),
    SHELL_CMD(off, NULL, "Turn LED off", cmd_led_off),
    SHELL_SUBCMD_SET_END // Array terminator
);

/* Register main command "led" */
SHELL_CMD_REGISTER(led, &sub_led, "Control the LED", NULL);

int main(void)
{
    /* Initializa hardware */
    if (!gpio_is_ready_dt(&led)) {
        return 0;
    }
    gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);

    return 0;
}