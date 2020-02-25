#include "head.h"
#include "Arduino.h"

Head::Head(Pins yaw_pins, Pins4 pitch_pins) {

  /// PITCH
  //stepper;
  motor_pitch = new Stepper(4, pitch_pins.in1, pitch_pins.in3,
                              pitch_pins.in2, pitch_pins.in4);  

  motor_pitch->setSpeed(800);
  /// ENCODERS
  //yaw = 0;
  //pitch = 0;
  
  //pinMode(ENC_YAW_A, INPUT_PULLUP);
  //pinMode(ENC_YAW_B, INPUT_PULLUP);
  
  motor_yaw = new DCMotor(yaw_pins);
}

// <-- --> DEBUG VERSION
void Head::set_yaw(int angle) {
  // DEBUG
  if (0 == angle) {
    motor_yaw->set_speed(0);
  } else if (0 < angle) {
    motor_yaw->set_speed(HIGH);
  } else {
    motor_yaw->set_speed(-1 * HIGH);
  }
}

// | |
void Head::set_pitch(int angle) {
  motor_pitch->step(angle);
}

void Head::adjust_pitch() {
  
}
