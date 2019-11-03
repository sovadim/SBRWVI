#include "chassis.h"
#include "Arduino.h"

Chassis::Chassis(Pins pins_l, Pins pins_r)
{
  l_motor = new DCMotor(pins_l);
  r_motor = new DCMotor(pins_r);

  //l_encoder
  //r_encoder
}

void Chassis::set_speed(double speed)
{
  l_motor->set_speed(speed * HIGH);
  r_motor->set_speed(-1 * speed * HIGH);
}