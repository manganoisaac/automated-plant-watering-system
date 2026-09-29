//Header guard
#ifndef ULTRASONIC_SENSOR_H

//Includes
#include "ISensor.h"
#define ULTRASONIC_SENSOR_H

//Measures distance (used to check the water level in the tank)
class UltrasonicSensor : public ISensor {
private:
  int trigPin; //Pin that sends out the pulse
  int echoPin; //Pin that the pulse bounces back on

public:
  UltrasonicSensor(int trigPin, int echoPin);
  void setup() override;
  float read() override;
};

#endif // !ULTRASONIC_SENSOR_H
