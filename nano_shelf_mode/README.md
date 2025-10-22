# nano_self_mode

A minimal idle sketch for the Arduino Nano, designed to safely park the board while it's not in active use. It sets all GPIOs to known states and avoids unnecessary power draw or serial activity.

## 🎯 Purpose

- Prevent floating pins or unpredictable behavior during storage
- Ensure all digital outputs are LOW
- Set analog-capable pins to INPUT
- Avoid blinking, serial output, or power-hungry loops

## 🧪 Hardware Setup

No external components required. This sketch is intended for use when the Nano is disconnected from active circuits and stored.

## ⚙️ Behavior

- Digital pins D2–D13 are set to `OUTPUT LOW`
- Analog pins A0–A5 are set to `INPUT`
- PWM outputs (D3, D5, D6, D9, D10, D11) are explicitly disabled
- Loop runs with a minimal delay to keep the MCU active but quiet

## 🧰 Usage

Upload this sketch before placing the Nano into storage. It ensures predictable behavior and avoids accidental current draw or floating states.

## 📌 Notes

- D0 and D1 (serial RX/TX) are left untouched to avoid interfering with USB communication
- Ideal for boards shelved between projects or awaiting reassignment

## 📜 License

MIT License — feel free to fork, adapt, and contribute.