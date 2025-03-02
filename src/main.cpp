#include "UDPServer.hpp"
#include "DataProcessor.hpp"
#include "RingBuffer.hpp"
#include <iostream>

int main() {
    // Create a shared ring buffer for TimedData
    RingBuffer<TimedData, 1024> buffer; // Use TimedData instead of std::string

    // Create and start the UDP server
    UDPServer server("127.0.0.1", 12345);
    server.start();

    // Create and start the data processor
    DataProcessor processor(buffer);
    processor.start();

    // Keep the main thread alive
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();

    // Stop the server and processor
    server.stop();
    processor.stop();

    return 0;
}