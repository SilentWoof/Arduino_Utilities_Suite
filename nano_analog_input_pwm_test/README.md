# nano_analog_input_pwm_test

This sketch tests analog input and PWM output on the Arduino Nano using a single button to cycle through analog input pins (A0–A5). It reads voltage from a potentiometer and maps it to LED brightness via PWM on D3.

## 🎯 Purpose

- Verify analog input functionality across A0–A5
- Confirm PWM output behavior on D3
- Provide tactile and visual feedback without relying on serial output

## 🧪 Hardware Setup

### Components
- Arduino Nano (ATmega328P)
- 1x Potentiometer
- 1x LED
- 1x 220Ω–330Ω resistor
- 1x Pushbutton
- Breadboard + jumper wires

### Wiring

#### Potentiometer
- One side → **5V**
- Other side → **GND**
- Wiper → **Flying lead** (move between A0–A5)

#### LED
- Anode → **D3**
- Cathode → **GND** (via resistor)

#### Button
- One side → **D8**
- Other side → **GND**

## 🎮 Usage

- On boot, the sketch starts with A0 as the active analog input.
- Press the button to cycle through A1–A5.
- LED brightness reflects the analog voltage read from the selected pin.
- Serial output confirms button presses and active input pin (e.g., "Switched to input A2").

## 🧰 Notes

- This sketch avoids serial spam — only pin changes are logged.
- Ideal for quick validation of analog inputs and PWM output.
- Can be adapted to include A6/A7 if your Nano variant supports them.

## 📜 License

MIT License — feel free to fork, adapt, and contribute.