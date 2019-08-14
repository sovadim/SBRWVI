#include "head.h"
#include "chassis.h"
#include "hands.h"
#include "gyro.h"

/// Modules
Head *head;
Chassis *chassis;
Hands *hands;
Gyro *gyro;

void setup() {
  Serial.begin(9600);
  head = new Head();
  chassis = new Chassis();
  hands = new Hands();
  gyro = new Gyro();
}

void loop() {

  gyro->debug();

  /*for (int8_t i = -90; i < 90; ++i)
  {
    hands->set_rotation_shoulder_r(i);
    delay(10);
    Serial.print("Pos:");
    Serial.println(i);
  }
  hands->set_rotation_shoulder_r(0);
  delay(2000);*/
  //hands->set_rotation_shoulder_l(90);
  //delay(2000);
  //hands->set_rotation_shoulder_l(180);
  //delay(2000);
  //hands->set_rotation_shoulder_l(90);
  //delay(2000);


  //head_test();
  //chassis_test();
  //hands_test();


  for (int i = 0; i < 250; ++i)
  {
    chassis->set_speed(i);
    delay(50);
  }
  delay(3000);

  chassis->set_speed(0);
  delay(1500);
}

void info()
{
  /// Head
  //Serial.print();

  /// Chassis
  // Serial.print();

  /// Hands
  Hands::Info hands_info = hands->get_info();
  Serial.print("Left shoulder angle: ");
  Serial.println(hands_info.shoulder_angle_l);
  Serial.print("Right shoulder angle: ");
  Serial.println(hands_info.shoulder_angle_r);

  /// End of message
  Serial.println("/////////////////////////");
}
