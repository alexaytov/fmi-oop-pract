#include <catch2/catch_all.hpp>
#include "../functions.h" // Include the header file

TEST_CASE("Testing add function", "[add]") {
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(-1, 1) == 0);
}