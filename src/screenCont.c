#include "screenCont.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/spi_master.h"


#define B_GPIOO 27
#define B_GPIOI 26

#define GPIO_BZ 4

static const char *TAG = "BUTTON";

void newButton(void); 
void screenMain(void);
void humSensor(void);

void screenMain(void) {
    //Add I2C config code for the screen later.
}



void newButton(void) {
  gpio_config_t B_detect_config1 = {
        .mode=GPIO_MODE_OUTPUT,
        .pin_bit_mask=(1ULL << B_GPIOO),
        .pull_up_en=GPIO_PULLUP_DISABLE,
        .pull_down_en=GPIO_PULLDOWN_DISABLE,
        .intr_type=GPIO_INTR_DISABLE,
    };
    gpio_config_t B_detect_config2 = {
        .mode=GPIO_MODE_DEF_INPUT,
        .pin_bit_mask=(1ULL << B_GPIOI),
        .pull_up_en=GPIO_PULLUP_DISABLE,
        .pull_down_en=GPIO_PULLDOWN_DISABLE,
        .intr_type=GPIO_INTR_DISABLE,
    };
    gpio_config_t BZ_config = {
        .mode=GPIO_MODE_OUTPUT,
        .pin_bit_mask=(1ULL << GPIO_BZ),
        .pull_up_en=GPIO_PULLUP_DISABLE,
        .pull_down_en=GPIO_PULLDOWN_DISABLE,
        .intr_type=GPIO_INTR_DISABLE,
    };

    gpio_config(&B_detect_config1);
    gpio_config(&B_detect_config2);
    gpio_config(&BZ_config);
    ESP_LOGI(TAG,"Starting Output power to Button on GPIO %d", B_GPIOO);
    ESP_LOGI(TAG,"Starting Input check to Button on GPIO %d", B_GPIOI);

    while(1) {
        gpio_set_level(B_GPIOO,1);
        gpio_set_level(GPIO_BZ,0);
        int level = gpio_get_level(B_GPIOI);
        if (level == 1) {
            ESP_LOGI(TAG, "Button Pressed!!");
            // int num = helper();
            gpio_set_level(GPIO_BZ,1);
             ESP_LOGI(TAG, "BLINK!!");
        }
        vTaskDelay(pdMS_TO_TICKS(100));
        gpio_set_level(GPIO_BZ, 0);
    }
}

  void humSensor(void) {

    }
// int helper(void) {
//     gpio_set_level(GPIO_BZ, 1);
//     vTaskDelay(pdMS_TO_TICKS(400));
//     return 0;

// }



       // gpio_set_level(B_GPIOO, 1);
        // gpio_set_level(GPIO_BZ,0);
        // int level = gpio_get_level(B_GPIOI);
        // if (level == 1) {
        //     ESP_LOGI(TAG, "Button Pressed!!");
        //     gpio_set_level(GPIO_BZ, 1);
        //     ESP_LOGI(TAG, "BUZZ!!");
        // }
        // vTaskDelay(pdMS_TO_TICKS(100));