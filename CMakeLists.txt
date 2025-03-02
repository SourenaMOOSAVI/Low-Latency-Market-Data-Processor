cmake_minimum_required(VERSION 3.14)
project(LowLatencyMarketDataProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Add Boost dependency
find_package(Boost REQUIRED COMPONENTS system)

# Add Catch2 dependency
find_package(Catch2 REQUIRED)

# Add Google Benchmark dependency
find_package(benchmark REQUIRED)

# Main executable
add_executable(market_data_processor
    src/main.cpp
    src/UDPServer.cpp
    src/DataProcessor.cpp
    src/LatencyMonitor.cpp
)
target_link_libraries(market_data_processor Boost::system)

# Tests
enable_testing()
add_executable(test_RingBuffer tests/test_RingBuffer.cpp)
target_link_libraries(test_RingBuffer Catch2::Catch2 Catch2::Catch2WithMain)

add_executable(test_UDPServer tests/test_UDPServer.cpp src/UDPServer.cpp)
target_link_libraries(test_UDPServer Catch2::Catch2 Catch2::Catch2WithMain Boost::system)

add_executable(test_DataProcessor tests/test_DataProcessor.cpp src/DataProcessor.cpp src/LatencyMonitor.cpp)
target_link_libraries(test_DataProcessor Catch2::Catch2 Catch2::Catch2WithMain)

# Benchmark
add_executable(benchmark_RingBuffer benchmarks/benchmark_RingBuffer.cpp)
target_link_libraries(benchmark_RingBuffer benchmark::benchmark)