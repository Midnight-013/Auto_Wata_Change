#include <stdio.h>
#include <flow_sense.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

// Set LED GPIO - 2 is default for most ESP32 DevKits
#define BLINK_GPIO 2 

void app_main(void)
{
 // Configure the GPIO pin
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while(1) {
        printf("Adam Turns LED off\n");
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1s

        // printf("Adam Turns LED on\n");
        printf("But Ivan turns LED ON\n");
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1s
    }
}