#define PIN_IN_A 26
#define PIN_IN_B 24
#define PIN_EN 22

void setup() {
    pinMode(PIN_IN_A, OUTPUT);
    pinMode(PIN_IN_B, OUTPUT);
    pinMode(PIN_EN, OUTPUT);

    digitalWrite(PIN_IN_A, LOW);
    digitalWrite(PIN_IN_B, LOW);
    digitalWrite(PIN_EN, LOW);
}

void loop() {
    // rotate
    digitalWrite(PIN_EN, HIGH);
    digitalWrite(PIN_IN_A, HIGH);
    digitalWrite(PIN_IN_B, LOW);
    delay(2000);

    // stop
    digitalWrite(PIN_EN, LOW);
    delay(2000);

    // rotate in another direction
    digitalWrite(PIN_EN, HIGH);
    digitalWrite(PIN_IN_A, LOW);
    digitalWrite(PIN_IN_B, HIGH);
    delay(2000);

    // stop
    digitalWrite(PIN_EN, LOW);
    delay(2000);
}
