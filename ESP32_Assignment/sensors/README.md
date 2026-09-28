# Sensors

This section contains all the code that reads values from the system (soil moisture, water level, temperature).

The files:

**ISensor.h**
The shared interface that every sensor follows, so they all have a setup and read function.

**Moisture_Sensor.h / Moisture_Sensor.cpp**
Reads the soil moisture level from an analog pin.

**Ultrasonic_Sensor.h / Ultrasonic_Sensor.cpp**
Measures distance using an ultrasonic sensor, used to check the water level in the tank.

**Heat_Detector.h**
A sub-interface for anything that reports temperature. Has no code of its own, just extends ISensor.

**Wifi_Heat_Detector.h / Wifi_Heat_Detector.cpp**
Gets the current temperature from an online weather API instead of a physical sensor.
