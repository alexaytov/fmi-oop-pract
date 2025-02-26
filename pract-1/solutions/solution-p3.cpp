#include <iostream>
#include <chrono>

#define SQUARE(x) ((x) * (x)) // Macro for squaring a number

inline int squareInline(int x) { // Inline function for squaring a number
    return x * x;
}

int squareNotInline(int x) { // Function for squaring a number
    return x * x;
}

int main() {
    const int ITERATIONS = 10000000; // 10 million iterations
    int sum = 0; // Variable to store the sum (to prevent optimization)

    // Measure time for the macro
    auto startMacro = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; i++) {
        sum += SQUARE(i); // Using the macro
    }
    auto endMacro = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> macroTime = endMacro - startMacro;

    // Reset sum for fair comparison
    sum = 0;

    // Measure time for the inline function
    auto startInline = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; i++) {
        sum += squareInline(i); // Using the inline function
    }
    auto endInline = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> inlineTime = endInline - startInline;

    // Measure time for the non-inline function
    auto startNonInline = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; i++) {
        sum += squareNotInline(i); // Using the non-inline function
    }
    auto endNonInline = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> nonInlineTime = endNonInline - startNonInline;

    // Print execution times
    std::cout << "Execution time using macro: " << macroTime.count() << " seconds\n";
    std::cout << "Execution time using inline function: " << inlineTime.count() << " seconds\n";
    std::cout << "Execution time using non-inline function: " << nonInlineTime.count() << " seconds\n";

    return 0;
}