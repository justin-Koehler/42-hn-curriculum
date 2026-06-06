# Recursion

Recursion is an elegant loop from within. Instead of using a standard `while` engine to repeat an action, a function calls **itself** over and over again, breaking a massive calculation down into smaller, identical sub-problems.

---

### The 3 Rules

1. **It demands a base case.** A recursive function must have a strict `if` condition that stops it from calling itself. Without it, the function spins infinitely until the computer runs out of memory.
2. **It must move forward.** Every single recursive call must pass a modified value that brings the program one step closer to the base case.
3. **It operates on a stack.** Every time a function calls itself, the computer pauses the current layer and pushes a brand-new layer on top of the execution stack. Only when the base case is hit do the layers resolve backward.

---

### How to Use It

Building a recursive function requires a clean split between the emergency brake (base case) and the self-triggering loop:

```c
// A function that prints digits down to 1 recursively
void	ft_countdown(int nbr)
{
	char	digit;

	// 1. Base Case: The emergency brake
	if (nbr <= 0)
		return;

	// 2. The Action
	digit = nbr + '0';
	write(1, &digit, 1);

	// 3. Recursive Call: Moving forward with a smaller value
	ft_countdown(nbr - 1);
}
```

---

### Why it Matters

Some of the most powerful algorithms in computer science—like searching through complex folder structures, parsing data trees, or sorting massive datasets—are incredibly hard to write with standard `while` loops. Recursion simplifies your code dramatically. It replaces pages of messy loop logic and state tracking with a few lines of self-referencing code. By mastering recursion, you learn to trust the stack, allowing you to solve deeply nested mathematical problems with absolute elegance and minimal code footprints.
