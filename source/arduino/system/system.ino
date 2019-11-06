#include "src/platform.h"
#include "src/extra/tests/test.h"
#include <string.h>

using namespace std;

// Whole system
Platform *platform;

// String command will be used for
// reading commands from serial port
String command;

// Prototypes
void command_parser();

void setup() {
  Serial.begin(9600);
  while (!Serial.available());
  
  platform = new Platform();
}

void loop() {

  command_parser();

  //TESTS::all_modules(platform);
  //MISSIONS::core(platform);

  //while (1) { delay(1000); }
}

void command_parser() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('>');
    //data = Serial.read();
    
    Serial.print("r:");
    Serial.println(command);
  }
}
