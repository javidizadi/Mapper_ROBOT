#include "scheduler.h"

#include "heartbeat.h"
#include "comm.h"
#include "imu.h"
#include "debug.h"
#include "display.h"


void setup()
{
    heartbeat_init();

    debug_init();

    comm_init();
    imu_init();

    display_init();

    scheduler_init();
}


void loop()
{
    scheduler_run();
}