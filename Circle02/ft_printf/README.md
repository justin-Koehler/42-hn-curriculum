*This project has been created as part of the 42 curriculum by jukohler.*

***

# ft_printf: Because ft_putnbr and ft_putstr aren't enough.

Most people take `printf()` for granted. They think it's just a tool to throw text on a screen. But under the hood, it is a masterpiece of extensible architecture. 

This project is a complete rewrite of the standard C library’s `printf()`. No bloated buffers. No shortcuts. Just pure, system-level stream management that works seamlessly with variable parameter inputs.

---

## Description

The goal of `ft_printf` is straightforward: mimic the original `printf()` function from `libc`. It intercepts a formatted string, detects specifiers starting with `%`, extracts arguments dynamically, and prints them on the fly while tracking the exact number of bytes written.

### Supported Conversions
This library handles the 9 core pillars of C string formatting:
* `%c` – A single character.
* `%s` – A convention-standard C string.
* `%p` – A memory pointer printed in lowercase hexadecimal format.
* `%d` / `%i` – Base 10 decimal integers.
* `%u` – Unsigned base 10 decimal integers.
* `%x` / `%X` – Base 16 hexadecimal numbers (lowercase and uppercase).
* `%%` – A literal percent sign.

---

## Algorithm & Code Architecture

Great design is not just what it looks like; it's how it works. The engine of this `ft_printf` relies on two fundamental concepts: **Variadic Arguments** and an **Extensible Branching Switch**.

### 1. The Dynamic Extraction Engine (`va_list`)
Normal functions require a fixed number of parameters. `ft_printf` uses `<stdarg.h>` to handle an *infinite* number of variables dynamically.
* `va_start` initializes the argument pointer stack.
* `va_arg` steps through the memory block, grabbing variables of specific byte-sizes (`int`, `char *`, etc.) on demand.
* `va_end` safely cleans up the stack once parsing finishes.

### 2. The Step-by-Step Breakdown of our Logic

* **The Core Loop (`ft_printf`):** The program scans the `format` string character by character. If it finds a normal character, it prints it directly via `write`. If it hits a `%`, it freezes, hands the next character over to `checkformat`, and advances its cursor by 2.
* **The Central Switch (`checkformat`):** This is the brain of the operation. It maps each specifier (`c`, `s`, `d`, etc.) directly to its specialized printing handler.
* **The Pointer Safeguard (`ft_print_str` & `ft_print_ptr`):** To prevent system crashes (`Segmentation faults`), our functions intercept empty or invalid inputs. If a string pointer is null, it gracefully outputs `(null)`. If a hardware address is null, it prints `(nil)`.
* **The Recursive Hex Converter (`ft_print_hex`):** Instead of using dirty loops or massive static arrays, we convert hardware memory addresses and integers into hexadecimal notation using elegant mathematical recursion. By dividing the number by 16 repeatedly, we print the digits from left to right while dynamically adding up the total byte count.
* **The Leak Protection:** For operations that require converting integers into strings (`ft_itoa`), we pass a security flag (`is_allocated = 1`) to our string printer. This forces the function to automatically `free()` the temporary memory allocation on the spot, guaranteeing 0 memory leaks.

---

## Instructions

We built this project to compile effortlessly. It produces a clean, archived binary library archive called `libftprintf.a`.

### Compilation Rules
The provided `Makefile` contains the essential commands to orchestrate your build without performing unnecessary relinking:
* `make` / `make all` – Compiles the library using `cc` with strict `-Wall -Wextra -Werror` flags.
* `make clean` – Removes temporary object files (`.o`).
* `make fclean` – Wipes all objects and the final `.a` library file.
* `make re` – Triggers a fresh, pristine rebuild from scratch.

### How to use it in your code
1. Run `make` to compile the library.
2. Include the header file in your C source file: `#include "ft_printf.h"`
3. Compile your project file alongside the archive file: `cc main.c libftprintf.a`

---

## Resources & AI Use

### References
* **C Library Documentation:** Standard input/output manual pages for `printf(3)` and `stdarg(3)`.
* **42 School Norm Guidelines:** The definitive rules for clean, standard-compliant C syntax.

### Artificial Intelligence Disclosure
In line with the 42 AI Global Approach, an AI collaborator was strictly utilized for code refactoring, aesthetic optimization, and code review tasks. 
* **Refactoring:** AI was consulted to evaluate structural branches and ensure compliance with strict styling metrics (Norminette).
* **Reviewing:** AI acted as a validation buddy to double-check that our edge-case exceptions (like handling null string inputs and pointer allocations) were completely krisensicher before finalizing submission. No direct boilerplate shortcuts were generated; the core algorithmic structure remains completely hand-crafted to establish solid engineering foundations.


# Code Architecture: ft_printf.c

This is a deep dive into the inner mechanics of `ft_printf.c`. It is designed to be simple, clean, and intuitive—even if you are just starting your journey in C.

---

## The 42 Header

At the very top of the file lives the standard 42 header. 

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:37:59 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/02 15:59:48 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

*   **The Blueprint:** This is an unforgeable cryptographic stamp generated by the 42 network. It tracks exactly who created the file (`By`), when it was born (`Created`), and the precise second it was last modified (`Updated`). It guarantees authenticity and transparency during peer evaluations.

---

## 1. The Core Engine: ft_printf

We start at the bottom because that is where the execution loop begins:

```c
int	ft_printf(const char *format, ...)
```

*   **The Ellipsis `...`:** This notation represents **variadic parameters**. It signals that the function can accept an unpredictable sequence of incoming variables. You can pass one argument, or one hundred. It adapts automatically.
*   **`va_list ap;`:** A highly optimized storage tracker. It remembers the exact memory coordinates of where the optional arguments reside in your RAM.
*   **`va_start(ap, format);`:** This activates the argument list, placing the memory reader cursor immediately after the initial `format` string.
*   **The Main Loop (`while (format[i])`):** It walks through the text byte by byte. 
    *   If it encounters a normal character, it writes it straight to the screen using `write(1, &format[i], 1)` and increments our master counter `len`.
    *   If it hits a `%` sign followed by a specifier character, it freezes. It routes that specific type to `checkformat`, updates the total print length `len`, and advances the reading position by 2 spaces (`i += 2`).
*   **`va_end(ap);`:** Safely detaches the memory reader, tearing down the temporary argument stack to maintain system stability.
*   **The Output:** The engine returns `len`, the exact count of characters successfully displayed on the screen.

---

## 2. The Decision Gateway: checkformat

This is the central switching station. It receives the isolated formatting specifier and the argument list:

```c
static int	checkformat(char specifier, va_list ap)
```

*   **`va_arg(ap, Type)`:** The command used to extract the next argument from the stack. You must declare the precise data type so the hardware knows exactly how many bytes to read from memory.
*   **The Routing Switch:** It maps the format specifier to the correct internal handler:
    *   `%` -> Outputs a literal percent sign.
    *   `c` -> Extracts an `int`, converting it to a standard character via `ft_putchar_fd`.
    *   `s` -> Extracts a string pointer (`char *`), passing it to `ft_print_str`.
    *   `d` / `i` -> Extracts a signed integer, serializes it to text with `ft_itoa`, and prints via `ft_print_str`.
    *   `u` -> Extracts an `unsigned int` and handles it similarly using `ft_itoa` and `ft_print_str`.
    *   `x` / `X` -> Extracts an unsigned integer, passing it to the base-16 converter `ft_print_hex`.
    *   `p` -> Extracts a raw hardware address (`unsigned long long`) and routes it to `ft_print_ptr`.

---

## 3. The String Master: ft_print_str

```c
static int	ft_print_str(char *str, int is_allocated)
```

*   **The Defensive Shield:** If a string pointer points to absolute nothingness (`!str`), the system protects itself from a crash by substituting it with the standard fallback string `"(null)"`.
*   **Execution:** It measures the size via `ft_strlen` and commits the entire block to the output channel in a single `write` transaction.
*   **Memory Integrity (`is_allocated`):** When numbers are transformed into temporary text blocks on the heap via `ft_itoa`, they consume dynamic RAM. Passing an execution flag of `1` instructs the function to immediately execute `free(str)` post-printing. This guarantees zero memory leaks.

---

## 4. The Address Reader: ft_print_ptr

```c
static int	ft_print_ptr(unsigned long long ptr)
```

*   **The Null Safeguard:** If a pointer address is completely empty (`0`), standard system protocol requires it to display `(nil)`. This function handles that gracefully.
*   **The Prefix:** Every authentic memory address is introduced using hex notation. The function writes out the traditional `"0x"` prefix before feeding the address directly into the hexadecimal converter.

---

## 5. The Recursive Hex Engine: ft_print_hex

This component translates numbers into base-16 hexadecimal strings using the mathematical beauty of **recursion**:

```c
static int	ft_print_hex(unsigned long long num, char specifier)
```

*   **The Base Arrays:** Depending on whether the user requested lowercase (`x`) or uppercase (`X`), the engine targets the precise character map array needed.
*   **The Recursive Stack (`if (num >= 16)`):** If a number exceeds 15, it cannot fit inside a single hex digit. The function divides the value by 16 and re-invokes itself with the quotient.
*   **The Visual Result:** This unrolls the value from the back to the front mathematically, but prints it perfectly from left to right as the function stack resolves. Using the modulo operator (`% 16`), it isolates the remainder, picks the matching character from our base array, writes it out, and returns the total byte count.
