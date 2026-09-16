#ifndef ADAFRUIT_H

#define ADAFRUIT_H

#include "IObserver.h"
#include "WiFiClient.h"
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <map>
#include <string>
#include <vector>

class AdaFruit : public IObserver {
private:
  std::string username;
  std::string server;
  std::string key;
  int port;
  WiFiClient wifi_client;
  Adafruit_MQTT_Client *mqtt;
  std::map<std::string, Adafruit_MQTT_Publish *> feeds;

public:
  AdaFruit(std::string username, std::string server, std::string key, int port);

  void notify(std::string event, std::string data) override;
  void connect();
  void addFeed(std::string feedName);
};

#endif // !ADAFRUIT_H
