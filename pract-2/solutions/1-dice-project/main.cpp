#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dice.h"

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализиране на генератора на случайни числа

    int singleRoll = rollDie(); // Хвърляне на един зар
    int doubleRoll = rollTwoDice(); // Хвърляне на два зара

    std::cout << "Хвърляне на един зар: " << singleRoll << std::endl; // Извеждане на резултата от хвърлянето на един зар
    std::cout << "Хвърляне на два зара: " << doubleRoll << std::endl; // Извеждане на сумата от хвърлянето на два зара

    return 0;
}