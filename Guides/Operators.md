# C Operators

These symbols are the vocabulary of pure logic. They are the tools that allow your software to make decisions, execute loops, and navigate the computer's memory with absolute precision. 

---

### The 3 Rules

1. **`%` creates circular logic.** The Modulo operator divides two numbers and returns **only the remainder**. It is the secret to turning a linear path into a closed loop.
2. **`||` simplifies choices.** The Logical OR operator combines multiple conditions. If **at least one** side is true, the entire gateway opens.
3. **`>` , `<` and `==` build the brain.** These are the gatekeepers. They compare values to determine if a number is **greater than** (`>`), **less than** (`<`), or **exactly equal** (`==`) to another.

---

### How to Use Them

When you combine these operators, you give your software the power to navigate and protect itself:

```c
int i = 42;

// 1. Modulo (%): Isolate a value or wrap around.
int digit = i % 10;        // 42 / 10 = 4, remainder is 2. 'digit' is now 2.

// 2. Logical OR (||): Combine conditions into a single elegant line.
if (i == 42 || i == 99)    // True, because i is 42. The block executes.
    i++;

// 3. Comparisons (> and <): Protect your memory boundaries.
if (i > 0 && i < 100)      // Essential for guarding pointers from running
    i--;                   // out of bounds (like str > argv[1]).

// 4. Equality (==): Check values without changing them.
if (i == 43)               // '==' checks the value. 
    i = 0;                 // '=' assigns the value. Never mix them up.
```

---

### Why it Matters

Without these operators, your code would be blind, running in a single straight line until it crashes. 
* **`%`** lets you create cycles, like wrapping the character `'Z'` back to `'A'` in a Caesar cipher without writing complex logic. 
* **`||`** removes clutter, replacing nests of ugly `if` statements with one beautiful line. 
* **`>`**, **`<`**, and **`==`** provide safety. They allow your loops to traverse text arrays and stop **exactly** before hitting a `Segmentation fault`. They make your code intelligent, safe, and incredibly fast.
