#include "src/platform.h"
#include "src/extra/tests/test.h"

Platform *platform;

void setup() {
  Serial.begin(9600);
  
  platform = new Platform();
}

void loop() {

  //TESTS::all_modules(platform);
  MISSIONS::core(platform);

  while (1) { delay(1000); }
}
