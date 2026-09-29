//Include Block
#include "LED.h"
#include "Arduino.h"
#include "esp32-hal-gpio.h"

//Stores what pin the LED is
LED::LED(int pin) : pin(pin) {}

//Sets the LED pin to be output
void LED::setup() { pinMode(pin, OUTPUT); }

//Turns the LED on and off
void LED::turnOn() { digitalWrite(pin, HIGH); }
void LED::turnOff() { digitalWrite(pin, LOW); }
