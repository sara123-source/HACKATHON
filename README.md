# DripGuard – Smart IV Monitoring System

**Technologies:** ESP32, HX711 Load Cell, OLED Display, Buzzer, Blynk IoT

---

## Project Overview
![ALERT DISPLAY](images/ALERT DISPLAY.png)  
*DripGuard IoT-based IV fluid monitoring system in action.*

DripGuard is an **IoT-based IV fluid monitoring system** designed to reduce manual nurse checks by 70% and ensure patient safety by providing real-time alerts for abnormal fluid levels or flow rates. This system integrates sensors, microcontrollers, and mobile notifications to optimize IV management in hospitals and elderly care centers.

---

## Key Features
- **Real-time monitoring:** Measures IV fluid levels using HX711 load cell and displays data on OLED.
- **Automated alerts:** Sends mobile notifications via **Blynk IoT** and triggers buzzer/LED indicators when fluid levels are low or flow abnormal.
- **Cost-effective & scalable:** Designed at under ₹400 per unit for deployment in 25+ rural and elderly care centers.
- **Hackathon Recognition:** Won **2nd Runner-Up at GIH Hackathon 2025**.
- **Research Contribution:** Findings published in a peer-reviewed research paper detailing IoT-based patient monitoring solutions.

---

## Hardware Setup
1. ESP32 microcontroller  
2. HX711 Load Cell for measuring IV fluid weight  
3. OLED Display for real-time monitoring  
4. Buzzer & LED indicators for alerts  

### Wiring Diagram
![WIRING](images/WIRING.jpg)  
*Wiring connections for ESP32, HX711, OLED, and buzzer.*

### Project Setup Photos
![FULL DISPLAY](images/FULL DISPLAY.jpg)  
*Complete DripGuard hardware setup on the IV stand.*  

![ALERT DISPLAY](images/ALERT DISPLAY.png)  
*Close-up of HX711 load cell and OLED display showing real-time fluid data.*

![WINNERS](images/WINNERS.jpg)  
*Team photo from GIH Hackathon 2025 – 2nd Runner-Up.*

![CERTIFICATION](images/CERTIFICATION.jpg)  
*Hackathon certificate and recognition.*

---

## Software Setup
1. Install **Arduino IDE** or **PlatformIO**.  
2. Add ESP32 board in Arduino IDE (`Tools → Board → ESP32 Dev Module`).  
3. Open `src/DripGuard.ino` and configure your **Blynk auth token**.  
4. Upload the code to ESP32.  
5. Monitor real-time IV fluid data on OLED and receive mobile alerts via Blynk.  

---

## Repository Structure
