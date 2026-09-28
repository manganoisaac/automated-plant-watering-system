# Actuators

This section contains all the code that controls the physical output devices for the plant watering system (the LED and the water pump).

The files:

**IActuator.h**
The shared interface that the LED and pump both follow, so every actuator has a setup, turnOn, and turnOff function.

**LED.h / LED.cpp**
Controls the status LED. Turns it on or off.

**Pump_Relay.h / Pump_Relay.cpp**
Controls the water pump through a relay. Note this relay works backwards (LOW turns the pump on, HIGH turns it off).
