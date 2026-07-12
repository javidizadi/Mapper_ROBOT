#include <Arduino.h>
#include <Wire.h>

#include "addresses.h"
#include "motor_comm.h"
#include "web_comm.h"

void motorComm_init() {}

void motorComm_update() {
  COMMAND command = webComm_getCommand();

  Wire.beginTransmission(MOTOR_BOARD_ADDRESS);

  Wire.write(static_cast<uint8_t>(command));

  Wire.endTransmission();
}
