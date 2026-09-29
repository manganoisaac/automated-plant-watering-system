//Includes
#include "Moisture_Sensor.h"
#include "Arduino.h"
#include "esp32-hal-adc.h"
#include "esp32-hal-gpio.h"

//Stores which pin the sensor is connected to
MoistureSensor::MoistureSensor(int pin) : pin(pin) {};

//Sets the sensor pin to be an input
void MoistureSensor::setup() { pinMode(pin, INPUT); }

//Reads the raw analog value from the sensor (higher = drier soil)
float MoistureSensor::read() {
  auto val = analogRead(pin);
  return val;
}
