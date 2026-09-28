# Logger

This section contains the code that reacts to events happening in the system (sensor readings, state changes, etc). These all follow the observer pattern, the Controller notifies them and each one decides what to do with that event.

The files:

**IObserver.h**
The shared interface. Anything that wants to be notified of events must implement a notify function.

**Logger.h / Logger.cpp**
Prints events straight to the Serial monitor.

**AdaFruit.h / AdaFruit.cpp**
Sends events to Adafruit IO over MQTT, so readings can be viewed online/remotely.

**FaultDetector.h / FaultDetector.cpp**
Keeps a short history of recent readings and flags a fault if a reading is outside the expected range (e.g. dryness, water level, temperature).

**FaultStatus.h**
An enum listing the possible fault types (water_level, dryness, temperature).
