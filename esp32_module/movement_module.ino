#pragma once
#include "MovementSystem.h"
#include "movement_instruction_enum.h"

#define ML_CTRL_1 13
#define ML_CTRL_2 15
#define ML_PWM 21

#define MR_CTRL_1 2
#define MR_CTRL_2 0
#define MR_PWM 21

#define STANDBY_PIN 4

#define DEFAULT_MOTOR_SPEED 0.7 * 255

MovementSystem movement_system(Motor(MR_CTRL_1, MR_CTRL_2, MR_PWM), Motor(ML_CTRL_1, ML_CTRL_2, ML_PWM), STANDBY_PIN);

void handleInstruction(MovementInstruction instr) {
  switch (instr) {
    case MovementInstruction::FORWARD:
      movement_system.drive(DEFAULT_MOTOR_SPEED);
      break;

    case MovementInstruction::BACKWARD:
      movement_system.drive(-1 * DEFAULT_MOTOR_SPEED);
      break;

    case MovementInstruction::TURN_LEFT:
      movement_system.rotate(DEFAULT_MOTOR_SPEED);
      break;

    case MovementInstruction::TURN_RIGHT:
      movement_system.rotate(-1 * DEFAULT_MOTOR_SPEED);
      break;

    case MovementInstruction::BRAKE:
      movement_system.brake();
      break;

    default:
      break;
  }
}




