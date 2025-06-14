# cpp_01

Advanced exploration of memory management, references, pointers and dynamic allocation in C++.

---

## Table of Contents

1. [What is cpp_01?](#what-is-cpp_01)
2. [Exercises](#exercises)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Credits](#credits)

---

## What is cpp_01?

`cpp_01` delves into memory management concepts in C++, introducing dynamic allocation, references, pointers and advanced object manipulation techniques. This module is fundamental for understanding effective resource management and preventing memory leaks.

---

## Exercises

### ex00: BraiiiiiiinnnzzzZ

Introduction to dynamic memory allocation with the Zombie class.

**Concepts learned:**

- `new` and `delete` operators
- Dynamic vs static allocation
- Parameterized constructors
- Memory management
- Stack vs Heap

### ex01: Moar brainz!

Creation and management of dynamically allocated object arrays.

**Concepts learned:**

- Dynamic object arrays
- Default constructors
- Array management with `new[]` and `delete[]`
- Object initialization in arrays
- Memory management for arrays

### ex02: HI THIS IS BRAIN

Exploration of differences between pointers and references.

**Concepts learned:**

- References in C++
- Differences between pointers and references
- Memory addressing
- Reference syntax and semantics
- When to use pointers vs references

### ex03: Unnecessary violence

Implementation of interconnected classes with composition.

**Concepts learned:**

- Object composition
- References as class members
- Object interaction
- Composition design patterns
- Object lifetime management

### ex04: Sed is for losers

String replacement in files without using C functions.

**Concepts learned:**

- File manipulation in C++
- `std::ifstream` and `std::ofstream`
- String manipulation
- Replacement algorithms
- I/O error handling

### ex05: Harl 2.0

Logging system using pointers to member functions.

**Concepts learned:**

- Pointers to member functions
- Arrays of function pointers
- Alternative to switch statements
- Logging systems
- Multiple class methods

### ex06: Harl filter

Implementation of a message filter using switch statements.

**Concepts learned:**

- Switch statements in C++
- Fall-through behavior
- Message filters
- Logging levels
- Advanced control flow

---

## Features

- Complete dynamic memory management
- Safe allocation/deallocation implementation
- In-depth exploration of references and pointers
- Advanced file manipulation
- Configurable logging systems
- Memory leak prevention
- Object-oriented design patterns
- Compliance with 42 School standards

---

## Installation

Navigate to the module directory:

```bash
cd cpp_modules/cpp_01
```

Compile each exercise:

```bash
for ex in ex00 ex01 ex02 ex03 ex04 ex05 ex06; do
    cd $ex && make && cd ..
done
```

---

## Usage

### ex00: Zombie

```bash
cd ex00
make
./zombie
# Creates zombies on stack and heap
```

### ex01: Zombie Horde

```bash
cd ex01
make
./zombie_horde
# Creates a zombie horde
```

### ex02: Brain

```bash
cd ex02
make
./brain
# Demonstrates references vs pointers
```

### ex03: Human Weapons

```bash
cd ex03
make
./violence
# Simulates combat with weapons
```

### ex04: File Replace

```bash
cd ex04
make
./replace filename string1 string2
# Replaces string1 with string2 in the file
```

### ex05: Harl

```bash
cd ex05
make
./harl
# Interactive logging system
```

### ex06: Harl Filter

```bash
cd ex06
make
./harlFilter DEBUG
# Filters messages by level
```

---

## Project Structure

```
cpp_01/
├── ex00/                      # Zombie allocation
│   ├── Makefile
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   ├── main.cpp
│   ├── newZombie.cpp
│   └── randomChump.cpp
├── ex01/                      # Zombie horde
│   ├── Makefile
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   ├── main.cpp
│   └── zombieHorde.cpp
├── ex02/                      # Brain references
│   ├── Makefile
│   └── main.cpp
├── ex03/                      # Human weapons
│   ├── Makefile
│   ├── HumanA.hpp
│   ├── HumanA.cpp
│   ├── HumanB.hpp
│   ├── HumanB.cpp
│   ├── Weapon.hpp
│   ├── Weapon.cpp
│   └── main.cpp
├── ex04/                      # File replacement
│   ├── Makefile
│   ├── header.hpp
│   ├── main.cpp
│   ├── input.cpp
│   ├── replaceStrings.cpp
│   ├── test.txt
│   └── test.txt.replace
├── ex05/                      # Harl logging
│   ├── Makefile
│   ├── Harl.hpp
│   ├── Harl.cpp
│   └── main.cpp
└── ex06/                      # Harl filter
    ├── Makefile
    ├── Harl.hpp
    ├── Harl.cpp
    └── main.cpp
```

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module provides essential foundations for safe memory management in C++.

---
