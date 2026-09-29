//Header guard
#ifndef LOGGER_H
#define LOGGER_H

//Includes
#include "Arduino.h"
#include "HardwareSerial.h"
#include "IObserver.h"
#include <string>

//Observer that prints events to the Serial monitor
class Logger : public IObserver {
public:
  void notify(std::string event, std::string data);
};

#endif // !LOGGER_H
