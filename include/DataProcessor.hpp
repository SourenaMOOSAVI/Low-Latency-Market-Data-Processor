#ifndef DATAPROCESSOR_HPP
#define DATAPROCESSOR_HPP

#include "RingBuffer.hpp"
#include "LatencyMonitor.hpp" // Include LatencyMonitor.hpp
#include <string>
#include <thread>
#include <atomic>

class DataProcessor {
public:
    DataProcessor(RingBuffer<TimedData, 1024>& buffer); // Use TimedData instead of std::string
    ~DataProcessor();

    void start(); // Start the data processor
    void stop();  // Stop the data processor

private:
    void run();   // Main processing loop

    RingBuffer<TimedData, 1024>& buffer; // Use TimedData instead of std::string
    std::thread processor_thread;
    std::atomic<bool> running{false};
};

#endif // DATAPROCESSOR_HPP