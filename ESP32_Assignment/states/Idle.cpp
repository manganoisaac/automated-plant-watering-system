#include "Idle.h"
#include "../constants.h"
#include "../controller/Controller.h"
#include "Arduino.h"
#include "Error.h"
#include "HardwareSerial.h"
#include "Idle_Hot_Day.h"
#include "Water_Empty.h"
#include "Watering.h"
#include "esp_sleep.h"
#include <string>

void Idle::next(Controller *controller) {
  Serial.println("Idle state");

  // set actuators for state
  controller->pumpOff();
  controller->waterLowOff();

  // read sensors
  auto dryness = controller->readMoisture();
  auto distance = controller->readUltrasonic();
  auto heat = controller->readHeatDetector();

  // send out notifications
  controller->notify(constants::event_dryness, std::to_string(dryness));
  controller->notify(constants::event_water_level, std::to_string(distance));
  controller->notify(constants::event_temperature, std::to_string(heat));

  // check error status
  auto errors = controller->readFaultDetector();

  // if error go to error state
  if (errors.size() > 0) {
    this->to_error(controller);
    return;
  }

  // is water empty
  else if (distance > constants::upper_water_level_threshold) {
    Serial.println("Switching state to WATER_EMPTY");
    this->to_water_empty(controller);
    return;

    // soil is dry
  } else if (dryness > constants::upper_dryness_threshold) {
    Serial.println("Switching state to WATERING");
    this->to_watering(controller);
    return;

    // hot temperature
  } else if (heat > constants::upper_heat_threshold) {
    Serial.println("Switching state to IDLE_HOT_DAY");
    this->to_idle_hot_day(controller);
    return;
  }

  this->sleep(60 * 60 * 1000);
}
