# README.md

# Dice Rolling Project

## Overview
This project is a simple C++ program that simulates rolling dice. It demonstrates how to organize a C++ project using separate header and source files. The program includes functions to roll a single die and to roll two dice, returning their results.

## Files
- `dice.h`: Contains the declarations of the functions `rollDie()` and `rollTwoDice()`.
- `dice.cpp`: Implements the functions declared in `dice.h`.
- `main.cpp`: Contains the `main()` function that demonstrates the functionality of the dice rolling functions.

## Compilation and Execution
To compile the program, use the following command in your terminal:

```sh
g++ main.cpp dice.cpp -o dice_program
```

To run the program, execute:

```sh
./dice_program
```

## Example Output
```
Rolling one die: 4
Rolling two dice: 9
``` 

## Requirements
- C++ compiler (g++)
- Standard C++ library

This project is intended for educational purposes to illustrate basic C++ programming concepts and project structure.