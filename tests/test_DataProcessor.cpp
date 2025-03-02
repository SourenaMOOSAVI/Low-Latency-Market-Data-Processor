#include <catch2/catch_all.hpp> // Do not define CATCH_CONFIG_MAIN here

#include "DataProcessor.hpp"
#include "RingBuffer.hpp"
#include "Common.hpp"

TEST_CASE("DataProcessor start and stop", "[DataProcessor]") {
    RingBuffer<TimedData, 1024> buffer;
    DataProcessor processor(buffer);

    SECTION("Start and stop processor") {
        processor.start();
        REQUIRE_NOTHROW(processor.stop());
    }
}