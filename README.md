# 42 Common Core Portfolio

This repository contains my solutions, documentation, and conceptual breakdowns for the 42 Heilbronn Common Core curriculum. It serves as a visual and technical portfolio tracking my journey through system programming, memory management, and software architecture.

## Philosophy

The 42 network thrives on peer-to-peer learning and rigorous intellectual growth. This repository is built strictly as a learning resource to explain low-level logic, algorithmic structures, and complex edge cases. 

**Learn, do not copy.** Code duplication is strictly penalized by the 42 evaluation systems and, more importantly, prevents true foundational learning. Use this repository to inspire your own logic, not to bypass the struggle of debugging.

---

## Directory Structure

### Guides
*   **Concepts & Breakdown Guides**: Detailed Markdown summaries explaining core programming fundamentals (Pointers, Memory Allocation, Recursion, and Operators) written in a highly scannable, conceptual format.

### Circle 01
*   **Libft**: A foundational reimplementation of standard C library functions. This project focuses on the absolute basics of low-level memory handling, string manipulation, and pointer arithmetic.

### Circle 02
*   **ft_printf**: A complete recreation of the `printf` engine from `libc`. It explores variadic arguments (`va_list`), runtime memory parsing, and dynamic type formatting without using external buffer management.
*   **get_next_line**: An optimized function designed to read any valid file descriptor line by line. This project dives deep into the behavior of static variables, precise buffer management, and dynamic heap allocations.

### Circle 03+
*   *Upcoming milestones (such as Pipex, Push_swap, Minishell, and Philosophers) will be systematically added, structured, and documented as I progress through the curriculum.*

---

## Technical Standards

Every line of source code inside this repository strictly complies with the following engineering guidelines:

*   **The Norminette**: Complete adherence to the official 42 code formatting standard (such as 25-line function limits, strict variable declaration rules, and controlled control structures).
*   **Memory Integrity**: Absolute zero memory leaks and zero dangling pointers. Every dynamic allocation (`malloc`) is securely guarded and systematically cleared (`free`).
*   **Defensive Coding**: Complete protection against `NULL` pointers, empty arguments, and critical system edge cases to prevent unexpected crashes (`Segmentation faults` or `Bus errors`).

---

## License

This repository is open-source software licensed under the MIT License.
