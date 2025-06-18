# 🔊 Smart Proximity Alert System using Arduino, LCD, and Buzzer

This project is a real-time **distance monitoring and alert system** built using an **Arduino UNO**, an **HC-SR04 ultrasonic sensor**, a **16x2 LCD display**, and a **buzzer**. The system measures the distance to nearby objects and provides both **visual feedback** via the LCD and **audible alerts** that increase in frequency as the object gets closer.

---

## 📌 Features

- 📏 Measures distance using ultrasonic sensing
- 📺 Displays distance in real-time on a 16x2 LCD
- 🔊 Buzzer beeps faster as objects get closer
- 🧠 Simple, intuitive feedback system (like car parking sensors)
- 💻 Code written in Arduino IDE using standard libraries

---

## ⚙️ Components Used

| Component              | Description                                 |
|------------------------|---------------------------------------------|
| Arduino UNO            | Microcontroller to control all components   |
| HC-SR04 Sensor         | Ultrasonic sensor to measure distance       |
| 16x2 LCD Display       | To display distance in centimeters          |
| Potentiometer (10kΩ)   | Adjusts LCD contrast                        |
| Active Buzzer          | Provides audio feedback based on proximity |
| Breadboard & Jumper Wires | For prototyping and connections         |

---

## 🧠 Why 4-Bit LCD Mode?

The 16x2 LCD can operate in **8-bit or 4-bit mode**.  
This project uses **4-bit mode** to:

- **Save Arduino pins**: Only 6 pins are needed instead of 10.
- **Leave space for other modules** (like the sensor, buzzer).
- **Sufficient for simple text**: We're only sending characters, so 4-bit mode is efficient enough.

---

## 🛠️ Circuit Connections

### HC-SR04 Ultrasonic Sensor
- VCC → 5V (Arduino)
- GND → GND
- TRIG → D9
- ECHO → D8

### LCD (16x2) in 4-Bit Mode
- RS → D12  
- E  → D11  
- D4 → D5  
- D5 → D4  
- D6 → D3  
- D7 → D2  
- RW → GND  
- VSS → GND  
- VDD → 5V  
- V0 (Contrast) → Middle pin of Potentiometer (10kΩ)

### Potentiometer
- One side → 5V  
- One side → GND  
- Middle pin → LCD V0

### Buzzer
- Positive → D7  
- Negative → GND

---

## 🧾 How It Works

1. The **HC-SR04 sensor** emits an ultrasonic pulse and listens for the echo.
2. The **Arduino** calculates the time it takes for the echo to return and converts it into a distance (in cm).
3. The distance is displayed on the **LCD screen** in real-time.
4. The **buzzer beeps**:
   - Faster when the object is **closer**
   - Slower when the object is **farther**
   - Silent beyond a defined threshold (e.g., 100 cm)

The beep delay is dynamically calculated using `map()` to scale the distance into a time interval.

---

## 💾 Arduino Code Overview

- Uses the **LiquidCrystal** library for LCD control
- Distance is calculated using:
distance = (duration * 0.0343) / 2;

.

🧰 Tools Used

Arduino IDE for development and uploading code
Serial Monitor (optional) for debugging
Linux terminal (if using Raspberry Pi later for integration)

📦 Future Enhancements

Add LED indicators for different distance ranges
Include Bluetooth/Wi-Fi for remote alerts
Integrate camera (PiCam2) with OpenCV for object recognition
Mount system on a robot or vehicle for obstacle detection

👨‍💻 Author
[ ADESH PALANIVEL ]
Engineering Trainee at Zeetaminds
Specializing in embedded systems, Linux-based development, and sensor integration.


