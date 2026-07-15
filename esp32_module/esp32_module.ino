#include <Wire.h>
#include "web_server.h"
#include "movement_instruction_enum.h"

#define I2C_SCL 32
#define I2C_SDA 33

extern volatile MovementInstruction command_to_send;

void setup() {
  init_web_server();

  Wire.setPins(I2C_SDA, I2C_SCL);
  Wire.onRequest(I2C_onRequest);
  Wire.begin(0x10);
}

void loop() {
  request_handle_web_server();
  handleInstruction(command_to_send);
}

void I2C_onRequest() {
  Wire.write(command_to_send);
}
