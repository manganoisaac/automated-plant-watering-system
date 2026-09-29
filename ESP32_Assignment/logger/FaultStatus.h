//Header guard
#ifndef FAULT_STATUS_H
#define FAULT_STATUS_H

//The possible things FaultDetector can flag as faulty
enum class FaultStatus {
  water_level = 0,
  dryness,
  temperature,
};
#endif // !FAULT_STATUS_H
