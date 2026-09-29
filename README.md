# Automated Plant Watering System

An ESP32 based system that monitors soil moisture, water tank level, and temperature, and automatically waters a plant when needed. Readings and events are logged to the Serial monitor and to Adafruit IO.

All the code lives in the ESP32_Assignment folder. Each folder inside it has its own README with more detail.

The folders:

**actuators**
Controls the physical outputs (pump, status LED).

**sensors**
Reads values from the system (soil moisture, water level, temperature).

**controller**
Ties the sensors, actuators, and state machine together.

**states**
The state machine that decides what the system should be doing (idle, watering, error, etc).

**logger**
Reacts to events, either printing them to Serial or sending them to Adafruit IO.

**wifi**
Connects the ESP32 to wifi.

**threshold_strategy**
Currently empty, planned but unused.

Other files:

**ESP32_Assignment.ino**
The entry point of the program, wires everything together and runs the main loop.

**constants.h**
Threshold values and other shared constants.

**secrets.example.h**
Template for secrets.h, copy it and fill in your own wifi/API details. secrets.h itself is not committed to git.
