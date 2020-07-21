#pragma once
#include "sensivity/position/gyro.h"
#include "modules/chassis/chassis.h"
#include "modules/hand/hand.h"
#include "modules/head.h"

class Platform {
 public:
    Platform();
    ~Platform();

    Hand* l_hand;
    Hand* r_hand;
    Chassis* chassis;
    Head* head;
};
