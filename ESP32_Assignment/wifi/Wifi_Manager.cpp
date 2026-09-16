#include "Wifi_Manager.h"
#include "Arduino.h"
#include "WiFiType.h"
#include <WiFi.h>
#include <string>

WifiManager::WifiManager(std::string SSID, std::string password)
    : SSID(SSID), password(password) {}

void WifiManager::connect() {
  WiFi.begin(String(SSID.c_str()), String(password.c_str()));
  Serial.println("Connecting to wifi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println("Connected");
}

bool WifiManager::isConnected() {
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }
  return false;
}
