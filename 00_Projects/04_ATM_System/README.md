# ATM System Project

This project is a console-based ATM system developed in **C++** to simulate real banking operations in a simple and practical way. It was built as part of the learning journey focused on programming logic, file handling, validation, and user interaction.

The application allows a client to authenticate, view account information, perform financial operations, and return safely to the main menu after each transaction.

---

## Project Overview

This system was designed to model a real ATM workflow in a lightweight and beginner-friendly way. It demonstrates how software can manage:

- user authentication
- balance tracking
- account validation
- money withdrawal and deposit
- transaction flow
- persistent client data using local files

---

## Features

### Authentication

- Client login by account number and PIN
- Secure validation before access is granted
- Protection against invalid login attempts

### Transaction Operations

- Quick withdraw options
- Standard withdraw flow
- Cash deposit
- Balance inquiry
- Safe transaction validation to prevent overdrafts

### Client Management

- Store client information such as account number, PIN, and current balance
- Load client data from a local file
- Update balance after each successful operation

---

## Project Structure

This project is intentionally simple and compact, with all core logic kept in a single application file for learning purposes.

- `ATM_System.cpp` — main program file containing the ATM logic, menus, validation, and transaction flow
- `Clients.txt` — flat-file data storage for client records

---

## Data Storage

The project uses a text file to simulate a small database system. Client records are stored in a local file and loaded when the program starts, which makes it a good example of file-based persistence without a real database.

---

## Technologies Used

- **Language:** C++
- **Concepts:** input validation, file handling, loops, conditionals, data storage
- **Architecture:** procedural and structured console application
- **Environment:** CLI-based terminal application

---

## Why This Project Matters

This project is useful because it brings together several important programming ideas in one place:

- handling user input safely
- validating business logic
- updating data after actions
- maintaining persistent records
- building an interactive terminal application

It is a strong example of how a real-world system can be simplified into a learning project while still keeping realistic behavior.

---

## Developer Note

This ATM system was built as a practical exercise to strengthen problem-solving and software design skills. It introduces real-world banking logic in a way that is easy to follow and extend in future projects.
