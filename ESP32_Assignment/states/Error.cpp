// Includes
#include "Error.h"
#include "../constants.h"
#include "../controller/Controller.h"
#include "HardwareSerial.h"
#include "IState.h"
#include "Idle.h"
#include "Idle_Hot_Day.h"
#include <string>

// Keeps the pump off and waits for the fault to clear before returning to Idle
void Error::next(Controller *controller) {
  Serial.println("Error State");

  // set actuators
  controller->resetLEDs();
  controller->errorOn();
  controller->pumpOff();
  controller->alertBuzzerOn();

  // read from sensors
  auto temperature = controller->readHeatDetector();
  auto dryness = controller->readMoisture();
  auto water_level = controller->readUltrasonic();

  // log levels
  controller->notify(constants::event_dryness, std::to_string(dryness));
  controller->notify(constants::event_temperature, std::to_string(temperature));
  controller->notify(constants::event_water_level, std::to_string(water_level));

  // check error status
  auto errors = controller->readFaultDetector();

  // switch states if no error
  if (errors.size() <= 0) {
    if (temperature < constants::upper_heat_threshold) {
      this->to_idle_hot_day(controller);
      return;

    } else {
      this->to_idle(controller);
      return;
    }
    this->sleep(constants::error_sleep_duration);
  }
}
