# ✋ Sign Language Recognition Glove  

The **Sign Language Recognition Glove** is an Arduino-based project that translates hand gestures into text for real-time communication between sign language users and non-signers. This project uses flex sensors, MPU6050, and wireless communication modules to capture and process gestures.

---

## 📌 Features
- Converts hand gestures into readable text.  
- Uses **Arduino + C++** for embedded processing.  
- Includes **Bluetooth (HC-05)** support for wireless communication.  
- Compact, low-cost, and scalable prototype.  

---

## 📂 Project Structure
```yaml
.
├── src/                # Source code (Arduino .cpp files)
│   ├── main.cpp        # Main Arduino sketch
│   └── gestures.cpp    # Gesture handling logic
├── LICENSE             # MIT License
├── .gitignore          # Ignored files for Git
└── README.md           # Documentation

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

