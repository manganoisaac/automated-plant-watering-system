//Includes
#include "Idle_Hot_Day.h"
#include "../constants.h"
#include "../controller/Controller.h"
#include "Arduino.h"
#include "HardwareSerial.h"
#include "Idle.h"
#include "Watering.h"

//Same checks as Idle, but also drops back to Idle once it cools down
void IdleHotDay::next(Controller *controller) {
  Serial.println("Idle Hot Day state");

  // set actuators for state
  controller->pumpOff();
  controller->waterLowOff();

  // read sensors
  auto dryness = controller->readMoisture();
  auto distance = controller->readUltrasonic();
  auto heat = controller->readHeatDetector();

  // notify observers
  controller->notify(constants::event_dryness, std::to_string(dryness));
  controller->notify(constants::event_water_level, std::to_string(distance));
  controller->notify(constants::event_temperature, std::to_string(heat));

  // is water empty
  if (distance > constants::upper_water_level_threshold) {
    Serial.println("Switching state to WATER_EMPTY");
    this->to_water_empty(controller);
    return;

    // is soil dry
  } else if (dryness > constants::upper_dryness_threshold) {
    Serial.println("Switching state to WATERING");
    this->to_watering(controller);
    return;

  } else if (heat < constants::lower_heat_threshold) {
    Serial.println("Switching to Idle");
    this->to_idle(controller);
    return;
  }
  this->sleep(60 * 60 * 1000);
}
