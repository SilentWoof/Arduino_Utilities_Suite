const int redButtonPin  = 8;   // Red button: next pin
const int blueButtonPin = 9;   // Blue button: toggle pin

const int testPins[] = {2, 3, 4, 5, 6, 7, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5};
const int totalPins = sizeof(testPins) / sizeof(testPins[0]);

int currentPinIndex = 0;
bool currentState = LOW;
bool redPrev = HIGH;
bool bluePrev = HIGH;

void setup() {
  Serial.begin(9600);
  Serial.println("=== Arduino Nano GPIO Walk Test ===");

  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);

  for (int i = 0; i < totalPins; i++) {
    pinMode(testPins[i], OUTPUT);
    digitalWrite(testPins[i], LOW);
  }

  Serial.print("Starting test on ");
  Serial.println(getPinLabel(testPins[currentPinIndex]));
}

void loop() {
  bool redNow = digitalRead(redButtonPin);
  bool blueNow = digitalRead(blueButtonPin);

  if (redPrev == HIGH && redNow == LOW) {
    digitalWrite(testPins[currentPinIndex], LOW);
    currentPinIndex++;

    if (currentPinIndex >= totalPins) {
      Serial.println("✅ All GPIOs have been tested.");
      while (true);
    }

    currentState = LOW;
    Serial.print("➡️ Moving to ");
    Serial.println(getPinLabel(testPins[currentPinIndex]));
  }

  if (bluePrev == HIGH && blueNow == LOW) {
    currentState = !currentState;
    digitalWrite(testPins[currentPinIndex], currentState);
    Serial.print("🔘 ");
    Serial.print(getPinLabel(testPins[currentPinIndex]));
    Serial.print(" set to ");
    Serial.println(currentState == HIGH ? "HIGH" : "LOW");
  }

  redPrev = redNow;
  bluePrev = blueNow;
  delay(50);
}

// === Helper: Convert pin number to label ===
String getPinLabel(int pin) {
  if (pin >= A0 && pin <= A5) {
    return "A" + String(pin - A0);
  } else {
    return "D" + String(pin);
  }
}
