
//Header guard
#ifndef WIFI_HEAT_DETECTOR

#define WIFI_HEAT_DETECTOR

//Includes
#include "Heat_Detector.h"
#include "ISensor.h"
#include <string>

//Gets temperature from an online weather API instead of a physical sensor
class WifiHeatDetector : public HeatDetector {
private:
  std::string apiKey; //Weather API key
  std::string lat; //Lat of weather
  std::string lng; //Lng of weather

public:
  WifiHeatDetector(std::string apiKey, std::string lat, std::string lng);
  void setup() override;
  float read() override;
};

#endif // !HEAT_DETECTOR_H
