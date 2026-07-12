#include <Wire.h>
#include "MovementSystem.h"

// NOTE: Don't use pin 5 nor 6 as PWM pin, they've been used by millis or delay funciton, so they're inaccurate.

#define ML_CTRL_1 12
#define ML_CTRL_2 13
#define ML_PWM 9

#define MR_CTRL_1 7
#define MR_CTRL_2 8
#define MR_PWM 10

#define STANDBY_PIN 6

#define DEFAULT_MOTOR_SPEED 0.7 * 255

volatile bool isCommandArrived = false;

void setup() {
  Wire.begin(0x10);
  Wire.onReceive(I2C0_OnReceive);
}

void loop() {
  if (isCommandArrived) {
    isCommandArrived = false;
    handleInstruction();
  }
}

enum INSTRUCTION : uint8_t {
  FORWARD = 0x00,
  BACK = 0x01,
  TURN_RIGHT = 0x02,
  TURN_LEFT = 0x03,
  BRAKE = 0x04
};

MovementSystem movement_system(Motor(MR_CTRL_1, MR_CTRL_2, MR_PWM), Motor(ML_CTRL_1, ML_CTRL_2, ML_PWM), STANDBY_PIN);

void handleInstruction() {
  INSTRUCTION instr = Wire.read();
  switch (instr) {
    case INSTRUCTION::FORWARD:
      movement_system.drive(DEFAULT_MOTOR_SPEED);
      break;

    case INSTRUCTION::BACK:
      movement_system.drive(-1 * DEFAULT_MOTOR_SPEED);
      break;

    case INSTRUCTION::TURN_LEFT:
      movement_system.rotate(DEFAULT_MOTOR_SPEED);
      break;

    case INSTRUCTION::TURN_RIGHT:
      movement_system.rotate(-1 * DEFAULT_MOTOR_SPEED);
      break;

    case INSTRUCTION::BRAKE:
      movement_system.brake();
      break;

    default:
      break;
  }
}

void I2C0_OnReceive(int bytes_count) {
  if (bytes_count < 1) return;
  isCommandArrived = true;
}




