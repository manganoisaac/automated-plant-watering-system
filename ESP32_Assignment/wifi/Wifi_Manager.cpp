// Includes
#include "Wifi_Manager.h"
#include "Arduino.h"
#include "WiFiType.h"
#include <WiFi.h>
#include <string>

// Stores the wifi credentials
WifiManager::WifiManager(std::string SSID, std::string password)
    : SSID(SSID), password(password) {}

// Connects to wifi and blocks here until it succeeds
void WifiManager::connect() {
  WiFi.begin(String(SSID.c_str()), String(password.c_str()));
  Serial.println("Connecting to wifi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println("Connected");
}

// Checks if wifi is currently connected
bool WifiManager::isConnected() {
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }
  return false;
}
