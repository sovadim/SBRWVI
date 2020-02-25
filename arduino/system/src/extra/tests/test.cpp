#include "test.h"
#include "../../constants.h"

namespace TESTS {

void all_modules(Platform *platform) {

    delay(2000);

    if (T_HEAD) {
        
        // DEBUG
        platform->head->set_yaw(1);
        delay(150);
        platform->head->set_yaw(0);

        platform->head->set_yaw(-1);
        delay(150);
        platform->head->set_yaw(0);

        // Pitch
        platform->head->set_pitch(100);
        delay(2000);

        platform->head->set_pitch(-100);
        delay(2000);
    }

    if (T_CHASSIS) {
        platform->chassis->set_speed(0.5);
        delay(1000);
        platform->chassis->set_speed(0.8);
        delay(1000);
        platform->chassis->set_speed(1.0);
        delay(1000);
        platform->chassis->set_speed(0.0);
    }

    if (T_SHOULDER) {

        Serial.print("20\n");
        platform->l_hand->set_rotation_shoulder(90 + 20, false);
        platform->r_hand->set_rotation_shoulder(90 + 20, true);
        delay(2000);

        Serial.print("180rted\n");
        platform->l_hand->set_rotation_shoulder(180, false);
        platform->r_hand->set_rotation_shoulder(90 + 90, true);
        delay(2000);

        Serial.print("SHOULDERS_START_POS\n");
        platform->l_hand->set_rotation_shoulder(SHOULDERS_START_POS, false);
        platform->r_hand->set_rotation_shoulder(SHOULDERS_START_POS, true);
        delay(2000);
    }

    if (T_FOREARM) {
        // Left hand
        platform->l_hand->forearm->start(false);
        delay(1500);
        platform->l_hand->forearm->stop();
        delay(500);
        platform->l_hand->forearm->start(true);
        delay(1500);
        platform->l_hand->forearm->stop();

        // Right hand
        platform->r_hand->forearm->start(false);
        delay(1500);
        platform->r_hand->forearm->stop();
        delay(500);
        platform->r_hand->forearm->start(true);
        delay(1500);
        platform->r_hand->forearm->stop();
    }

    if (T_WRIST) {
        // Left hand
        platform->l_hand->wrist->start(true);
        delay(1000);

        platform->l_hand->wrist->stop();
        delay(500);

        platform->l_hand->wrist->start(false);
        delay(1000);

        platform->l_hand->wrist->stop();

        // Roght hand
        platform->r_hand->wrist->start(true);
        delay(1000);
        
        platform->r_hand->wrist->stop();
        delay(500);

        platform->r_hand->wrist->start(false);
        delay(1000);

        platform->r_hand->wrist->stop();
    }
}

} // namespace TESTS

namespace MISSIONS {

void core(Platform *platform) {

    // Hand up
    platform->r_hand->forearm->start(false);
    delay(1500);
    platform->r_hand->forearm->stop();
    delay(1000);

    // Open grab
    platform->r_hand->wrist->start(true);
    delay(250);
    platform->r_hand->wrist->stop();
    delay(1500);

    // Take target - close grab
    platform->r_hand->wrist->start(false);
    delay(2500);
    platform->r_hand->wrist->stop();
    delay(1000);

    // Hand forward
    platform->r_hand->forearm->start(true);
    platform->r_hand->set_rotation_shoulder(90 + 60, true);
    delay(2500);
    platform->r_hand->forearm->stop();
    platform->r_hand->set_rotation_shoulder(90 + 75, true);

    delay(5000);

    // Release target
    platform->r_hand->wrist->start(true);
    delay(500);
    platform->r_hand->wrist->stop();

}

}