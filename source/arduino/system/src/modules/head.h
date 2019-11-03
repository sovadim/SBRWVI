#pragma once

#include <Stepper.h>
#include "auxiliary/dcmotor.h"

class Head
{
public:
  explicit Head(Pins yaw_pins, Pins4 pitch_pins);

  // left / right
  void set_yaw(int angle);
  // up / down 
  void set_pitch(int angle);

private:

  // Motor for yaw control
  DCMotor *motor_yaw;
  
  // Motor for push control
  Stepper *motor_pitch;
  
  int yaw;
  int pitch;

  void adjust_pitch();

};
