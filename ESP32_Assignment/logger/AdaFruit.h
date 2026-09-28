//Header guard
#ifndef ADAFRUIT_H

#define ADAFRUIT_H

//Includes
#include "IObserver.h"
#include "WiFiClient.h"
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <map>
#include <string>
#include <vector>

//Observer that publishes events to Adafruit IO over MQTT
class AdaFruit : public IObserver {
private:
  std::string username;
  std::string server;
  std::string key;
  int port;
  WiFiClient wifi_client;
  Adafruit_MQTT_Client *mqtt;
  std::map<std::string, Adafruit_MQTT_Publish *> feeds; //Feed name -> feed to publish to

public:
  AdaFruit(std::string username, std::string server, std::string key, int port);

  void notify(std::string event, std::string data) override;
  void connect();
  bool isConnected();
  void addFeed(std::string feedName);
};

#endif // !ADAFRUIT_H
