# IOT-Irrigation-System
This project is a low-cost, IoT-enabled system for monitoring environmental conditions to support small-scale farming. It uses a NodeMCU (ESP8266) to read real-time temperature and humidity data from a DHT11 sensor. The data is then transmitted to the Blynk cloud platform, allowing for remote monitoring via a smartphone.
Features:
Real-Time Monitoring: Measures and displays current temperature and humidity.
Wireless Data Transmission: Sends sensor data to the cloud via Wi-Fi.
Remote Access: Allows for live data monitoring from anywhere using the Blynk mobile app.
Local Display: Shows readings on a 16x2 I2C LCD for on-site monitoring.
Modular Design: Can be easily expanded to include more sensors (e.g., soil moisture, LDR) and actuators (e.g., a relay for pump control).
Components:
Microcontroller: NodeMCU ESP8266
Sensor: DHT11 Temperature & Humidity Sensor
Display: 16x2 I2C LCD
Software: Arduino IDE, Blynk IoT Platform
