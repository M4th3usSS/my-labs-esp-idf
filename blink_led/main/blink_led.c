/**
 * Autor: Matheus Sousa
 * Obejetivo: Treinamento de ESP-IDF 
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


/**
 * 
 * Tarefa de Blink led 
 * 
*/
void vTaskBlinkLed(void *pvParameter) {

    esp_rom_gpio_pad_select_gpio(GPIO_NUM_12); 
    gpio_set_direction(GPIO_NUM_12,GPIO_MODE_OUTPUT);
    printf("Blinking LED on GPIO 16\n");
    
    uint32_t ulCounter = 0;

    for(;;) {
		gpio_set_level(GPIO_NUM_12,ulCounter %2);
        ulCounter ++;
        vTaskDelay(pdMS_TO_TICKS(90));
    }
}


/**
 * 
 * App-main
 * 
*/
void app_main(void) {
	xTaskCreate(vTaskBlinkLed, "Task blink led", 1024, NULL, 1, NULL);
}
 