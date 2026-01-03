//Device address is 0x3c

/**
 * The I2C driver offers following services:

    Resource Allocation - covers how to allocate I2C bus with properly set of configurations. It also covers how to recycle the resources when they finished working.

    I2C Master Controller - covers behavior of I2C master controller. Introduce data transmit, data receive, and data transmit and receive.

    I2C Slave Controller - covers behavior of I2C slave controller. Involve data transmit and data receive.

    Power Management - describes how different source clock will affect power consumption.

    IRAM Safe - describes tips on how to make the I2C interrupt work better along with a disabled cache.

    Thread Safety - lists which APIs are guaranteed to be thread safe by the driver.

    Kconfig Options - lists the supported Kconfig options that can bring different effects to the driver.

 */

#include "driver/i2c.h"
#include "driver/i2c_slave.h"
#include "driver/i2c_master.h"

i2c_master_bus_config_t i2c_master_conf = {
    .clk_source = I2C_CLK_SRC_DEFAULT,



};