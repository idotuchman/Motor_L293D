#include <Motor_L293D.h>    // https://github.com/idotuchman/Motor_L293D

const int MOTOR_A_PWM_PIN = D1;
const int MOTOR_A_DIRECTION_PIN = D3; // low for forward
const int MOTOR_B_PWM_PIN = D2; 
const int MOTOR_B_DIRECTION_PIN = D4; // low for forward

Motor_L293D leftMotor(MOTOR_A_PWM_PIN, MOTOR_A_DIRECTION_PIN);    // motorA = left motor viewed from back
Motor_L293D rightMotor(MOTOR_B_PWM_PIN, MOTOR_B_DIRECTION_PIN);   // motorB = right motor viewed from back

void setup() {}

void loop() {
  int i;

  for(i = 0; i < 2000; i++) {
    rightMotor.setSpeed(1024);
    leftMotor.setSpeed(1024);
    delay(1);
  }

  for(i = 0; i < 2000; i++) {
    rightMotor.setSpeed(-1024);
    leftMotor.setSpeed(-1024);
    delay(1);
  }

  delay(0);
}