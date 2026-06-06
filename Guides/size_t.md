# size_t

`size_t` is a specialized data type in C designed for one specific job: **measuring sizes and counting elements in memory.** 

---

### The 3 Rules

1. **It is always positive.** It cannot hold negative numbers (it is `unsigned`). It starts at `0` and goes up.
2. **It scales automatically.** On a 32-bit system, it is 4 bytes. On a 64-bit system, it automatically grows to 8 bytes. It always matches your computer's maximum memory capacity.
3. **It is a replacement for `int`.** Whenever you count bytes, array indexes, or string lengths, use `size_t` instead of `int`.

---

### How to Use It

You use it just like a regular integer, but it protects you from negative number bugs.

```c
#include <stddef.h> // Essential: size_t lives here

size_t len;
len = 0;

while (str[len] != '\0')
{
    len++; // Perfect for counting lengths
}
```

---

### Why it Matters

Using `int` for memory sizes is dangerous. An `int` can go negative, which makes no sense for the length of a string and causes critical security bugs. `size_t` ensures your loops never crash due to negative numbers and can handle even the largest possible files.
