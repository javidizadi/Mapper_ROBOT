#include "scheduler.h"

#include "debug.h"
#include "display.h"
#include "heartbeat.h"
#include "imu.h"
#include "motion_manager.h"
#include "motor_comm.h"
#include "servo.h"
#include "ultrasonic.h"
#include "web_comm.h"

static Task tasks[] = {
    {0, 20, webComm_update},     {0, 20, motionManager_update},
    {0, 20, motorComm_update},

    {0, 10, imu_update},         {0, 20, servo_update},
    {0, 100, ultrasonic_update},

    {0, 200, display_update},    {0, 500, debug_update},
    {0, 1000, heartbeat_update}};

static const byte TASK_COUNT = sizeof(tasks) / sizeof(tasks[0]);

void scheduler_init() {
  unsigned long now = millis();

  for (byte i = 0; i < TASK_COUNT; i++) {
    tasks[i].previousTime = now;
  }
}

void scheduler_run() {
  unsigned long now = millis();

  for (byte i = 0; i < TASK_COUNT; i++) {
    if (now - tasks[i].previousTime >= tasks[i].period) {
      tasks[i].previousTime = now;
      tasks[i].callback();
    }
  }
}
