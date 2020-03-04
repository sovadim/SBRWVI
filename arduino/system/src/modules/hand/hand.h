#pragma once

#include "../auxiliary/dcmotor.h"
#include "../auxiliary/lineardrive.h"
#include <Servo.h>

class Hand {
 public:
  explicit Hand(unsigned pin_SRV, unsigned srv_start_pos,
                Pins forearm_pins, Pins wrist_pins);
  ~Hand();

  void set_rotation_shoulder(unsigned angle, bool reverse);
  void set_position_forearm(unsigned position);
  void set_wrist_position(bool open);

  LinearDrive * forearm;
  LinearDrive * wrist;

 private:
  Servo shoulder;
};
