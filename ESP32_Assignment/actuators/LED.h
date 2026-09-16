#ifndef LED_H
#define LED_H

#include "../actuators/IActuator.h"
class LED : public IActuator {
private:
  int pin;

public:
  LED(int pin);
  void setup() override;
  void turnOn() override;
  void turnOff() override;
};

#endif // !LED_H
