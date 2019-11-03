#include "hand.h"
#include "Arduino.h"
 
Hand::Hand(unsigned pin_SRV, unsigned srv_start_pos, Pins forearm_pins, Pins wrist_pins)
{
  shoulder.attach(pin_SRV);

  forearm = new LinearDrive(forearm_pins);

  wrist = new LinearDrive(wrist_pins);
}

void Hand::set_rotation_shoulder(unsigned angle, bool reverse)
{
  if (reverse) {
    if(angle > 180) {
      shoulder.write(180);
    } else {
      shoulder.write(angle);
    }
  } else {
    if(angle > 180) {
      shoulder.write(180 - 180);
    } else {
      shoulder.write(180 - angle);
    }
  }
}

void Hand::set_position_forearm(unsigned position)
{
  forearm->set_position(position);
}

void Hand::set_wrist_position(bool open)
{
  wrist->set_position(open);
}


/*int16_t Hands::get_translate_rotation_sh_l(int16_t angle)
{
  return 90 - angle;
}

int16_t Hands::get_translate_rotation_sh_r(int16_t angle)
{
  return 90 + angle;
}*/