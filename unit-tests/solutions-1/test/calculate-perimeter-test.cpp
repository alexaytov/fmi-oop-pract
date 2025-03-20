#include <catch2/catch_test_macros.hpp>
#include "../src/functions/functions.h"

TEST_CASE( "CalculatePerimeter() returns correct code values on negative numbers" ) {

    SECTION( "Single number is < 0" ) {

        CHECK( CalculatePerimeter( -1, 1, 1 ) == -1 );
        CHECK( CalculatePerimeter( 1, -1, 1 ) == -10 );
        CHECK( CalculatePerimeter( 1, 1, -1 ) == -100 );
    }

    SECTION( "Two numbers are < 0" ) {

        CHECK( CalculatePerimeter( -1, -1, 1 ) == -11 );
        CHECK( CalculatePerimeter( -1, 1, -1 ) == -101 );
        CHECK( CalculatePerimeter( 1, -1, -1 ) == -110 );
    }

    SECTION( "All numbers are < 0" ) {
    
        CHECK( CalculatePerimeter( -1, -1, -1 ) == -111 );
    }
}

TEST_CASE(
    "CalculatePerimeter() returns correct code values on triangle inequality condition" 
)
{
    CHECK( CalculatePerimeter( 3, 1, 1 ) == -200 );
    CHECK( CalculatePerimeter( 1, 3, 1 ) == -200 );
    CHECK( CalculatePerimeter( 1, 1, 3 ) == -200 );
}

TEST_CASE( "CalculatePerimeter() behaves correctly on valid values" ) {

    REQUIRE( CalculatePerimeter( 2, 3, 4 ) == 9 );
    REQUIRE( CalculatePerimeter( 3554, 4894, 5145 ) == 13593 );
    REQUIRE( CalculatePerimeter( 10654, 22632, 30474 ) == 63760 );
}