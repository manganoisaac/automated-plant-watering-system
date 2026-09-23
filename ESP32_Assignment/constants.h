#pragma once

#include <string>
namespace constants {
// low and high thresholds for hysterisis

// DRYNESS
// -------
inline constexpr double lower_dryness_threshold = 1500;
inline constexpr double upper_dryness_threshold = 3000;

// HEAT
// -------
inline constexpr double lower_heat_threshold = 200;
inline constexpr double upper_heat_threshold = 250;

// WATER LEVEL
// -------------
inline constexpr double lower_water_level_threshold = 15;
inline constexpr double upper_water_level_threshold = 20;

// Event Labels
// -------------
inline std::string event_dryness = "moisture";
inline std::string event_water_level = "water_level";
inline std::string event_temperature = "temperature";

// Hyper Parameters
// ---------------
inline constexpr int max_on_device_readings = 10;

// Togglable Testing Settings
// ---------------------------

// turn off to test quick state changes
inline constexpr bool sleep_enabled = true;

} // namespace constants
