# cpp_03

Inheritance in C++: from basic simple inheritance to complex multiple and virtual inheritance problems.

---

## Table of Contents

1. [What is cpp_03?](#what-is-cpp_03)
2. [Exercises](#exercises)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Credits](#credits)

---

## What is cpp_03?

`cpp_03` explores the concept of inheritance in C++ in depth, starting from simple inheritance to addressing complex scenarios like multiple inheritance and the diamond problem. Through creating combat robots, this module demonstrates how to structure effective class hierarchies and manage typical inheritance problems.

---

## Exercises

### ex00: Aaaaand... OPEN!

Implementation of the ClapTrap base class.

**Concepts learned:**

- Fundamental base classes
- Encapsulation with protected members
- Basic virtual methods
- Object state management
- Basic combat systems
- Formatted output for debugging

### ex01: Serena, my love!

Introduction to simple inheritance with ScavTrap.

**Concepts learned:**

- Simple inheritance (`class Derived : public Base`)
- Method overriding
- Base class constructor calls
- Protected vs private members
- Behavior specialization
- Additional member functions

### ex02: Repetitive work

Multiple inheritance with FragTrap and ScavTrap.

**Concepts learned:**

- Multiple inheritance
- Managing multiple base classes
- Name conflicts and resolution
- Selective method overriding
- Constructors in multiple inheritance
- Design patterns for combat systems

### ex03: Now it's weird!

DiamondTrap and the diamond problem with virtual inheritance.

**Concepts learned:**

- Diamond problem in inheritance
- Virtual inheritance (`virtual public`)
- Ambiguity resolution
- Virtual constructors
- Scope resolution operator
- Design patterns for complex problems

---

## Features

- Complete hierarchy of combat robot classes
- Correct implementation of virtual inheritance
- Advanced constructor and destructor management
- Combat system with hit points and energy
- Detailed debug output for tracking calls
- Diamond problem resolution
- Consistent naming patterns
- Compliance with 42 School standards

---

## Installation

Navigate to the module directory:

```bash
cd cpp_modules/cpp_03
```

Compile each exercise:

```bash
for ex in ex00 ex01 ex02 ex03; do
    cd $ex && make && cd ..
done
```

---

## Usage

### ex00: ClapTrap

```bash
cd ex00
make
./claptrap
# Demonstrates basic ClapTrap behavior
```

### ex01: ScavTrap

```bash
cd ex01
make
./scavtrap
# Shows simple inheritance and guard gate
```

### ex02: FragTrap

```bash
cd ex02
make
./fragtrap
# Tests multiple inheritance and high fives
```

### ex03: DiamondTrap

```bash
cd ex03
make
./diamondtrap
# Solves the diamond problem with virtual inheritance
```

---

## Project Structure

```
cpp_03/
├── ex00/                      # ClapTrap base
│   ├── Makefile
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   └── main.cpp
├── ex01/                      # ScavTrap inheritance
│   ├── Makefile
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   ├── ScavTrap.hpp
│   ├── ScavTrap.cpp
│   └── main.cpp
├── ex02/                      # FragTrap multiple inheritance
│   ├── Makefile
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   ├── ScavTrap.hpp
│   ├── ScavTrap.cpp
│   ├── FragTrap.hpp
│   ├── FragTrap.cpp
│   └── main.cpp
└── ex03/                      # DiamondTrap virtual inheritance
    ├── Makefile
    ├── ClapTrap.hpp
    ├── ClapTrap.cpp
    ├── ScavTrap.hpp
    ├── ScavTrap.cpp
    ├── FragTrap.hpp
    ├── FragTrap.cpp
    ├── DiamondTrap.hpp
    ├── DiamondTrap.cpp
    └── main.cpp
```

---

## Class Hierarchy

```
       ClapTrap (virtual base)
       /        \
      /          \
 ScavTrap    FragTrap
      \          /
       \        /
      DiamondTrap
```

### Class Specifications

**ClapTrap:**

- Hit points: 10
- Energy points: 10
- Attack damage: 0

**ScavTrap:**

- Hit points: 100
- Energy points: 50
- Attack damage: 20
- Special: `guardGate()`

**FragTrap:**

- Hit points: 100
- Energy points: 100
- Attack damage: 30
- Special: `highFivesGuys()`

**DiamondTrap:**

- Hit points: FragTrap (100)
- Energy points: ScavTrap (50)
- Attack damage: FragTrap (30)
- Special: `whoAmI()` + inherits from both

---

## Key Concepts Demonstrated

### Virtual Inheritance

```cpp
class ScavTrap : virtual public ClapTrap {};
class FragTrap : virtual public ClapTrap {};
class DiamondTrap : public FragTrap, public ScavTrap {};
```

### Constructor Order

1. Virtual base constructors
2. Direct base constructors (inheritance order)
3. Member object constructors
4. Current class constructor

### Method Resolution

```cpp
// DiamondTrap uses ScavTrap's attack
void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
```

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module addresses one of the most complex and powerful aspects of C++: inheritance in all its forms.

---
