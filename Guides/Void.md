# void

`void` literally means "nothing." In C, it is a placeholder used to tell the compiler that a function either returns no data or accepts no inputs.

---

### The 3 Rules

1. **No product returned.** When used as a return type, it means the function does its job (like printing text or altering memory) and finishes without sending back a value.
2. **No inputs accepted.** When placed inside the parameter brackets `(void)`, it explicitly tells the compiler that this function strictly takes zero arguments.
3. **No size of its own.** Unlike `int` or `char`, `void` represents the absence of a type, meaning you cannot create a variable of type `void`.

---

### How to Use It

You use it to define functions that perform an action rather than a calculation:

```c
// 1. Returns NOTHING | 2. Takes NOTHING
void	ft_print_welcome(void)
{
	// This function just acts, it does not calculate a result
	write(1, "Welcome.\n", 9);
	
	// A return statement is optional and has no value
	return ; 
}
```

---

### Why it Matters

Computers demand absolute clarity. If a function does not return a value, the compiler needs to know so it doesn't waste time waiting for a result or throwing errors. `void` acts as a clear stop sign, making your code safe and predictable.
