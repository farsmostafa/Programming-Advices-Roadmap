# Tic-Tac-Toe

A C# Windows Forms game that supports single-player and multiplayer matches.

## Overview

The game allows players to start a match, choose the game mode, set the number of wins required, and play multiple rounds while tracking the match score.

## Features

- Single-player mode against the computer
- Two-player mode
- Custom player names
- Configurable target number of wins
- Three-by-three Tic-Tac-Toe board
- X and O turn management
- Winner and draw detection
- Highlighting of the winning line
- Multiple rounds within the same match
- Scoreboard for player wins, draws, rounds, and current turn
- Match completion when a player reaches the target wins
- Option to exit the match

## Technologies

- C#
- Windows Forms
- .NET Framework 4.8
- Visual Studio

## Project Structure

- `Tic_Tac_Toe.sln` - Visual Studio solution file
- `Tic_Tac_Toe/` - Application source code and resources
- `MainScreen.cs` - Match setup and game mode selection
- `TicTacClash-Arena.cs` - Board logic, turns, rounds, scoring, and winner detection
- `Resources/` - Game images and visual resources

## How to Run

1. Open `Tic_Tac_Toe.sln` in Visual Studio.
2. Restore or install the required .NET Framework 4.8 developer tools if needed.
3. Build the solution.
4. Run the application.
5. Enter the player details, choose the game mode, set the target wins, and start the match.

This project is part of the C# Level 1 learning path in the Programming Advices Roadmap.
