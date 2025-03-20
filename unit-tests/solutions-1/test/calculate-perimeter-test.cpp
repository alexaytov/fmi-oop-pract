#include <catch2/catch_test_macros.hpp>
#include "../src/functions/functions.h"

// Тестваме всички комбинации от случаи, в които един един,
// или повече от аргументите са с отрицателна стойност:
TEST_CASE( "CalculatePerimeter() returns correct code values on negative numbers" ) {

    // Във всяка секция сме обособили всеки подслуай:

    SECTION( "Single number is < 0" ) {
        
        // а < 0: (-1)
        CHECK( CalculatePerimeter( -1, 1, 1 ) == -1 );
        // b < 0: (-10)
        CHECK( CalculatePerimeter( 1, -1, 1 ) == -10 );
        // c < 0: (-100)
        CHECK( CalculatePerimeter( 1, 1, -1 ) == -100 );
    }

    SECTION( "Two numbers are < 0" ) {

        // a, b < 0: (-1) + (-10)
        CHECK( CalculatePerimeter( -1, -1, 1 ) == -11 );
        // a, c < 0: (-1) + (-100)
        CHECK( CalculatePerimeter( -1, 1, -1 ) == -101 );
        // b, c < 0: (-10) + (-100)
        CHECK( CalculatePerimeter( 1, -1, -1 ) == -110 );
    }

    SECTION( "All numbers are < 0" ) {
    
        // a, b, c < 0: (-1) + (-10) + (-100)
        CHECK( CalculatePerimeter( -1, -1, -1 ) == -111 );
    }
}

// Тестваме всички комбинации от случаи, в които е / не е
// изпълнено правилото на триъгълника:
TEST_CASE(
    "CalculatePerimeter() returns correct code values on triangle inequality condition" 
)
{
    // Една от страните е по-голяма от сумата на другите две:
    SECTION( "One of the three sides is greater than the other two" ) {

        // a > b + c
        CHECK( CalculatePerimeter( 3, 1, 1 ) == -200 );
        // b > a + c
        CHECK( CalculatePerimeter( 1, 3, 1 ) == -200 );
        // c > a + b
        CHECK( CalculatePerimeter( 1, 1, 3 ) == -200 );
    }

    // Една от страните е равна на сумата на другите две:
    SECTION( "One of the three sides is equal to the other two" ) {

        // a = b + c
        CHECK( CalculatePerimeter( 2, 1, 1 ) == -200 );
        // b = a + c
        CHECK( CalculatePerimeter( 1, 2, 1 ) == -200 );
        // c = a + b
        CHECK( CalculatePerimeter( 1, 1, 2 ) == -200 );
    }

    // Неравенството е удовлетворено:
    SECTION( "The inequality is satisfied" ) {

        // a + b > c
        CHECK( CalculatePerimeter( 2, 3, 4 ) >= 0 );
        // b + c > a
        CHECK( CalculatePerimeter( 4, 2, 3 ) >= 0 );
        // a + c > b
        CHECK( CalculatePerimeter( 3, 4, 2 ) >= 0 );
    }
}

TEST_CASE( "CalculatePerimeter() behaves correctly on valid values" ) {

    REQUIRE( CalculatePerimeter( 2, 3, 4 ) == 9 );
    REQUIRE( CalculatePerimeter( 3554, 4894, 5145 ) == 13593 );
    REQUIRE( CalculatePerimeter( 10654, 22632, 30474 ) == 63760 );
}
