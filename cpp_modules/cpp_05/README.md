# cpp_05 - Not graded yet

Exception handling, multiple inheritance, and design patterns: bureaucracy in C++.

---

## Table of Contents

1. [What is cpp_05?](#what-is-cpp_05)
2. [Exercises](#exercises)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Credits](#credits)

---

## What is cpp_05?

`cpp_05` explores exception handling, inheritance, and design patterns through a class hierarchy simulating bureaucracy. The module introduces custom exceptions, form signing and execution, and dynamic object creation via an Intern class.

---

## Exercises

### ex00: Bureaucrat

Introduction to exceptions and access limits with the `Bureaucrat` class.

**Concepts learned:**

- Custom exceptions (`GradeTooHighException`, `GradeTooLowException`)
- Parameter validation in constructors
- Output operator overloading

### ex01: Form

Adds the `Form` class and its interaction with `Bureaucrat`.

**Concepts learned:**

- Class composition
- Form signing with permission checks
- Exceptions in class methods

### ex02: AForm and Specialized Forms

Introduces the abstract class `AForm` and specialized forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`).

**Concepts learned:**

- Abstract classes and pure virtual methods
- Inheritance and polymorphism
- Polymorphic execution of actions

### ex03: Intern

Dynamic creation of forms via the `Intern` class.

**Concepts learned:**

- Factory pattern
- Function pointer arrays
- Dynamic memory management

---

## Features

- Complete bureaucratic class hierarchy
- Custom exception handling
- Abstract base class for forms
- Specialized forms with unique behaviors
- Dynamic form creation (factory pattern)
- Full compliance with 42 School standards

---

## Installation

Navigate to the module directory:

```bash
cd cpp_modules/cpp_05
```

Compile each exercise:

```bash
for ex in ex00 ex01 ex02 ex03; do
	cd $ex && make && cd ..
done
```

---

## Usage

### ex00: Bureaucrat

```bash
cd ex00
make
./bureaucrat
# Demonstrates grade limits and exception handling
```

### ex01: Form

```bash
cd ex01
make
./form
# Shows form signing and permission checks
```

### ex02: Specialized Forms

```bash
cd ex02
make
./forms
# Demonstrates abstract forms and polymorphic execution
```

### ex03: Intern

```bash
cd ex03
make
./intern
# Tests dynamic form creation via Intern
```

---

## Project Structure

```
cpp_05/
├── ex00
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── main.cpp
│   └── Makefile
├── ex01
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── Form.cpp
│   ├── Form.hpp
│   ├── main.cpp
│   └── Makefile
├── ex02
│   ├── AForm.cpp
│   ├── AForm.hpp
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── main.cpp
│   ├── Makefile
│   ├── PresidentialPardonForm.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   └── ShrubberyCreationForm.hpp
├── ex03
│   ├── AForm.cpp
│   ├── AForm.hpp
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── Intern.cpp
│   ├── Intern.hpp
│   ├── main.cpp
│   ├── Makefile
│   ├── PresidentialPardonForm.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   └── ShrubberyCreationForm.hpp
└── README.MD
```

---

## Class Hierarchy

```
		Bureaucrat
			 |
		   AForm (abstract)
		 /     |      \
Shrubbery  Robotomy  Presidential
Creation    Request     Pardon
Form        Form        Form
```

---

## Key Concepts Demonstrated

### Custom Exceptions

```cpp
class Bureaucrat {
public:
	class GradeTooHighException : public std::exception { ... };
	class GradeTooLowException : public std::exception { ... };
	// ...
};
```

### Abstract Forms and Polymorphism

```cpp
class AForm {
public:
	virtual void execute(Bureaucrat const & executor) const = 0;
	// ...
};

class ShrubberyCreationForm : public AForm { ... };
class RobotomyRequestForm : public AForm { ... };
class PresidentialPardonForm : public AForm { ... };
```

### Factory Pattern (Intern)

```cpp
class Intern {
public:
	AForm* makeForm(std::string const & formName, std::string const & target);
};
```

---

## Memory Management Highlights

- Exception safety in constructors and methods
- Proper use of destructors
- No memory leaks (Valgrind tested)
- Dynamic allocation and cleanup of forms

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module deepens the understanding of exception handling, inheritance, and design patterns in C++ for robust and maintainable software.

---
