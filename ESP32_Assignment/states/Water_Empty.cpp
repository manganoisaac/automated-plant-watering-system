#include "Water_Empty.h"
#include "../controller/Controller.h"
#include "Arduino.h"
#include "HardwareSerial.h"
#include "Idle.h"
#include "Watering.h"
void WaterEmpty::next(Controller *controller) {

  Serial.println("Water empty state");

  // set actuators for state
  controller->pumpOff();
  controller->waterLowOn();

  // read sensors
  auto distance = controller->readUltrasonic();

  // notify observers
  controller->notify("water_level", std::to_string(distance));

  // is water refilled
  if (distance < 100) {

    // check moisture
    auto moisture = controller->readMoisture();

    controller->notify("moisture", std::to_string(moisture));

    // if soil is dry, set to watering state
    if (moisture < 3000) {
      Serial.println("Switching to watering state");
      static auto watering_state = Watering();
      controller->setState(&watering_state);
      return;
    }

    // otherwise, set to idle
    Serial.println("Switching state to Idle");
    static auto idle_state = Idle();
    controller->setState(&idle_state);
  }
}
