#include "Motor_L293D.h"

Motor_L293D::Motor_L293D(int pwmPin, int directionPin) {
  _pwmPin = pwmPin;
  _directionPin = directionPin; 
  _disabled = false;
  _speed = 0;
  pinMode(_pwmPin, OUTPUT);
  analogWrite(_pwmPin, _speed);    // stop motor
  pinMode(_directionPin, OUTPUT);
  digitalWrite(_directionPin, MOTOR_FORWARD);
}

void Motor_L293D::setSpeed(int speed) {
  if (_disabled) {
    return;
  }

  // smooth out speed
  // https://stackoverflow.com/questions/12636613/how-to-calculate-moving-average-without-keeping-the-count-and-data-total
  // https://electronics.stackexchange.com/questions/219633/smooth-a-dc-motor-movement/219743
  // https://electronics.stackexchange.com/questions/38573/smooth-a-motor-movement

  _speed -= _speed / SPEED_SAMPLES;
  _speed += (float) speed / SPEED_SAMPLES;

  _direction = _speed < 0 ? MOTOR_BACKWARD : MOTOR_FORWARD;
  _speed = constrain(_speed, -PWMRANGE, PWMRANGE);

  // DEADBAND compensation
  // see http://engineeronadisk.com/V3/engineeronadisk-230.html
  // if (_speed != 0 && abs(_speed) < STICTION_COMPENSATION) {   // if speed within motor deadband bump up speed
  //   _speed = STICTION_COMPENSATION;
  // }

  digitalWrite(_directionPin, _direction);
  analogWrite(_pwmPin, (int) abs(_speed));
}