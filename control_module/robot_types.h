#ifndef ROBOT_TYPES_H
#define ROBOT_TYPES_H

#include <Arduino.h>

enum class RobotState {
  STARTUP,

  IDLE,

  EXPLORE,

  FOLLOW_LEFT_WALL,
  FOLLOW_RIGHT_WALL,

  TURN_LEFT,
  TURN_RIGHT,
  TURN_AROUND,

  STOPPED,

  ERROR
};

enum class RobotEvent {
  NONE,

  START,
  STOP,

  FRONT_BLOCKED,
  FRONT_CLEAR,

  WALL_FOUND,
  WALL_LOST,

  TURN_COMPLETE,

  SENSOR_FAILURE
};

enum class SensorMode {
  OFF,

  FORWARD,

  FOLLOW_LEFT,
  FOLLOW_RIGHT
};

enum class MotionMode {
  STOP,

  FORWARD,

  FOLLOW_LEFT_WALL,
  FOLLOW_RIGHT_WALL,

  TURN_LEFT,
  TURN_RIGHT,
  TURN_AROUND
};

#endif
