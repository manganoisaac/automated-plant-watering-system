
#ifndef WIFI_HEAT_DETECTOR

#define WIFI_HEAT_DETECTOR

#include "Heat_Detector.h"
#include "ISensor.h"
#include <string>
class WifiHeatDetector : public HeatDetector {
private:
  std::string apiKey;
  std::string lat;
  std::string lng;

public:
  WifiHeatDetector(std::string apiKey, std::string lat, std::string lng);
  void setup() override;
  float read() override;
};

#endif // !HEAT_DETECTOR_H
