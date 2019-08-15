#include "hands.h"
#include "Arduino.h"

Hands::Hands()
{
  /// SHOULDERS
  shoulder_servo_l.attach(SRV_PIN_L);
  shoulder_servo_r.attach(SRV_PIN_R);

  shoulder_servo_l.write(SHOULDERS_START_POS);
  shoulder_servo_r.write(SHOULDERS_START_POS);

  /// ELBOWS
  pinMode(IN_LEFT_EL_L, OUTPUT);
  pinMode(IN_LEFT_EL_R, OUTPUT);
  pinMode(EN_LEFT_EL__, OUTPUT);

  pinMode(IN_RIGHT_EL_L, OUTPUT);
  pinMode(IN_RIGHT_EL_R, OUTPUT);
  pinMode(EN_RIGHT_EL__, OUTPUT);

  /// WRISTS
  pinMode(IN_LEFT_WR_L, OUTPUT);
  pinMode(IN_LEFT_WR_R, OUTPUT);
  pinMode(EN_LEFT_WR__, OUTPUT);

  pinMode(IN_RIGHT_WR_L, OUTPUT);
  pinMode(IN_RIGHT_WR_R, OUTPUT);
  pinMode(EN_RIGHT_WR__, OUTPUT);

  /*/// INFO
  info = new Info();
  info->shoulder_angle_l = SHOULDERS_START_POS;
  info->shoulder_angle_r = SHOULDERS_START_POS;*/

  set_rotation_shoulder_l(get_translate_rotation_sh_l(SHOULDERS_START_POS));
  set_rotation_shoulder_r(get_translate_rotation_sh_r(SHOULDERS_START_POS));
}

/// Shoulders
void Hands::set_rotation_shoulder_l(int16_t angle)
{
  angle = get_translate_rotation_sh_l(angle);
  
  if(angle > 180)
  {
    shoulder_servo_l.write(180);
    info->shoulder_angle_l = 180;
  }
  else
  {
    shoulder_servo_l.write(angle);
    info->shoulder_angle_l = angle;
  } 
}

void Hands::set_rotation_shoulder_r(int16_t angle)
{
  angle = get_translate_rotation_sh_r(angle);
  
  if(angle > 180)
  {
    shoulder_servo_r.write(180);
    info->shoulder_angle_r = 180;
  }
  else
  {
    shoulder_servo_r.write(angle);
    info->shoulder_angle_r = angle;
  }  
}

int16_t Hands::get_translate_rotation_sh_l(int16_t angle)
{
  return 90 - angle;
}

int16_t Hands::get_translate_rotation_sh_r(int16_t angle)
{
  return 90 + angle;
}

/// Elbows
void Hands::rotate_elbow_l(unsigned char angle)
{
  
}

void Hands::rotate_elbow_r(unsigned char angle)
{
  
}

/// Wrists
void Hands::rotate_wrist_l(unsigned char angle)
{
  
}

void Hands::rotate_wrist_r(unsigned char angle)
{
  
}

/// Info
Hands::Info Hands::get_info()
{
  return *info;
}
