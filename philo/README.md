# philosophers

A simulation of the dining philosophers problem, showcasing process synchronization and thread management.

---

## Table of Contents

1. [What is philosophers?](#what-is-philosophers)
2. [Features](#features)
3. [How it Works](#how-it-works)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Credits](#credits)

---

## What is philosophers?

`philosophers` is a project that tackles the classic dining philosophers problem, a thought experiment in concurrent algorithm design used to illustrate synchronization issues and techniques for resolving them. The project implements both a threads and processes version, demonstrating resource sharing, deadlock prevention, and process synchronization techniques in a UNIX environment, following the coding standards of **42 School**.

---

## Features

- Implementation of the dining philosophers problem using threads and mutexes
- Bonus implementation using processes and semaphores
- Precise time management to simulate philosopher activities
- Deadlock prevention mechanisms
- Resource management for shared resources (forks)
- Death detection to monitor philosophers' states
- Detailed status reporting of philosopher activities
- Compliant with the 42 School `norminette` standards

---

## How it Works

The simulation follows these principles:
1. Each philosopher is represented by a thread (or process in the bonus part)
2. Philosophers alternate between eating, sleeping, and thinking
3. To eat, a philosopher needs two forks (shared resources)
4. If a philosopher doesn't eat within a specified time, they die
5. The program monitors and reports all state changes
6. The simulation ends when a philosopher dies or all philosophers have eaten enough times

This approach demonstrates thread synchronization, mutex locking, and resource allocation in a concurrent environment.

---

## Installation

Clone the repository:
```bash
git clone https://github.com/yourusername/42_cursus.git
cd 42_cursus/philosophers
```

Build the mandatory part:
```bash
make
```

Build the bonus part:
```bash
cd bonus
make
```

This will compile both the mandatory and bonus executables.

---

## Usage

### Mandatory Part

Run the program with the following arguments:
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]
```

Example:
```bash
./philo 5 800 200 200 7
```

### Bonus Part

Run the bonus version with the same arguments:
```bash
./philo_bonus 5 800 200 200 7
```

Parameters:
- `number_of_philosophers`: The number of philosophers and forks
- `time_to_die`: Time in milliseconds after which a philosopher dies if they haven't started eating
- `time_to_eat`: Time in milliseconds that a philosopher takes to eat
- `time_to_sleep`: Time in milliseconds that a philosopher spends sleeping
- `number_of_times_each_philosopher_must_eat`: Optional parameter, if all philosophers eat this many times, the simulation stops

---

## Project Structure

```
philosophers/
├── srcs/                   # Source files for mandatory part
│   ├── general_utils.c     # General utility functions
│   ├── main.c              # Main function
│   ├── philo.c             # Core philosopher functions
│   ├── philo_init.c        # Initialization functions
│   ├── philo_mm.c          # Memory management functions
│   ├── philo_operations.c  # Philosopher actions
│   └── philo_utils.c       # Utility functions for philosophers
├── includes/               # Header files
│   └── philo.h             # Main header file
├── bonus/                  # Bonus part implementation
│   ├── srcs/               # Source files for bonus part
│   │   ├── general_utils_bonus.c
│   │   ├── main_bonus.c
│   │   ├── philo_bonus.c
│   │   ├── philo_init_bonus.c
│   │   ├── philo_mm_bonus.c
│   │   ├── philo_operations_bonus.c
│   │   └── philo_utils_bonus.c
│   ├── includes/           # Header files for bonus
│   │   └── philo_bonus.h   # Bonus header file
│   └── Makefile            # Build instructions for bonus
└── Makefile                # Build instructions for mandatory part
```
---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. Special thanks to the 42 community for guidance and inspiration.
---
