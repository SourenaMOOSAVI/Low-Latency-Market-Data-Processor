#include "DataProcessor.hpp"
#include "LatencyMonitor.hpp"
#include <iostream>

DataProcessor::DataProcessor(RingBuffer<TimedData, 1024>& buffer)
    : buffer(buffer) {}

DataProcessor::~DataProcessor() {
    stop();
}

void DataProcessor::start() {
    running.store(true);
    processor_thread = std::thread(&DataProcessor::run, this);
}

void DataProcessor::stop() {
    running.store(false);
    if (processor_thread.joinable()) {
        processor_thread.join();
    }
}

void DataProcessor::run() {
    TimedData item;
    while (running.load()) {
        if (buffer.pop(item)) {
            // Process the item (e.g., parse market data)
            std::cout << "Processed: " << item.data << std::endl;

            // Log the latency
            LatencyMonitor::logLatency(item);
        }
    }
}