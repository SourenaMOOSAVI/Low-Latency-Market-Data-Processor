#include "LatencyMonitor.hpp"
#include <iostream>

void LatencyMonitor::logLatency(const TimedData& data) {
    auto now = std::chrono::high_resolution_clock::now();
    auto latency = std::chrono::duration_cast<std::chrono::microseconds>(now - data.timestamp).count();
    std::cout << "Latency: " << latency << " microseconds" << std::endl;
}