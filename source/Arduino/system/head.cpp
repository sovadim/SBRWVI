#include "head.h"
#include "Arduino.h"
#include "constants.h"

Head::Head()
{
  /// YAW
  pinMode(IN_YAW_L, OUTPUT);
  pinMode(IN_YAW_R, OUTPUT);
  pinMode(EN_YAW__, OUTPUT);

  /// PITCH
  //stepper;
  AccelStepper stepper(4, IN_PITCH_1, IN_PITCH_2, IN_PITCH_3, IN_PITCH_4);
  
  /// ENCODERS
  yaw = 0;
  pitch = 0;
  
  pinMode(ENC_YAW_A, INPUT_PULLUP);
  pinMode(ENC_YAW_B, INPUT_PULLUP);
  
}

void Head::set_yaw()
{
  
}

void Head::set_pitch()
{
  
}

void Head::adjust_pitch()
{
  
}
