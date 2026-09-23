#include "FaultDetector.h"
#include "../constants.h"
#include "FaultStatus.h"
#include "HardwareSerial.h"
#include <string>
#include <vector>
void FaultDetector::notify(std::string event, std::string data_string) {
  // convert data to double, (error handling?)
  double data = std::stod(data_string);

  // DRYNESS
  // -------------
  if (event == constants::event_dryness) {
    if (data > 4000 || data < 500) {
      this->dryness_faulty = true;
    } else {
      this->dryness_faulty = false;
    }
    this->dryness_readings.push_back(data);
    if (this->dryness_readings.size() > constants::max_on_device_readings) {
      this->dryness_readings.pop_front();
    }

    // WATER LEVEL
    // ------------
  } else if (event == constants::event_water_level) {
    if (data > 50 || data < 0) {
      this->water_level_faulty = true;
    } else {
      this->water_level_faulty = false;
    }
    this->water_level_readings.push_back(data);
    if (this->water_level_readings.size() > constants::max_on_device_readings) {
      this->water_level_readings.pop_front();
    }

    // TEMPERATURE
    // ------------
  } else if (event == constants::event_temperature) {
    if (data > 500 || data < 50) {
      this->heat_faulty = true;
    } else {
      this->heat_faulty = false;
    }
    this->heat_readings.push_back(data);
    if (this->heat_readings.size() > constants::max_on_device_readings) {
      this->heat_readings.pop_front();
    }

    // NO MATCH
    // ---------
  } else {
    Serial.println("event name doesn't match any constants");
  }
}

std::vector<FaultStatus> FaultDetector::status() {
  std::vector<FaultStatus> faults;
  if (this->dryness_faulty) {
    faults.push_back(FaultStatus::dryness);
  }
  if (this->water_level_faulty) {
    faults.push_back(FaultStatus::water_level);
  }
  if (this->heat_faulty) {
    faults.push_back(FaultStatus::temperature);
  }
  // check range, if sensor values dont change then something is broken
  return faults;
}
