// Includes
#include "StateBase.h"
#include "../constants.h"
#include "../controller/Controller.h"
#include "Error.h"
#include "Idle.h"
#include "Idle_Hot_Day.h"
#include "Water_Empty.h"
#include "Watering.h"
#include "esp_sleep.h"
#include "esp_wifi.h"

// Each to creates its state only once and switches the controller to it
void StateBase::to_error(Controller *controller) {
  static auto error_state = Error();
  controller->setState(&error_state);
};

void StateBase::to_idle(Controller *controller) {
  static auto idle_state = Idle();
  controller->setState(&idle_state);
};

void StateBase::to_idle_hot_day(Controller *controller) {
  static auto idle_hot_day = IdleHotDay();
  controller->setState(&idle_hot_day);
};

void StateBase::to_watering(Controller *controller) {
  static auto watering = Watering();
  controller->setState(&watering);
};

void StateBase::to_water_empty(Controller *controller) {
  static auto water_empty = WaterEmpty();
  controller->setState(&water_empty);
}

// Puts the ESP32 into deep sleep to save power
void StateBase::sleep(int millis) {
  if (constants::sleep_enabled) {
    Serial.println("Going to sleep");

    // set sleep duration
    esp_sleep_enable_timer_wakeup((uint64_t)millis * 1000ULL);

    // disable wifi for sleep
    esp_wifi_stop();

    // enable sleep
    // TODO: choose between light sleep and deep sleep
    esp_light_sleep_start();
    // esp_deep_sleep_start();

    // wake-up point for light sleep, never runs on deep sleep
    Serial.println("Waking up");
  }
}
