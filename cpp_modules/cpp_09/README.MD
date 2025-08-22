# cpp_09 - Not graded yet

STL containers, algorithms, and real-world data processing in C++.

---

## Table of Contents

1. [What is cpp_09?](#what-is-cpp_09)
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

## What is cpp_09?

`cpp_09` explores advanced use of STL containers, algorithms, and real-world data processing. The module demonstrates how to parse, store, and process data efficiently using C++ standard library features and custom classes. 

### Container Choice Rationale

The subject required using STL containers without repetition, one per exercise, except for the `PmergeMe` class which required at least two containers for performance comparison. The choices made are explained as follows:

- **`std::map`** was selected for its ability to efficiently map key-value pairs, making it the most suitable choice for the `BitcoinExchange` exercise.  
- **`std::stack`** was selected for the RPN evaluator because expressions in Reverse Polish Notation naturally follow a LIFO logic, which directly maps to stack operations.  
- **`std::vector`** was selected for its random-access efficiency, enabling the direct use of `std::sort` and `std::lower_bound`.  
- **`std::list`** was selected to contrast with `vector`, emphasizing sequential access and constant-time insertion, which required implementing a custom ordered insertion routine.  

In this module, I tested another formatting approach: instead of following my custom style character by character, I used the clang automatic formatter with some customized command settings. This is a personal experiment to try to improve readability.

---

## Exercises

### ex00: BitcoinExchange

Implements a class to parse and process Bitcoin exchange rates from a CSV file, allowing queries by date and robust error handling.

**Concepts learned:**

- File parsing and validation
- Data storage with `std::map`
- Exception handling and custom exceptions
- Real-world data processing

### ex01: RPN (Reverse Polish Notation)

Implements a class to evaluate mathematical expressions in Reverse Polish Notation using a stack.

**Concepts learned:**

- Stack-based algorithms
- Parsing and evaluating expressions
- Exception safety and error reporting

### ex02: PmergeMe

Implements a class to sort a sequence of integers using both `std::vector` and `std::list`, measuring and comparing performance.

**Concepts learned:**

- Sorting algorithms
- Performance measurement
- Use of multiple STL containers
- Exception safety

---

## Features

- Real-world data parsing and validation
- Stack-based expression evaluation
- Efficient sorting and performance benchmarking
- Robust exception handling
- C++98 standard compliance

---

## Installation

Navigate to the module directory:

```bash
cd cpp_modules/cpp_09
```

Compile each exercise:

```bash
for ex in ex00 ex01 ex02; do
	cd $ex && make && cd ..
done
```

---

## Usage

### ex00: BitcoinExchange

```bash
cd ex00
make
./BitcoinExchange input.txt
# Parses input file and prints exchange rates by date
```

### ex01: RPN

```bash
cd ex01
make
./RPN "3 4 + 2 * 7 /"
# Evaluates the RPN expression and prints the result
```

### ex02: PmergeMe

```bash
cd ex02
make
./PmergeMe 3 5 1 8 2 7
# Sorts the input sequence and prints timing for vector and list
```

---

## Project Structure

```
cpp_09/
├── ex00
│   ├── BitcoinExchange.cpp
│   ├── BitcoinExchange.hpp
│   ├── data.csv
│   ├── input.txt
│   ├── main.cpp
│   └── Makefile
├── ex01
│   ├── main.cpp
│   ├── Makefile
│   ├── RPN.cpp
│   └── RPN.hpp
├── ex02
│   ├── main.cpp
│   ├── Makefile
│   ├── PmergeMe.cpp
│   └── PmergeMe.hpp
└── README.MD
```

---

## Class Hierarchy

```
BitcoinExchange
Rpn
PmergeMe
```

---

## Key Concepts Demonstrated

### File Parsing and Data Storage

```cpp
class BitcoinExchange {
	void load(const std::string& filename);
	float getPriceByDate(const std::string& date) const;
	// ...
};
```

### Stack-Based RPN Evaluation

```cpp
class Rpn {
	void compute(std::string& input);
	double getResult() const;
	// ...
};
```

### Sorting and Performance Measurement

```cpp
class PmergeMe {
	void sortVector();
	void sortList();
	double getVecTime() const;
	double getListTime() const;
	// ...
};
```

---

## Memory Management Highlights

- No memory leaks (Valgrind tested)
- Proper use of destructors and copy semantics
- Exception safety for file and data operations

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. This module deepens the understanding of STL, algorithms, and real-world data processing in C++ for robust and maintainable software.

---
