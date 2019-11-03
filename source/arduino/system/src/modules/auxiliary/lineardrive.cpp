#include "lineardrive.h"

LinearDrive::LinearDrive(Pins pins) {
    motor = new DCMotor(pins);
    opened = 0;
}

LinearDrive::~LinearDrive() {
    delete motor;
}

void LinearDrive::open() {

}

void LinearDrive::close() {
    
}

void LinearDrive::set_position(double position) {

}

void LinearDrive::start(bool direction) {
    if (direction) {
        motor->set_speed(HIGH);
    } else {
        motor->set_speed(-1 * HIGH);
    }
}

void LinearDrive::stop() {
    motor->set_speed(0);
}