#pragma once

#include <AccelStepper.h>

class Head
{
public:
  explicit Head();

  void set_yaw();   // left / right
  void set_pitch(); // up   / down

private:
  int yaw;
  int pitch;

  void adjust_pitch();

  AccelStepper stepper;
};
