#pragma once

class Chassis
{
public:
  explicit Chassis();

  void set_speed(unsigned int speed_rate);
  unsigned int get_current_speed();
};
