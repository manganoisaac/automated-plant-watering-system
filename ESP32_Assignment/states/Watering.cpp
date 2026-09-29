//Includes
#include "Watering.h"
#include "../constants.h"
#include "../controller/Controller.h"
#include "Arduino.h"
#include "HardwareSerial.h"
#include "Idle.h"

//Runs the pump until the soil is moist enough, then goes back to Idle
void Watering::next(Controller *controller) {
  Serial.println("Watering State");

  // set actuators
  controller->resetLEDs();
  controller->pumpOn();

  // read sensors
  auto dryness = controller->readMoisture();

  // notify observers
  controller->notify(constants::event_dryness, std::to_string(dryness));

  // if soil is moist set to idle
  if (dryness < constants::lower_dryness_threshold) {
    Serial.println("Switching to Idle");
    this->to_idle(controller);
    return;
  }
}
