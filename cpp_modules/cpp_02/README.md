# cpp_02

Ad-hoc polymorphism, operator overloading and Orthodox Canonical form of C++ classes.

---

## Table of Contents

1. [What is cpp_02?](#what-is-cpp_02)
2. [Exercises](#exercises)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Credits](#credits)

---

## What is cpp_02?

`cpp_02` introduces advanced object-oriented programming concepts in C++, focusing on ad-hoc polymorphism through operator overloading and implementation of the Orthodox Canonical form. This module is essential for creating robust and reusable classes that behave like built-in types.

---

## Exercises

### ex00: My First Class in Orthodox Canonical Form

Implementation of the Fixed class in Orthodox Canonical form.

**Concepts learned:**

- Orthodox Canonical form (Big Three)
- Default constructor
- Copy constructor
- Assignment operator
- Destructor
- Fixed-point numbers
- Binary representation

### ex01: Towards a more useful fixed-point number class

Extension of the Fixed class with conversions and output.

**Concepts learned:**

- Conversion constructors
- int/float conversions
- Overloading the `<<` operator
- `toInt()` and `toFloat()` methods
- Bit-level manipulation
- Numerical precision

### ex02: Now we're talking

Complete implementation of operators for the Fixed class.

**Concepts learned:**

- Comparison operators (`>`, `<`, `>=`, `<=`, `==`, `!=`)
- Arithmetic operators (`+`, `-`, `*`, `/`)
- Increment/decrement operators (`++`, `--`)
- Pre-increment vs post-increment
- Static `min()` and `max()` functions
- Const-correctness

### ex03: BSP (Binary Space Partitioning)

BSP algorithm using fixed-point numbers to determine if a point is inside a triangle.

**Concepts learned:**

- Geometric algorithms
- Triangle area calculation
- Binary Space Partitioning
- Practical applications of fixed-point
- Computational geometry
- Immutable Point class

---

## Features

- Complete implementation of Orthodox Canonical form
- High-precision fixed-point number system
- Complete operator overloading
- Advanced geometric algorithms
- Safe memory management
- Rigorous const-correctness
- Optimized performance for mathematical calculations
- Compliance with 42 School standards

---

## Installation

Navigate to the module directory:

```bash
cd cpp_modules/cpp_02
```

Compile each exercise:

```bash
for ex in ex00 ex01 ex02 ex03; do
    cd $ex && make && cd ..
done
```

---

## Usage

### ex00: Fixed Basic

```bash
cd ex00
make
./fixed
# Demonstrates basic constructors and destructors
```

### ex01: Fixed Conversions

```bash
cd ex01
make
./fixed
# Shows conversions and formatted output
```

### ex02: Fixed Operators

```bash
cd ex02
make
./fixed
# Tests all implemented operators
```

### ex03: BSP

```bash
cd ex03
make
./bsp
# Tests BSP algorithm with various triangles and points
```

---

## Project Structure

```
cpp_02/
├── ex00/                      # Fixed point basics
│   ├── Makefile
│   ├── Fixed.hpp
│   ├── Fixed.cpp
│   └── main.cpp
├── ex01/                      # Fixed point conversions
│   ├── Makefile
│   ├── Fixed.hpp
│   ├── Fixed.cpp
│   └── main.cpp
├── ex02/                      # Fixed point operators
│   ├── Makefile
│   ├── Fixed.hpp
│   ├── Fixed.cpp
│   └── main.cpp
└── ex03/                      # BSP algorithm
    ├── Makefile
    ├── Fixed.hpp
    ├── Fixed.cpp
    ├── Point.hpp
    ├── Point.cpp
    ├── bsp.cpp
    └── main.cpp
```

---

## Key Concepts Demonstrated

### Orthodox Canonical Form

```cpp
class Fixed {
    Fixed();                        // Default constructor
    Fixed(const Fixed& other);      // Copy constructor
    Fixed& operator=(const Fixed&); // Assignment operator
    ~Fixed();                       // Destructor
};
```

### Operator Overloading

```cpp
// Arithmetic operators
Fixed operator+(const Fixed& rhs) const;
Fixed operator-(const Fixed& rhs) const;

// Comparison operators
bool operator>(const Fixed& rhs) const;
bool operator<(const Fixed& rhs) const;

// Increment/Decrement
Fixed& operator++();      // Pre-increment
Fixed operator++(int);    // Post-increment
```

### Fixed-Point Arithmetic

- 24-bit frazione per alta precisione
- Supporto per operazioni matematiche
- Conversioni sicure tra tipi
- Overflow/underflow handling

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module provides fundamental skills for creating robust and performant C++ classes.

---
