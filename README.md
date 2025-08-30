# ✋ Sign Language Recognition Glove  

The **Sign Language Recognition Glove** is an Arduino-based project that translates hand gestures into text for real-time communication between sign language users and non-signers. This project uses flex sensors, MPU6050, and wireless communication modules to capture and process gestures.

---

## 📌 Features
- Converts hand gestures into readable text.  
- Uses **Arduino + C++** for embedded processing.  
- Includes **Bluetooth (HC-05)** support for wireless communication.  
- Compact, low-cost, and scalable prototype.  

---

## System_Architecture:
  Hardware:
    - Arduino UNO/NANO
    - Flex Sensors
    - Accelerometer ADXL
    - Bluetooth Module (HC-05)
    - Jumper Wires
    - Glove
    - Breadboard
    - 9V Battery
  Software:
    - Arduino IDE
    - Gesture Recognition Algorithm
    - Android Application
  Communication:
    - Bluetooth Communication Protocol

---
## Android App

Receives data via Bluetooth (HC-05)

Displays recognized gestures in text form

User-friendly UI for real-time communication

---
## Workflow

Wear the glove with sensors.

Flex sensors + accelerometer capture gesture data.

Arduino processes values and sends them over Bluetooth.

Android app receives data and displays the recognized gesture as text.

---


## ⚡ 3. Quick Start Guide

Follow these steps to run the project:

```bash
# 1. Clone the repository
git clone https://github.com/your-username/Sign-Language-Glove.git
cd Sign-Language-Glove

# 2. Open the code
# Open src/main.ino in Arduino IDE or VS Code (with Arduino extension)

# 3. Install dependencies
# - Arduino IDE (latest)
# - Required Libraries:
#   * SoftwareSerial
#   * Wire
#   * ESP8266WiFi (if using Wi-Fi)
#   * Any sensor-specific libraries

# 4. Connect hardware
# - Flex sensors to Arduino analog pins
# - HC-05 (TX/RX) or ESP8266 for wireless communication
# - Power up the glove

# 5. Upload code
# Select the correct Arduino board & COM port, then upload src/main.ino

# 6. Test
# Open Serial Monitor or connect via Bluetooth/Wi-Fi to see gesture outputs
---

