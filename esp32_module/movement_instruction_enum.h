#pragma once
enum MovementInstruction : uint8_t {
  FORWARD = 0x00,
  BACKWARD = 0x01,
  TURN_RIGHT = 0x02,
  TURN_LEFT = 0x03,
  BRAKE = 0x04,
  NONE = 0x05
};
