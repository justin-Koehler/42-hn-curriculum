# The Void Pointer

A `void *` is a universal connector. It points to any address in memory, but it doesn't care what type of data is stored there.

---

### The 3 Rules

1. **It accepts everything.** You can plug any pointer straight into it. No setup required.
2. **It cannot read or write.** It does not know the size of the data, so you cannot look inside yet.
3. **It cannot move.** You cannot use math (like `ptr++`) directly on it.

---

### How to Use It

To make it work, simply tell the compiler what type of data to expect. We call this **casting**.

```c
void *b;               // The generic pointer

unsigned char *ptr;    // 1. Create a specific pointer
ptr = (unsigned char *)b; // 2. Cast it

ptr++;                 // 3. It just works: now you can move and edit!
*ptr = 0;
```

---

### Why it Matters

It makes your code **universal**. Functions like `ft_memset` use `void *` so they can clear a string, an array of numbers, or a complex structure with the exact same line of code.
