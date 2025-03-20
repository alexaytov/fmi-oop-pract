#include <catch2/catch_test_macros.hpp>
#include "../src/functions/functions.h"

TEST_CASE( "Addition() returns correct value with positive numbers and negative numbers" ) {

    REQUIRE( Addition( -1, -1 ) == -2 );
    REQUIRE( Addition( -1, 0 ) == -1 );
    REQUIRE( Addition( 0, -1 ) == -1 );
    REQUIRE( Addition( -5, 38 ) == 33 );
    REQUIRE( Addition( 45, -49 ) == -4);
}

TEST_CASE( "Addition() returns correct values with large numbers" ) {

    CHECK( Addition( -2239, -8107 ) == -10346 );
    CHECK( Addition( -2950, 5347 ) ==  2397 );
    CHECK( Addition( 4127, 6352 ) == 10479 );
}