# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

# FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)

# idf_component_register(SRCS ${app_sources})

# PRIV_REQUIRES esp_driver_i2c
# PRIV_REQUIRES esp_driver_ledc
# PRIV_REQUIRES esp_driver_gpio  

idf_component_register(
    SRCS
        "main.c"
        "screenCont.c"
        "i2cConfig.c"
    INCLUDE_DIRS
        "."
    PRIV_REQUIRES
        esp_driver_i2c
        esp_driver_ledc
        esp_driver_gpio
)