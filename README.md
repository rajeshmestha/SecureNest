# 🔐 Secure Nest – Arduino-Based Smart Door Lock System

Secure Nest is an Arduino-powered smart door security system that combines multiple technologies to provide secure, automated, and intelligent home access control. It features a 4x4 keypad for password entry, an LCD display for real-time feedback, a servo motor to control door locking, and sensors for temperature and light-based automation. Ideal for smart home applications and educational projects in IoT and embedded systems.

---

## 📷 Project Preview

[Secure Nest Setup]![Image](https://github.com/user-attachments/assets/485d6b0d-28c9-4019-81d7-75cfee91b07f) 

---

## 🚀 Features

- 🔢 **Keypad-based Password Entry**  
  4x4 matrix keypad for secure user authentication.

- 📟 **LCD Interface (16x2, I2C)**  
  Displays prompts, feedback, and sensor data in real-time.

- 🔒 **Servo-Controlled Lock Mechanism**  
  Automatically unlocks and locks the door based on password verification.

- 🌡️ **Temperature Monitoring**  
  Activates fan LED when temperature exceeds threshold.

- 💡 **Ambient Light Detection**  
  Automatically turns on LED lighting in low-light conditions.

- 🔊 **Buzzer Alerts**  
  Alerts on wrong password attempts and plays welcome melody on access grant.

---

## 🛠️ Hardware Requirements

| Component             | Quantity |
|----------------------|----------|
| Arduino Uno / Nano   | 1        |
| 4x4 Keypad           | 1        |
| 16x2 I2C LCD         | 1        |
| Servo Motor (SG90)   | 1        |
| Temperature Sensor (LM35) | 1    |
| Light Sensor (LDR)   | 1        |
| Buzzer               | 1        |
| LEDs (Door, Fan, Light) | 3     |
| Resistors            | As needed |
| Breadboard & Jumper Wires | -    |
| 5V Power Supply or USB | 1      |

---

## 🔧 Circuit Connections

| Device         | Arduino Pin |
|----------------|-------------|
| Keypad Rows    | 6, 7, 8, 9   |
| Keypad Columns | 2, 3, 4, 5   |
| LCD (I2C)      | A4 (SDA), A5 (SCL) |
| Servo Motor    | A2          |
| LM35 (Temp)    | A0          |
| LDR (Light)    | A1          |
| Buzzer         | 13          |
| Door LED       | 12          |
| Light LED      | 10          |
| Fan LED        | 11          |

---

## 🧠 How It Works

1. **Boot Up:** LCD greets the user and prompts for a password.
2. **Password Input:** User enters a 4-digit password using the keypad.
3. **Verification:**
   - ✅ If correct: Servo unlocks door, welcome melody plays, and sensors activate.
   - ❌ If incorrect: Warning message shown, buzzer beeps after repeated wrong attempts.
4. **Sensor Automation:**
   - If **temperature > 30°C**, fan LED is turned ON.
   - If **ambient light < threshold**, light LED is turned ON.
5. **Auto-lock (optional):** Door re-locks after a timeout (configurable).

---

## 📦 Code Overview

- `setup()`: Initializes LCD, pins, and welcomes the user.
- `loop()`: Manages keypad input, password logic, and triggers sensor functions.
- `doorUnlock()`: Unlocks the door and activates welcome sequence.
- `monitorTemperature()`: Reads temperature and toggles fan.
- `monitorLight()`: Reads light levels and toggles LED lighting.
- `playWelcomeMusic()`: Simple tone sequence on access granted.

---

## 🧪 Future Enhancements

- 🔐 EEPROM-based password storage and change feature
- 📱 Bluetooth or Wi-Fi (ESP8266) based mobile app control
- 📷 Integration with a camera module for intruder detection
- 🔐 Fingerprint module for biometric authentication
- 🕒 Add RTC module to show date/time on LCD

---

## 🤝 Contributing

Feel free to fork this project, suggest improvements, or submit pull requests. Feedback and ideas are always welcome!

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 👨‍💻 Author

**Rajesh** – Passionate about IoT, VLSI, and embedded systems  
📧 [Email Me](mestharajesh001@gmail.com)
---

