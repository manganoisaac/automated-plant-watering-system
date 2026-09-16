#include "Idle.h"
#include "../controller/Controller.h"
#include "Arduino.h"
#include "HardwareSerial.h"
#include "Idle_Hot_Day.h"
#include "Water_Empty.h"
#include "Watering.h"
#include <string>

void Idle::next(Controller *controller) {
  Serial.println("Idle state");

  // set actuators for state
  controller->pumpOff();
  controller->waterLowOff();

  // read sensors
  auto moisture = controller->readMoisture();
  auto distance = controller->readUltrasonic();
  auto heat = controller->readHeatDetector();

  // send out notifications
  controller->notify("moisture", std::to_string(moisture));
  controller->notify("water_level", std::to_string(distance));
  controller->notify("temperature", std::to_string(heat));

  // is water empty
  if (distance > 100) {

    // switch to water empty state
    Serial.println("Switching state to WATER_EMPTY");
    static auto no_water = WaterEmpty();
    controller->setState(&no_water);
  } else if (moisture > 3000) {

    // soil is dry
    Serial.println("Switching state to WATERING");
    static auto next_state = Watering();
    controller->setState(&next_state);
  } else if (heat > 200) {

    // hot temperature
    Serial.println("Switching state to IDLE_HOT_DAY");
    static auto idle_hot_day = IdleHotDay();
    controller->setState(&idle_hot_day);
  }
}
