#ifndef ISENSOR_H
#define ISENSOR_H

class ISensor {
public:
  virtual void setup() = 0;
  virtual float read() = 0;
};
#endif // ! ISENSOR_H
