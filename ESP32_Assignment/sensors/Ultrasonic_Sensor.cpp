#include "Ultrasonic_Sensor.h"
#include "Arduino.h"
#include "esp32-hal-gpio.h"
#include "esp32-hal.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin)
    : trigPin(trigPin), echoPin(echoPin) {};

void UltrasonicSensor::setup() {
  // TODO: implement with library
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float UltrasonicSensor::read() {
  // TODO: implement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance_cm = (duration * 0.034) / 2;
  return distance_cm;
}
