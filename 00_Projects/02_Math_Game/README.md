# Math Game 🧮

## Description

A dynamic, console-based Math Quiz Game built with C++. This project generates random arithmetic questions based on user-defined difficulty levels and operation types. It tracks the user's performance, evaluates the results, and provides a final pass/fail grade.

## 🚀 Features

- **Multiple Difficulty Levels:** Choose from Easy (1-10), Medium (11-50), Hard (51-100), or a "Mixed" mode that fairly distributes difficulties.
- **Various Operations:** Supports Addition, Subtraction, Multiplication, Division, and a Mixed operations mode.
- **Smart Validation:** Handles all edge cases, including negative numbers and zero for answers, while strictly validating initial setup inputs.
- **Interactive UI:** Features colored feedback (Green for correct/pass, Red for wrong/fail) and clean screen transitions.

## 🧠 Technical Concepts Applied

- **Advanced State Management:** Uses nested Structs (`stQuestion`, `stQuiz`) and Arrays to store and manage the entire session's state locally.
- **Memory Optimization:** Implemented `Pass-by-Reference` for large Struct arrays to prevent unnecessary memory overhead during function calls.
- **Probability Logic:** Engineered a fair random generation algorithm for the "Mixed" difficulty mode to ensure an equal 33% distribution across Easy, Medium, and Hard questions.
- **Clean Architecture:** Fully modular code with isolated single-responsibility functions (e.g., Generator, Evaluator, UI renderer).

## 🛠️ How to Run

1. Ensure you have a C++ compiler installed (e.g., GCC/MinGW).
2. Open your terminal in the project directory.
3. Compile the code:
   g++ -std=c++17 MathGame.cpp -o MathGame

4. Run the executable:
   ./MathGame

_(If on Windows, simply run MathGame.exe)_
