#ifndef PUMP_RELAY_H
#define PUMP_RELAY_H

#include "IActuator.h"
class PumpRelay : public IActuator {
private:
  int pin;

public:
  PumpRelay(int pin);
  void setup() override;
  void turnOn() override;
  void turnOff() override;
};
#endif // !PUMP_RELAY_H
