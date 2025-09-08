# 🧹 Desktop Cleaner 

This project is an **Arduino-based desktop cleaner robot** equipped with an **ultrasonic sensor** for obstacle detection, a **DC motor driver for movement**, and an **OLED display** for real-time distance monitoring.

---

## 📌 Features
- Displays "DESKTOP CLEANER" on an OLED screen at startup.
- Uses **HC-SR04 Ultrasonic Sensor** for measuring distance.
- DC motor control with direction pins for cleaning action.
- Real-time distance feedback on OLED and Serial Monitor.
- Stops when objects are far; activates motor when close.

---

## 📂 Hardware Components
- Arduino UNO / Nano / Mega  
- DC Motor + Driver (L293D / H-Bridge)  
- HC-SR04 Ultrasonic Sensor  
- SSD1306 OLED Display (128x64)  
- Power Supply (Battery/USB)  

---

## ⚙️ Pin Configuration
- **Motor Control**  
  - `motor1pin1` → Pin 2  
  - `motor1pin2` → Pin 3  

- **Ultrasonic Sensor**  
  - `TrigPin` → Pin 9  
  - `EchoPin` → Pin 8  

- **OLED Display**  
  - I2C Communication (SDA, SCL) at address `0x3C`  

---

## 🚀 Code Explanation
1. Initializes the **OLED display** and shows "DESKTOP CLEANER".  
2. Measures distance using the **HC-SR04 ultrasonic sensor**.  
3. Displays distance in **cm** on OLED and Serial Monitor.  
4. If distance ≤ 15 cm → motor runs forward ("LOW DISTANCE").  
5. If distance > 15 cm → motor stops ("HIGH DISTANCE").  

---

## 📊 Example Output
- **OLED Display**  
DESKTOP CLEANER
Distance: 12 cm

- **Serial Monitor**  
Distance: 12 cm
LOW DISTANCE

---

## 🔧 Installation & Usage
1. Connect all components as per pin configuration.  
2. Install required Arduino libraries:  
 - `Adafruit_GFX.h`  
 - `Adafruit_SSD1306.h`  
3. Upload the sketch to Arduino using Arduino IDE.  
4. Open Serial Monitor at **9600 baud rate**.  

---

## 👨‍💻 Author
Developed by **MegaZroN (Gaus Mohiuddin Sayyad)**  
🌐 Portfolio: [https://megazron.com](https://megazron.com)  

---

## 📜 License
This project is licensed under the terms of the [LICENSE](LICENSE) file.
