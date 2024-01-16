#include <FreeRTOSConfig.h>

#include <FreeRTOS.h>
#include <task.h>

#include <pico/stdlib.h>

const TickType_t ms_delay = 500 / portTICK_PERIOD_MS;

TaskHandle_t main_task_handle = NULL;

void main_task(void *unused)
{
    uint32_t state = 0;

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    while (1) {
        state ^= 1;
        gpio_put(PICO_DEFAULT_LED_PIN, state);
        vTaskDelay(ms_delay);
    }
}

int main(void) {

    BaseType_t status = xTaskCreate(main_task, "BLINK", 128, NULL, 1, &main_task_handle);

    if (status == pdPASS) {
        vTaskStartScheduler();
    }

    while (true) {
        // Nothing.
    }
}

void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                    char * pcTaskName )
{
    /* Check pcTaskName for the name of the offending task,
     * or pxCurrentTCB if pcTaskName has itself been corrupted. */
    ( void ) xTask;
    ( void ) pcTaskName;

    while (true) {
        // Nothing.
    }
}