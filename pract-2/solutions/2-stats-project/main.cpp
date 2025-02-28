#include <iostream>
#include "stats.h"

int main() {
    int numbers[] = {1, 2, 2, 3, 4, 5, 5, 5, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Sum: " << sum(numbers, size) << std::endl;
    std::cout << "Average: " << average(numbers, size) << std::endl;
    std::cout << "Median: " << median(numbers, size) << std::endl;
    std::cout << "Mode: " << mode(numbers, size) << std::endl;

    return 0;
}