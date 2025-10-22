// === CONFIGURATION ===
const int analogPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
const int totalAnalogPins = sizeof(analogPins) / sizeof(analogPins[0]);

const int pwmOutputPin = 3;       // LED + resistor
const int nextButtonPin = 8;      // Button to cycle analog input

// === STATE TRACKING ===
int currentAnalogIndex = 0;
bool buttonPrev = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(pwmOutputPin, OUTPUT);
  pinMode(nextButtonPin, INPUT_PULLUP);

  Serial.println("=== Analog Input Test ===");
  Serial.print("Starting with input ");
  Serial.println(getAnalogLabel(analogPins[currentAnalogIndex]));
}

void loop() {
  // === Button handling ===
  bool buttonNow = digitalRead(nextButtonPin);
  if (buttonPrev == HIGH && buttonNow == LOW) {
    currentAnalogIndex++;
    if (currentAnalogIndex >= totalAnalogPins) {
      currentAnalogIndex = 0;
      Serial.println("🔁 Restarting analog input cycle.");
    }
    Serial.print("➡️ Switched to input ");
    Serial.println(getAnalogLabel(analogPins[currentAnalogIndex]));
  }
  buttonPrev = buttonNow;

  // === Read analog input and drive PWM ===
  int raw = analogRead(analogPins[currentAnalogIndex]);
  int pwmValue = map(raw, 0, 1023, 0, 255);
  analogWrite(pwmOutputPin, pwmValue);

  delay(100);
}

// === Helper: Convert analog pin to label ===
String getAnalogLabel(int pin) {
  return "A" + String(pin - A0);
}
