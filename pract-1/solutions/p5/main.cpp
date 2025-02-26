#include <iostream>
#include "calculator.h"

int main() {
    int choice, a, b;

    std::cout << "Select operation: \n";
    std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    std::cin >> choice;

    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    switch (choice) {
        case 1:
            std::cout << "Result: " << add(a, b) << std::endl;
            break;
        case 2:
            std::cout << "Result: " << subtract(a, b) << std::endl;
            break;
        case 3:
            std::cout << "Result: " << multiply(a, b) << std::endl;
            break;
        case 4:
            std::cout << "Result: " << divide(a, b) << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}