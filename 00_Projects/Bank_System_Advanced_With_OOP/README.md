# Bank System Advanced With OOP

This project is an advanced banking management application developed in **C++** using **Object-Oriented Programming (OOP)** principles. It was built to simulate a real banking system with clients, user accounts, transactions, authentication, and financial operations in a structured and maintainable way.

The goal of this project is to move beyond basic console applications and build a more realistic business-oriented system that reflects how banking software is often modeled in professional settings.

---

## Project Overview

This application demonstrates how a real-world banking platform can be implemented using a modular design and OOP concepts such as:

- inheritance
- encapsulation
- abstraction
- validation logic
- file-based persistence
- menu-driven interfaces
- business rule enforcement

It is a practical project focused on building strong software design habits while improving problem-solving and system modeling skills.

---

## Features

### Client Management

- Add new clients
- Delete clients
- Update client information
- Search and find clients
- Display all stored clients
- Maintain unique account numbers

### Banking Transactions

- Deposit money
- Withdraw money
- Check balance
- Transfer funds between accounts
- Track transaction history
- Prevent invalid overdraft operations

### User and Access Management

- User login flow
- User registration
- Role and permission handling
- User activity tracking
- Main menu-based access control

### Currency Features

- View supported currencies
- Update exchange rates
- Perform simple currency calculations

---

## Project Structure

The project is organized in a modular way to separate responsibilities:

- `Main.cpp` — app entry point
- `Core/` — core business and model classes
- `Screens/` — screen and menu logic
- `Helpers/` — validation and utility functions
- `Data/` — local file-based data storage
- `Global/` — shared global state

This structure keeps the code easier to maintain and extend as the project grows.

---

## Core Concepts Demonstrated

This project is designed to apply several important programming concepts:

- **OOP design** using classes and inheritance
- **File handling** for persistent storage
- **Input validation** to prevent invalid actions
- **Business logic implementation** for deposits, withdrawals, and transfers
- **Console UI separation** from business logic
- **Maintainable project organization** across folders and files

---

## Data Storage

The application stores client and system data in local text files instead of a database, which makes it a useful example of lightweight persistence and flat-file storage.

Examples include:

- user data files
- client records
- transfer log files

This is a good learning approach for understanding how software stores data before moving to full database systems.

---

## Technologies Used

- **Language:** C++
- **Programming style:** Object-Oriented Programming
- **Data persistence:** Flat-file storage
- **Environment:** Console application

---

## Why This Project Is Important

This project is more than a simple exercise. It shows how real business rules can be mapped into software through classes, validation, storage, and user interaction.

It combines multiple important software engineering ideas into a single practical system:

- reusable design
- maintainable code organization
- clear business logic
- user-friendly console flow
- realistic banking workflow

---

## Developer Note

This project represents a major learning milestone in building larger and more realistic systems. It demonstrates how an application can evolve from simple coding exercises into a structured business solution with practical functionality and scalable architecture.
