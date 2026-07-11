#include <Arduino.h>

#include "ultrasonic.h"
#include "pins.h"


static uint16_t distanceCM = 0;


void ultrasonic_init()
{
    pinMode(ULTRASONIC_TRIGGER_PIN, OUTPUT);
    pinMode(ULTRASONIC_ECHO_PIN, INPUT);

    digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);
}


void ultrasonic_update()
{
    /*
     * Send 10us trigger pulse
     */

    digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(ULTRASONIC_TRIGGER_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);


    /*
     * Measure echo time
     *
     * Timeout:
     * 30000us ≈ 5 meters
     */

    unsigned long duration =
        pulseIn(
            ULTRASONIC_ECHO_PIN,
            HIGH,
            30000
        );


    if(duration == 0)
    {
        distanceCM = 0;
        return;
    }


    /*
     * Sound speed:
     *
     * distance(cm) = time(us) / 58
     */

    distanceCM = duration / 58;
}


uint16_t ultrasonic_getDistance()
{
    return distanceCM;
}