#pragma once

#include "../platform.h"

// COMMANDS
// Let all commands be 4 chars max
// Special
#define CORE "core"
#define TEST "test"
#define AGREE "agre"

// Hand
#define GRAB "grab"
#define RELEASE "rele"

namespace PARSER {

void parse(char *command, Platform *pl);

} // namespace PARCER