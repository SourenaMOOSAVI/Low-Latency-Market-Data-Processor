#ifndef LATENCYMONITOR_HPP
#define LATENCYMONITOR_HPP

#include <chrono>
#include <string>
#include "Common.hpp"

class LatencyMonitor {
public:
    static void logLatency(const TimedData& data);
};

#endif // LATENCYMONITOR_HPP