#ifndef IACTUATOR_H
#define IACTUATOR_H

class IActuator {
public:
  virtual void setup() = 0;
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
};

#endif // !IACTUATOR_H
