#include <Arduino.h>

#include "debug.h"
#include "imu.h"
#include "web_comm.h"

void debug_init() {
  Serial.begin(115200);

  while (!Serial) {
    ;
  }

  Serial.println("=== Robot Brain Debug ===");
}

void debug_update() {
  const IMUData &imu = imu_getData();

  Serial.print("AX=");
  Serial.print(imu.accelX);

  Serial.print(" AY=");
  Serial.print(imu.accelY);

  Serial.print(" AZ=");
  Serial.print(imu.accelZ);

  Serial.print(" GX=");
  Serial.print(imu.gyroX);

  Serial.print(" GY=");
  Serial.print(imu.gyroY);

  Serial.print(" GZ=");
  Serial.println(imu.gyroZ);

  COMMAND cmd = webComm_getCommand();

  Serial.print("CMD=");

  switch (cmd) {
  case FORWARD:
    Serial.print("FORWARD");
    break;

  case BACKWARD:
    Serial.print("BACKWARD");
    break;

  case TURN_LEFT:
    Serial.print("TURN_LEFT");
    break;

  case TURN_RIGHT:
    Serial.print("TURN_RIGHT");
    break;

  case BRAKE:
    Serial.print("BRAKE");
    break;

  default:
    Serial.print("NONE");
    break;
  }

  Serial.println();
}
