# States

This section contains the state machine that decides what the system should be doing (idle, watering, etc). Each state reads the sensors through the Controller, decides if anything needs to change, and switches to the next state if needed.

The files:

**IState.h**
The shared interface. Every state has a next function that runs its logic and decides the next state.

**StateBase.h / StateBase.cpp**
A shared base class all states inherit from. Holds the helper functions used to switch to each state, plus the sleep function.

**Idle.h / Idle.cpp**
Default state. Checks the sensors and moves to another state if watering is needed, the tank is empty, or it's too hot.

**Idle_Hot_Day.h / Idle_Hot_Day.cpp**
Same as Idle, but used when it's a hot day.

**Watering.h / Watering.cpp**
Turns the pump on and waters the plant.

**Water_Empty.h / Water_Empty.cpp**
Entered when the water tank is empty. Waits until it's refilled.

**Error.h / Error.cpp**
Entered when a fault is detected. Stops normal operation.
