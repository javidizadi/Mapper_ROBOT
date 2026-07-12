#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "display.h"
#include "imu.h"
#include "ultrasonic.h"
#include "web_comm.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

static Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void display_init()
{
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    oled.clearDisplay();

    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);

    oled.setCursor(0, 0);
    oled.println("Robot Brain");
    oled.println("Starting...");

    oled.display();
}

void display_update()
{
    const IMUData &imu = imu_getData();

    oled.clearDisplay();

    oled.setCursor(0, 0);

    oled.print("CMD: ");

    switch(webComm_getCommand())
    {
        case FORWARD:
            oled.println("FORWARD");
            break;

        case BACKWARD:
            oled.println("BACKWARD");
            break;

        case TURN_LEFT:
            oled.println("LEFT");
            break;

        case TURN_RIGHT:
            oled.println("RIGHT");
            break;

        case BRAKE:
            oled.println("BRAKE");
            break;

        case NONE:
        default:
            oled.println("NONE");
            break;
    }

    oled.print("AX:");
    oled.println(imu.accelX);

    oled.print("AY:");
    oled.println(imu.accelY);

    oled.print("AZ:");
    oled.println(imu.accelZ);

    oled.print("GX:");
    oled.println(imu.gyroX);

    oled.print("GY:");
    oled.println(imu.gyroY);

    oled.print("GZ:");
    oled.println(imu.gyroZ);

    uint16_t distance = ultrasonic_getDistance();

    oled.print("D:");
    oled.print(distance);
    oled.println("cm");

    oled.display();
}