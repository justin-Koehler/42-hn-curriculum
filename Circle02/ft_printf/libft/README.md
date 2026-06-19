*This project has been created as part of the 42 curriculum by zmaurer.*

# Libft

## Description

Libft is the first project of the 42 curriculum. The goal is to recreate a part of the C standard library from scratch, along with additional utility functions and linked list operations.

The purpose of this project is to build a strong foundation in C programming by working directly with memory, pointers, and data structures. It also introduces concepts such as dynamic memory allocation, function reuse, and modular code design.

The library is structured to be reusable across future 42 projects.

---

## Library Overview

Libft is divided into three main parts:

### 1. Standard C Library Reimplementation
This section contains functions that replicate behavior from the standard C library. The focus is on low-level operations such as memory manipulation, string handling, and character checks.

Examples:
- Memory: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_bzero`
- Strings: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`
- Comparison: `ft_strncmp`, `ft_memcmp`
- Conversion: `ft_atoi`, `ft_calloc`, `ft_strdup`

---

### 2. Additional Utility Functions
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- `ft_itoa`
- `ft_strmapi`, `ft_striteri`
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

---

### 3. Linked Lists

Implements a singly linked list using `t_list`.

Each node contains:
- `content`
- `next`

Functions:
- `ft_lstnew`
- `ft_lstadd_front`, `ft_lstadd_back`
- `ft_lstsize`, `ft_lstlast`
- `ft_lstdelone`, `ft_lstclear`
- `ft_lstiter`, `ft_lstmap`

---

## Instructions

### Compilation

```bash
make
```

### Make Rules

```bash
make clean   # remove object files
make fclean  # remove library and objects
make re      # rebuild everything
```

## Usage

To use the library functions, include this header:
```c
#include "libft.h"
```

To compile with the library:
```c
cc main.c libft.a
```

### Usage Example

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str = ft_strdup("Libft works!");

    printf("%s\n", str);
    free(str);

    return (0);
}
```

## Resources

- Linux man pages (malloc, free, write)
- 42 Libft subject PDF
- https://www.geeksforgeeks.org/
- https://beej.us/guide/bgc/

### AI Usage

AI was used for:

- clarifying unclear behaviors of standard C functions,
- understanding edge cases (memory overlap, allocation limits),
- reviewing README structure and improving clarity,
- assisting in organizing explanations of linked lists and function categories.

All implementation work and code decisions were performed manually.


