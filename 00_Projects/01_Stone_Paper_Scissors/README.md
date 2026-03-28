# Stone Paper Scissors Game 🎮

## Description

A fully functional, interactive command-line implementation of the classic "Stone, Paper, Scissors" game, written in modern C++. This project demonstrates solid software engineering principles, clean code architecture, and a dynamic text-based user interface.

## 🚀 Features

- **Dynamic UI/UX:** The console automatically clears between games and uses color-coded output to indicate round and game outcomes (Green for Player win, Red for Computer win, Yellow for Draw).
- **Customizable Gameplay:** Players can choose the number of rounds to play per game (1 to 10 rounds).
- **Replayability:** Built-in game loop allowing users to play multiple matches without restarting the program.
- **Robust Input Validation:** Prevents crashes and undefined behavior by strictly validating user inputs.

## 🧠 Technical Concepts Applied

This project heavily relies on clean coding practices and modular architecture:

- **Structs & State Management:** Used `stRoundDetails` and `stGameFinalResult` to cleanly encapsulate and pass game states between functions.
- **Enums:** Utilized strongly typed enums (`enGameChoice`, `enWinner`) for readable and maintainable logic instead of raw integers.
- **Optimized Lookups:** Replaced `switch` statements with `O(1)` Array indexing for fast Enum-to-String conversions
  (e.g., printing choice and winner names).
- **Modular Design (Separation of Concerns):** The code is broken down into single-responsibility functions
  (e.g., `StartNewRound`, `PlayGame`, `ShowGameOverScreen`).

## 🛠️ How to Run

1. Ensure you have a C++ compiler installed (e.g., GCC/MinGW).
2. Open your terminal in the project directory.
3. Compile the code:

   ```bash
   g++ -std=c++17 Game.cpp -o Game

   ```

4. Run the executable:
   ./Game

_(If on Windows, simply run Game.exe)_
