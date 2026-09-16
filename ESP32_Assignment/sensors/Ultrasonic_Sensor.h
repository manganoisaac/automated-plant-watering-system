#ifndef ULTRASONIC_SENSOR_H
#include "ISensor.h"

#define ULTRASONIC_SENSOR_H

class UltrasonicSensor : public ISensor {
private:
  int trigPin;
  int echoPin;

public:
  UltrasonicSensor(int trigPin, int echoPin);
  void setup() override;
  float read() override;
};

#endif // !ULTRASONIC_SENSOR_H
