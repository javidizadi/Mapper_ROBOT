#include <Arduino.h>

#include "debug.h"
#include "imu.h"


void debug_init()
{
    Serial.begin(115200);

    while (!Serial)
    {
        ;
    }

    Serial.println("=== Robot Brain Debug ===");
}


void debug_update()
{
    const IMUData& imu = imu_getData();

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
}