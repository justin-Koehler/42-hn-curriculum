# Libft - Your First Custom C Library

Welcome to your very first project in the 42 Common Core. In this project, you will re-code standard C library functions (like `strlen`, `memcpy`, `atoi`) and learn how to package them into a single archive file (`.a`).

## Why Libft Matters

You are not allowed to use standard functions in future 42 projects. From now on, you will use this library (`libft.a`) for everything you build. Writing it yourself forces you to understand exactly how memory, pointers, and types work under the hood.

## Core Concepts to Understand

Before writing code, make sure you understand these basic concepts:
* **Pointers & Memory Addresses**: How variables are stored and how to move through arrays using memory addresses.
* **Typecasting**: Converting one data type to another (especially `(char *)` and `(void *)`).
* **Void Pointers (`void *`)**: Generic pointers that can point to any data type. Essential for memory functions like `memset` or `memcpy`.
* **Dynamic Memory (`malloc` & `free`)**: Allocating memory on the heap and preventing memory leaks.

## Project Structure

Your project should be organized cleanly. Here is the standard setup:

* **src/**: Contains all your `.c` files (e.g., `ft_strlen.c`, `ft_memset.c`).
* **libft.h**: The header file containing all function prototypes and structure definitions.
* **Makefile**: The script that automates compilation with flags (`-Wall -Wextra -Werror`).

## Common Beginner Mistakes (Edge Cases)

To pass the Moulinette and peer evaluations, test your functions against these scenarios:
1. **Passing NULL pointers**: What happens if someone passes `NULL` to `ft_strlen`? (Protect your functions!).
2. **Buffer Overflows**: Ensure your memory functions (`ft_strlcpy`, `ft_memcpy`) never write outside the allocated memory size.
3. **The `ft_atoi` traps**: Test it with multiple spaces, negative signs (`---2`), and values that exceed integer limits (int overflow).
4. **Memory Leaks**: Every time you use `malloc`, ensure you have a plan to `free` that memory if something fails.

## How to Test Your Libft

Do not submit your project without testing it with automated testers. Here are the community favorites:
* **Libfttester** by Tripouille
* **libft-war-machine**

*Note: Testers help find bugs, but you must still understand your code for the defense!*
