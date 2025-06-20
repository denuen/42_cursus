# cpp_modules

A comprehensive collection of C++ exercises exploring fundamental object-oriented programming concepts, designed to provide a solid foundation in C++ paradigms and techniques.

---

## Table of Contents

1. [What is cpp_modules?](#what-is-cpp_modules)
2. [Modules Overview](#modules-overview)
3. [Learning Objectives](#learning-objectives)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Credits](#credits)

---

## What is cpp_modules?

`cpp_modules` is a progressive series of C++ learning modules covering essential object-oriented programming topics. Each module is designed to build upon previous concepts, guiding developers through a structured learning path from C++ basics to advanced concepts like multiple inheritance and polymorphism.

The project complies with **42 School** coding standards and implements modern C++98 best practices.

---

## Modules Overview

### cpp_00: Introduction to C++
### cpp_01: Memory allocation, pointers to members, references, switch statement
### cpp_02: Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form
### cpp_03: Inheritance
### cpp_04: Subtype polymorphism, abstract classes, interfaces

---

## Learning Objectives

These modules are made to learn about:

- **C++ Fundamentals**: Syntax, classes, objects and encapsulation
- **Memory Management**: Dynamic allocation, RAII and resource management
- **Advanced OOP**: Inheritance, polymorphism and abstract classes
- **Overloading**: Operators and functions for greater expressiveness
- **Best Practices**: Orthodox canonical form and design patterns
- **Debugging**: Problem-solving techniques and memory management

---

## Installation

Clone the repository:

```bash
git clone https://github.com/denuen/42_cursus.git
cd 42_cursus/cpp_modules
```

Each module can be compiled individually:

```bash
cd cpp_XX/exYY
make
```

---

## Usage

Each exercise has its own executable:

```bash
# Example for cpp_00/ex00
cd cpp_00/ex00
make
./megaphone "Hello World"

# Example for cpp_03/ex01
cd cpp_03/ex01
make
./scavtrap
```

Consult the specific README of each module for detailed instructions.

---

## Project Structure

```
cpp_modules/
├── cpp_00/                    # Introduction to C++
│   ├── ex00/                  # Megaphone
│   ├── ex01/                  # PhoneBook
│   └── ex02/                  # Account Dreams
├── cpp_01/                    # Memory and references
│   ├── ex00/                  # Zombie allocation
│   ├── ex01/                  # Zombie horde
│   ├── ex02/                  # Brain references
│   ├── ex03/                  # Human weapons
│   ├── ex04/                  # File replacement
│   ├── ex05/                  # Harl logging
│   └── ex06/                  # Harl filter
├── cpp_02/                    # Overloading and canonical forms
│   ├── ex00/                  # Fixed point basics
│   ├── ex01/                  # Fixed point conversions
│   ├── ex02/                  # Fixed point operators
│   └── ex03/                  # BSP algorithm
├── cpp_03/                    # Inheritance
│   ├── ex00/                  # ClapTrap base
│   ├── ex01/                  # ScavTrap inheritance
│   ├── ex02/                  # FragTrap multiple inheritance
│   └── ex03/                  # DiamondTrap virtual inheritance
└── cpp_04/                    # Polymorphism
    ├── ex00/                  # Animal polymorphism
    ├── ex01/                  # Brain deep copy
    └── ex02/                  # Abstract Animal class
```

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. Special thanks to the 42 community for guidance and inspiration during this C++ learning journey.

---
