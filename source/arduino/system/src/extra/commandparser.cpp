#include "commandparser.h"
#include "tests/test.h"
#include "Arduino.h"

namespace PARSER {

void parse(char *command, Platform *pl) {

    if (NULL != strstr(command, CORE)) {
        MISSIONS::core(pl);
    }
    else
    if (NULL != strstr(command, TEST)) {
        TESTS::all_modules(pl);
    }
    else
    if (NULL != strstr(command, RELEASE)) {
        pl->r_hand->wrist->start(true);
        delay(1000);
        pl->r_hand->wrist->stop();
    }
    else
    if (NULL != strstr(command, GRAB)) {
        pl->r_hand->wrist->start(false);
        delay(1000);
        pl->r_hand->wrist->stop();
    }
    else
    if (NULL != strstr(command, AGREE)) {
        pl->r_hand->wrist->start(false);
        delay(1000);
        pl->r_hand->wrist->stop();
    }

}

} // namespace PARCER