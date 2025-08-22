# cpp_07 - Not graded yet

Templates, generic programming, and dynamic arrays in C++.

---

## Table of Contents

1. [What is cpp_07?](#what-is-cpp_07)
2. [Exercises](#exercises)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Class Hierarchy](#class-hierarchy)
8. [Key Concepts Demonstrated](#key-concepts-demonstrated)
9. [Memory Management Highlights](#memory-management-highlights)
10. [Credits](#credits)

---

## What is cpp_07?

`cpp_07` explores C++ templates, generic programming, and dynamic memory management. The module demonstrates how to write reusable code with templates, apply functions to arrays generically, and implement a robust dynamic array class.

---

## Exercises

### ex00: whatever

Implements template functions for `swap`, `min`, and `max` that work with any type supporting the required operators.

**Concepts learned:**

- Function templates
- Operator overloading
- Generic programming

### ex01: iter

Implements a template function `iter` that applies a given function to each element of an array, supporting both mutable and constant elements.

**Concepts learned:**

- Function templates with function pointers
- Iteration over arrays
- Const-correctness

### ex02: Array

Implements a template class `Array` that provides a dynamic array with bounds checking, deep copy, and exception safety.

**Concepts learned:**

- Class templates
- Dynamic memory management
- Copy constructor and assignment operator
- Exception handling (custom exception for out-of-bounds access)

---

## Features

- Generic swap, min, and max functions
- Generic array iteration with function application
- Dynamic array class with bounds checking
- Exception-safe and robust template code
- C++98 standard compliance

---

## Installation

Navigate to the module directory:

```bash
cd cpp_modules/cpp_07
```

Compile each exercise:

```bash
for ex in ex00 ex01 ex02; do
	cd $ex && make && cd ..
done
```

---

## Usage

### ex00: whatever

```bash
cd ex00
make
./whatever
# Demonstrates swap, min, and max with different types
```

### ex01: iter

```bash
cd ex01
make
./iter
# Applies functions to array elements generically
```

### ex02: Array

```bash
cd ex02
make
./Array
# Tests dynamic array with bounds checking and copy semantics
```

---

## Project Structure

```
cpp_07/
├── ex00
│   ├── main.cpp
│   ├── Makefile
│   └── whatever.hpp
├── ex01
│   ├── iter.hpp
│   ├── main.cpp
│   └── Makefile
├── ex02
│   ├── Array.hpp
│   ├── Array.tpp
│   ├── main.cpp
│   └── Makefile
└── README.MD
```

---

## Class Hierarchy

```
Array<T>
```

---

## Key Concepts Demonstrated

### Function Templates

```cpp
template <typename T>
void swap(T& a, T& b);
template <typename T>
T min(const T& a, const T& b);
template <typename T>
T max(const T& a, const T& b);
```

### Generic Array Iteration

```cpp
template <typename T>
void iter(T* arr, size_t len, void (*func)(T&));
template <typename T>
void iter(T* arr, size_t len, void (*func)(const T&));
```

### Template Dynamic Array

```cpp
template <typename T>
class Array {
	// ...
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int size() const;
	class OutOfBounds : public std::exception { ... };
};
```

---

## Memory Management Highlights

- No memory leaks (Valgrind tested)
- Proper use of destructors and copy semantics
- Exception safety for out-of-bounds access

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module deepens the understanding of templates, generic programming, and dynamic memory management in C++ for robust and maintainable software.

---
