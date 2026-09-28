//Includes
#include "Logger.h"
#include "Arduino.h"
#include "HardwareSerial.h"

//Prints the event name and its data to the Serial monitor
void Logger::notify(std::string event, std::string data) {
  Serial.println(String(event.c_str()) + ":");
  Serial.println(data.c_str());
}
