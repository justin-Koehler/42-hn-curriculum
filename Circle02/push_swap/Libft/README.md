# Libft

*This project has been created as part of the 42 curriculum by jukohler.*

---

## Description

**Libft** is the very first project of the 42 curriculum. The goal is to code a C library containing a collection of general purpose functions that will be reused throughout the entire 42 curriculum.

This project consists of reimplementing standard C library functions (libc), as well as creating additional utility functions and a linked list implementation — all from scratch, without relying on any external libraries.

---

## Functions

### Part 1 — Libc Functions

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if character is alphabetic |
| `ft_isdigit` | Checks if character is a digit |
| `ft_isalnum` | Checks if character is alphanumeric |
| `ft_isascii` | Checks if character is in ASCII range (0-127) |
| `ft_isprint` | Checks if character is printable (32-126) |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Sets memory to zero |
| `ft_memcpy` | Copies memory from source to destination |
| `ft_memmove` | Copies memory safely (handles overlapping) |
| `ft_strlcpy` | Copies string with size limitation |
| `ft_strlcat` | Appends string with size limitation |
| `ft_toupper` | Converts character to uppercase |
| `ft_tolower` | Converts character to lowercase |
| `ft_strchr` | Locates first occurrence of character in string |
| `ft_strrchr` | Locates last occurrence of character in string |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_memchr` | Searches for a byte in memory |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Locates a substring in a string |
| `ft_atoi` | Converts string to integer |
| `ft_calloc` | Allocates memory and sets it to zero |
| `ft_strdup` | Duplicates a string using malloc |

### Part 2 — Additional Functions

| Function | Description |
|---|---|
| `ft_substr` | Creates a substring from a string |
| `ft_strjoin` | Concatenates two strings into a new one |
| `ft_strtrim` | Removes characters from beginning and end of string |
| `ft_split` | Splits a string by a delimiter character |
| `ft_itoa` | Converts integer to string |
| `ft_strmapi` | Applies a function to each character of a string |
| `ft_striteri` | Applies a function to each character in place |
| `ft_putchar_fd` | Outputs a character to a file descriptor |
| `ft_putstr_fd` | Outputs a string to a file descriptor |
| `ft_putendl_fd` | Outputs a string followed by newline to a file descriptor |
| `ft_putnbr_fd` | Outputs an integer to a file descriptor |

### Part 3 — Linked List

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new linked list node |
| `ft_lstadd_front` | Adds a node at the beginning of a list |
| `ft_lstsize` | Counts the number of nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds a node at the end of a list |
| `ft_lstdelone` | Deletes a single node |
| `ft_lstclear` | Deletes and frees an entire list |
| `ft_lstiter` | Iterates a function over a list |
| `ft_lstmap` | Creates a new list from applying a function to each node |

---

## Instructions

### Compilation

```bash
# Build the library
make

# Clean object files
make clean

# Remove all compiled files
make fclean

# Rebuild everything
make re
```

### Usage

To use libft in another project:

```c
#include "libft.h"
```

Then compile with:

```bash
cc your_file.c -L. -lft -o your_program
```

---

## Resources

- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [man pages](https://man7.org/linux/man-pages/)
- [42 Norm](https://github.com/42School/norminette)

### AI Usage

Claude (claude.ai) was used during this project as a **learning tool** — to understand concepts, get explanations of error messages, and discuss logic. All code was written independently. AI was not used to generate or copy any functions directly.