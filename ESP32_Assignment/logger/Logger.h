#ifndef LOGGER_H

#define LOGGER_H

#include "Arduino.h"
#include "HardwareSerial.h"
#include "IObserver.h"
#include <string>

class Logger : public IObserver {
public:
  void notify(std::string event, std::string data);
};

#endif // !LOGGER_H
