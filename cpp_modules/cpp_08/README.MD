# cpp_08 - Not graded yet

Templates, STL containers, and advanced data structures in C++.

---

## Table of Contents

1. [What is cpp_08?](#what-is-cpp_08)
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

## What is cpp_08?

`cpp_08` explores advanced use of C++ templates, STL containers, and custom data structures. The module demonstrates how to write generic algorithms, manage collections, and extend standard containers with new capabilities.

---

## Exercises

### ex00: easyfind

Implements a template function `easyfind` to search for a value in any STL-like container, throwing an exception if not found.

**Concepts learned:**

- Function templates
- STL containers and iterators
- Exception handling

### ex01: Span

Implements a class `Span` to store a collection of integers and efficiently compute the shortest and longest span between elements, with robust exception handling.

**Concepts learned:**

- Class design with private members
- Efficient algorithms for min/max span
- Exception safety and custom exceptions
- Bulk insertion of elements

### ex02: MutantStack

Implements a template class `MutantStack` that extends `std::stack` with iterator support, allowing traversal of stack elements.

**Concepts learned:**

- Inheriting from STL containers
- Exposing iterators for stack traversal
- Template specialization

---

## Features

- Generic search in STL containers
- Efficient span calculation in collections
- Stack with iterator support
- Exception-safe and robust template code
- C++98 standard compliance

---

## Installation

Navigate to the module directory:

```bash
cd cpp_modules/cpp_08
```

Compile each exercise:

```bash
for ex in ex00 ex01 ex02; do
	cd $ex && make && cd ..
done
```

---

## Usage

### ex00: easyfind

```bash
cd ex00
make
./easyfind
# Demonstrates searching for values in different containers
```

### ex01: Span

```bash
cd ex01
make
./Span
# Tests adding numbers and computing shortest/longest span
```

### ex02: MutantStack

```bash
cd ex02
make
./MutantStack
# Demonstrates stack traversal with iterators
```

---

## Project Structure

```
cpp_08/
├── ex00
│   ├── easyfind.hpp
│   ├── easyfind.tpp
│   ├── main.cpp
│   └── Makefile
├── ex01
│   ├── main.cpp
│   ├── Makefile
│   ├── Span.cpp
│   └── Span.hpp
├── ex02
│   ├── main.cpp
│   ├── Makefile
│   ├── MutantStack.hpp
│   └── MutantStack.tpp
└── README.MD
```

---

## Class Hierarchy

```
Span
MutantStack<T> : public std::stack<T>
```

---

## Key Concepts Demonstrated

### Generic Search in Containers

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int nbr);
```

### Span Calculation

```cpp
class Span {
	void addNumber(int nbr);
	int shortestSpan() const;
	int longestSpan() const;
	// ...
};
```

### Stack with Iterator Support

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
	iterator begin();
	iterator end();
	// ...
};
```

---

## Memory Management Highlights

- No memory leaks (Valgrind tested)
- Proper use of destructors and copy semantics
- Exception safety for out-of-bounds and invalid operations

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module deepens the understanding of STL, templates, and advanced data structures in C++ for robust and maintainable software.

---
