//Header Gaurd
#ifndef LED_H
#define LED_H

//Includes
#include "../actuators/IActuator.h"

//LED actuator implements IActuator Framework
class LED : public IActuator {
private:
  int pin; //What pin the LED is connected to

public:
  LED(int pin);
  void setup() override;
  void turnOn() override;
  void turnOff() override;
};

#endif // !LED_H
