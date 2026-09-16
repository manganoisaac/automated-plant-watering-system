#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H

#include "ISensor.h"

class MoistureSensor : public ISensor {
private:
  int pin;

public:
  MoistureSensor(int pin);
  void setup() override;
  float read() override;
};
#endif // !MOISTURE_SENSOR_H
