# Arduino Utilities Suite

A modular collection of utility scripts, diagnostics, and test harnesses for Arduino-based devices. Designed for hardware validation, tactile feedback, and reproducible workflows across multiple boards and use cases.

## 📦 Contents

### [`nano_gpio_walk_test`](nano_gpio_walk_test/)
Interactive GPIO tester for Arduino Nano:
- Red button cycles through testable GPIOs (D2–D13, A0–A5)
- Blue button toggles the current pin HIGH/LOW
- Serial output confirms each action and pin label

### [`nano_analog_input_pwm_test`](nano_analog_input_pwm_test/)
Analog input and PWM output tester:
- Cycles through A0–A5 using a button
- Reads analog voltage from a potentiometer
- Drives PWM brightness on D3 based on input
- Serial confirms pin changes only

### [`nano_shelf_mode`](nano_shelf_mode/)
Safe idle sketch for storage:
- Sets all digital pins to OUTPUT LOW
- Sets analog pins to INPUT
- No serial, blinking, or floating pins

## 🧰 Usage

Each sketch lives in its own folder and is self-contained. Open the `.ino` file in the Arduino IDE and upload to your board. Wiring diagrams and usage notes are available in each sketch’s dedicated [`README.md`](nano_gpio_walk_test/README.md).

## 🧪 Hardware Assumptions

- Arduino Nano (ATmega328P) for current sketches
- USB connection for upload and serial
- Breadboard setup with buttons, LED, resistors, and potentiometer

## 🚀 Future Expansion

This repo is intended for general-purpose Arduino utilities. Specific projects (e.g., sensor integrations, display drivers, robotics) will live in their own repositories. Planned additions include:

- I2C scanner and diagnostics
- SPI display test harnesses
- EEPROM read/write utilities
- Watchdog timer test scripts
- Cross-board compatibility notes

## 📜 License

MIT License — feel free to fork, adapt, and contribute.

---

Built for clarity, modularity, and tactile diagnostics.