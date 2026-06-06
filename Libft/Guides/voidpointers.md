# Guide: Void Pointers in C (`void *`)

A `void *` (generic pointer) is one of the most powerful tools in low-level C programming. In the 42 curriculum—especially in `Libft`—understanding how to handle generic memory addresses is essential for writing reusable functions.

---

## 1. What is a Void Pointer?

A standard pointer (like `int *` or `char *`) always knows what type of data it points to. A `void *` is a **generic pointer**. It holds a raw memory address, but it has no data type attached to it.

Think of a void pointer as a **delivery address written on a envelope**, without knowing whether there is a book, a shirt, or a laptop inside the house.

### The Strict Rules of `void *`
Because the compiler does not know the size or type of the data behind a `void *`, you are strictly forbidden from doing two things directly:
1.  **No Dereferencing**: You cannot read or write to it directly (`*ptr` will throw a compiler error).
2.  **No Pointer Arithmetic**: You cannot move it through memory (`ptr++` or `ptr + 1` is undefined behavior).

---

## 2. Why Do We Need Them? (Generic Functions)

Without void pointers, you would have to write a separate copy function for every single data type. You would need `memcpy_int`, `memcpy_char`, `memcpy_double`, etc.

By using `void *`, a single function can accept **any memory address**, regardless of what is stored there.

### Examples from Standard Libc:
*   `void *malloc(size_t size);` — Returns a raw memory address. It doesn't care if you intend to store ints, chars, or structs inside it.
*   `void *memcpy(void *dest, const void *src, size_t n);` — Copies raw bytes from one address to another, no matter what data type those bytes represent.

---

## 3. How to Use Void Pointers (The Typecast)

To safely read, write, or navigate through a `void *`, you must first convert it into a typed pointer. This process is called **Typecasting**.

In `Libft` memory functions (`memset`, `memcpy`, `memmove`), we always cast `void *` to `unsigned char *`. 
*   An `unsigned char` is exactly **1 byte** big.
*   Casting to `unsigned char *` allows us to move through the generic memory block precisely **byte by byte**.

### Norminette-Compliant Example: `ft_memcpy`
This function copies `n` bytes from a generic source area to a generic destination area.

```c
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
```

---

## 4. Implicit Casting with `void *`

One unique feature of C is that a `void *` can be implicitly converted to and from any other pointer type **without an explicit cast during assignment**.

### Norminette-Compliant Allocation Example
When using `malloc`, it returns a `void *`. You do not need to explicitly cast it. The assignment handles it safely and cleanly:

```c
int	*ft_allocate_ints(size_t count)
{
	int	*array;

	array = malloc(count * sizeof(int));
	return (array);
}
```
*Note: Explicitly casting malloc (e.g., `(int *)malloc(...)`) is outdated and discouraged under modern 42 standards.*

---

## 5. Summary Checklist

*   `void *` = Just a raw address. The compiler doesn't know what is inside.
*   To read or modify the data, **cast it** to a typed pointer first.
*   Cast to `(unsigned char *)` when you need to manipulate raw memory **byte by byte**.
*   Always check if the pointers are valid (`if (!dest && !src)`) before attempting any casting or operations.
