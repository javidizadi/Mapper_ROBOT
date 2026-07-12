#ifndef WEB_COMM_H
#define WEB_COMM_H

#include <Arduino.h>

enum COMMAND : uint8_t {
  FORWARD = 0x00,
  BACKWARD = 0x01,
  TURN_RIGHT = 0x02,
  TURN_LEFT = 0x03,
  BRAKE = 0x04,
  NONE = 0x05
};

void webComm_init();

void webComm_update();

COMMAND webComm_getCommand();

#endif
