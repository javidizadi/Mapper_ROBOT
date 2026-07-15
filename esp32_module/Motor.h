#pragma once

class Motor {
private:
  int _pin_ctrl_1;
  int _pin_ctrl_2;
  int _pin_pwm;

  bool isValidSpeed(int speed) {
    return speed >= -255 && speed <= 255;
  }

public:
  Motor(int ctrl1_pin, int ctrl2_pin, int pwm_pin)
    : _pin_ctrl_1(ctrl1_pin), _pin_ctrl_2(ctrl2_pin), _pin_pwm(pwm_pin) {
    pinMode(ctrl1_pin, OUTPUT);
    pinMode(ctrl2_pin, OUTPUT);
    pinMode(pwm_pin, OUTPUT);

    digitalWrite(ctrl1_pin, LOW);
    digitalWrite(ctrl2_pin, LOW);
    analogWrite(pwm_pin, 0);
  }

  void clockwise() {
    digitalWrite(_pin_ctrl_1, LOW);
    digitalWrite(_pin_ctrl_2, HIGH);
  }

  void counter_clockwise() {
    digitalWrite(_pin_ctrl_1, HIGH);
    digitalWrite(_pin_ctrl_2, LOW);
  }

  void brake() {
    digitalWrite(_pin_ctrl_1, HIGH);
    digitalWrite(_pin_ctrl_2, HIGH);
    analogWrite(_pin_pwm, 0);
  }

  // Positive Speed: clockwise rotation
  // Negative Speed: counter clockwise rotation
  void set_speed(int speed) {
    if (!isValidSpeed(speed)) {
      this->brake();
      return;
    }

    if (speed < 0)
      this->counter_clockwise();
    else
      this->clockwise();

    analogWrite(_pin_pwm, abs(speed));
  }
};