#include "dcmotor.h"
#include "Arduino.h"

DCMotor::DCMotor(Pins pins) {
    this->pins.a = pins.a;
    this->pins.b = pins.b;
    this->pins.en = pins.en;

    pinMode(pins.a, OUTPUT);
    pinMode(pins.b, OUTPUT);
    pinMode(pins.en, OUTPUT);

    // digitalWrite(pins.en, HIGH);
}

void DCMotor::set_speed(int rate) {
    // 0 speed disables enable output
    if (0 != rate) {
        digitalWrite(pins.en, rate);
    } else {
        digitalWrite(pins.en, rate);
    }

    digitalWrite(pins.en, HIGH);
    if (rate > 0) {
        digitalWrite(pins.a, rate);
        digitalWrite(pins.b, 0);
    } else {
        digitalWrite(pins.a, 0);
        digitalWrite(pins.b, -1 * rate);
    }
}

DCMotor::~DCMotor() {}
