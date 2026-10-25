# Practical 7: Polymorphism in C++

## Aim
To implement compile-time and run-time polymorphism in C++ using function overloading, operator overloading, virtual functions, and abstract classes.

## Problem Statement
Write a C++ program to demonstrate polymorphism using real-life examples such as finding the area of shapes, adding complex numbers, and animals making different sounds.

## Concepts Used
- Polymorphism
- Function overloading
- Operator overloading (`+` and `==`)
- Virtual functions
- Function overriding
- Abstract classes
- Pure virtual functions
- Base class pointers

## Features
1. Calculate the area of a square, rectangle, and circle using overloaded functions.
2. Add complex numbers using the overloaded `+` operator.
3. Compare complex numbers using the overloaded `==` operator.
4. Demonstrate virtual functions using Animal, Dog, and Cat classes.
5. Demonstrate an abstract Shape class with Circle and Rectangle derived classes.
6. Test boundary cases, including negative values and zero dimensions.

## Technologies Used
- Programming Language: C++
- IDE: Dev-C++ / VS Code / Code::Blocks
- Compiler: g++
- Library: `<iostream>`

## How to Run
1. Open `polymorphism.cpp` in your C++ IDE.
2. Compile the program using a C++ compiler.
3. Run the program.
4. Observe the output for function overloading, operator overloading, and run-time polymorphism.

## Test Cases
- Square area: `area(5)` → 25
- Rectangle area: `area(4, 6)` → 24
- Circle area: `area(2.0)` → 12.56
- Negative side validation
- Complex number addition and comparison
- Virtual sound functions for Dog and Cat
- Circle and Rectangle area calculations using an abstract class
- Zero-length boundary case

## Expected Result
The program should demonstrate compile-time and run-time polymorphism and display the correct results for all test cases.

## Conclusion
This practical demonstrates how polymorphism allows the same function name or operator to behave differently in different situations. Function overloading and operator overloading show compile-time polymorphism, while virtual functions and abstract classes demonstrate run-time polymorphism.
