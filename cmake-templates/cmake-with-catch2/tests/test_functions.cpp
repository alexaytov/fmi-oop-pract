#include <catch2/catch_test_macros.hpp>
#include "../functions.h" // Include the header file

TEST_CASE("Testing add function") {
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(-1, 1) == 0);
}