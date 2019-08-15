#include "Arduino.h"

#ifndef MOTOR_L293D_H
#define MOTOR_L293D_H

#define MOTOR_FORWARD LOW
#define MOTOR_BACKWARD HIGH
#define SPEED_SAMPLES 150

// Motors have a voltage deadband where no movement occurs. STICTION_COMPENSATION 
// avoids the deadband by bumping up low speeds to the STICTION_COMPENSATION value.
#define STICTION_COMPENSATION 350   // PWM bias to start initial motion

class Motor_L293D
{
  public: 
    Motor_L293D(int pwmPin, int directionPin);    
    void setSpeed(int speed);
    // void stop();
    float _speed = 0;
    int _direction;
      
  private: 
    int _pwmPin;
    int _directionPin;
    bool _disabled;
};

#endif