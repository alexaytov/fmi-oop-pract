#include <catch2/catch_test_macros.hpp>
#include "../src/functions/functions.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

TEST_CASE( "Swap() behaves correctly on null values" ) {

    const int expectedValue = -91590;
    int number = expectedValue;
    
    Swap( nullptr, nullptr );
    CHECK( number == expectedValue );

    Swap( &number, nullptr );
    CHECK( number == expectedValue );

    Swap( nullptr, &number );
    CHECK( number == expectedValue );
}

TEST_CASE( "Swap() behaves correctly on non null values" ) {

    SECTION( "Small numbers" ) {

        int original1 = 3, original2 = 4;
        int var1 = original1, var2 = original2;
        Swap( &var1, &var2 );
        REQUIRE( var1 == original2 );
        REQUIRE( var2 == original1 );
    }

    SECTION( "Larger numbers 1" ) {

        int original1 = -59497; 
        int original2 = -5715;
        int var1 = original1, var2 = original2;
        Swap( &var1, &var2 );
        REQUIRE( var1 == original2 );
        REQUIRE( var2 == original1 );
    }

    SECTION( "Larger numbers 2" ) {
        
        int original1 = -36660, original2 = 17813;
        int var1 = original1, var2 = original2;
        Swap( &var1, &var2 );
        REQUIRE( var1 == original2 );
        REQUIRE( var2 == original1 );
    }
}

TEST_CASE( "Swap() executes in less than a minute" ) {

    int var1 = 9, var2 = 9;
    std::chrono::high_resolution_clock::time_point time1 = 
        high_resolution_clock::now();
    Swap( &var1, &var2 ); 
    std::chrono::high_resolution_clock::time_point time2 =
        high_resolution_clock::now();
    duration<double, std::milli> differenceInMilliseconds = time2 - time1;
    REQUIRE( differenceInMilliseconds.count() < 1000 );

    var1 = 999; 
    var2 = 999;
    time1 = high_resolution_clock::now();
    Swap( &var1, &var2 ); 
    time2 = high_resolution_clock::now();
    differenceInMilliseconds = time2 - time1;
    REQUIRE( differenceInMilliseconds.count() < 1000 );

    var1 = 9999; 
    var2 = 9999;
    time1 = high_resolution_clock::now();
    Swap( &var1, &var2 ); 
    time2 = high_resolution_clock::now();
    differenceInMilliseconds = time2 - time1;
    REQUIRE( differenceInMilliseconds.count() < 1000 );
}