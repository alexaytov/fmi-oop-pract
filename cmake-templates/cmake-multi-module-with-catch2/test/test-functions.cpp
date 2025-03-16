#include <catch2/catch_test_macros.hpp>
#include "../src/functions/functions.h"

TEST_CASE("Testing add function") {
    REQUIRE(add(2, 3) == 5);
}