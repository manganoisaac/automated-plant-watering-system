//Header guard
#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H

//Includes
#include "ISensor.h"

//Reads soil moisture from an analog pin
class MoistureSensor : public ISensor {
private:
  int pin; //Which pin the sensor is wired to

public:
  MoistureSensor(int pin);
  void setup() override;
  float read() override;
};
#endif // !MOISTURE_SENSOR_H
