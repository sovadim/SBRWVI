#include "chassis.h"
#include "Arduino.h"
#include "constants.h"

Chassis::Chassis()
{
  // MOTORS SETUP
  pinMode(L_IN_F, OUTPUT);
  pinMode(L_IN_B, OUTPUT);

  pinMode(R_IN_F, OUTPUT);
  pinMode(R_IN_B, OUTPUT);

  pinMode(L_EN, OUTPUT);
  pinMode(R_EN, OUTPUT);

  // ENCODERS SETUP
  /*pinMode();
  pinMode();
  
  pinMode();
  pinMode();*/
  
}

void Chassis::set_speed(unsigned int speed_rate)
{
  // ! DEBUG !
  digitalWrite(L_IN_F, HIGH);
  digitalWrite(L_IN_B, 0);
  
  digitalWrite(R_IN_F, HIGH);
  digitalWrite(R_IN_B, 0);
  
  analogWrite(L_EN, speed_rate);
  analogWrite(R_EN, speed_rate);
}

unsigned int Chassis::get_current_speed()
{
  
}
