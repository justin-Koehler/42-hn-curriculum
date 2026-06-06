# Functions

A function is a reusable machine. It takes raw materials (inputs), performs a specific task (logic), and delivers a finished product (output).

---

### The 3 Rules

1. **One job only.** A good function does exactly one thing perfectly. If it does more, it should be split into smaller functions.
2. **Strict blueprint.** Every function must explicitly declare what type of data it returns and exactly what type of data it expects to receive.
3. **Isolated scope.** Variables created inside a function live and die inside that function. They cannot be seen or modified by the rest of the program.

---

### How to Build It

A function is always built using four essential components:

```c
// Return-Type | Name | Parameters (Inputs)
int	ft_add(int a, int b)
{
	int	result; // 1. Local variable (Setup)

	result = a + b; // 2. Logic (The processing)
	return (result); // 3. Return-Value (The output)
}
```
*(If a machine does a job without returning a product, its Return-Type is `void`.)*

---

### Why it Matters

Without functions, code would be a single, massive, unreadable wall of text. Functions break a complex problem down into small, predictable Lego blocks. You can test each block individually, fix bugs in one place, and assemble a stable software architecture.
