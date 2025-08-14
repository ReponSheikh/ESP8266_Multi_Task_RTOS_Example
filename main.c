#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_common.h"
#include "gpio.h"
#include "uart.h"
#include <stdio.h>

#define LED_GPIO 2 // Built-in LED pin for most ESP-12 modules

// Task 1: Blink LED
void blink_task(void *pvParameter) {
    GPIO_ConfigTypeDef gpioConfig;
    gpioConfig.GPIO_Pin = BIT(LED_GPIO);
    gpioConfig.GPIO_Mode = GPIO_Mode_Output;
    gpio_config(&gpioConfig);

    while (1) {
        gpio_output_set(0, BIT(LED_GPIO), BIT(LED_GPIO), 0); // LED ON
        printf("Task 1: LED ON\n");
        vTaskDelay(500 / portTICK_RATE_MS);

        gpio_output_set(BIT(LED_GPIO), 0, BIT(LED_GPIO), 0); // LED OFF
        printf("Task 1: LED OFF\n");
        vTaskDelay(500 / portTICK_RATE_MS);
    }
}

// Task 2: Print messages
void print_task(void *pvParameter) {
    while (1) {
        printf("Task 2: Hello from ESP8266 RTOS SDK!\n");
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

// Required by SDK
uint32 user_rf_cal_sector_set(void) {
    flash_size_map size_map = system_get_flash_size_map();
    uint32 rf_cal_sec = 0;

    switch (size_map) {
        case FLASH_SIZE_4M_MAP_256_256: rf_cal_sec = 128 - 5; break;
        case FLASH_SIZE_8M_MAP_512_512: rf_cal_sec = 256 - 5; break;
        case FLASH_SIZE_16M_MAP_512_512:
        case FLASH_SIZE_16M_MAP_1024_1024: rf_cal_sec = 512 - 5; break;
        case FLASH_SIZE_32M_MAP_512_512:
        case FLASH_SIZE_32M_MAP_1024_1024: rf_cal_sec = 1024 - 5; break;
        default: rf_cal_sec = 0; break;
    }
    return rf_cal_sec;
}

// Main entry point
void user_init(void) {
    uart_div_modify(0, UART_CLK_FREQ / 115200); // Set baud rate

    printf("ESP8266 RTOS SDK Multi-Task Test\n");
    printf("SDK version: %s\n", system_get_sdk_version());

    // Create two tasks
    xTaskCreate(blink_task, "blink_task", 256, NULL, 2, NULL);
    xTaskCreate(print_task, "print_task", 256, NULL, 2, NULL);
}
