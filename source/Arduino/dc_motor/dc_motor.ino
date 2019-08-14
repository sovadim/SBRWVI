int A_ph = 20;
//int B_ph = 21;

volatile int state_A = LOW;
//volatile int state_B = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(A_ph, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(A_ph), blink, CHANGE);
  //attachInterrupt(0, blink, CHANGE);
  Serial.write("Hello\n");
}

void loop() {
  //Serial.write("loop");
  //digitalWrite(A_ph, state_A);
}

void blink() {
  state_A = !state_A;
  Serial.write("Change\n");
}
