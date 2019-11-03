#pragma once

#include "Arduino.h"
#include "dcmotor.h"

class LinearDrive
{
public:
    explicit LinearDrive(Pins pins);
    ~LinearDrive();

    // Set linear in opened / closed state
    void open();
    void close();

    // Enable / disable motor rotation
    // bool direction:
    // - true: move to 1.0 position (opened)
    // - false: move to 0.0 position (closed)
    void start(bool direction);
    void stop();

    // Set position between opened / closed state
    // double position:
    // 0.0 (closed) < position < 1.0 (opened)
    void set_position(double position);

    // Set speed of motor rotation
    // double speed:
    // 0.0 (disabled) < speed < 1.0 (MAX_SPEED)
    void set_speed(double speed);

private:
    DCMotor* motor;
    bool opened;
    unsigned speed;
    const static unsigned MAX_SPEED = HIGH;
};


