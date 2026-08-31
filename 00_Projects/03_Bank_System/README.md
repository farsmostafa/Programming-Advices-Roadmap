# Bank System Project

A practical banking management application built with **C++** and designed for a **command-line interface (CLI)**. This project was developed as part of a learning path focused on object-oriented programming, file-based data persistence, and real-world business logic implementation.

The system simulates a bank environment where users can manage clients, process financial transactions, and maintain records using local text files as a lightweight database.

---

## Project Overview

This project demonstrates how to build a complete business application using core programming concepts, including:

- class-based design
- encapsulation
- inheritance
- file handling
- validation logic
- data storage and retrieval
- transaction processing
- clean console-based user interaction

It is designed to reflect a realistic banking workflow while remaining beginner-friendly and easy to understand.

---

## Features

### Client Management

- Add new customers
- Delete existing clients
- Update client information
- View all clients
- Search for a specific client
- Validate unique account numbers

### Banking Operations

- Deposit money
- Withdraw money
- Check account balance
- View total balances
- Transfer funds between clients
- Maintain transaction logs

### User and Access Control

- User login and registration flow
- Permission-based access handling
- User management screen
- Login activity tracking

### Currency Support

- View supported currencies
- Update exchange rates
- Calculate currency conversion values

---

## Project Structure

The project is organized around a modular architecture:

- `Main.cpp` — entry point of the application
- `Core/` — core business classes such as users and clients
- `Screens/` — menu and screen management classes
- `Helpers/` — utility and validation helpers
- `Data/` — flat-file data storage
- `Global/` — shared globals and application state

This structure keeps the code easier to read, maintain, and extend.

---

## Core Classes

The application is built around key class models, including:

- `clsPerson` — base class for personal information
- `clsUser` — user authentication and permissions
- `clsBankClient` — customer account data and banking logic
- screen classes for each operational module
- helper classes for formatting, validation, and dates

This is a good example of OOP design in a real-world business system.

---

## Data Storage

The project uses local text files instead of a database system to simulate persistent storage. Records are stored in files such as:

- `Users.txt`
- `Clients.txt`
- `TransferLog.txt`

This approach is useful for learning how applications persist data without relying on a full database engine.

---

## Technologies Used

- **Language:** C++
- **Concepts:** OOP, file I/O, validation, transaction handling
- **Libraries:** standard C++ libraries and custom helper utilities
- **Environment:** console application

---

## Why This Project Matters

This project is valuable because it combines multiple software engineering ideas into one practical system:

- object-oriented design
- maintainable class separation
- interactive console interfaces
- file-based persistence
- business rules and validation
- transaction safety logic

It is an excellent example of how a real-world banking app can be built step by step using structured programming and OOP principles.

---

## Developer Note

This project represents a solid learning milestone in building larger and more realistic applications. It demonstrates how a simple console program can evolve into a structured business system with proper separation between logic, screens, data, and utilities.
