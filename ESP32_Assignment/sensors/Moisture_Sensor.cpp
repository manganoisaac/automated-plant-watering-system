#include "Moisture_Sensor.h"
#include "Arduino.h"

#include "esp32-hal-adc.h"
#include "esp32-hal-gpio.h"

MoistureSensor::MoistureSensor(int pin) : pin(pin) {};

void MoistureSensor::setup() { pinMode(pin, INPUT); }
float MoistureSensor::read() {
  auto val = analogRead(pin);
  return val;
}
