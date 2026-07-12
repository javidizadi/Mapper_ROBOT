#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "robot_types.h"

void stateMachine_init();

void stateMachine_update();

void stateMachine_postEvent(RobotEvent event);

RobotState stateMachine_getState();

#endif
