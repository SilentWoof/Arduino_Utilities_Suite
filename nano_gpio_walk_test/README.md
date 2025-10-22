# nano_gpio_walk_test

This sketch provides a button-controlled GPIO walk test for the Arduino Nano. It cycles through digital and analog-capable pins, allowing manual toggling of each pin's state with visual and serial confirmation.

## 🎯 Purpose

- Verify digital output functionality across D2–D13 and A0–A5
- Confirm pin toggling via LED feedback
- Provide serial confirmation of pin labels and states (e.g., "D4 set to HIGH")

## 🧪 Hardware Setup

### Components
- Arduino Nano (ATmega328P)
- 1x LED
- 1x 220Ω–330Ω resistor
- 2x Pushbuttons
- Breadboard + jumper wires

### Wiring

#### LED
- Anode → **Flying lead** (move between test pins)
- Cathode → **GND** (via resistor)

#### Buttons
- Red button → **D8** (next pin)
- Blue button → **D9** (toggle pin state)
- Both buttons → **GND** on other side

## 🎮 Usage

- On boot, the sketch starts with D2 as the active test pin.
- Press the **red button** to move to the next pin.
- Press the **blue button** to toggle the current pin HIGH/LOW.
- Serial output confirms each action and pin label (e.g., "➡️ Moving to D3", "🔘 D3 set to HIGH").

## 📌 Notes

- Analog-capable pins (A0–A5) are tested as digital outputs.
- Pin labels are printed in Arduino-style format (e.g., D4, A2).
- Sketch halts after all pins are tested — restart to repeat.

## 📜 License

MIT License — feel free to fork, adapt, and contribute.