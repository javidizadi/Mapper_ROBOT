#include <Wire.h>

#include "addresses.h"
#include "web_comm.h"

static COMMAND currentCommand = NONE;

void webComm_init() { Wire.begin(); }

void webComm_update() {
  Wire.requestFrom(WEB_BOARD_ADDRESS, (uint8_t)1);

  if (Wire.available()) {
    currentCommand = (COMMAND)Wire.read();
  }
}

COMMAND webComm_getCommand() { return currentCommand; }
