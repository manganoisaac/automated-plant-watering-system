// Includes
#include "Pump_Relay.h"
#include "Arduino.h"
#include "esp32-hal-gpio.h"

//Stores which pin the relay is connected to
PumpRelay::PumpRelay(int pin) : pin(pin) {};

//Sets the relay pin to be an output, starts with the pump off
void PumpRelay::setup() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}

//This relay is active LOW, so LOW=On HIGH=Off
void PumpRelay::turnOn() { digitalWrite(pin, LOW); }

void PumpRelay::turnOff() { digitalWrite(pin, HIGH); }
