#include "AdaFruit.h"
#include "Arduino.h"
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <WiFiClient.h>
#include <cstring>

AdaFruit::AdaFruit(std::string username, std::string server, std::string key,
                   int port)
    : username(username), server(server), key(key), port(port) {
  this->mqtt =
      new Adafruit_MQTT_Client(&wifi_client, this->server.c_str(), this->port,
                               this->username.c_str(), this->key.c_str());
}

void AdaFruit::connect() {
  Serial.println("connecting to adafruit");
  while (mqtt->connect() != 0) {
    delay(1000);
    Serial.println("connecting to MQTT...");
  }
}

void AdaFruit::notify(std::string event, std::string data) {
  if (feeds.count(event)) {

    feeds[event]->publish(data.c_str());
  }
}

void AdaFruit::addFeed(std::string feedName) {
  std::string topic = username + "/feeds/" + feedName;

  auto newFeed = new Adafruit_MQTT_Publish(mqtt, strdup(topic.c_str()));
  feeds[feedName] = newFeed;
}
