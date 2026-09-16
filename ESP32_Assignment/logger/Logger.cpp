
#include "Logger.h"
#include "Arduino.h"
#include "HardwareSerial.h"
void Logger::notify(std::string event, std::string data) {
  Serial.println(String(event.c_str()) + ":");
  Serial.println(data.c_str());
}
