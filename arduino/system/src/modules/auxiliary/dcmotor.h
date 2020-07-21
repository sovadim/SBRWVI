#pragma once
#include "pins.h"

class DCMotor {
 public:
    explicit DCMotor(Pins pins);
    ~DCMotor();

    // Set speed of motor rotation
    void set_speed(int rate);

 private:
    Pins pins;
};
