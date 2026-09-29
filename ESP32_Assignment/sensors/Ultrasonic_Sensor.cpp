// Includes
#include "Ultrasonic_Sensor.h"
#include "Arduino.h"
#include "esp32-hal-gpio.h"
#include "esp32-hal.h"

// Stores which pins the sensor's trigger and echo wires are connected to
UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin)
    : trigPin(trigPin), echoPin(echoPin) {};

// Setup trigger and echo pins
void UltrasonicSensor::setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Sends pulse to trigger, times echo bounceback, converts to distance
float UltrasonicSensor::read() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance_cm = (duration * 0.034) / 2;
  return distance_cm;
}
