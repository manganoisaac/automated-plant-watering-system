//Includes
#include "Water_Empty.h"
#include "../constants.h"
#include "../controller/Controller.h"
#include "Arduino.h"
#include "HardwareSerial.h"
#include "Idle.h"
#include "Watering.h"

//Turns the water-low LED on and waits here until the tank is refilled
void WaterEmpty::next(Controller *controller) {

  Serial.println("Water empty state");

  // set actuators for state
  controller->resetLEDs();
  controller->pumpOff();
  controller->waterLowOn();
  controller->alertBuzzerOn();

  // read sensors
  auto distance = controller->readUltrasonic();

  // notify observers
  controller->notify(constants::event_water_level, std::to_string(distance));

  // is water refilled
  if (distance < constants::lower_water_level_threshold) {

    // check moisture
    auto dryness = controller->readMoisture();

    controller->notify(constants::event_dryness, std::to_string(dryness));

    // if soil is dry, set to watering state
    if (dryness > constants::upper_dryness_threshold) {
      Serial.println("Switching to watering state");
      this->to_watering(controller);
      return;
    }

    // otherwise, set to idle
    Serial.println("Switching state to Idle");
    this->to_idle(controller);
  }

  this->sleep(constants::water_empty_sleep_duration);
}
