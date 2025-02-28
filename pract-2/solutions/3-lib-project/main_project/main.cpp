#include <iostream>
#include "mathlib.h"

int main() {
    int a = 10, b = 5;

    std::cout << "Add: " << add(a, b) << std::endl;
    std::cout << "Subtract: " << subtract(a, b) << std::endl;
    std::cout << "Multiply: " << multiply(a, b) << std::endl;
    std::cout << "Divide: " << divide(a, b) << std::endl;

    return 0;
}