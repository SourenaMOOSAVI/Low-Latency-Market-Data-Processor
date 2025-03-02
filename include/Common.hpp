#ifndef COMMON_HPP
#define COMMON_HPP

#include <chrono>
#include <string>

// Common data structure for timed market data
struct TimedData {
    std::string data; // The actual data (e.g., market data)
    std::chrono::high_resolution_clock::time_point timestamp; // Timestamp when the data was sent
};

#endif // COMMON_HPP