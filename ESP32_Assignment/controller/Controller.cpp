#include "Controller.h"
#include "../actuators/IActuator.h"
#include "../logger/FaultDetector.h"
#include "../logger/FaultStatus.h"
#include "../states/IState.h"
#include <vector>

void Controller::setState(IState *state) { this->state = state; }

void Controller::addUltrasonic(ISensor *ultrasonic_sensor) {
  this->ultrasonic_sensor = ultrasonic_sensor;
  this->ultrasonic_sensor->setup();
}

void Controller::addMoistureSensor(ISensor *moisture_sensor) {
  this->moisture_sensor = moisture_sensor;
  this->moisture_sensor->setup();
}

void Controller::addPumpRelay(IActuator *pump_relay) {
  this->pump_relay = pump_relay;
  this->pump_relay->setup();
}

void Controller::addWaterLowLED(IActuator *water_low_led) {
  this->water_low_led = water_low_led;
  this->water_low_led->setup();
}

void Controller::addErrorLED(IActuator *error_led) {
  this->error_led = error_led;
  this->error_led->setup();
}

void Controller::addIdleOrWateringLED(IActuator *idle_or_watering_led) {
  this->idle_or_watering_led = idle_or_watering_led;
  this->idle_or_watering_led->setup();
}

void Controller::addHotDayLED(IActuator *hot_day_led) {
  this->hot_day_led = hot_day_led;
  this->hot_day_led->setup();
}

void Controller ::addAlertBuzzer(IActuator *alert_buzzer) {
  this->alert_buzzer = alert_buzzer;
  this->alert_buzzer->setup();
}

void Controller::addHeatDetector(ISensor *heat_detector) {
  this->heat_detector = heat_detector;
  this->heat_detector->setup();
}

void Controller::addFaultDetector(FaultDetector *fault_detector) {
  this->fault_detector = fault_detector;
}

void Controller::registerObserver(IObserver *observer) {
  observers.push_back(observer);
};

void Controller::notify(std::string event, std::string data) {
  for (auto observer : observers) {
    observer->notify(event, data);
  }
}

float Controller::readUltrasonic() { return ultrasonic_sensor->read(); }

float Controller::readMoisture() { return moisture_sensor->read(); }

float Controller::readHeatDetector() { return heat_detector->read(); }

std::vector<FaultStatus> Controller::readFaultDetector() {
  return fault_detector->status();
}

void Controller::pumpOn() { pump_relay->turnOn(); }

void Controller::pumpOff() { pump_relay->turnOff(); }

void Controller::waterLowOn() { water_low_led->turnOn(); }

void Controller::waterLowOff() { water_low_led->turnOff(); }

void Controller::idleOrWateringOn() { idle_or_watering_led->turnOn(); }

void Controller::hotDayOn() { hot_day_led->turnOn(); }

void Controller::errorOn() { error_led->turnOn(); }

void Controller::alertBuzzerOn() { alert_buzzer->turnOn(); }

void Controller::resetLEDs() {
  water_low_led->turnOff();
  idle_or_watering_led->turnOff();
  hot_day_led->turnOff();
  error_led->turnOff();
  alert_buzzer->turnOff();
}

void Controller::step() { state->next(this); }
