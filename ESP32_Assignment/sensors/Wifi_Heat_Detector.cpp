//Includes
#include "Wifi_Heat_Detector.h"
#include "ArduinoJson.h"
#include "ArduinoJson/Document/JsonDocument.hpp"
#include "ArduinoJson/Json/JsonDeserializer.hpp"
#include <HTTPClient.h>
#include <string>

//Stores the API key and location used to look up the weather
WifiHeatDetector::WifiHeatDetector(std::string apiKey, std::string lat,
                                   std::string lng)
    : apiKey(apiKey), lat(lat), lng(lng) {}

//Nothing to set up, there's no physical pin, just an API call
void WifiHeatDetector::setup() {}

//Calls the weather API for the given location and returns the temperature
//Or -999 if the request failed
float WifiHeatDetector::read() {
  HTTPClient http;
  String url = "https://api.openweathermap.org/data/2.5/"
               "weather?lat=" +
               String(lat.c_str()) + "&lon=" + String(lng.c_str()) +
               "&appid=" + String(apiKey.c_str());
  http.begin(url);

  int code = http.GET();
  if (code == 200) {
    JsonDocument doc;
    deserializeJson(doc, http.getStream());
    float temp = doc["main"]["temp"];
    http.end();
    return temp;
  }

  return -999.0;
}
