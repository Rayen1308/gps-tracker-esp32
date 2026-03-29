# ESP32 GPS Tracker

A portable GPS tracking device built around the ESP32 microcontroller and the SIM800L GSM module. The device reads its location from GPS satellites and sends the coordinates to a phone number via SMS as a Google Maps link — no app, no subscription, no cloud service needed.

---

## Background

I built this as a low-cost alternative to commercial trackers, which are either expensive or tied to monthly fees. The idea is simple: something small and cheap that you can hide in a bag or attach to an object, and that will tell you where it is when you need to know.

---

## How it works

The GPS module continuously reads satellite data and outputs NMEA sentences over UART. The ESP32 parses these using the TinyGPS++ library, extracts the latitude and longitude, and formats them into a Google Maps link. That link is then sent as an SMS via the SIM800L GSM module using standard AT commands.

The message a user receives looks like this:

```
Location update:
https://maps.google.com/?q=49.8728,8.6512
```

---

## Hardware

| Component | Role |
|---|---|
| ESP32 Dev Board | Main microcontroller |
| NEO-6M GPS Module | Satellite positioning via UART |
| SIM800L GSM Module | SMS transmission over 2G cellular |
| LiPo Battery 3.7V | Portable power |
| Power module + capacitors | Voltage stabilisation for SIM800L (peak draw ~2A) |
| GPS and GSM antennas | Signal reception |
| Breadboard and jumper wires | Prototyping |

---

## Wiring

```
ESP32            NEO-6M GPS
GPIO16 (RX2)  -> TX
GPIO17 (TX2)  -> RX
3.3V          -> VCC
GND           -> GND

ESP32            SIM800L
GPIO4  (RX)   -> TX
GPIO2  (TX)   -> RX
GND           -> GND
External 4V   -> VCC  (do not power from ESP32 3.3V pin)
```

The SIM800L requires a stable supply capable of handling current spikes during transmission. Powering it directly from the ESP32 3.3V rail will cause resets. A dedicated power module with capacitors across the supply pins solves this.

---

## Software

- Language: C++ (Arduino framework)
- GPS parsing: TinyGPS++ library
- GSM control: AT commands over SoftwareSerial
- Tested on: ESP32 DevKit v1, Arduino IDE

---

## Current status

The GPS module reads coordinates reliably and the SIM800L connects to the cellular network and sends SMS. The full automatic pipeline — GPS fix acquired, link formatted, SMS sent without manual trigger — is still being integrated and tested.

| Feature | Status |
|---|---|
| GPS coordinate reading | Working |
| Google Maps link generation | Working |
| GSM network connection | Working |
| SMS transmission | Working |
| Full automatic GPS to SMS | In progress |
| Stable power circuit | In progress |
| Compact enclosure | Planned |

---

## What's next

- Complete the end-to-end automation
- Add deep sleep between location updates to extend battery life
- Design a proper charging and power regulation circuit
- Build or print a small enclosure for real-world use
- Possibly add a simple web dashboard for continuous tracking

---

## Getting started

1. Install ESP32 board support in Arduino IDE
2. Install the TinyGPS++ library via Library Manager
3. Clone or download this repository
4. Open `main.ino`, set your phone number in the config section at the top
5. Insert a SIM card with SMS capability into the SIM800L
6. Flash to the ESP32 and open Serial Monitor at 115200 baud to see debug output

---

## Project structure

```
gps-tracker-esp32/
├── main.ino              # Main sketch
├── gps_handler.cpp       # GPS parsing logic
├── gsm_handler.cpp       # SIM800L AT command interface
├── config.h              # Pin definitions and settings
└── docs/
    └── wiring.png        # Wiring diagram
```

---

## Author

Mohamed Rayen Majidi
B.Sc. Mechatronics / B.Sc. Information Systems Engineering — TU Darmstadt
