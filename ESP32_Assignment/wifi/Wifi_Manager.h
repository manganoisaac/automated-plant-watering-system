#ifndef WIFI_MANAGER_H

#define WIFI_MANAGER_H

#include <string>
class WifiManager {
private:
  std::string SSID;
  std::string password;

public:
  WifiManager(std::string SSID, std::string password);
  void connect();
  bool isConnected();
};

#endif // !WIFI_MANAGER_H
