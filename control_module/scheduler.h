#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>

struct Task
{
    unsigned long previousTime;
    unsigned long period;
    void (*callback)();
};

void scheduler_init();
void scheduler_run();

#endif