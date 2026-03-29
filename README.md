# 📍 ESP32 GPS Tracker

A portable, low-cost GPS tracking device built on the ESP32 microcontroller. The tracker determines its location via GPS satellites and sends the coordinates to the user as an SMS containing a direct Google Maps link — no app required.

---

## 🔍 Problem Statement

Commercial GPS trackers are either expensive, subscription-based, or locked to proprietary apps. This project provides a fully open, DIY alternative that:

- Locates lost or stolen items (wallet, bag, bicycle, etc.)
- Tracks objects remotely when outdoors
- Delivers location instantly via SMS — works on any phone

---

## ⚙️ How It Works

1. The **GPS module** acquires satellite signals and outputs coordinates (latitude/longitude)
2. The **ESP32** parses the NMEA data and formats a Google Maps link
3. The **SIM800L GSM module** sends the link to a pre-configured phone number via SMS
4. The user receives a message like:
   ```
   Location update:
   https://maps.google.com/?q=49.8728,8.6512
   ```

---

## 🧰 Hardware Components

| Component | Description |
|---|---|
| ESP32 Dev Board | Main microcontroller — WiFi/Bluetooth capable |
| NEO-6M GPS Module | Satellite-based positioning, UART output |
| SIM800L GSM Module | 2G cellular module for SMS transmission |
| LiPo Battery (3.7V) | Portable power supply |
| Capacitors + Power Module | Voltage stability for SIM800L (requires peak ~2A) |
| GPS + GSM Antennas | Signal reception for both modules |
| Breadboard + Jumper Wires | Prototyping setup |

---

## 💻 Software & Libraries

- **Language:** C++ (Arduino framework via PlatformIO / Arduino IDE)
- **GPS parsing:** TinyGPS++ library
- **GSM communication:** AT commands over UART (SoftwareSerial)
- **Platform:** ESP32 (tested on ESP32 DevKit v1)

---

## 📦 Current Status

> **Stage: Prototype — Partially Functional**

| Feature | Status |
|---|---|
| GPS coordinate acquisition | ✅ Working |
| Google Maps link generation | ✅ Working |
| GSM network connection | ✅ Working |
| SMS transmission | ✅ Working |
| Full automatic GPS → SMS integration | 🔄 In progress |
| Stable power system | 🔄 In progress |
| Compact enclosure | 📋 Planned |

---

## 🗺️ Roadmap

- [ ] Complete end-to-end GPS → SMS automation
- [ ] Implement deep sleep mode for battery efficiency
- [ ] Design stable charging circuit for LiPo battery
- [ ] 3D print or fabricate compact enclosure
- [ ] Optional: Web/mobile dashboard for live tracking
- [ ] Optional: Bluetooth short-range tracking mode

---

## 🔌 Wiring Overview

```
ESP32          NEO-6M GPS
------         ----------
GPIO16 (RX2) → TX
GPIO17 (TX2) → RX
3.3V         → VCC
GND          → GND

ESP32          SIM800L
------         -------
GPIO4  (RX)  → TX
GPIO2  (TX)  → RX
GND          → GND
External 4V  → VCC (via power module — do NOT power from ESP32 3.3V)
```

---

## 🚀 Getting Started

### Prerequisites
- Arduino IDE or PlatformIO
- ESP32 board support package installed
- Libraries: `TinyGPS++`, `SoftwareSerial`

### Setup
1. Clone this repository
   ```bash
   git clone https://github.com/rayen-majidi/gps-tracker-esp32.git
   ```
2. Open the project in Arduino IDE or PlatformIO
3. In `config.h`, set your target phone number:
   ```cpp
   #define PHONE_NUMBER "+49XXXXXXXXXX"
   ```
4. Insert a SIM card with SMS capability into the SIM800L
5. Flash to your ESP32 and open Serial Monitor (115200 baud)

---

## 📁 Project Structure

```
gps-tracker-esp32/
├── src/
│   ├── main.cpp          # Main application logic
│   ├── gps_handler.cpp   # GPS parsing and coordinate formatting
│   └── gsm_handler.cpp   # SIM800L AT command interface
├── include/
│   └── config.h          # Pin definitions and configuration
├── docs/
│   └── wiring_diagram.png  # Hardware wiring reference
└── README.md
```

---

## 🧠 Key Learnings

- Serial communication between multiple UART devices on ESP32
- Parsing NMEA sentences from GPS modules using TinyGPS++
- AT command interface for GSM modules (SIM800L)
- Power management challenges with high-current GSM modules
- Prototyping and debugging embedded hardware on a breadboard

---

## 👤 Author

**Mohamed Rayen Majidi**
B.Sc. Mechatronics & B.Sc. Information Systems Engineering
TU Darmstadt

---

## 📄 License

This project is open source under the [MIT License](LICENSE).
