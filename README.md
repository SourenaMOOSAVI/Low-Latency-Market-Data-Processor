Low-Latency Market Data Processor
=================================

This project demonstrates the implementation of a low-latency market data processing system using modern C++ techniques. It simulates a high-frequency trading (HFT) environment where market data (e.g., stock prices or order book updates) is ingested, processed, and analyzed with minimal delay. The system leverages UDP-based communication, lock-free data structures, multi-threading, and performance optimization techniques to achieve ultra-low latency.

Key Features
------------

1. Real-Time Data Ingestion

    * **UDP-Based Server**: A UDP server is used to simulate a market data feed. UDP is chosen for its low overhead and suitability for high-frequency, low-latency applications.

    * **Binary Protocol**: Data is transmitted in a binary format for efficient serialization and deserialization, reducing processing time.

    Where It’s Used in the project

    * The `UDPServer` class in `src/UDPServer.cpp` implements the UDP server.

    * Market data is simulated as strings (e.g., `STOCK_A,100.50`) and sent over UDP using `Boost.Asio`.

2. Low-Latency Processing

    * **Lock-Free Data Structures**: A lock-free ring buffer is used to exchange data between the producer (UDP server) and consumer (data processor) threads. This avoids the overhead of locks and ensures minimal latency.

    * **Minimal Delay**: Data is processed as soon as it is received, with no unnecessary delays.

    Where It’s Used in the project

    * The `RingBuffer` class in `include/RingBuffer.hpp` implements the lock-free ring buffer.

    * The `DataProcessor` class in `src/DataProcessor.cpp` consumes data from the ring buffer and processes it.

3. Multi-Threading

    * Producer-Consumer Model: The system uses a multi-threaded architecture:

        * Producer Thread: Receives data from the UDP server and pushes it into the ring buffer.

        * Consumer Thread: Processes data from the ring buffer.

    * Thread Safety: The ring buffer ensures thread-safe data exchange without locks.

    Where It’s Used in the project

    * The `UDPServer` class runs in a separate thread to receive data.

    * The `DataProcessor` class runs in a separate thread to process data.

    * Thread synchronization is handled by the lock-free ring buffer.

4. Performance Optimization

    * **Memory Management**: The ring buffer uses a fixed-size array to avoid dynamic memory allocations, reducing latency and fragmentation.

    * **CPU Cache Efficiency**: Data is stored in contiguous memory to minimize cache misses.

    * **Modern C++ Features**: The project uses `std::atomic`, `std::thread`, and `std::mutex` for efficient and safe concurrency.

    Where It’s Used in the project

    * The `RingBuffer` class uses a fixed-size `std::array` for storage.

    * The `std::atomic` type is used for the `head` and `tail` indices in the ring buffer.

    * The `std::thread` class is used to create and manage threads.

    * The `std::mutex` class is used for synchronization in the ring buffer.

5. Latency Measurement

    * **End-to-End Latency**: The system measures the time taken from data generation (in the UDP server) to data processing (in the data processor).

    * **Logging**: Latency metrics are logged for analysis and optimization.

    Where It’s Used in the project

    * The LatencyMonitor class in src/LatencyMonitor.cpp calculates and logs latency.

    * Each data packet is timestamped when it is generated and when it is processed.

Project Structure
-----------------

```plaintext
LowLatencyMarketDataProcessor/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── RingBuffer.hpp
│   ├── UDPServer.hpp
│   ├── DataProcessor.hpp
│   ├── LatencyMonitor.hpp
│   └── Common.hpp
├── src/
│   ├── main.cpp
│   ├── UDPServer.cpp
│   ├── DataProcessor.cpp
│   ├── LatencyMonitor.cpp
├── tests/
│   ├── test_RingBuffer.cpp
│   ├── test_UDPServer.cpp
│   └── test_DataProcessor.cpp
├── benchmarks/
│   └── benchmark_RingBuffer.cpp
└── scripts/
    └── run_tests.sh
```

Building the Project
--------------------

1. Prerequisites:

    * C++17-compatible compiler (e.g., GCC, Clang).

    * CMake (version 3.14 or higher).

    * Boost.Asio (for networking).

    * Catch2 (for testing).

    * Google Benchmark (for benchmarking).

2. Build Instructions:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. Run the Tests:

    ```bash
    ./scripts/run_tests.sh
    ```

4. Run the Benchmark:

    ```bash
    ./build/benchmark_RingBuffer
    ```

5. Run the Main Executable:

    ```bash
    ./market_data_processor
    ```

Concepts Covered
----------------

1. UDP-Based Server

    * **Why UDP?**: UDP is connectionless and has lower overhead compared to TCP, making it ideal for low-latency applications.

    * **Implementation**: The UDPServer class uses Boost.Asio to send and receive data over UDP.

2. Binary Protocol

    * **Efficiency**: Binary protocols are faster to serialize and deserialize compared to text-based protocols.

    * **Implementation**: Data is transmitted as raw bytes, and the receiver reconstructs it into the appropriate format.

3. Lock-Free Programming

    * **Why Lock-Free?**: Lock-free data structures avoid the overhead of locks, reducing contention and improving performance.

    * **Implementation**: The RingBuffer class uses atomic operations (std::atomic) to ensure thread safety.

4. Multi-Threading

    * **Producer-Consumer Model**: Separates data ingestion (producer) from data processing (consumer) to improve throughput.

    * **Implementation**: The UDPServer and DataProcessor classes run in separate threads.

5. Performance Optimization

    * **Memory Pools**: Fixed-size arrays are used to avoid dynamic memory allocation.

    * **Cache Efficiency**: Data is stored in contiguous memory to minimize cache misses.

    * **Modern C++**: Features like std::atomic, std::thread, and std::mutex are used for efficient concurrency.

6. Latency Measurement

    * **End-to-End Latency**: Measures the time taken for data to travel from the producer to the consumer.

    * **Implementation**: The LatencyMonitor class calculates and logs latency metrics.

Future Enhancements
-------------------

1. **Hardware Acceleration**: Explore FPGA or GPU acceleration for further performance improvements.

2. **Kernel Bypass**: Use kernel-bypass technologies like DPDK or XDP for even lower latency.

3. **Distributed Processing**: Extend the system to handle distributed data processing across multiple nodes.

Contributing
------------

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bugfix (`git checkout -b feature-branch`).
3. Submit a pull request with a description of your changes.

License
-------

This project is licensed under the MIT License. See the [LICENSE](https://github.com/SourenaMOOSAVI/Low-Latency-Market-Data-Processor?tab=MIT-1-ov-file#readme) file for details.
