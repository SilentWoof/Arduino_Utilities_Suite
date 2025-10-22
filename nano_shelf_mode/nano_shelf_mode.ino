// === Shelf Mode: Safe Idle Sketch ===
// Sets all digital pins to OUTPUT LOW and analog pins to INPUT
// No serial, no blinking, no floating pins

void setup() {
  // Set all digital pins (except D0/D1) to OUTPUT LOW
  for (int pin = 2; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  // Set analog pins A0–A5 to INPUT (safe default)
  for (int pin = A0; pin <= A5; pin++) {
    pinMode(pin, INPUT);
  }

  // Optional: disable PWM outputs
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
}

void loop() {
  // Idle loop — minimal activity
  delay(1000);
}
