#pragma once

#include "Arduino.h"
#include "../../platform.h"

#define T_HEAD 1

#define T_CHASSIS 0

#define T_SHOULDER 0
#define T_FOREARM 0
#define T_WRIST 0

namespace TESTS {

void all_modules(Platform *platform);


} // namespace TESTS

namespace MISSIONS {

void core(Platform *platform);

} // namespace MISSIONS