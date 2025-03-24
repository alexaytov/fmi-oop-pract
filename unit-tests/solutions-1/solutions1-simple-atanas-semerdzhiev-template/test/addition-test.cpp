#include <catch2/catch_test_macros.hpp>
#include "library.h"

// Тестване с положителни числа:
TEST_CASE( "Addition() returns correct value with positive numbers" ) {

    // Постепенно тестваме с по-големи числа:
    REQUIRE( Addition( 1, 1 ) == 2 );
    REQUIRE( Addition( 3, 5 ) == 8 );
    REQUIRE( Addition( 46, 42 ) == 88 );
}

// Тестване с положителни и отрицателни числа:
TEST_CASE( "Addition() returns correct value with positive numbers and negative numbers" ) {

    REQUIRE( Addition( -1, -1 ) == -2 );
    REQUIRE( Addition( -1, 0 ) == -1 );
    REQUIRE( Addition( 0, -1 ) == -1 );
    REQUIRE( Addition( -5, 38 ) == 33 );
    REQUIRE( Addition( 45, -49 ) == -4);
}

// Тестване с големи числа:
TEST_CASE( "Addition() returns correct values with large numbers" ) {

    // Използваме CHECK(...), тъй като в случая тестовете са независими
    // (тестваме с еднакво големи, различни числа):
    CHECK( Addition( -2239, -8107 ) == -10346 );
    CHECK( Addition( -2950, 5347 ) ==  2397 );
    CHECK( Addition( 4127, 6352 ) == 10479 );
}