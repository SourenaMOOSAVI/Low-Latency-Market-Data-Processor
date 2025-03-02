#include <catch2/catch_all.hpp> // Do not define CATCH_CONFIG_MAIN here

#include "UDPServer.hpp"

TEST_CASE("UDPServer start and stop", "[UDPServer]") {
    UDPServer server("127.0.0.1", 12345);

    SECTION("Start and stop server") {
        server.start();
        REQUIRE_NOTHROW(server.stop());
    }
}