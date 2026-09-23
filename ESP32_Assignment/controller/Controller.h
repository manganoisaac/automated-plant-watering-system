#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../actuators/IActuator.h"
#include "../logger/FaultDetector.h"
#include "../logger/FaultStatus.h"
#include "../logger/IObserver.h"
#include "../sensors/ISensor.h"
#include "../states/IState.h"
#include <string>
#include <vector>
class Controller {
private:
  // TODO: Use smart pointers (unique pointers)
  FaultDetector *fault_detector;
  ISensor *ultrasonic_sensor;
  ISensor *moisture_sensor;
  ISensor *heat_detector;
  IActuator *pump_relay;
  IActuator *water_low_led;
  IState *state;
  std::vector<IObserver *> observers;

public:
  void setState(IState *state);

  void addUltrasonic(ISensor *ultrasonic_sensor);

  void addMoistureSensor(ISensor *moisture_sensor);

  void addPumpRelay(IActuator *pump_relay);

  void addWaterLowLED(IActuator *water_low_led);

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

  void step();
};

#endif // !CONTROLLER_H
