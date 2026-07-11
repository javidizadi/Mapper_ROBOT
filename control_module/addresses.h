#ifndef ADDRESSES_H
#define ADDRESSES_H

#include <Arduino.h>

/*
 * I²C Devices
 */
constexpr uint8_t OLED_ADDRESS        = 0x3C;
constexpr uint8_t MPU6050_ADDRESS     = 0x68;
constexpr uint8_t MOTOR_BOARD_ADDRESS = 0x10;
constexpr uint8_t WEB_BOARD_ADDRESS   = 0x11;

#endif