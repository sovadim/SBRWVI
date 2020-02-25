#include "src/platform.h"
#include "src/extra/tests/test.h"
#include "src/extra/commandparser.h"
#include <string.h>

using namespace std;

// Whole system
Platform *platform;

// String command will be used for
// reading commands from serial port
String command;

// Prototypes
void command_parser();

// DEBUG
#define STEPS 32
Stepper stepper(STEPS, 8, 10, 9, 11);
int val;

void setup() {
  Serial.begin(9600);
  //while (!Serial.available());
  
  platform = new Platform();
  delay(1000);
  // DEBUG
  val = 0;
  stepper.setSpeed(200);
}

void loop() {
  // DEBUG
  /*if (Serial.available() > 0)
  {
    val = Serial.parseInt();
    //stepper.step(val);
    platform->head->set_pitch(val);
    Serial.println(val); //for debugging
  }*/

  //platform->head->set_pitch(-100);
  //delay(2000);
  //platform->head->set_pitch(100);
  //platform->r_hand->forearm->start(false);
  //delay(2000);
  //platform->r_hand->forearm->stop();

  //command_parser();

  TESTS::all_modules(platform);
  //MISSIONS::core(platform);

  while (1) { delay(1000); }
}

void command_parser() {
  if (Serial.available() > 0) {
    command = Serial.readString();
    //data = Serial.read();
    
    PARSER::parse(command.c_str(), platform );

    if (command.c_str() == "grab\0") {
      Serial.print("TRUE: ");
    }

    Serial.print("r:");
    Serial.println(command);
  }
}
