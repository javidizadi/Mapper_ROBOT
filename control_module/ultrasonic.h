#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

void ultrasonic_init();

void ultrasonic_update();

uint16_t ultrasonic_getDistance();

#endif