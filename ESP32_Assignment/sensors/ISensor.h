// Header guard
#ifndef ISENSOR_H
#define ISENSOR_H

// Interface for every sensor so that it can be used the same way
class ISensor {
public:
  virtual void setup() = 0;
  virtual float read() = 0;
};
#endif // ! ISENSOR_H
