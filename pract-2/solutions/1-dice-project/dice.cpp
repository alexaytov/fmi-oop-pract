#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dice.h"

int rollDie() {
    return rand() % 6 + 1; // Generates a random number between 1 and 6
}

int rollTwoDice() {
    return rollDie() + rollDie(); // Sums the results of two dice rolls
}