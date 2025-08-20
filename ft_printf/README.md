# ft_printf - Grade: 100/100

A custom implementation of the `printf` function in C, adhering to the 42 School standards.

---

## Table of Contents

1. [What is ft_printf?](#what-is-ft_printf)
2. [Features](#features)
3. [Specification of Conversions](#specification-of-conversions)
4. [Installation](#installation)
5. [Usage](#usage)
6. [File Structure](#file-structure)
7. [Credits](#credits)

---

## What is ft_printf?

`ft_printf` is a custom implementation of the standard C library function `printf`. This project demonstrates an in-depth understanding of variadic functions and formatted output handling in C. The code complies with the formatting standards of **42 School** and follows the rules enforced by the `norminette` tool.

---

## Features

- Supports the following basic conversions:
  - **Characters**: `c`
  - **Strings**: `s`
  - **Pointers**: `p`
  - **Signed integers**: `d`, `i`
  - **Unsigned integers**: `u`
  - **Hexadecimal numbers**: `x`, `X`
  - **Percent sign**: `%`

- Handles the following flags:
  - `#`: Adds the appropriate prefix for hexadecimal values.
  - `0`: Pads the output with zeros.
  - `-`: Left-aligns the output.
  - `+`: Forces a plus sign for positive numbers.
  - `(space)`: Adds a space before positive numbers.

- Supports field width and precision for greater output control.

---

## Specification of Conversions

- `%c`: Prints a single character.
- `%s`: Prints a string of characters.
- `%p`: Prints the address of a pointer in hexadecimal format.
- `%d` or `%i`: Prints a signed integer in decimal format.
- `%u`: Prints an unsigned integer in decimal format.
- `%x`: Prints an unsigned integer in lowercase hexadecimal format.
- `%X`: Prints an unsigned integer in uppercase hexadecimal format.
- `%%`: Prints a percent sign.

### Bonus Features (Not Included in This Repository)

- Extended conversion specifiers and advanced flag combinations are typically part of a `ft_printf` bonus. However, this repository focuses solely on the mandatory part of the project.

---

## Installation

Clone the repository:

```bash
git clone https://github.com/denuen/42_cursus.git
cd 42_cursus/ft_printf
```

Build the library:

```bash
make
```

This will generate `libftprintf.a`, a static library that you can link to your projects.

---

## Usage

1. Include `ft_printf.h` in your C files:

   ```c
   #include "ft_printf.h"
   ```

2. Compile your program with the `libftprintf.a` library:

   ```bash
   gcc -Wall -Wextra -Werror -L. -lftprintf your_program.c
   ```

Example usage:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Number: %d\n", 42);
    ft_printf("String: %s\n", "Hello, world!");
    ft_printf("Character: %c\n", 'A');
    ft_printf("Hexadecimal: %x\n", 255);
    return 0;
}
```

Output:

```
Number: 42
String: Hello, world!
Character: A
Hexadecimal: ff
```

---

## File Structure

```
ft_printf/
├── includes/          # Header file (ft_printf.h)
├── srcs/              # Source files
├── Makefile           # Build instructions
├── libftprintf.a      # Static library (generated after compilation)
└── README.md          # Project documentation
```

---

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. Special thanks to the 42 community for guidance and inspiration.

---

