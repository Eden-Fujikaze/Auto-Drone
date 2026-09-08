#include <cstdio>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

constexpr gpio_num_t BLINK_GPIO = GPIO_NUM_0;

static const char *TAG = "blink";

extern "C" void app_main(void)
{
  gpio_reset_pin(BLINK_GPIO);
  gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

  ESP_LOGI(TAG, "blink GPIO %d", static_cast<int>(BLINK_GPIO));

  bool state = false;
  while (true) {
    gpio_set_level(BLINK_GPIO, state);
    ESP_LOGI(TAG, "set to %s", state ? "ON" : "OFF");
    state = !state;
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
