# Arrays & Strings

An array is a structured sequence. Instead of creating twenty separate variables for twenty different items, you allocate one continuous block of memory where values sit neatly shoulder-to-shoulder.

---

### The 3 Rules

1. **They are zero-indexed.** The very first element of an array lives at position `[0]`, not `[1]`. The final element is always at position `[size - 1]`.
2. **They must have a uniform type.** Every single slot in an array must hold the exact same type of data (such as all `int` or all `char`). 
3. **Strings require a sentinel.** In C, a string is simply an array of characters. It **must** end with a hidden `\0` (Null terminator) so loops know exactly when the text is over.

---

### How to Use Them

Navigating arrays safely requires combining an index pointer with a strict boundary check:

```c
// 1. Create a string array (automatically adds '\0' at the end)
char	word[] = "42"; 

int	i = 0;

// 2. Loop until the null terminator is reached
while (word[i] != '\0') 
{
	write(1, &word[i], 1); // 3. Access elements via [i]
	i++;
}
```

---

### Why it Matters

Arrays and strings are the physical architecture of data in memory. Without them, processing text, handling command-line arguments (`argv`), or managing lists of numbers would be mathematically impossible. Because array elements are packed perfectly next to each other in your RAM, the CPU can jump to any specific slot instantly. Understanding how arrays and their null terminators work is the ultimate secret to mastering text manipulation and keeping your code blisteringly fast.