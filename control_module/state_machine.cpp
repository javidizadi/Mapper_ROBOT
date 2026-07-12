#include "state_machine.h"

// Future includes:
//
// #include "sensor_manager.h"
// #include "motion_manager.h"

static RobotState currentState = RobotState::STARTUP;

static RobotEvent pendingEvent = RobotEvent::NONE;

static void enterState(RobotState state) {
  switch (state) {
  case RobotState::STARTUP:

    // sensorManager_setMode(OFF);
    // motionManager_setMode(STOP);

    break;

  case RobotState::IDLE:

    // sensorManager_setMode(OFF);
    // motionManager_setMode(STOP);

    break;

  case RobotState::EXPLORE:

    // sensorManager_setMode(FORWARD);
    // motionManager_setMode(FORWARD);

    break;

  case RobotState::FOLLOW_LEFT_WALL:

    // sensorManager_setMode(FOLLOW_LEFT);
    // motionManager_setMode(FOLLOW_LEFT_WALL);

    break;

  case RobotState::FOLLOW_RIGHT_WALL:

    // sensorManager_setMode(FOLLOW_RIGHT);
    // motionManager_setMode(FOLLOW_RIGHT_WALL);

    break;

  case RobotState::TURN_LEFT:

    // sensorManager_setMode(OFF);
    // motionManager_setMode(TURN_LEFT);

    break;

  case RobotState::TURN_RIGHT:

    // sensorManager_setMode(OFF);
    // motionManager_setMode(TURN_RIGHT);

    break;

  case RobotState::TURN_AROUND:

    // sensorManager_setMode(OFF);
    // motionManager_setMode(TURN_AROUND);

    break;

  case RobotState::STOPPED:

    // sensorManager_setMode(OFF);
    // motionManager_setMode(STOP);

    break;

  case RobotState::ERROR:

    // sensorManager_setMode(OFF);
    // motionManager_setMode(STOP);

    break;
  }
}

void stateMachine_init() {
  currentState = RobotState::STARTUP;

  enterState(currentState);
}

void stateMachine_postEvent(RobotEvent event) { pendingEvent = event; }

RobotState stateMachine_getState() { return currentState; }

void stateMachine_update() {
  if (pendingEvent == RobotEvent::NONE) {
    return;
  }

  RobotState nextState = currentState;

  switch (currentState) {
  case RobotState::STARTUP:

    if (pendingEvent == RobotEvent::START) {
      nextState = RobotState::EXPLORE;
    }

    break;

  case RobotState::IDLE:

    if (pendingEvent == RobotEvent::START) {
      nextState = RobotState::EXPLORE;
    }

    break;

  case RobotState::EXPLORE:

    if (pendingEvent == RobotEvent::FRONT_BLOCKED) {
      nextState = RobotState::TURN_LEFT;
    } else if (pendingEvent == RobotEvent::WALL_FOUND) {
      nextState = RobotState::FOLLOW_LEFT_WALL;
    }

    break;

  case RobotState::FOLLOW_LEFT_WALL:

    if (pendingEvent == RobotEvent::FRONT_BLOCKED) {
      nextState = RobotState::TURN_RIGHT;
    } else if (pendingEvent == RobotEvent::WALL_LOST) {
      nextState = RobotState::EXPLORE;
    }

    break;

  case RobotState::FOLLOW_RIGHT_WALL:

    if (pendingEvent == RobotEvent::FRONT_BLOCKED) {
      nextState = RobotState::TURN_LEFT;
    } else if (pendingEvent == RobotEvent::WALL_LOST) {
      nextState = RobotState::EXPLORE;
    }

    break;

  case RobotState::TURN_LEFT:
  case RobotState::TURN_RIGHT:
  case RobotState::TURN_AROUND:

    if (pendingEvent == RobotEvent::TURN_COMPLETE) {
      nextState = RobotState::EXPLORE;
    }

    break;

  case RobotState::STOPPED:

    if (pendingEvent == RobotEvent::START) {
      nextState = RobotState::EXPLORE;
    }

    break;

  case RobotState::ERROR:

    break;
  }

  pendingEvent = RobotEvent::NONE;

  if (nextState != currentState) {
    currentState = nextState;
    enterState(currentState);
  }
}
