# libft
A custom implementation of a utility library in C, recreating some of the most common functions from the standard C library, along with additional helpful functions.

---

## Table of Contents
1. [What is libft?](#what-is-libft)
2. [Features](#features)
3. [Functions List](#functions-list)
4. [Installation](#installation)
5. [Usage](#usage)
6. [File Structure](#file-structure)
7. [Credits](#credits)

---

## What is libft?  
`libft` is a C library that reimplements several standard library functions, as well as additional utilities that simplify working with strings, memory, file descriptors, and linked lists.  
While it sacrifices some efficiency compared to the optimized versions in the standard library, it provides safeguards for compilation errors and memory leaks, and all the code complies with the formatting standards of **42 School**'s `norminette`.

---

## Features  
- Reimplementation of standard C library functions (e.g., `atoi`, `memcpy`, `strlen`)
- Memory management helpers (e.g., `calloc`, `bzero`)
- String manipulation utilities (e.g., `strjoin`, `split`)
- File descriptor management (e.g., `get_next_line`, `putchar_fd`)
- Custom linked list functions for dynamic data structures
- Compliant with the 42 School `norminette` standards

---

## Functions List  

### Standard C Library Functions
- Memory functions: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memcmp`, `ft_memchr`
- String functions: `ft_strlen`, `ft_strdup`, `ft_strncmp`, `ft_strchr`, `ft_strrchr`, `ft_strlcpy`, `ft_strlcat`
- Character checks and transformations: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`

### Additional Utility Functions
- String utilities: `ft_split`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_strmapi`, `ft_striteri`
- Number utilities: `ft_atoi`, `ft_itoa`
- Output functions: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Bonus: Linked List Functions
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`
- `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

### Advanced Utilities
- `get_next_line` and its bonus versions for reading files line by line
- `ft_printf` for formatted output

---

## Installation  

Clone the repository:
```bash
git clone https://github.com/deunen/42_cursus.git
cd 42_cursus/libft
```

Build the library:
```bash
make
```

This will generate `libft.a`, a static library that you can link to your own projects.

---

## Usage  

1. Include `libft.h` in your C files:
   ```c
   #include "libft.h"
   ```

2. Compile your program with the `libft.a` library:
   ```bash
   gcc -Wall -Wextra -Werror -L. -lft your_program.c
   ```

---

## File Structure  
```
libft/
├── includes/          # Header files (libft.h)
├── srcs/              # Source files
├── Makefile           # Build instructions
├── libft.a            # Static library (generated after compilation)
└── README.md          # Project documentation
```

---

## Credits  
Developed by [deunen](https://github.com/deunen) as part of the 42 School curriculum.  
Special thanks to the 42 community for guidance and inspiration.

---

