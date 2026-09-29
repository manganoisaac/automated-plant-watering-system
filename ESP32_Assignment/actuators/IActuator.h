//Header Gaurd
#ifndef IACTUATOR_H
#define IACTUATOR_H

//Interface that every actuator uses so they can be
//set up and turned on/off the same way
class IActuator {
public:
  virtual void setup() = 0;
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
};

#endif // !IACTUATOR_H
