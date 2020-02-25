#include "platform.h"
#include "constants.h"
#include "Arduino.h"

Platform::Platform()
{
    l_hand = new Hand(SRV_PIN_L, SHOULDERS_START_POS,
                {IN_LEFT_EL_L, IN_LEFT_EL_R, EN_LEFT_EL__},
                {IN_LEFT_WR_L, IN_LEFT_WR_R, EN_LEFT_WR__});

    r_hand = new Hand(SRV_PIN_R, SHOULDERS_START_POS,
                {IN_RIGHT_EL_L, IN_RIGHT_EL_R, EN_RIGHT_EL__},
                {IN_RIGHT_WR_L, IN_RIGHT_WR_R, EN_RIGHT_WR__});

    l_hand->set_rotation_shoulder(SHOULDERS_START_POS, false);
    r_hand->set_rotation_shoulder(SHOULDERS_START_POS, true);

    chassis = new Chassis({L_IN_F, L_IN_B, L_EN}, {R_IN_F, R_IN_B, R_EN});
    
    head = new Head({IN_YAW_L, IN_YAW_R, EN_YAW__},
                    {IN_PITCH_1, IN_PITCH_2, IN_PITCH_3, IN_PITCH_4});
}

Platform::~Platform() {

    delete l_hand;
    delete r_hand;
    delete chassis;
    delete head;
}