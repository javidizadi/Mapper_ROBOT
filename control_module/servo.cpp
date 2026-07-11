#include <Servo.h>

#include "servo.h"
#include "pins.h"


static Servo servoMotor;


static uint8_t currentAngle = 90;
static uint8_t targetAngle = 90;


constexpr uint8_t STEP_SIZE = 1;


void servo_init()
{
    servoMotor.attach(SERVO_PIN);

    servoMotor.write(currentAngle);
}


void servo_update()
{
    if(currentAngle == targetAngle)
    {
        return;
    }


    if(currentAngle < targetAngle)
    {
        currentAngle += STEP_SIZE;

        if(currentAngle > targetAngle)
        {
            currentAngle = targetAngle;
        }
    }
    else
    {
        currentAngle -= STEP_SIZE;

        if(currentAngle < targetAngle)
        {
            currentAngle = targetAngle;
        }
    }


    servoMotor.write(currentAngle);
}


void servo_setTarget(uint8_t angle)
{
    if(angle > 180)
    {
        angle = 180;
    }

    targetAngle = angle;
}


uint8_t servo_getAngle()
{
    return currentAngle;
}