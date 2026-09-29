// Header guard
#ifndef CONTROLLER_H
#define CONTROLLER_H

// Includes
#include "../actuators/IActuator.h"
#include "../logger/FaultDetector.h"
#include "../logger/FaultStatus.h"
#include "../logger/IObserver.h"
#include "../sensors/ISensor.h"
#include "../states/IState.h"
#include <string>
#include <vector>

// Hub that holds the sensors/actuators and lets the states use them
class Controller {
private:
  FaultDetector *fault_detector;
  ISensor *ultrasonic_sensor;
  ISensor *moisture_sensor;
  ISensor *heat_detector;
  IActuator *pump_relay;
  IActuator *water_low_led;
  IActuator *idle_or_watering_led;
  IActuator *hot_day_led;
  IActuator *error_led;
  IActuator *alert_buzzer;
  IState *state;                      // Current state in the state machine
  std::vector<IObserver *> observers; // Listening for events

public:
  void setState(IState *state);

  void addUltrasonic(ISensor *ultrasonic_sensor);

  void addMoistureSensor(ISensor *moisture_sensor);

  void addPumpRelay(IActuator *pump_relay);

  void addWaterLowLED(IActuator *water_low_led);

  void addErrorLED(IActuator *error_led);

  void addIdleOrWateringLED(IActuator *idle_or_watering_led);

  void addHotDayLED(IActuator *hot_day_led);

  void addAlertBuzzer(IActuator *alert_buzzer);

  void addHeatDetector(ISensor *heat_detector);

  void addFaultDetector(FaultDetector *fault_detector);

  void registerObserver(IObserver *observer);

  void notify(std::string event, std::string data);

  float readUltrasonic();

  float readMoisture();

  float readHeatDetector();

  std::vector<FaultStatus> readFaultDetector();

  void pumpOn();

  void pumpOff();

  void waterLowOn();

  void waterLowOff();

  void idleOrWateringOn();

  void hotDayOn();

  void errorOn();

  void alertBuzzerOn();

  void resetLEDs();

  void step();
};

#endif // !CONTROLLER_H
