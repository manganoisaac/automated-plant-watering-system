//Includes
#include "Controller.h"
#include "../actuators/IActuator.h"
#include "../logger/FaultDetector.h"
#include "../logger/FaultStatus.h"
#include "../states/IState.h"
#include <vector>

void Controller::setState(IState *state) { this->state = state; }

//Each add stores the device and calls its setup()
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

//Tells every registered observer (e.g. logger) that an event happened
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

//Moves the state machine forward by one step
void Controller::step() { state->next(this); }
