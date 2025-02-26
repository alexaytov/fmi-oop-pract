#include <iostream>

// Macro to print the function name and call the function
#define CALL_FUNC(func, ...) \
    std::cout << "Calling function: " << #func << std::endl; \
    int test_##func = func(__VA_ARGS__); \
    std::cout << "Result: " << test_##func << std::endl;

int add(int a, int b) {
    int result = a + b;
    return result;
}

int multiply(int a, int b) {
    int result = a * b;
    return result;
}

int main() {
    CALL_FUNC(add, 3, 4);       // Calls add(3, 4) and prints its name
    CALL_FUNC(multiply, 3, 4);  // Calls multiply(3, 4) and prints its name

    return 0;
}