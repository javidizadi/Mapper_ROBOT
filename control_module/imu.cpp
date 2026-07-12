#include <Wire.h>

#include "addresses.h"
#include "imu.h"

constexpr uint8_t PWR_MGMT_1 = 0x6B;
constexpr uint8_t ACCEL_XOUT_H = 0x3B;

static IMUData imuData;

static int16_t readInt16() {
  int16_t high = Wire.read();
  int16_t low = Wire.read();

  return (high << 8) | low;
}

void imu_init() {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission();
}

void imu_update() {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU6050_ADDRESS, (uint8_t)14);

  imuData.accelX = readInt16();
  imuData.accelY = readInt16();
  imuData.accelZ = readInt16();

  // Skip temperature
  Wire.read();
  Wire.read();

  imuData.gyroX = readInt16();
  imuData.gyroY = readInt16();
  imuData.gyroZ = readInt16();
}

const IMUData &imu_getData() { return imuData; }
