#include <Arduino.h>
#include "heartbeat.h"

static bool ledState = false;

void heartbeat_init()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

void heartbeat_update()
{
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
}