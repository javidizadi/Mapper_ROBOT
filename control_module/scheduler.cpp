#include "scheduler.h"

static void heartbeat_task();

static Task tasks[] =
{
    {0, 1000, heartbeat_task}
};

static const byte TASK_COUNT = sizeof(tasks) / sizeof(tasks[0]);

static void heartbeat_task()
{
    static bool ledState = false;

    ledState = !ledState;

    digitalWrite(LED_BUILTIN, ledState);
}

void scheduler_init()
{
    pinMode(LED_BUILTIN, OUTPUT);

    unsigned long now = millis();

    for (byte i = 0; i < TASK_COUNT; i++)
    {
        tasks[i].previousTime = now;
    }
}

void scheduler_run()
{
    unsigned long now = millis();

    for (byte i = 0; i < TASK_COUNT; i++)
    {
        if (now - tasks[i].previousTime >= tasks[i].period)
        {
            tasks[i].previousTime = now;
            tasks[i].callback();
        }
    }
}