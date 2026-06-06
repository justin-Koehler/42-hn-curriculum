# Guide: Dynamic Memory Allocation in C

Dynamic memory allocation allows a program to request memory from the operating system at runtime (while the program is running). In the 42 curriculum, mastering the heap is essential for handling unpredictable data sizes without crashing.

---

## 1. Static vs. Dynamic Allocation

*   **Static Allocation**: When you declare a fixed array like `int array[100];`, the size is locked at compile time. If your program suddenly needs 101 integers, it will crash. If it only needs 2, you waste memory.
*   **Dynamic Allocation**: You request the exact amount of bytes you need from a giant pool of memory called **The Heap** using `malloc()`.

---

## 2. The Core Functions: `malloc` and `free`

To use dynamic memory, you must include the standard library `<stdlib.h>`.

### Allocation: `malloc`
`malloc()` takes one argument: the total number of bytes you want to allocate. It returns a generic pointer (`void *`) to the first byte of that newly allocated space.

### Deallocation: `free`
Memory on the heap does not disappear automatically. When you are done using it, you must release it back to the operating system using `free()`.

---

## 3. Norminette-Compliant Implementation

When working with `malloc`, you must **always** protect it. If the operating system runs out of memory, `malloc` will return `NULL`. Trying to write to a `NULL` pointer causes an immediate crash.

### Safe String Allocation Example
```c
char	*ft_alloc_string(size_t size)
{
	char	*str;

	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}
```
*Note: Under modern 42 standards, explicit casting of malloc (e.g., `(char *)malloc(...)`) is discouraged because `void *` automatically converts to any pointer type upon assignment.*

---

## 4. The Two Fatal Errors: Leaks and Dangling Pointers

Managing memory manually gives you great power, but it requires perfect discipline.

### Trap 1: Memory Leaks
A memory leak happens when you allocate memory on the heap, but lose the pointer pointing to it without calling `free()`. That memory stays locked and unusable until the entire program terminates.

```c
void	ft_leak_example(void)
{
	char	*ptr;

	ptr = malloc(10);
	if (!ptr)
		return ;
	ptr = malloc(20); 
	free(ptr);
}
```
*What went wrong?* The second `malloc` overwrote the address stored in `ptr`. The first 10 bytes are now permanently lost in RAM because we can no longer call `free` on them.

### Trap 2: Dangling Pointers / Double Free
After you call `free(ptr);`, the memory is gone, but the variable `ptr` still holds the old address. If you try to use `*ptr` or call `free(ptr);` a second time, your program will crash.

**The Solution**: Always clear your pointers immediately after freeing them by setting them to `NULL`.

```c
void	ft_safe_free(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
```

---

## 5. Summary Checklist for 42 Evaluations

*   **Size Calculation**: Always use `sizeof(type)` inside your malloc calculation to ensure cross-platform compatibility (e.g., `malloc(count * sizeof(int))`).
*   **Protection**: Every single `malloc` call must be immediately followed by an `if (!ptr)` check.
*   **Cleaning Up**: If a function allocates memory but fails halfway through, it must clean up and `free` everything it allocated before returning `NULL`.
*   **Zero Leaks**: Run your test binaries with leak detectors (`Valgrind` or system-specific flags) before submitting your project.
