#include "scheduler.h"

#include "heartbeat.h"
#include "web_comm.h"
#include "motor_comm.h"
#include "motion_manager.h"
#include "imu.h"
#include "servo.h"
#include "ultrasonic.h"
#include "display.h"
#include "debug.h"

void setup()
{
    heartbeat_init();

    webComm_init();
    motorComm_init();

    motionManager_init();

    imu_init();

    servo_init();

    ultrasonic_init();

    display_init();

    debug_init();

    scheduler_init();
}

void loop()
{
    scheduler_run();
}
