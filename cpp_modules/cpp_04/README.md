# cpp_04

Subtype polymorphism, abstract classes and interfaces: the pinnacle of object-oriented programming in C++.

---

## Table of Contents

1. [What is cpp_04?](#what-is-cpp_04)
2. [Exercises](#exercises)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Credits](#credits)

---

## What is cpp_04?

`cpp_04` represents the culmination of object-oriented programming learning, exploring subtype polymorphism through virtual functions, abstract classes and interfaces. This module demonstrates how to create flexible and powerful class hierarchies that make the most of C++ capabilities.

---

## Exercises

### ex00: Polymorphism

Introduction to polymorphism with the Animal/Dog/Cat hierarchy.

**Concepts learned:**

- Subtype polymorphism
- Virtual functions
- Late binding vs early binding
- Virtual destructors
- Slicing problem
- Virtual table (vtable)
- Basic polymorphic behavior

### ex01: I don't want to set the world on fire

Deep copy and memory management with the Brain class.

**Concepts learned:**

- Deep copy vs shallow copy
- Memory management in inheritance
- Composition with pointers
- Rule of Three in complex contexts
- Memory leak prevention
- RAII (Resource Acquisition Is Initialization)
- Copy constructor and assignment operator

### ex02: Abstract class

Implementation of abstract classes with pure virtual functions.

**Concepts learned:**

- Abstract classes
- Pure virtual functions (`= 0`)
- Interfaces in C++
- Non-instantiable classes
- Design by contract
- Template Method pattern
- Forced polymorphism

---

## Features

- Complete animal hierarchy with polymorphism
- Advanced memory management system
- Abstract class implementation
- Safe deep copy for complex objects
- Brain system with ideas
- Complete memory leak prevention
- Template Method design pattern
- Compliance with 42 School standards

---

## Installation

Navigate to the module directory:

```bash
cd cpp_modules/cpp_04
```

Compile each exercise:

```bash
for ex in ex00 ex01 ex02; do
    cd $ex && make && cd ..
done
```

---

## Usage

### ex00: Animal Polymorphism

```bash
cd ex00
make
./animal
# Demonstrates basic polymorphism and virtual functions
```

### ex01: Brain Deep Copy

```bash
cd ex01
make
./brain
# Tests deep copy and advanced memory management
```

### ex02: Abstract Animal

```bash
cd ex02
make
./abstract
# Shows abstract classes and interfaces
```

---

## Project Structure

```
cpp_04/
├── ex00/                      # Animal polymorphism
│   ├── Makefile
│   ├── Animal.hpp
│   ├── Animal.cpp
│   ├── Dog.hpp
│   ├── Dog.cpp
│   ├── Cat.hpp
│   ├── Cat.cpp
│   ├── WrongAnimal.hpp
│   ├── WrongAnimal.cpp
│   ├── WrongDog.hpp
│   ├── WrongDog.cpp
│   ├── WrongCat.hpp
│   ├── WrongCat.cpp
│   └── main.cpp
├── ex01/                      # Brain deep copy
│   ├── Makefile
│   ├── Animal.hpp
│   ├── Animal.cpp
│   ├── Dog.hpp
│   ├── Dog.cpp
│   ├── Cat.hpp
│   ├── Cat.cpp
│   ├── Brain.hpp
│   ├── Brain.cpp
│   ├── WrongAnimal.hpp
│   ├── WrongAnimal.cpp
│   ├── WrongDog.hpp
│   ├── WrongDog.cpp
│   ├── WrongCat.hpp
│   ├── WrongCat.cpp
│   └── main.cpp
└── ex02/                      # Abstract Animal class
    ├── Makefile
    ├── Animal.hpp
    ├── Animal.cpp
    ├── Dog.hpp
    ├── Dog.cpp
    ├── Cat.hpp
    ├── Cat.cpp
    ├── Brain.hpp
    ├── Brain.cpp
    ├── WrongAnimal.hpp
    ├── WrongAnimal.cpp
    ├── WrongDog.hpp
    ├── WrongDog.cpp
    ├── WrongCat.hpp
    ├── WrongCat.cpp
    └── main.cpp
```

---

## Class Hierarchy

### Correct Hierarchy (with virtual functions)

```
        Animal (base class)
        /            \
       /              \
     Dog              Cat
     |                |
   Brain*           Brain*
```

### Wrong Hierarchy (without virtual functions)

```
     WrongAnimal (demonstrates wrong behavior)
     /               \
    /                 \
 WrongDog           WrongCat
```

---

## Key Concepts Demonstrated

### Virtual Functions

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual (ex02)
    virtual ~Animal();                   // Virtual destructor
};

class Dog : public Animal {
public:
    void makeSound() const override;     // Override virtual function
};
```

### Brain Class (Deep Copy)

```cpp
class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& other);           // Deep copy constructor
    Brain& operator=(const Brain& other); // Deep copy assignment
    ~Brain();
};
```

### Polymorphic Behavior

```cpp
Animal* animals[4];
animals[0] = new Dog();
animals[1] = new Cat();

// Calls correct makeSound() due to virtual functions
for (int i = 0; i < 4; i++) {
    animals[i]->makeSound();  // Polymorphic call
    delete animals[i];        // Calls correct destructor
}
```

### Abstract Classes (ex02)

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual = abstract class
    // Animal cannot be instantiated
    // Animal* ptr = new Animal();  // ERROR!
};
```

---

## Memory Management Highlights

- **RAII Pattern**: Resource management tied to object lifetime
- **Deep Copy**: Complete duplication of pointed-to objects
- **Virtual Destructors**: Ensure proper cleanup in inheritance
- **No Memory Leaks**: Verified with tools like Valgrind
- **Exception Safety**: Proper cleanup even during exceptions

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module concludes the fundamental learning of object-oriented programming in C++, providing the tools to create robust and maintainable software.

---
