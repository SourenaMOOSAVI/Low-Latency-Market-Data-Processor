#define CATCH_CONFIG_MAIN // Define the main function for Catch2
#include <catch2/catch_all.hpp>

#include "RingBuffer.hpp"
#include "Common.hpp"

TEST_CASE("RingBuffer push and pop", "[RingBuffer]") {
    RingBuffer<TimedData, 1024> buffer;
    TimedData item;

    SECTION("Push and pop single item") {
        REQUIRE(buffer.push({"test", std::chrono::high_resolution_clock::now()}));
        REQUIRE(buffer.pop(item));
        REQUIRE(item.data == "test");
    }

    SECTION("Buffer full") {
        for (int i = 0; i < 10; ++i) {
            REQUIRE(buffer.push({"data" + std::to_string(i), std::chrono::high_resolution_clock::now()}));
        }
        REQUIRE_FALSE(buffer.push({"overflow", std::chrono::high_resolution_clock::now()}));
    }

    SECTION("Buffer empty") {
        REQUIRE_FALSE(buffer.pop(item));
    }
}