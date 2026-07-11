#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

/*
 * Servo
 */
constexpr uint8_t SERVO_PIN = 9;

/*
 * Ultrasonic Sensor (HC-SR04)
 */
constexpr uint8_t ULTRASONIC_TRIGGER_PIN = 7;
constexpr uint8_t ULTRASONIC_ECHO_PIN    = 8;

#endif