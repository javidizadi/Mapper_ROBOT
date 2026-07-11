#pragma once
#include "Motor.h"

class MovementSystem {
private:
  const int _pin_standby;
  Motor motor_l, motor_r;

public:
  MovementSystem(Motor r, Motor l, int standby_pin)
    : motor_l(l), motor_r(r), _pin_standby(standby_pin) {
    pinMode(standby_pin, OUTPUT);
    wakeup();
  }

  void wakeup() {
    digitalWrite(_pin_standby, HIGH);
  }

  void standby() {
    digitalWrite(_pin_standby, LOW);
  }

  void forward(int speed) {
    motor_r.set_speed(abs(speed));
    motor_l.set_speed(-1 * abs(speed));
  }

  void backward(int speed) {
    motor_r.set_speed(-1 * abs(speed));
    motor_l.set_speed(abs(speed));
  }

  void drive(int speed_on_x) {
    motor_r.set_speed(speed_on_x);
    motor_l.set_speed(-1 * speed_on_x);
  }

  // TODO: rotation should be done with one only, currently does it with two
  void rotate(int speed_on_yaw) {
    // motor_l.set_speed(speed_on_yaw);
    // motor_r.set_speed(speed_on_yaw);

    // TURN LEFT
    if (speed_on_yaw >= 0) {
      motor_r.set_speed(speed_on_yaw);
    }
    // TURN RIGHT
    else {
      motor_l.set_speed(speed_on_yaw);
    }
  }

  void brake() {
    motor_l.brake();
    motor_r.brake();
  }
};
