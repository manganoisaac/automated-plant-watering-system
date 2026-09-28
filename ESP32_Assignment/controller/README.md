# Controller

This section contains the code that ties all the other parts of the system together (sensors, actuators, fault detection, and states). The states call into the Controller to read sensors and switch actuators on/off, instead of touching them directly.

The files:

**Controller.h**
Declares the Controller class, the sensors/actuators/state it holds, and all the functions it offers (adding devices, reading sensors, turning things on/off, notifying observers, stepping the state machine).

**Controller.cpp**
Implements those functions.
