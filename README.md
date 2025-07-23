# GAFS_ULTRA
Main Arduino information file (c++)  with all sensor and control logic


# GAFS-ULTRA: Gas and Fire Shield – Ultra

A next-generation, low-cost, and autonomous fire and gas leak detection system designed for high-risk environments such as restaurants, homes, and industrial zones. This project integrates multiple sensors, GSM alerting, and automated mitigation mechanisms on a modular hardware platform powered by Arduino.

---

## 🔥 Features

- 🔍 **Multi-zone Flame Detection** (3 Zones)
- 🧪 **Gas Leak Detection** with automatic exhaust and shutdown
- 📟 **Real-time LCD Alerts** and buzzer/voice warnings
- 📱 **Automated SMS Notification System** via GSM
- ⚙️ **Autonomous Control of Safety Devices** (pump, gas line, fan, lights)
- 🧠 **No Internet Required** — Works entirely offline
-     ** Automatic Water Sprinkler On 

---

## 📸 System Overview

| Component           | Description                                 |
|---------------------|---------------------------------------------|
| Controller          | Arduino (Uno/Nano/ESP32 compatible)         |
| Gas Sensor          | MQ-series (e.g., MQ-2/MQ-5)                 |
| Flame Sensors       | IR Flame Sensors (x3)                       |
| GSM Module          | SIM800L                                     |
| Output Controls     | Relays for fan, pump, buzzer, etc.          |
| LCD Display         | I2C 20x4 Liquid Crystal Display             |

---

## 📁 Repository Contents


---

## 🚀 Getting Started

### ✅ Hardware Requirements

- Arduino Uno/Nano
- MQ gas sensor
- IR flame sensors (x3)
- GSM Module (SIM800L or similar)
- I2C LCD (20x4)
- Relay modules
- 12V water pump or fan
- Power source (5V/12V regulated)


---

## 🧠 How It Works

1. The system continuously reads gas and flame sensor data.
2. If a threshold is breached, it:
   - Activates a relay to shut off the gas line
   - Powers up exhaust fans and pumps
   - Sends SMS alerts to:
     - Fire services
     - Restaurant/authority owner
3. The LCD updates in real time to show zone status.

---

## 📲 SMS Alert Format 
sample SMS for fire station-1

Sample message sent via GSM: "Fire detected on (current location name ), please quicly arrive at this GPS location with proper safety instruments. (google maps link here) 



---

## 📚 Documentation

This project is part of the **GAFS-ULTRA research prototype**, featured in several competitions and currently submitted for journal publication. See the [Appendix](...) in the publication for embedded code snapshots.

---

## 🏆 Credits

Developed by **Creativity Icon**  
Supervised at **Cumilla Polytechnic Institute, Dept. of Mechanical Engineering**  
Prototype tested at **Star Kabab & Restaurant**, **Cumilla Gas Distribution Company Ltd.**

---


---

## 💬 Contact

Have questions, suggestions, or collaboration requests?  
📧 Email: [mehedihasanroni2186@gmail.com]  
🌐 Website: www.creativityicon.site


