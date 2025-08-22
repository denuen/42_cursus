# cpp_06 - Not graded yet

Type conversion, serialization, and runtime type identification in C++.

---

## Table of Contents

1. [What is cpp_06?](#what-is-cpp_06)
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

## What is cpp_06?

`cpp_06` explores advanced C++ features such as static class methods, type conversion, serialization, and runtime type identification (RTTI). The module demonstrates how to safely convert between types, serialize pointers, and use dynamic_cast for polymorphic type discovery.

---

## Exercises

### ex00: ScalarConverter

Implements a static class to convert a string literal to `char`, `int`, `float`, and `double`, handling impossible and special cases.

**Concepts learned:**

- Static classes and methods
- Type conversion and parsing
- Handling impossible conversions and edge cases
- Output formatting

### ex01: Serializer

Implements serialization and deserialization of a pointer to a struct using `reinterpret_cast` and `uintptr_t`.

**Concepts learned:**

- Serialization and deserialization
- Pointer manipulation
- `reinterpret_cast` and `uintptr_t`
- Structs and memory representation

### ex02: RTTI and dynamic_cast

Implements a polymorphic base class and three derived classes (`A`, `B`, `C`). Demonstrates runtime type identification using `dynamic_cast` with both pointers and references.

**Concepts learned:**

- Runtime type identification (RTTI)
- `dynamic_cast` with pointers and references
- Polymorphism and inheritance
- Random object generation

---

## Features

- Static class for type conversion
- Safe serialization/deserialization of pointers
- Polymorphic class hierarchy with RTTI
- Demonstrates C++98 standard compliance

---

## Installation

Navigate to the module directory:

```bash
cd cpp_modules/cpp_06
```

Compile each exercise:

```bash
for ex in ex00 ex01 ex02; do
	cd $ex && make && cd ..
done
```

---

## Usage

### ex00: ScalarConverter

```bash
cd ex00
make
./ScalarConverter <literal>
# Converts the input literal to char, int, float, and double
```

### ex01: Serializer

```bash
cd ex01
make
./Serializer
# Demonstrates serialization and deserialization of struct pointers
```

### ex02: RTTI and dynamic_cast

```bash
cd ex02
make
./SomeForms
# Identifies the actual derived type of randomly generated objects
```

---

## Project Structure

```
cpp_06/
├── ex00
│   ├── main.cpp
│   ├── Makefile
│   ├── ScalarConverter.cpp
│   └── ScalarConverter.hpp
├── ex01
│   ├── Data.hpp
│   ├── main.cpp
│   ├── Makefile
│   ├── Serializer.cpp
│   └── Serializer.hpp
├── ex02
│   ├── A.hpp
│   ├── B.hpp
│   ├── Base.cpp
│   ├── Base.hpp
│   ├── C.hpp
│   ├── header.hpp
│   ├── main.cpp
│   ├── Makefile
│   └── utils.cpp
└── README.MD
```

---

## Class Hierarchy

```
	Base (abstract)
   /   |   \
  A    B    C
```

---

## Key Concepts Demonstrated

### Static Class and Type Conversion

```cpp
class ScalarConverter {
public:
	static void convert(const std::string& literal);
	// ...
};
```

### Serialization and reinterpret_cast

```cpp
class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
```

### RTTI and dynamic_cast

```cpp
class Base { virtual ~Base(); };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);
```

---

## Memory Management Highlights

- No memory leaks (Valgrind tested)
- Proper use of destructors in polymorphic base classes
- Safe pointer handling and casting

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module deepens the understanding of type conversion, serialization, and runtime type identification in C++ for robust and maintainable software.

---
