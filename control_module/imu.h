#ifndef IMU_H
#define IMU_H

#include <Arduino.h>

struct IMUData
{
    int16_t accelX;
    int16_t accelY;
    int16_t accelZ;

    int16_t gyroX;
    int16_t gyroY;
    int16_t gyroZ;
};

void imu_init();
void imu_update();

const IMUData& imu_getData();

#endif