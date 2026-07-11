#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>

void servo_init();

void servo_update();

void servo_setTarget(uint8_t angle);

uint8_t servo_getAngle();

#endif