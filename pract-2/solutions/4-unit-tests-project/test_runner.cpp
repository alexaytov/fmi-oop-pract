#include <iostream>
#include "math_functions.h"

#define ASSERT_EQUAL(expected, actual) \
    if ((expected) == (actual)) { \
        std::cout << "Test passed: " << __FILE__ << ":" << __LINE__ << std::endl; \
    } else { \
        std::cerr << "Test failed: " << __FILE__ << ":" << __LINE__ << " Expected: " << (expected) << " but got: " << (actual) << std::endl; \
    }

void test_add() {
    ASSERT_EQUAL(5, add(2, 3));
    ASSERT_EQUAL(0, add(-1, 1));
    ASSERT_EQUAL(-5, add(-2, -3));
}

void test_subtract() {
    ASSERT_EQUAL(1, subtract(3, 2));
    ASSERT_EQUAL(-2, subtract(-1, 1));
    ASSERT_EQUAL(1, subtract(-2, -3));
}

void test_multiply() {
    ASSERT_EQUAL(6, multiply(2, 3));
    ASSERT_EQUAL(-1, multiply(-1, 1));
    ASSERT_EQUAL(6, multiply(-2, -3));
}

int main() {
    test_add();
    test_subtract();
    test_multiply();
    return 0;
}