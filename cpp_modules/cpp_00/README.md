# cpp_00

Introduction to the fundamental concepts of C++, exploring classes, objects, static members and user interaction.

---

## Table of Contents

1. [What is cpp_00?](#what-is-cpp_00)
2. [Exercises](#exercises)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Credits](#credits)

---

## What is cpp_00?

'cpp_00' is the first step into the world of C++, introducing fundamental concepts such as classes, objects, encapsulation and user interaction. This module provides a solid foundation for understanding object-oriented programming and the syntactic peculiarities of C++.

---

## Exercises

### ex00: megaphone

The first C++ program that converts user input to uppercase.

**Concepts learned:**

- Basic C++ syntax
- String manipulation
- Use of 'std::cout' and command line parameters
- Differences between C and C++

### ex01: My Awesome PhoneBook

Implementation of an interactive phone book using C++ classes.

**Concepts learned:**

- Definition of classes and objects
- Encapsulation and private/public members
- Getter and setter methods
- Array of objects
- User interaction with input/output
- Output formatting

### ex02: The Job Of Your Dreams

Recreation of the behavior of a banking log system with static members.

**Concepts learned:**

- Static class members
- Static methods
- Timestamp management
- System logs
- Constructors and destructors
- Handling of log files

---

## Features

- Progressive introduction to C++ concepts
- Implementation of the basic canonical form
- Management of user input/output
- Advanced data formatting
- Logging system with timestamp
- Input validation
- Interactive command line interface
- Compliance with 42 School standards

---

## Installation

Browse the module directory:

```bash
cd cpp_modules/cpp_00
```

Compile every exercise individually:

```bash
cd ex00 && make
cd ex01 && make
cd ex02 && make
```

---

## Usage

### ex00: megaphone

```bash
cd ex00
make
./megaphone "hello world"
# Output: HELLO WORLD

./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### ex01: PhoneBook

```bash
cd ex01
make
./phonebook
```

Available commands:

- `ADD`: Add a new contact
- `SEARCH`: Search and display contacts
- `EXIT`: Exit the program

### ex02: Account

```bash
cd ex02
make
./account
# Displays the banking operations log
```

---

## Project Structure

```
cpp_00/
├── ex00/                      # Megaphone
│   ├── Makefile
│   └── src/
│       └── megaphone.cpp
├── ex01/                      # PhoneBook
│   ├── Makefile
│   ├── includes/
│   │   ├── Contact.hpp
│   │   └── PhoneBook.hpp
│   └── src/
│       ├── Contact.cpp
│       ├── PhoneBook.cpp
│       └── main.cpp
└── ex02/                      # Account
    ├── Account.cpp
    ├── Account.hpp
    ├── main.cpp
    ├── tests.cpp
    ├── Makefile
    └── 19920104_091532.log    # Example log
```

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module lays the foundation for all subsequent C++ concepts.

---
