#include "sensors/Moisture_Sensor.h"
#include "secrets.h"
#define MOISTURE_PIN 4
#define ULTRASONIC_TRIG_PIN 5
#define ULTRASONIC_ECHO_PIN 6
#define PUMP_RELAY_PIN 7
#define WATER_LOW_PIN 8
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include "sensors/Moisture_Sensor.cpp"
#include "sensors/Ultrasonic_Sensor.h"
#include "sensors/Ultrasonic_Sensor.cpp"
#include "sensors/Wifi_Heat_Detector.h"
#include "sensors/Wifi_Heat_Detector.cpp"
#include "actuators/Pump_Relay.h"
#include "actuators/Pump_Relay.cpp"
#include "actuators/LED.h"
#include "actuators/LED.cpp"
#include "controller/Controller.h"
#include "controller/Controller.cpp"
#include "states/Idle.h"
#include "states/Idle.cpp"
#include "states/Watering.h"
#include "states/Watering.cpp"
#include "states/Water_Empty.h"
#include "states/Water_Empty.cpp"
#include "states/Idle_Hot_Day.h"
#include "states/Idle_Hot_Day.cpp"
#include "wifi/Wifi_Manager.h"
#include "wifi/Wifi_Manager.cpp"
#include "logger/AdaFruit.h"
#include "logger/AdaFruit.cpp"
#include "logger/Logger.h"
#include "logger/Logger.cpp"

auto pump_relay = PumpRelay(PUMP_RELAY_PIN);
auto moisture_sensor = MoistureSensor(MOISTURE_PIN);
auto ultrasonic_sensor = UltrasonicSensor(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN);
auto wifi_heat_detector = WifiHeatDetector(OPEN_WEATHER_API_KEY, LATUTUDE, LONGITUDE);
auto water_low_led = LED(WATER_LOW_PIN);
auto controller = Controller();
auto initial_state = Idle();
auto wifi_manager = WifiManager(WIFI_SSID, WIFI_PASSWORD);
auto adafruit = AdaFruit(IO_USERNAME, AIO_SERVER, IO_KEY, AIO_SERVERPORT);
auto console_logger = Logger();


void setup() {
  Serial.begin(9600);
  controller.addMoistureSensor(&moisture_sensor);
  controller.addUltrasonic(&ultrasonic_sensor);
  controller.addPumpRelay(&pump_relay);
  controller.addWaterLowLED(&water_low_led);
  controller.addHeatDetector(&wifi_heat_detector);
  controller.registerObserver(&adafruit);
  controller.registerObserver(&console_logger);
  controller.setState(&initial_state);
  wifi_manager.connect();
  adafruit.connect();
  adafruit.addFeed("moisture");
  adafruit.addFeed("water_level");
  adafruit.addFeed("temperature");
}

void loop() {
  controller.step();
  delay(5000);
}
