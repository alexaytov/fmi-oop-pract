#include <catch2/catch_test_macros.hpp>
#include "../src/functions/functions.h"

// Необходими са за третия тестов случай:
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

// Тестваме, че функцията не влияе по никакъв начин
// на аргумента, в случай, че поне единт от аргументите
// е със стойност 'nullptr':
TEST_CASE( "Swap() behaves correctly on null values" ) {

    const int expectedValue = 0;
    int number = expectedValue;
    
    Swap( nullptr, nullptr );
    CHECK( number == expectedValue );

    Swap( &number, nullptr );
    CHECK( number == expectedValue );

    Swap( nullptr, &number );
    CHECK( number == expectedValue );
}

// Тестваме, че функцията работи коректно при все
// по-големи стойности:
TEST_CASE( "Swap() behaves correctly on non null values" ) {

    int original1 = 3, original2 = 4;
    int var1 = original1, var2 = original2;
    Swap( &var1, &var2 );
    REQUIRE( var1 == original2 );
    REQUIRE( var2 == original1 );

    original1 = -59497; 
    original2 = -5715;
    var1 = original1; 
    var2 = original2;
    Swap( &var1, &var2 );
    REQUIRE( var1 == original2 );
    REQUIRE( var2 == original1 );
    
    original1 = -36660; 
    original2 = 17813;
    var1 = original1; 
    var2 = original2;
    Swap( &var1, &var2 );
    REQUIRE( var1 == original2 );
    REQUIRE( var2 == original1 );
}

// Тестваме, че функцията се изпълнява за по-малко от 1 секунда:
TEST_CASE( "Swap() executes in less than a minute" ) {

    int var1 = 9, var2 = 9;
    // Взимаме времето преди да започне изпълнениято на
    // функцията:
    std::chrono::high_resolution_clock::time_point time1 = 
        high_resolution_clock::now();
    // Изпълняваме функцията:
    Swap( &var1, &var2 ); 
    // Аналогично взимаме и време след като е приключила
    // да се изпълнява фунцкията:
    std::chrono::high_resolution_clock::time_point time2 =
        high_resolution_clock::now();
    // При изваждане на променливи от ти "time_point", получаваме
    // резултат, който може да бъде записан в променлива от тип 
    // 'duration<double, std::milli>' коя ще съдържа информация за времевата
    // разлика в милисекунди във формат от тип 'double'. Можем да извлечем
    // стойността с (член) функцията count() на променливата:
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
