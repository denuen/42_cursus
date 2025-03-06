# get_next_line

A custom implementation of a line-reading function in C, designed to efficiently read lines from file descriptors at the 42 School.

---

## Table of Contents
1. [What is get_next_line?](#what-is-get_next_line)
2. [Features](#features)
3. [Project Challenges](#project-challenges)
4. [Installation](#installation)
5. [Usage](#usage)
6. [File Structure](#file-structure)
7. [Credits](#credits)

---

## What is get_next_line?

`get_next_line` is a crucial project in the 42 School curriculum that implements a function capable of reading a line from a file descriptor, handling multiple file descriptors simultaneously. This project demonstrates deep understanding of memory management, static variables, and file I/O in C programming.

---

## Features

- Reads a single line from a file descriptor
- Supports multiple file descriptors
- Efficient memory management
- Handles various edge cases:
  - Empty lines
  - End of file
  - Multiple file descriptors
- Customizable buffer size

---

## Project Challenges

The primary challenges in developing `get_next_line` included:
- Intricate byte management, particularly handling:
  - Bytes to be discarded
  - Bytes to be recovered
- Navigating the complexities of static variables
- Implementing a robust solution for line reading across different file descriptors

The initial approach was challenging due to a novice understanding of static variables. Through dedicated study and iterative development, the project gradually took shape, revealing the power and nuance of low-level file reading in C.

---

## Installation

Clone the repository:
```bash
git clone https://github.com/deunen/42_cursus.git
cd 42_cursus/get_next_line
```

## Usage

1. Include the header in your C files:
   ```c
   #include "get_next_line.h"
   ```
2. Compile your program with the get_next_line source files:
   ```bash
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_program.c
   ```
Example usage:
```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

---

## File Structure

```
get_next_line/
├── get_next_line.c           # Main implementation
├── get_next_line.h           # Header file
├── get_next_line_utils.c     # Utility functions
├── get_next_line_bonus.c     # Bonus implementation for multiple file descriptors
├── get_next_line_bonus.h     # Bonus header file
├── get_next_line_utils_bonus.c # Bonus utility functions
└── Makefile                  # Build instructions
```
---

## Credits

Developed by [deunen](https://github.com/deunen) as part of the 42 School curriculum. Special thanks to the 42 community for guidance and support in mastering low-level file reading techniques.

---
