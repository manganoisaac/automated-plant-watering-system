#include "Pump_Relay.h"
#include "Arduino.h"
#include "esp32-hal-gpio.h"

PumpRelay::PumpRelay(int pin) : pin(pin) {};

void PumpRelay::setup() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}

void PumpRelay::turnOn() { digitalWrite(pin, LOW); }

void PumpRelay::turnOff() { digitalWrite(pin, HIGH); }
