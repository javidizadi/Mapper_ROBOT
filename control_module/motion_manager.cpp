#include "motion_manager.h"

#include "servo.h"
#include "web_comm.h"

void motionManager_init() { servo_setTarget(90); }

void motionManager_update() {
  COMMAND command = webComm_getCommand();

  switch (command) {
  case FORWARD:

    servo_setTarget(90);

    break;

  case BACKWARD:

    servo_setTarget(90);

    break;

  case TURN_LEFT:

    servo_setTarget(0);

    break;

  case TURN_RIGHT:

    servo_setTarget(180);

    break;

  case BRAKE:

    servo_setTarget(90);

    break;

  case NONE:

  default:

    break;
  }
}
