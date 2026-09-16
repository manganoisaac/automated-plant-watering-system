#include "LED.h"
#include "Arduino.h"
#include "esp32-hal-gpio.h"
LED::LED(int pin) : pin(pin) {}

void LED::setup() { pinMode(pin, OUTPUT); }

void LED::turnOn() { digitalWrite(pin, HIGH); }
void LED::turnOff() { digitalWrite(pin, LOW); }
