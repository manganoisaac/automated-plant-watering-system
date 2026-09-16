#include "Watering.h"
#include "../controller/Controller.h"
#include "Arduino.h"
#include "HardwareSerial.h"
#include "Idle.h"
void Watering::next(Controller *controller) {
  Serial.println("Watering State");

  // set actuators
  controller->pumpOn();
  controller->waterLowOff();

  // read sensors
  auto moisture = controller->readMoisture();

  // notify observers
  controller->notify("moisture", std::to_string(moisture));

  // if soil is moist set to idle
  if (moisture < 3000) {
    Serial.println("Switching to Idle");
    static auto new_state = Idle();
    controller->setState(&new_state);
  }
}
