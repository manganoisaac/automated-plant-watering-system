//Header guard
#ifndef PUMP_RELAY_H
#define PUMP_RELAY_H

//Includes
#include "IActuator.h"

//Pump actuator implements IActuator Framework
class PumpRelay : public IActuator {
private:
  int pin; //What pin the LED is connected to

public:
  PumpRelay(int pin);
  void setup() override;
  void turnOn() override;
  void turnOff() override;
};
#endif // !PUMP_RELAY_H
