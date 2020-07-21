#pragma once

#include "../auxiliary/dcmotor.h"
#include "../auxiliary/encoder.h"

class Chassis {
 public:
  explicit Chassis(Pins pins_l, Pins pins_r);

  void set_speed(double speed);

 private:
  DCMotor* l_motor;
  DCMotor* r_motor;

  Encoder* l_encoder;
  Encoder* r_encoder;
};
