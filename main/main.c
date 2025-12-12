#include "ButtonBuzz.h"          // your own declarations (i2c_config_TEST etc.)
#include "i2cConfig.h"             

#include <stdio.h>               // printf
#include "freertos/FreeRTOS.h"   // FreeRTOS base types/macros
#include "freertos/task.h"       // vTaskDelay, pdMS_TO_TICKS

#include "esp_err.h"             // ESP_OK, esp_err_t (if you use it)

#include "driver/ledc.h"         // LEDC timer/channel config
#include "driver/i2c_master.h"   // new I2C master API



void app_main(void) {
i2c_config_TEST();
//i2c_master_init();
//newButton(); 
}

