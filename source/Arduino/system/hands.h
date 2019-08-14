#pragma once

#include "constants.h"
#include <Servo.h>

class Hands
{
public:
  explicit Hands();

  /// Shoulders
  void set_rotation_shoulder_l(int16_t angle);
  void set_rotation_shoulder_r(int16_t angle);

  /// Elbows
  void rotate_elbow_l(unsigned char angle);
  void rotate_elbow_r(unsigned char angle);

  /// Wrists
  void rotate_wrist_l(unsigned char angle);
  void rotate_wrist_r(unsigned char angle);

  /// Info
  struct Info
  {
    unsigned char shoulder_angle_l;
    unsigned char shoulder_angle_r;
  };

  Info get_info();


private:
  Servo shoulder_servo_l;
  Servo shoulder_servo_r;

  int16_t get_translate_rotation_sh_l(int16_t angle);
  int16_t get_translate_rotation_sh_r(int16_t angle);

  Info *info;
};
