#include "screenCont.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_log.h"
#include "driver/i2c.h"
#include <stdio.h>
#include <stdint.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define I2C_MASTER_SCL_IO   18
#define I2C_MASTER_SDA_IO   19
#define I2C_MASTER_PORT      I2C_NUM_0
#define I2C_MASTER_FREQ_HZ  4000000
#define I2C_MASTER_TX_BUF_DISABLE   0
#define I2C_MASTER_RX_BUF_DISABLE   0
#define I2C_SLAVE_ADDR    0x3C

static const char *TAG  = "i2c-example";

void i2c_master_init(void);

void app_main(void) {
//i2c_master_init();
newButton(); 
}



void setup() {

}


void i2c_master_init(void) {
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed= I2C_MASTER_FREQ_HZ,
    };

    ESP_ERROR_CHECK(i2c_param_config(I2C_MASTER_PORT  , &conf));
    ESP_ERROR_CHECK(i2c_driver_install(
        I2C_MASTER_PORT,
        conf.mode,
        I2C_MASTER_RX_BUF_DISABLE,
        I2C_MASTER_TX_BUF_DISABLE, 
        0
    ));

    while(1) {
            

    }

}
