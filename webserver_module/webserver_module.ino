#include <Wire.h>
#include "web_server.h"

#define I2C_SCL 32
#define I2C_SDA 33

extern volatile COMMAND command_to_send;

void setup() {
  init_web_server();

  Wire.setPins(I2C_SDA, I2C_SCL);
  Wire.onRequest(I2C_onRequest);
  Wire.begin(0x10);
}

void loop() {
  request_handle_web_server();
}

void I2C_onRequest() {
  Wire.write(command_to_send);
}
