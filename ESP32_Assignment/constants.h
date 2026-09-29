// Header guard (shorthand for the #ifndef/#define/#endif used elsewhere)
#pragma once
#include <string>

// Groups these constants under constants:: so they don't clash with other names
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

// Sleep Durations
// ---------------
inline constexpr int idle_sleep_duration = 2 * 60 * 60 * 1000 * 1000ULL;
inline constexpr int idle_hot_day_sleep_duration = 1 * 60 * 60 * 1000 * 1000ULL;
inline constexpr int error_sleep_duration = 20 * 60 * 1000 * 1000ULL;
inline constexpr int water_empty_sleep_duration = 20 * 60 * 1000 * 1000ULL;

// Hyper Parameters
// ---------------
inline constexpr int max_on_device_readings = 10;

// Togglable Testing Settings
// ---------------------------

// turn off to test quick state changes
inline constexpr bool sleep_enabled = true;

} // namespace constants
