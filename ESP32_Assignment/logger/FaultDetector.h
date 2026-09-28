//Header guard
#ifndef FAULT_DETECTOR_H
#define FAULT_DETECTOR_H

//Includes
#include "FaultStatus.h"
#include "IObserver.h"
#include <deque>
#include <queue>
#include <vector>

//Observer that watches sensor readings and flags when one goes out of range
class FaultDetector : public IObserver {
private:
  std::deque<double> dryness_readings;
  std::deque<double> heat_readings;
  std::deque<double> water_level_readings;
  bool dryness_faulty;
  bool heat_faulty;
  bool water_level_faulty;

public:
  void notify(std::string event, std::string data);
  std::vector<FaultStatus> status();
};
#endif // !FAULT_DETECTOR_H
